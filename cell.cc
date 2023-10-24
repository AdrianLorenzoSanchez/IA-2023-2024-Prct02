#include "cell.h"


Cell::Cell(int x, int y, Cell* parent) {
  x_ = x;
  y_ = y;
  parent_ = parent;

}

int Cell::get_x() {
  return x_;
} 
int Cell::get_y() {
  return y_;
} 
float Cell::get_gn() {
  return gn_;
}
float Cell::get_hn() {
  return hn_;
}
float Cell::get_fn() {
  return fn_;
}


void Cell::set_gn(float gn) {
  gn_ = gn;
}
void Cell::set_hn(float hn) {
  hn_ = hn;
}

void Cell::set_fn() {
  fn_ = gn_ + hn_;
}




