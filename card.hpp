#pragma once

#include <iosfwd>

/// Represents the suit of a card.
enum Suit
{
  Spades,
  Clubs,
  Diamonds,
  Hearts,
};

/// Represents the rank of a card.
enum Rank
{
  Ace,
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King,
};

/// Represents the color of a card.
enum Color
{
  Black,
  Red,
};


/// Represents a playing card with a suit and a rank.
///
/// This class is represented as an 8-bit value (on any reasonably 
/// system). The layout of bits is as follows.
///
///   00ssrrrr
///
/// Where s is a suit bit and r is a rank bit.
class Card
{
public:
  Card() = default;
  /// Constructs a card with indeterminate value.

  Card(Rank r, Suit s);
  /// Construct a card with a rank and suit.

  // Accessors

  Rank get_rank() const;
  // Returns the rank of the card.

  Suit get_suit() const;
  // Returns the suit of the card.

  Color get_color() const;
  // Returns the color of the card.

  unsigned char get_raw_value() const { return m_value; }
  /// Returns the underlying representation.

private:
  unsigned char m_value;
};

bool operator==(Card a, Card b);
bool operator!=(Card a, Card b);

bool operator<(Card a, Card b);
bool operator>(Card a, Card b);
bool operator<=(Card a, Card b);
bool operator>=(Card a, Card b);

std::ostream& operator<<(std::ostream& os, Rank r);
std::ostream& operator<<(std::ostream& os, Suit s);
std::ostream& operator<<(std::ostream& os, Card c);

