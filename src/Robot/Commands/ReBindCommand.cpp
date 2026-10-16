//
// Created by Guill on 16/10/2026.
//

#include "ReBindCommand.h"

#include "MoveCommand.h"

void ReBindCommand::Execute(Level& level)
{
    azerty = !azerty;

    input_handler.Unbind(azerty ? 'w' : 'z');
    input_handler.Unbind(azerty ? 'a' : 'q');

    input_handler.Bind(azerty ? 'z' : 'w', std::make_unique<MoveCommand>(MoveCommand(0,-1)));
    input_handler.Bind(azerty ? 'q' : 'a', std::make_unique<MoveCommand>(MoveCommand(-1,0)));
}
