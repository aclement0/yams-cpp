#include "yams/Dice.hpp"

namespace yams {

DiceHand::DiceHand() {
    // TODO
}

DiceHand::DiceHand(const Values& values) {
    (void)values;
    // TODO
}

void DiceHand::rollAll(std::mt19937& rng) {
    (void)rng;
    // TODO
}

void DiceHand::rollIndices(const std::vector<std::size_t>& indices, std::mt19937& rng) {
    (void)indices;
    (void)rng;
    // TODO
}

void DiceHand::setValues(const Values& values) {
    (void)values;
    // TODO
}

const DiceHand::Values& DiceHand::values() const {
    // TODO
    static Values placeholder{};
    return placeholder;
}

std::mt19937 makeSeededRng(unsigned int seed) {
    (void)seed;
    // TODO
    return std::mt19937{};
}

}  // namespace yams
