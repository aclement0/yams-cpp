#pragma once

#include <array>
#include <optional>

#include "yams/ScoreCategory.hpp"

namespace yams {

/**
 * @brief Grille de score d'un joueur : une valeur (ou aucune) par categorie.
 */
class ScoreCard {
public:
    static constexpr int UpperBonusThreshold = 63;
    static constexpr int UpperBonusValue = 35;

    /**
     * @brief Construit une grille de score vide (aucune categorie remplie).
     */
    ScoreCard();

    /**
     * @brief Vrai si la categorie a deja un score enregistre.
     * @param category La categorie a tester.
     * @return true si la categorie est remplie, false sinon.
     */
    bool isFilled(ScoreCategory category) const;

    /**
     * @brief Renvoie le score enregistre pour la categorie, ou aucune valeur si non remplie.
     * @param category La categorie dont on veut le score.
     * @return Le score enregistre, ou std::nullopt si la categorie n'est pas remplie.
     */
    std::optional<int> scoreFor(ScoreCategory category) const;

    /**
     * @brief Enregistre le score d'une categorie. Comportement a definir si la
     *        categorie est deja remplie.
     * @param category La categorie a remplir.
     * @param score La valeur a enregistrer pour cette categorie.
     */
    void recordScore(ScoreCategory category, int score);

    /**
     * @brief Somme des scores des 6 categories "chiffres" (As a Six), hors bonus.
     * @return Le sous-total de la section superieure.
     */
    int upperSectionSubtotal() const;

    /**
     * @brief Bonus obtenu si upperSectionSubtotal() atteint UpperBonusThreshold, sinon 0.
     * @return Le bonus de la section superieure.
     */
    int upperSectionBonus() const;

    /**
     * @brief Somme du sous-total et du bonus de la section superieure.
     * @return Le total de la section superieure.
     */
    int upperSectionTotal() const;

    /**
     * @brief Somme des scores des categories de la section inferieure.
     * @return Le total de la section inferieure.
     */
    int lowerSectionTotal() const;

    /**
     * @brief Score total de la grille (section superieure + section inferieure).
     * @return Le score total.
     */
    int grandTotal() const;

    /**
     * @brief Vrai si les 13 categories ont ete remplies.
     * @return true si la grille est complete, false sinon.
     */
    bool isComplete() const;

private:
    std::array<std::optional<int>, CategoryCount> scores_;
};

}  // namespace yams
