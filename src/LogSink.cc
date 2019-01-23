#include "../include/LogSink.h"

namespace Sel {
  LogSink::LogSink(Levels minLevel) {
    this->minLevel = minLevel;
  };

  Levels LogSink::getMinLevel() {
    return this->minLevel;
  }

  void LogSink::out(Levels level, const char* src, const char* msg) {

  }
}