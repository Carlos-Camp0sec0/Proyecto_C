/* Las líneas anteriores son las declaraciones de las bibliotecas de C++ que se utilizarán en el
programa, en este caso "iostream" y "string". La línea using namespace std indica que se usará el espacio de nombres "std"
de la biblioteca estándar de C++, que es la que contiene los elementos básicos del lenguaje. */
#include <iostream>
#include <string>
using namespace std;

/* Estas líneas declaran dos variables enteras, puntos_jugador1f y puntos_jugador2f,
inicializadas con valor cero. Estas variables almacenarán los puntos que acumule cada jugador durante el juego. */
int puntos_jugador1f=0,puntos_jugador2f=0;
/* Esta es una función llamada "graficos" que recibe como parámetro un entero x. Esta función se encarga de dibujar una línea
horizontal de caracteres ASCII en la consola, en este caso utilizando el carácter "219", que representa un cuadrado en la tabla ASCII. */
void graficos(int x){
    for (int i = 0; i < x; i++) {
        cout << char(219)<< " ";
    }
    cout << endl;
}
/*Esta es una función llamada "puntos" que recibe dos enteros x e y. Esta función se encarga de sumar los valores de x y
 y a las variables globales puntos_jugador1f y puntos_jugador2f, respectivamente. Esas variables acumulan los puntos de cada jugador. */
void puntos (int x, int y){
    extern int puntos_jugador1f, puntos_jugador2f;
    puntos_jugador1f+=x;
    puntos_jugador2f+=y;
}
/* Esta es una función llamada "partida" que recibe dos strings, jugador1 y jugador2, que representan los nombres de los jugadores.*/
void partida(string jugador1, string jugador2) {
    /* Esta línea imprime en la consola los puntos acumulados por cada jugador hasta el momento. */
    cout<<"El jugador 1 tiene: "<<puntos_jugador1f<<" puntos."<<endl<<"El jugador 2 tiene: "<<puntos_jugador2f<<" puntos."<<endl;
    /* Estas líneas declaran dos variables enteras, puntos_jugador1 y puntos_jugador2, inicializadas con valor cero.
     Estas variables almacenarán los puntos que acumule cada jugador durante la partida actual. */
    int puntos_jugador1 = 0, puntos_jugador2 = 0;
    int jugador = 1;
    /* numero de piezas */
    int fila1 = 3, fila2 = 5, fila3 = 7, fila = 0, piezas_q;
    int i = 4;
/* una variable booleana llamada "fin" e inicializa su valor en falso. La variable "fin" se utiliza más adelante en el código
 para controlar el bucle while y determinar cuándo debe finalizar el juego. */
    bool fin = false;

/* un bucle while que se ejecuta mientras la variable i sea mayor o igual a 1 y la variable fin sea falsa. Dentro del bucle
 se llaman a varias funciones graficos.  */
    while (i >= 1 && !fin) {
        /* se encarga de mostrar en la pantalla las representaciones gráficas de las tres filas en el juego,
         El cout<<endl es para agregar un salto de línea después de cada representación gráfica, de modo que las filas se muestren
         correctamente una debajo de la otra. */
        graficos(fila1); cout<<endl;
        graficos(fila2); cout<<endl;
        graficos(fila3); cout<<endl;
/* Se muestra información sobre el estado actual de tres filas (fila1, fila2 y fila3), y el turno correspondiente  */
        cout << "Turno del jugador " << jugador << endl;
        cout << "Objetos en la fila 1: " << fila1 << endl;
        cout << "Objetos en la fila 2: " << fila2 << endl;
        cout << "Objetos en la fila 3: " << fila3 << endl;
/* Luego se solicita al usuario que elija una fila (1, 2 o 3) y un número de piezas de esa fila. */
       
		cout << "Escoja la fila (1-3): ";
        cin >> fila;
 /* Se verifica que la fila seleccionada esté dentro del rango válido (1-3). Si la entrada es inválida, se le pide al usuario
 que vuelva a ingresar una fila válida. */
 		while ((fila==1&&fila1==0)||(fila==2&&fila2==0)||(fila==3&&fila3==0)){
		 cout <<endl<<"opcion invalida, escoja la fila (1-3): ";
            cin >> fila;}
        while (fila < 1 || fila > 3) {
            cout <<endl<<"opcion invalida, escoja la fila (1-3): ";
            cin >> fila;
        }
        cout << "Escoja un numero de piezas: ";
        cin >> piezas_q;
/* Se verifica que la cantidad de piezas seleccionadas esté dentro del rango válido para la fila seleccionada. Si la entrada
 es inválida, se le pide al usuario que vuelva a ingresar una cantidad de piezas válida. Si la fila seleccionada es 1, se verifica
 que la cantidad de piezas seleccionadas no sea mayor que la cantidad de objetos en la fila 1, y lo mismo para las filas 2 y 3. */
        while (piezas_q < 1 || piezas_q > fila1 && fila == 1 || piezas_q > fila2 && fila == 2 ||
               piezas_q > fila3 && fila == 3) {
            cout << "opcion invalida, escoja un numero de piezas: ";
            cin >> piezas_q;
        }
/* Este código está utilizando una sentencia switch para actualizar el número de objetos en la fila seleccionada por el jugador.
 La variable fila contiene el número de fila seleccionada, y la variable piezas_q contiene el número de objetos que el jugador
 desea eliminar de esa fila. Dependiendo del valor de fila, el código actualizará la cantidad correcta de objetos en la fila correspondiente (fila1, fila2, o fila3). */
        switch (fila) {
            case 1:
                fila1 -= piezas_q;
                break;
            case 2:
                fila2 -= piezas_q;
                break;
            case 3:
                fila3 -= piezas_q;
                break;
        }
/* verifica si alguna de las tres filas tiene solo una pieza, lo que significa que el jugador actual no tiene más opciones
 * para tomar piezas y, por lo tanto, pierde el juego. Si una fila tiene solo una pieza, se muestra un mensaje que indica
 * que el jugador actual pierde y se le otorgan 3 puntos al otro jugador. Luego, la variable "fin" se establece en true para indicar que el juego ha terminado. */
        if (fila1 ==1 ||  fila2 == 1 || fila3 == 1) {
            cout << "El jugador " << jugador << " pierde." << endl;
            if (jugador == 1) {
                puntos_jugador2 += 3;
            } else {
                puntos_jugador1 += 3;
            }
            fin = true;
/* verifica si todas las filas están vacías, es decir, no tienen ninguna pieza. En ese caso, se considera un empate.
Se muestra un mensaje indicando el empate y se otorga 1 punto a cada jugador. Luego, la variable "fin" se establece en true para indicar que el juego ha terminado. */
        } else if (fila1 == 0 && fila2 == 0 && fila3 == 0) {
            cout << "Empate." << endl;
            puntos_jugador1 += 1;
            puntos_jugador2 += 1;
            fin = true;
        }
/* Comienza comprobando si la variable "fin" es falsa, lo que significa que el juego aún no ha terminado. Si es así, cambia el
 turno del jugador actual. Si el jugador actual es el jugador 1, se cambia a 2 y viceversa. */
        if (!fin) {
            if (jugador == 1) {
                jugador = 2;
            } else {
                jugador = 1;
            }
        }

        cout << endl;
    }
/* el bucle while ha terminado y el juego ha finalizado, se llama a la función "puntos" pasando como argumentos las variables
"puntos_jugador1" y "puntos_jugador2". Esto actualiza los puntos totales de cada jugador al sumar los puntos obtenidos en la partida recién jugada. */
    puntos(puntos_jugador1,puntos_jugador2);

}

