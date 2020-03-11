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

#include "services_list.h"

using namespace InSys;

CServicesListElem::CServicesListElem(IService::SharedPtr &&service)
    : m_Value{std::make_pair(service->getType(), std::move(service))} {}

CServicesListElem::CServicesListElem(const IService::SharedPtr &service)
    : m_Value{std::make_pair(service->getType(), service)} {}

CServicesListElem CServicesList::find(ServiceId id) const {
  if (m_Map.empty()) {
    return CServicesListElem();
  }
  auto service = m_Map.find(id);
  if (service == m_Map.end()) {
    return CServicesListElem();
  }
  return service->second;
}

CServicesInfoList CServicesList::getAvailable() const {
  CServicesInfoList availableServices{};
  for (const auto &value : m_Map) {
    ServiceInfo info;
    info.id = value.first;
    info.type = value.second.getType();
    availableServices.push_back(std::move(info));
  }
  return availableServices;
}
