#include "Cast.h"

Cast::Cast(const Sex* sex, const Cast::Value& value) : SEX{ sex }, value{ value } {}

Cast::Value Cast::getValue(void) const { return value; }

void Cast::setValue(const Cast::Value& value) {
	this->value = value;
	this->index = static_cast<size_t>(value);
}

std::string Cast::getDenomination(void) const { return SEX->getValue() == Sex::Value::FEMALE ? *new std::string(FEMALE_DENOMINATION[index]) : *new std::string(DENOMINATION[index]); }

std::string Cast::getStringValue(void) const { return *new std::string(VALUE[index]); }

std::string Cast::toString(void) const { return getDenomination() + ", " + getStringValue(); }