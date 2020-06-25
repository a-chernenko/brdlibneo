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

struct IBaseModule : IModule {
  using SharedPtr = std::shared_ptr<IBaseModule>;
  virtual ~IBaseModule() noexcept = default;
};

template <typename DerrivedInterface>
auto BaseModuleCast(const IBaseModule::SharedPtr& base) {
  return ModuleCast<DerrivedInterface, const IBaseModule::SharedPtr>(base);
}

template <typename BaseModule, typename... Args>
IBaseModule::SharedPtr MakeBaseModule(Args&&... args) {
  return std::make_shared<BaseModule>(args...);
}

}  // namespace InSys
