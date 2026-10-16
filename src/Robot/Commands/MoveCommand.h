//
// Created by Guill on 16/10/2026.
//

#pragma once
#include "ICommand.h"

class MoveCommand : public ICommand
{
public:
    MoveCommand(int dx, int dy) : dx(dx), dy(dy) {};
    void Execute(Level& level) override;

private:
    int dx;
    int dy;
};