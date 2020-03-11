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

#include "module.h"

using namespace InSys;
using namespace InSys::Private;
using namespace std::string_literals;

void CModule::init() {}

ModuleType CModule::getType() const noexcept { return ModuleType::Common; }

std::string CModule::getName() const noexcept { return "Common Module"s; }

CServicesList &CModule::getServicesList() { return d_ptr->m_ServiceList; }

CStorage &CModule::getStorage() { return d_ptr->m_Storage; }

CModuleControl &CModule::getModuleControl() { return d_ptr->m_ModuleControl; }

CServicesListElem CModule::findService(ServiceId id) const {
  return d_ptr->m_ServiceList.find(id);
}

CServicesInfoList CModule::getAvailableServices() const noexcept {
  return d_ptr->m_ServiceList.getAvailable();
}
