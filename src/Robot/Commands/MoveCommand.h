//
// Created by Guill on 16/10/2026.
//

#pragma once
#include "ICommand.h"
#include "InputHandler.h"

class MoveCommand : public ICommand
{
public:
    MoveCommand(int dx, int dy) : dx(dx), dy(dy) {};
    bool Execute(Level& level) override;
    void Undo(Level& level) override;

private:
    int dx;
    int dy;
    bool pushedBox;
};

namespace Commands
{
    CommandFactory Move(int dx, int dy);
}