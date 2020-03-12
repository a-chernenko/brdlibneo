/*

BRDLIBNEO
Copyright (C) 2020 JSC "InSys", Alexander Chernenko (chernenko.a@insys.ru)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <iostream>

#include "basemodules.h"
#include "brdlibneo.h"
#include "sidedrivers.h"

using namespace InSys;

int main(int argc, char *argv[]) {
  auto basedriver = MakeBaseModule<CBambpex>();
  if (basedriver == nullptr) {
    std::cerr << "Can't make basedriver!" << std::endl;
  }
  std::cout << "Module name: " << basedriver->getName() << '\n';
  basedriver->init();
  auto availableServices = basedriver->getAvailableServices();
  if (availableServices.empty()) {
    std::cout << "No available services!\n";
  } else {
    std::cout << "Available services:\n";
    for (const auto &serviceInfo : availableServices) {
      std::cout << "id: " << ServiceIdToInt(serviceInfo.id) << ", type: ["
                << ServiceTypeToInt(serviceInfo.type) << "] "
                << ServiceTypeToString(serviceInfo.type) << '\n';
    }
  }

  auto sidedriver = MakeSubModule<CFm9009>();
  if (sidedriver == nullptr) {
    std::cerr << "Can't make sidedriver!" << std::endl;
  }
  std::cout << "Module name: " << sidedriver->getName() << '\n';
  sidedriver->init();
  availableServices = sidedriver->getAvailableServices();
  if (availableServices.empty()) {
    std::cout << "No available services!\n";
  } else {
    std::cout << "Available services:\n";
    for (const auto &serviceInfo : availableServices) {
      std::cout << "id: " << ServiceIdToInt(serviceInfo.id) << ", type: ["
                << ServiceTypeToInt(serviceInfo.type) << "] "
                << ServiceTypeToString(serviceInfo.type) << '\n';
      auto service = sidedriver->findService(serviceInfo.id);
      if (service.isAvailable()) {
        switch (service.getType()) {
          case ServiceType::Adc: {
            auto adcService = service.getInterface<IAdcService>().get();
            std::cout << "\tService name: " << adcService->getName() << '\n';
            auto &adcInputSubsystem = adcService->getInputSubsystem();
            double gain{12.};
            adcInputSubsystem.setGain(gain);
            gain = adcInputSubsystem.getGain();
            std::cout << "\tGain: " << gain << '\n';
            int channel{2};
            gain = 25;
            adcInputSubsystem.setGain(channel, gain);
            gain = adcInputSubsystem.getGain(channel);
            std::cout << "\tGain[" << channel << "]: " << gain << '\n';
            auto &adcClockSubsystem = adcService->getClockSubsystem();
            double clockRate{55.};
            adcClockSubsystem.setRate(clockRate);
            clockRate = adcClockSubsystem.getRate();
            std::cout << "\tClock Rate: " << clockRate << '\n';
            break;
          }
          case ServiceType::Dac: {
            auto dacService = service.getInterface<IDacService>().get();
            std::cout << "\tService name: " << dacService->getName() << '\n';
            break;
          }
          case ServiceType::Ddc: {
            auto ddcService = service.getInterface<IDdcService>().get();
            std::cout << "\tService name: " << ddcService->getName() << '\n';
            break;
          }
          default:
            std::cerr << "Undefined service!" << std::endl;
            break;
        }
      } else {
        std::cerr << "Service is not available!" << std::endl;
      }
    }
  }
  return 0;
}
