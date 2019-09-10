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
        table.push_back(temp);
    }
    for(int i = 0; i < players; i++){
        hands.push_back(Hand{deck});
    }
}

std::vector<Hand>& Game::getHands(){
    return hands;
}

int Game::row_score(int row){
    int score = 0;
    for(int i = 0; i < table[row].size(); i++){
        score += table[row][i].get_score();
    }
    return score;
}

std::string Game::to_string(){
    std::string temp;
    for (int i = 0; i < table.size(); i++)
    {
        temp += "ID: " + std::to_string(i) + " -- " + std::to_string(row_score(i)) + " -- ";
        for (int j = 0; j < table[i].size(); j++)
        {
            temp += table[i][j].to_string() + "  ";
        }
        temp += "\n";
    }
    return temp;
}

int Game::hand_score(int hand_index){
    return hands[hand_index].get_score();
}

void Game::play(int hand_index, int card_index){
    Card card = hands[hand_index].play(card_index);
    int target_row = -1;
    int target_value = -1;
    int current_value = -1;
    for(int i = 0; i < 4; i++){
        current_value = table[i].back().get_value();
        if(current_value >= target_value && current_value < card.get_value()){
            target_row = i;
            target_value = current_value;
        }
    }

    if(target_row != -1){
        int score = 0;
        if(table[target_row].size() == 5){
            for(int i = 0; i < 5; i++){
                score += table[target_row][i].get_score();
            }
            table[target_row].clear();
        }
        table[target_row].push_back(card);
        hands[hand_index].inc_score(score);
    } else {
        int score = 0;
        //std::cout << "[Card value " << std::to_string(card.get_value()) << "]: ID of row to take and replace: ";
        //std::cin >> target_row;
        target_row = 0;
        for(int i = 0; i < table[target_row].size(); i++){
            score += table[target_row][i].get_score();
        }
        table[target_row].clear();
        table[target_row].push_back(card);
        hands[hand_index].inc_score(score);
    }
}

void Game::reset(){

}
