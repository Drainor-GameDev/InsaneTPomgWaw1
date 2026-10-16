//
// Created by Guill on 16/10/2026.
//

#include "MoveCommand.h"

bool MoveCommand::Execute(Level& level)
{
    return level.TryMoveRobot(dx, dy, pushedBox);
}

void MoveCommand::Undo(Level& level)
{
    level.UndoMove(dx, dy, pushedBox);
}

namespace Commands
{
    CommandFactory Move(int dx, int dy)
    {
        return [dx, dy]() { return std::make_unique<MoveCommand>(dx, dy); };
    }
}
