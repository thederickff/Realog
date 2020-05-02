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

    template<typename... Args>
    void info(const char* message, const Args&... args)
    {
      

      log(message, args...);
    }

  private:
    template<typename... Args>
    void log(const char* message, const Args&... args)
    {
      time_t now = time(0);
      tm *ltm = localtime(&now);

      auto result = build(message, args...);

      std::cout << "[" 
      << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour << ":" 
      << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min << ":" 
      << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec << "] " 
      << m_name << ": "
      << result << std::endl;
    }

    template<typename... Args>
    std::string build(const char* message, const Args&... args)
    {
      size_t numArgs = sizeof...(Args);

      if (numArgs > 0) {
        recur(NULL, args...);
      }
      
      std::cout << std::endl;

      return message;
    }

    template<typename T, typename... Args>
    void recur(T first, const Args&... args)
    {
      if (reinterpret_cast<void*>(first) != NULL) {
        recur(first);
      }

      recur(args...);      
    }

    template<typename T>
    void recur(T t)
    {
      std::cout << t << " ";
    }
  private:
    std::string m_name;
  };
}

#endif /* defined(__Realog_Header__) */
