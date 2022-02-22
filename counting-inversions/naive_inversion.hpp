#include <iostream>
#include <vector>
using namespace std;

/**
 * implement the naive solution to counting inversions problem
 * 
 * @param
 *  a --> 1d array
 * 
 * @return
 * the number of inversions in the array
*/
int naive_counting_inversions(vector<int> a){
    int count =0;
    for (int i = 0; i < a.size(); ++i) {

        for (int j = i+1; j < a.size(); ++j) {
            if (a[i]>a[j])
                count++;
        }

    }
    return count;
}
