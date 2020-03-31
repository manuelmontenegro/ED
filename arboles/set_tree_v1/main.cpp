/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */
 
/*
 * Uso del TAD Conjunto
 */

#include "set_tree.h"

using namespace std;

int main() {
    SetTree<int> sv;

    sv.insert(10);
    sv.insert(20);

    cout << sv << endl;

    // sv.insert(15);

    cout << sv << endl;

    cout << sv.contains(10) << endl;
    sv.erase(15);
    cout << sv.contains(10) << endl;
    
    return 0;
}
