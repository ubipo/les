#pragma once

#include "./Sel.h"
#include "./LogSink.h"
#include <Arduino.h>

class SerialLogSink : public Sel::LogSink {
  public:
  SerialLogSink(HardwareSerial* serialOut = &Serial, Sel::Levels minLevel = Sel::Levels::DEBUG);
  SerialLogSink(Sel::Levels minLevel);

  virtual void out(Sel::Levels level, const char* src, const char* msg);

  /**
   * Checks wether the provided
   * serial connection is both
   * effective and ready to send.
   */
  bool isReady();

  private:
  HardwareSerial* serialOut;
};