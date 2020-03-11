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

#include "../modules/module_control.h"
#include "../modules/storage.h"
#include "service_interface.h"

namespace InSys {

namespace Private {

struct CServiceControl : CModuleControlReference, CStorageReference {
  CServiceControl(CModuleControl &, CStorage &);
};

struct CServiceData final : CServiceControl {
  CServiceData(CModuleControl &, CStorage &);
};

}  // namespace Private

class CService : public IService {
  std::shared_ptr<Private::CServiceData> d_ptr;

 public:
  CService() = delete;
  CService(const CService &) = default;
  CService(CService &&) = default;
  CService &operator=(const CService &) = default;
  CService &operator=(CService &&) noexcept = default;
  ~CService() noexcept = default;

  CService(CModuleControl &, CStorage &);

 private:
  ServiceType getType() const noexcept override;
  std::string getName() const noexcept override;
};

}  // namespace InSys
