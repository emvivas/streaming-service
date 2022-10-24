#pragma once
#include <clocale>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include "User.h"
#include "Participant.h"
#include "Serie.h"
#include "Season.h"
#include "Film.h"
#include "Rating.h"
#define DATABASE_INDEX_NUMBER 2
#define WIDTH_SIZE 100
#define HEIGHT_SIZE 35
#define UP_KEY 72
#define DOWN_KEY 80
#define ENTER_KEY 13

class View {
private:
	static const std::string DATABASES[DATABASE_INDEX_NUMBER];
	static std::vector<std::string> split(const std::string& str, const char& pattern = '|');
	struct PersonalData {
		std::string email{}, isp{}, phoneNumber{}, username{}, name[NAME_INDEX_NUMBER]{}, password{}, birthdayString{};
		std::tm birthday{};
	};
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT windowSize = { 0, 0, WIDTH_SIZE, HEIGHT_SIZE };
	CONSOLE_CURSOR_INFO cursor{ 1, FALSE };
	std::string separator{ *new std::string(WIDTH_SIZE, '_') };
	User** USER{ nullptr };
	PersonalData registerPerson(void);
public:
	explicit View(void) = delete;
	explicit View(User** const user);
	View(const View& view) = default;
	~View(void) = default;
	constexpr View& operator=(const View& view) = default;
	std::string getHeader(const std::string& title) const;
	std::string getHeader(const std::string& title, const std::string& instructions) const;
	std::string getMenu(const std::string& title, const std::string& instructions, const std::vector<std::string>* options, signed short int& option) const;
	bool evaluateMenu(const int& key, signed short int& option) const;
	void registerUser(void);
	void registerParticipant(void);
	void registerMovie(void);
	void registerSerie(void);
	void setData(void);
	void vote(void);
	void showStatus(void);
	User* logIn(void);
};