//
// Created by 10 on 12/20/2021.
//

#include <iostream>
#include<bits/stdc++.h>



using namespace std;
int midium_ins(queue<int> &q,int arr [],int l, int h){

    int mid = (l+h)/2;
    cout<<arr[mid];
    if(l== h )
        return arr[h];
    midium_ins(q,arr,l,mid-1);
    midium_ins(q,arr,mid+1,h);

}
int main(int argc, char** argv) {
    int arr [7]={1,2,3,4,5,6,7};
    queue<int> q;
    int l = 0,h =6;
    int mid = (l+h)/2;
    for(int i=0;i<7;i++){
        q.push(arr[mid]);
        int lr=mid-1;
        int rl =mid+1;
        if(lr!=l){
            q.push(arr[l])
        }
    }


    return 0
}