//
// Created by mohit on 4/2/17.
//
#include <bits/stdc++.h>

#define MAXROW 10
#define MAXCOL 10
using namespace std;
#define mod 1000000007


int main(){

    long long int l, r, k;
    cin>>l>>r>>k;

    long long int ans = 1;
    bool flag = false;
    while(ans > 0){
        if (ans>=l && ans <=r){
            cout<<ans<<" ";
            flag = true;
        }
        ans = ans*k;
    }
    if(flag == false){
        cout<<"-1";
    }
    return 0;
}