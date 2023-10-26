#include "maze.h"


Maze::Maze(string file, int heuristica) {

  // Lectura de fichero
  file_ = file;
  heuristica_ = heuristica;

  generated_nodes_ = 0;
  inspected_nodes_ = 0;

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
  
  vector<Cell*> cerrados;     // Conjunto de nodos cerrados
  vector<Cell*> abiertos;     // Conjunto de nodos abiertos

  // Evaluamos el nodo raiz y lo metemosen el conjunto de nodos abiertos
  int hn = distancia_manhattan(start_.first, start_.second);
  Cell* actual = new Cell(start_.first, start_.second, 0, hn, hn, NULL);
  abiertos.push_back(actual);
  generated_nodes_++; // Aumentamos contador generados

  while (!abiertos.empty()) {
    
    // Obtener mejor nodo de los abiertos y removerlo del vector
    actual = abiertos[0];
    int min_pos = 0;
    for (int i = 0; i < abiertos.size(); i++) {
        if (abiertos[i]->get_fn() < actual->get_fn()) {
          actual = abiertos[i];
          min_pos = i;
        }
    }
    abiertos.erase(abiertos.begin() + min_pos);


    // Añadir nodo actual a los cerrados y prueba de meta
    cerrados.push_back(actual);
    inspected_nodes_++; // Aumentamos el contador de inspeccionados 
    if ((actual->get_x() == finish_.first) && (actual->get_y() == finish_.second)) 
      return actual;
    
    // Generamos los hijos del nodo actual
    generar_hijos(actual, abiertos, cerrados);


  }
  
  // Si no hay solucion devuelve el nodo con coste -1
  actual->set_fn(-1);
  return actual;
  
}

