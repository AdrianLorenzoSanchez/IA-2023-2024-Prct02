#include <fstream>
#include <vector>
#include <set>

#include "cell.h"

#pragma ONCE

using namespace std;

class Maze {
 private:
  string file_;                 // Fichero laberinto
  vector<vector<char>> maze_;   // Estructura para almacenar laberinto
  pair<int, int> start_;        // Coordenadas salida       
  pair<int, int> finish_;       // Coordenadas meta
  int generated_nodes_;
  int inspected_nodes_;



 public:
  Maze(string file);
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

  
  
  
  float distancia_manhattan(int x, int y);
  void print_file(Cell* meta);
};