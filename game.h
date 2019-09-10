#ifndef __GAME_H
#define __GAME_H
#include "card.h"
#include "deck.h"
#include "hand.h"
#include <vector>

class Game{
    private:
        std::vector<std::vector<Card>> table;
        std::vector<Hand> hands;
    public:
        Game(int players);
        std::string to_string();
        std::vector<Hand>& getHands();
        int hand_score(int hand_index);
        int row_score(int row);
        void play(int hand_index, int card_index);
        void reset();
};

#endif
