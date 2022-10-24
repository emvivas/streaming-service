#include "FilmGenre.h"

FilmGenre::FilmGenre(const FilmGenre::Value& value) : value{ value } {}

FilmGenre::Value FilmGenre::getValue(void) const { return value; }

void FilmGenre::setValue(const FilmGenre::Value& value) {
	this->value = value;
	this->index = static_cast<size_t>(value);
}

std::string FilmGenre::getDenomination(void) const { return *new std::string(DENOMINATION[index]); }

std::string FilmGenre::getStringValue(void) const { return *new std::string(VALUE[index]); }

std::string FilmGenre::toString(void) const { return getDenomination() + ", " + getStringValue(); }