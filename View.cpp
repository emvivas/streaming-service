#include "View.h"

const std::string View::DATABASES[DATABASE_INDEX_NUMBER]{ "MoviesDatabase.txt", "SeriesDatabase.txt" };

View::View(User** const user) : USER{ user } {
    setlocale(LC_ALL, "es_Es");
    SetConsoleTitleA("Servicio de Streaming (v1.0a)");
    SetConsoleWindowInfo(handle, 1, &windowSize);
    SetConsoleCursorInfo(handle, &cursor);
    std::system("cls");
}

View::PersonalData View::registerPerson(void) {
    PersonalData personalData{};
    std::istringstream* ss{ nullptr };
    std::cout << "- Nombre de usuario: ";
    std::cin >> personalData.username;
    std::cout << "\n\t- Correo electrónico: ";
    std::cin >> personalData.email;
    std::cout << "\n\t- Nombre: ";
    std::cin >> personalData.name[static_cast<size_t>(User::NameIndex::NAME)];
    std::cout << "\n\t- Primer apellido: ";
    std::cin >> personalData.name[static_cast<size_t>(User::NameIndex::FIRST_LASTNAME)];
    std::cout << "\n\t- Segundo apellido: ";
    std::cin >> personalData.name[static_cast<size_t>(User::NameIndex::SECOND_LASTNAME)];
    std::cout << "\n\t- ISP: ";
    std::cin >> personalData.isp;
    std::cout << "\n\t- Número telefónico: ";
    std::cin >> personalData.phoneNumber;
    do {
        std::cout << "\n\t- Fecha de nacimiento [d/m/Y]: ";
        std::cin >> personalData.birthdayString;
        ss = new std::istringstream(personalData.birthdayString);
        ss->imbue(std::locale("es_Es.utf-8"));
        *ss >> std::get_time(&personalData.birthday, "%d/%m/%Y");
    } while (ss->fail());
    std::cout << "\n\t- Contraseña: ";
    std::cin >> personalData.password;
    return personalData;
}

std::vector<std::string> View::split(const std::string& str, const char& pattern) {
    int posInit{ 0u };
    int posFound{ 0u };
    std::string splitted;
    std::vector<std::string> results;
    while (posFound >= 0) {
        posFound = static_cast<int>(str.find(pattern, static_cast<size_t>(posInit)));
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        results.push_back(splitted);
    }
    return results;
}

std::string View::getHeader(const std::string& title) const {
    return '\n' + separator + "\n\n\t::\t" + title + ".\n" + separator + '\n';
}

std::string View::getHeader(const std::string& title, const std::string& instructions) const {
    return getHeader(title) + "\n\n\t" + instructions + ":\n\n\n\t";
}

std::string View::getMenu(const std::string& title, const std::string& instructions, const std::vector<std::string>* options, signed short int& option) const {
    option = static_cast<signed short int>(option < 0 ? options->size() - 1 : option % options->size());
    std::string menu{ getHeader(title, instructions) };
    for (size_t index = 0; index < options->size(); ++index) {
        menu += index == option ? "->" : "";
        menu += "\t" + options->at(index) + ".\n\n\t";
    }
    return menu;
}

bool View::evaluateMenu(const int& key, signed short int& option) const {
    Sleep(25);
    std::system("cls");
    switch (key) {
    case UP_KEY:
        --option;
        return true;
    case DOWN_KEY:
        ++option;
        return true;
    case ENTER_KEY:
        return false;
    default:
        return true;
    }
}

void View::registerUser(void) {
    if (*USER != nullptr) std::cout << getHeader((*USER)->getName() + ", cuenta de administración del sistema.\n\t\tRegistrar usuario", "Introduzca los siguientes datos personales del nuevo usuario");
    else std::cout << getHeader("Servicio de streaming.\n\t\tRegistrar usuario", "Introduzca sus siguientes datos personales");
    PersonalData personalData = registerPerson();
    User newUser(personalData.email, personalData.isp, personalData.phoneNumber, personalData.username, personalData.password, personalData.birthday, personalData.name[static_cast<size_t>(User::NameIndex::NAME)], personalData.name[static_cast<size_t>(User::NameIndex::FIRST_LASTNAME)], personalData.name[static_cast<size_t>(User::NameIndex::SECOND_LASTNAME)]);
    std::cout << "\n\n\t¡Bienvenido, " << newUser.getName() << "!\n\tSu identificador asignado es " << newUser.getIdentificator() << std::endl << "\n\t";
    std::system("pause");
    std::system("cls");
}

