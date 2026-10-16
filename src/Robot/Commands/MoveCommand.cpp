//
// Created by Guill on 16/10/2026.
//

#include "MoveCommand.h"

void MoveCommand::Execute(Level& level)
{
    auto pushedBox = false;
    level.TryMoveRobot(dx, dy, pushedBox);
}
