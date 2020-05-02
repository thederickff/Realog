#ifndef __Realog_Header__
#define __Realog_Header__

#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>

namespace realog {
  class Util
  {
  public:
    Util() = delete;

    template<typename... Args>
    static std::vector<std::string> convertArgsToStringVector(const Args&... args)
    {
      std::vector<std::string> vector;

      iterate(vector, NULL, args...);

      return vector;
    }

  private:
    template<typename T, typename... Args>
    static void iterate(std::vector<std::string> &vector, T first, const Args&... args)
    {
      iterate(vector, first);
      iterate(vector, args...);      
    }

    template<typename T>
    static void iterate(std::vector<std::string> &vector, T t)
    {
      if (reinterpret_cast<const void*>(t) != NULL) {
        std::stringstream stream;
        stream << t;
        vector.push_back(stream.str());
      }
    }
  };

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
      log(message, Util::convertArgsToStringVector(args...));
    }

  private:
    void log(const char* message, const std::vector<std::string> &args)
    {
      time_t now = time(0);
      tm *ltm = localtime(&now);

      auto result = build(message, args);

      std::cout << "[" 
      << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour << ":" 
      << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min << ":" 
      << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec << "] " 
      << m_name << ": "
      << result << std::endl;
    }

    std::string build(const char* message, const std::vector<std::string> &args)
    {
      std::cout << "MESSAGE: " << message << std::endl;    

      if (args.size() > 0) {
        std::stringstream ss;

        for (const std::string &arg : args) {
          // std::cout << arg << " ";
        }

        // std::cout << std::endl;
      }
      
      return message;
    }

   
  private:
    std::string m_name;
  };
}

#endif /* defined(__Realog_Header__) */
