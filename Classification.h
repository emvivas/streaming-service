#pragma once
#include <string>
#include "Preselectable.h"
#define CLASSIFICATION_INDEX_NUMBER 7

class Classification final : public virtual Preselectable {
public:
	static const constexpr char* const DENOMINATION[CLASSIFICATION_INDEX_NUMBER] = { "NA", "AA", "A", "B", "B15", "C", "D" };
	static const constexpr char* const VALUE[CLASSIFICATION_INDEX_NUMBER] = { "Sin especificar", "P�blico infantil menor de siete a�os de edad", "P�blico en general", "P�blico adolescente de 12 a�os en adelante", "P�blico adolescente de 15 a�os en adelante", "P�blico adulto de 18 a�os en adelante", "P�blico adulto exclusivamente" };
	enum class Value : size_t { NONE, AA, A, B, B15, C, D };
	explicit Classification(void) = default;
	explicit Classification(const Classification::Value& value);
	Classification(const Classification& classification) = default;
	~Classification(void) = default;
	constexpr Classification& operator=(const Classification& classification) = default;
	Classification::Value getValue(void) const;
	void setValue(const Classification::Value& value);
	std::string getDenomination(void) const override;
	std::string getStringValue(void) const override;
	std::string toString(void) const override;
private:
	Value value{ Classification::Value::NONE };
	size_t index{ static_cast<size_t>(value) };
};