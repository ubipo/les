#pragma once

#include <cstddef>
#include "Sel.h"
#include "LogSink.h"

using byte = unsigned char;

namespace Sel {
  template <size_t sinkArrSize>
  class Logger {
    public:  
    Logger(TimeGetter& timeGetter) : timeGetter(timeGetter) {};

    void log(Levels level, const char* src, const char* msg) {      
      for(Sel::LogSink* sink : sinks) {
        if (sink != nullptr && level >= sink->getMinLevel()) {
          sink->out(level, src, msg);
        }
      }
    };

    bool registerSink(LogSink* sink) {
      if (noSinks >= sinkArrSize)
        return false;
      
      sinks[noSinks++] = sink;
      return true;
    };

    // DEBUG, INFO, WARNING, ERROR, CRITICAL

    void debug(const char* src, const char* msg) {
      log(Levels::DEBUG, src, msg);
    };

    void info(const char* src, const char* msg) {
      log(Levels::INFO, src, msg);
    };

    void warning(const char* src, const char* msg) {
      log(Levels::WARNING, src, msg);
    };

    void error(const char* src, const char* msg) {
      log(Levels::ERROR, src, msg);
    };

    void critical(const char* src, const char* msg) {
      log(Levels::CRITICAL, src, msg);
    };

    // void registerSink(LogSink &sink) {
    //   sinks[--noSinks] = sink;
    // };

    private:
    TimeGetter& timeGetter;
    size_t noSinks = 0;
    Sel::LogSink* sinks[sinkArrSize] = {0};
    static const char* levelsCString[noLevels];
  };
}