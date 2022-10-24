#include "EpisodeGrouping.h"

EpisodeGrouping::EpisodeGrouping(const std::string& denomination, const std::string& slogan, const std::string& description) : Classifiable::Classifiable(denomination, slogan, description) {}

std::string EpisodeGrouping::getData(void) const { return "<Agrupamiento de episodios>\n- Identificador: " + getIdentificator() + "\n- Fecha de creación: " + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG, Identifiable::TimeFormat::BRIEF) + "\n- Fecha de modificación: " + getRegistrationString(Identifiable::RegistrationIndex::CHANGE_LOG, Identifiable::TimeFormat::BRIEF); }

std::string EpisodeGrouping::toString(void) const { return "<Agrupamiento de episodios> " + getIdentificator() + " (" + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG) + ')'; }

void EpisodeGrouping::setSince(std::tm* since) { 
	this->since = since;
	setChangeLog();
}

void EpisodeGrouping::setUntil(std::tm* until) {
	this->until = until;
	setChangeLog();
}

std::tm EpisodeGrouping::getSince(void) const { return *since; }

std::string EpisodeGrouping::getSinceString(const Identifiable::TimeFormat& format) const { return Identifiable::getTimeString(*since, format); }

std::tm EpisodeGrouping::getUntil(void) const { return *until; }

std::string EpisodeGrouping::getUntilString(const Identifiable::TimeFormat& format) const { return Identifiable::getTimeString(*until, format); }

std::vector<Classification> EpisodeGrouping::getClassifications(void) const { return classifications; }

std::vector<FilmGenre> EpisodeGrouping::getFilmGenres(void) const { return filmGenres; }

void EpisodeGrouping::setClassifications(std::vector<Classification::Value>* classifications) {
	this->classifications.clear();
	if (classifications->size() > 0) {
		std::sort(classifications->begin(), classifications->end());
		auto last = std::unique(classifications->begin(), classifications->end());
		classifications->erase(last, classifications->end());
		if (*classifications->begin() == Classification::Value::NONE) classifications->erase(classifications->begin());
		for (const Classification::Value& value : *classifications) this->classifications.push_back(*new Classification(value));
		this->classifications.shrink_to_fit();
		setChangeLog();
	}
}

bool EpisodeGrouping::addClassification(const Classification::Value& classification) {
	if (classification != Classification::Value::NONE) {
		for (const Classification& value : classifications)
			if (classification == value.getValue()) return false;
		classifications.push_back(*new Classification(classification));
		classifications.shrink_to_fit();
		setChangeLog();
		return true;
	}
	else return false;
}

bool EpisodeGrouping::deleteClassification(const Classification::Value& classification) {
	if (classification != Classification::Value::NONE) {
		for (size_t index = 0; index < classifications.size(); ++index) {
			if (classification == classifications[index].getValue()) {
				classifications.erase(classifications.begin() + index);
				classifications.shrink_to_fit();
				setChangeLog();
				return true;
			}
		}
	}
	return false;
}

void EpisodeGrouping::setFilmGenres(std::vector<FilmGenre::Value>* filmGenres) {
	this->filmGenres.clear();
	if (filmGenres->size() > 0) {
		std::sort(filmGenres->begin(), filmGenres->end());
		auto last = std::unique(filmGenres->begin(), filmGenres->end());
		filmGenres->erase(last, filmGenres->end());
		if (*filmGenres->begin() == FilmGenre::Value::NONE) filmGenres->erase(filmGenres->begin());
		for (const FilmGenre::Value& value : *filmGenres) this->filmGenres.push_back(*new FilmGenre(value));
		this->classifications.shrink_to_fit();
		setChangeLog();
	}
}

bool EpisodeGrouping::addFilmGenre(const FilmGenre::Value& filmGenre) {
	if (filmGenre != FilmGenre::Value::NONE) {
		for (const FilmGenre& value : filmGenres)
			if (filmGenre == value.getValue()) return false;
		filmGenres.push_back(*new FilmGenre(filmGenre));
		filmGenres.shrink_to_fit();
		setChangeLog();
		return true;
	} else return false;
}

bool EpisodeGrouping::deleteFilmGenre(const FilmGenre::Value& filmGenre) {
	if (filmGenre != FilmGenre::Value::NONE) {
		for (size_t index = 0; index < filmGenres.size(); ++index) {
			if (filmGenre == filmGenres[index].getValue()) {
				filmGenres.erase(filmGenres.begin() + index);
				filmGenres.shrink_to_fit();
				setChangeLog();
				return true;
			}
		}
	}
	return false;
}