#pragma once

#include "interface/IPlayer.h"

class HumanPlayer : public IPlayer {
    char symbol;

public:
    explicit HumanPlayer(char symbol);

    char Symbol() const override;

    BoardPosition TakeTurn(const std::vector<BoardPosition>& freePositions) override;
};