void Maze::generar_hijos(Cell* actual, vector<Cell*>& abiertos, vector<Cell*>& cerrados) {

    int salida; // variable resultado del metodo comprobar_conjunto()
    int pos_x = actual->get_x();
    int pos_y = actual->get_y();
    float gn = actual->get_gn();
    float hn;
    float fn;
    
    if (check_norte(actual)) {
      
      // Comprobar si el nodo a generar esta en el conjunto de cerrados
      if (comprobar_conjunto(pos_x-1, pos_y, cerrados) == -1) {
        
        hn = heuristica(pos_x-1, pos_y); 
        fn = gn+5 + hn;

        salida = comprobar_conjunto(pos_x-1, pos_y, abiertos);
        if (salida == - 1) { 
          abiertos.push_back(new Cell(pos_x-1, pos_y, gn+5, hn, fn, actual));
          generated_nodes_++;
        }
        else {
          // Si fn del nodo que se esta evaluando es menor al fn del nodo de la abiertos 
          if (fn < abiertos[salida]->get_fn()) {
            abiertos[salida]->set_parent(actual);
            abiertos[salida]->set_fn(fn);
            abiertos[salida]->set_gn(gn+5);
            generated_nodes_++;
          }

        }
      }

    }

    if (check_sur(actual)) {

      // Comprobar si el nodo a generar esta en el conjunto de cerrados
      if (comprobar_conjunto(pos_x+1, pos_y, cerrados) == -1) {

        hn = heuristica(pos_x+1, pos_y); 
        fn = gn+5 + hn;
        salida = comprobar_conjunto(pos_x+1, pos_y, abiertos);

        if (salida == - 1) {
          abiertos.push_back(new Cell(pos_x+1, pos_y, gn+5, hn, fn, actual));
          generated_nodes_++;
        }
        else {
          // Si fn del nodo que se esta evaluando es menor al fn del nodo de la abiertos 
          if (fn < abiertos[salida]->get_fn()) {
            abiertos[salida]->set_parent(actual);
            abiertos[salida]->set_fn(fn);
            abiertos[salida]->set_gn(gn+5);
            generated_nodes_++;
          }

        }    
      }
    }

    if (check_este(actual)) {

      // Comprobar si el nodo a generar esta en el conjunto de cerrados
      if (comprobar_conjunto(pos_x, pos_y+1, cerrados) == -1) {

        hn = heuristica(pos_x, pos_y+1); 
        fn = gn+5 + hn;
        salida = comprobar_conjunto(pos_x, pos_y+1, abiertos);

        if (salida == - 1) {
          abiertos.push_back(new Cell(pos_x, pos_y+1, gn+5, hn, fn, actual));
          generated_nodes_++;
        }
        else {
          // Si fn del nodo que se esta evaluando es menor al fn del nodo de la abiertos 
          if (fn < abiertos[salida]->get_fn()) {
            abiertos[salida]->set_parent(actual);
            abiertos[salida]->set_fn(fn);
            abiertos[salida]->set_gn(gn+5);
            generated_nodes_++;
          }
        } 
      } 

    }

    if (check_oeste(actual)) {

      // Comprobar si el nodo a generar esta en el conjunto de cerrados
      if (comprobar_conjunto(pos_x, pos_y-1, cerrados) == -1) {

        hn = heuristica(pos_x, pos_y-1); 
        fn = gn+5 + hn;
        salida = comprobar_conjunto(pos_x, pos_y-1, abiertos);

        if (salida == - 1) {  
          abiertos.push_back(new Cell(pos_x, pos_y-1, gn+5, hn, fn, actual));
          generated_nodes_++;
        }
        else {
          // Si fn del nodo que se esta evaluando es menor al fn del nodo de la abiertos 
          if (fn < abiertos[salida]->get_fn()) {
            abiertos[salida]->set_parent(actual);
            abiertos[salida]->set_fn(fn);
            abiertos[salida]->set_gn(gn+5);
            generated_nodes_++;
          }
        }
      } 

    }

    if (check_noreste(actual)) {

      // Comprobar si el nodo a generar esta en el conjunto de cerrados
      if (comprobar_conjunto(pos_x-1, pos_y+1, cerrados) == -1) {

        hn = heuristica(pos_x-1, pos_y+1); 
        fn = gn+7 + hn;
        salida = comprobar_conjunto(pos_x-1, pos_y+1, abiertos);

        if (salida == - 1) {
          abiertos.push_back(new Cell(pos_x-1, pos_y+1, gn+7, hn, fn, actual));
          generated_nodes_++;
        }
        else {
          // Si fn del nodo que se esta evaluando es menor al fn del nodo de la abiertos 
          if (fn < abiertos[salida]->get_fn()) {
            abiertos[salida]->set_parent(actual);
            abiertos[salida]->set_fn(fn);
            abiertos[salida]->set_gn(gn+7);
            generated_nodes_++;

          }
        } 
      }    

    }

    if (check_noroeste(actual)) {

      // Comprobar si el nodo a generar esta en el conjunto de cerrados
      if (comprobar_conjunto(pos_x-1, pos_y-1, cerrados) == -1) {

        hn = heuristica(pos_x-1, pos_y-1); 
        fn = gn+7 + hn;
        salida = comprobar_conjunto(pos_x-1, pos_y-1, abiertos);

        if (salida == - 1) {        
          abiertos.push_back(new Cell(pos_x-1, pos_y-1, gn+7, hn, fn, actual));
          generated_nodes_++;
        }
        else {
          // Si fn del nodo que se esta evaluando es menor al fn del nodo de la abiertos 
          if (fn < abiertos[salida]->get_fn()) {
            abiertos[salida]->set_parent(actual);
            abiertos[salida]->set_fn(fn);
            abiertos[salida]->set_gn(gn+7);
            generated_nodes_++;
          }
        }
      }  
    }

    if (check_sureste(actual)) {

      // Comprobar si el nodo a generar esta en el conjunto de cerrados
      if (comprobar_conjunto(pos_x+1, pos_y+1, cerrados) == -1) {

        hn = heuristica(pos_x+1, pos_y+1); 
        fn = gn+7 + hn;
        salida = comprobar_conjunto(pos_x+1, pos_y+1, abiertos);

        if (salida == - 1) {
          abiertos.push_back(new Cell(pos_x+1, pos_y+1, gn+7, hn, fn, actual));
          generated_nodes_++;
        }
        else {
          // Si fn del nodo que se esta evaluando es menor al fn del nodo de la abiertos 
          if (fn < abiertos[salida]->get_fn()) {
            abiertos[salida]->set_parent(actual);
            abiertos[salida]->set_fn(fn);
            abiertos[salida]->set_gn(gn+7);
            generated_nodes_++;
          }
        }
      }    
    }

    if (check_suroeste(actual)) {

      // Comprobar si el nodo a generar esta en el conjunto de cerrados
      if (comprobar_conjunto(pos_x+1, pos_y-1, cerrados) == -1) {

        hn = heuristica(pos_x+1, pos_y-1); 
        fn = gn+7 + hn;
        salida = comprobar_conjunto(pos_x+1, pos_y-1, abiertos);

        if (salida == - 1) { 
          abiertos.push_back(new Cell(pos_x+1, pos_y-1, gn+7, hn, fn, actual));
          generated_nodes_++;
        }
        else {
          // Si fn del nodo que se esta evaluando es menor al fn del nodo de la abiertos 
          if (fn < abiertos[salida]->get_fn()) {
            abiertos[salida]->set_parent(actual);
            abiertos[salida]->set_fn(fn);
            abiertos[salida]->set_gn(gn+7);
            generated_nodes_++;
          }
        }  
      }   
    }

}

