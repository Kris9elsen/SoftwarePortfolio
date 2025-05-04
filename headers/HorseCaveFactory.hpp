#ifndef HORSECAVEFACTORY_HPP
#define HORSECAVEFACTORY_HPP

#pragma once

#include "CaveFactory.hpp"
#include "Enemy.hpp"

#include <vector>

class HorseCaveFactory : public CaveFactory {
public:
    Cave createCave(const Hero& hero) override;

protected:

};

#endif