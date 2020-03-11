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

#include "dac_service.h"

using namespace InSys;
using namespace Private;
using namespace std::string_literals;

CDacServiceData::CDacServiceData(CModuleControl &control, CStorage &storage)
    : CServiceControl{control, storage} {}

CDacService::CDacService(CModuleControl &control, CStorage &storage)
    : m_Service{control, storage},
      d_ptr{std::make_shared<CDacServiceData>(control, storage)} {}

ServiceType CDacService::getType() const noexcept { return ServiceType::Dac; }

std::string CDacService::getName() const noexcept {
  return "DAC Service"s;
}
