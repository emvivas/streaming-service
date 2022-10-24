#include "Streaming.h"

unsigned long long int Streaming::index = 0;

Streaming::Streaming(const std::string& denomination, const std::string& email, User* administrator, const std::string& isp, const std::string& phoneNumber, const Country::Value& country, const std::string& slogan, const std::string& description, const std::string& website, std::vector<Film>* movies, std::vector<Serie>* series, std::vector<Streaming>* agreement) : Classifiable::Classifiable(denomination, slogan, description) {
	setIdentificator("S", ++index);
	setAdministrator(administrator);
	setEmail(email);
	setWebsite(website);
	setISP(isp);
	setPhoneNumber(phoneNumber);
	setCountry(country);
	setMovies(movies);
	setSeries(series);
	setAgreement(agreement);
}

std::string Streaming::getData(void) const { return "<Streaming>\n- Identificador: " + getIdentificator() + "\n- Fecha de creación: " + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG, Identifiable::TimeFormat::BRIEF) + "\n- Fecha de modificación: " + getRegistrationString(Identifiable::RegistrationIndex::CHANGE_LOG, Identifiable::TimeFormat::BRIEF); }

std::string Streaming::toString(void) const { return "<Streaming> " + getIdentificator() + " (" + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG) + ')'; }

Country Streaming::getCountry(void) const { return country; }

bool Streaming::setCountry(const Country::Value& country) {
	const bool STATUS{ country != Country::Value::NONE };
	if (STATUS) {
		this->country = *new Country(country);
		setChangeLog();
	}
	return STATUS;
}

std::string Streaming::getEmail(void) const { return email; }

std::string Streaming::getWebsite(void) const { return website; }

std::string Streaming::getISP(void) const { return isp; }

std::string Streaming::getPhoneNumber(void) const { return phoneNumber; }

std::string Streaming::getCompletePhoneNumber(void) const { return '+' + std::to_string(country.getAreaCode()) + " (" + getISP() + ") " + getPhoneNumber(); }

bool Streaming::setEmail(const std::string& email) {
	const bool STATUS{ email.length() >= 5 && std::count(email.begin(), email.end(), '@') == 1 && std::count(email.begin(), email.end(), '.') > 0 };
	if (STATUS) {
		this->email = email;
		setChangeLog();
	}
	return STATUS;
}

bool Streaming::setWebsite(const std::string& website) {
	const bool STATUS{ website.length() >= 5 && std::count(website.begin(), website.end(), '.') > 1 };
	if (STATUS) {
		this->website = website;
		setChangeLog();
	}
	return STATUS;
}

bool Streaming::setISP(const std::string& isp) {
	const bool STATUS{ isp.length() > 0 && isp.length() <= 3 };
	if (STATUS) {
		this->isp = isp;
		setChangeLog();
	}
	return STATUS;
}

bool Streaming::setPhoneNumber(const std::string& phoneNumber) {
	const bool STATUS{ phoneNumber.length() == 7 };
	if (STATUS) {
		this->phoneNumber = phoneNumber;
		setChangeLog();
	}
	return STATUS;
}

bool Streaming::setPhoneNumber(const Country::Value& country, const std::string& isp, const std::string& phoneNumber) {
	bool status{ setCountry(country) };
	if (status) status = setISP(isp);
	if (status) status = setPhoneNumber(phoneNumber);
	return status;
}

User Streaming::getAdministrator(void) const { return *administrator; }

std::vector<Film> Streaming::getMovies(void) const { return movies; }

std::vector<Serie> Streaming::getSeries(void) const { return series; }

std::vector<Streaming> Streaming::getAgreement(void) const { return agreement; }

void Streaming::setAdministrator(User* administrator) {
	this->administrator = administrator;
	setChangeLog();
}

void Streaming::setMovies(std::vector<Film>* movies) {
	this->movies.clear();
	if (movies->size() > 0) {
		this->movies = *movies;
		this->movies.shrink_to_fit();
		setChangeLog();
	}
}

bool Streaming::addMovie(Film* movie) {
	for (const Film& value : movies)
		if (movie->getIdentificator().compare(value.getIdentificator()) == 0) return false;
	movies.push_back(*movie);
	movies.shrink_to_fit();
	setChangeLog();
	return true;
}

bool Streaming::deleteMovie(Film* movie) {
	for (size_t index = 0; index < movies.size(); ++index) {
		if (movie->getIdentificator().compare(movies[index].getIdentificator()) == 0) {
			movies.erase(movies.begin() + index);
			movies.shrink_to_fit();
			setChangeLog();
			return true;
		}
	}
	return false;
}

void Streaming::setSeries(std::vector<Serie>* series) {
	this->series.clear();
	if (series->size() > 0) {
		this->series = *series;
		this->series.shrink_to_fit();
		setChangeLog();
	}
}

bool Streaming::addSerie(Serie* serie) {
	for (const Serie& value : series)
		if (serie->getIdentificator().compare(value.getIdentificator()) == 0) return false;
	series.push_back(*serie);
	series.shrink_to_fit();
	setChangeLog();
	return true;
}

bool Streaming::deleteSerie(Serie* serie) {
	for (size_t index = 0; index < series.size(); ++index) {
		if (serie->getIdentificator().compare(series[index].getIdentificator()) == 0) {
			series.erase(series.begin() + index);
			series.shrink_to_fit();
			setChangeLog();
			return true;
		}
	}
	return false;
}

void Streaming::setAgreement(std::vector<Streaming>* agreement) {
	this->agreement.clear();
	if (agreement->size() > 0) {
		this->agreement = *agreement;
		this->agreement.shrink_to_fit();
		setChangeLog();
	}
}

bool Streaming::addAgreement(Streaming* agreement) {
	for (const Streaming& value : this->agreement)
		if (agreement->getIdentificator().compare(value.getIdentificator()) == 0) return false;
	this->agreement.push_back(*agreement);
	this->agreement.shrink_to_fit();
	setChangeLog();
	return true;
}

bool Streaming::deleteAgreement(Streaming* agreement) {
	for (size_t index = 0; index < this->agreement.size(); ++index) {
		if (agreement->getIdentificator().compare(this->agreement[index].getIdentificator()) == 0) {
			this->agreement.erase(this->agreement.begin() + index);
			this->agreement.shrink_to_fit();
			setChangeLog();
			return true;
		}
	}
	return false;
}