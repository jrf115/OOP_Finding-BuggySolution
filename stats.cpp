#include "stats.hpp"

#include <cmath>
#include <algorithm>
#include <iostream>

Accumulator::Accumulator(unsigned s)
  : m_seed(s)
{ }

void
Accumulator::observe(int w, int n)
{
  if (w < 0)
    ++m_wins1;
  else if (w > 0)
    ++m_wins2;
  else
    ++m_ties;
  m_turns.push_back(n);
}

template<typename Iter>
double
median(Iter first, Iter last)
{
  int const n = last - first;
  Iter i = first + (n / 2);
  if (n % 2 == 0) {
    Iter j = i + 1;
    return (*i + *j) / 2.0;
  }
  else {
    return *i;
  }
}

template<typename Iter>
double
average(Iter first, Iter last)
{
  int const n = last - first;
  double sum = 0;
  while (first != last)
    sum += *first++;
  return sum / n;
}

template<typename Iter>
double
var(Iter first, Iter last, double u)
{
  int const n = last - first;
  double sum = 0;
  while (first != last) {
    double n = *first++;
    sum += n * n - u;
  }
  return sum / n;
}

template<typename Iter>
double
stddev(Iter first, Iter last, double u)
{
  return std::sqrt(var(first, last, u));
}

Statistics
Accumulator::get_stats()
{
  std::sort(m_turns.begin(), m_turns.end());

  Statistics s;
  s.seed = m_seed;
  s.size = m_turns.size();
  s.wins1 = m_wins1;
  s.wins2 = m_wins2;
  s.ties = m_ties;
  s.min_turns = m_turns.front();
  s.max_turns = m_turns.back();
  s.median_turns = median(m_turns.begin(), m_turns.end());
  s.average_turns = average(m_turns.begin(), m_turns.end());
  s.stddev_turns = stddev(m_turns.begin(), m_turns.end(), s.average_turns);
  return s;
}

std::ostream& 
operator<<(std::ostream& os, Statistics const& s)
{
  std::cout << "seed value: " << s.seed << '\n';
  std::cout << "num of games: " << s.size << '\n';
  std::cout << "wins for p1: " << s.wins1 << '\n';
  std::cout << "wins for p2: " << s.wins2 << '\n';
  std::cout << "ties: " << s.ties << '\n';
  std::cout << "min turns: " << s.min_turns << '\n';
  std::cout << "max turns: " << s.max_turns << '\n';
  std::cout << "median turns: " << s.median_turns << '\n';
  std::cout << "average turns: " << s.average_turns << '\n';
  std::cout << "stddev turns: " << s.stddev_turns << '\n';
  return os;
}
