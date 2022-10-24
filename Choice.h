#pragma once
#include <string>
#include "Identifiable.h"
#include "User.h"
#include "Rating.h"

class Choice final : public virtual Identifiable {
private:
	static unsigned long long int index;
	std::string comments{ "NA" };
	User* user{ nullptr };
	Rating rating{};
public:
	explicit Choice(void) = delete;
	explicit Choice(User* user, const Rating::Value& rating = Rating::Value::NONE, const std::string& comments = "NA");
	Choice(const Choice& choice) = default;
	~Choice(void) = default;
	constexpr Choice& operator=(const Choice& choice) = default;
	std::string getData(void) const override;
	std::string toString(void) const override;
	std::string getComments(void) const;
	User getUser(void) const;
	Rating getRating(void) const;
	void setComments(const std::string& comments);
	void setRating(const Rating::Value& rating);
};