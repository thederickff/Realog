#ifndef __Realog_Header__
#define __Realog_Header__

#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>

namespace realog {
  struct NoArg {};

  std::ostream &operator<<(std::ostream &stream, const NoArg& arg)
  {
    return stream;
  }

  class Util
  {
  public:
    Util() = delete;

    static void replaceAll(std::string &string, const std::string &replace, const std::string &with)
    {
      size_t pos = string.find(replace);

      while (pos != std::string::npos)
      {
        string.replace(pos, replace.size(), with);
        pos = string.find(replace, pos + with.size());
      }
    }

    template<typename... Args>
    static std::vector<std::string> convertArgsToStringVector(const Args&... args)
    {
      std::vector<std::string> vector;

      iterate(vector, NoArg(), args...);

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
      if (!std::is_same<T, NoArg>::value) {
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
    void info(const std::string &message, const Args&... args)
    {
      log(message, Util::convertArgsToStringVector(args...));
    }

  private:
    void log(const std::string &message, const std::vector<std::string> &args)
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

    std::string build(const std::string &message, const std::vector<std::string> &args)
    {
      std::string result = message;

      for (size_t i = 0; i < args.size(); ++i) {
        std::stringstream ss;
        ss << '{' << i << '}';
        Util::replaceAll(result, ss.str(), args[i]);
      }
      
      return result;
    }

  private:
    std::string m_name;
  };
}

#endif /* defined(__Realog_Header__) */
