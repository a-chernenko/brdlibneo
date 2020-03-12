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

#include "brdlibneo.h"

namespace InSys {

struct IFm9009_DdcService {
  using SharedPtr = std::shared_ptr<IFm9009_DdcService>;
  virtual ~IFm9009_DdcService() noexcept = default;
};

namespace Private {

struct CFm9009_DdcServiceData final : CServiceControl {
  CFm9009_DdcServiceData(CModuleControl &, CStorage &);
};

}  // namespace Private

class CFm9009_DdcService final : public IFm9009_DdcService, public CDdcService {
  std::shared_ptr<Private::CFm9009_DdcServiceData> d_ptr;

 public:
  CFm9009_DdcService(CModuleControl &, CStorage &);

 private:
  std::string getName() const noexcept final;
};

}  // namespace InSys
