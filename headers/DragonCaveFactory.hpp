#ifndef DRAGONCAVEFACTORY_HPP
#define DRAGONCAVEFACTORY_HPP

#pragma once

#include "CaveFactory.hpp"
#include "Enemy.hpp"

#include <vector>

class DragonCaveFactory : public CaveFactory {
public:
    Cave createCave(const Hero& hero) override;

protected:

};

#endif