#include "maze.h"


Maze::Maze(string file) {

  // Lectura de fichero
  file_ = file;

  int rows, cols;
  ifstream fin;
  
  fin.open(file);
  fin >> rows >> cols;

  maze_.resize(rows);
  for (int i=0; i<maze_.size(); i++) 
    maze_[i].resize(cols); 

  for (int i=0; i<rows; i++) {
    for (int j=0; j<cols; j++) {
      fin >> maze_[i][j];

      if (maze_[i][j] == '3') {
        start_.first = i; start_.second = j;
      }
      else if (maze_[i][j] == '4') {
        finish_.first = i; finish_.second = j;
      }
    }
  }

  fin.close();
  
}


void Maze::algoritmo() {
  
  vector<Cell*> close;
  set<Cell*, Comp> open;

  Cell* aux2 = new Cell(start_.first, start_.second, 2);
  Cell* aux1 = new Cell(start_.first, start_.second, 1);
  Cell* aux3 = new Cell(start_.first, start_.second, 3);
  Cell* aux4 = new Cell(start_.first, start_.second, 4);
  Cell* aux0 = new Cell(start_.first, start_.second, 0);

  open.insert(aux3);
  open.insert(aux4);
  for (Cell* cell : open) {
    cout << cell->get_cost() << endl;
  } 

  open.insert(aux1); 
  open.insert(aux2);
  cout << endl;
  for (Cell* cell : open) {
    cout << cell->get_cost() << endl;
  }

  open.insert(aux0);
  cout << endl;
  for (Cell* cell : open) {
    cout << cell->get_cost() << endl;
  }
  
  

  
}



void Maze::print_file() {
  for (int i=0; i<maze_.size(); i++) {
    for (int j=0; j<maze_[i].size(); j++) 
      cout << maze_[i][j] << " ";
    cout << endl;
  }
  cout << "(" << start_.first << "," << start_.second << ")" << endl;
  cout << "(" << finish_.first << "," << finish_.second << ")" << endl;
}



