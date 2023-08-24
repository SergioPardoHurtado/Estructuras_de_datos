#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
using namespace ::std;

struct Paises {
  string pais;
  int tropas;
};
struct Continentes {
  string continente;
  std::list<Paises> PA;
};

struct jugador {
  int fichas;
  int identificador;
  string nombre;
  std::list<Paises> paises_domados;
};

void agregarPaisAContinente(Continentes &continente, const string &nombrePais) {
  Paises nuevoPais;
  nuevoPais.pais = nombrePais;
  continente.PA.push_back(nuevoPais);
}

void contienetes(list<Continentes> &listaContinentes) {
  listaContinentes.push_back({"America del Norte"});
  listaContinentes.push_back({"Africa"});
  listaContinentes.push_back({"America del Sur"});
  listaContinentes.push_back({"Europa"});
  listaContinentes.push_back({"Asia"});
  listaContinentes.push_back({"Oceania"});
  for (auto &continente : listaContinentes) {

    if (continente.continente == "America del Norte") {
      agregarPaisAContinente(continente, "Alaska");
      agregarPaisAContinente(continente, "Alberta");
      agregarPaisAContinente(continente, "Mexico, America Central y el Caribe");
      agregarPaisAContinente(continente,
                             "Estados Unidos del Este, compuesta por el "
                             "Noreste y el Sudeste de Estados Unidos");
      agregarPaisAContinente(continente, "Territorios del Noroeste");
      agregarPaisAContinente(continente, "Ontario");
      agregarPaisAContinente(continente, "Quebec");
      agregarPaisAContinente(continente, "Estados Unidos del Oeste");
    }

    if (continente.continente == "Ãfrica") {
      agregarPaisAContinente(continente, "Congo");
      agregarPaisAContinente(continente, "Africa Oriental");
      agregarPaisAContinente(continente, "Egipto");
      agregarPaisAContinente(continente, "Madagascar");
      agregarPaisAContinente(continente, "Africa del Norte");
      agregarPaisAContinente(continente, "Sudafrica");
    }
    if (continente.continente == "America del Sur") {
      agregarPaisAContinente(continente, "Argentina");
      agregarPaisAContinente(continente, "Brasil");
      agregarPaisAContinente(continente, "Peru");
      agregarPaisAContinente(continente, "Venezuela");
    }

    if (continente.continente == "Europa") {
      agregarPaisAContinente(continente, "Gran Bretana");
      agregarPaisAContinente(continente, "Islandia");
      agregarPaisAContinente(continente, "Europa del Norte");
      agregarPaisAContinente(continente, "Escandinavia");
      agregarPaisAContinente(continente, "Europa del Sur");
      agregarPaisAContinente(continente, "Rusia");
      agregarPaisAContinente(continente, "Europa Occidental");
    }

    if (continente.continente == "Asia") {
      agregarPaisAContinente(continente, "AfganistÃ¡n");
      agregarPaisAContinente(continente, "China");
      agregarPaisAContinente(continente, "India");
      agregarPaisAContinente(continente, "Irkutsk");
      agregarPaisAContinente(continente, "Japon");
      agregarPaisAContinente(continente, "Kamchatka");
      agregarPaisAContinente(continente, "Oriente Medio");
      agregarPaisAContinente(continente, "Mongolia");
      agregarPaisAContinente(continente, "Sudeste Asiatico");
      agregarPaisAContinente(continente, "Siberia");
      agregarPaisAContinente(continente, "Ural");
      agregarPaisAContinente(continente, "Yakutsk");
    }
    if (continente.continente == "Oceania") {
      agregarPaisAContinente(continente,
                             "Australia Oriental, compuesta por Queensland y "
                             "por la Nueva Gales del Sur");
      agregarPaisAContinente(continente, "Indonesia");
      agregarPaisAContinente(continente, "Nueva Guinea");
      agregarPaisAContinente(continente, "Australia Occidental");
    }
  }
}