int Maze::comprobar_conjunto(int x, int y, vector<Cell*>& conjunto) {

  for (int i = 0; i < conjunto.size(); i++) {
    if (x == conjunto[i]->get_x() && y == conjunto[i]->get_y())
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
  if (pos_x == 0 || pos_y == maze_[pos_x].size()-1)
    return false;

  // Comprobación muro
  if (maze_[pos_x-1][pos_y+1] == '1')
    return false;
  
  return true;
}

bool Maze::check_noroeste(Cell* actual) {

  int pos_x = actual->get_x();
  int pos_y = actual->get_y();

  // Comprobacion borde superior e izquierdo
  if (pos_x == 0 || pos_y == 0)
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
  if (pos_x == maze_.size()-1 || pos_y == maze_[pos_x].size()-1)
    return false;

  // Comprobación muro
  if (maze_[pos_x+1][pos_y+1] == '1')
    return false;
  
  return true;
}

bool Maze::check_suroeste(Cell* actual) {

  int pos_x = actual->get_x();
  int pos_y = actual->get_y();

  // Comprobacion borde inferior e izquierdo
  if (pos_x == maze_.size()-1 || pos_y == 0)
    return false;

  // Comprobación muro
  if (maze_[pos_x+1][pos_y-1] == '1')
    return false;
  
  return true;
}

void Maze::cambiar_entrada_salida(int x1, int y1, int x2, int y2) {

  // Cambiamos entrada y salida por un muro
  maze_[start_.first][start_.second] = '1';
  maze_[finish_.first][finish_.second] = '1';

  // Añadimos la nueva entrada salida
  maze_[x1][y1] = '3';
  maze_[x2][y2] = '4';

  start_.first = x1; start_.second = y1;
  finish_.first = x2; finish_.second = y2;


}


float Maze::heuristica(int x, int y) {
  if (heuristica_ == 1) {
    return distancia_manhattan(x, y);
  }
  else if (heuristica_ == 2) {
    return distancia_euclidia(x, y);
  }
  else {
    return -1;
  }

}


float Maze::distancia_manhattan(int x, int y) {
  float expresion1 = abs(finish_.first-x);
  float expresion2 = abs(finish_.second-y);
  
  return ( (expresion1 + expresion2) * 3);
}

float Maze::distancia_euclidia(int x, int y) {
  int expresion1 = pow((finish_.first-x), 2);
  int expresion2 = pow((finish_.second-y), 2);
  float expresion3 = sqrt(expresion1 + expresion2);
  
  return (expresion3 * 3);
}


void Maze::print_file(Cell* meta) {

  string file = "salida" + file_;
  ofstream fout(file, ios::app);

  fout << "Instancia: " << file_;
  if (heuristica_ == 1) fout << " Manhattan" << endl;
  if (heuristica_ == 2) fout << " Euclidia" << endl;
  fout << "Filas: " << maze_.size() << " " << "Columnas: " << maze_[0].size() << endl;
  fout << "Entrada / Salida: " <<  "(" << start_.first << "," << start_.second << ") / ("
       << finish_.first << "," << finish_.second << ")" << endl;

  int coste_camino = meta->get_fn();
  if ( coste_camino == -1) {
    for (int i=0; i<maze_.size(); i++) {
      for (int j=0; j<maze_[i].size(); j++) 
        fout << maze_[i][j] << " ";
    fout << endl;
    }
    fout << "No hay solucion" << endl;
  }

  else {
    // Almacenamos la solucion en el vector
    vector<Cell*> camino;
    while (meta->get_parent() != NULL) {
      camino.push_back(meta);
      maze_[meta->get_x()][meta->get_y()] = '*';
      meta = meta->get_parent();
    }
    maze_[meta->get_x()][meta->get_y()] = '*';
    camino.push_back(meta);

    // Imprimimos el laberinto resultado
    for (int i=0; i<maze_.size(); i++) {
      for (int j=0; j<maze_[i].size(); j++) 
        fout << maze_[i][j] << " ";
      fout << endl;
    }

    // Imprimimos el camino
    fout << "Camino: ";
    for (int i = camino.size()-1; i >= 0; i--) {
      fout << "(" << camino[i]->get_x() << "," << camino[i]->get_y() << ") -> ";
    }
    fout << endl << "Coste: " << coste_camino << endl;

  }

  fout << "Nodos generados: " << generated_nodes_ << endl;
  fout << "Nodos inspeccionados: " << inspected_nodes_ << endl;

  fout << endl << endl;

}
