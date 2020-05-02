#ifndef __Realog_Header__
#define __Realog_Header__

#include <iostream>
#include <ctime>

namespace realog {
  class Logger
  {
  public:
    Logger(const std::string &name = "Realog")
    : m_name(name)
    {
    }

    Logger(const Logger &other) = delete;
    Logger &operator=(const Logger &other) = delete;

    void info(const char* message)
    {
      log(message);
    }

  private:
    void log(const char* message)
    {
      time_t now = time(0);
      tm *ltm = localtime(&now);

      std::cout << "[" 
      << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour << ":" 
      << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min << ":" 
      << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec << "] " 
      << m_name << ": "
      << message << std::endl;
    }
  private:
    std::string m_name;
  };
}

#endif /* defined(__Realog_Header__) */
