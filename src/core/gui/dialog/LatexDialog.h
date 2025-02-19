/*
 * Xournal++
 *
 * Latex implementation
 *
 * @author W Brenna
 * http://wbrenna.ca
 *
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "gui/GladeGui.h"
#include "model/TexImage.h"

class LatexDialog: public GladeGui {
public:
    LatexDialog() = delete;
    LatexDialog(const LatexDialog& other) = delete;
    LatexDialog& operator=(const LatexDialog& other) = delete;
    LatexDialog(GladeSearchpath* gladeSearchPath);
    ~LatexDialog() override;

public:
    /**
     * Show the dialog.
     */
    void show(GtkWindow* parent) override;

    /**
     * Show the dialog, optionally selecting the text field contents by default.
     */
    void show(GtkWindow* parent, bool selectTex);

    // Set and retrieve text from text box
    void setFinalTex(std::string texString);
    std::string getFinalTex();

    // Set and retrieve temporary Tex render
    void setTempRender(PopplerDocument* pdf);

    // Necessary for the controller in order to connect the 'text-changed'
    // signal handler
    GtkTextBuffer* getTextBuffer();

    /**
     * @return The contents of the formula input text buffer.
     */
    std::string getBufferContents();

private:
    // Temporary render
    GtkWidget* texTempRender;
    cairo_surface_t* scaledRender = nullptr;
    GtkCssProvider* cssProvider;

    // Text field
    GtkWidget* texBox;
    GtkTextBuffer* textBuffer;

    /**
     * The final LaTeX string to save once the dialog is closed.
     */
    std::string finalLatex;
};
