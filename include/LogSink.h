#pragma once

#include "./Sel.h"

namespace Sel {
  class LogSink {
    public:
    LogSink(Levels minLevel = Levels::DEBUG);

    /**
     * Outputs a new log message
     * to this sink (not meant to
     * be used on it's own)
     * 
     * When called by 'Logger'
     * strlen of:
     *  src <= 6
     *  msg <= 80
     */
    virtual void out(Levels level, const char* src, const char* msg);
    Levels getMinLevel();

    private:
    Levels minLevel;
  };
}