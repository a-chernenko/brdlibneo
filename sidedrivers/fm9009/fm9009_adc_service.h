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

#include "brdlibneo.h"

namespace InSys {

struct IFm9009_AdcService {
  using SharedPtr = std::shared_ptr<IFm9009_AdcService>;
  virtual ~IFm9009_AdcService() noexcept = default;
};

class CFm9009_AdcInputSubsystem final : public CAdcInputSubsystem {
 public:
  CFm9009_AdcInputSubsystem(CModuleControl &, CStorage &);

 private:
  void setGain(double) final;
  double getGain() final;
  void setGain(uint32_t, double) final;
  double getGain(uint32_t) final;
};

namespace Private {

struct CFm9009_AdcServiceData final : CServiceControl {
  CFm9009_AdcServiceData(CModuleControl &, CStorage &);
  CFm9009_AdcInputSubsystem m_InputSubsystem;
};

}  // namespace Private

class CFm9009_AdcService final : public IFm9009_AdcService, public CAdcService {
  std::shared_ptr<Private::CFm9009_AdcServiceData> d_ptr;

 public:
  CFm9009_AdcService(CModuleControl &, CStorage &);

 private:
  std::string getName() const noexcept final;
  IAdcInputSubsystem &getInputSubsystem() final {
    return d_ptr->m_InputSubsystem;
  }
};

}  // namespace InSys
