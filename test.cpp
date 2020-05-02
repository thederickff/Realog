#include "realog.hpp"

int main()
{
  realog::Logger logger;
  logger.info("Hello My Logger");

  realog::Logger custom("Custom");
  custom.info("Hello My Logger var={0}", 2, "A hello", 20, 20, "I don't know", 30, 31);

  return 0;
}