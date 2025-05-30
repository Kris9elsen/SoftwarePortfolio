#ifndef CAVEFACTORY_HPP
#define CAVEFACTORY_HPP

#pragma once

#include "Hero.hpp"
#include "Cave.hpp"

class CaveFactory {
public:
    virtual Cave createCave(const Hero& hero) = 0;
    virtual ~CaveFactory() {};

};

#endif