#ifndef MONKEYCAVEFACTORY_HPP
#define MONKEYCAVEFACTORY_HPP

#pragma once

#include "CaveFactory.hpp"
#include "Enemy.hpp"

#include <vector>

class MonkeyCaveFactory : public CaveFactory {
public:
    Cave createCave(const Hero& hero) override;

protected:

};

#endif