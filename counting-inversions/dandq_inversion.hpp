#include <iostream>
#include <vector>
using namespace std;

/**
 * implement the divide and conquer solution to counting inversions problem
 * 
 * @param
 * a --> 1d array
 * 
 * @return
 * the number of inversions in the array
*/
int count_merge(vector<int> &a , int l, int m , int r) {



    vector<int> left_arr , right_arr;
     left_arr.assign(a.begin()+l,a.begin()+m+1);
     right_arr.assign(a.begin() +m+1,a.begin()+r+1);

    int i,j,k, swap;
    i =0 ;j=0; k=l; swap = 0;

    while (i < left_arr.size() && j < right_arr.size()) {
        if (left_arr[i] <= right_arr[j]){

            a[k++] = left_arr[i++];
        }

        else {
            a[k++] = right_arr[j++];
            swap += (m + 1) - (l + i);
        }
    }

    while (i < left_arr.size()){
        a[k++] = left_arr[i++];
    }
    while (j <  right_arr.size()){
        a[k++] = right_arr[j++];

    }

    return swap;


}
int count_sort (vector<int> &a , int l, int r){
    int count = 0 ;
    if(l<r){
        int mid = (l+r)/2;

        count+= count_sort(a,l,mid);
        count+= count_sort(a,mid+1,r);
        count+= count_merge(a,l,mid,r);


    }
    return count;

}

int dandq_counting_inversions (vector<int> a ){
    int l=0;
    int r = a.size()-1;
    int count = count_sort(a,l,r);

return count;
}
