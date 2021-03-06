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

#include "dac_service_interface.h"
#include "service.h"

namespace InSys {

namespace Private {

struct CDacServiceData final : CServiceControl {
  CDacServiceData(CModuleControl &, CStorage &);
};

}  // namespace Private

class CDacService : public IDacService {
  CService m_Service;
  std::shared_ptr<Private::CDacServiceData> d_ptr;

 public:
  CDacService() = delete;
  CDacService(CModuleControl &, CStorage &);
  CDacService(const CDacService &) = default;
  CDacService(CDacService &&) = default;
  CDacService &operator=(const CDacService &) = default;
  CDacService &operator=(CDacService &&) noexcept = default;
  ~CDacService() noexcept = default;

 private:
  ServiceType getType() const noexcept override;
  std::string getName() const noexcept override;
};

}  // namespace InSys
