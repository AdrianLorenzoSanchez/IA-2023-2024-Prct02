#include "cell.h"


Cell::Cell(int x, int y, float gn, float hn, float fn, Cell* parent) {
  x_ = x;
  y_ = y;
  gn_ = gn;
  hn_ = hn;
  fn_ = fn;
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
Cell* Cell::get_parent() {
  return parent_;
}

void Cell::set_gn(float gn) {
  gn_ = gn;
}
void Cell::set_hn(float hn) {
  hn_ = hn;
}

void Cell::set_fn(float fn) {
  fn_ = fn;
}

void Cell::set_parent(Cell* parent) {
  parent_ = parent;
}




