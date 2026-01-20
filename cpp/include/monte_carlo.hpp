#pragma once
#include <vector>
#include "card.hpp"

double estimate_equity(const std::vector<Card>& hero,
                       const std::vector<Card>& board,
                       int iterations);
