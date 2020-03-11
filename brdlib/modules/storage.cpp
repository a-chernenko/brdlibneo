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

#include "storage.h"

using namespace InSys;

CStorageReference::CStorageReference(CStorage &storage) : m_Storage{storage} {}

CStorageElem CStorage::find(const std::string &key) const {
  if (m_Map.empty()) {
    return CStorageElem();
  }
  auto hash_value = std::hash<std::string>{}(key);
  auto value = m_Map.find(hash_value);
  if (value == m_Map.end()) {
    return CStorageElem();
  }
  return value->second;
}
