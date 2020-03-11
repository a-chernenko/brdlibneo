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

#include "service_interface.h"

namespace InSys {

struct IAdcClockSubsystem {
  virtual void setRate(double) = 0;
  virtual double getRate() = 0;
  virtual ~IAdcClockSubsystem() noexcept = default;
};

struct IAdcInputSubsystem {
  virtual void setGain(double) = 0;
  virtual double getGain() = 0;
  virtual void setGain(uint32_t, double) = 0;
  virtual double getGain(uint32_t) = 0;
  virtual ~IAdcInputSubsystem() noexcept = default;
};

struct IAdcService : IService {
  using SharedPtr = std::shared_ptr<IAdcService>;
  virtual IAdcClockSubsystem &getClockSubsystem() = 0;
  virtual IAdcInputSubsystem &getInputSubsystem() = 0;
  virtual ~IAdcService() noexcept = default;
};

template <typename DerrivedInterface>
auto AdcServiceDownCast(const IAdcService::SharedPtr &base) {
  return ServiceDownCast<DerrivedInterface, const IAdcService::SharedPtr>(base);
}

template <typename AdcService, typename ...Args>
IAdcService::SharedPtr MakeAdcService(Args && ... args) {
  return std::make_shared<AdcService>(args...);
}

}  // namespace InSys
