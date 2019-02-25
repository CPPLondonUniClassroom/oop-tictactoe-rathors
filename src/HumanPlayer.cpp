#include "HumanPlayer.h"
#include "utility.h"

#include <algorithm>

HumanPlayer::HumanPlayer(char symbol) : symbol{symbol} {}

BoardPosition HumanPlayer::TakeTurn(const std::vector<BoardPosition>& freePositions) {
    if (freePositions.size() == 1)
        return freePositions.front();
    PrintMessage(symbol, " - Take your turn. Available positions are: ");
    for (const auto& i : freePositions)
        PrintMessage(BoardPositionToInt(i) + 1, ' ');
    auto pos = ReadNumber(1, 9) - 1;
    auto ret = NumberToBoardPosition(pos);
    if (std::find(freePositions.begin(), freePositions.end(), ret) != freePositions.end())
        return ret;
    PrintMessage("ERROR: NOT A VALID OPTION. CHOOSE AGAIN\n");
    return TakeTurn(freePositions);
}

char HumanPlayer::Symbol() const {
    return symbol;
}