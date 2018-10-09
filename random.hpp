#pragma once

#include <random>

std::default_random_engine& get_random_engine();
/// Returns the default random number engine.

void seed_random_device(std::uint32_t n);
/// Seeds the random device with the value n.
