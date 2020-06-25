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
        void clrsrc(); //������� ������ ������ (���������� �������)
        Node *makeNodes(int depth,int num); //�������� ��������� ������� ������ (�� ����� �������� �������)
        void outNodes(Node *nd,int r,int c); //��������� ����� ����� � ����� ������

        Node *root = NULL;
        static char tag,maxtag; //��� ���� � ����������� ��������� ���
        static int maxdepth, //������������ ������� ������
                maxwidth; //������������ ������ ������ ������
        static int offset; //�������� ��� ���� ������ ������ � ������ ������
        int num;
        char **screen = NULL; //����� ������
    public:
        BinTree();

        void makeTree(){ //������� ������
            root = makeNodes(0,0);
        }
        void outTree(); //������� ������

        bool Exist(){
            return root != NULL;
        }

        int DFS(); //����� � ������� � ��������� ����� ������
        int DFS(Node *nd,int depth); //��������������� ����������� �����

        ~BinTree();
};

#endif // BINTREE_H_INCLUDED
