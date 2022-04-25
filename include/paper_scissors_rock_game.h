#pragma once

#include <string>
#include <vector>
#include <ranges>
#include <random>
#include <set>
#include <unordered_map>

#include "game.h"
#include "referee.h"

namespace imc::game {
    class PaperScissorsRockGame : public IGame {

    public:
        enum class GameMove {
            PAPER = 0,
            ROCK = 1,
            SCISSORS = 2

        };

        //since I use unordered_map
        struct GameMoveHash {
            std::size_t operator()(GameMove t) const {
                return static_cast<std::size_t>(t);
            }
        };

        GameScore play(int number_of_games) override;

    private:
        [[nodiscard]] GameMove get_random_move() const;

        [[nodiscard]] bool is_valid_move(int) const;

        [[nodiscard]] GameMove get_player_move() const;

        static constexpr std::string_view menu{"Choose your move: \n"
                                               "1. Paper.\n"
                                               "2. Scissors.\n"
                                               "3. Rock.\n"};

        static std::string get_move_string(const GameMove &move);
        static void print_scoreboard(uint wins, uint draws, uint games_played);

        const static std::unordered_map<GameMove, std::unordered_set<GameMove>, GameMoveHash> rules_;
        Referee<GameMove, GameMoveHash> referee_{rules_};
        const std::vector<GameMove> moves_{GameMove::PAPER, GameMove::SCISSORS, GameMove::ROCK};
    };


}

