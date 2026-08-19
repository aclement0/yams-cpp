#pragma once

#include <random>
#include <vector>

#include "yams/Dice.hpp"

namespace yams {

/**
 * @brief Le plateau de jeu : les des du tour en cours et le nombre de lancers
 *        deja effectues (3 lancers max par tour).
 */
class Board {
public:
    static constexpr int MaxRolls = 3;

    /**
     * @brief Construit un plateau vide, sans lancer effectue.
     */
    Board();

    /**
     * @brief Reinitialise le plateau pour un nouveau tour (nombre de lancers remis a zero).
     */
    void startTurn();

    /**
     * @brief Relance tous les des du tour en cours.
     * @param rng Generateur pseudo-aleatoire utilise pour tirer les nouvelles valeurs.
     */
    void roll(std::mt19937& rng);

    /**
     * @brief Relance uniquement les des selectionnes du tour en cours.
     * @param indices Positions (0 a 4) des des a relancer ; les autres des sont conserves.
     * @param rng Generateur pseudo-aleatoire utilise pour tirer les nouvelles valeurs.
     */
    void rollIndices(const std::vector<std::size_t>& indices, std::mt19937& rng);

    /**
     * @brief Nombre de lancers deja effectues dans le tour courant (0 a MaxRolls).
     * @return Le nombre de lancers effectues.
     */
    int rollsPlayed() const;

    /**
     * @brief Vrai si le nombre de lancers max (MaxRolls) n'est pas encore atteint.
     * @return true si un lancer supplementaire est possible, false sinon.
     */
    bool canRoll() const;

    /**
     * @brief Renvoie la main de des courante du plateau.
     * @return La main de des du tour en cours.
     */
    const DiceHand& diceHand() const;

private:
    DiceHand dice_;
    int rollsPlayed_;
};

}  // namespace yams
