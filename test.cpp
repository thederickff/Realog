/*
  MIT License

  Copyright (c) 2020 Derick Felix

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/
#include "realog.hpp"

int main()
{
  std::cout << "SIMPLE EXAMPLE\n";
  {
    realog::Logger logger("My Logger");
    logger.log("Hello my Logger!");
  }

  std::cout << "\nVARIABLES EXAMPLE\n";
  {
    realog::Logger logger;

    logger.log("This is {0} triangle with {1} Custom {0} vars={1} * {2}", "A", 20, 40 * 20);
    
    logger.log("I {0} am {1} using {2} more {3} than {4} I {5} need", "_", 'A', 40.2 / 30, 10.0 / 3);

    logger.log("Number {0} times number {1} is {2}", 40.2, 24, 40.2 * 24);
  }

  std::cout << "\nCOLOR AND LEVELS\n";
  {
    realog::Logger logger("MyLogger", realog::Level::INFO);
    logger.log("Here is my info!");
    logger.setLevel(realog::Level::WARN);
    logger.log("Changed to warning!");
    std::cout << "\n";
    logger.trace("Show Trace");
    logger.debug("Show Debug");
    logger.info("Show Info");
    logger.warn("Show Warning");
    logger.error("Show Error");
    logger.critical("Show Critical");
  }

  return 0;
}