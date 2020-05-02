# Realog
C++ Simple Header-Only Log Library (Made to use on my game engine)

### Install
Download the header and include on your project, or you can add this repository as your submodule for easy update.

### Simple example
```cpp
  Realog::Logger logger("My Logger");
  logger.info("Hello my Logger!");
```
Outputs: `[17:01:18] My Logger: Hello my Logger!`

### Variables
```cpp
  Realog::Logger logger;
  logger.info("Number {0} times number {1} is {2}", 40.2, 24, 40.2 * 24);
```
Outputs: `[17:05:22] Realog: Number 40.2 times number 24 is 964.8`

### Levels
```cpp
  Realog::Logger logger("MyLogger", Realog::Level::INFO);
  logger.log("Here is my info!");
  logger.setLevel(Realog::Level::WARN);
  logger.log("Changed to warning!");
  std::cout << "\n";
  logger.trace("Show Trace");
  logger.debug("Show Debug");
  logger.info("Show Info");
  logger.warn("Show Warning");
  logger.error("Show Error");
  logger.critical("Show Critical");
```
Outputs:

![Preview](https://github.com/derickfelix/Realog/blob/master/preview.png)
