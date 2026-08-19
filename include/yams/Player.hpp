#pragma once

#include <string>

#include "yams/ScoreCard.hpp"

namespace yams {

// Un joueur : un nom et sa grille de score.
class Player {
public:
    explicit Player(std::string name);

    const std::string& name() const;

    ScoreCard& scoreCard();
    const ScoreCard& scoreCard() const;

private:
    std::string name_;
    ScoreCard scoreCard_;
};

}  // namespace yams
