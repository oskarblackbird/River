#include "evaluator.hpp"
#include <array>
#include <algorithm>

enum HandRank { HIGH_CARD=1, PAIR, TWO_PAIR, TRIPS, STRAIGHT, FLUSH, FULL_HOUSE, QUADS, STRAIGHT_FLUSH };

uint32_t evaluate_hand(const std::vector<Card>& cards) {
    std::array<int, 13> ranks{};
    std::array<int, 4> suits{};

    for (Card c : cards) {
        ranks[rank(c)]++;
        suits[suit(c)]++;
    }

    bool flush = std::any_of(suits.begin(), suits.end(), [](int c){ return c >= 5; });

    int consecutive = 0;
    bool straight = false;
    for(int i=0;i<13;i++){
        if(ranks[i]) consecutive++;
        else consecutive=0;
        if(consecutive>=5) straight=true;
    }

    int pairs=0, trips=0, quads=0;
    for(int c:ranks){
        if(c==4) quads++;
        else if(c==3) trips++;
        else if(c==2) pairs++;
    }

    HandRank hr;
    if(straight && flush) hr = STRAIGHT_FLUSH;
    else if(quads) hr = QUADS;
    else if(trips && pairs) hr = FULL_HOUSE;
    else if(flush) hr = FLUSH;
    else if(straight) hr = STRAIGHT;
    else if(trips) hr = TRIPS;
    else if(pairs>=2) hr = TWO_PAIR;
    else if(pairs==1) hr = PAIR;
    else hr = HIGH_CARD;

    return static_cast<uint32_t>(hr)<<24;
}
