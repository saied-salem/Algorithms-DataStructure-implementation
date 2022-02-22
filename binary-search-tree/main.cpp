


#include <iostream>
#include <vector>
#include "my_tree.h"


using namespace std;

int main(int argc, char** argv) {


    int tree_size, num_of_operations;
    cout << "enter size of tree" << endl;
    cin >> tree_size;
    cout << "enter num of operations" << endl;
    cin >> num_of_operations;
    MyTree<int> t;
    for (int i = 0; i < tree_size; ++i) {
        int element;
        cin >> element;
        t.insert(element);

    }
    for (int i = 0; i < num_of_operations; ++i) {
        int num_of_opr;
        cin >> num_of_opr;
        if (num_of_opr == 1) {
            int inserted_item;
            cin >> inserted_item;
            t.insert(inserted_item);
        } else if (num_of_opr == 2) {
            int searched_element;
            cin >> searched_element;
            t.search(searched_element);
        } else if (num_of_opr == 3) {
            int num_of_method_of_traversal;
            cin >> num_of_method_of_traversal;
            if (num_of_method_of_traversal == 1) {
                t.inorder_rec();
            }
            if (num_of_method_of_traversal == 2) {
                t.inorder_it();
            }

        } else if (num_of_opr == 4) {
            int num_of_method_of_traversal;
            cin >> num_of_method_of_traversal;
            if (num_of_method_of_traversal == 1) {
                t.preorder_rec();
            }
            if (num_of_method_of_traversal == 2) {
                t.preorder_it();
            }

        } else if (num_of_opr == 5) {
            int num_of_method_of_traversal;
            cin >> num_of_method_of_traversal;
            if (num_of_method_of_traversal == 1) {
                t.postorder_rec();
            }
            if (num_of_method_of_traversal == 3) {
                t.postorder_it();
            }

        } else if (num_of_opr == 6) {
            t.breadth_traversal();
        } else if (num_of_opr == 7) {
            cout << t.size();
        }
    }


//    MyTree<type> t(v);
//    t.insert(40);
//    t.insert(78);
//    t.insert(25);
//    t.insert(10);
//    t.insert(32);
//    t.inorder_rec();
//    cout<<t.size();

}