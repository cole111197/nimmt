#ifndef __DECK_H
#define __DECK_H
#include "card.h"
#include <vector>

class Deck{
    private:
        int _maxsize;
        int _size;
        std::vector<Card> cards;
    public:
        Deck(int maxsize);
        void reset();
        void shuffle();
        Card draw();
        std::string to_string();
};

#endif
