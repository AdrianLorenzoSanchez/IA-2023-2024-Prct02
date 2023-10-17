#include <iostream>

#pragma ONCE

using namespace std;

class Cell {
 private:
  pair<int, int> pos_;  // Posicion (x,y) laberinto
  float cost_;    
  Cell* parent_;


 public:        
  Cell(int x, int y, float cost);

  float get_cost();

  bool operator< (Cell* cell) {
    return (cost_ < cell->get_cost());
  }
  
};