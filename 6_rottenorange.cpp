#include<iostream>
#include<queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        if(grid.empty()){
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;
        int total_oranges = 0;   //To keep track of total orange(fresh+rottened)
        int new_rotten = 0;      //To keep track of total rottened oranges
        queue<pair<int,int>>rotten;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){   //if cell has fresh or rottened orange
                    total_oranges+=1;
                }
                if(grid[i][j]==2){   //if cell has rottened orange
                    rotten.push({i,j});
                }
            }
        }
        //To move across 4 adjacent sides of cell
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        //Rottening process
        while(!rotten.empty()){
            int k = rotten.size();
            new_rotten+=k;
            while(k--){
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();//Once a rottened orange is utilized for rotening its neighbours, it will be removed from queue
                for(int i=0;i<4;i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]!=1){ //To check if cell is within bound or cell has fresh orange
                        continue;
                    }
                    //if cell has fresh orange, make it rottened
                    grid[nx][ny] = 2;
                    rotten.push({nx,ny});
                }
            }
            //if new oranges are rottened, move to next time step
            if(!rotten.empty()){
                time+=1;
            }
        }
        //if all oranges(fresh+rottened) have all become rottened
        if(new_rotten==total_oranges){
            return time;
        }
        return -1;
    }