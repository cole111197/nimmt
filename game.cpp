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

void Game::play(Card card, int row){
    table[row].push_back(card);
}

void Game::reset(){

}
