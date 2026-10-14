//
// Created by Guill on 14/10/2026.
//

#include "Bow.h"

#include <iostream>

void Bow::Attack(const std::string& who, const std::string& target) const
{
    std::cout << who << " bow attack " << target << std::endl;
}
