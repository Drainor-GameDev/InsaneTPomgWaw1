//
// Created by Guill on 16/10/2026.
//

#pragma once

#include "ICommand.h"
#include "InputHandler.h"


class ReBindCommand : public ICommand{
public:
    ReBindCommand(InputHandler& input_handler, bool& azerty) : input_handler(input_handler), azerty(azerty) {};
    void Execute(Level& level) override;
private:
    InputHandler& input_handler;
    bool& azerty;
};

