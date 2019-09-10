#include "card.h"
#include "hand.h"
#include "deck.h"
#include "game.h"
#include <iostream>
#include <vector>

int main(){
    Game game{4};
    
    std::cout << game.to_string() << std::endl;
    for(int i = 0; i < 10; i++){
            for(int h = 0; h < 4; h++){
                game.play(h,0);
                std::cout << game.to_string() << std::endl;
                std::cout << "Hand " << h << " score: " << std::to_string(game.hand_score(h)) << std::endl;
            }
    }
    std::cout << "-------------\nScores:" << std::endl;
    for(int h = 0; h < 4; h++){
        std::cout << "Hand " << h << " score: " << std::to_string(game.hand_score(h)) << std::endl;
    }
}
