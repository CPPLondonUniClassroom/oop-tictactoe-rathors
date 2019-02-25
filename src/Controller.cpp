#include "Controller.h"
#include "utility.h"

#include <algorithm>

static bool TestRowForWinner(const std::vector<char>& boardState, BoardPosition a, BoardPosition b, BoardPosition c) {
    auto x = BoardPositionToChar(a), y = BoardPositionToChar(b), z = BoardPositionToChar(c);
    return boardState[x] && boardState[x] == boardState[y] && boardState[x] == boardState[z];
}

static bool CheckForWinner(const std::vector<char>& boardState) {
    return TestRowForWinner(boardState,
                    BoardPosition::TOP_LEFT, BoardPosition::TOP_MIDDLE, BoardPosition::TOP_RIGHT) ||
            TestRowForWinner(boardState,
                    BoardPosition::MIDDLE_LEFT, BoardPosition::CENTER, BoardPosition::MIDDLE_RIGHT) ||
            TestRowForWinner(boardState,
                    BoardPosition::BOTTOM_LEFT, BoardPosition::BOTTOM_MIDDLE, BoardPosition::BOTTOM_RIGHT) ||
            TestRowForWinner(boardState,
                    BoardPosition::TOP_LEFT, BoardPosition::MIDDLE_LEFT, BoardPosition::BOTTOM_LEFT) ||
            TestRowForWinner(boardState,
                    BoardPosition::TOP_MIDDLE, BoardPosition::CENTER, BoardPosition::BOTTOM_MIDDLE) ||
            TestRowForWinner(boardState,
                    BoardPosition::TOP_RIGHT, BoardPosition::MIDDLE_RIGHT, BoardPosition::BOTTOM_RIGHT) ||
            TestRowForWinner(boardState,
                    BoardPosition::TOP_LEFT, BoardPosition::CENTER, BoardPosition::BOTTOM_RIGHT) ||
            TestRowForWinner(boardState,
                    BoardPosition::TOP_RIGHT, BoardPosition::CENTER, BoardPosition::BOTTOM_LEFT);
}

static void Winner(const IPlayer& player) {
    PrintMessage("Congratulations Player ", player.Symbol(), " - You won!");
}

Controller::Controller(IRenderer& renderer, IPlayer& p1, IPlayer& p2)
    : renderer{renderer}, p1{p1}, p2{p2} {}

void Controller::PlayGame() {
    for (auto i = 0; i < 4; ++i) {
        auto pos = p1.TakeTurn(board.FreePositions());
        board.OccupyPosition(pos, p1);
        renderer.RenderBoard(board.CurrentState());
        if (CheckForWinner(board.CurrentState()))
            return Winner(p1);
        pos = p2.TakeTurn(board.FreePositions());
        board.OccupyPosition(pos, p2);
        renderer.RenderBoard(board.CurrentState());
        if (CheckForWinner(board.CurrentState()))
            return Winner(p2);
    }
    board.OccupyPosition(p1.TakeTurn(board.FreePositions()), p1);
    renderer.RenderBoard(board.CurrentState());
    if (CheckForWinner(board.CurrentState()))
        return Winner(p1);
    PrintMessage("DRAW. Nobody won\n");
}
