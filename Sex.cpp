#include "Sex.h"

Sex::Sex(const Sex::Value& value) : value{ value } {}

Sex::Value Sex::getValue(void) const { return value; }

void Sex::setValue(const Sex::Value& value) {
	this->value = value;
	this->index = static_cast<size_t>(value);
}

std::string Sex::getDenomination(void) const { return *new std::string(DENOMINATION[index]); }

std::string Sex::getStringValue(void) const { return *new std::string(VALUE[index]); }

std::string Sex::toString(void) const { return getDenomination() + ", " + getStringValue(); }