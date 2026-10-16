//
// Created by Guill on 16/10/2026.
//

#pragma once

#include "CommandHistory.h"
#include "ICommand.h"
#include "InputHandler.h"


class UndoCommand : public ICommand{
public:
    UndoCommand(CommandHistory& commandHistory) : commandHistory(commandHistory) {};
    bool Execute(Level& level) override;
    void Undo(Level& level) override;
    bool IsUndoable() const override { return false; }
private:
    CommandHistory& commandHistory;
};

namespace Commands
{
    CommandFactory Undo(CommandHistory& commandHistory);
}