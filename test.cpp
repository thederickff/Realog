#include "realog.hpp"

int main()
{
  realog::Logger logger;
  logger.info("Hello My Logger");

  realog::Logger custom("Custom");
  custom.info("Hello My Logger var={0}", 20, 20, 30, 30, 31);

  return 0;
}