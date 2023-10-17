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




 public:
  Maze(string file);
  void algoritmo();
  void print_file();
};