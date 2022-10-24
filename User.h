#pragma once
#include <string>
#include <ctime>
#include <deque>
#include "Identifiable.h"
#include "Contactable.h"
#include "Sex.h"
#include "Country.h"
#define NAME_INDEX_NUMBER 3

class User : public virtual Identifiable, public virtual Contactable {
private:
	static User const* ADMINISTRATOR;
	static std::deque<User> users;
	static unsigned long long int index;
	std::string email{ "user@userblog.com" }, website{ "www.userblog.com" }, isp{ "55" }, phoneNumber{ "5555555" }, username{ "username" }, name[NAME_INDEX_NUMBER]{ "NA", "NA", "NA" }, password{ "\u0000" };
	std::tm birthday{};
	Country country{};
	Sex sex{};
protected:
	Sex const* getSexReference(void) const;
public:
	static std::deque<User> getUsers(void);
	static User* authenticate(const std::string& identificator, const std::string& password);
	enum class NameIndex : size_t { NAME, FIRST_LASTNAME, SECOND_LASTNAME };
	explicit User(void) = delete;
	explicit User(const std::string& email, const std::string& isp, const std::string& phoneNumber, const std::string& username, const std::string& password, const std::tm& birthday, const std::string& name, const std::string& firstLastname, const std::string& secondLastName = "NA", const Country::Value& country = Country::Value::NONE, const Sex::Value& sex = Sex::Value::NONE, const std::string& website = "www.userblog.com");
	User(const User& user) = default;
	~User(void) = default;
	constexpr User& operator=(const User& user) = default;
	virtual std::string getData(void) const override;
	virtual std::string toString(void) const override;
	Country getCountry(void) const override;
	bool setCountry(const Country::Value& country) override;
	std::string getEmail(void) const override;
	std::string getWebsite(void) const override;
	std::string getISP(void) const override;
	std::string getPhoneNumber(void) const override;
	std::string getCompletePhoneNumber(void) const override;
	bool setEmail(const std::string& email) override;
	bool setWebsite(const std::string& website) override;
	bool setISP(const std::string& ips) override;
	bool setPhoneNumber(const std::string& phoneNumber) override;
	bool setPhoneNumber(const Country::Value& country, const std::string& isp, const std::string& phoneNumber) override;
	std::string getUsername(void) const;
	std::string getName(void) const;
	std::string getName(const NameIndex& index) const;
	Sex getSex(void) const;
	std::tm getBirthday(void) const;
	std::string getBirthdayString(const Identifiable::TimeFormat& format = Identifiable::TimeFormat::DEFAULT) const;
	bool setUsername(const std::string& username);
	bool setName(const std::string name[3]);
	bool setName(const std::string& name, const std::string& firstLastname, const std::string& secondLastname = "Segundo apellido");
	bool setName(const std::string& name, const NameIndex& index = NameIndex::NAME);
	bool setSex(const Sex::Value& sex);
	bool setBirthday(const unsigned short int& day, const unsigned short int& month, const unsigned short int& year, const unsigned short int& weekDay = 0);
	bool setBirthday(const std::tm& birthday);
	bool setPassword(const std::string& newPassword, const std::string& password = "\u0000");
	bool authenticate(const std::string& password);
	bool authenticate(void);
};