void View::registerParticipant(void) {
    std::cout << getHeader((*USER)->getName() + ", cuenta de administración del sistema.\n\t\tRegistrar usuario participante", "Introduzca los siguientes datos personales del nuevo usuario");
    PersonalData personalData = registerPerson();
    Participant newParticipant(personalData.email, personalData.isp, personalData.phoneNumber, personalData.username, personalData.password, personalData.birthday, personalData.name[static_cast<size_t>(User::NameIndex::NAME)], personalData.name[static_cast<size_t>(User::NameIndex::FIRST_LASTNAME)], personalData.name[static_cast<size_t>(User::NameIndex::SECOND_LASTNAME)]);
    std::cout << "\n\n\t¡Bienvenido, " << newParticipant.getName() << "!\n\tSu identificador de usuario asignado es " << newParticipant.getIdentificator() << "\n\tIdentifíquese como participante de alguna producción con " << newParticipant.getParticipantIdentificator() << std::endl << "\n\t";
    std::system("pause");
    std::system("cls");
}

void View::registerMovie(void) {
    std::istringstream* ss{ nullptr };
    std::string denomination{}, lengthString{}, releaseString{};
    std::tm length{}, release{};
    std::cout << getHeader((*USER)->getName() + ", cuenta de administración del sistema.\n\t\tRegistrar película", "Introduzca los siguientes datos de la nueva película");
    std::cout << "- Denominación: ";
    std::cin >> denomination;
    do {
        std::cout << "\n\t- Duración [H:M:S]: ";
        std::cin >> lengthString;
        ss = new std::istringstream(lengthString);
        ss->imbue(std::locale("es_Es.utf-8"));
        *ss >> std::get_time(&length, "%H:%M:%S");
    } while (ss->fail());
    do {
        std::cout << "\n\t- Estreno [d/m/Y]: ";
        std::cin >> releaseString;
        ss = new std::istringstream(releaseString);
        ss->imbue(std::locale("es_Es.utf-8"));
        *ss >> std::get_time(&release, "%d/%m/%Y");
    } while (ss->fail());
    Film newFilm(denomination, length, release);
    std::cout << "\n\n\t¡" << newFilm.getDenomination() << " se ha registrado!\n\tEl identificador de película asignado es " << newFilm.getIdentificator() << std::endl << "\n\t";
    std::system("pause");
    std::system("cls");
}

void View::registerSerie(void) {
    size_t seasonsNumber{ 0u };
    std::string denomination{};
    std::vector<Season> seasons{};
    std::cout << getHeader((*USER)->getName() + ", cuenta de administración del sistema.\n\t\tRegistrar serie", "Introduzca los siguientes datos de la nueva serie");
    std::cout << "- Denominación: ";
    std::cin >> denomination;
    do {
        std::cout << "\n\t- Número de temporadas: ";
        std::cin >> seasonsNumber;
    } while (seasonsNumber <= 0);
    for (size_t index{ 0u }; index < seasonsNumber; ++index) seasons.push_back(*new Season(index));
    Serie newSerie(denomination, seasons);
    std::cout << "\n\n\t¡" << newSerie.getDenomination() << " se ha registrado!\n\tEl identificador de serie asignado es " << newSerie.getIdentificator() << std::endl << "\n\t";
    std::system("pause");
    std::system("cls");
}

void View::setData(void) {
    std::string str{};
    std::cout << getHeader((*USER)->getName() + ", cuenta de administración del sistema.\n\t\tCargar archivos de datos") << '\n';
    for (size_t index{ 0u }; index < DATABASE_INDEX_NUMBER; ++index) {
        std::ifstream* database = new std::ifstream(DATABASES[index]);
        if (database->good()) {
            std::cout << "\n\tRegistros provenientes de \"" + DATABASES[index] + "\" recién añadidos al sistema:\n\n";
            while (std::getline(*database, str)) std::cout << "\t\t" << *Film::getRegister(split(str)) << "\n\n";
            if(str.empty()) std::cout << "\t\tSin registros disponibles.\n\n";
        }
        else std::cout << "\n\tLa base de datos \"" << DATABASES[index] << "\" no se encuentra disponible.\n\n";
    }
    std::cout << "\n\n\t";
    std::system("pause");
    std::system("cls");
}

