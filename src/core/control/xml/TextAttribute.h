/*
 * Xournal++
 *
 * XML Writer helper class
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "Attribute.h"

class TextAttribute: public XMLAttribute {
public:
    TextAttribute(std::string name, std::string value);
    ~TextAttribute() override;

public:
    void writeOut(OutputStream* out) override;

private:
    std::string value;
};
