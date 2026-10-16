//
// Created by Guill on 16/10/2026.
//

#pragma once
#include <memory>

#include "ICommand.h"


class CommandHistory
{
public:
    void Execute(std::unique_ptr<ICommand> command, Level& level);
    bool Undo(Level& level);
    bool Redo(Level& level);
    int GetMoveCount() const;
private:
    std::vector<std::unique_ptr<ICommand>> done;
    std::vector<std::unique_ptr<ICommand>> undone;
};
