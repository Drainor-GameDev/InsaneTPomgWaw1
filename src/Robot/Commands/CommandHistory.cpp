//
// Created by Guill on 16/10/2026.
//

#include "CommandHistory.h"

void CommandHistory::Execute(std::unique_ptr<ICommand> command, Level& level)
{
    if (command.get()->Execute(level) && command.get()->IsUndoable())
        done.push_back(std::move(command));
}

bool CommandHistory::Undo(Level& level)
{
    if (done.empty()) return false;
    auto cmd = std::move(done.back());
    cmd->Undo(level);
    undone.push_back(std::move(cmd));
    done.pop_back();
    return true;
}

bool CommandHistory::Redo(Level& level)
{
    if (undone.empty()) return false;
    auto cmd = std::move(undone.back());

    if (!cmd->Execute(level)) return false;

    undone.pop_back();
    done.push_back(std::move(cmd));
    return true;
}

int CommandHistory::GetMoveCount() const
{
    return done.size();
}
