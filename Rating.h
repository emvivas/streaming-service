#pragma once
#include <string>
#include "Preselectable.h"
#define RATING_INDEX_NUMBER 6

class Rating final : public virtual Preselectable {
public:
	static const constexpr char* const DENOMINATION[RATING_INDEX_NUMBER] = { "NA", "Deficiente", "Aceptable", "Regular", "Bueno", "Excelente" };
	static const constexpr char* const VALUE[RATING_INDEX_NUMBER] = { "Sin puntuación", "Puntuación 1/5", "Puntuación 2/5", "Puntuación 3/5", "Puntuación 4/5", "Puntuación 5/5" };
	enum class Value : size_t { NONE, DEFICIENT, ACCEPTABLE, REGULAR, GOOD, EXCELLENT };
	explicit Rating(void) = default;
	explicit Rating(const Rating::Value& value);
	Rating(const Rating& rating) = default;
	~Rating(void) = default;
	constexpr Rating& operator=(const Rating& rating) = default;
	Rating::Value getValue(void) const;
	void setValue(const Rating::Value& value);
	std::string getDenomination(void) const override;
	std::string getStringValue(void) const override;
	std::string toString(void) const override;
private:
	Value value{ Rating::Value::NONE };
	size_t index{ static_cast<size_t>(value) };
};