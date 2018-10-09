#include "war.hpp"
#include "stats.hpp"

#include <iostream>


War::War(std::default_random_engine& rng, Accumulator* acc)
  : m_rng(rng),
    m_deck(Deck::make_standard_52()),
    m_player1(),
    m_player2(),
    m_pile(),
    m_turns(0),
    m_accum(acc)
{ }

bool
War::is_over() const
{
  return m_player1.is_empty() || m_player2.is_empty() || m_turns >= 10000;
}

bool
War::is_tie() const
{
  return m_player1.is_empty() && m_player2.is_empty();
}

bool
War::is_winner(Player const& p) const
{
  Player const& q = (&p == &m_player1) ? m_player2 : m_player1;
  return !p.is_empty() && q.is_empty();
}

void
War::play()
{
  // Set up the deck and players.
  shuffle();
  deal();

  // Execute the game.
  do {
    turn();
  } while (!is_over());

  // Perform any final cleanups and accounting.
  finish();
}

void
War::shuffle()
{
  m_deck.shuffle(m_rng);
}

void
War::deal()
{
  // This algorithm is designed to handle n players.
  while (true) {
    if (deal(m_player1))
      break;
    if (deal(m_player2))
      break;
  }
}

bool
War::deal(Player& p)
{
  p.put_top(m_deck.take_top());
  return m_deck.is_empty();
}

void
War::turn()
{
  // If either play has no cards the game is over.
  if (is_over())
    return;

  // Count the turn only if we're not in war.
  if (m_pile.is_empty())
    ++m_turns;

  // Each player flips their top card.
  Card c1 = flip(m_player1);
  Card c2 = flip(m_player2);

  // The player whose card has the greatest rank takes both.
  if (rank(c1) > rank(c2))
    claim(m_player1);
  else if (rank(c2) > rank(c1))
    claim(m_player2);
  else
    war();
}

Card
War::flip(Player& p)
{
  assert(!p.is_empty());
  Card c = p.take_top();
  m_pile.put_top(c);
  return c;
}

void
War::claim(Player& p)
{
  m_pile.shuffle(m_rng);
  p.put_bottom(m_pile);
}

void
War::war()
{
  // Each player puts one card face down, if possible.
  // The "war" is actually executed in the following turn.
  if (!m_player1.is_empty())
    flip(m_player1);
  if (!m_player2.is_empty())
    flip(m_player2);
}

void
War::finish()
{
  // If the pile is non-empty, one of the players
  // ran out of cards during war. Give the pile
  // to the winner.
  //
  // There is a curious case where a tie is possible.
  if (!m_pile.is_empty()) {
    if (is_tie())
      return;
    if (is_winner(m_player1))
      claim(m_player1);
    else
      claim(m_player2);
  }

  if (m_accum) {
    // FIXME: this is kind of gross. Can we do better?
    int w;
    if (is_winner(m_player1))
      w = -1;
    else if (is_winner(m_player2))
      w = 1;
    else
      w = 0;
    m_accum->observe(w, m_turns);
  }
}

int
War::rank(Card c)
{
  if (c.get_rank() == Ace)
    return King + 1;
  else
    return c.get_rank();
}
