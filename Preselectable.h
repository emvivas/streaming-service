#pragma once
#include <string>

class Preselectable {
public:
	explicit constexpr Preselectable(void) = default;
	~Preselectable(void) = default;
	constexpr Preselectable& operator=(const Preselectable& preselectable) = default;
	virtual std::string getDenomination(void) const = 0;
	virtual std::string getStringValue(void) const = 0;
	virtual std::string toString(void) const = 0;
};