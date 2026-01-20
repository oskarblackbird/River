#include "monte_carlo.hpp"
#include "deck.hpp"
#include "evaluator.hpp"

double estimate_equity(const std::vector<Card>& hero,
                       const std::vector<Card>& board,
                       int iterations) {
    int wins=0, ties=0;

    for(int i=0;i<iterations;i++){
        Deck deck;
        deck.remove(hero);
        deck.remove(board);

        std::vector<Card> opp = {deck.draw(), deck.draw()};
        std::vector<Card> full_board = board;

        while(full_board.size()<5) full_board.push_back(deck.draw());

        std::vector<Card> hero_cards = hero;
        hero_cards.insert(hero_cards.end(), full_board.begin(), full_board.end());

        std::vector<Card> opp_cards = opp;
        opp_cards.insert(opp_cards.end(), full_board.begin(), full_board.end());

        uint32_t hero_rank = evaluate_hand(hero_cards);
        uint32_t opp_rank = evaluate_hand(opp_cards);

        if(hero_rank > opp_rank) wins++;
        else if(hero_rank == opp_rank) ties++;
    }

    return (wins + 0.5*ties)/iterations;
}
