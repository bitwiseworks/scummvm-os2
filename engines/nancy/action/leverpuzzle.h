/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef NANCY_ACTION_LEVERPUZZLE_H
#define NANCY_ACTION_LEVERPUZZLE_H

#include "engines/nancy/action/actionrecord.h"
#include "engines/nancy/renderobject.h"

#include "engines/nancy/commontypes.h"

#include "common/str.h"
#include "common/array.h"

#include "graphics/managed_surface.h"

namespace Nancy {
namespace Action {

class LeverPuzzle : public ActionRecord, public RenderObject {
public:
    enum SolveState { kNotSolved, kPlaySound, kWaitForSound };
    LeverPuzzle(RenderObject &redrawFrom) : RenderObject(redrawFrom) {}
    virtual ~LeverPuzzle() {}

    virtual void init() override;
    
    virtual void readData(Common::SeekableReadStream &stream) override;
    virtual void execute() override;
    virtual void handleInput(NancyInput &input) override;
    virtual void onPause(bool pause) override;

    Common::String imageName; // 0x0
    Common::Array<Common::Array<Common::Rect>> srcRects; // 0xA, 0xC0 bytes
    Common::Array<Common::Rect> destRects; // 0xCA, 0x30 bytes
    Common::Array<byte> correctSequence; // 0xFA, 3 bytes
    SoundDescription moveSound; // 0x100
    SoundDescription noMoveSound; // 0x122
    SceneChangeDescription solveExitScene; // 0x144
    EventFlagDescription flagOnSolve; // 0x14E
    uint16 solveSoundDelay; // 0x151
    SoundDescription solveSound; // 0x153
    SceneChangeDescription exitScene; // 0x175
    EventFlagDescription flagOnExit; // 0x17F
    Common::Rect exitHotspot; // 0x182

    Common::Array<byte> playerSequence;
    Common::Array<bool> leverDirection;
    Graphics::ManagedSurface image;
    Time solveSoundPlayTime;
    SolveState solveState = kNotSolved;

protected:
    virtual Common::String getRecordTypeName() const override { return "LeverPuzzle"; }

    virtual uint16 getZOrder() const override { return 7; }
    virtual bool isViewportRelative() const override { return true; }

    void drawLever(uint id);
};

} // End of namespace Action
} // End of namespace Nancy

#endif // NANCY_ACTION_LEVERPUZZLE_H