#pragma once
#include <ostream>
#include <string>
#include <ctime>
#define REGISTRATION_INDEX_NUMBER 2
#define FORMATTED_TEXT_INDEX_LIMIT 75

class Identifiable {
private:
	std::string identificator{ "NA" };
	std::tm registration[REGISTRATION_INDEX_NUMBER]{};
	void setChangeLog(const std::time_t& currentTime);
protected:
	virtual void setIdentificator(const std::string& prefix, const unsigned long long int& index);
	void setChangeLog(void);
public:
	enum class RegistrationIndex : size_t { CREATION_LOG, CHANGE_LOG };
	enum class TimeFormat : unsigned short int { DEFAULT, DETAILED, BRIEF, DETAILED_DATE, BRIEF_DATE, DETAILED_HOUR, BRIEF_HOUR, REGISTRATION, LENGTH };
	static std::string getTimeString(const std::tm& time, const TimeFormat& format = TimeFormat::DEFAULT);
	explicit Identifiable(void);
	Identifiable(const Identifiable& identifiable) = default;
	~Identifiable(void) = default;
	constexpr Identifiable& operator=(const Identifiable& identifiable) = default;
	std::string getIdentificator(void) const;
	std::tm getRegistration(const RegistrationIndex& index) const;
	std::string getRegistrationString(const RegistrationIndex& index, const TimeFormat& format = TimeFormat::DEFAULT) const;
	virtual std::string getData(void) const;
	virtual std::string toString(void) const;
	friend std::ostream& operator<<(std::ostream& out, const Identifiable& identifiable);
};