#pragma once
#include <string>
#include "Locatable.h"
#include "Country.h"

class Contactable : public virtual Locatable {
public:
	explicit Contactable(void) = default;
	Contactable(const Contactable& contactable) = default;
	~Contactable(void) = default;
	constexpr Contactable& operator=(const Contactable& contactable) = default;
	virtual Country Locatable::getCountry(void) const = 0;
	virtual bool Locatable::setCountry(const Country::Value& country) = 0;
	virtual std::string getEmail(void) const = 0;
	virtual std::string getWebsite(void) const = 0;
	virtual std::string getISP(void) const = 0;
	virtual std::string getPhoneNumber(void) const = 0;
	virtual std::string getCompletePhoneNumber(void) const = 0;
	virtual bool setEmail(const std::string& email) = 0;
	virtual bool setWebsite(const std::string& website) = 0;
	virtual bool setISP(const std::string& isp) = 0;
	virtual bool setPhoneNumber(const std::string& phoneNumber) = 0;
	virtual bool setPhoneNumber(const Country::Value& country, const std::string& isp, const std::string& phoneNumber) = 0;
};