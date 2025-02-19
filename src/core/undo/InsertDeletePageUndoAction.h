/*
 * Xournal++
 *
 * Undo action for insert page / delete page
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <string>
#include <vector>

#include "UndoAction.h"


class InsertDeletePageUndoAction: public UndoAction {
public:
    InsertDeletePageUndoAction(const PageRef& page, int pagePos, bool inserted);
    ~InsertDeletePageUndoAction() override;

public:
    bool undo(Control* control) override;
    bool redo(Control* control) override;

    std::string getText() override;

private:
    bool insertPage(Control* control);
    bool deletePage(Control* control);

private:
    bool inserted;
    int pagePos;
};
