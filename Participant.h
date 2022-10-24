#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "User.h"
#include "Cast.h"

class Participant final : public virtual User {
private:
	static unsigned long long int index;
	std::string participantIdentificator{ "NA" }, stageName{ "NA" }, description{ "NA" };
	std::tm debut{};
	std::vector<Cast> cast{};
protected:
	void setIdentificator(const std::string& prefix, const unsigned long long int& index) override;
public:
	explicit Participant(void) = delete;
	explicit Participant(const std::string& email, const std::string& isp, const std::string& phoneNumber, const std::string& username, const std::string& password, const std::tm& birthday, const std::string& name, const std::string& firstLastname, const std::string& secondLastName = "NA", const std::string& stageName = "NA", const std::tm& debut = {}, const std::string& description = "NA", std::vector<Cast::Value>* cast = new std::vector<Cast::Value>{}, const Country::Value & country = Country::Value::MEXICO, const Sex::Value & sex = Sex::Value::MALE, const std::string & website = "www.userblog.com");
	Participant(const Participant& participant) = default;
	~Participant(void) = default;
	constexpr Participant& operator=(const Participant& participant) = default;
	std::string getData(void) const override;
	std::string toString(void) const override;
	std::string getParticipantIdentificator(void) const;
	std::string getStageName(void) const;
	std::string getDescription(void) const;
	std::tm getDebut(void) const;
	std::string getDebutString(const Identifiable::TimeFormat& format = Identifiable::TimeFormat::DEFAULT) const;
	std::vector<Cast> getCast(void) const;
	void setStageName(const std::string& stageName);
	void setDescription(const std::string& description);
	bool setDebut(const unsigned short int& day, const unsigned short int& month, const unsigned short int& year, const unsigned short int& weekDay = 0);
	bool setDebut(const std::tm& debut);
	void setCast(std::vector<Cast::Value>* cast);
	bool addCast(const Cast::Value& cast);
	bool deleteCast(const Cast::Value& cast);
};