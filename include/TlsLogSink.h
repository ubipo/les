#pragma once

#include "./Sel.h"
#include "./LogSink.h"
#include <Arduino.h>
#include <ESP8266WiFi.h>

using namespace Sel;

class TlsLogSink : public LogSink {
  public:
  TlsLogSink(IPAddress sstlIp, int stlPort, Levels minLevel = Levels::DEBUG);

  virtual void out(Levels level, const char* src, const char* msg);

  bool connect();

  /**
   * Checks wether the tcp
   * connection is ready to send.
   */
  bool isReady();

  private:
  IPAddress sstlIp;
  int sstlPort;
  WiFiClient client;
};