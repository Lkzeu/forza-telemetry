#include <cstdio>
#include <iostream>
#include "telemetryDataout.hpp"

int main() {
   udpPacket p;
   auto car = reinterpret_cast<carTelemetry*>(p.payload);
   std::printf("p.payload address:\t\t%p\n", &p.payload[0]);            // 0x7ffcc31ef9bc
   std::printf("car->isRaceOn address:\t\t%p\n", &car->IsRaceOn);       // 0x7ffcc31ef9bc
   std::printf("car->TimestampMS address:\t%p\n", &car->TimestampMS);   // 0x7ffcc31ef9c0

   std::cout << "p Alignment: "   << alignof(udpPacket)    << std::endl; // 4
   std::cout << "car Alignment: " << alignof(carTelemetry) << std::endl; // 4
   return 0;
}
