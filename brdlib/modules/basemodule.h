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

#include "basemodule_interface.h"
#include "module.h"

namespace InSys {

namespace Private {

struct CBaseModuleData final {};

}  // namespace Private

class CBaseModule : public IBaseModule {
  CModule m_Module{};
  std::shared_ptr<Private::CBaseModuleData> d_ptr{
      std::make_shared<Private::CBaseModuleData>()};

 public:
  CBaseModule();
  CBaseModule(const CBaseModule &) = default;
  CBaseModule(CBaseModule &&) = default;
  CBaseModule &operator=(const CBaseModule &) = default;
  CBaseModule &operator=(CBaseModule &&) noexcept = default;
  ~CBaseModule() noexcept = default;

 protected:
  void init() override;
  CServicesList &getServicesList() override;
  CStorage &getStorage() override;
  CModuleControl &getModuleControl() override;
  CServicesInfoList getAvailableServices() const noexcept override;
  CServicesListElem findService(ServiceId) const override;

 private:
  ModuleType getType() const noexcept override;
  std::string getName() const noexcept override;
};

}  // namespace InSys
