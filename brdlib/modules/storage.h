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
#include <functional>
#include <map>
#include <string>

namespace InSys {

class CStorageElem final {
 public:
  using ValueType = std::any;
  CStorageElem() = default;
  CStorageElem(const CStorageElem &) = default;
  CStorageElem(CStorageElem &&) = default;
  CStorageElem &operator=(const CStorageElem &) = default;
  CStorageElem &operator=(CStorageElem &&) noexcept = default;
  ~CStorageElem() noexcept = default;

  template <typename ElementType = ValueType>
  CStorageElem(ElementType &&value)
      : m_Value{std::forward<ElementType>(value)} {}
  bool hasValue() const noexcept { return m_Value.has_value(); }
  template <typename ElementType>
  auto getValue() const {
    return std::any_cast<ElementType>(m_Value);
  }
  template <typename ElementType>
  bool getValue(ElementType &value) const {
    try {
      value = std::any_cast<ElementType>(m_Value);
    } catch (const std::bad_any_cast &) {
      return false;
    }
    return true;
  }

 private:
  ValueType m_Value;
};

class CStorage final {
  std::map<size_t, CStorageElem> m_Map;

 public:
  CStorage() = default;
  CStorage(const CStorage &) = delete;
  CStorage(CStorage &&) = default;
  CStorage &operator=(const CStorage &) = delete;
  CStorage &operator=(CStorage &&) noexcept = delete;
  ~CStorage() noexcept = default;

  template <typename ElementType = CStorageElem>
  bool add(const std::string &key, ElementType &&value) {
    auto hash_value = std::hash<std::string>{}(key);
    return m_Map.emplace(hash_value, std::forward<ElementType>(value)).second;
  }
  CStorageElem find(const std::string &key) const;
  inline auto empty() const noexcept { return m_Map.empty(); }
};

struct CStorageReference {
  CStorageReference() = delete;
  CStorageReference(CStorage &);
  CStorage &m_Storage;
};

}  // namespace InSys
