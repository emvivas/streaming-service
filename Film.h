#pragma once
#include <string>
#include <vector>
#include <deque>
#include <iomanip>
#include <sstream>
#include "Classifiable.h"
#include "Locatable.h"
#include "Choice.h"
#include "Country.h"
#include "Classification.h"
#include "FilmGenre.h"
#define FRAME_INDEX_NUMBER 2

class Film final : public virtual Classifiable, public virtual Locatable {
private:
	static std::deque<Film> films;
	static unsigned long long int index;
	unsigned short int frame[FRAME_INDEX_NUMBER]{ 0u, 0u };
	unsigned int dataRate{ 0u }, totalBitrate{ 0u };
	float size{ 0.0f }, frameRate { 0.0f };
	long double collection { 0.0l }, budget { 0.0l };
	std::string region{ "NA" };
	std::tm release{};
	Country country{};
	Classification classification{};
	FilmGenre filmGenre{};
	std::vector<Choice> choices{};
public:
	static std::deque<Film> getFilms(void);
	static Film* getFilm(const size_t& index);
	static Film* getRegister(const std::vector<std::string>& data);
	enum class FrameIndex : size_t { WIDTH, HEIGHT };
	explicit Film(void) = delete;
	explicit Film(const std::string& denomination, const std::tm& length, const std::tm& release, const FilmGenre::Value& filmGenre = FilmGenre::Value::NONE, const Classification::Value& classification = Classification::Value::NONE, const Country::Value& country = Country::Value::NONE, const std::string& region = "NA", const std::string& slogan = "NA", const std::string& description = "NA", const long double& collection = 0.0l, const long double& budget = 0.0l, std::vector<Language::Value>* languages = new std::vector<Language::Value>{}, std::vector<Participant>* participants = new std::vector<Participant>{}, std::vector<Choice>* choices = new std::vector<Choice>{}, const float& size = 0.0f, const float& frameRate = 0.0f, const unsigned int& dataRate = 0u, const unsigned int& toltalBitrate = 0u, const unsigned short int& frameWidth = 0u, const unsigned short int& frameHeight = 0u);
	Film(const Film& film) = default;
	~Film(void) = default;
	constexpr Film& operator=(const Film& film) = default;
	std::string getData(void) const override;
	std::string toString(void) const override;
	Country getCountry(void) const override;
	bool setCountry(const Country::Value& country) override;
	std::string getRegion(void) const;
	std::string getLocation(void) const;
	std::tm getRelease(void) const;
	std::string getReleaseString(const Identifiable::TimeFormat& format = Identifiable::TimeFormat::DETAILED_DATE) const;
	FilmGenre getFilmGenre(void) const;
	Classification getClassification(void) const;
	float getSize(void) const;
	float getFrameRate(void) const;
	unsigned short int getFrame(const FrameIndex& index) const;
	unsigned int getDataRate(void) const;
	unsigned int getTotalBitrate(void) const;
	long double getCollection(void) const;
	long double getBudget(void) const;
	std::vector<Choice> getChoices(void) const;
	bool setLength(const unsigned short int& second = 0u, const unsigned short int& minute = 0u, const unsigned short int& hour = 0u, const unsigned short int& day = 0u, const unsigned short int& month = 0u, const unsigned short int& year = 0u);
	bool setLength(const std::tm& length);
	void setRegion(const std::string& region);
	bool setRelease(const unsigned short int& day, const unsigned short int& month, const unsigned short int& year, const unsigned short int& weekDay = 0);
	bool setRelease(const std::tm& release);
	bool setFilmGenre(const FilmGenre::Value& filmGenre);
	bool setClassification(const Classification::Value& classification);
	bool setSize(const float& size);
	bool setFrameRate(const float& frameRate);
	bool setFrame(const FrameIndex& index, const unsigned short int& frame);
	bool setFrame(const unsigned short int& frameWidth, const unsigned short int& frameHeight);
	bool setDataRate(const unsigned int& dataRate);
	bool setTotalBitrate(const unsigned int& totalBitrate);
	bool setCollection(const long double& collection);
	bool setBudget(const long double& budget);
	void setChoices(std::vector<Choice>* choices);
	bool addChoice(Choice* choice);
	bool deleteChoice(Choice* choice);
};