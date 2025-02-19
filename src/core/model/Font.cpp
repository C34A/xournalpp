#include "Font.h"

#include <utility>

#include "util/serializing/ObjectInputStream.h"
#include "util/serializing/ObjectOutputStream.h"

XojFont::XojFont() = default;

XojFont::~XojFont() = default;

auto XojFont::getName() const -> std::string { return this->name; }

void XojFont::setName(std::string name) { this->name = std::move(name); }

auto XojFont::getSize() const -> double { return size; }

void XojFont::setSize(double size) { this->size = size; }

void XojFont::operator=(const XojFont& font) {
    this->name = font.name;
    this->size = font.size;
}

void XojFont::serialize(ObjectOutputStream& out) const {
    out.writeObject("XojFont");

    out.writeString(this->name);
    out.writeDouble(this->size);

    out.endObject();
}

void XojFont::readSerialized(ObjectInputStream& in) {
    in.readObject("XojFont");

    this->name = in.readString();
    this->size = in.readDouble();

    in.endObject();
}
