#include "hand.h"
#include <iostream>

int Hand::id = 0;

Hand::Hand(Deck &deck){
    _score = 0;
    for(int i = 0; i < 10; i++){
        _cards.push_back(deck.draw());
    }
}

Card Hand::remove(int index){
    Card temp = _cards.at(index);
    _cards.erase(_cards.begin()+index);
    return temp;
}

int Hand::get_score(){
    return _score;
}

void Hand::set_score(int score){
    _score = score;
}

void Hand::inc_score(int score){
    _score += score;
}

std::string Hand::to_string(){
    std::string temp;
    temp += "ID: " + std::to_string(_id) + "\nCards:\n";
    for(int i = 0; i < _cards.size(); i++){
        temp += _cards[i].to_string() + "\n";
    }
    temp += "-------------------";
    return temp;
}
