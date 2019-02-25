#pragma once

#include "interface/IRenderer.h"
#include "interface/IPlayer.h"
#include "Board.h"

class Controller {
    IRenderer& renderer;
    Board board;
    IPlayer& p1;
    IPlayer& p2;

public:
    Controller(IRenderer& renderer, IPlayer& p1, IPlayer& p2);

    void PlayGame();
};