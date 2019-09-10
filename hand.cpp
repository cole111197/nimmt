#include "hand.h"
#include <iostream>

int Hand::id = 0;

Hand::Hand(Deck &deck){
    _score = 0;
    for(int i = 0; i < 10; i++){
        cards.push_back(deck.draw());
    }
}

Card Hand::play(int index){
    Card temp = cards.at(index);
    cards.erase(cards.begin()+index);
    return temp;
}

std::vector<Card>& Hand::get_cards(){
    return cards;
}

void Hand::set_score(int score){
    _score = score;
}

void Hand::inc_score(int score){
    _score += score;
}

int Hand::get_score(){
    return _score;
}

std::string Hand::to_string(){
    std::string temp;
    temp += "ID: " + std::to_string(_id) + "\nCards:\n";
    for(int i = 0; i < cards.size(); i++){
        temp += cards[i].to_string() + "\n";
    }
    temp += "-------------------";
    return temp;
}
