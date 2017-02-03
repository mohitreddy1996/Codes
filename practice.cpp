//
// Created by mohit on 4/2/17.
//
#include <bits/stdc++.h>

using namespace std;

struct Rent{
    int start, dur, cost;
    bool operator <(const Rent &rent) const {
        return start < rent.start;
    }
};

Rent rent[10005];
int ans[10005];

int find_next(int time, int n){
    int low = 0;
    int high = n;
    while((high - low) > 1){
        int mid = low + (high-low)/2;
        if(rent[mid].start >= time){
            high = mid;
        }else{
            low = mid;
        }
    }
    return high;
}

int main(){

    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;

        for(int i=0; i<=N;i++)
            ans[i] = 0;
        for(int i=0; i<N; i++){
            int start, dur, cost;
            scanf("%d %d %d", &start, &dur, &cost);
            rent[i].start = start;
            rent[i].cost = cost;
            rent[i].dur = dur;
        }

        sort(rent, rent+N);
        ans[N] = 0;
        for(int i=N-1; i>=0; i--){
            ans[i] = max(ans[i+1], ans[find_next(rent[i].start + rent[i].dur, N)] + rent[i].cost);
        }

        printf("%d\n", ans[0]);
    }

    return 0;
}