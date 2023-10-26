#include "maze.h"


int main() {
  Maze maze("M_1.txt");
  Cell* cell = maze.algoritmo_A();
  maze.print_file(cell);
}

