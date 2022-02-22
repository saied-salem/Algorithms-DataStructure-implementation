//

#include <bits/stdc++.h>
using namespace std;


void heapsort(vector<int>::iterator begin, vector<int>::iterator end)
{
    make_heap(begin, end);
    sort_heap(begin, end);
}

vector<int>::iterator partition(vector<int>::iterator begin, vector<int>::iterator end) {
    vector<int>::iterator pivot = end-1;

    auto i =  begin - 1;
    for (vector<int>::iterator j = begin; j <= end -1 ; j++) {
        if (*j < *pivot) {
            
            std::iter_swap(i+1, j);
            i++;
        }
    }
    std::iter_swap(i+1, pivot);

    return i+1;
}

void introsort(vector<int> &a, vector<int>::iterator begin, vector<int>::iterator end, int max_depth){
    //cout << "begin_idx: " << begin - a.begin() << " ";
    //cout << "end_idx: " << end - a.begin() << endl;

    //cout << "begin_value: " << * begin << " ";
    //cout << "end_value: " << *end << endl;


    if(a.size() <= 1) 
        return;

    else if (max_depth == 0) {
        heapsort(begin, end );
       // cout << "inside heapsort" << endl;
    }
    else if(std::distance(begin, end) > 0){
        // otherwise, perform quicksort
        vector<int>::iterator pivot = partition( begin , end );


        introsort(a, begin, pivot  , max_depth - 1);

        introsort(a, pivot +1, end , max_depth - 1);
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
//     cout<< "introSort"<<endl;
//     vector<int>  arr = { 10, 7, 8, 9, 1, 5 ,-8,-213,-8,4,6,98,-354,-11,634};
//     int n = arr.size(); 
//     int maxdepth =  floor(std::log(arr.size()));
//     cout << "printing vector befor sorting : " << endl;
//     print_arr(arr);
//     vector<int>::iterator start = arr.begin();
//     vector<int>::iterator end  = arr.end();
//     introsort(arr, start , end - 1,maxdepth);
//     cout << "printing vector after sorting : " << endl;
//     print_arr(arr);

// }
