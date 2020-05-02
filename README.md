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