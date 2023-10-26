#include <fstream>
#include <vector>
#include <set>
#include <cmath>

#include "cell.h"

#pragma ONCE

using namespace std;

class Maze {
 private:
  string file_;                 // Fichero laberinto
  vector<vector<char>> maze_;   // Estructura para almacenar laberinto
  pair<int, int> start_;        // Coordenadas salida       
  pair<int, int> finish_;       // Coordenadas meta
  int generated_nodes_;         // Nodos generados
  int inspected_nodes_;         // Nodos inspeccionados
  int heuristica_;              // Tipo heuristica



 public:
  Maze(string file, int heuristica);
  Cell* algoritmo_A();
  void generar_hijos(Cell* actual, vector<Cell*>& abiertos, vector<Cell*>& cerrados);
  int comprobar_conjunto(int x, int y, vector<Cell*>& conjunto);

  bool check_norte(Cell* actual);
  bool check_sur(Cell* actual);
  bool check_este(Cell* actual);
  bool check_oeste(Cell* actual);
  bool check_noreste(Cell* actual);
  bool check_noroeste(Cell* actual);
  bool check_sureste(Cell* actual);
  bool check_suroeste(Cell* actual);

  
  void cambiar_entrada_salida(int x1, int y1, int x2, int y2);
  float heuristica(int x, int y);
  float distancia_manhattan(int x, int y);
  float distancia_euclidia(int x, int y);
  void print_file(Cell* meta);
};