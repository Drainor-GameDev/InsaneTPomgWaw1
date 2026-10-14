//
// Created by Guill on 14/10/2026.
//

#include "Melee.h"

#include <iostream>
#include <ostream>

void Melee::Attack(const std::string& who, const std::string& target) const
{
    std::cout << who << " melee attack " << target << std::endl;
}
