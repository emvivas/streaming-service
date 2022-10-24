#pragma once
#include <string>
#include "Preselectable.h"
#define SEX_INDEX_NUMBER 3

class Sex final : public virtual Preselectable {
public:
	static const constexpr char* const DENOMINATION[SEX_INDEX_NUMBER] = { "NA", "M", "F" };
	static const constexpr char* const VALUE[SEX_INDEX_NUMBER] = { "Sin especificar", "Masculino", "Femenino" };
	enum class Value : size_t { NONE, MALE, FEMALE };
	explicit Sex(void) = default;
	explicit Sex(const Sex::Value& value);
	Sex(const Sex& sex) = default;
	~Sex(void) = default;
	constexpr Sex& operator=(const Sex& sex) = default;
	Sex::Value getValue(void) const;
	void setValue(const Sex::Value& value);
	std::string getDenomination(void) const override;
	std::string getStringValue(void) const override;
	std::string toString(void) const override;
private:
	Value value{ Sex::Value::NONE };
	size_t index{ static_cast<size_t>(value) };
};