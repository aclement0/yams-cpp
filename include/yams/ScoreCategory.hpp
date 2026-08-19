#pragma once

#include <array>
#include <cstddef>
#include <string_view>

namespace yams {

// Les 13 categories de la grille de score d'un joueur.
enum class ScoreCategory {
    Ones,
    Twos,
    Threes,
    Fours,
    Fives,
    Sixes,
    ThreeOfAKind,
    FourOfAKind,
    FullHouse,
    SmallStraight,
    LargeStraight,
    Yams,
    Chance,
};

inline constexpr std::size_t CategoryCount = 13;

// Toutes les categories, dans l'ordre de la grille.
std::array<ScoreCategory, CategoryCount> allCategories();

// Vrai pour les 6 categories "chiffres" (As a Six).
bool isUpperSection(ScoreCategory category);

// Nom lisible de la categorie (en francais), pour l'affichage.
std::string_view toString(ScoreCategory category);

}  // namespace yams
