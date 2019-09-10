#include "card.h"

Card::Card(int value){
    _value = value;
    if(value==55){
        _score = 7;
    } else if(value%11 == 0){
        _score = 5;
    } else if(value%10 == 0){
        _score = 3;
    } else if(value%10 == 5){
        _score = 2;
    } else{
        _score = 1;    
    }
}

std::string Card::to_string(){
    return "Value=" + std::to_string(_value) + " , Score=" + std::to_string(_score);
}

int Card::get_value(){
    return _value;
}

int Card::get_score(){
    return _score;
}
