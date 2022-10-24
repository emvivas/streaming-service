#pragma once
#include <string>
#include "Preselectable.h"
#include "Sex.h"
#define CAST_INDEX_NUMBER 18

class Cast final : public virtual Preselectable {
public:
	static const constexpr char* const DENOMINATION[CAST_INDEX_NUMBER] = {
		"NA",
		"Actor intérprete",
		"Actor de voz",
		"Animador",
		"Compositor",
		"Crítico de cine",
		"Director general",
		"Director de arte",
		"Director de casting",
		"Director de fotografía",
		"Director de producción",
		"Actor de doblaje",
		"Actor doble de acción",
		"Editor de cinematografía",
		"Especialista en efectos especiales",
		"Guionista de cine",
		"Productor",
		"Sonidista"
	};
	static const constexpr char* const FEMALE_DENOMINATION[CAST_INDEX_NUMBER] = {
		"NA",
		"Actriz intérprete",
		"Actriz de voz",
		"Animadora",
		"Compositora",
		"Crítica de cine",
		"Directora general",
		"Directora de arte",
		"Directora de casting",
		"Directora de fotografía",
		"Directora de producción",
		"Actriz de doblaje",
		"Actriz doble de acción",
		"Editora de cinematografía",
		"Especialista en efectos especiales",
		"Guionista de cine",
		"Productora",
		"Sonidista"
	};
	static const constexpr char* const VALUE[CAST_INDEX_NUMBER] = {
		"Sin especificar",
		"Artista que representa el papel de algún personaje",
		"Artista que representa la voz de algún personaje en el lenguaje original del film",
		"Artista que diseña secuencias audiovisuales",
		"Artista que diseña y aplica composiciones y elementos sonoros",
		"Profesional que estudia, analiza, aprecia y entiende en su totalidad el discurso",
		"Persona investida de máxima autoridad en la gestión y dirección administrativa",
		"Persona investida de máxima autoridad en la gestión y dirección artística",
		"Persona investida de máxima autoridad en la gestión y dirección de papeles del film",
		"Persona investida de máxima autoridad en la gestión y dirección fotográfica",
		"Persona investida de máxima autoridad en la gestión y dirección del film",
		"Artista que representa la voz de algún personaje en algún lenguaje distinto al original en el film",
		"Profesional que reemplaza a un intérprete en una escena difícil o peligrosa de ejecutar",
		"Profesional que compone escenas y secuencias con un equipo de montaje",
		"Profesional que emplea los distintos trucos visuales que logran dar credibilidad a la producción",
		"Profesional que permite a cualquier persona interpretar correctamente la obra sin margen de dudas",
		"Representante legal de una obra cinematográfica y responsable de los aspectos organizativos y técnicos",
		"Profesional en producción, transmisión o emisión electrónica de sonido"
	};
	enum class Value : size_t {
		NONE,
		ACTOR_PERFORMER,
		VOICE_ACTOR,
		ANIMATOR,
		COMPOSER,
		FILM_CRITIC,
		GENERAL_DIRECTOR,
		ART_DIRECTOR,
		CASTING_DIRECTOR,
		PHOTOGRAPHY_DIRECTOR,
		PRODUCTION_DIRECTOR,
		DUBBING_PERFORMER,
		RISK_PERFORMER,
		FILM_EDITOR,
		SPECIAL_EFFECTS_SPECIALIST,
		SCREENWRITER,
		PRODUCER,
		SOUNDMAN
	};
	explicit Cast(void) = delete;
	explicit Cast(const Sex* sex, const Cast::Value& value = Cast::Value::NONE);
	Cast(const Cast& cast) = default;
	~Cast(void) = default;
	constexpr Cast& operator=(const Cast& cast) = default;
	Cast::Value getValue(void) const;
	void setValue(const Cast::Value& value);
	std::string getDenomination(void) const override;
	std::string getStringValue(void) const override;
	std::string toString(void) const override;
private:
	const Sex* SEX{ nullptr };
	Value value{ Cast::Value::NONE };
	size_t index{ static_cast<size_t>(value) };
};