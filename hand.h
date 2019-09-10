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
        std::vector<Card> cards;
    public:
        Hand(Deck &deck);
        void set_score(int score);
        void inc_score(int score);
        int get_score();
        std::vector<Card>& get_cards();
        Card play(int index);
        std::string to_string();
};

#endif
