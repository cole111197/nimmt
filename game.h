#ifndef __GAME_H
#define __GAME_H
#include "card.h"
#include "deck.h"
#include "hand.h"
#include <vector>

class Game{
    private:
        std::vector<std::vector<Card>> _table;
        std::vector<Hand> _hands;
    public:
        Game(int players);
        void play(int hand_index, int card_index);
        int get_hand_score(int hand_index);
        int get_row_score(int row);
        void reset();
        std::string to_string();
};

#endif
