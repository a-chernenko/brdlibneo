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

#include "fm9009_adc_service.h"

using namespace InSys;
using namespace Private;
using namespace std::string_literals;

CFm9009_AdcService::CFm9009_AdcService(CModuleControl &control,
                                       CStorage &storage)
    : CAdcService{control, storage},
      d_ptr{std::make_shared<CFm9009_AdcServiceData>(control, storage)} {}

std::string CFm9009_AdcService::getName() const noexcept {
  return "FM9009 ADC Service"s;
}

CFm9009_AdcServiceData::CFm9009_AdcServiceData(CModuleControl &control,
                                               CStorage &storage)
    : CServiceControl{control, storage}, m_InputSubsystem{control, storage} {}

CFm9009_AdcInputSubsystem::CFm9009_AdcInputSubsystem(CModuleControl &control,
                                                     CStorage &storage)
    : CAdcInputSubsystem{control, storage} {}

void CFm9009_AdcInputSubsystem::setGain(double value) {
  m_Storage.add("setGain", value);
}

double CFm9009_AdcInputSubsystem::getGain() {
  return m_Storage.find("setGain").getValue<double>();
}

void CFm9009_AdcInputSubsystem::setGain(uint32_t channel, double value) {
  std::string key{"setGain"};
  key += std::to_string(channel);
  m_Storage.add(key, value);
  m_ModuleControl.writeIndirect(0, 0);
}

double CFm9009_AdcInputSubsystem::getGain(uint32_t channel) {
  std::string key{"setGain"};
  key += std::to_string(channel);
  uint32_t value{};
  m_ModuleControl.readIndirect(0, value);
  return m_Storage.find(key).getValue<double>();
}
