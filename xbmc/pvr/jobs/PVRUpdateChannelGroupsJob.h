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

#ifndef PVRUPDATECHANNELGROUPSJOB_H
#define	PVRUPDATECHANNELGROUPSJOB_H

#include "PVRJob.h"
#include "pvr/PVRManager.h"

namespace PVR
{
class CPVRChannelGroupsUpdateJob : public CPVRJob
{
public:
  CPVRChannelGroupsUpdateJob(void) {}
  virtual ~CPVRChannelGroupsUpdateJob() {}
  virtual const char *GetType() const { return "pvr-update-channelgroups"; }

  virtual bool DoWork()
  {
    return g_PVRChannelGroups->Update(false);
  }
};
}
#endif	/* PVRUPDATECHANNELGROUPSJOB_H */

