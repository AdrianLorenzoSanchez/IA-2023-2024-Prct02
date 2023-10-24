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


Cell* Maze::algoritmo_A() {
  
  vector<Cell*> close;    // Conjunto de nodos cerrados
  vector<Cell*> frontera;     // Conjunto de nodos abiertos

  Cell* actual = new Cell(start_.first, start_.second, NULL);
  actual->set_gn(0);
  actual->set_hn(distancia_manhattan(actual));
  actual->set_fn();

  frontera.push_back(actual);

  while (!frontera.empty()) {
    
    // Obtener mejor nodo y removerlo del vector
    actual = frontera[0];
    int min_pos = 0;
    for (int i = 0; i < frontera.size(); i++) {
        if (frontera[i]->get_fn() < actual->get_fn()) {
          actual = frontera[i];
          min_pos = i;
        }
    }
    frontera.erase(frontera.begin() + min_pos);

    // Prueba de meta
    if ((actual->get_x() == finish_.first) && (actual->get_y() == finish_.second))
      return actual;

    generar_hijos(actual, frontera);


  }
  
  // Si no hay solucion devuelve el nodo con coste -1
  actual->set_gn(-1);
  return actual;
  
}

void Maze::generar_hijos(Cell* actual, vector<Cell*>& frontera) {

    int salida; // variable resultado del metodo comprobar_frontera()
    if (check_norte(actual)) {
      salida = comprobar_frontera(actual, frontera);
      if (salida == - 1) {
         
      }
      else {
        // Comprobamos si su fn es menor
      }
    }

    if (check_sur(actual)) {
      salida = comprobar_frontera(actual, frontera);
      if (salida == - 1) {
         
      }
      else {
        // Comprobamos si su fn es menor
      }    
    }
    if (check_este(actual)) {
      salida = comprobar_frontera(actual, frontera);
      if (salida == - 1) {
         
      }
      else {
        // Comprobamos si su fn es menor
      }  
    }
    if (check_oeste(actual)) {
      salida = comprobar_frontera(actual, frontera);
      if (salida == - 1) {
         
      }
      else {
        // Comprobamos si su fn es menor
      }     
    }
    if (check_noreste(actual)) {
      salida = comprobar_frontera(actual, frontera);
      if (salida == - 1) {
         
      }
      else {
        // Comprobamos si su fn es menor
      }     
    }
    if (check_noroeste(actual)) {
      salida = comprobar_frontera(actual, frontera);
      if (salida == - 1) {
         
      }
      else {
        // Comprobamos si su fn es menor
      }    
    }
    if (check_sureste(actual)) {
      salida = comprobar_frontera(actual, frontera);
      if (salida == - 1) {
         
      }
      else {
        // Comprobamos si su fn es menor
      }      
    }
    if (check_suroeste(actual)) {
      salida = comprobar_frontera(actual, frontera);
      if (salida == - 1) {
         
      }
      else {
        // Comprobamos si su fn es menor
      }     
    }
}

int Maze::comprobar_frontera(Cell* actual, vector<Cell*>& frontera) {

  int pos_x = actual->get_x();
  int pos_y = actual->get_y();

  for (int i = 0; i < frontera.size(); i++) {
    if (pos_x == frontera[i]->get_x() && pos_y == frontera[i]->get_y())
      return i;
  }

  return -1;
}

bool Maze::check_norte(Cell* actual) {

  int pos_x = actual->get_x();
  int pos_y = actual->get_y();

  // Comprobacion borde superior
  if (pos_x == 0)
    return false;

  // Comprobación muro
  if (maze_[pos_x-1][pos_y] == '1')
    return false;
  
  return true;
}

bool Maze::check_sur(Cell* actual) {

  int pos_x = actual->get_x();
  int pos_y = actual->get_y();

  // Comprobacion borde inferior
  if (pos_x == maze_.size()-1)
    return false;

  // Comprobación muro
  if (maze_[pos_x+1][pos_y] == '1')
    return false;
  
  return true;
}

bool Maze::check_este(Cell* actual) {

  int pos_x = actual->get_x();
  int pos_y = actual->get_y();

  // Comprobacion borde derecho
  if (pos_y == maze_[pos_x].size()-1)
    return false;

  // Comprobación muro
  if (maze_[pos_x][pos_y+1] == '1')
    return false;
  
  return true;
}

bool Maze::check_oeste(Cell* actual) {

  int pos_x = actual->get_x();
  int pos_y = actual->get_y();

  // Comprobacion borde izquierdo
  if (pos_y == 0)
    return false;

  // Comprobación muro
  if (maze_[pos_x][pos_y-1] == '1')
    return false;
  
  return true;
}

bool Maze::check_noreste(Cell* actual) {

  int pos_x = actual->get_x();
  int pos_y = actual->get_y();
  // Comprobacion borde superior y derecho
  if (pos_x == 0 && pos_y == maze_[pos_x].size()-1)
    return false;

  // Comprobación muro
  if (maze_[pos_x+1][pos_y+1] == '1')
    return false;
  
  return true;
}

bool Maze::check_noroeste(Cell* actual) {

  int pos_x = actual->get_x();
  int pos_y = actual->get_y();

  // Comprobacion borde superior e izquierdo
  if (pos_x == 0 && pos_y == 0)
    return false;

  // Comprobación muro
  if (maze_[pos_x-1][pos_y-1] == '1')
    return false;
  
  return true;
}

bool Maze::check_sureste(Cell* actual) {

  int pos_x = actual->get_x();
  int pos_y = actual->get_y();

  // Comprobacion borde inferior y derecho
  if (pos_x == maze_.size()-1 && pos_y == maze_[pos_x].size()-1)
    return false;

  // Comprobación muro
  if (maze_[pos_x-1][pos_y+1] == '1')
    return false;
  
  return true;
}

bool Maze::check_suroeste(Cell* actual) {

  int pos_x = actual->get_x();
  int pos_y = actual->get_y();

  // Comprobacion borde inferior e izquierdo
  if (pos_x == maze_.size()-1 && pos_y == 0)
    return false;

  // Comprobación muro
  if (maze_[pos_x+1][pos_y-1] == '1')
    return false;
  
  return true;
}




float Maze::distancia_manhattan(Cell* actual) {
  return (abs(finish_.first-actual->get_x() + abs(finish_.second-actual->get_y())) * 3);
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



