#include "Rating.h"

Rating::Rating(const Rating::Value& value) : value{ value } {}

Rating::Value Rating::getValue(void) const { return value; }

void Rating::setValue(const Rating::Value& value) {
	this->value = value;
	this->index = static_cast<size_t>(value);
}

std::string Rating::getDenomination(void) const { return *new std::string(DENOMINATION[index]); }

std::string Rating::getStringValue(void) const { return *new std::string(VALUE[index]); }

std::string Rating::toString(void) const { return getDenomination() + ", " + getStringValue(); }