#include "Country.h"

Country::Country(const Country::Value& value) : value{ value } {}

Country::Value Country::getValue(void) const { return value; }

void Country::setValue(const Country::Value& value) {
	this->value = value;
	this->index = static_cast<size_t>(value);
}

unsigned short int Country::getAreaCode(void) const { return AREA_CODE[index]; }

std::string Country::getDenomination(void) const { return *new std::string(DENOMINATION[index]); }

std::string Country::getStringValue(void) const { return *new std::string(VALUE[index]); }

std::string Country::toString(void) const { return getDenomination() + ", " + getStringValue() + " (+" + std::to_string(getAreaCode()) + ')'; }