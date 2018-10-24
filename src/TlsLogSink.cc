#include "TlsLogSink.h"
#include <ESP8266WiFi.h>
#include "Arduino.h"

#include <cstddef>

using namespace Sel;

TlsLogSink::TlsLogSink(IPAddress sstlIp, int sstlPort, Levels minLevel) : LogSink::LogSink(Levels::DEBUG) {
  this->sstlIp = sstlIp;
  this->sstlPort = sstlPort;

  connect();
};

bool TlsLogSink::connect() {
  if (isReady())
    client.stop();

  bool connected = client.connect(sstlIp, sstlPort);

  if (connected)
    client.keepAlive(30, 30, 5);
  
  return connected;
}

bool TlsLogSink::isReady() {
  return client.availableForWrite();
};

void TlsLogSink::out(Levels level, const char* src, const char* msg) {
  if (!isReady() && !connect()) return; // Isn't ready and can't connect

  char sep = '$';
  unsigned char t = 5;
  size_t buffSize = 1 + 1 + strlen(src) + 1 + strlen(msg) + 1;
  char* buff = new char[buffSize];

  buff[0] = 48 + t;
  buff[1] = sep;
  strcpy(buff+2, src);
  buff[2+strlen(src)] = sep;
  strcpy(buff+2+strlen(src)+1, msg);
  buff[2+strlen(src)+1+strlen(msg)] = '\0';

  client.print(buff);

  delete buff;
};
