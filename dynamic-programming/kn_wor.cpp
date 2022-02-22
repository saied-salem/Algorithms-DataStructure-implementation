#include<bits/stdc++.h>
using namespace std;

int  ks_with_repetetion (int weights[],int values[],int num, int max_wheight){
    int knap_sack[num+1][max_wheight+1];
    for (int i = 0; i <=num ; i++)
        for (int j = 0; j <=max_wheight ; j++) {
            knap_sack[i][j] = 0;
        }

    for(int i=1 ;i <=num;i++){
        for(int w=0;w<=max_wheight;w++) {
            knap_sack[i][w] = knap_sack[i-1][w];
            if(w>=weights[i-1]){
                int val = values[i-1] + knap_sack[i-1][w - weights[i-1]];
                if(val>knap_sack[i][w]){
                    knap_sack[i][w]=val;
                }

            }
        }
    }

    return knap_sack[num][max_wheight];
}


int main()
{
    int max_weight,num;
    cin>> num >> max_weight;
    int val[num];
    int wt[num];


    for (int i = 0; i <num ; ++i) {
        cin>>wt[i];

    }
    for (int i = 0; i <num ; ++i) {
        cin>>val[i];

    }


    cout << ks_with_repetetion(wt, val, num, max_weight);

    return 0;
}
