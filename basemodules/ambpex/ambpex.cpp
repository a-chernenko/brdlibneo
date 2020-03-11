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

#include <string>

#include "ambpex.h"
#include "services/stream_service.h"

using namespace InSys;
using namespace std::string_literals;

CAmbpex::CAmbpex() {
  getServicesList().remove(ServiceId::Stream2);
  getServicesList().remove(ServiceId::Stream3);
}

void CAmbpex::init() { CBaseModule::init(); }

std::string CAmbpex::getName() const noexcept { return "AMBPEX"s; }
