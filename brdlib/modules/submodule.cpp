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

#include "submodule.h"

using namespace InSys;
using namespace std::string_literals;

void CSubModule::init() { m_Module.init(); }

ModuleType CSubModule::getType() const noexcept { return ModuleType::Sub; }

std::string CSubModule::getName() const noexcept {
  return "Common SubModule"s;
}

CServicesList &CSubModule::getServicesList() { return m_Module.getServicesList(); }

CStorage &CSubModule::getStorage() { return m_Module.getStorage(); }

CModuleControl &CSubModule::getModuleControl() { return m_Module.getModuleControl(); }

CServicesInfoList CSubModule::getAvailableServices() const noexcept {
  return m_Module.getAvailableServices();
}

CServicesListElem CSubModule::findService(ServiceId id) const {
  return m_Module.findService(id);
}
