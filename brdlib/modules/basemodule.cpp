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

#include "basemodule.h"
#include "stream_service.h"

using namespace InSys;
using namespace std::string_literals;

CBaseModule::CBaseModule() {
  auto &serviceList = m_Module.getServicesList();
  auto &storage = m_Module.getStorage();
  auto &control = m_Module.getModuleControl();
  serviceList.add(ServiceId::Stream0, MakeStreamService(control, storage));
  serviceList.add(ServiceId::Stream1, MakeStreamService(control, storage));
  serviceList.add(ServiceId::Stream2, MakeStreamService(control, storage));
  serviceList.add(ServiceId::Stream3, MakeStreamService(control, storage));
}

void CBaseModule::init() { m_Module.init(); }

ModuleType CBaseModule::getType() const noexcept { return ModuleType::Base; }

std::string CBaseModule::getName() const noexcept {
  return "Common Base Module"s;
}

CServicesList &CBaseModule::getServicesList() {
  return m_Module.getServicesList();
}

CStorage &CBaseModule::getStorage() { return m_Module.getStorage(); }

CModuleControl &CBaseModule::getModuleControl() {
  return m_Module.getModuleControl();
}

CServicesInfoList CBaseModule::getAvailableServices() const noexcept {
  return m_Module.getAvailableServices();
}

CServicesListElem CBaseModule::findService(ServiceId id) const {
  return m_Module.findService(id);
}
