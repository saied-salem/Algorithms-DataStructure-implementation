// Tsak2_second_trial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;

vector<int>::iterator Partition(vector<int>::iterator begin, vector<int>::iterator end) {
    vector<int>::iterator pivot = end-1;

    auto i =  begin - 1;
    for (vector<int>::iterator j = begin; j <= end-1; j++) {
        if (*j < *pivot) {
            
            std::iter_swap(i+1, j);
            i++;
        }
    }
    std::iter_swap(i+1, pivot);

    return i+1;
}



void quickSort(vector<int> &v, vector<int>::iterator begin, vector<int>::iterator end) {

    if(v.size() <= 1) 
        return;

    else if (std::distance(begin, end) > 0) {
        vector<int>::iterator splitPosition = Partition(begin, end);

        quickSort(v, begin, splitPosition);
        quickSort(v, splitPosition + 1, end);
    }
}


// void print_arr(vector<int>v) {

//     for (int i = 0; i < v.size();i++) {
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }





// int main()
// {
//     vector<int>  arr = { 10, 7, 8, 9, 1, 5 ,-8,-213,-8,4,6,98,-354,-11,634};
//     cout << "printing vector befor sorting : " << endl;
//     print_arr(arr);
//     vector<int>::iterator start = arr.begin();
//     vector<int>::iterator end  = arr.end();
//     quickSort(arr, start , end );
//     cout << "printing vector after sorting : " << endl;
//     print_arr(arr);

// }

