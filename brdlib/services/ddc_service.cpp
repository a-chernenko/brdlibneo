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

#include "ddc_service.h"

using namespace InSys;
using namespace Private;
using namespace std::string_literals;

CDdcServiceData::CDdcServiceData(CModuleControl &control, CStorage &storage)
    : CServiceControl{control, storage} {}

CDdcService::CDdcService(CModuleControl &control, CStorage &storage)
    : m_Service{control, storage},
      d_ptr{std::make_shared<CDdcServiceData>(control, storage)} {}

ServiceType CDdcService::getType() const noexcept { return ServiceType::Ddc; }

std::string CDdcService::getName() const noexcept {
  return "DDC Service"s;
}
