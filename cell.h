#include <iostream>

#pragma ONCE

using namespace std;

class Cell {
 private:
  int x_;
  int y_;  
  float gn_;
  float hn_;  
  float fn_;  
  Cell* parent_;


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

  

  //friend bool operator< (const Cell right, const Cell left); 
};

/*bool operator< (const Cell left, const Cell right) {
  return (left.fn_ < right.fn_);
}

struct Comp {
    bool operator()(const Cell* a, const Cell* b)
    {
        if (a && b)
        {
            return *a < *b;
        }
        return a<b;
    }
};*/