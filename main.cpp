#include <cstring>
#include <iostream>
#include <memory>
#include "src/telemetryDataout.hpp"
#include "src/networkFactory.hpp"

void lZeroMemory(char* data, size_t size) {
   std::memset(data, 0, size);
}

int main() {
   udpPacket packet;
   constexpr auto bufferSize = constant::fudp_dash_size;
   lZeroMemory(packet.payload, bufferSize);

   auto car = reinterpret_cast<carTelemetry*>(packet.payload);
   auto network = NetworkFactory::createNetwork();

   int bytesRecv = 0;
   network->recv(packet.payload, bufferSize, bytesRecv);

   std::cout << "well... a lot of work TODO\n";
   return 0;
}
