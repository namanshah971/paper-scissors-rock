#pragma once

#include "game.h"
#include <unordered_map>
#include <unordered_set>


namespace imc::game {

    // I chose template instead of making this class with
    // virtual functions as the code becomes succint, more readable
    template<typename Move, typename MoveHash>
    class Referee {
    public:
        explicit Referee(const std::unordered_map<Move, std::unordered_set<Move>, MoveHash> &rules) : rules_(rules) {}

        GameResult judge(const Move &player_move, const Move &computer_move) const {
            if (player_move == computer_move) {
                return GameResult::DRAW;
            }

            // I left this unchecked as the program should crash
            // if rules are not defined for all the valid moves
            return rules_.at(player_move).contains(computer_move) ? GameResult::WIN : GameResult::LOSE;
        };

    private:
        // I use unordered_set and not just the individual
        // value so that rules can be used when a single move
        // could win against multiple moves
        std::unordered_map<Move, std::unordered_set<Move>, MoveHash> rules_{};
    };
}
