#include "Film.h"

std::deque<Film> Film::films{};

unsigned long long int Film::index = 0;

Film::Film(const std::string& denomination, const std::tm& length, const std::tm& release, const FilmGenre::Value& filmGenre, const Classification::Value& classification, const Country::Value& country, const std::string& region, const std::string& slogan, const std::string& description, const long double& collection, const long double& budget, std::vector<Language::Value>* languages, std::vector<Participant>* participants, std::vector<Choice>* choices, const float& size, const float& frameRate, const unsigned int& dataRate, const unsigned int& totalBitrate, const unsigned short int& frameWidth, const unsigned short int& frameHeight) : Classifiable::Classifiable(denomination, slogan, description, languages, participants) {
	setIdentificator("F", ++index);
	setFrame(frameWidth, frameHeight);
	setDataRate(dataRate);
	setTotalBitrate(totalBitrate);
	setSize(size);
	setFrameRate(frameRate);
	setCollection(collection);
	setBudget(budget);
	setRegion(region);
	setRelease(release);
	setCountry(country);
	setClassification(classification);
	setFilmGenre(filmGenre);
	setChoices(choices);
	setRating(&this->choices);
	setLength(length);
	films.push_back(*this);
	films.shrink_to_fit();
}

std::deque<Film> Film::getFilms(void) { return films; }

Film* Film::getFilm(const size_t& index) { return index >= 0 && index <= films.size() - 1 ? &films[index] : nullptr; }

Film* Film::getRegister(const std::vector<std::string>& data) {
	std::tm length{}, release{};
	std::istringstream* ss{ new std::istringstream(data[2]) };
	ss->imbue(std::locale("es_Es.utf-8"));
	*ss >> std::get_time(&length, "%H:%M:%S");
	ss = new std::istringstream(data[3]);
	ss->imbue(std::locale("es_Es.utf-8"));
	*ss >> std::get_time(&release, "%d/%m/%Y");
	return new Film(data[1], length, release, static_cast<FilmGenre::Value>(std::stoi(data[4])), static_cast<Classification::Value>(std::stoi(data[5])), static_cast<Country::Value>(std::stoi(data[6])), data[7], data[8], data[9], std::stod(data[10]), std::stod(data[11]));
}

std::string Film::getData(void) const {
	return "\t\t" + toString() + ".\n\n\n\t\t- Identificador: " + getIdentificator() + "\n\n\t\t- Denominación: " + getDenomination() + ".\n\n\t\t- Slogan: " + getSlogan() + ".\n\n\t\t- Género cinematográfico: " + getFilmGenre().toString() + ".\n\n\t\t- Clasificación: " + getClassification().toString() + ".\n\n\t\t- Localización del rodaje: " + getLocation() + ".\n\n\t\t- Sinopsis:\n\t\t" + getDescription() + ".\n\n\t\t- Fecha de creación : " + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG, Identifiable::TimeFormat::BRIEF) + "\n\n\t\t- Fecha de modificación : " + getRegistrationString(Identifiable::RegistrationIndex::CHANGE_LOG, Identifiable::TimeFormat::BRIEF);
}

std::string Film::toString(void) const { return "<Filme> " + getIdentificator() + ": " + getTitle(); }

Country Film::getCountry(void) const { return country; }

bool Film::setCountry(const Country::Value& country) {
	const bool STATUS{ country != Country::Value::NONE };
	if (STATUS) this->country = *new Country(country);
	return STATUS;
}

std::string Film::getRegion(void) const { return region; }

std::string Film::getLocation(void) const { return region + ", " + country.getStringValue(); }

std::tm Film::getRelease(void) const { return release; }

std::string Film::getReleaseString(const Identifiable::TimeFormat& format) const { return Identifiable::getTimeString(release, format); }

FilmGenre Film::getFilmGenre(void) const { return filmGenre; }

Classification Film::getClassification(void) const { return classification; }

float Film::getSize(void) const { return size; }

float Film::getFrameRate(void) const { return frameRate; }

unsigned short int Film::getFrame(const FrameIndex& index) const { return frame[static_cast<size_t>(index)]; }

unsigned int Film::getDataRate(void) const { return dataRate; }

unsigned int Film::getTotalBitrate(void) const { return totalBitrate; }

long double Film::getCollection(void) const { return collection; }

long double Film::getBudget(void) const { return budget; }

std::vector<Choice> Film::getChoices(void) const { return choices; }

bool Film::setLength(const unsigned short int& second, const unsigned short int& minute, const unsigned short int& hour, const unsigned short int& day, const unsigned short int& month, const unsigned short int& year) { return Classifiable::setLength(std::tm{ second, minute, hour, day, month, year, 0, 0, 0 }); }

