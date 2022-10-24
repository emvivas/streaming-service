#pragma once
#include <string>
#include "Preselectable.h"
#define FILMGENRE_INDEX_NUMBER 19

class FilmGenre final : public virtual Preselectable {
public:
	static const constexpr char* const DENOMINATION[FILMGENRE_INDEX_NUMBER] = {
		"NA",
		"Drama",
		"Acción",
		"Misterio",
		"Aventura",
		"Ciencia ficción",
		"Comedia",
		"Documental",
		"Fantasía",
		"Musical",
		"Suspenso",
		"Terror",
		"Policiaco",
		"Romance",
		"Épico",
		"Biografía",
		"Historia",
		"Bélico",
		"Viejo oeste"
	};
	static const constexpr char* const VALUE[FILMGENRE_INDEX_NUMBER] = {
		"Sin especificar",
		"Víctimas del infortunio, la maldad y el dolor humano",
		"El clímax de la historia puede redefinirse en un instante",
		"Un contexto desconocido para hallar posibles respuestas a los problemas existentes",
		"Un viaje repleto de experiencias significativas para los protagonistas de la historia",
		"Mundos maravillosos, irreales y de ensueño",
		"Episodios de la vida cotidiana, en clave de humor y optimismo",
		"La realidad, la relación directa con la historia narrada",
		"Temáticas positivas, la extravagancia está implícita en el contexto de la trama",
		"Canción, ritmo y danza como los elementos fundamentales",
		"Incertidumbre de los hechos como un papel fundamental en este tipo de trama",
		"Suspenso y la intriga, recreación escenarios lúgubres o misteriosos",
		"Corte policial, de temática criminal, de espionaje y detectivesco",
		"El amor como la emoción característica de la trama principal",
		"Historia, pero con la visión propia del creador",
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