//
// Created by Guill on 14/10/2026.
//

#include "Spell.h"

#include <iostream>

void Spell::Attack(const std::string& who, const std::string& target) const
{
    std::cout << who << " spell attack " << target << std::endl;
}
