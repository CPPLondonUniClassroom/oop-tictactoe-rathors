#pragma once
#include "interface/IRenderer.h"

class Renderer : public IRenderer {
public:
    void RenderBoard(const std::vector<char>& v) override;
};