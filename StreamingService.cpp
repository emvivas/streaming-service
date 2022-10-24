/**
@program Streaming Service
@version 1.0alpha
@author Emiliano Vivas Rodríguez
@email a01424732@tec.mx
@since 2022/06/17

Certificados del administrador.
Identificador: U22[ Número del día de este mes ][ Número del día de hoy ]1
Contraseña: 321
*/

#include <cstdlib>
#include "View.h"

using namespace std;

int main()
{
    User* user{ nullptr };
    View view(&user);
    signed short int option[4]{0, 0, 0, 0};
    do {
        do { cout << view.getMenu("Servicio de streaming.\n\t\tEmiliano Vivas Rodríguez, a01424732@tec.mx", "Bienvenido a este evaluador de películas y series de cada servicio de streaming.\n\tSeleccione alguna de las siguientes opciones", new vector<string>{ "Mostrar calificaciones de los vídeos", "Iniciar sesión", "Registrarse en el sistema", "Salir del sistema" }, option[0]); } while (view.evaluateMenu(_getch(), option[0]));
        switch (option[0]) {
        case 0:
            view.showStatus();
            break;
        case 1:
            if ((user = view.logIn()) != nullptr) {
                cout << "\n\n\t¡Bienvenido, " << user->getName() << '!' << endl;
                Sleep(2000);
                std::system("cls");
                if (user->authenticate()) {
                    do {
                        do { cout << view.getMenu(user->getName() + ", cuenta de administración del sistema", "Seleccione alguna de las siguientes opciones", new vector<string>{ "Mostrar calificaciones de los vídeos", "Realizar votación", "Cargar archivos de datos", "Administrar usuarios", "Administrar vídeos", "Administrar servicios de streaming", "Configurar cuenta de usuario", "Cerrar sesión", "Salir del sistema" }, option[1]); } while (view.evaluateMenu(_getch(), option[1]));
                        switch (option[1]) {
                        case 0:
                            view.showStatus();
                            break;
                        case 1:
                            view.vote();
                            break;
                        case 2:
                            view.setData();
                            break;
                        case 3:
                            do {
                                do { cout << view.getMenu(user->getName() + ", cuenta de administración del sistema.\n\t\tAdministrar usuarios", "Seleccione alguna de las siguientes opciones", new vector<string>{ "Registrar usuario", "Seleccionar usuario", "Regresar al menú anterior" }, option[2]); } while (view.evaluateMenu(_getch(), option[2]));
                                switch (option[2]) {
                                case 0:
                                    do {
                                        do { cout << view.getMenu(user->getName() + ", cuenta de administración del sistema.\n\t\tAdministrar usuarios", "¿El usuario a registrar ha participado en algún proyecto cinematográfico?", new vector<string>{ "Sí, ha participado", "No, no lo sé", "Cancelar registro" }, option[3]); } while (view.evaluateMenu(_getch(), option[3]));
                                        switch (option[3]) {
                                        case 0:
                                            view.registerParticipant();
                                            option[3] = 2;
                                            break;
                                        case 1:
                                            view.registerUser();
                                            option[3] = 2;
                                        }
                                    } while (option[3] != 2);
                                    option[3] = 0;
                                    break;
                                case 1:
                                    break;
                                }
                            } while (option[2] != 2);
                            break;
                        case 4:
                            do {
                                do { cout << view.getMenu(user->getName() + ", cuenta de administración del sistema.\n\t\tAdministrar vídeos", "Seleccione alguna de las siguientes opciones", new vector<string>{ "Registrar película", "Seleccionar película", "Registrar serie", "Seleccionar serie", "Regresar al menú anterior" }, option[2]); } while (view.evaluateMenu(_getch(), option[2]));
                                switch (option[2]) {
                                case 0:
                                    view.registerMovie();
                                    break;
                                case 1:
                                    break;
                                case 2:
                                    view.registerSerie();
                                    break;
                                case 3:
                                    break;
                                }
                            } while (option[2]!=4);
                            break;
                        case 5:
                            do { cout << view.getMenu(user->getName() + ", cuenta de administración del sistema.\n\t\tAdministrar servicios de streaming", "Seleccione alguna de las siguientes opciones", new vector<string>{ "Registrar servicio", "Seleccionar servicio", "Regresar al menú anterior" }, option[2]); } while (view.evaluateMenu(_getch(), option[2]));
                            break;
                        case 6:
                            break;
                        case 8:
                            return EXIT_SUCCESS;
                        }
                    } while (option[1] != 7);
                    user = nullptr;
                }
                else {
                        do {
                            do { cout << view.getMenu(user->getName() + ", cuenta de usuario", "Seleccione alguna de las siguientes opciones", new vector<string>{ "Mostrar calificaciones de los vídeos", "Realizar votación", "Configurar cuenta de usuario", "Cerrar sesión" }, option[1]); } while (view.evaluateMenu(_getch(), option[1]));
                            switch (option[1]) {
                            case 0:
                                view.showStatus();
                                break;
                            case 1:
                                view.vote();
                                break;
                            case 2:
                                break;
                            }
                        } while (option[1] != 3);
                        user = nullptr;
                    }
            } else {
                cout << "\n\n\tLas credenciales no coinciden con ningún usuario." << endl;
                Sleep(2000);
                std::system("cls");
            }
            break;
        case 2:
            view.registerUser();
        }
    } while (option[0] != 3);
    return EXIT_SUCCESS;
}