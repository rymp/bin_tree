#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "BinTree.h"

using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL,"rus");

    BinTree tree = BinTree();
    tree.makeTree();

    cout << "Дерево - " << endl;
    tree.outTree();

    cout << "Число вершин на глубине не более 3 - " << tree.DFS() << endl;

    return 0;
}
