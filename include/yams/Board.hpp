#pragma once

#include <random>
#include <vector>

#include "yams/Dice.hpp"

namespace yams {

// Le plateau de jeu : les des du tour en cours et le nombre de lancers
// deja effectues (3 lancers max par tour).
class Board {
public:
    static constexpr int MaxRolls = 3;

    Board();

    // Reinitialise le plateau pour un nouveau tour (nombre de lancers remis a zero).
    void startTurn();

    // Relance tous les des.
    void roll(std::mt19937& rng);

    // Relance uniquement les des selectionnes.
    void rollIndices(const std::vector<std::size_t>& indices, std::mt19937& rng);

    int rollsPlayed() const;
    bool canRoll() const;

    const DiceHand& diceHand() const;

private:
    DiceHand dice_;
    int rollsPlayed_;
};

}  // namespace yams
