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

  friend bool operator< (const Cell right, const Cell left); 
};

struct Comp {
    bool operator()(const Cell* a, const Cell* b)
    {
        if (a && b)
        {
            return *a < *b;
        }
        return a<b;
    }
};