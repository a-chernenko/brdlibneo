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

#include "modules/submodule.h"

namespace InSys {

struct IFm9009 {
  using SharedPtr = std::shared_ptr<IFm9009>;
  virtual ~IFm9009() noexcept = default;
};

namespace Private {

struct CFm9009_Data final {};

}  // namespace Private

class CFm9009 final : public IFm9009, public CSubModule {
  std::shared_ptr<Private::CFm9009_Data> d_ptr{
      std::make_shared<Private::CFm9009_Data>()};

 public:
  CFm9009() = default;
  CFm9009(const CFm9009 &) = default;
  CFm9009(CFm9009 &&) = default;
  CFm9009 &operator=(const CFm9009 &) = default;
  CFm9009 &operator=(CFm9009 &&) noexcept = default;
  ~CFm9009() noexcept = default;

 private:
  void init() final;
  std::string getName() const noexcept final;
};

}  // namespace InSys
