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

  enum class Level
  {
    TRACE, DEBUG, INFO, WARN, ERROR, CRITICAL
  };

  class Logger
  {
  public:
    Logger(const std::string &name = "Realog", const Level &level = Level::TRACE)
    : m_name(name), m_level(level)
    {
    }

    Logger(const Logger &other) = delete;
    Logger &operator=(const Logger &other) = delete;

    template<typename... Args>
    inline void trace(const std::string &message, const Args&... args)
    {
      log(message, Level::TRACE, Util::convertArgsToStringVector(args...));
    }

    template<typename... Args>
    inline void debug(const std::string &message, const Args&... args)
    {
      log(message, Level::DEBUG, Util::convertArgsToStringVector(args...));
    }

    template<typename... Args>
    inline void info(const std::string &message, const Args&... args)
    {
      log(message, Level::INFO, Util::convertArgsToStringVector(args...));
    }

    template<typename... Args>
    inline void warn(const std::string &message, const Args&... args)
    {
      log(message, Level::WARN, Util::convertArgsToStringVector(args...));
    }

    template<typename... Args>
    inline void error(const std::string &message, const Args&... args)
    {
      log(message, Level::ERROR, Util::convertArgsToStringVector(args...));
    }

    template<typename... Args>
    inline void critical(const std::string &message, const Args&... args)
    {
      log(message, Level::CRITICAL, Util::convertArgsToStringVector(args...));
    }

    template<typename... Args>
    inline void log(const std::string &message, const Args&... args)
    {
      log(message, m_level, Util::convertArgsToStringVector(args...));
    }

    inline void setLevel(const Level &level)
    {
      m_level = level;
    }

  private:
    void log(const std::string &message, const Level& level, const std::vector<std::string> &args)
    {
      time_t now = time(0);
      tm *ltm = localtime(&now);

      switch (level)
      {
      case Level::TRACE:
        std::cout << "\033[0m";
        break;
      case Level::DEBUG:
        std::cout << "\033[0;34m";
        break;
      case Level::INFO:
        std::cout << "\033[0;32m";
        break;
      case Level::WARN:
        std::cout << "\033[0;33m";
        break;
      case Level::ERROR:
        std::cout << "\033[0;31m";
        break;
      case Level::CRITICAL:
        std::cout << "\033[0;41m";
        break;
      };

      auto result = build(message, args);

      std::cout << "[" 
      << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour << ":" 
      << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min << ":" 
      << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec << "] " 
      << m_name << ": "
      << result;

      std::cout << "\033[0m" << std::endl;
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
    Level m_level;
  };
}

#endif /* defined(__Realog_Header__) */
