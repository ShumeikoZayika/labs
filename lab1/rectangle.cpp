#include <iostream>
using namespace std;

// Definição da estrutura
struct Rectangle {
  int length;
  int breadth;
  char x = 'a';
};

int main() {
  // Declaração e inicialização
  struct Rectangle r = {10, 5};

  // Aceder e modificar membros usando o operador ponto (.)
  r.length = 15;
  r.breadth = 7;

  cout << "A área do retângulo é: " << r.length * r.breadth << endl;
  cout << "O valor de x é: " << r.x << endl;
  cout << "O tamanho de Rectangle em bytes é: " << sizeof(Rectangle) << endl;
  return 0;
}
