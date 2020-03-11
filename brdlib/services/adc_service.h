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

#pragma once

#include "adc_service_interface.h"
#include "service.h"

namespace InSys {

class CAdcClockSubsystem : public IAdcClockSubsystem,
                           public Private::CServiceControl {
 public:
  CAdcClockSubsystem(CModuleControl &, CStorage &);

 protected:
  void setRate(double) override;
  double getRate() override;
};

class CAdcInputSubsystem : public IAdcInputSubsystem,
                           public Private::CServiceControl {
 public:
  CAdcInputSubsystem(CModuleControl &, CStorage &);

 protected:
  void setGain(double) override;
  double getGain() override;
  void setGain(uint32_t, double) override;
  double getGain(uint32_t) override;
};

namespace Private {

struct CAdcServiceData final : CServiceControl {
  CAdcServiceData(CModuleControl &, CStorage &);
  CAdcClockSubsystem m_ClockSubsystem;
  CAdcInputSubsystem m_InputSubsystem;
};

}  // namespace Private

class CAdcService : public IAdcService {
  CService m_Service;
  std::shared_ptr<Private::CAdcServiceData> d_ptr;

 public:
  CAdcService() = delete;
  CAdcService(CModuleControl &, CStorage &);
  CAdcService(const CAdcService &) = default;
  CAdcService(CAdcService &&) = default;
  CAdcService &operator=(const CAdcService &) = default;
  CAdcService &operator=(CAdcService &&) noexcept = default;
  ~CAdcService() noexcept = default;

 protected:
  IAdcClockSubsystem &getClockSubsystem() override;
  IAdcInputSubsystem &getInputSubsystem() override;

 private:
  ServiceType getType() const noexcept override;
  std::string getName() const noexcept override;
};

}  // namespace InSys
