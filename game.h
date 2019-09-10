#ifndef __GAME_H
#define __GAME_H
#include "card.h"
#include "deck.h"
#include <vector>

class Game{
    private:
        std::vector<std::vector<Card>> table;
    public:
        Game(Deck &deck);
        std::string to_string();
        int play(Card card);
        void reset();
};

#endif
