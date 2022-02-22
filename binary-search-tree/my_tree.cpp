#include <iostream>
#include<bits/stdc++.h>
#include <vector>
#include "my_tree.h"

using namespace std;



template <class T>
MyTree<T>::MyTree(){
    ROOT = NULL;
    TREE_SIZE =0;
}

template <class T>
MyTree<T>::MyTree(vector<T> elements){
    ROOT = NULL;
    TREE_SIZE =0;
    for (int i = 0; i < elements.size(); ++i) {
        int e = elements[i];
        insert(e);
    }
}

template <class T>
node<T>* MyTree<T>:: creat_node(T element){
    node<T>* tempNode = new node<T>;
    tempNode->data = element;
    tempNode->left = NULL;
    tempNode->right= NULL;
    return tempNode;
}

template <class T>
bool  MyTree<T>:: search(T element){
    return search(element,ROOT);
}

template <class T>
bool  MyTree<T>:: search(T element,node<T>* root){
    if(root== NULL){
        return false;
    }
    if(root->data == element){
        return true;
    }
    else if(root->data < element){
        return search(element,root->right);
    }
    else if (root->data > element){
        return search(element,root->left);
    }
    return false;
}


template <class T>
node<T>* MyTree<T>:: insert(T element){
    ROOT = insert(element,ROOT);
    return ROOT;
}

template <class T>
node<T>* MyTree<T>:: insert(T element,node<T>* root){

    if(root == NULL){
        node<T>* root= creat_node(element);
        TREE_SIZE++;
        return root;
    }
    else if(root->data < element){
        root->right =insert(element,root->right);
    }
    else if (root->data > element){
        root->left =insert(element,root->left);
    }
    return root;
}

template <class T>
int MyTree<T>::size(){
    return TREE_SIZE;
}

template <class T>
void MyTree<T>::inorder_rec(node<T>* root){
    if (root == NULL)
        return;

    inorder_rec(root->left);

    cout << root->data << " ";

    inorder_rec(root->right);

}
template <class T>
void MyTree<T>::preorder_rec(node<T>* root){
    if (root == NULL)
        return;

    cout << root->data << " ";

    preorder_rec(root->left);

    preorder_rec(root->right);

}
template <class T>
void MyTree<T>::postorder_rec(node<T>* root){
    if (root == NULL)
        return;
    postorder_rec(root->left);

    postorder_rec(root->right);

    cout << root->data << " ";
}



template <class T>
void MyTree<T>:: inorder_rec() {
    inorder_rec(ROOT);
}
template <class T>
void MyTree<T>:: preorder_rec() {
    preorder_rec(ROOT);
}

template <class T>
void MyTree<T>:: postorder_rec() {
    postorder_rec(ROOT);

}

template <class T>
void MyTree<T>:: inorder_it() {
    inorder_it(ROOT);
}

template <class T>
void MyTree<T>:: preorder_it(){
    preorder_it(ROOT);
}

template <class T>
void MyTree<T>::postorder_it(){
    postorder_it(ROOT);
}

template <class T>
void MyTree<T>:: inorder_it(node<T>* root){
    stack<node<T>*> s;
    node<T> *curr = root;

    while (curr != NULL || s.empty() == false)
    {
        while (curr !=  NULL)
        {

            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        curr = curr->right;

    }
}


template <class T>
void MyTree<T>:: preorder_it(node<T>* root){
    stack<node<T>*> s;
    s.push(root);
    node<T>*curr;
    while (s.empty() == false)
    {
        curr = s.top();
        cout << curr->data << " ";
        s.pop();

        if (curr->right) {
            s.push(curr->right);
        }
        if (curr->left) {
            s.push(curr->left);
        }
        curr = curr->right;

    }

}
template <class T>
void MyTree<T>::postorder_it(node<T>* root){
    stack<node<T>*> s1,s2;
    node<T>*curr;
    s1.push(root);
    while (!s1.empty()) {

        curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left)
            s1.push(curr->left);
        if (curr->right)
            s1.push(curr->right);
    }

    while (!s2.empty()) {
        curr = s2.top();
        s2.pop();
        cout << curr->data << " ";
    }

}

template <class T>
void MyTree<T>::breadth_traversal(node<T>*root){
    queue<node<T>*> queue;
    queue.push(root);
    while (!queue.empty()){
        node<T>* curr = queue.front();
        cout<<curr->data<<" ";
        queue.pop();
        if(curr->left!=NULL) {
            queue.push(curr->left);
        }
        if(curr->right!=NULL) {
            queue.push(curr->right);
        }
    }
}
template <class T>
void MyTree<T>::breadth_traversal(){
    breadth_traversal(ROOT);
}

int midium_adjustment(vector<int>&v,vector<int>&arr, int l, int h){

    int mid = (l+h)/2;
    v.push_back(arr[mid]);
    if(l== h )
        return arr[h];
    midium_adjustment(v,arr,l,mid-1);
    midium_adjustment(v,arr,mid+1,h);
    return 0;
}

int main(int argc, char** argv){


    int tree_size,num_of_operations;
    vector<int>arr;
    vector<int>v;
//    cout<<"enter size of tree"<<endl;

    cin>> tree_size;
//    cout<<"enter num of operations"<<endl;
    cin>>num_of_operations;


//    cout<<"input line"<<endl;
    for (int i = 0; i < tree_size; ++i) {
        int element;
        cin>> element;
        arr.push_back(element);

    }
    sort(arr.begin(), arr.end());

    midium_adjustment(v,arr,0,tree_size-1);

    MyTree<int> t(v);

    for (int i = 0; i < num_of_operations; ++i) {
        int num_of_opr;
//        cout<<"enter operation num "<<endl;
        cin>> num_of_opr;
        if (num_of_opr == 1){
            int inserted_item ;
//            cout<<"enter num to be inserted"<<endl;
            cin>> inserted_item;
            t.insert(inserted_item);
        }
        else if(num_of_opr == 2){
            int searched_element;
//            cout<<"enter num to be searched"<<endl;

            cin>> searched_element;
            if( t.search(searched_element))
                cout<<1<<" "<<endl;

            else
                cout<<0<<" "<<endl;
        }
        else if (num_of_opr == 3){
            int num_of_method_of_traversal ;
//            cout<<"enter num to of traversal methodology"<<endl;
            cin>>num_of_method_of_traversal;
            if (num_of_method_of_traversal==1){
                t.inorder_rec();
                cout<<endl;
            }
            if (num_of_method_of_traversal==2){
                t.inorder_it();
                cout<<endl;
            }
        }
        else if (num_of_opr == 4){
            int num_of_method_of_traversal ;
//            cout<<"enter num to of traversal methodology"<<endl;
            cin>>num_of_method_of_traversal;
            if (num_of_method_of_traversal==1){
                t.preorder_rec();
                cout<<endl;
            }
            if (num_of_method_of_traversal==2){
                t.preorder_it();
                cout<<endl;
            }
        }
        else if (num_of_opr == 5){
            int num_of_method_of_traversal ;
//            cout<<"enter num to of traversal methodology"<<endl;
            cin>>num_of_method_of_traversal;
            if (num_of_method_of_traversal==1){
                t.postorder_rec();
                cout<<endl;
            }
            else if (num_of_method_of_traversal==3){

                t.postorder_it();
                cout<<endl;
            }
            else{
                t.postorder_it();
                cout<<endl;
            }

        }
        else if (num_of_opr == 6){
            t.breadth_traversal();
            cout<<endl;

        }
        else if (num_of_opr == 7){
            cout<<t.size()<<" ";
            cout<<endl;

        }
    }
}