void Inicializar(list<jugador> &listaJugadores,
                 list<Continentes> &listaContinentes) {
  int jp;
  string nombre;
  cout << "CuÃ¡ntos jugadores van a jugar (mÃ­nimo 3, mÃ¡ximo 6):" << endl;
  cin >> jp;

  int totalFichas =
      40 - (jp - 3) *
               5; // Calcular el total de fichas segÃºn el nÃºmero de jugadores

  map<string, bool> paisesDisponibles;
  for (const auto &continente : listaContinentes) {
    for (const auto &pais : continente.PA) {
      paisesDisponibles[pais.pais] = true;
    }
  }

  for (int i = 0; i < jp; i++) {
    cout << "Ingrese el nombre del jugador " << i + 1 << ":" << endl;
    cin >> nombre;

    jugador nuevoJugador;
    nuevoJugador.nombre = nombre;
    nuevoJugador.identificador = i + 100;

    nuevoJugador.fichas = totalFichas; // Asignar fichas al jugador

    listaJugadores.push_back(nuevoJugador);

    cout << "Paises disponibles para " << nuevoJugador.nombre << ":" << endl;
    for (const auto &pair : paisesDisponibles) {
      if (pair.second) {
        cout << pair.first << " ";
      }
    }
    cout << endl;

    string paisElegido;
    bool paisValido = false;

    do {
      cout << "Elija un paÃ­s para " << nuevoJugador.nombre << ": ";
      cin >> paisElegido;
      auto it = paisesDisponibles.find(paisElegido);
      if (it != paisesDisponibles.end() && it->second) {
        nuevoJugador.paises_domados.push_back({paisElegido});
        it->second = false;
        paisValido = true;
      } else {
        cout << "PaÃ­s no vÃ¡lido o ya seleccionado. Intente nuevamente."
             << endl;
        paisValido = false;
      }
    } while (!paisValido);

    int fichasColocadas;
    do {
      cout << "Ingrese la cantidad de fichas que colocarÃ¡ en " << paisElegido
           << ": ";
      cin >> fichasColocadas;

      if (fichasColocadas <= nuevoJugador.fichas) {
        for (auto &continente : listaContinentes) {
          for (auto &pais : continente.PA) {
            if (pais.pais == paisElegido) {
              pais.tropas += fichasColocadas;
              nuevoJugador.fichas -= fichasColocadas;
              paisValido = true;
              break;
            }
          }
          if (paisValido) {
            break;
          }
        }
      } else {
        cout << "No tiene suficientes fichas. Ingrese un nÃºmero vÃ¡lido."
             << endl;
      }
    } while (!paisValido);
    cout << "su ID es: " << nuevoJugador.identificador << endl;
  }

  cout << "(Juego en curso) El juego ya ha sido inicializado." << endl;
  cout << "(InicializaciÃ³n satisfactoria) El juego se ha inicializado "
          "correctamente."
       << endl;
}
void Turno_IDJugador(list<Continentes> &listaContinentes,
                     list<jugador> &listaJugadores, bool inicializar,
                     bool juegoterminado, bool jugadorvalido,
                     bool turnojugador) {

  cout << "" << endl;
  cout << "Escriba el identificador del jugador: " << endl;
  int iden;
  cin >> iden;

  bool jugadorEncontrado = false;
  jugador jugadorSeleccionado;

  // Buscar el jugador en la lista de jugadores
  for (jugador &j : listaJugadores) {
    if (j.identificador == iden) {
      jugadorEncontrado = true;
      jugadorSeleccionado = j;
      break;
    }
  }

  if (!jugadorEncontrado) {
    cout << "El jugador con ID " << iden << " no existe. Intente nuevamente."
         << endl;
    return; // Salir de la funciÃ³n si el jugador no existe
  }

  if (inicializar == true) {
    if (juegoterminado == false) {
      if (jugadorvalido == true) {

        string territorioOrigen, territorioDestino;

        for (jugador &jpr : listaJugadores) {
          if (jpr.identificador != jugadorSeleccionado.identificador) {
            // Saltar a la siguiente iteraciÃ³n si el jugador no es el
            // seleccionado
            continue;
          }

          cout << "Bonus tropa" << endl;
          for (jugador &jpr : listaJugadores) {
            int cant = jpr.paises_domados.size();
            if (cant >= 12 && cant <= 14) {
              jpr.fichas += 1;
              cout << "tropas extra +1" << endl;
            } else if (cant >= 15 && cant <= 17) {
              jpr.fichas += 2;
              cout << "tropas extra +2" << endl;
            } else if (cant >= 18 && cant <= 20) {
              jpr.fichas += 3;
              cout << "tropas extra +3" << endl;
            } else if (cant >= 21 && cant <= 23) {
              jpr.fichas += 4;
              cout << "tropas extra +4" << endl;
            } else if (cant >= 24 && cant <= 26) {
              jpr.fichas += 5;
              cout << "tropas extra +5" << endl;
            } else if (cant >= 27 && cant <= 29) {
              jpr.fichas += 6;
              cout << "tropas extra +6" << endl;
            } else if (cant >= 30 && cant <= 32) {
              jpr.fichas += 7;
              cout << "tropas extra +7" << endl;
            } else if (cant >= 33 && cant <= 35) {
              jpr.fichas += 8;
              cout << "tropas extra +8" << endl;
            } else if (cant >= 36 && cant <= 38) {
              jpr.fichas += 9;
              cout << "tropas extra +9" << endl;
            } else if (cant >= 39 && cant <= 41) {
              jpr.fichas += 10;
              cout << "tropas extra +10" << endl;
            } else {
              cout << "no hay tropas extra" << endl;
            }

            cout << "(Turno del jugador " << jpr.nombre << ")" << endl;

            if (jpr.fichas > 0) {
              string paisElegido;
              bool paisValido = false;

              do {
                cout << "Elija un paÃ­s para colocar " << jpr.fichas
                     << " tropa(s): ";
                cin >> paisElegido;

                for (auto &continente : listaContinentes) {
                  for (auto &pais : continente.PA) {
                    if (pais.pais == paisElegido && jpr.nombre == pais.pais) {
                      pais.tropas += jpr.fichas;
                      jpr.fichas = 0;
                      paisValido = true;
                      break;
                    }
                  }
                  if (paisValido) {
                    break;
                  }
                }

                if (!paisValido) {
                  cout << "PaÃ­s no vÃ¡lido o no controlado por el jugador. "
                          "Intente nuevamente."
                       << endl;
                }

              } while (!paisValido);
            }

            bool territorioValido = false;

            do {

              cout << "(Turno del jugador " << jpr.nombre
                   << ") Elige el territorio de origen para el ataque: ";
              cin >> territorioOrigen;

              for (const Paises &pais : jpr.paises_domados) {
                if (pais.pais == territorioOrigen) {
                  territorioValido = true;
                  break;
                }
              }

              if (!territorioValido) {
                cout << "No tienes control sobre el territorio "
                     << territorioOrigen << ". Intenta nuevamente." << endl;
              }

            } while (!territorioValido);

            bool DestinoValido = false;
            string nombreJugadorDefensor;
            do {

              cout << "(Turno del jugador " << jpr.nombre
                   << ") Elige el territorio de destino para el ataque: ";
              cin >> territorioDestino;

              for (jugador &opponent : listaJugadores) {
                if (opponent.nombre !=
                    jpr.nombre) { // No se busca en los propios territorios
                  for (const Paises &pais : opponent.paises_domados) {
                    if (pais.pais == territorioDestino) {
                      nombreJugadorDefensor = opponent.nombre;
                      DestinoValido = true;
                      break;
                    }
                  }
                }
                if (DestinoValido) {
                  break;
                }
              }

              if (!DestinoValido) {
                cout
                    << "El territorio " << territorioDestino
                    << " no es controlado por otro jugador. Intenta nuevamente."
                    << endl;
              }

            } while (!DestinoValido);

            if (territorioValido && DestinoValido) {
              int dadoJugador1 = rand() % 6 + 1;
              int dadoJugador2 = rand() % 6 + 1;
              int unidadesGanadasAtacante =
                  0; // Inicializa estas variables segÃºn tu lÃ³gica
              int unidadesGanadasDefensor = 0;

              if (dadoJugador1 < dadoJugador2) {
                for (Paises &pais : jpr.paises_domados) {
                  if (pais.pais == territorioOrigen) {
                    unidadesGanadasAtacante =
                        pais.tropas; // Resta las tropas del paÃ­s de origen al
                                     // atacante
                    jpr.fichas -= pais.tropas;
                    pais.tropas =
                        0; // El paÃ­s de origen pierde todas las tropas
                    break;
                  }
                }
              }

              std::cout << "Resultado del ataque:" << std::endl;
              std::cout << "Dados del atacante: " << dadoJugador1 << std::endl;
              std::cout << "Dados del defensor: " << dadoJugador2 << std::endl;
              std::cout << "Unidades ganadas por el atacante: "
                        << unidadesGanadasAtacante << std::endl;
              std::cout << "Unidades ganadas por el defensor: "
                        << unidadesGanadasDefensor << std::endl;
            }

            cout << "(Turno terminado correctamente) El turno del jugador "
                 << jpr.nombre << " ha terminado." << endl;
          }
        }
      }else {
          cout << "(Jugador no vÃ¡lido) El jugador <id_jugador> no forma parte "
                  "de esta partida."
               << endl;
        }
      } else {
        cout << "(Juego terminado) Esta partida ya tuvo un ganador." << endl;
      }
    } else {
      cout << "(Juego no inicializado) Esta partida no ha sido inicializada "
              "correctamente."
           << endl;
    }
  }

  void impresion() {
    cout << "*******Lista de Comandos********" << endl;
    cout << "-inicializar" << endl;
    cout << "-turno" << endl;
    cout << "-salir" << endl;
    cout << "-guardar <nombre_Archivo>" << endl;
    cout << "-guardar_comprimido <nombre_Archivo>" << endl;
    cout << "-inicializar <nombre_Archivo>" << endl;
    cout << "-costo conquista" << endl;
    cout << "-conquista mas barata" << endl;
    cout << "- help" << endl;
  }
  void menu() {
    std::list<jugador> listaJugadores;
    std::list<Continentes> listaContinentes;
    string comando;
    bool salir = false;
    bool inicializar = false;
    bool juegoterminado = false;
    bool jugadorvalido = true;
    bool turnojugador = true;
    bool cargarc = false;
    bool guardar = false;
    bool guardarc = false;
    bool comandoT = false;
    bool conquistV = false;
    contienetes(listaContinentes);

    while (!salir) {

      std::cout << "Ingrese un comando: ";
      std::cin >> comando;

      if (comando == "inicializar") {
        Inicializar(listaJugadores, listaContinentes);
        inicializar = true;

      } else if (comando == "Turno") {
        Turno_IDJugador(listaContinentes, listaJugadores, inicializar,
                        juegoterminado, jugadorvalido, turnojugador);

        //-------------------------------------------------
      } else if (comando == "salir") {
        salir = true;
        system("CLS()");
      }

      else if (comando == "guardar <nombre_Archivo>") {
        if (inicializar == true) {
          if (guardar == true) {
            cout << "\n(Comando correcto, seccion aun sin implementar) La "
                    "partida seria guardada correctamente.\n";
          } else {
            cout << "\n(Error al guardar, seccion aun sin implementar) La "
                    "partida no seria guardada correctamente.\n";
          }
        } else {
          cout << "\n(Juego no inicializado) Esta partida no ha sido "
                  "inicializada correctamente.\n";
        }
      } else if (comando == "guardar_comprimido <nombre_Archivo>") {
        if (inicializar == true) {
          if (guardarc != false) {
            cout << "\n(Comando correcto, seccion aun sin implementar) La "
                    "partida seria codificada y guardada correctamente.\n";
          } else {
            cout << "\n(Error al codificar y/o guardar , seccion aun sin "
                    "implementar) La partida seria codificada ni guardada "
                    "correctamente.\n";
          }
        } else {
          cout << "\n(Juego no inicializado) Esta partida no ha sido "
                  "inicializada correctamente.\n";
        }
      } else if (comando == "inicializar <nombre_Archivo>") {
        if (inicializar != true) {
          if (cargarc == true) {
            cout
                << "\n(Comando correcto, seccion aun sin implementar) El juego "
                   "se inicializaria correctamente a partir de un archivo.\n";
            inicializar = true;
          } else {
            cout << "\n(Archivo vacÃ­o o incompleto, seccion aun sin "
                    "implementar) "
                    "el archivo no contendria la informaciÃ³n vÃ¡lida para "
                    "inicializar el juego.\n";
          }
        } else {
          cout << "\nEl juego ya ha sido inicializado.\n";
        }
      }

      else if (comando == "costo conquista") {
        if (inicializar == true) {
          if (juegoterminado != true) {
            if (comandoT == true) {
              cout
                  << "\n(Comando correcto, seccion aun sin implementar) Para "
                     "conquistar el territorio <territorio>, debe atacar desde "
                     "<territorio_1>,pasando por los territorios "
                     "<territorio_2>, <territorio_3>, ..., <territorio_m>. "
                     "Debe "
                     "conquistar<n>unidades de ejÃ©rcito.\n";
            }
          } else {
            cout << "\nEsta partida ya tuvo un ganador.\n";
          }
        } else {
          cout << "\nEsta partida no ha sido inicializada correctamente.\n";
        }
      }

      else if (comando == "conquista mas barata") {
        if (inicializar == true) {
          if (juegoterminado != true) {
            if (conquistV != true) {
              cout
                  << "\n(Jugador no vÃ¡lido, seccion aun sin implementar) La "
                     "conquista mÃ¡s barata es avanzar "
                     "sobre el territorio <territorio_1>desde el territorio "
                     "<territorio_2>. Para conquistar el territorio "
                     "<territorio_1>, debe atacardesde <territorio_2>, pasando "
                     "por los territorios <territorio_3>, <territorio_4>, "
                     "...,<territorio_m>. Debe conquistar <n>unidades de "
                     "ejÃ©rcito.\n";
            }
          } else {
            cout << "\n(Juego terminado) Esta partida ya tuvo un ganador.\n";
          }
        } else {
          cout << "\n(Juego no inicializado) Esta partida no ha sido "
                  "inicializada correctamente.\n";
        }
      } else if (comando == "help") {
        impresion();
      } else if (comando == "inicializar help") {
        cout << "\nComando: inicializar\n";
        cout << "\nPosibles salidas:\n";
        cout << "\n(Juego en curso) El juego ya ha sido inicializado.\n";
        cout << "\n(InicializaciÃ³n satisfactoria) El juego se ha inicializado "
                "correctamente.\n";
        cout << "\nDescipcion del conmando:\n";
        cout
            << "\nRealiza las operaciones necesarias para inicializar el "
               "juego, "
               "de acuerdo a las instrucciones entregadas. De esta forma, el "
               "comando deberÃ­a preguntar la cantidad de jugadores, para cada "
               "jugador su nombre o identificador, y luego, por turnos, "
               "preguntar a cada jugador en quÃ© territorio desea ubicar sus "
               "unidades de ejÃ©rcito. En cada turno, el jugador sÃ³lo puede "
               "indicar un Ãºnico territorio a ocupar. En este comando es "
               "clave "
               "utilizar una interfaz adecuada de asignaciÃ³n de territorios "
               "que "
               "sea fÃ¡cil de seguir para los jugadores en pantalla.\n";

      } else if (comando == "turno help") {
        cout << "\nComando: turno <id_jugador>\n";
        cout << "\nPosibles salidas:\n";
        cout
            << "\n(Juego no inicializado) Esta partida no ha sido inicializada "
               "correctamente.\n";
        cout << "\n(Juego terminado) Esta partida ya tuvo un ganador.\n";
        cout << "\n(Jugador no vÃ¡lido) El jugador <id_jugador>no forma parte "
                "de "
                "esta partida.\n";
        cout << "\n(Jugador fuera de turno) No es el turno del jugador "
                "<id_jugador>.\n";
        cout << "\n(Turno terminado correctamente) El turno del jugador "
                "<id_jugador>ha terminado.\n";
        cout << "\nDescipcion del conmando:\n";
        cout
            << "\nRealiza las operaciones descritas dentro del turno de un "
               "jugador (obtener nuevas unidades,atacar y fortificar). De esta "
               "forma, el comando deberÃ­a primero informar al jugador "
               "cuÃ¡ntas "
               "unidades adicionales puede reclamar, para luego preguntarle en "
               "cuÃ¡les de sus territorios las quiere asignar y en quÃ© "
               "cantidad.A continuaciÃ³n, deberÃ­a preguntar la configuraciÃ³n "
               "del "
               "ataque, desde cuÃ¡l territorio y hacia cuÃ¡l "
               "territorio,verificando las condiciones ya descritas. Luego "
               "deberÃ­a informar los valores obtenidos con los dados, y "
               "lacantidad de unidades que se ganan o pierden. Este proceso se "
               "repite hasta que alguno de los dos territoriosse quede sin "
               "unidades, o hasta que el atacante decida detenerse. "
               "Finalmente, "
               "el comando deberÃ­a preguntar al jugador los territorios "
               "vecinos "
               "que desea seleccionar para la fortificaciÃ³n, asÃ­ como la "
               "cantidad de unidadesque se trasladarÃ¡n de uno al otro. De "
               "nuevo, en este comando es clave utilizar una interfaz adecuada "
               "que sea fÃ¡cil de seguir para los jugadores en pantalla.\n";
      } else if (comando == "guardar help") {
        cout << "\nComando: guardar <nombre_archivo>\n";
        cout << "\nPosibles salidas:\n";
        cout << "\n(Juego no inicializado) Esta partida no ha sido "
                "inicializada correctamente.\n";
        cout << "\n(Comando correcto) La partida ha sido guardada "
                "correctamente.\n";
        cout << "\n(Error al guardar) La partida no ha sido guardada "
                "correctamente.\n";
        cout << "\nDescipcion del conmando:\n";
        cout << "\nEl estado actual del juego es guardado en un archivo de "
                "texto. El archivo debe contener lacantidad de jugadores, y "
                "para cada jugador debe almacenar su nombre, su color de "
                "jugador, la cantidadde paÃ­ses que ocupa, el identificador de "
                "cada paÃ­s junto con la cantidad de unidades de ejÃ©rcito en "
                "Ã©l, lacantidad de tarjetas que posee y el identificador de "
                "cada tarjeta. Note que este comando guarda un archivode texto "
                "plano, sin codificaciÃ³n.\n";
      } else if (comando == "guardar_comprimido help") {
        cout << "\nComando: guardar_comprimido <nombre_archivo>\n";
        cout << "\nPosibles salidas:\n";
        cout << "\n(Juego no inicializado) Esta partida no ha sido "
                "inicializada correctamente.\n";
        cout << "\n(Comando correcto) La partida ha sido codificada y guardada "
                "correctamente.\n";
        cout << "\n(Error al codificar y/o guardar) La partida no ha sido "
                "codificada ni guardada correctamente.\n";
        cout << "\nDescipcion del conmando:\n";
        cout
            << "\nEl estado actual del juego es guardado en un archivo "
               "binario (con extensiÃ³n .bin) con lainformaciÃ³n (la misma que "
               "se almacenarÃ­a en un archivo de texto normal, ver comando "
               "guardar) comprimida,utilizando la codificaciÃ³n de Huffman en "
               "el formato descrito mÃ¡s arriba.\n";
      } else if (comando == "inicializar_archivo help") {
        cout << "\nComando: inicializar <nombre_archivo>\n";
        cout << "\nPosibles salidas:\n";
        cout << "\n(Juego en curso) El juego ya ha sido inicializado.\n";
        cout << "\n(Archivo vacÃ­o o incompleto) el archivo no contiene "
                "informaciÃ³n vÃ¡lida para inicializar el juego.\n";
        cout << "\nDescipcion del conmando:\n";
        cout
            << "\nInicializa el juego con los datos contenidos en el archivo "
               "identificado por <nombre_archivo>.El archivo deberÃ­a contener "
               "la informaciÃ³n descrita en el comando guardar. El comando "
               "debe poder inicializar el juego desde un archivo de juego "
               "normal (generado por el comando guardar) o un archivo "
               "binariocon los datos comprimidos (generado por el comando "
               "guardar_comprimido).\n";
      } else if (comando == "costo_conquista help") {
        cout << "\nComando: costo_conquista <territorio>\n";
        cout << "\nPosibles salidas:\n";
        cout << "\n(Juego no inicializado) Esta partida no ha sido "
                "inicializada correctamente.\n";
        cout << "\n(Juego terminado) Esta partida ya tuvo un ganador.\n";
        cout << "\n(Comando correcto) Para conquistar el territorio "
                "<territorio>, debe atacar desde <territorio_1>,pasando por "
                "los territorios <territorio_2>, <territorio_3>, ..., "
                "<territorio_m>. Debe conquistar<n>unidades de ejÃ©rcito.\n";
        cout << "\nDescipcion del conmando:\n";
        cout
            << "\nEl programa debe calcular el costo y la secuencia de "
               "territorios a ser conquistados para lograrcontrolar el "
               "territorio dado por el usuario. El territorio desde donde debe "
               "atacar debe ser aquel que el jugadortenga controlado mÃ¡s "
               "cerca "
               "al dado por el jugador. Esta informaciÃ³n se analiza desde el "
               "punto de vista deljugador que tiene el turno de juego.\n";
      } else if (comando == "conquista_mas_barata help") {
        cout << "\nComando: conquista_mas_barata\n";
        cout << "\nPosibles salidas:\n";
        cout << "\n(Juego no inicializado) Esta partida no ha sido "
                "inicializada correctamente.\n";
        cout << "\n(Juego terminado) Esta partida ya tuvo un ganador.\n";
        cout << "\n(Jugador no vÃ¡lido) La conquista mÃ¡s barata es avanzar "
                "sobre el territorio <territorio_1>desdeel territorio "
                "<territorio_2>. Para conquistar el territorio <territorio_1>, "
                "debe atacardesde <territorio_2>, pasando por los territorios "
                "<territorio_3>, <territorio_4>, ...,<territorio_m>. Debe "
                "conquistar <n>unidades de ejÃ©rcito.\n";
        cout << "\nDescipcion del conmando:\n";
        cout << "\nDe todos los territorios posibles, calcular aquel que pueda "
                "implicar un menor nÃºmero de unidades de ejÃ©rcito perdidas. "
                "Esta informaciÃ³n se analiza desde el punto de vista del "
                "jugador que tiene el turno de juego.\n";
      } else if (comando == "salir help") {
        cout << "\nsalir:\n";
        cout << "\nPosibles salidas:\n";
        cout << "\n(No tiene salida por pantalla)\n";
        cout << "\nDescipcion del conmando:\n";
        cout << "\nTermina la ejecuciÃ³n de la aplicaciÃ³n.\n";
      } else {
        cout << "comando no valido" << endl;
        cout
            << "Para revisar las opciones de comandos disponibles teclee el "
               "comando help o si quiere saber mas de un comando en especifico "
               "teclee <comando> help (sin los diamantes)"
            << endl;
      }
    }
  }
int main() {
    menu();
    return 0;
  }