#pragma once

#include <array>
#include <optional>
#include <functional>
#include <vector>

#include "BoardPosition.h"
#include "interface/IPlayer.h"

class Board {
    using PlayerRef = std::reference_wrapper<const IPlayer>;
    std::array<std::optional<PlayerRef>, 9> board;
public:
    std::vector<BoardPosition> FreePositions() const;

    void OccupyPosition(const BoardPosition& pos, const IPlayer& player);

    std::vector<char> CurrentState() const;
};