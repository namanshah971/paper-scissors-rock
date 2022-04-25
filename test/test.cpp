#include <string>
#include "../include/referee.h"


void test_referee_with_valid_rules() {
    std::string a{"a"};
    std::string b{"b"};

    const std::unordered_map<std::string, std::unordered_set<std::string>> rules{{a, {b}},
                                                                                 {b, {}}};
    imc::game::Referee<std::string, std::hash<std::string>> referee{rules};

    const auto result = referee.judge(a, b);
    assert(imc::game::GameResult::WIN == result);
    const auto result2 = referee.judge(b, a);
    assert(imc::game::GameResult::LOSE == result2);
    const auto result3 = referee.judge(a, a);
    assert(imc::game::GameResult::DRAW == result3);
}

void test_referee_fail_when_rules_not_defined_for_every_move() {
    std::string a{"a"};
    std::string b{"b"};

    const std::unordered_map<std::string, std::unordered_set<std::string>> rules{{a, {b}}};
    imc::game::Referee<std::string, std::hash<std::string>> referee{rules};

    const auto result = referee.judge(a, b);
    assert(imc::game::GameResult::WIN == result);
    const auto result3 = referee.judge(a, a);
    assert(imc::game::GameResult::DRAW == result3);

    bool exception_thrown{false};
    try {
        referee.judge(b, a);
    }
    catch (const std::out_of_range &e) {
        exception_thrown = true;
    }

    assert(exception_thrown);

}


int main() {
    test_referee_with_valid_rules();
    test_referee_fail_when_rules_not_defined_for_every_move();
    return 0;
}



