#include "Participant.h"

unsigned long long int Participant::index = 0;

Participant::Participant(const std::string& email, const std::string& isp, const std::string& phoneNumber, const std::string& username, const std::string& password, const std::tm& birthday, const std::string& name, const std::string& firstLastname, const std::string& secondLastName, const std::string& stageName, const std::tm& debut, const std::string& description, std::vector<Cast::Value>* cast, const Country::Value& country, const Sex::Value& sex, const std::string& website) : User::User(email, isp, phoneNumber, username, password, birthday, name, firstLastname, secondLastName, country, sex, website) {
	setIdentificator("PU", ++index);
	setStageName(stageName);
	setDescription(description);
	setDebut(debut);
	setCast(cast);
}

void Participant::setIdentificator(const std::string& prefix, const unsigned long long int& index) {
	participantIdentificator = prefix + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG, Identifiable::TimeFormat::REGISTRATION) + std::to_string(index);
	setChangeLog();
}

std::string Participant::getData(void) const { return "<Participante>\n- Identificador: " + getIdentificator() + "\n- Identificador de participante: " + getParticipantIdentificator() + "\n- Fecha de creación: " + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG, Identifiable::TimeFormat::BRIEF) + "\n- Fecha de modificación: " + getRegistrationString(Identifiable::RegistrationIndex::CHANGE_LOG, Identifiable::TimeFormat::BRIEF); }

std::string Participant::toString(void) const { return "<Participante> " + getIdentificator() + '-' + getParticipantIdentificator() + " (" + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG) + ')'; }

std::string Participant::getParticipantIdentificator(void) const { return participantIdentificator; }

std::string Participant::getStageName(void) const { return stageName; }

std::string Participant::getDescription(void) const { return description; }

std::tm Participant::getDebut(void) const { return debut; }

std::string Participant::getDebutString(const Identifiable::TimeFormat& format) const { return Identifiable::getTimeString(debut, format); }

std::vector<Cast> Participant::getCast(void) const { return cast; }

void Participant::setStageName(const std::string& stageName) {
	this->stageName = stageName.empty() ? "NA" : stageName;
	setChangeLog();
}

void Participant::setDescription(const std::string& description) {
	this->description = description.empty() ? "NA" : description;
	setChangeLog();
}

bool Participant::setDebut(const unsigned short int& day, const unsigned short int& month, const unsigned short int& year, const unsigned short int& weekDay) { return setDebut(std::tm{ 0, 0, 0, day, month, year, weekDay, 0, 0 }); }

bool Participant::setDebut(const std::tm& debut) {
	const bool STATUS{ debut.tm_mday >= 1 && debut.tm_mday <= 31 && debut.tm_mon >= 0 && debut.tm_mon <= 11 && debut.tm_year >= 0 && debut.tm_year <= 122 && debut.tm_wday >= 0 && debut.tm_wday <= 6 };
	if (STATUS) {
		this->debut = { 0, 0, 0, debut.tm_mday, debut.tm_mon, debut.tm_year, debut.tm_wday, 0, 0 };
		setChangeLog();
	}
	return STATUS;
}

void Participant::setCast(std::vector<Cast::Value>* cast) {
	this->cast.clear();
	if (cast->size() > 0) {
		std::sort(cast->begin(), cast->end());
		auto last = std::unique(cast->begin(), cast->end());
		cast->erase(last, cast->end());
		if (*cast->begin() == Cast::Value::NONE) cast->erase(cast->begin());
		for (const Cast::Value& value : *cast) this->cast.push_back(*new Cast(getSexReference(), value));
		this->cast.shrink_to_fit();
		setChangeLog();
	}
}

bool Participant::addCast(const Cast::Value& cast) {
	if (cast != Cast::Value::NONE) {
		for (const Cast& value : this->cast)
			if (cast == value.getValue()) return false;
		this->cast.push_back(*new Cast(getSexReference(), cast));
		this->cast.shrink_to_fit();
		setChangeLog();
		return true;
	} else return false;
}

bool Participant::deleteCast(const Cast::Value& cast) {
	if (cast != Cast::Value::NONE) {
		for (size_t index = 0; index < this->cast.size(); ++index) {
			if (cast == this->cast[index].getValue()) {
				this->cast.erase(this->cast.begin() + index);
				this->cast.shrink_to_fit();
				setChangeLog();
				return true;
			}
		}
	}
	return false;
}