#ifndef MY_TREE_H
#define MY_TREE_H

#include <vector>
using namespace std;


template <class T>
struct node {
    T data;
    node* left;
    node* right;
};

template <class T>
class MyTree{

    private:

    bool search(T key,node<T>* root);

    node<T>* insert(T key, node<T>* root);
    void inorder_rec(node<T>* root);
    void preorder_rec(node<T>* root);
    void postorder_rec(node<T>* root);
    void inorder_it(node<T>* root);
    void preorder_it(node<T>* root);
    void postorder_it(node<T>* root);
    void breadth_traversal(node<T>* root);

    node<T>* ROOT;
    int TREE_SIZE;


    public:
        MyTree();
        
        MyTree(vector<T> elements);

        node<T>* creat_node(T element);

        bool search(T element);

        node<T>* insert(T element);

        void inorder_rec();
        
        void preorder_rec();
        
        void postorder_rec();
        
        void inorder_it();
        
        void preorder_it();
        
        void postorder_it();

        void breadth_traversal();

        int size();


};

#endif