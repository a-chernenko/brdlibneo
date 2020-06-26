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

#include "fm9009_adc_service.h"
#include "fm9009_dac_service.h"
#include "fm9009_ddc_service.h"

using namespace InSys;

int main(int argc, char *argv[]) {
  // create basemodule
  auto basedriver = MakeBaseModule<CBambpex>();
  if (basedriver == nullptr) {
    std::cerr << "Can't make basedriver!" << std::endl;
  }
  std::cout << "Module name: " << basedriver->getName() << '\n';
  basedriver->init();
  // get basemodule services list
  auto availableServices = basedriver->getAvailableServices();
  if (availableServices.empty()) {
    std::cout << "No available services!\n";
  } else {
    std::cout << "Available services:\n";
    // print basemodule service info
    for (const auto &serviceInfo : availableServices) {
      std::cout << "id: " << ServiceIdToInt(serviceInfo.id) << ", type: ["
                << ServiceTypeToInt(serviceInfo.type) << "] "
                << ServiceTypeToString(serviceInfo.type) << '\n';
      // get service by id
      auto service = basedriver->findService(serviceInfo.id);
      if (service.isAvailable()) {
        service.getType();
        switch (service.getType()) {
          case ServiceType::Stream: {
            // TODO:
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

  // create submodule
  auto sidedriver = MakeSubModule<CFm9009>();
  if (sidedriver == nullptr) {
    std::cerr << "Can't make sidedriver!" << std::endl;
  }
  std::cout << "Module name: " << sidedriver->getName() << '\n';
  sidedriver->init();
  // get submodule services list
  availableServices = sidedriver->getAvailableServices();
  if (availableServices.empty()) {
    std::cout << "No available services!\n";
  } else {
    std::cout << "Available services:\n";
    // print basemodule service info
    for (const auto &serviceInfo : availableServices) {
      std::cout << "id: " << ServiceIdToInt(serviceInfo.id) << ", type: ["
                << ServiceTypeToInt(serviceInfo.type) << "] "
                << ServiceTypeToString(serviceInfo.type) << '\n';
      // get service by id
      auto service = sidedriver->findService(serviceInfo.id);
      if (service.isAvailable()) {
        // get service type
        switch (service.getType()) {
          case ServiceType::Adc: {
            // get ADC service interface
            auto adcService = service.getInterface<IAdcService>();
            std::cout << "\tService name: " << adcService->getName() << '\n';
            // get ADC input subsystem
            auto &adcInputSubsystem = adcService->getInputSubsystem();
            // set gain
            double gain{12.};
            adcInputSubsystem.setGain(gain);
            // get gain
            gain = adcInputSubsystem.getGain();
            std::cout << "\tGain: " << gain << '\n';
            int channel{2};
            gain = 25;
            adcInputSubsystem.setGain(channel, gain);
            gain = adcInputSubsystem.getGain(channel);
            std::cout << "\tGain[" << channel << "]: " << gain << '\n';
            // get ADC clock subsystem
            auto &adcClockSubsystem = adcService->getClockSubsystem();
            // set clock rate
            double clockRate{55.};
            adcClockSubsystem.setRate(clockRate);
            // get clock rate
            clockRate = adcClockSubsystem.getRate();
            std::cout << "\tClock Rate: " << clockRate << '\n';
            try {
              // get device specific ADC service interface
              auto adcServiceFm9009 =
                  ServiceCast<IFm9009_AdcService>(adcService);
            } catch (const std::bad_cast &e) {
              std::cerr << e.what() << '\n';
            }
            break;
          }
          case ServiceType::Dac: {
            // get DAC service interface
            auto dacService = service.getInterface<IDacService>();
            std::cout << "\tService name: " << dacService->getName() << '\n';
            try {
              // get device specific DAC service interface
              auto dacServiceFm9009 =
                  ServiceCast<IFm9009_DacService>(dacService);
            } catch (const std::bad_cast &e) {
              std::cerr << e.what() << '\n';
            }
            break;
          }
          case ServiceType::Ddc: {
            // get DDC service interface
            auto ddcService = service.getInterface<IDdcService>();
            std::cout << "\tService name: " << ddcService->getName() << '\n';
            try {
              // get device specific DDC service interface
              auto ddcServiceFm9009 =
                  ServiceCast<IFm9009_DdcService>(ddcService);
            } catch (const std::bad_cast &e) {
              std::cerr << e.what() << '\n';
            }
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
