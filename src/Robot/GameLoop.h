//
// Created by Guill on 16/10/2026.
//

#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <string>
#include <vector>

#include "Commands/InputHandler.h"


class GameLoop {
public:
    void Run();
private:
    void Bind();
    void Init();
    const std::vector<std::string> kLevel = {
        "########",
        "# #",
        "# .$$. #",
        "# @ #",
        "# #",
        "########",
        };
    InputHandler inputHandler;
    bool azerty = true;
};

#endif //GAMELOOP_H
