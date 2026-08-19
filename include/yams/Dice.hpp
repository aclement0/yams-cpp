#pragma once

#include <array>
#include <cstddef>
#include <random>
#include <vector>

namespace yams {

// Represente les 5 des d'une main de Yams et gere leurs lancers.
class DiceHand {
public:
    static constexpr std::size_t Size = 5;
    using Values = std::array<int, Size>;

    DiceHand();
    explicit DiceHand(const Values& values);

    // Relance les 5 des.
    void rollAll(std::mt19937& rng);

    // Relance uniquement les des aux indices donnes (0..4).
    void rollIndices(const std::vector<std::size_t>& indices, std::mt19937& rng);

    // Fixe directement les valeurs des des (utile pour les tests).
    void setValues(const Values& values);

    const Values& values() const;

private:
    Values values_;
};

// Genere un generateur pseudo-aleatoire a partir d'une graine,
// pour permettre des lancers reproductibles (tests, replays).
std::mt19937 makeSeededRng(unsigned int seed);

}  // namespace yams
