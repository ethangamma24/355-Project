#include "myrandom.h"

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'MyRandom' for the queueing theory computation.
 *
 * This class has the CERT-acceptable random number functions for:
 *   (double) normal distribution from a mean and std dev
 *   (double) uniform distribution from a lower to an upper bound
 *   (int) uniform distribution from a lower to an upper bound
 *
 * Author: Duncan A. Buell
 * Date last modified: 20 April 2015
**/

/******************************************************************************
 * Constructor
**/
MyRandom::MyRandom() {
  std::default_random_engine generator_;
}

/******************************************************************************
 * Destructor
**/
MyRandom::~MyRandom() {
}

/******************************************************************************
 * Accessors and Mutators
**/

/******************************************************************************
 * General functions.
**/

/******************************************************************************
 * Function 'RandomNormal'.
 * This generates 'double' random numbers normally distributed with
 * mean 'mean' and standard deviation 'dev'.
 *
 * Parameters:
 *   mean - the mean of the normally distributed RNs
 *   dev - the standard deviation of the normally distributed RNs
 *
 * Returns:
 *   the random number as a 'double'
**/
double MyRandom::RandomNormal(double mean, double dev)
{
  assert(dev >= 0.0);
  std::normal_distribution<double> distribution(mean, dev);
  double r = distribution(generator_);
  return r;
}

/******************************************************************************
 * Function 'RandomUniformDouble'.
 * This generates 'double' random numbers uniformly distributed from
 * 'lower' to 'upper' inclusive.
 *
 * Parameters:
 *   lower - the smallest value of the RNs
 *   upper - the largest value of the RNs
 *
 * Returns:
 *   the random number as a 'double'
**/
double MyRandom::RandomUniformDouble(double lower, double upper)
{
  assert(lower <= upper);
  std::uniform_real_distribution<double> distribution(lower, upper);
  double r = distribution(generator_);
  return r;
}

/******************************************************************************
 * Function 'RandomUniformInt'.
 * This generates 'int' random numbers uniformly distributed from
 * 'lower' to 'upper' inclusive.
 *
 * Parameters:
 *   lower - the smallest value of the RNs
 *   upper - the largest value of the RNs
 *
 * Returns:
 *   the random number as an 'int'
**/
int MyRandom::RandomUniformInt(int lower, int upper)
{
  assert(lower <= upper);
  std::uniform_int_distribution<int> distribution(lower, upper);
  int r = distribution(generator_);
  return r;
}
