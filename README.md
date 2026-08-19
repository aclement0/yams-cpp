# Yams (Yahtzee) en C++

Réimplémentation du jeu de société **Yams** (aussi connu sous le nom *Yahtzee*) en C++, jouable dans un premier temps en console, avec une architecture pensée pour évoluer vers une interface graphique par la suite.

## Sommaire

- [Présentation](#présentation)
- [Règles du jeu](#règles-du-jeu)
  - [Matériel](#matériel)
  - [Déroulement d'un tour](#déroulement-dun-tour)
  - [Grille de score](#grille-de-score)
  - [Fin de partie](#fin-de-partie)
- [Objectifs du projet](#objectifs-du-projet)
- [Fonctionnalités prévues](#fonctionnalités-prévues)
- [Architecture envisagée](#architecture-envisagée)
- [Structure du dépôt](#structure-du-dépôt)
- [Prérequis](#prérequis)
- [Compilation](#compilation)
- [Utilisation](#utilisation)
- [Feuille de route](#feuille-de-route)
- [Tests](#tests)
- [Contribuer](#contribuer)
- [Licence](#licence)

## Présentation

Le Yams se joue avec **5 dés à 6 faces**. Chaque joueur dispose, à tour de rôle, de **3 lancers maximum** par tour pour essayer de constituer la meilleure combinaison possible, puis doit inscrire son résultat dans l'une des **13 catégories** de sa grille de score. La partie se termine lorsque toutes les catégories de tous les joueurs sont remplies. Le joueur avec le score total le plus élevé remporte la partie.

## Règles du jeu

### Matériel

- 5 dés à 6 faces.
- Une grille de score par joueur (13 catégories, réparties en une section "Chiffres" et une section "Combinaisons").
- Un gobelet à dés (optionnel, non simulé).

### Déroulement d'un tour

1. Le joueur lance les 5 dés.
2. Il peut relancer tout ou partie des dés jusqu'à **2 fois supplémentaires** (donc 3 lancers max par tour).
3. Après le dernier lancer (ou plus tôt s'il le souhaite), le joueur doit choisir **une catégorie non encore utilisée** de sa grille et y inscrire le score correspondant au résultat de ses dés (le score peut être 0 si la combinaison ne correspond à rien d'intéressant, mais la case est alors "brûlée").
4. C'est au tour du joueur suivant.

### Grille de score

**Section supérieure (chiffres)** — la somme des dés montrant la valeur demandée :

| Catégorie | Score |
|---|---|
| As (1) | Somme des 1 |
| Deux (2) | Somme des 2 |
| Trois (3) | Somme des 3 |
| Quatre (4) | Somme des 4 |
| Cinq (5) | Somme des 5 |
| Six (6) | Somme des 6 |

> **Bonus** : si le total de la section supérieure atteint **63 points ou plus**, un bonus de **35 points** est ajouté (ce seuil correspond à obtenir 3 exemplaires de chaque chiffre).

**Section inférieure (combinaisons)** :

| Catégorie | Règle | Score |
|---|---|---|
| Brelan (Three of a Kind) | Au moins 3 dés identiques | Somme de tous les dés |
| Carré (Four of a Kind) | Au moins 4 dés identiques | Somme de tous les dés |
| Full House | 3 dés identiques + 2 dés identiques (paire différente) | 25 points fixes |
| Petite Suite (Small Straight) | 4 valeurs consécutives | 30 points fixes |
| Grande Suite (Large Straight) | 5 valeurs consécutives | 40 points fixes |
| Yams | 5 dés identiques | 50 points fixes |
| Chance | N'importe quelle combinaison | Somme de tous les dés |

> **Yams bonus** : si un joueur obtient un second Yams (ou plus) alors que la case "Yams" est déjà remplie avec 50 points, il gagne généralement un bonus de **100 points** supplémentaires par Yams additionnel (règle à confirmer/paramétrer selon la variante choisie), et doit utiliser la valeur des dés pour remplir une autre case selon les règles de "joker" (le dé peut être utilisé comme joker dans la section chiffres correspondante, ou dans une combinaison de la section inférieure si la case du chiffre correspondant est déjà remplie).

### Fin de partie

La partie se termine quand chaque joueur a rempli les 13 cases de sa grille. Le score final est la somme de la section supérieure (bonus inclus) et de la section inférieure (bonus Yams inclus). Le joueur avec le score total le plus élevé gagne.

## Objectifs du projet

- Implémenter un moteur de jeu **fidèle aux règles officielles** du Yams, testable indépendamment de l'interface.
- Proposer une **interface console** simple et lisible pour commencer.
- Garder une architecture **découplée** (logique de jeu / affichage / entrées utilisateur) pour pouvoir brancher une interface graphique (SFML, Qt, Dear ImGui...) plus tard sans réécrire le moteur.
- Supporter plusieurs joueurs en local (tour par tour).
- Code **moderne, propre et testé** (C++17/20, CMake, tests unitaires).

## Fonctionnalités prévues

- [ ] Lancer de dés avec relances sélectives (choix des dés à garder/relancer).
- [ ] Détection automatique de toutes les combinaisons possibles à partir d'un lancer.
- [ ] Calcul des scores pour chaque catégorie (y compris bonus section supérieure et bonus Yams).
- [ ] Grille de score par joueur avec suggestion des cases encore disponibles.
- [ ] Mode multijoueur local (2 à N joueurs, au même clavier).
- [ ] Sauvegarde / reprise de partie (sérialisation simple, JSON ou fichier texte).
- [ ] Mode "aide" affichant le score potentiel de chaque catégorie disponible avant validation.
- [ ] (Optionnel, plus tard) IA simple pour jouer contre l'ordinateur.
- [ ] (Optionnel, plus tard) Interface graphique.

## Architecture envisagée

Séparation en couches pour faciliter les tests et l'évolution vers une UI graphique :

```
+---------------------+
|   Interface (CLI)   |   <- affichage, saisie utilisateur
+---------------------+
|   Contrôleur / Jeu  |   <- déroulement d'une partie, tours, joueurs
+---------------------+
|   Moteur de règles  |   <- Dice, ScoreCategory, ScoreCalculator, ScoreCard
+---------------------+
```

Quelques classes clés envisagées :

- `Dice` / `DiceHand` : représente les 5 dés, gère le lancer et les relances sélectives.
- `ScoreCategory` : énumération des 13 catégories.
- `ScoreCalculator` : calcule le score obtenu pour une combinaison donnée, pour chaque catégorie.
- `ScoreCard` : grille de score d'un joueur (catégories remplies, total, bonus).
- `Player` : identité + `ScoreCard` du joueur.
- `Game` : orchestre le déroulement de la partie (tours, joueurs, fin de partie).
- `ConsoleUI` : affichage et interactions en ligne de commande.

## Structure du dépôt

```
yams-cpp/
├── CMakeLists.txt
├── README.md
├── include/
│   └── yams/            # en-têtes publics du moteur de jeu
├── src/                 # implémentation du moteur + main.cpp
├── tests/                # tests unitaires (ex: Catch2 / GoogleTest)
└── docs/                 # notes de conception, variantes de règles
```

> Structure indicative : elle sera mise en place au fur et à mesure du développement.

## Prérequis

- Un compilateur C++17 (ou supérieur) : g++, clang++...
- [CMake](https://cmake.org/) >= 3.16
- (Optionnel) [Catch2](https://github.com/catchorg/Catch2) ou [GoogleTest](https://github.com/google/googletest) pour les tests unitaires

## Compilation

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

## Utilisation

```bash
./yams
```

Le jeu se joue ensuite au clavier : choix des dés à relancer, choix de la catégorie où inscrire son score, etc.

> À détailler une fois l'interface console implémentée.

## Feuille de route

1. **V0 — Moteur de règles** : dés, calcul de score pour chaque catégorie, tests unitaires.
2. **V1 — Boucle de jeu console** : un joueur, un tour complet (lancers, relances, choix de catégorie), grille affichée en console.
3. **V2 — Multijoueur local** : plusieurs joueurs, gestion des tours, écran de fin de partie avec classement.
4. **V3 — Confort de jeu** : sauvegarde/reprise, aide au score, historique de partie.
5. **V4 (optionnel) — IA** : joueur contrôlé par l'ordinateur avec une stratégie simple.
6. **V5 (optionnel) — Interface graphique**.

## Tests

Les tests unitaires couvriront en priorité le moteur de règles (`ScoreCalculator`, `ScoreCard`, `DiceHand`) car c'est la partie la plus sensible aux erreurs (calcul des scores, bonus, cas limites comme le Yams bonus ou les jokers).

```bash
cd build
ctest
```

## Contribuer

Projet personnel d'apprentissage. Les suggestions et retours sont bienvenus via les issues.

## Licence

À définir (MIT par défaut si aucune contrainte particulière).
