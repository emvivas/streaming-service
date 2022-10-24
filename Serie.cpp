#include "Serie.h"

std::deque<Serie> Serie::series{};

unsigned long long int Serie::index = 0;

Serie::Serie(const std::string& denomination, std::vector<Season>& seasons, const std::string& slogan, const std::string& description) : EpisodeGrouping::EpisodeGrouping(denomination, slogan, description), Classifiable::Classifiable(denomination, slogan, description) {
	setIdentificator("SE", ++index);
	setSeasons(seasons);
	series.push_back(*this);
	series.shrink_to_fit();
}

std::deque<Serie> Serie::getSeries(void) { return series; }

std::string Serie::getData(void) const { return "<Serie>\n- Identificador: " + getIdentificator() + "\n- Fecha de creación: " + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG, Identifiable::TimeFormat::BRIEF) + "\n- Fecha de modificación: " + getRegistrationString(Identifiable::RegistrationIndex::CHANGE_LOG, Identifiable::TimeFormat::BRIEF); }

std::string Serie::toString(void) const { return "<Serie> " + getIdentificator() + " (" + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG) + ')'; }

std::vector<Season> Serie::getSeasons(void) const { return seasons; }

void Serie::setSeasons(std::vector<Season>& seasons) {
	this->seasons.clear();
	if (seasons.size() > 0) {
		this->seasons = seasons;
		this->seasons.shrink_to_fit();
		setChangeLog();
	}
}

bool Serie::addSeason(Season* season) {
	for (const Season& value : seasons)
		if (season->getIdentificator().compare(value.getIdentificator()) == 0) return false;
	seasons.push_back(*season);
	seasons.shrink_to_fit();
	setChangeLog();
	return true;
}

bool Serie::deleteSeason(Season* season) {
	for (size_t index = 0; index < seasons.size(); ++index) {
		if (season->getIdentificator().compare(seasons[index].getIdentificator()) == 0) {
			seasons.erase(seasons.begin() + index);
			seasons.shrink_to_fit();
			setChangeLog();
			return true;
		}
	}
	return false;
}