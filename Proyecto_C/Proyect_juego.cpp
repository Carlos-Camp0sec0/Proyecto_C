#include <iostream>
#include <string>
using namespace std;

void graficos(int x){
    for (int i = 0; i < x; i++) {
        cout << char(219);
    }
    cout << endl;
}



void partida() {
    string jugador1, jugador2;
    int puntos_jugador1 = 0, puntos_jugador2 = 0;
    int jugador = 1;
    int fila1 = 3, fila2 = 5, fila3 = 7, fila = 0, piezas_q;
    int i = 4;
    bool fin = false;

    cout << "Ingrese el nombre del jugador 1: ";
    cin >> jugador1;
    cout << "Ingrese el nombre del jugador 2: ";
    cin >> jugador2;

    while (i >= 1 && !fin) {
        graficos(fila1);
        graficos(fila2);
        graficos(fila3);

        cout << "Turno del jugador " << jugador << endl;
        cout << "Objetos en la fila 1: " << fila1 << endl;
        cout << "Objetos en la fila 2: " << fila2 << endl;
        cout << "Objetos en la fila 3: " << fila3 << endl;

        cout << "Escoja la fila (1-3): ";
        cin >> fila;
        while (fila < 1 || fila > 3) {
            cout << "Opción inválida, escoja la fila (1-3): ";
            cin >> fila;
        }

        cout << "Escoja un número de piezas: ";
        cin >> piezas_q;
        while (piezas_q < 1 || piezas_q > fila1 && fila == 1 || piezas_q > fila2 && fila == 2 ||
               piezas_q > fila3 && fila == 3) {
            cout << "Opción inválida, escoja un número de piezas: ";
            cin >> piezas_q;
        }

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

        if (fila1 == 0 && fila2 == 0 && fila3 == 1) {
            cout << "El jugador " << jugador << " pierde." << endl;
            if (jugador == 1) {
                puntos_jugador2 += 3;
            } else {
                puntos_jugador1 += 3;
            }
            fin = true;
        } else if (fila1 == 0 && fila2 == 1 && fila3 == 0) {
            cout << "El jugador " << jugador << " pierde." << endl;
            if (jugador == 1) {
                puntos_jugador2 += 3;
            } else {
                puntos_jugador1 += 3;
            }
            fin = true;
        } else if (fila1 == 1 && fila2 == 0 && fila3 == 0) {
            cout << "El jugador " << jugador << " pierde." << endl;
            if (jugador == 1) {
                puntos_jugador2 += 3;
            } else {
                puntos_jugador1 += 3;
            }
            fin = true;
        } else if (fila1 == 0 && fila2 == 1 && fila3 == 0) {
            cout << "El jugador " << jugador << " pierde." << endl;
            if (jugador == 1) {
                puntos_jugador2 += 3;
            } else {
                puntos_jugador1 += 3;
            }
            fin = true;
        } else if (fila1 == 1 && fila2 == 0 && fila3 == 0) {
            cout << "El jugador " << jugador << " pierde." << endl;
            if (jugador == 1) {
                puntos_jugador2 += 3;
            } else {
                puntos_jugador1 += 3;
            }
            fin = true;
        } else if (fila1 == 0 && fila2 == 0 && fila3 == 0) {
            cout << "Empate." << endl;
            puntos_jugador1 += 1;
            puntos_jugador2 += 1;
            fin = true;
        }
        if (!fin) {
            if (jugador == 1) {
                jugador = 2;
            } else {
                jugador = 1;
            }
        }

        cout << endl;
    }

    cout << "Jugador " << jugador1 << " tiene " << puntos_jugador1 << " puntos." << endl;
    cout << "Jugador " << jugador2 << " tiene " << puntos_jugador2 << " puntos." << endl;

    
    if (puntos_jugador1 > puntos_jugador2) {
        cout << "¡Felicitaciones " << jugador1 << ", has ganado el juego!" << endl;
    } else if (puntos_jugador2 > puntos_jugador1) {
        cout << "¡Felicitaciones " << jugador2 << ", has ganado el juego!" << endl;
    } else if (puntos_jugador2 == puntos_jugador1){
        cout << "¡El juego ha terminado en empate!" << endl;
    }

}



 int main(){
    partida();
    // preguntar si se desea jugar otra ronda
    char jugar_otra;
    cout << "¿Desea jugar otra ronda? (s/n): ";
    cin >> jugar_otra;
    if (jugar_otra == 's') {
        // reiniciar variables para una nueva ronda
        partida();
    } else if (jugar_otra == 'n'){
        // finalizar juego
        cout << "Gracias por jugar!" << endl;
    }
    return 0;
}
