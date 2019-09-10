#include "hand.h"
#include <iostream>

int Hand::id = 0;

Hand::Hand(Deck &deck){
    for(int i = 0; i < 10; i++){
        cards.push_back(deck.draw());
    }
}

Card Hand::play(int index){
    Card temp = cards.at(index);
    cards.erase(cards.begin()+index);
    return temp;
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
