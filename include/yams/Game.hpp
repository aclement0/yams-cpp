#pragma once

#include <cstddef>
#include <vector>

#include "yams/Board.hpp"
#include "yams/Player.hpp"

namespace yams {

// Orchestre le deroulement d'une partie : joueurs, tour courant, fin de partie.
class Game {
public:
    explicit Game(std::vector<Player> players);

    const std::vector<Player>& players() const;

    Player& currentPlayer();
    const Player& currentPlayer() const;

    Board& board();
    const Board& board() const;

    // Passe au joueur suivant.
    void advanceToNextPlayer();

    // Vrai quand tous les joueurs ont rempli leur grille de score.
    bool isOver() const;

    // Le(s) joueur(s) avec le meilleur score total, une fois la partie terminee.
    std::vector<const Player*> winners() const;

private:
    std::vector<Player> players_;
    std::size_t currentPlayerIndex_;
    Board board_;
};

}  // namespace yams
