#pragma once
#include <string>
#include "Preselectable.h"
#include "Sex.h"
#define CAST_INDEX_NUMBER 18

class Cast final : public virtual Preselectable {
public:
	static const constexpr char* const DENOMINATION[CAST_INDEX_NUMBER] = {
		"NA",
		"Actor int�rprete",
		"Actor de voz",
		"Animador",
		"Compositor",
		"Cr�tico de cine",
		"Director general",
		"Director de arte",
		"Director de casting",
		"Director de fotograf�a",
		"Director de producci�n",
		"Actor de doblaje",
		"Actor doble de acci�n",
		"Editor de cinematograf�a",
		"Especialista en efectos especiales",
		"Guionista de cine",
		"Productor",
		"Sonidista"
	};
	static const constexpr char* const FEMALE_DENOMINATION[CAST_INDEX_NUMBER] = {
		"NA",
		"Actriz int�rprete",
		"Actriz de voz",
		"Animadora",
		"Compositora",
		"Cr�tica de cine",
		"Directora general",
		"Directora de arte",
		"Directora de casting",
		"Directora de fotograf�a",
		"Directora de producci�n",
		"Actriz de doblaje",
		"Actriz doble de acci�n",
		"Editora de cinematograf�a",
		"Especialista en efectos especiales",
		"Guionista de cine",
		"Productora",
		"Sonidista"
	};
	static const constexpr char* const VALUE[CAST_INDEX_NUMBER] = {
		"Sin especificar",
		"Artista que representa el papel de alg�n personaje",
		"Artista que representa la voz de alg�n personaje en el lenguaje original del film",
		"Artista que dise�a secuencias audiovisuales",
		"Artista que dise�a y aplica composiciones y elementos sonoros",
		"Profesional que estudia, analiza, aprecia y entiende en su totalidad el discurso",
		"Persona investida de m�xima autoridad en la gesti�n y direcci�n administrativa",
		"Persona investida de m�xima autoridad en la gesti�n y direcci�n art�stica",
		"Persona investida de m�xima autoridad en la gesti�n y direcci�n de papeles del film",
		"Persona investida de m�xima autoridad en la gesti�n y direcci�n fotogr�fica",
		"Persona investida de m�xima autoridad en la gesti�n y direcci�n del film",
		"Artista que representa la voz de alg�n personaje en alg�n lenguaje distinto al original en el film",
		"Profesional que reemplaza a un int�rprete en una escena dif�cil o peligrosa de ejecutar",
		"Profesional que compone escenas y secuencias con un equipo de montaje",
		"Profesional que emplea los distintos trucos visuales que logran dar credibilidad a la producci�n",
		"Profesional que permite a cualquier persona interpretar correctamente la obra sin margen de dudas",
		"Representante legal de una obra cinematogr�fica y responsable de los aspectos organizativos y t�cnicos",
		"Profesional en producci�n, transmisi�n o emisi�n electr�nica de sonido"
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