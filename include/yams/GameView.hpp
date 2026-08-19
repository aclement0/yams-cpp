#pragma once

#include <ostream>
#include <string>
#include <vector>

#include "yams/Board.hpp"
#include "yams/Player.hpp"

namespace yams {

/**
 * @brief Vue (au sens MVC) chargee d'afficher l'etat du jeu.
 *
 * Ne modifie jamais le modele (Board, Player, ScoreCard, ...) : elle se
 * contente de le lire et d'ecrire une representation textuelle dans le
 * flux de sortie qui lui a ete fourni. La logique de jeu reste dans le
 * modele, le pilotage (lecture des entrees, enchainement des tours)
 * relevera d'un futur controleur.
 */
class GameView {
public:
    /**
     * @brief Construit une vue qui ecrit dans le flux donne.
     * @param out Flux de sortie utilise pour tous les affichages (ex: std::cout).
     */
    explicit GameView(std::ostream& out);

    /**
     * @brief Affiche le message d'accueil du jeu.
     */
    void displayWelcome() const;

    /**
     * @brief Affiche les 5 valeurs de des d'une main.
     * @param dice La main de des a afficher.
     */
    void displayDiceHand(const DiceHand& dice) const;

    /**
     * @brief Affiche l'etat du plateau : des du tour et lancers restants.
     * @param board Le plateau de jeu a afficher.
     */
    void displayBoard(const Board& board) const;

    /**
     * @brief Affiche la grille de score complete d'un joueur (categories
     *        remplies, sous-totaux, bonus, total general).
     * @param player Le joueur dont on affiche la grille de score.
     */
    void displayScoreCard(const Player& player) const;

    /**
     * @brief Annonce le joueur dont c'est le tour de jouer.
     * @param player Le joueur dont c'est le tour.
     */
    void displayCurrentPlayerTurn(const Player& player) const;

    /**
     * @brief Affiche un message generique (information, erreur, consigne...).
     * @param message Le texte a afficher.
     */
    void displayMessage(const std::string& message) const;

    /**
     * @brief Affiche le(s) gagnant(s) en fin de partie.
     * @param winners Les joueurs gagnants (plusieurs en cas d'egalite).
     */
    void displayWinners(const std::vector<const Player*>& winners) const;

private:
    std::ostream& out_;
};

}  // namespace yams
