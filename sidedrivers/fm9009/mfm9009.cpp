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

#include "mfm9009.h"

#include "fm9009_adc_service.h"
#include "fm9009_dac_service.h"
#include "fm9009_ddc_service.h"

using namespace InSys;
using namespace std::string_literals;

void CFm9009::init() {
  CSubModule::init();
  auto &serviceList = getServicesList();
  auto &storage = getStorage();
  auto &control = getModuleControl();
  serviceList.add(ServiceId::Fm9009_Adc0,
                  MakeAdcService<CFm9009_AdcService>(control, storage));
  serviceList.add(ServiceId::Fm9009_Adc1,
                  MakeAdcService<CFm9009_AdcService>(control, storage));
  serviceList.add(ServiceId::Fm9009_Dac,
                  MakeDacService<CFm9009_DacService>(control, storage));
  serviceList.add(ServiceId::Fm9009_Ddc,
                  MakeDdcService<CFm9009_DdcService>(control, storage));
}

std::string CFm9009::getName() const noexcept { return "FM9009"s; }
