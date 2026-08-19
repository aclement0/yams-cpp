#include "yams/Board.hpp"

namespace yams {

Board::Board() {
    // TODO
}

void Board::startTurn() {
    // TODO
}

void Board::roll(std::mt19937& rng) {
    (void)rng;
    // TODO
}

void Board::rollIndices(const std::vector<std::size_t>& indices, std::mt19937& rng) {
    (void)indices;
    (void)rng;
    // TODO
}

int Board::rollsPlayed() const {
    // TODO
    return 0;
}

bool Board::canRoll() const {
    // TODO
    return false;
}

const DiceHand& Board::diceHand() const {
    // TODO
    return dice_;
}

}  // namespace yams
