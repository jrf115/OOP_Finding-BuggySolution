#pragma once

#include "card.hpp"

#include <algorithm>    // Added this to enable sort and shuffle in C++11
#include <deque>
#include <random>
#include <iosfwd>

/// Represents a deck of cards. Conceptually, this is modeled as a
/// double-ended queue (deque) where cards can be taken from or added
/// to the top or bottom of the deck. A deck may be empty.
class Deck
{
public:
  Deck() = default;
  /// Constructs an empty deck of cards.

  Deck(std::initializer_list<Card> list);
  /// Constructs a deck from the given list of cards.

  bool is_empty() const;
  /// Returns true if the deck is empty.

  int get_size() const;
  /// Returns the number of cards in the deck.

  // Card insertion and removal

  void clear();
  /// Reset this deck to an empty deck.

  Card take_top();
  /// Take a card from the top of the deck.

  Card take_bottom();
  /// Takes a card from the bottom of the deck.

  void put_top(Card c);
  /// Put a card on the top of the deck.

  void put_top(Deck& d);
  /// Place the cards in `d` on top of this deck; `d` is empty afterwards.

  void put_bottom(Card c);
  /// Puts a card on the bottom of the deck.

  void put_bottom(Deck& d);
  /// Place cards in `d` on the bottom of this stack; `d` is empty afterwards.

  // Permutations

  void shuffle(std::default_random_engine& rng);
  /// Shuffles the deck of cards using the random number generator.

  void sort();
  /// Sorts the deck of cards.

  // Iterators

  using iterator = std::deque<Card>::iterator;
  /// The type of iterators into the deck.

  using const_iterator = std::deque<Card>::const_iterator;
  /// The type of iterators into an immutable deck.

  iterator begin();
  /// Returns an iterator to the first card in the deck.

  iterator end();
  /// Returns an iterator past the last card in the deck.

  const_iterator begin() const;
  /// Returns an iterator to the first card in the deck.

  const_iterator end() const;
  /// Returns an iterator past the last card in the deck.

  // Deck factories

  static Deck make_standard_52();
  // Returns the next deck of cards.

private:
  std::deque<Card> m_cards;
};


Deck operator+(Deck const& a, Deck const& b);
/// Combine two decks in their current order.

std::ostream& operator<<(std::ostream& os, Deck const& d);
/// Write the deck to the output stream.

