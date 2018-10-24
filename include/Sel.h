#pragma once

#include <cstddef>
using byte = unsigned char;

namespace Sel {
  const byte noLevels = 9;
  enum Levels : byte {
    DEBUG, INFO, WARNING, ERROR, CRITICAL
  };
  template <size_t sinkArrSize = 5>
  class Logger;
  class LogSink;
}