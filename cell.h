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
  Cell(int x, int y, Cell* parent);

  int get_x();
  int get_y();
  float get_gn();
  float get_hn();
  float get_fn();

  void set_gn(float gn);
  void set_hn(float hn);
  void set_fn();

  

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