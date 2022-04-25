#pragma once

namespace imc::game {
    enum class GameResult {
        WIN,
        LOSE,
        DRAW
    };

    struct GameScore {
        int wins;
        int draws;
        int total_games;
    };


    struct IGame {
        virtual GameScore play(int number_of_games) = 0;

        virtual ~IGame() = default;
    };

}

