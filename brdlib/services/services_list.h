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

#include <any>
#include <map>
#include <vector>

#include "service_id.h"
#include "service_interface.h"

namespace InSys {

using CServiceAny = std::any;

class CServicesListElem final {
 public:
  using ValueType = std::pair<ServiceType, CServiceAny>;
  CServicesListElem() = default;
  CServicesListElem(const CServicesListElem &) = default;
  CServicesListElem(CServicesListElem &&) = default;
  CServicesListElem &operator=(const CServicesListElem &) = default;
  CServicesListElem &operator=(CServicesListElem &&) noexcept = default;
  ~CServicesListElem() noexcept = default;

  CServicesListElem(IService::SharedPtr &&service);
  CServicesListElem(const IService::SharedPtr &service);
  bool isAvailable() const noexcept { return m_Value.second.has_value(); }
  template <typename ServiceInterface>
  auto getInterface() const {
    return ServiceCast<ServiceInterface>(
        std::any_cast<IService::SharedPtr>(m_Value.second));
  }
  template <typename ServiceInterface>
  bool getInterface(ServiceInterface &service) const {
    try {
      service = ServiceCast<ServiceInterface>(
          std::any_cast<IService::SharedPtr>(m_Value.second));
    } catch (const std::bad_any_cast &) {
      return false;
    }
    return true;
  }
  inline auto getType() const noexcept { return m_Value.first; }

 private:
  ValueType m_Value;
};

struct ServiceInfo {
  ServiceId id;
  ServiceType type;
};

using CServicesInfoList = std::vector<ServiceInfo>;

class CServicesList final {
  std::map<ServiceId, CServicesListElem> m_Map;

 public:
  CServicesList() = default;
  CServicesList(const CServicesList &) = delete;
  CServicesList(CServicesList &&) = delete;
  CServicesList &operator=(const CServicesList &) = delete;
  CServicesList &operator=(CServicesList &&) noexcept = delete;
  ~CServicesList() noexcept = default;

  inline bool add(ServiceId id, IService::SharedPtr &&service) {
    return m_Map.emplace(id, std::move(service)).second;
  }
  inline bool add(ServiceId id, const IService::SharedPtr &service) {
    return m_Map.emplace(id, service).second;
  }
  CServicesListElem find(ServiceId) const;
  inline auto empty() const noexcept { return m_Map.empty(); }
  inline void clear() noexcept { m_Map.clear(); }
  inline auto remove(ServiceId id) noexcept { m_Map.erase(id); }
  CServicesInfoList getAvailable() const;
};

}  // namespace InSys
