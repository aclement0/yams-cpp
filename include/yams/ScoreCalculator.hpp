#pragma once

#include "yams/Dice.hpp"
#include "yams/ScoreCategory.hpp"

namespace yams {

/**
 * @brief Calcule le score obtenu pour une categorie donnee, a partir d'une main de des.
 *
 * Ne connait rien des grilles de score ni des regles de joker/bonus Yams :
 * ces regles relevent du controleur de partie (voir Game, a venir).
 */
class ScoreCalculator {
public:
    /**
     * @brief Calcule le score obtenu pour une categorie donnee, a partir d'une main de des.
     * @param category La categorie pour laquelle calculer le score.
     * @param dice Les 5 valeurs de des sur lesquelles baser le calcul.
     * @return Le score obtenu pour cette categorie avec cette main de des.
     */
    static int score(ScoreCategory category, const DiceHand::Values& dice);
};

}  // namespace yams
