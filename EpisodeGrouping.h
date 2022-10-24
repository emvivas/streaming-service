#pragma once
#include <string>
#include <vector>
#include "Classifiable.h"
#include "Classification.h"
#include "FilmGenre.h"

class EpisodeGrouping : public virtual Classifiable {
private:
	std::tm *since{ nullptr }, *until{ nullptr };
	std::vector<Classification> classifications{};
	std::vector<FilmGenre> filmGenres{};
protected:
	void setSince(std::tm* since);
	void setUntil(std::tm* until);
public:
	explicit EpisodeGrouping(void) = delete;
	explicit EpisodeGrouping(const std::string& denomination, const std::string& slogan = "NA", const std::string& description = "NA");
	EpisodeGrouping(const EpisodeGrouping& episodeGrouping) = default;
	~EpisodeGrouping(void) = default;
	constexpr EpisodeGrouping& operator=(const EpisodeGrouping& episodeGrouping) = default;
	virtual std::string getData(void) const override;
	virtual std::string toString(void) const override;
	std::tm getSince(void) const;
	std::string getSinceString(const Identifiable::TimeFormat& format = Identifiable::TimeFormat::DETAILED_DATE) const;
	std::tm getUntil(void) const;
	std::string getUntilString(const Identifiable::TimeFormat& format = Identifiable::TimeFormat::DETAILED_DATE) const;
	std::vector<Classification> getClassifications(void) const;
	std::vector<FilmGenre> getFilmGenres(void) const;
	void setClassifications(std::vector<Classification::Value>* classifications);
	bool addClassification(const Classification::Value& classification);
	bool deleteClassification(const Classification::Value& classification);
	void setFilmGenres(std::vector<FilmGenre::Value>* filmGenres);
	bool addFilmGenre(const FilmGenre::Value& filmGenre);
	bool deleteFilmGenre(const FilmGenre::Value& filmGenre);
};