#include "deck.h"
#include <algorithm>
#include <iostream>

Deck::Deck(int maxsize){
    _maxsize = maxsize;
    for(int i = 1; i <= maxsize; i++){
        _cards.push_back(Card{i});
    }
}

Card Deck::draw(){
    Card temp = _cards.back();
    _cards.pop_back();
    return temp;
}

int Deck::get_size(){
    return _size;
}

void Deck::reset(){
    _cards.clear();
    for(int i = 1; i <= _maxsize; i++){
        _cards.push_back(Card{i});
    }
}

void Deck::shuffle(){
    std::random_shuffle(_cards.begin(), _cards.end());
}

std::string Deck::to_string(){
    std::string temp;
    for(int i=0; i<_cards.size(); i++){
        temp += std::to_string(i) + " : " + _cards[i].to_string() + "\n";
    }
    return temp;
}
