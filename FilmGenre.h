#pragma once
#include <string>
#include "Preselectable.h"
#define FILMGENRE_INDEX_NUMBER 19

class FilmGenre final : public virtual Preselectable {
public:
	static const constexpr char* const DENOMINATION[FILMGENRE_INDEX_NUMBER] = {
		"NA",
		"Drama",
		"Acci�n",
		"Misterio",
		"Aventura",
		"Ciencia ficci�n",
		"Comedia",
		"Documental",
		"Fantas�a",
		"Musical",
		"Suspenso",
		"Terror",
		"Policiaco",
		"Romance",
		"�pico",
		"Biograf�a",
		"Historia",
		"B�lico",
		"Viejo oeste"
	};
	static const constexpr char* const VALUE[FILMGENRE_INDEX_NUMBER] = {
		"Sin especificar",
		"V�ctimas del infortunio, la maldad y el dolor humano",
		"El cl�max de la historia puede redefinirse en un instante",
		"Un contexto desconocido para hallar posibles respuestas a los problemas existentes",
		"Un viaje repleto de experiencias significativas para los protagonistas de la historia",
		"Mundos maravillosos, irreales y de ensue�o",
		"Episodios de la vida cotidiana, en clave de humor y optimismo",
		"La realidad, la relaci�n directa con la historia narrada",
		"Tem�ticas positivas, la extravagancia est� impl�cita en el contexto de la trama",
		"Canci�n, ritmo y danza como los elementos fundamentales",
		"Incertidumbre de los hechos como un papel fundamental en este tipo de trama",
		"Suspenso y la intriga, recreaci�n escenarios l�gubres o misteriosos",
		"Corte policial, de tem�tica criminal, de espionaje y detectivesco",
		"El amor como la emoci�n caracter�stica de la trama principal",
		"Historia, pero con la visi�n propia del creador",
		"Historia real o basada de una persona en su determinado contexto temporal",
		"Hechos y acontecimientos que sucedieron en la historia real",
		"Traumas, violencia, problemas, desarraigo, y riesgos de la guerra en la sociedad",
		"Territorios, gente y costumbres muy peculiares de la historia estadunidense"
	};
	enum class Value : size_t {
		NONE,
		DRAMA,
		ACTION,
		MISTERY,
		ADVENTURE,
		SCIENCE_FICTION,
		COMEDY,
		DOCUMENTARY,
		FANTASY,
		MUSICAL,
		SUSPENSE,
		TERROR,
		POLICE,
		ROMANCE,
		EPIC,
		BIOGRAPHY,
		HISTORY,
		BELIC,
		OLD_WEST
	};
	explicit FilmGenre(void) = default;
	explicit FilmGenre(const FilmGenre::Value& value);
	FilmGenre(const FilmGenre& filmGenre) = default;
	~FilmGenre(void) = default;
	constexpr FilmGenre& operator=(const FilmGenre& filmGenre) = default;
	FilmGenre::Value getValue(void) const;
	void setValue(const FilmGenre::Value& value);
	std::string getDenomination(void) const override;
	std::string getStringValue(void) const override;
	std::string toString(void) const override;
private:
	Value value{ FilmGenre::Value::NONE };
	size_t index{ static_cast<size_t>(value) };
};