#pragma once

#include <cstddef>
#include <vector>

#include "yams/Board.hpp"
#include "yams/Player.hpp"

namespace yams {

/**
 * @brief Orchestre le deroulement d'une partie : joueurs, tour courant, fin de partie.
 */
class Game {
public:
    /**
     * @brief Construit une partie a partir de la liste des joueurs qui y participent.
     * @param players Les joueurs de la partie, dans leur ordre de passage.
     */
    explicit Game(std::vector<Player> players);

    /**
     * @brief Renvoie la liste des joueurs de la partie.
     * @return Les joueurs de la partie.
     */
    const std::vector<Player>& players() const;

    /**
     * @brief Renvoie le joueur dont c'est le tour (acces modifiable).
     * @return Le joueur courant.
     */
    Player& currentPlayer();

    /**
     * @brief Renvoie le joueur dont c'est le tour (acces en lecture seule).
     * @return Le joueur courant.
     */
    const Player& currentPlayer() const;

    /**
     * @brief Renvoie le plateau de jeu du tour en cours (acces modifiable).
     * @return Le plateau de jeu.
     */
    Board& board();

    /**
     * @brief Renvoie le plateau de jeu du tour en cours (acces en lecture seule).
     * @return Le plateau de jeu.
     */
    const Board& board() const;

    /**
     * @brief Passe au joueur suivant.
     */
    void advanceToNextPlayer();

    /**
     * @brief Vrai quand tous les joueurs ont rempli leur grille de score.
     * @return true si la partie est terminee, false sinon.
     */
    bool isOver() const;

    /**
     * @brief Le(s) joueur(s) avec le meilleur score total, une fois la partie terminee.
     * @return La liste des joueurs gagnants (plusieurs en cas d'egalite).
     */
    std::vector<const Player*> winners() const;

private:
    std::vector<Player> players_;
    std::size_t currentPlayerIndex_;
    Board board_;
};

}  // namespace yams
