#include "cell.h"


Cell::Cell(int x, int y, float cost) {
  pos_.first = x;
  pos_.second = y;
  cost_ = cost;
}

float Cell::get_cost() {
  return cost_;
}

bool operator< (const Cell left, const Cell right) {
  return (left.cost_ < right.cost_);
}
