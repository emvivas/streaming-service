#include "Choice.h"

unsigned long long int Choice::index = 0;

Choice::Choice(User* user, const Rating::Value& rating, const std::string& comments) : user{ user } {
	setIdentificator("C", ++index);
	setRating(rating);
	setComments(comments);
}

std::string Choice::getData(void) const { return "<Elección>\n- Identificador: " + getIdentificator() + "\n- Fecha de creación: " + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG, Identifiable::TimeFormat::BRIEF) + "\n- Fecha de modificación: " + getRegistrationString(Identifiable::RegistrationIndex::CHANGE_LOG, Identifiable::TimeFormat::BRIEF); }

std::string Choice::toString(void) const { return "<Elección> " + getIdentificator() + " (" + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG) + ')'; }

std::string Choice::getComments(void) const { return comments; }

User Choice::getUser(void) const { return *user; }

Rating Choice::getRating(void) const { return rating; }

void Choice::setComments(const std::string& comments) {
	this->comments = comments.empty() ? "NA" : comments;
	setChangeLog();
}

void Choice::setRating(const Rating::Value& rating) {
	this->rating = *new Rating(rating);
	setChangeLog();
}