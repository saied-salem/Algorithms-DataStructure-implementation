#include <iostream>
#include<bits/stdc++.h>
#include <vector>
#include "my_pq.h"

using namespace std;

My_PQ:: My_PQ() {
    SIZE=-1;

}

My_PQ:: My_PQ(vector<int> arr) {
    for (int i = 0; i < arr.size(); ++i) {
        insert(arr[i]);
    }

}
int My_PQ::size(){
    return SIZE+1;

}

int My_PQ::parent(int i) {
    return (i - 1) / 2;

}
int My_PQ::leftChild(int i) {
    return ((2 * i) + 1);
}
int My_PQ::rightChild(int i) {
    return ((2 * i) + 2);
}
void My_PQ::siftUp(int i){

    while (i > 0 && qeu[parent(i)] < qeu[i]) {

        swap(qeu[parent(i)], qeu[i]);


        i = parent(i);
    }

}

void My_PQ::siftDown(int i){
    int maxIndex = i;


    int l = leftChild(i);

    if (l < qeu.size() && qeu[l] > qeu[maxIndex]) {
        maxIndex = l;
    }

    int r = rightChild(i);

    if (r < qeu.size() && qeu[r] > qeu[maxIndex]) {
        maxIndex = r;
    }

    if (i != maxIndex) {
        swap(qeu[i], qeu[maxIndex]);
        siftDown(maxIndex);
    }

}
int My_PQ::getMax(){
return qeu[0];
}
///////////////////

int My_PQ::extract_max(){
    int result = qeu[0];

    swap(qeu[0], qeu[qeu.size() - 1]);
    SIZE = SIZE - 1;
    qeu.pop_back();

    siftDown(0);
    return result;
}

int My_PQ::change_priority(int index, int new_priority){
    int oldp = qeu[index];
    qeu[index] = new_priority;

    if (new_priority > oldp) {
        siftUp(index);
    }
    else {
        siftDown(index);
    }
    return 0;
}

int My_PQ::peek(){
    return qeu[0];

}

void My_PQ::insert(int value){
    SIZE = SIZE + 1;
    qeu.push_back(value);

    // Shift Up to maintain heap property
    siftUp(qeu.size() - 1);


}

void My_PQ::remove(int i)
{
    qeu[i] = getMax() + 1;


    siftUp(i);

    extract_max();
}

void My_PQ::extract_max_for_all()
{
    int size = qeu.size();
    for (int i = 0; i < size; i++)
    {
        int x = extract_max();
        cout << x << " ";
    }
    cout<<endl;
}

int main() {
    My_PQ q;

    int tree_size, num_of_operations;

    cout<<"enter size of tree"<<endl;

    cin >> tree_size;
    cout<<"enter num of operations"<<endl;
    cin >> num_of_operations;


    cout<<"input line"<<endl;
    for (int i = 0; i < tree_size; ++i) {
        int element;
        cin >> element;
        q.insert(element);

    }
//    q.extractMaxForAll();


    for (int i = 0; i < num_of_operations; ++i) {
        int num_of_opr;
//        cout<<"enter operation num "<<endl;
        cin >> num_of_opr;
        if (num_of_opr == 1) {
            int inserted_item;
//            cout<<"enter num to be inserted"<<endl;
            cin >> inserted_item;
            q.insert(inserted_item);
//            q.extractMaxForAll();
///
        } else if (num_of_opr == 2) {
            int chenged_piriorty;
            int chenged_element;

//            cout<<"enter num to be piriorty change"<<endl;

            cin >> chenged_element;
            cin >> chenged_piriorty;

            q.change_priority(chenged_element, chenged_piriorty);
//            q.extractMaxForAll();
///
        } else if (num_of_opr == 3) {
            int removed_element;
//            cout<<"enter num to be removed"<<endl;
            cin >> removed_element;
            q.remove(removed_element);
//            q.extractMaxForAll();
///
        } else if (num_of_opr == 4) {
            q.extract_max();
//            cout<<"ectracting max"<<endl;
//            cout<<q.extract_max()<<endl;

//            q.extractMaxForAll();
///
        } else if (num_of_opr == 5) {
//            cout<<"printing max element"<<endl;
            cout << q.peek() << " "<<endl;

//            q.extractMaxForAll();
///
        } else if (num_of_opr == 7) {
            cout << q.qeu.size() << " ";
            cout << endl;
//            q.extractMaxForAll();

        } else if (num_of_opr == 6) {

            q.extract_max_for_all();

            cout << "\n";

        }

    }

    return 0;
}
