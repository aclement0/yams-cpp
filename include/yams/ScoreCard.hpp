#pragma once

#include <array>
#include <optional>

#include "yams/ScoreCategory.hpp"

namespace yams {

// Grille de score d'un joueur : une valeur (ou aucune) par categorie.
class ScoreCard {
public:
    static constexpr int UpperBonusThreshold = 63;
    static constexpr int UpperBonusValue = 35;

    ScoreCard();

    bool isFilled(ScoreCategory category) const;
    std::optional<int> scoreFor(ScoreCategory category) const;

    // Enregistre le score d'une categorie. Comportement a definir si la
    // categorie est deja remplie.
    void recordScore(ScoreCategory category, int score);

    int upperSectionSubtotal() const;
    int upperSectionBonus() const;
    int upperSectionTotal() const;
    int lowerSectionTotal() const;
    int grandTotal() const;

    bool isComplete() const;

private:
    std::array<std::optional<int>, CategoryCount> scores_;
};

}  // namespace yams
