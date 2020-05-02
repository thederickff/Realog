#include "realog.hpp"

int main()
{
  realog::Logger logger;
  logger.info("Hello My Logger");

  realog::Logger custom("Custom");
  custom.info("Hello My Logger");

  return 0;
}