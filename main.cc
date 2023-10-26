#include "maze.h"


int main() {

  int heuristica;
  string fichero;
  char opcion;

  while (heuristica != 0) {
    cout << "Fichero_entrada: " ; cin >> fichero;
    cout << "Heuristica: " << endl << "0 -> Salir" << endl << "1 -> Manhattan" << endl << "2 -> Euclidia" << endl;
    cin >> heuristica;

    if (heuristica != 0) {
      Maze maze(fichero, heuristica);
      cout << "Nueva entrada salida? (y/n):  "; cin >> opcion;
      if (opcion == 'y') {
        int x1, y1, x2, y2;
        cout << "Entrada: "; cin >> x1 >> y1;
        cout << "Salida: "; cin >> x2 >> y2;
        maze.cambiar_entrada_salida(x1, y1, x2, y2);
      }
      Cell* cell = maze.algoritmo_A();
      maze.print_file(cell);

    }

  }
}

