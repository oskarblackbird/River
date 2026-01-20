#pragma once
#include <array>
#include <vector>
#include <random>
#include "card.hpp"

class Deck {
public:
    Deck();                              // Initialize full deck
    void remove(const std::vector<Card>& cards); // Remove known cards
    Card draw();                          // Draw random card

private:
    std::array<Card, 52> cards_;
    int size_;
    std::mt19937 rng_;
};
