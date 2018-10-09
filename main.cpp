#include "war.hpp"
#include "stats.hpp"

#include <ctime>
#include <iostream>
#include <random>
#include <cstdlib>  /// Added as a different rand number solution
#include <time.h>   /// Added as a different rand number solution

int
main()
{
  std::random_device rd;

  /// unsigned seed = rd(); // Replacing old rand number solution
  srand(time(NULL));        /// NEW
  unsigned seed = rand();   /// NEW
  std::default_random_engine rng(seed);
  Accumulator acc(seed);

  // unsigned seed = 0;
  // std::default_random_engine rng(seed);
  // Accumulator acc(seed);

  for (int i = 0; i < 10000; ++i) {
    War w(rng, &acc);
    w.play();
  }

  std::cout << acc.get_stats();

}
