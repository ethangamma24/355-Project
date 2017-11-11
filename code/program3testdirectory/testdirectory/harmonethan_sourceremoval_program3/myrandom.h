/****************************************************************
 * Header file for the random number generator for the queueing
 * theory program.
 *
 * Author/copyright:  Duncan Buell
 * Date: 31 December 2014
 *
**/

#ifndef MYRANDOM_H
#define MYRANDOM_H

#include <iostream>
#include <random>
#include <cassert>
using namespace std;

#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

#undef NDEBUG

class MyRandom {
public:
 MyRandom();
 virtual ~MyRandom();

 double RandomNormal(double mean, double dev);
 double RandomUniformDouble(double lower, double upper);
 int RandomUniformInt(int lower, int upper);

private:
 std::default_random_engine generator_;
};

#endif
