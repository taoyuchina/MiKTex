/* mikui.cpp:

   Copyright (C) 2000-2018 Christian Schenk

   This file is part of the MiKTeX UI Library.

   The MiKTeX UI Library is free software; you can redistribute it
   and/or modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2, or
   (at your option) any later version.

   The MiKTeX UI Library is distributed in the hope that it will be
   useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with the MiKTeX UI Library; if not, write to the Free
   Software Foundation, 59 Temple Place - Suite 330, Boston, MA
   02111-1307, USA. */

#include "StdAfx.h"

#include <afxdllx.h>

#include "internal.h"

using namespace MiKTeX::Core;
using namespace MiKTeX::Packages;
using namespace std;

AFX_EXTENSION_MODULE MikuiDLL = { FALSE, nullptr };

extern "C" int APIENTRY DllMain(HINSTANCE hInstance, DWORD reason, LPVOID pReserved)
{
  UNREFERENCED_PARAMETER(pReserved);

  if (reason == DLL_PROCESS_ATTACH)
  {
    if (!AfxInitExtensionModule(MikuiDLL, hInstance))
    {
      return 0;
    }
    new CDynLinkLibrary(MikuiDLL);
  }
  else if (reason == DLL_PROCESS_DETACH)
  {
    AfxTermExtensionModule(MikuiDLL);
  }
  return 1;
}

MIKTEXUIEXPORT void MIKTEXCEECALL MiKTeX::UI::MFC::InitializeFramework()
{
  if (!AfxWinInit(::GetModuleHandle(nullptr), nullptr, ::GetCommandLine(), 0))
  {
    MIKTEX_UNEXPECTED();
  }
}
