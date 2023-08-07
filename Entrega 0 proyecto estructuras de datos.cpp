#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace ::std;

int main() {
  string comando;
  int n;
  bool salir=false;
  bool inicializar=false;
  bool juegoterminado=false;
  bool jugadorvalido=true;
  bool turnojugador=true;
  bool cargarc=false;
  bool guardar=false;
  bool guardarc=false;
  bool comandoT=false;
  bool conquistV=false;
  
  transform(comando.begin(), comando.end(), comando.begin(), ::tolower);
  
while(salir==false){
  cout<<"\nInserte el comando\n";
  cout<<"\n[ANOTACION] Si desconoce los comandos escriba help, si quiere saber mas de de la funcionalidad los comandos, ingrese el comando seguido de .help\n";
  cout << "$ ";
  cin>>comando;
  
  switch(n){
    case 1:
      if (comando=="inicializar.help"){
        cout<<"\nComando: inicializar\n";
        cout<<"\nPosibles salidas:\n";
        cout<<"\n(Juego en curso) El juego ya ha sido inicializado.\n";
        cout<<"\n(Inicialización satisfactoria) El juego se ha inicializado correctamente.\n";
        cout<<"\nDescipcion del conmando:\n";
        cout<<"\nRealiza las operaciones necesarias para inicializar el juego, de acuerdo a las instrucciones entregadas. De esta forma, el comando debería preguntar la cantidad de jugadores, para cada jugador su nombre o identificador, y luego, por turnos, preguntar a cada jugador en qué territorio desea ubicar sus unidades de ejército. En cada turno, el jugador sólo puede indicar un único territorio a ocupar. En este comando es clave utilizar una interfaz adecuada de asignación de territorios que sea fácil de seguir para los jugadores en pantalla.\n";
        break; 
      }
      if (comando=="inicializar"){
        if(inicializar==true){
        cout<<"\nEl juego se ha inicializado correctamente.\n";
        inicializar=true;
        
    }else{
        cout<<"\n(Juego en curso) El juego ya ha sido inicializado.\n";
        }
        break;  
      }
    case 2:
      if(comando=="turno.help"){
        cout<<"\nComando: turno <id_jugador>\n";
        cout<<"\nPosibles salidas:\n";
        cout<<"\n(Juego no inicializado) Esta partida no ha sido inicializada correctamente.\n";
        cout<<"\n(Juego terminado) Esta partida ya tuvo un ganador.\n";
        cout<<"\n(Jugador no válido) El jugador <id_jugador>no forma parte de esta partida.\n";
        cout<<"\n(Jugador fuera de turno) No es el turno del jugador <id_jugador>.\n";
        cout<<"\n(Turno terminado correctamente) El turno del jugador <id_jugador>ha terminado.\n";
        cout<<"\nDescipcion del conmando:\n";
        cout<<"\nRealiza las operaciones descritas dentro del turno de un jugador (obtener nuevas unidades,atacar y fortificar). De esta forma, el comando debería primero informar al jugador cuántas unidades adicionales puede reclamar, para luego preguntarle en cuáles de sus territorios las quiere asignar y en qué cantidad.A continuación, debería preguntar la configuración del ataque, desde cuál territorio y hacia cuál territorio,verificando las condiciones ya descritas. Luego debería informar los valores obtenidos con los dados, y lacantidad de unidades que se ganan o pierden. Este proceso se repite hasta que alguno de los dos territoriosse quede sin unidades, o hasta que el atacante decida detenerse. Finalmente, el comando debería preguntar al jugador los territorios vecinos que desea seleccionar para la fortificación, así como la cantidad de unidadesque se trasladarán de uno al otro. De nuevo, en este comando es clave utilizar una interfaz adecuada que sea fácil de seguir para los jugadores en pantalla.\n";
        break;
      }
      if (comando=="turno"){
        if(inicializar==true){
          if(juegoterminado!=true){
              if(jugadorvalido!=false){
                if(turnojugador!=false){
                  cout<<"\nEl turno del jugador <id_jugador> ha terminado.\n";
                }else{
                cout<<"\nNo es el turno del jugador <id_jugador>.\n";  
                }
              }else{
                cout<<"\nEl jugador <id_jugador> no forma parte de esta partida.\n";
              }
          }else{
            cout<<"\nEsta partida ya tuvo un ganador.\n";
          }
        }else{
          cout<<"\nEsta partida no ha sido inicializada correctamente.\n";
        } 
        break;
   }
    case 3:
      if (comando=="guardar.help"){
        cout<<"\nComando: guardar <nombre_archivo>\n";
        cout<<"\nPosibles salidas:\n";
        cout<<"\n(Juego no inicializado) Esta partida no ha sido inicializada correctamente.\n";
        cout<<"\n(Comando correcto) La partida ha sido guardada correctamente.\n";
        cout<<"\n(Error al guardar) La partida no ha sido guardada correctamente.\n";
        cout<<"\nDescipcion del conmando:\n";
        cout<<"\nEl estado actual del juego es guardado en un archivo de texto. El archivo debe contener lacantidad de jugadores, y para cada jugador debe almacenar su nombre, su color de jugador, la cantidadde países que ocupa, el identificador de cada país junto con la cantidad de unidades de ejército en él, lacantidad de tarjetas que posee y el identificador de cada tarjeta. Note que este comando guarda un archivode texto plano, sin codificación.\n";
        break;
    }
      if(comando=="guardar"){
        if(inicializar!=true){
          if(guardar==true){
            cout<<"\n(Comando correcto) La partida ha sido guardada correctamente.\n";
          }else{
            cout<<"\n(Error al guardar) La partida no ha sido guardada correctamente.\n";
          }
        }else{
          cout<<"\n(Juego no inicializado) Esta partida no ha sido inicializada correctamente.\n";
        }
      break;
    }
    case 4:
      if (comando=="guardar_comprimido.help"){
        cout<<"\nComando: guardar_comprimido <nombre_archivo>\n";
        cout<<"\nPosibles salidas:\n";
        cout<<"\n(Juego no inicializado) Esta partida no ha sido inicializada correctamente.\n";
        cout<<"\n(Comando correcto) La partida ha sido codificada y guardada correctamente.\n";
        cout<<"\n(Error al codificar y/o guardar) La partida no ha sido codificada ni guardada correctamente.\n";
        cout<<"\nDescipcion del conmando:\n";
        cout<<"\nEl estado actual del juego es guardado en un archivo binario (con extensión .bin) con lainformación (la misma que se almacenaría en un archivo de texto normal, ver comando guardar) comprimida,utilizando la codificación de Huffman en el formato descrito más arriba.\n";
        break;
    }
      if (comando=="guardar_comprimido"){
        if(inicializar==true){
          if(guardarc!=false){
            cout<<"\n(Comando correcto) La partida ha sido codificada y guardada correctamente.\n";
          }else{
            cout<<"\n(Error al codificar y/o guardar) La partida no ha sido codificada ni guardada correctamente.\n";
          }
        }
        break;
    }
    case 5:
      if(comando=="inicializar_archivo.help"){
        cout<<"\nComando: inicializar <nombre_archivo>\n";
        cout<<"\nPosibles salidas:\n";
        cout<<"\n(Juego en curso) El juego ya ha sido inicializado.\n";
        cout<<"\n(Archivo vacío o incompleto) el archivo no contiene información válida para inicializar el juego.\n";
        cout<<"\nDescipcion del conmando:\n";
        cout<<"\nInicializa el juego con los datos contenidos en el archivo identificado por <nombre_archivo>.El archivo debería contener la información descrita en el comando guardar. El comando debe poder inicializar el juego desde un archivo de juego normal (generado por el comando guardar) o un archivo binariocon los datos comprimidos (generado por el comando guardar_comprimido).\n";
        break;
    }
      if(comando=="inicializar <nombre_archivo>"){
        if(inicializar!=true){
          if(cargarc==true){
            cout<<"\nEl juego se ha inicializado correctamente.\n";
            inicializar=true;
          }else{
            cout<<"\n(Archivo vacío o incompleto) el archivo no contiene información válida para inicializar el juego.\n";
          }
        }else{
          cout<<"\nEl juego ya ha sido inicializado.\n";
        }
        break;
    }
    case 6:
      if(comando=="costo_conquista.help"){
        cout<<"\nComando: costo_conquista <territorio>\n";
        cout<<"\nPosibles salidas:\n";
        cout<<"\n(Juego no inicializado) Esta partida no ha sido inicializada correctamente.\n";
        cout<<"\n(Juego terminado) Esta partida ya tuvo un ganador.\n";
        cout<<"\n(Comando correcto) Para conquistar el territorio <territorio>, debe atacar desde <territorio_1>,pasando por los territorios <territorio_2>, <territorio_3>, ..., <territorio_m>. Debe conquistar<n>unidades de ejército.\n";
        cout<<"\nDescipcion del conmando:\n";
        cout<<"\nEl programa debe calcular el costo y la secuencia de territorios a ser conquistados para lograrcontrolar el territorio dado por el usuario. El territorio desde donde debe atacar debe ser aquel que el jugadortenga controlado más cerca al dado por el jugador. Esta información se analiza desde el punto de vista deljugador que tiene el turno de juego.\n";
        break;
    }
      if(comando=="costo_conquista <territorio>"){
        if(inicializar==true){
          if(juegoterminado!=true){
            if(comandoT==true){
              cout<<"\n(Comando correcto) Para conquistar el territorio <territorio>, debe atacar desde <territorio_1>,pasando por los territorios <territorio_2>, <territorio_3>, ..., <territorio_m>. Debe conquistar<n>unidades de ejército.\n";
            }
          }else{
            cout<<"\nEsta partida ya tuvo un ganador.\n";
          }
        }else{
          cout<<"\nEsta partida no ha sido inicializada correctamente.\n";
        }
        break;
    }
    case 7:
      if(comando=="conquista_mas_barata.help"){
        cout<<"\nComando: conquista_mas_barata\n";
        cout<<"\nPosibles salidas:\n";
        cout<<"\n(Juego no inicializado) Esta partida no ha sido inicializada correctamente.\n";
        cout<<"\n(Juego terminado) Esta partida ya tuvo un ganador.\n";
        cout<<"\n(Jugador no válido) La conquista más barata es avanzar sobre el territorio <territorio_1>desdeel territorio <territorio_2>. Para conquistar el territorio <territorio_1>, debe atacardesde <territorio_2>, pasando por los territorios <territorio_3>, <territorio_4>, ...,<territorio_m>. Debe conquistar <n>unidades de ejército.\n";
        cout<<"\nDescipcion del conmando:\n";
        cout<<"\nDe todos los territorios posibles, calcular aquel que pueda implicar un menor número de unidades de ejército perdidas. Esta información se analiza desde el punto de vista del jugador que tiene el turno de juego.\n";
        break;
    }
      if(comando=="conquista_mas_barata"){
        if(inicializar==true){
          if(juegoterminado!=true){
            if(conquistV!=true){
              cout<<"\n(Jugador no válido) La conquista más barata es avanzar sobre el territorio <territorio_1>desdeel territorio <territorio_2>. Para conquistar el territorio <territorio_1>, debe atacardesde <territorio_2>, pasando por los territorios <territorio_3>, <territorio_4>, ...,<territorio_m>. Debe conquistar <n>unidades de ejército.\n";
            }
          }else{
            cout<<"\n(Juego terminado) Esta partida ya tuvo un ganador.\n";
          }
        }else{
          cout<<"\n(Juego no inicializado) Esta partida no ha sido inicializada correctamente.\n";
        }
        break;
      }
    case 8:
      if(comando=="salir.help"){
        cout<<"\nsalir:\n";
        cout<<"\nPosibles salidas:\n";
        cout<<"\n(No tiene salida por pantalla)\n";
        cout<<"\nDescipcion del conmando:\n";
        cout<<"\nTermina la ejecución de la aplicación.\n";
        break;
      }
      if(comando == "salir"){
        cout<<"saliendo...";
        salir=true;
        break;
    }
    case 9:
      if(comando =="help"){
        cout<<"\nLista de comandos:\n";cout<<"inicializar"<<endl;cout<<"turno <id_jugador>"<<endl;cout<<"guardar <nombre_archivo>"<<endl;cout<<"guardar_comprimido <nombre_archivo>"<<endl;cout<<"inicializar <nombre_archivo>"<<endl;cout<<"costo_conquista <territorio>"<<endl;cout<<"conquista_mas_barata"<<endl;cout<<"salir"<<endl;cout<<"\n[IMPORTANTE] Notese que los siguientes comandos terminados en .help indican la salida por pantalla y la respectiva descripcion del comando:\n";cout<<"inicializar.help"<<endl;cout<<"turno.help"<<endl;cout<<"guardar.help"<<endl;cout<<"guardar_comprimido.help"<<endl;cout<<"inicializar_archivo.help"<<endl;cout<<"costo_conquista.help"<<endl;cout<<"conquista_mas_barata.help"<<endl;cout<<"salir.help"<<endl;
        break;
      }
    default:
    cout << "Opción no válida." << endl;
    cout << "Para revisar las opciones teclee el comando help" << endl;
    break;
  }
 } 
}  