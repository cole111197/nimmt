#include "game.h"
#include <iostream>
#include <string>

Game::Game(Deck &deck){
    for(int i = 0; i < 4; i++){
        std::vector<Card> temp;
        temp.push_back(deck.draw());
        table.push_back(temp);
    }
}

std::string Game::to_string(){
    std::string temp;
    for (int i = 0; i < table.size(); i++)
    {
        for (int j = 0; j < table[i].size(); j++)
        {
            temp += table[i][j].to_string() + "  ";
        }
        temp += "\n";
    }
    return temp;
}

int Game::play(Card card){
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
        return score;
    } else {
        int score = 0;
        std::cout << "ID of row to take and replace: ";
        std::cin >> target_row;
        for(int i = 0; i < table[target_row].size(); i++){
            score += table[target_row][i].get_score();
        }
        table[target_row].clear();
        table[target_row].push_back(card);
        return score;
    }
}

void Game::reset(){

}
