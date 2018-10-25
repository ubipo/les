# Sel
The Sel Embedded Logger.

I made sel with another project of mine called [dcnt](https://github.com/ubipo/dcnt) in mind. However you should be able to use it in other arduino/esp projects without much hassle. If you use platformio, just clone (or submodule) this entire repo under 'libs'.

Sel uses a dynamic system of log sinks so you can choose yourself where your log messages go. I included two out of the box:
- 'SerialLogSink' just writes to serial in a fixed format
- 'StlsLogSink' writes to a purpose-made tcp log server on the network, see [stls](https://github.com/ubipo/stls). This can tie in with services like loggly
