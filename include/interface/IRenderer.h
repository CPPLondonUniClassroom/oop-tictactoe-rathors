#pragma once

#include <vector>

class IRenderer {
public:
    virtual void RenderBoard(const std::vector<char>& cells) = 0;
};