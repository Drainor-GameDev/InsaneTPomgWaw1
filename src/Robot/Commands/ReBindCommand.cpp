//
// Created by Guill on 16/10/2026.
//

#include "ReBindCommand.h"

#include "MoveCommand.h"

bool ReBindCommand::Execute(Level& level)
{
    azerty = !azerty;

    input_handler.Unbind(azerty ? 'w' : 'z');
    input_handler.Unbind(azerty ? 'a' : 'q');

    input_handler.Bind(azerty ? 'z' : 'w', Commands::Move(0,-1));
    input_handler.Bind(azerty ? 'q' : 'a', Commands::Move(-1,0));
    return true;
}

void ReBindCommand::Undo(Level& level)
{
    Execute(level);
}

namespace Commands
{
    CommandFactory Rebind(InputHandler& input_handler, bool& azerty)
    {
        return [&input_handler, &azerty]() { return std::make_unique<ReBindCommand>(input_handler,azerty); };
    }
}
