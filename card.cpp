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
    std::string svalue;    
    std::string sscore;
    if(_value < 10){
        svalue = "  " + std::to_string(_value);
    } else if(_value < 100){
        svalue = " " + std::to_string(_value);
    } else {
        svalue = std::to_string(_value);
    }
    if(_score < 10){
        sscore = " " + std::to_string(_score);    
    } else {
        sscore = std::to_string(_score);    
    }
    return "[" + svalue + "]" + "(" + sscore + ")";
}

int Card::get_value(){
    return _value;
}

int Card::get_score(){
    return _score;
}
