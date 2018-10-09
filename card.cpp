#include "card.hpp"

#include <iostream>

/// Return the suit shifted into its representation.
static inline unsigned
to_bits(Suit s)
{
  return static_cast<unsigned>(s) << 4;
}

/// Returns the rank as its representation.
static inline unsigned
to_bits(Rank r)
{
  return static_cast<unsigned>(r);
}

static inline Suit
to_suit(unsigned n)
{
  return static_cast<Suit>(n >> 4);
}

static inline Rank
to_rank(unsigned n)
{
  return static_cast<Rank>(n & 0xf);
}

Card::Card(Rank r, Suit s)
  : m_value(to_bits(s) | to_bits(r))
{
}

Rank
Card::get_rank() const
{
  return to_rank(m_value);
}

Suit
Card::get_suit() const
{
  return to_suit(m_value);
}

std::ostream&
operator<<(std::ostream& os, Rank r)
{
  switch (r) {
  case Ace: return os << "A";
  case Two: return os << "2";
  case Three: return os << "3";
  case Four: return os << "4";
  case Five: return os << "5";
  case Six: return os << "6";
  case Seven: return os << "7";
  case Eight: return os << "8";
  case Nine: return os << "9";
  case Ten: return os << "T";
  case Jack: return os << "J";
  case Queen: return os << "Q";
  case King: return os << "K";
  }
}

std::ostream&
operator<<(std::ostream& os, Suit s)
{
  switch (s)
  {
  case Spades: return os << "\u2660";
  case Clubs: return os << "\u2663";
  case Diamonds: return os << "\u2662";
  case Hearts: return os << "\u2661";
  }
}

bool
operator==(Card a, Card b)
{
  return a.get_raw_value() == b.get_raw_value();
}

bool
operator!=(Card a, Card b)
{
  return !(a == b);
}


bool
operator<(Card a, Card b)
{
  return a.get_raw_value() < b.get_raw_value();
}

bool
operator>(Card a, Card b)
{
  return b < a;
}

bool
operator<=(Card a, Card b)
{
  return !(b < a);
}

bool
operator>=(Card a, Card b)
{
  return !(a < b);
}

std::ostream&
operator<<(std::ostream& os, Card c)
{
  return os << c.get_rank() << c.get_suit();
}
