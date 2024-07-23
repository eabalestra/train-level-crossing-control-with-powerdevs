#ifndef UNIFORM_H
#define UNIFORM_H

#include "randomc.h"

class UniformDistribution
{
public:
  UniformDistribution(int seed);
  double genUniform(double min, double max);

private:
  CRandomMersenne rng; // Instancia del generador Mersenne Twister
};

#endif // UNIFORM_H