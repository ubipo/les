#pragma once

#include <functional>
#include <cstddef>

namespace Sel {
    using TimeGetter = std::function<unsigned long int()>;
    using byte = unsigned char;
    const byte noLevels = 9;
    enum Levels : byte {
      DEBUG, INFO, WARNING, ERROR, CRITICAL
    };
    // using TimeGetter = std::function<unsigned long()>;

    template <size_t sinkArrSize = 5>
    class Logger;
    class LogSink;
}