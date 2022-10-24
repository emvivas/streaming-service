#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "Identifiable.h"
#include "Language.h"
#include "Rating.h"
#include "Participant.h"
#include "Choice.h"

class Classifiable : public virtual Identifiable {
private:
	float meanRating{ 0.0f };
	std::string denomination{ "NA" }, slogan{ "NA" }, description{ "NA" };
	std::tm length{};
	Rating rating{};
	std::vector<Language> languages{};
	std::vector<Participant> participants{};
protected:
	void setRating(std::vector<Choice>* choices);
	bool setLength(const unsigned short int& second = 0u, const unsigned short int& minute = 0u, const unsigned short int& hour = 0u, const unsigned short int& day = 0u, const unsigned short int& month = 0u, const unsigned short int& year = 0u);
	bool setLength(const std::tm& length);
public:
	explicit Classifiable(void) = delete;
	explicit Classifiable(const std::string& denomination, const std::string& slogan = "NA", const std::string& description = "NA", std::vector<Language::Value>* languages = new std::vector<Language::Value>{}, std::vector<Participant>* participants = new std::vector<Participant>{});
	Classifiable(const Classifiable& classifiable) = default;
	~Classifiable(void) = default;
	constexpr Classifiable& operator=(const Classifiable& classifiable) = default;
	virtual std::string getData(void) const override;
	virtual std::string toString(void) const override;
	std::string getDenomination(void) const;
	std::string getSlogan(void) const;
	std::string getTitle(void) const;
	std::string getDescription(void) const;
	std::vector<Language> getLanguages(void) const;
	Rating getRating(void) const;
	float getMeanRating(void) const;
	std::tm getLength(void) const;
	std::string getLengthString(void) const;
	std::vector<Participant> getParticipants(void) const;
	bool setDenomination(const std::string& denomination);
	void setSlogan(const std::string& slogan);
	bool setDescription(const std::string& description);
	void setLanguages(std::vector<Language::Value>* languages);
	bool addLanguage(const Language::Value& language);
	bool deleteLanguage(const Language::Value& language);
	void setParticipants(std::vector<Participant>* participants);
	bool addParticipant(Participant* participant);
	bool deleteParticipant(Participant* participant);
};