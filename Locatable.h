#pragma once
#include "Country.h"

class Locatable {
public:
	explicit constexpr Locatable(void) = default;
	Locatable(const Locatable& locatable) = default;
	~Locatable(void) = default;
	constexpr Locatable& operator=(const Locatable& locatable) = default;
	virtual Country getCountry(void) const = 0;
	virtual bool setCountry(const Country::Value& country) = 0;
};