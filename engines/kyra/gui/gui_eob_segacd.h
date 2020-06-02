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
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifdef ENABLE_EOB

#ifndef KYRA_GUI_EOB_SEGACD_H
#define KYRA_GUI_EOB_SEGACD_H

#include "kyra/gui/gui_eob.h"

#ifdef ENABLE_EOB

namespace Kyra {

class GUI_EoB_SegaCD : public GUI_EoB {
public:
	GUI_EoB_SegaCD(EoBEngine *vm);
	~GUI_EoB_SegaCD() override;

private:
	void drawCampMenu() override;
	void initMemorizePrayMenu() override;
	void drawSaveSlotDialog(int x, int y, int id) override;
	bool confirmDialogue(int id) override;
	void displayTextBox(int id, int textColor, bool wait) override;
	void drawMenuButton(Button *b, bool clicked, bool highlight, bool noFill) override;
	void drawSaveSlotButton(int slot, int redrawBox, bool highlight) override;
	int getHighlightSlot() override;
	void memorizePrayMenuPrintString(int spellId, int bookPageIndex, int spellType, bool noFill, bool highLight) override;
	void updateOptionsStrings() override;
	void restParty_updateRestTime(int hours, bool init) override;

	const uint8 *_campMenu;
	Button* _saveLoadCancelButton;
	EoBEngine *_vm;

	struct MenuButtonTiles {
		uint16 nameTbl;
		uint16 srcOffs;
	};

	static const MenuButtonTiles _menuButtonTiles[35];
};

} // End of namespace Kyra

#endif // ENABLE_EOB

#endif

#endif // ENABLE_EOB || ENABLE_LOL