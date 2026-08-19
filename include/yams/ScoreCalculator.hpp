#pragma once

#include "yams/Dice.hpp"
#include "yams/ScoreCategory.hpp"

namespace yams {

// Calcule le score obtenu pour une categorie donnee, a partir d'une main de des.
// Ne connait rien des grilles de score ni des regles de joker/bonus Yams :
// ces regles relevent du controleur de partie (voir Game, a venir).
class ScoreCalculator {
public:
    static int score(ScoreCategory category, const DiceHand::Values& dice);
};

}  // namespace yams
