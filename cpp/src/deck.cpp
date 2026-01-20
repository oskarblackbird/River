#include "deck.hpp"
#include <algorithm>

Deck::Deck() : size_(52), rng_(std::random_device{}()) {
    for (int i = 0; i < 52; ++i) cards_[i] = static_cast<Card>(i);
}

void Deck::remove(const std::vector<Card>& cards) {
    for (Card c : cards) {
        auto it = std::find(cards_.begin(), cards_.begin() + size_, c);
        if (it != cards_.begin() + size_) {
            std::swap(*it, cards_[size_ - 1]);
            size_--;
        }
    }
}

Card Deck::draw() {
    std::uniform_int_distribution<int> dist(0, size_ - 1);
    int idx = dist(rng_);
    Card c = cards_[idx];
    std::swap(cards_[idx], cards_[size_ - 1]);
    size_--;
    return c;
}
