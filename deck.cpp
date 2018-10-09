#include "deck.hpp"
#include "random.hpp"

#include <cassert>

Deck::Deck(std::initializer_list<Card> list)
  : m_cards(list)
{ }

bool
Deck::is_empty() const
{
  return m_cards.empty();
}

int
Deck::get_size() const
{
  return m_cards.size();
}

void
Deck::clear()
{
  m_cards.clear();
}

Card
Deck::take_top()
{
  Card c = m_cards.back();
  m_cards.pop_back();
  return c;
}

Card
Deck::take_bottom()
{
  Card c = m_cards.front();
  m_cards.pop_front();
  return c;
}

void
Deck::put_top(Card c)
{
  m_cards.push_back(c);
}

void
Deck::put_top(Deck& d)
{
  m_cards.insert(m_cards.end(), d.m_cards.begin(), d.m_cards.end());
  d.clear();
}

void
Deck::put_bottom(Card c)
{
  m_cards.push_front(c);
}

void
Deck::put_bottom(Deck& d)
{
  m_cards.insert(m_cards.begin(), d.m_cards.begin(), d.m_cards.end());
  d.clear();
}

void
Deck::shuffle(std::default_random_engine& rng)
{
  std::shuffle(m_cards.begin(), m_cards.end(), rng);
}

void
Deck::sort()
{
  std::sort(m_cards.begin(), m_cards.end());
}

Deck::iterator
Deck::begin()
{
  return m_cards.begin();
}

Deck::iterator
Deck::end()
{
  return m_cards.end();
}

Deck::const_iterator
Deck::begin() const
{
  return m_cards.begin();
}

Deck::const_iterator
Deck::end() const
{
  return m_cards.end();
}

Deck
Deck::make_standard_52()
{
  return {
    {Ace, Spades},
    {Two, Spades},
    {Three, Spades},
    {Four, Spades},
    {Five, Spades},
    {Six, Spades},
    {Seven, Spades},
    {Eight, Spades},
    {Nine, Spades},
    {Ten, Spades},
    {Jack, Spades},
    {Queen, Spades},
    {King, Spades},

    {Ace, Clubs},
    {Two, Clubs},
    {Three, Clubs},
    {Four, Clubs},
    {Five, Clubs},
    {Six, Clubs},
    {Seven, Clubs},
    {Eight, Clubs},
    {Nine, Clubs},
    {Ten, Clubs},
    {Jack, Clubs},
    {Queen, Clubs},
    {King, Clubs},

    {Ace, Diamonds},
    {Two, Diamonds},
    {Three, Diamonds},
    {Four, Diamonds},
    {Five, Diamonds},
    {Six, Diamonds},
    {Seven, Diamonds},
    {Eight, Diamonds},
    {Nine, Diamonds},
    {Ten, Diamonds},
    {Jack, Diamonds},
    {Queen, Diamonds},
    {King, Diamonds},

    {Ace, Hearts},
    {Two, Hearts},
    {Three, Hearts},
    {Four, Hearts},
    {Five, Hearts},
    {Six, Hearts},
    {Seven, Hearts},
    {Eight, Hearts},
    {Nine, Hearts},
    {Ten, Hearts},
    {Jack, Hearts},
    {Queen, Hearts},
    {King, Hearts},
  };
}

std::ostream&
operator<<(std::ostream& os, const Deck & deck)
{
  // // Print in n rows of 13 cards
  // int n = 0;
  // for (Card c : deck) {
  //   os << c;
  //   if (++n % 13 == 0) {
  //     os << '\n';
  //     n = 0;
  //   }
  //   else {
  //     os << ' ';
  //   }
  // }
  for (Card c : deck)
    {
        os << c;
        //os << ' ';    /// This part is throwing a compiler error
    }
  return os;
}
