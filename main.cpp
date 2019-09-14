#include "card.h"
#include "hand.h"
#include "deck.h"
#include "game.h"
#include <iostream>
#include <vector>

const int NUM_PLAYERS = 4;
const int USER = 0;

int main(){
    Game game{NUM_PLAYERS};
    for(int i = 0; i < 10; i++){
            std::cout << game.to_string() << std::endl;
            int card_choice = 0;
            //User play
            std::cout << "Please select a card:" << std::endl;
            game.print_hand(USER);
            std::cin >> card_choice;
            //Check if card choice is valid
            while(card_choice > 9-i || card_choice < 0){
                std::cout << "Invalid card choice. Please reselect" << std::endl;
                game.print_hand(USER);
                std::cin >> card_choice;
            }
            game.play(card_choice);
            //Computer(s) play
            for(int h = 1; h < NUM_PLAYERS; h++){
                game.play(h,0);
                //std::cout << game.to_string() << std::endl;
                //std::cout << "Hand " << h << " score: " << std::to_string(game.get_hand_score(h)) << std::endl;
            }
    }
    std::cout << "-----------------\nScores:" << std::endl;
    for(int h = 0; h < NUM_PLAYERS; h++){
        std::cout << "Hand " << h << " score: " << std::to_string(game.get_hand_score(h)) << std::endl;
    }
    std::cout << "-----------------" << std::endl;
}
