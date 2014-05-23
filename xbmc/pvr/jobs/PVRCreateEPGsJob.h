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

#ifndef PVRCREATEEPGSJOB_H
#define	PVRCREATEEPGSJOB_H

#include "PVRJob.h"
#include "pvr/PVRManager.h"

namespace PVR
{
class CPVRCreateEpgsJob : public CPVRJob
{
public:
  CPVRCreateEpgsJob(void) {}
  virtual ~CPVRCreateEpgsJob() {}
  virtual const char *GetType() const { return "pvr-create-epgs"; }

  virtual bool DoWork()
  {
    return g_PVRManager.CreateChannelEpgs();
  }
};
}
#endif	/* PVRCREATEEPGSJOB_H */

