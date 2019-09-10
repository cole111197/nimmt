#ifndef __DECK_H
#define __DECK_H
#include "card.h"
#include <vector>

class Deck{
    private:
        int _maxsize;
        int _size;
        std::vector<Card> _cards;
    public:
        Deck(int maxsize);
        Card draw();
        int get_size();
        void reset();
        void shuffle();
        std::string to_string();
};

#endif
