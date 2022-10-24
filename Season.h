#pragma once
#include <vector>
#include "EpisodeGrouping.h"
#include "Film.h"

class Season final : public virtual EpisodeGrouping {
private:
	static unsigned long long int index;
	size_t number{ 0u };
	std::vector<Film> episodes{};
public:
	explicit Season(void) = delete;
	explicit Season(const size_t& number, const std::string& denomination = "NA", std::vector<Film>* episodes = new std::vector<Film>{}, const std::string& slogan = "NA", const std::string& description = "NA");
	Season(const Season& season) = default;
	~Season(void) = default;
	constexpr Season& operator=(const Season& season) = default;
	std::string getData(void) const override;
	std::string toString(void) const override;
	size_t getNumber(void) const;
	std::vector<Film> getEpisodes(void) const;
	bool setNumber(const size_t& number);
	void setEpisodes(std::vector<Film>* episodes);
	bool addEpisode(Film* episode);
	bool deleteEpisode(Film* episode);
};