void View::vote(void) {
    signed short int option[2]{0, 0};
    std::string label{ *USER != nullptr ? (*USER)->getName() + ((*USER)->authenticate() ? ", cuenta de administración del sistema." : ", cuenta de usuario.") : "Servicio de streaming." };
    std::vector<std::string> titles{}, ratings{};
    Film* film{ nullptr };
    for (const Film& film : Film::getFilms()) titles.push_back(film.toString());
    for (const Serie& serie : Serie::getSeries()) titles.push_back(serie.toString());
    titles.push_back("Cancelar selección");
    titles.shrink_to_fit();
    for (size_t index{ 0u }; index < RATING_INDEX_NUMBER; ++index) ratings.push_back(*new std::string(Rating::DENOMINATION[index]) + ", " + *new std::string(Rating::VALUE[index]));
    ratings.push_back("Cancelar voto");
    ratings.shrink_to_fit();
    do{ std::cout << getMenu(label + "\n\t\tRealizar votación", "Seleccione alguna de las siguientes películas y series", &titles, option[0]); } while (evaluateMenu(_getch(), option[0]));
    if (option[0] < titles.size() - Serie::getSeries().size() - 1) {
        film = Film::getFilm(static_cast<size_t>(option[0]));
        do { std::cout << getMenu(label + "\n\t\tRealizar votación para " + film->toString(), "Indique una de las siguientes opciones de voto para este ítem", &ratings, option[1]); } while (evaluateMenu(_getch(), option[1]));
        if (option[1] < ratings.size() - 1) {
            if (film->addChoice(new Choice(*USER, static_cast<Rating::Value>(option[1])))) {
                std::cout << getHeader(label + "\n\t\tResultados acumulados de " + film->toString()) << "\n\n\n" << film->getData() << "\n\n\n\n\t¡Su voto se ha registrado!\n\n\tUsted ha optado por la opción " + ratings[static_cast<size_t>(option[1])] + ".\n\tEl promedio de los votos(" + std::to_string(film->getMeanRating()) + ") corresponde a la opción " + film->getRating().toString() + ".\n\n\t";
                std::system("pause");
                std::system("cls");
            }
        }
    }
}

void View::showStatus(void) {
    signed short int option{ 0 };
    std::string label{ *USER!=nullptr ? (*USER)->getName() + ((*USER)->authenticate() ? ", cuenta de administración del sistema." : ", cuenta de usuario.") : "Servicio de streaming."};
    std::vector<std::string> titles{};
    Film* film{ nullptr };
    for (const Film& film : Film::getFilms()) titles.push_back(film.toString());
    for (const Serie& serie : Serie::getSeries()) titles.push_back(serie.toString());
    titles.push_back("Cancelar selección");
    titles.shrink_to_fit();
    do { std::cout << getMenu(label + "\n\t\tMostrar calificaciones de los vídeos", "Seleccione alguna de las siguientes películas y series", &titles, option); } while (evaluateMenu(_getch(), option));
    if (option < titles.size() - 1) {
        film = Film::getFilm(static_cast<size_t>(option));
        std::cout << getHeader(label + "\n\t\tResultados acumulados de " + film->toString()) << "\n\n\n" << film->getData() << "\n\n\n\n\tEl promedio de los votos (" + std::to_string(film->getMeanRating()) + ") corresponde a la opción " + film->getRating().toString() + ".\n\n\t";
        std::system("pause");
        std::system("cls");
    }
}

User* View::logIn(void) {
    std::string identificator{}, password{};
    std::cout << getHeader("Servicio de streaming.\n\t\tIniciar sesión de usuario", "Introduzca sus credenciales para autentificarse");
    std::cout << "- Identificador de usuario: ";
    std::cin >> identificator;
    std::cout << "\n\t- Contraseña: ";
    std::cin >> password;
    return User::authenticate(identificator, password);
}