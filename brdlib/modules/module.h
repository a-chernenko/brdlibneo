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

#include "module_interface.h"

namespace InSys {

namespace Private {

struct CModuleData final {
  CModuleControl m_ModuleControl{};
  CServicesList m_ServiceList{};
  CStorage m_Storage{};
};

}  // namespace Private

class CModule : public IModule {
  std::shared_ptr<Private::CModuleData> d_ptr{
      std::make_shared<Private::CModuleData>()};

 public:
  CModule() = default;
  CModule(const CModule &) = default;
  CModule(CModule &&) = default;
  CModule &operator=(const CModule &) = default;
  CModule &operator=(CModule &&) noexcept = default;
  ~CModule() noexcept = default;

  void init() override;
  CServicesList &getServicesList() override;
  CStorage &getStorage() override;
  CModuleControl &getModuleControl() override;
  CServicesInfoList getAvailableServices() const noexcept override;
  CServicesListElem findService(ServiceId) const override;

  ModuleType getType() const noexcept override;
  std::string getName() const noexcept override;
};

}  // namespace InSys
