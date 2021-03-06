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

#include "fm9009_dac_service.h"

using namespace InSys;
using namespace Private;
using namespace std::string_literals;

CFm9009_DacService::CFm9009_DacService(CModuleControl &control,
                                       CStorage &storage)
    : CDacService{control, storage},
      d_ptr{std::make_shared<CFm9009_DacServiceData>(control, storage)} {}

std::string CFm9009_DacService::getName() const noexcept {
  return "FM9009 DAC Service"s;
}

CFm9009_DacServiceData::CFm9009_DacServiceData(CModuleControl &control,
                                               CStorage &storage)
    : CServiceControl{control, storage} {}
