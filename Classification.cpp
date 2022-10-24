#include "Classification.h"

Classification::Classification(const Classification::Value& value) : value{ value } {}

Classification::Value Classification::getValue(void) const { return value; }

void Classification::setValue(const Classification::Value& value) {
	this->value = value;
	this->index = static_cast<size_t>(value);
}

std::string Classification::getDenomination(void) const { return *new std::string(DENOMINATION[index]); }

std::string Classification::getStringValue(void) const { return *new std::string(VALUE[index]); }

std::string Classification::toString(void) const { return getDenomination() + ", " + getStringValue(); }