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

#include <memory>
#include <stdexcept>
#include <string>

#include "service_type.h"

namespace InSys {

struct IService {
  using SharedPtr = std::shared_ptr<IService>;
  virtual ServiceType getType() const noexcept = 0;
  virtual std::string getName() const noexcept = 0;
  virtual ~IService() noexcept = default;
};

template <typename DerrivedInterface, typename BaseInterface>
auto ServiceCast(const BaseInterface &base) {
  auto derrived{std::dynamic_pointer_cast<DerrivedInterface>(base)};
  if (derrived == nullptr) {
    throw std::bad_cast();
  }
  return derrived;
}

template <typename Service, typename... Args>
IService::SharedPtr MakeService(Args &&... args) {
  return std::make_shared<Service>(args...);
}

}  // namespace InSys
