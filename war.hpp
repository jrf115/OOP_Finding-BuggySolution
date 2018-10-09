#pragma once

#include "card.hpp"
#include "deck.hpp"
#include <assert.h> // Added for the assert function used in war.cpp's Card War::flip function

class Accumulator;

using Player = Deck;
/// A player is just a deck of cards.


/// Represents a single instance of a game of war.
///
/// \todo Parameterize over all possible game rules!
class War
{
public:
  War(std::default_random_engine& rng, Accumulator* obs = nullptr);
  /// Construct the game with a generated random seed.

  // Game logic

  bool is_over() const;
  /// Returns true if the game is over.

  bool is_tie() const;
  /// Returns true if the game resulted in a tie.

  bool is_winner(Player const& p) const;
  /// Returns true if p is the winner.

  void play();
  /// Run the entire game to completion.

  void shuffle();
  /// Shuffle the deck.

  void deal();
  /// Deal cards to each player.

  bool deal(Player& p);
  /// Deal a from the top of the deck to the top of the player's hand.

  void turn();
  /// Run a single turn of the game, including wars.

  void war();
  /// War!

  Card flip(Player& p);
  /// Flip the top card for player p, putting it in the pile. The
  /// value of the card is returned.

  void claim(Deck& p);
  /// Claim the pile for the given player.
  ///
  /// \note The order in which 'p' claims cards determines the outcome
  /// of the game. Making this random actually means that the game of
  /// war is not formally a game (there are no decisions).

  void finish();
  /// Finish the game by computing the outcome.

  int rank(Card c);
  /// Returns the adjusted rank of a card (i.e., aces high).

private:
  std::default_random_engine& m_rng;
  /// The random number generator for the game.

  Deck m_deck;
  /// The initial deck of 52 standard cards.

  Player m_player1;
  /// The cards for player 1.

  Player m_player2;
  /// The cards for player 2.

  Deck m_pile;
  /// The pile of cards being battled over.

  /// The number of turns.
  int m_turns;

  Accumulator* m_accum;
  /// Records vital statistics about the game.
};
