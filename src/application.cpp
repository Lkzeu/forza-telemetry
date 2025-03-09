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

   int attempts = 0;
   while (true) {
      int bytesRecv = 0;
      net_->receive(packet_.payload, bufferSize, bytesRecv);

      if (bytesRecv != 331 && bytesRecv != 232) {
         std::cerr << "wrong data\n";
         if (++attempts > 4)
            break;
         continue;
      }

      attempts = 0;
      if (!car_->IsRaceOn) {
         continue;
      }

      // there is a 1 byte padding after the NormalizedAIBrakeDifference field due to memory alignment and the
      // way the data is sent by the game. So we need to move the data 1 byte to the right to fix this.
      std::memmove(&packet_.payload[312], &packet_.payload[311], 20);

      std::printf("\n\n"
         "RPM: %.1f\n"
         "Speed: %.0f Km/h\n"
         "Marcha: %u\n"
         "WheelOnRumbleStripFrontLeft: %d\n"
         "NormalizedAIBrakeDifference: %u\n "
         "TireWearFrontLeft: %f\n"
         "TireWearFrontRight: %f\n"
         "TireWearRearLeft: %f\n"
         "TireWearRearRight: %f\n"
         "TrackOrdinal: %d\n",
         car_->CurrentEngineRpm,
         car_->Speed * 3.6,
         car_->Gear,
         car_->WheelOnRumbleStripFrontLeft,
         car_->NormalizedAIBrakeDifference,
         car_->TireWearFrontLeft,
         car_->TireWearFrontRight,
         car_->TireWearRearLeft,
         car_->TireWearRearRight,
         car_->TrackOrdinal);
   } // end while
}

application::application() {
   car_ = reinterpret_cast<carTelemetry*>(packet_.payload);
   net_ = NetworkFactory::createNetwork();
   net_->createSocket("127.1.2.7", "8555");
}