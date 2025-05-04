#ifndef UNICORNCAVEFACTORY_HPP
#define UNICORNCAVEFACTORY_HPP

#pragma once

#include "CaveFactory.hpp"
#include "Enemy.hpp"

#include <vector>

class UnicornCaveFactory : public CaveFactory {
public:
    Cave createCave(const Hero& hero) override;

protected:

};

#endif