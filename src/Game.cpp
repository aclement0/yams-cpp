#include "yams/Game.hpp"

namespace yams {

Game::Game(std::vector<Player> players) : players_(std::move(players)), currentPlayerIndex_(0) {
    // TODO
}

const std::vector<Player>& Game::players() const {
    // TODO
    return players_;
}

Player& Game::currentPlayer() {
    // TODO
    return players_[currentPlayerIndex_];
}

const Player& Game::currentPlayer() const {
    // TODO
    return players_[currentPlayerIndex_];
}

Board& Game::board() {
    // TODO
    return board_;
}

const Board& Game::board() const {
    // TODO
    return board_;
}

void Game::advanceToNextPlayer() {
    // TODO
}

bool Game::isOver() const {
    // TODO
    return false;
}

std::vector<const Player*> Game::winners() const {
    // TODO
    return {};
}

}  // namespace yams
