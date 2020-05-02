#include "realog.hpp"

int main()
{
  std::cout << "SIMPLE EXAMPLE\n";
  {
    realog::Logger logger("My Logger");
    logger.info("Hello my Logger!");
  }

  std::cout << "\n\nVARIABLES EXAMPLE\n";
  {
    realog::Logger logger;

    logger.info("This is {0} triangle with {1} Custom {0} vars={1} * {2}", "A", 20, 40 * 20);
    
    logger.info("I {0} am {1} using {2} more {3} than {4} I {5} need", "_", 'A', 40.2 / 30, 10.0 / 3);

    logger.info("Number {0} * {1} = {2}", 40.2, 24, 40.2 * 24);
  }

  return 0;
}