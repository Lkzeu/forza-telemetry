#include <iostream>
#include <cstring>
#include <memory>
#include "application.hpp"
#include "network.hpp"
#include "networkFactory.hpp"
#include "telemetryDataout.hpp"

void application::run() {
   constexpr auto bufferSize = constant::fudp_dash_size;
   std::cout << "waiting data...\n";

   int tries = 0;
   while (true) {
      int bytesRecv = 0;
      net_->receive(packet_.payload, bufferSize, bytesRecv);

      if (bytesRecv != 331 && bytesRecv != 232) {
         std::cerr << "wrong data\n";
         if (++tries > 4)
            break;
         continue;
      }

      if (!car_->IsRaceOn) {
         continue;
      }

      // fix padding inside struct
      std::memmove(&packet_.payload[311], &packet_.payload[310], 20);

      std::printf("\n\n" // isRaceOn, isRaceOn);
         "RPM: %.1f\n"
         "Speed: %.0f Km/h\n"
         "Marcha: %u\n"
         "WheelOnRumbleStripFrontLeft: %d\n"
         "TrackOrdinal: %d\n",
         car_->CurrentEngineRpm,
         car_->Speed * 3.6,
         car_->Gear,
         car_->WheelOnRumbleStripFrontLeft,  // could be a bool, but it's a int32_t!! haha, forza :)
         car_->TrackOrdinal);
   } // end while
}

application::application() {
   car_ = reinterpret_cast<carTelemetry*>(packet_.payload);
   net_ = NetworkFactory::createNetwork();
   net_->createSocket("127.1.2.7", "8555");
}