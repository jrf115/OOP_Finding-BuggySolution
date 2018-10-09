#pragma once

#include <iosfwd>
#include <vector>

struct Statistics
{
  unsigned seed;

  int size;

  int wins1;
  int wins2;
  int ties;

  int min_turns;
  int max_turns;

  double median_turns;
  double average_turns;
  double stddev_turns;
};

std::ostream& operator<<(std::ostream& os, Statistics const& stats);


/// Scores statistics about the game of war.
class Accumulator
{
public:
  Accumulator(unsigned s);
  /// Construct an accumulator with a seed value.

  void observe(int p, int n);
  /// Record a game of n turns with winner being -1 for p1, 1 for p2 and
  /// a tie for 0.

  Statistics get_stats();
  /// Return the computed statistics.

private:
  unsigned m_seed;
  /// The random seed for the test sequence.
  
  int m_wins1;
  /// The number of wins for player 1.

  int m_wins2;
  /// The number of wins for player 2.

  int m_ties;
  /// The number of ties.

  std::vector<int> m_turns;
  /// The number of turns in each game.
};

