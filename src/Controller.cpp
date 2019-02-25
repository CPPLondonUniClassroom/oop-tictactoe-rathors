#include "Controller.h"
#include "utility.h"

#include <algorithm>

static bool TestRowForWinner(const std::vector<char>& boardState, BoardPosition a, BoardPosition b, BoardPosition c) {
    //TODO: IMPLEMENT.
    return true;
}

static bool CheckForWinner(const std::vector<char>& boardState) {
    //TODO: IMPLEMENT.
    return true;
}

static void Winner(const IPlayer& player) {
    PrintMessage("Congratulations Player ", player.Symbol(), " - You won!");
}

//TODO: IMPLEMENT
//Controller::Controller(IRenderer& renderer, IPlayer& p1, IPlayer& p2)

void Controller::PlayGame() {
//TODO: IMPLEMENT
}
