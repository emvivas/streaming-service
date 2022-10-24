#include "Identifiable.h"

std::string Identifiable::getTimeString(const std::tm& time, const Identifiable::TimeFormat& format) {
	char formattedText[FORMATTED_TEXT_INDEX_LIMIT]{};
	switch (format) {
	case Identifiable::TimeFormat::DETAILED:
		strftime(formattedText, sizeof(formattedText), "%A %d de %B de %Y, %H:%M:%S horas", &time);
		break;
	case Identifiable::TimeFormat::BRIEF:
		strftime(formattedText, sizeof(formattedText), "%c", &time);
		break;
	case Identifiable::TimeFormat::DETAILED_DATE:
		strftime(formattedText, sizeof(formattedText), "%A %d de %B de %Y", &time);
		break;
	case Identifiable::TimeFormat::BRIEF_DATE:
		strftime(formattedText, sizeof(formattedText), "%d/%m/%y", &time);
		break;
	case Identifiable::TimeFormat::DETAILED_HOUR:
		strftime(formattedText, sizeof(formattedText), "%H:%M:%S horas", &time);
		break;
	case Identifiable::TimeFormat::BRIEF_HOUR:
		strftime(formattedText, sizeof(formattedText), "%R", &time);
		break;
	case Identifiable::TimeFormat::REGISTRATION:
		strftime(formattedText, sizeof(formattedText), "%y%m%d", &time);
		break;
	case Identifiable::TimeFormat::LENGTH:
		strftime(formattedText, sizeof(formattedText), "%y años, %m meses, %d días, %H horas, %M minutos y %S segundos", &time);
		break;
	default:
		strftime(formattedText, sizeof(formattedText), "%d/%m/%y %R", &time);
	}
	return formattedText;
}

Identifiable::Identifiable(void) {
	const std::time_t CURRENT_TIME{ std::time(nullptr) };
	localtime_s(&registration[static_cast<size_t>(Identifiable::RegistrationIndex::CREATION_LOG)], &CURRENT_TIME);
	setChangeLog(CURRENT_TIME);
}

std::ostream& operator<<(std::ostream& out, const Identifiable& identifiable) {
	out << identifiable.toString();
	return out;
}

std::string Identifiable::getIdentificator(void) const { return identificator; }

std::tm Identifiable::getRegistration(const Identifiable::RegistrationIndex& index) const { return registration[static_cast<size_t>(index)]; }

std::string Identifiable::getRegistrationString(const Identifiable::RegistrationIndex& index, const Identifiable::TimeFormat& format) const {
	return getTimeString(registration[static_cast<size_t>(index)], format);
}

void Identifiable::setIdentificator(const std::string& prefix, const unsigned long long int& index) {
	identificator = prefix + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG, Identifiable::TimeFormat::REGISTRATION) + std::to_string(index);
	setChangeLog();
}

void Identifiable::setChangeLog(void) {
	const std::time_t CURRENT_TIME{ std::time(nullptr) };
	localtime_s(&registration[static_cast<size_t>(Identifiable::RegistrationIndex::CHANGE_LOG)], &CURRENT_TIME);
}

void Identifiable::setChangeLog(const std::time_t& currentTime) { localtime_s(&registration[static_cast<size_t>(Identifiable::RegistrationIndex::CHANGE_LOG)], &currentTime); }

std::string Identifiable::getData(void) const { return "<Identificable>\n- Identificador: " + getIdentificator() + "\n- Fecha de creación: " + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG, Identifiable::TimeFormat::BRIEF) + "\n- Fecha de modificación: " + getRegistrationString(Identifiable::RegistrationIndex::CHANGE_LOG, Identifiable::TimeFormat::BRIEF); }

std::string Identifiable::toString(void) const { return "<Identificable> " + getIdentificator() + " (" + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG) + ')'; }