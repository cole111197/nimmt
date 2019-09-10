#ifndef __HAND_H
#define __HAND_H
#include "card.h"
#include "deck.h"
#include <vector>
#include <string>

class Hand{
    private:
        static int id;
        int _id = id++;
        int _score;
        std::vector<Card> _cards;
    public:
        Hand(Deck &deck);
        Card remove(int index);
        int get_score();
        void set_score(int score);
        void inc_score(int score);
        std::string to_string();
};

#endif