bool Film::setLength(const std::tm& length) { return Classifiable::setLength(length); }

void Film::setRegion(const std::string& region) {
	this->region = region.empty() ? "NA" : region;
	setChangeLog();
}

bool Film::setRelease(const unsigned short int& day, const unsigned short int& month, const unsigned short int& year, const unsigned short int& weekDay) { return setRelease(std::tm{ 0, 0, 0, day, month, year, weekDay, 0, 0 }); }

bool Film::setRelease(const std::tm& release) {
	const bool STATUS{ release.tm_mday >= 1 && release.tm_mday <= 31 && release.tm_mon >= 0 && release.tm_mon <= 11 && release.tm_year >= 0 && release.tm_wday >= 0 && release.tm_wday <= 6 };
	if (STATUS) {
		this->release = { 0, 0, 0, release.tm_mday, release.tm_mon, release.tm_year, release.tm_wday, 0, 0 };
		setChangeLog();
	}
	return STATUS;
}

bool Film::setFilmGenre(const FilmGenre::Value& filmGenre) {
	const bool STATUS{ filmGenre != FilmGenre::Value::NONE };
	if (STATUS) {
		this->filmGenre = *new FilmGenre(filmGenre);
		setChangeLog();
	}
	return STATUS;
}

bool Film::setClassification(const Classification::Value& classification) {
	const bool STATUS{ classification != Classification::Value::NONE };
	if (STATUS) {
		this->classification = *new Classification(classification);
		setChangeLog();
	}
	return STATUS;
}

bool Film::setSize(const float& size) {
	const bool STATUS{ size >= 0 };
	if (STATUS) {
		this->size = size;
		setChangeLog();
	}
	return STATUS;
}

bool Film::setFrameRate(const float& frameRate) {
	const bool STATUS{ frameRate >= 0 };
	if (STATUS) {
		this->frameRate = frameRate;
		setChangeLog();
	}
	return STATUS;
}

bool Film::setFrame(const FrameIndex& index, const unsigned short int& frame) {
	const bool STATUS{ frame >= 0 };
	if (STATUS) {
		this->frame[static_cast<size_t>(index)] = frame;
		setChangeLog();
	}
	return STATUS;
}

bool Film::setFrame(const unsigned short int& frameWidth, const unsigned short int& frameHeight) {
	bool status{ setFrame(Film::FrameIndex::WIDTH, frameWidth) };
	if (status) status = setFrame(Film::FrameIndex::HEIGHT, frameHeight);
	return status;
}

bool Film::setDataRate(const unsigned int& dataRate) {
	const bool STATUS{ dataRate >= 0 };
	if (STATUS) {
		this->dataRate = dataRate;
		setChangeLog();
	}
	return STATUS;
}

bool Film::setTotalBitrate(const unsigned int& totalBitrate) {
	const bool STATUS{ totalBitrate >= 0 };
	if (STATUS) {
		this->totalBitrate = totalBitrate;
		setChangeLog();
	}
	return STATUS;
}

bool Film::setCollection(const long double& collection) {
	const bool STATUS{ collection >= 0 };
	if (STATUS) {
		this->collection = collection;
		setChangeLog();
	}
	return STATUS;
}

bool Film::setBudget(const long double& budget) {
	const bool STATUS{ budget >= 0 };
	if (STATUS) {
		this->budget = budget;
		setChangeLog();
	}
	return STATUS;
}

void Film::setChoices(std::vector<Choice>* choices) {
	this->choices.clear();
	if (choices->size() > 0) {
		this->choices = *choices;
		this->choices.shrink_to_fit();
	}
	setRating(&this->choices);
}

bool Film::addChoice(Choice* choice) {
	for (size_t index = 0; index < choices.size(); ++index) {
		if (choice->getIdentificator().compare(choices[index].getIdentificator()) == 0) return false;
		if (choice->getUser().getIdentificator().compare(choices[index].getUser().getIdentificator()) == 0) {
			choices[index].setRating(choice->getRating().getValue());
			setRating(&choices);
			return true;
		}
	}
	choices.push_back(*choice);
	choices.shrink_to_fit();
	setRating(&choices);
	return true;
}

bool Film::deleteChoice(Choice* choice) {
	for (size_t index = 0; index < choices.size(); ++index) {
		if (choice->getIdentificator().compare(choices[index].getIdentificator()) == 0) {
			choices.erase(choices.begin() + index);
			choices.shrink_to_fit();
			setRating(&choices);
			return true;
		}
	}
	return false;
}