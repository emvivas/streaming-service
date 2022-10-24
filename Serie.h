#pragma once
#include <string>
#include <vector>
#include <deque>
#include "EpisodeGrouping.h"
#include "Season.h"

class Serie final : public virtual EpisodeGrouping {
private:
	static std::deque<Serie> series;
	static unsigned long long int index;
	std::vector<Season> seasons;
public:
	static std::deque<Serie> getSeries(void);
	explicit Serie(void) = delete;
	explicit Serie(const std::string& denomination, std::vector<Season>& seasons = *new std::vector<Season>{}, const std::string & slogan = "NA", const std::string & description = "NA");
	Serie(const Serie& serie) = default;
	~Serie(void) = default;
	constexpr Serie& operator=(const Serie& serie) = default;
	std::string getData(void) const override;
	std::string toString(void) const override;
	std::vector<Season> getSeasons(void) const;
	void setSeasons(std::vector<Season>& seasons);
	bool addSeason(Season* season);
	bool deleteSeason(Season* season);
};