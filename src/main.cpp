#include <iostream>
#include "../include/paper_scissors_rock_game.h"


int main() {
    imc::game::PaperScissorsRockGame game{};

    std::cout << "Enter the number of games you want to play: ";

    int num_of_games;
    for (;;) {
        if (std::cin >> num_of_games && num_of_games > 0) {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong input! Enter again: ";
    }

    const auto score = game.play(num_of_games);
    std::cout << "\nFINAL SCORE: " << score.wins << "/" << score.draws << "/" << score.total_games;
    return 0;
}
