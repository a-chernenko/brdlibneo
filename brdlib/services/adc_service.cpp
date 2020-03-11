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

#include "adc_service.h"

using namespace InSys;
using namespace Private;
using namespace std::string_literals;

CAdcClockSubsystem::CAdcClockSubsystem(CModuleControl &control,
                                       CStorage &storage)
    : CServiceControl{control, storage} {}

CAdcInputSubsystem::CAdcInputSubsystem(CModuleControl &control,
                                       CStorage &storage)
    : CServiceControl{control, storage} {}

CAdcServiceData::CAdcServiceData(CModuleControl &control, CStorage &storage)
    : CServiceControl{control, storage},
      m_ClockSubsystem{control, storage},
      m_InputSubsystem{control, storage} {}

CAdcService::CAdcService(CModuleControl &control, CStorage &storage)
    : m_Service{control, storage},
      d_ptr{std::make_shared<CAdcServiceData>(control, storage)} {}

IAdcClockSubsystem &CAdcService::getClockSubsystem() {
  return d_ptr->m_ClockSubsystem;
}
IAdcInputSubsystem &CAdcService::getInputSubsystem() {
  return d_ptr->m_InputSubsystem;
}

ServiceType CAdcService::getType() const noexcept { return ServiceType::Adc; }

std::string CAdcService::getName() const noexcept {
  return "ADC Service"s;
}

void CAdcClockSubsystem::setRate(double value) {
  m_Storage.add("setRate", value);
}

double CAdcClockSubsystem::getRate() {
  return m_Storage.find("setRate").getValue<double>();
}

void CAdcInputSubsystem::setGain(double value) {}

double CAdcInputSubsystem::getGain() { return 0; }

void CAdcInputSubsystem::setGain(uint32_t channel, double value) {}

double CAdcInputSubsystem::getGain(uint32_t channel) { return 0; }
