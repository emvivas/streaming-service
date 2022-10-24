#pragma once
#include <string>
#include "Classifiable.h"
#include "Contactable.h"
#include "User.h"
#include "Film.h"
#include "Serie.h"

class Streaming final : public virtual Classifiable, public virtual Contactable {
private:
	static unsigned long long int index;
	std::string email{ "user@userblog.com" }, website{ "www.userblog.com" }, isp{ "55" }, phoneNumber{ "5555555" };
	Country country{};
	User* administrator{ nullptr };
	std::vector<Film> movies{};
	std::vector<Serie> series{};
	std::vector<Streaming> agreement{};
public:
	explicit Streaming(void) = delete;
	explicit Streaming(const std::string& denomination, const std::string& email, User* administrator, const std::string& isp, const std::string& phoneNumber, const Country::Value& country = Country::Value::MEXICO, const std::string& slogan = "NA", const std::string& description = "NA", const std::string& website = "www.userblog.com", std::vector<Film>* movies = new std::vector<Film>{}, std::vector<Serie>* series = new std::vector<Serie>{}, std::vector<Streaming>* agreement = new std::vector<Streaming>{});
	Streaming(const Streaming& streaming) = default;
	~Streaming(void) = default;
	constexpr Streaming& operator=(const Streaming& streaming) = default;
	std::string getData(void) const override;
	std::string toString(void) const override;
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
	User getAdministrator(void) const;
	std::vector<Film> getMovies(void) const;
	std::vector<Serie> getSeries(void) const;
	std::vector<Streaming> getAgreement(void) const;
	void setAdministrator(User* administrator);
	void setMovies(std::vector<Film>* movies);
	bool addMovie(Film* movie);
	bool deleteMovie(Film* movie);
	void setSeries(std::vector<Serie>* series);
	bool addSerie(Serie* serie);
	bool deleteSerie(Serie* serie);
	void setAgreement(std::vector<Streaming>* agreement);
	bool addAgreement(Streaming* agreement);
	bool deleteAgreement(Streaming* agreement);
};