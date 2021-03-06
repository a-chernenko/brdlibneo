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

#include "modules/basemodule.h"

namespace InSys {

struct IBambpex {
  using SharedPtr = std::shared_ptr<IBambpex>;
  virtual ~IBambpex() noexcept = default;
};

namespace Private {

struct CBambpexData final {};

}  // namespace Private

class CBambpex final : public IBambpex, public CBaseModule {
  std::shared_ptr<Private::CBambpexData> d_ptr{
      std::make_shared<Private::CBambpexData>()};

 public:
  CBambpex();

 private:
  void init() final;
  std::string getName() const noexcept final;
};

}  // namespace InSys
