#include <iostream>
#include "classPractice.h"


using namespace std;
 
int main() {
    ArrayOfFractions L;
 
    cout << "Contenido de L:" << endl;
    L.print();
 
    cout << "Maximo, minimo y suma de elementos en L" << endl;
    L.max().print();
    cout << ", ";
    L.min().print();
    cout << ", ";
    L.sum().print(); 
    cout << endl;
 
 
    L.sortAscending();
    cout << "Contenido de L, luego de ordenado" << endl;
    L.print();
    
    return 0;
}