/*
 * Xournal++
 *
 * A selection while you are selection, not for editing, only for selection
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <string>
#include <vector>

#include "gui/Redrawable.h"
#include "model/Element.h"
#include "model/PageRef.h"
#include "util/Util.h"


class Selection: public ShapeContainer {
public:
    Selection(Redrawable* view);
    ~Selection() override;

public:
    virtual bool finalize(PageRef page) = 0;
    virtual void paint(cairo_t* cr, GdkRectangle* rect, double zoom) = 0;
    virtual void currentPos(double x, double y) = 0;
    virtual bool userTapped(double zoom) = 0;

private:
protected:
    std::vector<Element*> selectedElements;
    PageRef page;
    Redrawable* view;

    double x1Box;
    double x2Box;
    double y1Box;
    double y2Box;

    friend class EditSelection;
};

class RectSelection: public Selection {
public:
    RectSelection(double x, double y, Redrawable* view);
    ~RectSelection() override;

public:
    bool finalize(PageRef page) override;
    void paint(cairo_t* cr, GdkRectangle* rect, double zoom) override;
    void currentPos(double x, double y) override;
    bool contains(double x, double y) override;
    bool userTapped(double zoom) override;

private:
    double sx;
    double sy;
    double ex;
    double ey;
    double maxDist = 0;

    /**
     * In zoom coordinates
     */
    double x1;
    double x2;
    double y1;
    double y2;
};

class RegionPoint;

class RegionSelect: public Selection {
public:
    RegionSelect(double x, double y, Redrawable* view);

public:
    bool finalize(PageRef page) override;
    void paint(cairo_t* cr, GdkRectangle* rect, double zoom) override;
    void currentPos(double x, double y) override;
    bool contains(double x, double y) override;
    bool userTapped(double zoom) override;

private:
    std::vector<RegionPoint> points;
};
