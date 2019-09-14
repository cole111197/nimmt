#include "game.h"
#include <iostream>
#include <string>

Game::Game(int players){
    if(players > 10){
        players = 10;
    }
    Deck deck{(10*players)+4};
    deck.shuffle();
    for(int i = 0; i < 4; i++){
        std::vector<Card> temp;
        temp.push_back(deck.draw());
        _table.push_back(temp);
    }
    for(int i = 0; i < players; i++){
        _hands.push_back(Hand{deck});
    }
}

void Game::play(int hand_index, int card_index){
    //Autoselect which row to take, if card fits in a row
    Card card = _hands[hand_index].remove(card_index);
    int target_row = -1;
    int target_value = -1;
    int current_value = -1;
    for(int i = 0; i < 4; i++){
        current_value = _table[i].back().get_value();
        if(current_value >= target_value && current_value < card.get_value()){
            target_row = i;
            target_value = current_value;
        }
    }

    //std::cout << card.to_string() << std::endl;
    //std::cout << std::to_string(target_row) << std::endl;

    if(target_row != -1){ //If card could fit into a row
        int score = 0;
        if(_table[target_row].size() == 5){
            for(int i = 0; i < 5; i++){
                score += _table[target_row][i].get_score();
            }
            _table[target_row].clear();
        }
        _table[target_row].push_back(card);
        _hands[hand_index].inc_score(score);
    } else { //If card could NOT fit into a row
        int target_row = 0;
        int score = get_row_score(0);

        for(int i = 1; i < 4; i++){
            if(get_row_score(i) < score){
                score = get_row_score(i);
                target_row = i;
            }
        }
        _table[target_row].clear();
        _table[target_row].push_back(card);
        _hands[hand_index].inc_score(score);
    }
}

void Game::play(int card_index){
    Card card = _hands[0].remove(card_index);
    int target_row = -1;
    int target_value = -1;
    int current_value = -1;
    for(int i = 0; i < 4; i++){
        current_value = _table[i].back().get_value();
        if(current_value >= target_value && current_value < card.get_value()){
            target_row = i;
            target_value = current_value;
        }
    }

    if(target_row != -1){
        std::cout << "Playing in row " << target_row << std::endl;
        int score = 0;
        if(_table[target_row].size() == 5){
            for(int i = 0; i < 5; i++){
                score += _table[target_row][i].get_score();
            }
            _table[target_row].clear();
        }
        _table[target_row].push_back(card);
        _hands[0].inc_score(score);
    } else {
        int score = 0;
        target_row = -1;
        while(target_row > 3 || target_row < 0){
            std::cout << "[Card value " << std::to_string(card.get_value()) << "]: ID of row (0-3) to take and replace: ";
            std::cin >> target_row;
        }
        //target_row = 0;
        for(int i = 0; i < _table[target_row].size(); i++){
            score += _table[target_row][i].get_score();
        }
        _table[target_row].clear();
        _table[target_row].push_back(card);
        _hands[0].inc_score(score);
    }
}

int Game::get_hand_score(int hand_index){
    return _hands[hand_index].get_score();
}

int Game::get_row_score(int row){
    int score = 0;
    for(int i = 0; i < _table[row].size(); i++){
        score += _table[row][i].get_score();
    }
    return score;
}

void Game::print_hand(int hand_index){
    Hand hand = _hands.at(0);
    std::cout << hand.to_string() << std::endl;
}

void Game::reset(){

}

std::string Game::to_string(){
    std::string temp;
    for (int i = 0; i < _table.size(); i++)
    {
        temp += "ID: " + std::to_string(i) + " -- " + std::to_string(get_row_score(i)) + " -- ";
        for (int j = 0; j < _table[i].size(); j++)
        {
            temp += _table[i][j].to_string() + "  ";
        }
        temp += "\n";
    }
    return temp;
}
