#include "Renderer.h"
#include "utility.h"

#include <iostream>

static char ZeroToSpace(char c) {
    return c != 0 ? c : ' ';
}

void Renderer::RenderBoard(const std::vector<char>& v)  {
    auto i = 0;
    PrintMessage("=======\n");
    for (auto x = 0; x < 3; ++x) {
        PrintMessage('|', ZeroToSpace(v[i++]));
        PrintMessage('|', ZeroToSpace(v[i++]));
        PrintMessage('|', ZeroToSpace(v[i++]), "|\n");
    }
    PrintMessage("=======\n");
}
