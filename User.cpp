#include "User.h"

std::deque<User> User::users{ *new User("a01424732@tec.mx", "777", "5317577", "emvivas", "321", tm{ 0, 0, 0, 10, 10, 101 }, "Emiliano", "Vivas", "Rodríguez", Country::Value::MEXICO, Sex::Value::MALE, "www.linkedin.com/in/vivasrguez") };

User const * User::ADMINISTRATOR{ &users[0] };

unsigned long long int User::index = 0;

User::User(const std::string& email, const std::string& isp, const std::string& phoneNumber, const std::string& username, const std::string& password, const std::tm& birthday, const std::string& name, const std::string& firstLastname, const std::string& secondLastName, const Country::Value& country, const Sex::Value& sex, const std::string& website) {
	setIdentificator("U", ++index);
	setEmail(email);
	setWebsite(website);
	setISP(isp);
	setPhoneNumber(phoneNumber);
	setUsername(username);
	setName(name, firstLastname, secondLastName);
	setPassword(password);
	setBirthday(birthday);
	setCountry(country);
	setSex(sex);
	users.push_back(*this);
	users.shrink_to_fit();
}

std::deque<User> User::getUsers(void) { return users; }

User* User::authenticate(const std::string& identificator, const std::string& password) {
	for (User& user : users) {
		if (user.getIdentificator().compare(identificator) == 0 && user.password.compare(password) == 0) {
			return &user;
		}
	}
	return nullptr;
}

std::string User::getData(void) const { return "<Usuario>\n- Identificador: " + getIdentificator() + "\n- Fecha de creación: " + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG, Identifiable::TimeFormat::BRIEF) + "\n- Fecha de modificación: " + getRegistrationString(Identifiable::RegistrationIndex::CHANGE_LOG, Identifiable::TimeFormat::BRIEF); }

std::string User::toString(void) const { return "<Usuario> " + getIdentificator() + " (" + getRegistrationString(Identifiable::RegistrationIndex::CREATION_LOG) + ')'; }

Sex const* User::getSexReference(void) const { return &sex; }

Country User::getCountry(void) const { return country; }

bool User::setCountry(const Country::Value& country) {
	const bool STATUS{ country != Country::Value::NONE };
	if (STATUS) {
		this->country = *new Country(country);
		setChangeLog();
	}
	return STATUS;
}

std::string User::getEmail(void) const { return email; }

std::string User::getWebsite(void) const { return website; }

std::string User::getISP(void) const { return isp; }

std::string User::getPhoneNumber(void) const { return phoneNumber; }

std::string User::getCompletePhoneNumber(void) const { return '+' + std::to_string(country.getAreaCode()) + " (" + getISP() + ") " + getPhoneNumber(); }

bool User::setEmail(const std::string& email) {
	const bool STATUS{ email.length() >= 5 && std::count(email.begin(), email.end(), '@') == 1 && std::count(email.begin(), email.end(), '.') > 0 };
	if (STATUS) {
		this->email = email;
		setChangeLog();
	}
	return STATUS;
}

bool User::setWebsite(const std::string& website) {
	const bool STATUS{ website.length() >= 5 && std::count(website.begin(), website.end(), '.') > 1 };
	if (STATUS) {
		this->website = website;
		setChangeLog();
	}
	return STATUS;
}

bool User::setISP(const std::string& isp) {
	const bool STATUS{ isp.length() > 0 && isp.length() <= 3 };
	if (STATUS) {
		this->isp = isp;
		setChangeLog();
	}
	return STATUS;
}

bool User::setPhoneNumber(const std::string& phoneNumber) {
	const bool STATUS{ phoneNumber.length() == 7 };
	if (STATUS) {
		this->phoneNumber = phoneNumber;
		setChangeLog();
	}
	return STATUS;
}

bool User::setPhoneNumber(const Country::Value& country, const std::string& isp, const std::string& phoneNumber){
	bool status{ setCountry(country) };
	if (status) status = setISP(isp);
	if (status) status = setPhoneNumber(phoneNumber);
	return status;
}

std::string User::getUsername(void) const { return username; }

std::string User::getName(void) const { return getName(User::NameIndex::NAME) + ' ' + getName(User::NameIndex::FIRST_LASTNAME) + ' ' + getName(User::NameIndex::SECOND_LASTNAME); }

std::string User::getName(const User::NameIndex& index) const { return name[static_cast<size_t>(index)]; }

Sex User::getSex(void) const { return sex; }

std::tm User::getBirthday(void) const { return birthday; }

std::string User::getBirthdayString(const Identifiable::TimeFormat& format) const { return Identifiable::getTimeString(birthday, format); }

bool User::setUsername(const std::string& username) {
	const bool STATUS{ !username.empty() };
	if (STATUS) {
		this->username = username;
		setChangeLog();
	}
	return STATUS;
}

bool User::setName(const std::string name[3]) { return setName(name[0], name[1], name[2]); }

bool User::setName(const std::string& name, const std::string& firstLastname, const std::string& secondLastname) {
	bool status{ setName(name, User::NameIndex::NAME) };
	if (status) status = setName(firstLastname, User::NameIndex::FIRST_LASTNAME);
	if (status) status = setName(secondLastname, User::NameIndex::SECOND_LASTNAME);
	return status;
}

bool User::setName(const std::string& name, const User::NameIndex& index) {
	const bool STATUS{ !name.empty() };
	if (STATUS) {
		this->name[static_cast<size_t>(index)] = name;
		setChangeLog();
	}
	return STATUS;
}

bool User::setSex(const Sex::Value& sex) {
	const bool STATUS{ sex != Sex::Value::NONE };
	if (STATUS) {
		this->sex = *new Sex(sex);
		setChangeLog();
	}
	return STATUS;
}

bool User::setBirthday(const unsigned short int& day, const unsigned short int& month, const unsigned short int& year, const unsigned short int& weekDay) { return setBirthday(std::tm{ 0, 0, 0, day, month, year, weekDay, 0, 0}); }

bool User::setBirthday(const std::tm& birthday) {
	const bool STATUS{ birthday.tm_mday >= 1 && birthday.tm_mday <= 31 && birthday.tm_mon >= 0 && birthday.tm_mon <= 11 && birthday.tm_year >= 0 && birthday.tm_wday >=0 && birthday.tm_wday <= 6 };
	if (STATUS) {
		this->birthday = { 0, 0, 0, birthday.tm_mday, birthday.tm_mon, birthday.tm_year, birthday.tm_wday, 0, 0 };
		setChangeLog();
	}
	return STATUS;
}

bool User::setPassword(const std::string& newPassword, const std::string& password) {
	const bool STATUS{ authenticate(password) };
	if (STATUS) {
		this->password = newPassword;
		setChangeLog();
	}
	return STATUS;
}

bool User::authenticate(const std::string& password) { return this->password.compare(password) == 0; }

bool User::authenticate(void) { return getIdentificator().compare(User::ADMINISTRATOR->getIdentificator()) == 0; }