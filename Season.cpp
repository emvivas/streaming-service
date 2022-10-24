#include "Season.h"

unsigned long long int Season::index = 0;

Season::Season(const size_t& number, const std::string& denomination, std::vector<Film>* episodes, const std::string& slogan, const std::string& description) : EpisodeGrouping::EpisodeGrouping(denomination, slogan, description), Classifiable::Classifiable(denomination, slogan, description) {
	setIdentificator("SN", ++index);
	setNumber(number);
	setEpisodes(episodes);
}

std::string Season::getData(void) const { return "<Temporada>\n- Identificador: " + getIdentificator() + "\n- Fecha de creación: " + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG, Identifiable::TimeFormat::BRIEF) + "\n- Fecha de modificación: " + getRegistrationString(Identifiable::RegistrationIndex::CHANGE_LOG, Identifiable::TimeFormat::BRIEF); }

std::string Season::toString(void) const { return "<Temporada> " + getIdentificator() + " (" + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG) + ')'; }

size_t Season::getNumber(void) const { return number; }

std::vector<Film> Season::getEpisodes(void) const { return episodes; }

bool Season::setNumber(const size_t& number) {
	const bool STATUS{ number >= 0 };
	if (STATUS) {
		this->number = number;
		setChangeLog();
	}
	return STATUS;
}

void Season::setEpisodes(std::vector<Film>* episodes) {
	this->episodes.clear();
	if (episodes->size() > 0) {
		this->episodes = *episodes;
		this->episodes.shrink_to_fit();
		setChangeLog();
	}
}

bool Season::addEpisode(Film* episode) {
	for (const Film& value : episodes)
		if (episode->getIdentificator().compare(value.getIdentificator()) == 0) return false;
	episodes.push_back(*episode);
	episodes.shrink_to_fit();
	setChangeLog();
	return true;
}

bool Season::deleteEpisode(Film* episode) {
	for (size_t index = 0; index < episodes.size(); ++index) {
		if (episode->getIdentificator().compare(episodes[index].getIdentificator()) == 0) {
			episodes.erase(episodes.begin() + index);
			episodes.shrink_to_fit();
			setChangeLog();
			return true;
		}
	}
	return false;
}