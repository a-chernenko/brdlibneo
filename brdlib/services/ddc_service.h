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

#include "ddc_service_interface.h"
#include "service.h"

namespace InSys {

namespace Private {

struct CDdcServiceData final : CServiceControl {
  CDdcServiceData(CModuleControl &, CStorage &);
};

}  // namespace Private

class CDdcService : public IDdcService {
  CService m_Service;
  std::shared_ptr<Private::CDdcServiceData> d_ptr;

 public:
  CDdcService() = delete;
  CDdcService(CModuleControl &, CStorage &);
  CDdcService(const CDdcService &) = default;
  CDdcService(CDdcService &&) = default;
  CDdcService &operator=(const CDdcService &) = default;
  CDdcService &operator=(CDdcService &&) noexcept = default;
  ~CDdcService() noexcept = default;

 private:
  ServiceType getType() const noexcept override;
  std::string getName() const noexcept override;
};

}  // namespace InSys
