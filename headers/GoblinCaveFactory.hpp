#ifndef GOBLINCAVEFACTORY_HPP
#define GOBLINCAVEFACTORY_HPP

#pragma once

#include "CaveFactory.hpp"
#include "Enemy.hpp"

#include <vector>

class GoblinCaveFactory : public CaveFactory {
public:
    Cave createCave(const Hero& hero) override;

protected:

};

#endif