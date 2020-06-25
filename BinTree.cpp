#include <iostream>
#include <malloc.h>
#include <memory.h>
#include <time.h>
#include "BinTree.h"

using namespace std;

char BinTree::tag = 'A';
char BinTree::maxtag = 'Z';
int BinTree::maxdepth = 5;
int BinTree::maxwidth = 65;
int BinTree::offset = BinTree::maxwidth / 2;

BinTree::BinTree(){
    screen = new char* [maxdepth*3];//*3 - для промежутка между уровнями(можно убрать
    for(int i = 0;i < maxdepth*3;i++)
        screen[i] = new char[maxwidth];
}

Node* BinTree::makeNodes(int depth,int num){
    Node *nd = NULL;
    if(depth <= rand()%maxdepth && num <= (maxtag - 'A')){
        nd = new Node;
        nd->left = makeNodes(depth + 1,++num);
        nd->right = makeNodes(depth + 1,++num);
        nd->tag = tag++;
    }
    return nd;
}

void BinTree::clrsrc(){
    for(int i = 0;i < maxdepth*3;i++)
        memset(screen[i],'.',maxwidth);
}

void BinTree::outNodes(Node *nd,int r,int c){
    if(r && c && (c < maxwidth)) screen[r-1][c-1] = nd->tag;
    if(r < maxdepth*3){
        if(nd->left) outNodes(nd->left,r + 1,c - (offset>>r));
        if(nd->right) outNodes(nd->right,r + 1,c + (offset>>r));
    }
}

void BinTree::outTree(){
    clrsrc();
    outNodes(root,1,offset);
    for(int i = 0;i < maxdepth*3;i++){
        screen[i][maxwidth] = '\0';
        cout << screen[i] << endl;
    }
}

int BinTree::DFS(){
    return DFS(root,0);
}

int BinTree::DFS(Node *nd,int depth){
    int l = 0,r = 0;
    if(nd->left) l = DFS(nd->left,depth + 1);
    if(nd->right) r = DFS(nd->right,depth + 1);
    if(depth + 1 < 3) return l + r + 1;
    else return 1;
}

BinTree::~BinTree(){
    for(int i = 0;i < maxdepth*3;i++)
        delete screen[i];
    delete screen;
    delete root;
}

