#include "uniform.h"

// Constructor que inicializa el generador con una semilla
UniformDistribution::UniformDistribution(int seed) : rng(seed) {}

// Genera un número aleatorio con distribución uniforme en el rango [min, max]
double UniformDistribution::genUniform(double min, double max)
{
  double randomFloat = rng.Random();      // Utiliza Random() para obtener un número flotante entre 0 y 1
  return min + (max - min) * randomFloat; // Escala y traslada el número para que esté en el rango [min, max]
}