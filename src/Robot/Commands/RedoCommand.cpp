//
// Created by Guill on 16/10/2026.
//

#include "RedoCommand.h"

bool RedoCommand::Execute(Level& level)
{
    return commandHistory.Redo(level);
}

void RedoCommand::Undo(Level& level)
{
}

namespace Commands
{
    CommandFactory Redo(CommandHistory& commandHistory)
    {
        return [&commandHistory]() { return std::make_unique<RedoCommand>(commandHistory); };
    }
}
