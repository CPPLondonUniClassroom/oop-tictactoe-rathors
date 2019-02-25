#include "Board.h"
#include "utility.h"

#include <string>

using namespace std::string_literals;

std::vector<BoardPosition> Board::FreePositions() const  {
    std::vector<BoardPosition> ret;
    for (auto i = 0; i < board.size(); ++i)
        if (!board[i])
            ret.emplace_back(NumberToBoardPosition(i));
    return ret;
}

void Board::OccupyPosition(const BoardPosition& pos, const IPlayer& player) {
    auto iPos = BoardPositionToChar(pos);
    if (board[iPos])
        throw std::logic_error{"ERROR: Attempt by player "s +
                               player.Symbol() + "to occupy spot " + std::to_string(iPos) +
                               " - already taken by " + board[iPos]->get().Symbol()};
    board[iPos] = player;
}

std::vector<char> Board::CurrentState() const {
    std::vector<char> ret(9, 0);
    for (auto i = 0; i < 9; ++i) {
        if (board[i])
            ret[i] = board[i]->get().Symbol();
    }
    return ret;
}