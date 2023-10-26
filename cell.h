#include <iostream>

#pragma ONCE

using namespace std;

class Cell {
 private:
  int x_;         // Posicion x del laberinto
  int y_;         // Posicion y del laberinto
  float gn_;      // Coste gn del nodo
  float hn_;      // Coste hn del nodo
  float fn_;      // Coste fn del nodo
  Cell* parent_;  // Puntero al padre del nodo


 public:        
  Cell(int x, int y, float gn, float hn, float fn, Cell* parent);

  int get_x();
  int get_y();
  float get_gn();
  float get_hn();
  float get_fn();
  Cell* get_parent();

  void set_gn(float gn);
  void set_hn(float hn);
  void set_fn(float fn);
  void set_parent(Cell* parent);

  
};

