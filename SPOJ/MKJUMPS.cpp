//
// Created by mohit on 4/2/17.
//
#include <bits/stdc++.h>

#define MAXROW 10
#define MAXCOL 10
using namespace std;

bool chessBoard[MAXROW][MAXCOL];
bool visited[MAXROW][MAXCOL];

void init(){
    for(int i=0; i<MAXROW; i++){
        for(int j=0; j<MAXCOL; j++){
            chessBoard[i][j] = false;
            visited[i][j] = false;
        }
    }
}

int moves[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}};

int max_count = 0;

void knight_moves(int x, int y, int count){

    // dfs
    visited[x][y] = true;
    for(int i=0; i<8; i++){
        int xx = x + moves[i][0];
        int yy = y + moves[i][1];
        if(xx >=0 && xx<MAXCOL && yy>=0 && yy<MAXCOL && !visited[xx][yy] && chessBoard[xx][yy]){
            knight_moves(xx, yy, count+1);
        }
    }
    visited[x][y] = false;
    if(count > max_count){
        max_count = count;
    }
}

int main(){
    int caseNo = 1;
    while(1){
        int N;
        cin>>N;
        if(N == 0){
            break;
        }
        init();
        int count = 0;
        for(int i=0; i<N;i++){
            int x, y;
            cin>>x>>y;
            for(int j=x; j<(x+y); j++){
                chessBoard[i][j] = true;
                count++;
            }
        }
        int x = 0, y = 0;
        for(int i=0; i<MAXCOL; i++){
            if(chessBoard[0][i]){
                x = 0;
                y = i;
                break;
            }
        }
        knight_moves(x, y, 1);
        int ans = count - max_count;
        max_count = 0;
        if(ans == 1){
            printf("Case %d, %d square can not be reached.\n", caseNo, ans);
        }else{
            printf("Case %d, %d squares can not be reached.\n", caseNo, ans);
        }
        caseNo++;
    }
    return 0;
}