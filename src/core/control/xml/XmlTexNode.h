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

#include "XmlNode.h"

class XmlTexNode: public XmlNode {
public:
    XmlTexNode(const char* tag, std::string&& binaryData);
    virtual ~XmlTexNode();

public:
    void writeOut(OutputStream* out) override;

private:
    /**
     * Binary .PNG or .PDF
     */
    std::string binaryData;
};
