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

struct IDacService : IService {
  using SharedPtr = std::shared_ptr<IDacService>;
  virtual ~IDacService() noexcept = default;
};

template <typename DerrivedInterface>
auto DacServiceCast(const IDacService::SharedPtr& base) {
  return ServiceCast<DerrivedInterface, const IDacService::SharedPtr>(base);
}

template <typename DacService, typename... Args>
IDacService::SharedPtr MakeDacService(Args&&... args) {
  return std::make_shared<DacService>(args...);
}

}  // namespace InSys
