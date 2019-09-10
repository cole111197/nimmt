#include "game.h"

Game::Game(Deck deck){
    for(int i = 0; i < 4; i++){
        std::vector<Card> temp;
        temp.push_back(deck.draw());
        table.push_back(temp);
    }
}

std::string Game::to_string(){
    return temp.at(0).at(0);
}
S
void Game::reset(){

}
