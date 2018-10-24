#include "../include/LogSink.h"

DcntLogger::LogSink::LogSink(DcntLogger::Levels minLevel) {
  this->minLevel = minLevel;
};

DcntLogger::Levels DcntLogger::LogSink::getMinLevel() {
  return this->minLevel;
}

void DcntLogger::LogSink::out(DcntLogger::Levels level, const char* src, const char* msg) {

}