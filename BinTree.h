#ifndef BINTREE_H_INCLUDED
#define BINTREE_H_INCLUDED

typedef struct Node Node;

struct Node{
    char tag;
    Node *left;
    Node *right;
};

class BinTree{
private:
    void clrsrc(); //Очистка буфера вывода (заполнение точками)
    Node *makeNodes(int depth,int num); //Создание случайным образом дерева (не более заданной глубины)
    void outNodes(Node *nd,int r,int c); //Занесение меток узлов в буфер вывода

    Node *root = NULL;
    static char tag,maxtag; //Тег узла и максимально возможный тег
    static int maxdepth, //Максимальная глубина дерева
            maxwidth; //Максимальная ширина буфера вывода
    static int offset; //Смещение для узла нового уровня в буфере вывода
    int num;
    char **screen = NULL; //Буфер вывода
public:
    BinTree();

    void makeTree(){ //Создать дерево
        root = makeNodes(0,0);
    }
    void outTree(); //Вывести дерево

    bool Exist(){
        return root != NULL;
    }

    int DFS(); //Обход в глубину с подсчётом числа вершин
    int DFS(Node *nd,int depth); //Вспомогательный рекурсивный метод

    ~BinTree();
};

#endif // BINTREE_H_INCLUDED
