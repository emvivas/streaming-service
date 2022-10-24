#include "Classifiable.h"

Classifiable::Classifiable(const std::string& denomination, const std::string& slogan, const std::string& description, std::vector<Language::Value>* languages, std::vector<Participant>* participants) {
	setDenomination(denomination);
	setSlogan(slogan);
	setDescription(description);
	setLanguages(languages);
	setParticipants(participants);
}

std::string Classifiable::getData(void) const { return "<Clasificable>\n- Identificador: " + getIdentificator() + "\n- Fecha de creación: " + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG, Identifiable::TimeFormat::BRIEF) + "\n- Fecha de modificación: " + getRegistrationString(Identifiable::RegistrationIndex::CHANGE_LOG, Identifiable::TimeFormat::BRIEF); }

std::string Classifiable::toString(void) const { return "<Clasificable> " + getIdentificator() + " (" + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG) + ')'; }

void Classifiable::setRating(std::vector<Choice>* choices) {
	unsigned long long int accumulateRating{ 0l };
	for (const Choice& choice : *choices) accumulateRating += static_cast<unsigned short int>(choice.getRating().getValue());
	meanRating = choices->size() > 0 ? (accumulateRating + 0.0f) / choices->size() : 0.0f;
	rating = *new Rating(static_cast<Rating::Value>(static_cast<size_t>(round(meanRating))));
	setChangeLog();
}

bool Classifiable::setLength(const unsigned short int& second, const unsigned short int& minute, const unsigned short int& hour, const unsigned short int& day, const unsigned short int& month, const unsigned short int& year) { return setLength(std::tm{ second, minute, hour, day, month, year, 0, 0, 0 }); }

bool Classifiable::setLength(const std::tm& length) {
	const bool STATUS{ length.tm_sec >= 0 && length.tm_sec<=59 && length.tm_min >= 0 && length.tm_min <= 59 && length.tm_hour >= 0 && length.tm_hour <= 23 && length.tm_mday >= 1 && length.tm_mday <= 31 && length.tm_mon >= 0 && length.tm_mon <= 11 && length.tm_year >= 0 };
	if (STATUS) {
		this->length = { length.tm_sec, length.tm_min, length.tm_hour, length.tm_mday, length.tm_mon, length.tm_year, 0, 0, 0 };
		setChangeLog();
	}
	return STATUS;
}

std::string Classifiable::getDenomination(void) const { return denomination; }

std::string Classifiable::getSlogan(void) const { return slogan; }

std::string Classifiable::getTitle(void) const { return getDenomination() + (getSlogan().compare("NA") != 0 ? ", " + getSlogan() : ""); }

std::string Classifiable::getDescription(void) const { return description; }

std::vector<Language> Classifiable::getLanguages(void) const { return languages; }

Rating Classifiable::getRating(void) const { return rating; }

float Classifiable::getMeanRating(void) const { return meanRating; }

std::tm Classifiable::getLength(void) const { return length; }

std::string Classifiable::getLengthString(void) const { return Identifiable::getTimeString(length, Identifiable::TimeFormat::LENGTH); }

std::vector<Participant> Classifiable::getParticipants(void) const { return participants; }

bool Classifiable::setDenomination(const std::string& denomination) {
	const bool STATUS{ !denomination.empty() };
	if (STATUS) {
		this->denomination = denomination;
		setChangeLog();
	}
	return STATUS;
}

void Classifiable::setSlogan(const std::string& slogan) {
	this->slogan = slogan.empty() ? "NA" : slogan;
	setChangeLog();
}

bool Classifiable::setDescription(const std::string& description) {
	const bool STATUS{ !description.empty() };
	if (STATUS) {
		this->description = description;
		setChangeLog();
	}
	return STATUS;
}

void Classifiable::setLanguages(std::vector<Language::Value>* languages) {
	this->languages.clear();
	if (languages->size() > 0) {
		std::sort(languages->begin(), languages->end());
		auto last = std::unique(languages->begin(), languages->end());
		languages->erase(last, languages->end());
		if (*languages->begin() == Language::Value::NONE) languages->erase(languages->begin());
		for (const Language::Value& value : *languages) this->languages.push_back(*new Language(value));
		this->languages.shrink_to_fit();
		setChangeLog();
	}
}

bool Classifiable::addLanguage(const Language::Value& language) {
	if (language != Language::Value::NONE) {
		for (const Language& value : languages)
			if (language == value.getValue()) return false;
		languages.push_back(*new Language(language));
		languages.shrink_to_fit();
		setChangeLog();
		return true;
	} else return false;
}

bool Classifiable::deleteLanguage(const Language::Value& language) {
	if (language != Language::Value::NONE) {
		for (size_t index = 0; index < languages.size(); ++index) {
			if (language == languages[index].getValue()) {
				languages.erase(languages.begin() + index);
				languages.shrink_to_fit();
				setChangeLog();
				return true;
			}
		}
	}
	return false;
}

void Classifiable::setParticipants(std::vector<Participant>* participants) {
	this->participants.clear();
	if (participants->size() > 0) {
		this->participants = *participants;
		this->participants.shrink_to_fit();
		setChangeLog();
	}
}

bool Classifiable::addParticipant(Participant* participant) {
	for (const Participant& value : participants)
		if (participant->getIdentificator().compare(value.getIdentificator()) == 0) return false;
	participants.push_back(*participant);
	participants.shrink_to_fit();
	setChangeLog();
	return true;
}

bool Classifiable::deleteParticipant(Participant* participant) {
	for (size_t index = 0; index < participants.size(); ++index) {
		if (participant->getIdentificator().compare(participants[index].getIdentificator()) == 0) {
			participants.erase(participants.begin() + index);
			participants.shrink_to_fit();
			setChangeLog();
			return true;
		}
	}
	return false;
}