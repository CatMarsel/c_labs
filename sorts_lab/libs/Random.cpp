//
// Created by Maksim Kuzin on 12/7/25.
//

#include "Random.h"

Random::Random(int min, int max)
    : dist(min, max)
{
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    engine = std::default_random_engine(seed);
}

int Random::Next() {
    return dist(engine);
}