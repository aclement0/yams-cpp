#include "yams/ScoreCard.hpp"

namespace yams {

ScoreCard::ScoreCard() {
    // TODO
}

bool ScoreCard::isFilled(ScoreCategory category) const {
    (void)category;
    // TODO
    return false;
}

std::optional<int> ScoreCard::scoreFor(ScoreCategory category) const {
    (void)category;
    // TODO
    return std::nullopt;
}

void ScoreCard::recordScore(ScoreCategory category, int score) {
    (void)category;
    (void)score;
    // TODO
}

int ScoreCard::upperSectionSubtotal() const {
    // TODO
    return 0;
}

int ScoreCard::upperSectionBonus() const {
    // TODO
    return 0;
}

int ScoreCard::upperSectionTotal() const {
    // TODO
    return 0;
}

int ScoreCard::lowerSectionTotal() const {
    // TODO
    return 0;
}

int ScoreCard::grandTotal() const {
    // TODO
    return 0;
}

bool ScoreCard::isComplete() const {
    // TODO
    return false;
}

}  // namespace yams
