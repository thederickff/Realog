# Realog
C++ Simple Header-Only Log Library (Made to use on my game engine)

### Simple example
```cpp
  realog::Logger logger("My Logger");
  logger.info("Hello my Logger!");
```
Outputs
```shell
[17:01:18] My Logger: Hello my Logger!
```

### Variables
```cpp
  realog::Logger logger;
  logger.info("Number {0} times number {1} is {2}", 40.2, 24, 40.2 * 24);
```
Outputs
```shell
[17:05:22] Realog: Number 40.2 times number 24 is 964.8
```

### Levels
```cpp
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
```
Outputs
![Preview](https://github.com/derickfelix/Realog/blob/master/preview.png)