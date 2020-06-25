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

    cout << "������ - " << endl;
    tree.outTree();

    cout << "����� ������ �� ������� �� ����� 3 - " << tree.DFS() << endl;

    return 0;
}
