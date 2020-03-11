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

#include "service.h"
#include "stream_service_interface.h"

namespace InSys {

namespace Private {

struct CStreamServiceData final : CServiceControl {
  CStreamServiceData(CModuleControl &, CStorage &);
};

}  // namespace Private

class CStreamService final : public IStreamService {
  CService m_Service;
  std::shared_ptr<Private::CStreamServiceData> d_ptr;

 public:
  CStreamService() = delete;
  CStreamService(CModuleControl &, CStorage &);
  CStreamService(const CStreamService &) = default;
  CStreamService(CStreamService &&) = default;
  CStreamService &operator=(const CStreamService &) = default;
  CStreamService &operator=(CStreamService &&) noexcept = default;
  ~CStreamService() noexcept = default;

 private:
  ServiceType getType() const noexcept final;
  std::string getName() const noexcept final;
};

template <typename... Args>
IStreamService::SharedPtr MakeStreamService(Args &&... args) {
  return std::make_shared<CStreamService>(args...);
}

}  // namespace InSys
