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

#include <chrono>
#include <mutex>
#include <thread>

namespace InSys {

enum {
  DEVScmd_REGREADDIR,
  DEVScmd_REGREADSDIR,
  DEVScmd_REGREADIND,
  DEVScmd_REGREADSIND,
  DEVScmd_REGWRITEDIR,
  DEVScmd_REGWRITESDIR,
  DEVScmd_REGWRITEIND,
  DEVScmd_REGWRITESIND,
  DEVScmd_SETSTATIRQ,
  DEVScmd_CLEARSTATIRQ,
  DEVScmd_GETBASEADR,
  DEVScmd_WAITSTATIRQ,
  DEVScmd_PACKEXECUTE
};

class CModuleControl {
  int32_t m_TetrId{-1};
  int32_t m_TetrNum{-1};
  int32_t m_idxMain{-1};

  bool read(uint32_t, int32_t, uint32_t&) const noexcept;
  bool write(uint32_t, int32_t, uint32_t) const noexcept;

 public:
  // CModuleControl() = delete;
  CModuleControl(const CModuleControl&) = delete;
  CModuleControl& operator=(const CModuleControl&) = delete;
  CModuleControl(CModuleControl&&) = delete;
  CModuleControl& operator=(CModuleControl&&) = delete;
  ~CModuleControl() noexcept = default;

  CModuleControl(int32_t index = -1) noexcept;
  bool find(uint32_t) noexcept;
  bool test(uint32_t) const noexcept;
  bool waitReady(const std::chrono::milliseconds&) const noexcept;
  inline bool writeDirect(int32_t regNo, uint32_t val) const noexcept {
    return write(DEVScmd_REGWRITEDIR, regNo, val);
  }
  inline bool writeIndirect(int32_t regNo, uint32_t val) const noexcept {
    return write(DEVScmd_REGWRITEIND, regNo, val);
  }
  inline bool readDirect(int32_t regNo, uint32_t& val) const noexcept {
    return read(DEVScmd_REGREADDIR, regNo, val);
  }
  inline bool readIndirect(int32_t regNo, uint32_t& val) const noexcept {
    return read(DEVScmd_REGREADIND, regNo, val);
  }
  void setIndex(int32_t index) noexcept { m_idxMain = index; }
};

struct CModuleControlReference {
  CModuleControlReference() = delete;
  CModuleControlReference(CModuleControl&);
  CModuleControl& m_ModuleControl;
};

}  // namespace InSys
