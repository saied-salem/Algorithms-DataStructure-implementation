#ifndef MY_PQ_H
#define MY_PQ_H

#include <vector>
using namespace std;

class My_PQ{
private:
    int parent(int i);
    int leftChild(int i);
    int rightChild(int i);
    void siftUp(int i);
    void siftDown(int i);
    int getMax();
    int SIZE;


public:

    My_PQ();
    
    My_PQ(vector<int> arr);

    vector<int> qeu;
    int extract_max();

    int change_priority(int index, int new_priority);

    int peek();

    void insert(int value);

    void remove(int index);
    int size();

    void extract_max_for_all();
};

#endif