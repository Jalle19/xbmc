/*
 *      Copyright (C) 2012-2014 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#ifndef PVRSTARTMANAGERJOB_H
#define	PVRSTARTMANAGERJOB_H

#include "PVRJob.h"

namespace PVR
{
  class CPVRStartManagerJob : public CPVRJob
  {
  public:
    CPVRStartManagerJob(bool bOpenPVRWindow = false) :
      m_bOpenPVRWindow(bOpenPVRWindow) {}
    ~CPVRStartManagerJob(void) {}
    virtual const char *GetType() const { return "pvr-start-manager"; }

    virtual bool DoWork(void)
    {
      g_PVRManager.Start(false, m_bOpenPVRWindow);
      return true;
    }
  private:
    bool m_bOpenPVRWindow;
  };
}

#endif	/* PVRSTARTMANAGERJOB_H */

