#pragma once

#include <array>
#include <cstddef>
#include <random>
#include <vector>

namespace yams {

/**
 * @brief Represente les 5 des d'une main de Yams et gere leurs lancers.
 */
class DiceHand {
public:
    static constexpr std::size_t Size = 5;
    using Values = std::array<int, Size>;

    /**
     * @brief Construit une main de des avec des valeurs par defaut (non lancee).
     */
    DiceHand();

    /**
     * @brief Construit une main de des a partir de valeurs deja connues.
     * @param values Les 5 valeurs (1 a 6) a affecter aux des, dans l'ordre.
     */
    explicit DiceHand(const Values& values);

    /**
     * @brief Relance les 5 des.
     * @param rng Generateur pseudo-aleatoire utilise pour tirer les nouvelles valeurs.
     */
    void rollAll(std::mt19937& rng);

    /**
     * @brief Relance uniquement les des aux indices donnes (0..4).
     * @param indices Positions (0 a 4) des des a relancer ; les autres des sont conserves.
     * @param rng Generateur pseudo-aleatoire utilise pour tirer les nouvelles valeurs.
     */
    void rollIndices(const std::vector<std::size_t>& indices, std::mt19937& rng);

    /**
     * @brief Fixe directement les valeurs des des (utile pour les tests).
     * @param values Les 5 valeurs (1 a 6) a affecter aux des, dans l'ordre.
     */
    void setValues(const Values& values);

    /**
     * @brief Renvoie les valeurs actuelles des 5 des.
     * @return Les 5 valeurs de des courantes.
     */
    const Values& values() const;

private:
    Values values_;
};

/**
 * @brief Genere un generateur pseudo-aleatoire a partir d'une graine,
 *        pour permettre des lancers reproductibles (tests, replays).
 * @param seed Graine d'initialisation du generateur.
 * @return Un generateur pseudo-aleatoire initialise avec la graine donnee.
 */
std::mt19937 makeSeededRng(unsigned int seed);

}  // namespace yams
