#pragma once

#include <array>
#include <cstddef>
#include <string_view>

namespace yams {

/**
 * @brief Les 13 categories de la grille de score d'un joueur.
 */
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

/**
 * @brief Toutes les categories, dans l'ordre de la grille.
 * @return Un tableau contenant les 13 categories.
 */
std::array<ScoreCategory, CategoryCount> allCategories();

/**
 * @brief Vrai pour les 6 categories "chiffres" (As a Six).
 * @param category La categorie a tester.
 * @return true si la categorie appartient a la section superieure, false sinon.
 */
bool isUpperSection(ScoreCategory category);

/**
 * @brief Nom lisible de la categorie (en francais), pour l'affichage.
 * @param category La categorie dont on veut le nom.
 * @return Le nom lisible de la categorie.
 */
std::string_view toString(ScoreCategory category);

}  // namespace yams
