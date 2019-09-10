#ifndef __CARD_H
#define __CARD_H
#include <string>

class Card{
    private:
        int _value;
        int _score;
    public:
        Card(int value);
        int get_value();
        int get_score();
        std::string to_string();
};

#endif
