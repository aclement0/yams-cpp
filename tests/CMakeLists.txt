include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.4
)
FetchContent_MakeAvailable(Catch2)

add_executable(yams_tests
    test_dice.cpp
    test_score_category.cpp
    test_score_calculator.cpp
    test_score_card.cpp
    test_player.cpp
    test_board.cpp
    test_game.cpp
)
target_link_libraries(yams_tests PRIVATE yams_engine Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)
catch_discover_tests(yams_tests)
