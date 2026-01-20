#pragma once
#include <cstdint>

using Card = uint8_t; // 0-51

inline int rank(Card c) { return c % 13; }  // 0=2, 12=Ace
inline int suit(Card c) { return c / 13; }  // 0-3
