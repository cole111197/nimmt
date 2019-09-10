#ifndef __HAND_H
#define __HAND_H
#include "card.h"
#include <vector>
#include <string>

class Hand{
    private:
        int _size;
        std::vector<Card> cards;
    public:
        int play(int index);
        std::string to_string();
};

#endif
