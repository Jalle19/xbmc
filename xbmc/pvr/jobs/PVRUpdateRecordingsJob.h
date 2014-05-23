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

#ifndef PVRUPDATERECORDINGSJOB_H
#define	PVRUPDATERECORDINGSJOB_H

#include "utils/Job.h"
#include "pvr/PVRManager.h"
#include "pvr/recordings/PVRRecordings.h"

namespace PVR
{
class CPVRRecordingsUpdateJob : public CJob
{
public:
  CPVRRecordingsUpdateJob(void) {}
  virtual ~CPVRRecordingsUpdateJob() {}
  virtual const char *GetType() const { return "pvr-update-recordings"; }

  virtual bool DoWork()
  {
    g_PVRRecordings->Update();
    return true;
  }
};
}
#endif	/* CPVRUPDATERECORDINGSJOB_H */

