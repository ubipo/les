// TlsLogSink.h - TCP Log Server Log sink
#pragma once

#include "./Sel.h"
#include "./LogSink.h"
#include <Arduino.h>
#include <ESP8266WiFi.h>

/**
 * A sel sink that sends log
 * messages over TCP to an
 * stls - Sel TCP Log Server.
 */
class StlsLogSink : public Sel::LogSink {
  public:
  StlsLogSink(IPAddress sstlIp, int stlPort, Sel::Levels minLevel = Sel::Levels::DEBUG);

  virtual void out(Sel::Levels level, const char* src, const char* msg);

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