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

#include <climits>
#include <string_view>

namespace InSys {

enum class ServiceType : int { Common = -1, Stream, Adc, Dac, Ddc, Sync };

inline int ServiceTypeToInt(ServiceType type) noexcept {
  return static_cast<std::underlying_type_t<ServiceType>>(type);
}

inline std::string_view ServiceTypeToString(ServiceType type) noexcept {
  using namespace std::string_literals;
  switch (type) {
    case ServiceType::Common:
      return "Common";
    case ServiceType::Stream:
      return "Stream";
    case ServiceType::Adc:
      return "Adc";
    case ServiceType::Dac:
      return "Dac";
    case ServiceType::Ddc:
      return "Ddc";
    case ServiceType::Sync:
      return "Sync";
    default:
      return "Unknown";
  }
}

}  // namespace InSys
