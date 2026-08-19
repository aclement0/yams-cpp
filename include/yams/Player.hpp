#pragma once

#include <string>

#include "yams/ScoreCard.hpp"

namespace yams {

/**
 * @brief Un joueur : un nom et sa grille de score.
 */
class Player {
public:
    /**
     * @brief Construit un joueur avec son nom et une grille de score vide.
     * @param name Nom affiche du joueur.
     */
    explicit Player(std::string name);

    /**
     * @brief Renvoie le nom du joueur.
     * @return Le nom du joueur.
     */
    const std::string& name() const;

    /**
     * @brief Renvoie la grille de score du joueur (acces modifiable).
     * @return La grille de score du joueur.
     */
    ScoreCard& scoreCard();

    /**
     * @brief Renvoie la grille de score du joueur (acces en lecture seule).
     * @return La grille de score du joueur.
     */
    const ScoreCard& scoreCard() const;

private:
    std::string name_;
    ScoreCard scoreCard_;
};

}  // namespace yams
