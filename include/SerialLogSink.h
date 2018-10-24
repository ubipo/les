#pragma once

#include "./Sel.h"
#include "./LogSink.h"
#include <Arduino.h>

using namespace Sel;

class SerialLogSink : public LogSink {
  public:
  SerialLogSink(HardwareSerial* serialOut = &Serial, Levels minLevel = Levels::DEBUG);
  SerialLogSink(Levels minLevel);

  virtual void out(Levels level, const char* src, const char* msg);

  /**
   * Checks wether the provided
   * serial connection is both
   * effective and ready to send.
   */
  bool isReady();

  private:
  HardwareSerial* serialOut;
};