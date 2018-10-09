#include "random.hpp"

#include <random>

static std::default_random_engine rng;

std::default_random_engine& 
get_random_engine()
{
  return rng;
}

void 
seed_random_device(std::uint32_t n)
{
  rng.seed(n);  
}
