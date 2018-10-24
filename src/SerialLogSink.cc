#include "SerialLogSink.h"
#include "Arduino.h"

#include <cstddef>

SerialLogSink::SerialLogSink(HardwareSerial* serialOut, DcntLogger::Levels minLevel) : LogSink::LogSink(DcntLogger::Levels::DEBUG) {
  this->serialOut = serialOut;
};

SerialLogSink::SerialLogSink(DcntLogger::Levels minLevels) : SerialLogSink(&Serial, minLevels) {};


void SerialLogSink::out(DcntLogger::Levels level, const char* src, const char* msg) {
  if (isReady()) {
    size_t srcLen = strlen(src);
    size_t msgLen = strlen(msg);

    if (srcLen + msgLen < 600) { // Idk, it can't be good if it's more than this, right?
      // "[<src>] <msg>\0"
      char out[1 + srcLen + 1 + 1 + msgLen + 1];

      // Source
      out[0] = '[';
      out[srcLen + 1] = ']';
      char* pSrcStart = out + 1;
      memcpy(pSrcStart, src, srcLen);

      // Seperator
      out[srcLen + 2] = ' ';
      
      // Message
      char* pMsgStart = out +  1 + srcLen + 2;
      memcpy(pMsgStart, msg, msgLen);

      // Terminator
      out[1 + srcLen + 1 + 1 + msgLen] = '\0';

      serialOut->println(out);
    }
  }
};

bool SerialLogSink::isReady() {
  return (serialOut != nullptr && serialOut->isTxEnabled());
};