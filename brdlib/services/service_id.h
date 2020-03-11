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

#include <type_traits>

namespace InSys {

enum class ServiceId : int {
  Stream0,
  Stream1,
  Stream2,
  Stream3,
  Fm9009_Adc0,
  Fm9009_Adc1,
  Fm9009_Dac,
  Fm9009_Ddc
};

inline int ServiceIdToInt(ServiceId id) noexcept {
  return static_cast<std::underlying_type_t<ServiceId>>(id);
}

}  // namespace InSys
