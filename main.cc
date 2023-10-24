#include "maze.h"


int main() {
  Maze maze("M_1.txt");
  Cell* cell = maze.algoritmo_A();
  cout << cell->get_fn() << endl;
  //maze.print_file();
}