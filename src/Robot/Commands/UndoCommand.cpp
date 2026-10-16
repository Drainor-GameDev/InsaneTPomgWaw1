//
// Created by Guill on 16/10/2026.
//

#include "UndoCommand.h"

bool UndoCommand::Execute(Level& level)
{
    return commandHistory.Undo(level);
}

void UndoCommand::Undo(Level& level)
{
}

namespace Commands
{
    CommandFactory Undo(CommandHistory& commandHistory)
    {
        return [&commandHistory]() { return std::make_unique<UndoCommand>(commandHistory); };
    }
}
