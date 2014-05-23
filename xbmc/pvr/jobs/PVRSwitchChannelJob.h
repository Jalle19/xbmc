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

#ifndef PVRSWITCHCHANNELJOB_H
#define	PVRSWITCHCHANNELJOB_H

#include "PVRJob.h"
#include "pvr/PVRManager.h"

namespace PVR
{
class CPVRSwitchChannelJob : public CPVRJob
{
public:
  CPVRSwitchChannelJob(CFileItem* previous, CFileItem* next) : m_previous(previous), m_next(next) {}
  virtual ~CPVRSwitchChannelJob() {}
  virtual const char *GetType() const { return "pvr-channel-switch"; }

  virtual bool DoWork()
  {
    // announce OnStop and delete m_previous when done
    if (m_previous)
    {
      CVariant data(CVariant::VariantTypeObject);
      data["end"] = true;
      ANNOUNCEMENT::CAnnouncementManager::Announce(ANNOUNCEMENT::Player, "xbmc", "OnStop", CFileItemPtr(m_previous), data);
    }

    // announce OnPlay if the switch was successful
    if (m_next)
    {
      CVariant param;
      param["player"]["speed"] = 1;
      param["player"]["playerid"] = g_playlistPlayer.GetCurrentPlaylist();
      ANNOUNCEMENT::CAnnouncementManager::Announce(ANNOUNCEMENT::Player, "xbmc", "OnPlay", CFileItemPtr(new CFileItem(*m_next)), param);
    }

    return true;
  }
private:
  CFileItem* m_previous;
  CFileItem* m_next;
};
}

#endif	/* PVRSWITCHCHANNELJOB_H */

