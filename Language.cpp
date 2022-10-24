#include "Language.h"

Language::Language(const Language::Value& value) : value{ value } {}

Language::Value Language::getValue(void) const { return value; }

void Language::setValue(const Language::Value& value) {
	this->value = value;
	this->index = static_cast<size_t>(value);
}

std::string Language::getDenomination(void) const { return *new std::string(DENOMINATION[index]); }

std::string Language::getStringValue(void) const { return *new std::string(VALUE[index]); }

std::string Language::toString(void) const { return getDenomination() + ", " + getStringValue(); }