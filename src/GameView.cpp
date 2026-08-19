#include "yams/GameView.hpp"

namespace yams {

GameView::GameView(std::ostream& out) : out_(out) {
    // TODO
}

void GameView::displayWelcome() const {
    // TODO
}

void GameView::displayDiceHand(const DiceHand& dice) const {
    (void)dice;
    // TODO
}

void GameView::displayBoard(const Board& board) const {
    (void)board;
    // TODO
}

void GameView::displayScoreCard(const Player& player) const {
    (void)player;
    // TODO
}

void GameView::displayCurrentPlayerTurn(const Player& player) const {
    (void)player;
    // TODO
}

void GameView::displayMessage(const std::string& message) const {
    (void)message;
    // TODO
}

void GameView::displayWinners(const std::vector<const Player*>& winners) const {
    (void)winners;
    // TODO
}

}  // namespace yams
