#include <iostream>

#include "../include/paper_scissors_rock_game.h"
#include <unordered_map>

using namespace imc::game;
using GameMove = PaperScissorsRockGame::GameMove;
using GameMoveHash = PaperScissorsRockGame::GameMoveHash;

const std::unordered_map<GameMove, std::unordered_set<GameMove>, GameMoveHash> PaperScissorsRockGame::rules_{{GameMove::PAPER,    {GameMove::ROCK}},
                                                                                                             {GameMove::ROCK,     {GameMove::SCISSORS}},
                                                                                                             {GameMove::SCISSORS, {GameMove::PAPER}}};

GameScore PaperScissorsRockGame::play(int number_of_games) {
    srand(time(0));

    int wins{0};
    int draws{0};

    std::cout << menu << std::endl;

    for (int games_played = 1; games_played <= number_of_games; games_played++) {
        std::cout << "Enter your move: ";
        const auto player_move = get_player_move();
        std::cout << "You chose: " << get_move_string(player_move) << std::endl;

        const auto computer_move = get_random_move();
        std::cout << "Computer chose: " << get_move_string(computer_move) << std::endl;

        const auto result = referee_.judge(player_move, computer_move);

        std::cout << "RESULT: ";
        if (result == GameResult::WIN) {
            std::cout << "Win\n" << std::endl;
            wins++;
        } else if (result == GameResult::DRAW) {
            std::cout << "Draw\n" << std::endl;
            draws++;
        } else {
            std::cout << "Lose\n" << std::endl;
        }

        print_scoreboard(wins, draws, games_played);

    }

    return {wins, draws, number_of_games};
}

GameMove PaperScissorsRockGame::get_random_move() const {
    //Next step: use <random> library to make this purely random
    return moves_[rand() % moves_.size()];
}

std::string PaperScissorsRockGame::get_move_string(const GameMove &move) {
    switch (move) {
        case GameMove::PAPER:
            return "PAPER";
        case GameMove::SCISSORS:
            return "SCISSORS";
        default:
            return "ROCK";
    }

}

bool PaperScissorsRockGame::is_valid_move(int option) const {
    return option > 0 && option <= moves_.size();
}

GameMove PaperScissorsRockGame::get_player_move() const {
    int option;
    for (;;) {
        if (std::cin >> option && is_valid_move(option)) {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Wrong move! Enter move again: ";
    }

    return moves_.at(option - 1);
}

void PaperScissorsRockGame::print_scoreboard(uint wins, uint draws, uint games_played) {
    std::cout << "SCOREBOARD: " << std::endl;
    std::cout << "WINS: " << wins << std::endl;
    std::cout << "DRAWS: " << draws << std::endl;
    std::cout << "GAMES PLAYED: " << games_played << std::endl;
}