int main(){
    string jugador1, jugador2;
    cout << "Ingrese el nombre del jugador 1: ";
    cin >> jugador1;
    cout << "Ingrese el nombre del jugador 2: ";
    cin >> jugador2;

    partida(jugador1, jugador2);
    // preguntar si se desea jugar otra ronda

    char jugar_otra;
    cout << "¿Desea jugar otra ronda? (s/n): ";
    cin >> jugar_otra;
    while (jugar_otra=='s'){

        if (jugar_otra == 's') {
            // reiniciar variables para una nueva ronda
            partida(jugador1, jugador2);
            cout << "¿Desea jugar otra ronda? (s/n): ";
            cin >> jugar_otra;
        } else if (jugar_otra == 'n'){
            // finalizar juego
            cout << "Gracias por jugar!" << endl;
        }
    }
    cout<<"El jugador 1 tiene: "<<puntos_jugador1f<<" puntos."<<endl<<"El jugador 2 tiene: "<<puntos_jugador2f<<" puntos."<<endl;
    if (puntos_jugador1f > puntos_jugador2f) {
        cout << "¡Felicitaciones " << jugador1 << ", has ganado el juego!" << endl;
    } else if (puntos_jugador2f > puntos_jugador1f) {
        cout << "¡Felicitaciones " << jugador2 << ", has ganado el juego!" << endl;
    } else if (puntos_jugador2f == puntos_jugador1f){
        cout << "¡El juego ha terminado en empate!" << endl;
    }
    return 0;
}
