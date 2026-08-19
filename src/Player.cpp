#include "yams/Player.hpp"

namespace yams {

Player::Player(std::string name) {
    (void)name;
    // TODO
}

const std::string& Player::name() const {
    // TODO
    static std::string placeholder;
    return placeholder;
}

ScoreCard& Player::scoreCard() {
    // TODO
    return scoreCard_;
}

const ScoreCard& Player::scoreCard() const {
    // TODO
    return scoreCard_;
}

}  // namespace yams
