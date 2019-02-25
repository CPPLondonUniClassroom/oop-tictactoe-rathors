#pragma once
#include <vector>

#include "BoardPosition.h"

class IPlayer {
public:
    virtual char Symbol() const = 0;
    virtual BoardPosition TakeTurn(const std::vector<BoardPosition>& freePositions) = 0;
};