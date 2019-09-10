#include "deck.h"
#include <algorithm>
#include <iostream>

Deck::Deck(int maxsize){
    for(int i = 1; i <= maxsize; i++){
        cards.push_back(Card{i});
    }
}

int Deck::get_size(){
    return _size;
}

void Deck::reset(){
    cards.clear();
    for(int i = 1; i <= _maxsize; i++){
        cards.push_back(Card{i});
    }
}

void Deck::shuffle(){
    std::random_shuffle(cards.begin(), cards.end());
}

Card Deck::draw(){
    Card temp = cards.back();
    cards.pop_back();
    return temp;
}

std::string Deck::to_string(){
    std::string temp;
    for(int i=0; i<cards.size(); i++){
        temp += std::to_string(i) + " : " + cards[i].to_string() + "\n";
    }
    return temp;
}
