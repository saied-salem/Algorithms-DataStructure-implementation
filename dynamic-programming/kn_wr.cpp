#include<bits/stdc++.h>
using namespace std;

int  ks_without_repetetion (int weights[],int values[],int num, int max_wheight){

    int knap_sack[max_wheight+1];
    for(int i=0;i<=max_wheight;i++){
        knap_sack[i] = 0;
        for(int j=0 ;j <num;j++){
            if(i>=weights[j]){
                int val = values[j]+knap_sack[i-weights[j]];
                if(val>knap_sack[i])
                    knap_sack[i]=val;

            }

        }
    }
    return knap_sack[max_wheight];
}


int main()
{

    int max_wheight,num;
    cin>> num >> max_wheight;
    int val[num];
    int wt[num];

    for (int i = 0; i <num ; ++i) {
        cin>>wt[i];

    }
    for (int i = 0; i <num ; ++i) {
        cin>>val[i];

    }
    cout << ks_without_repetetion(wt, val, num, max_wheight);

    return 0;
}
