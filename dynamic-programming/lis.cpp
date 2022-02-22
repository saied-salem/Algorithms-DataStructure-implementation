#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n= nums.size();
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                int val = arr[j]+1;
                if(val>arr[i]){
                    arr[i] =val;
                }
            }
        }
    }
    int max_idx =0 ;
    for(int i=0;i<n;i++){
        if(arr[i]>arr[max_idx]){
            max_idx=i;
        }
    }

    return arr[max_idx];
}


int main(int argc, char** argv){
    int num;
    cin >> num;
    vector<int>numbers(num);
    for (int i = 0; i <num ; ++i) {
        cin >>numbers[i];

    }
    cout << lengthOfLIS(numbers);

    return 0;
}

