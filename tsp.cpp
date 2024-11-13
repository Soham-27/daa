#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

int findmincost(vector<vector<int>>&matrix,int city,vector<bool>&visited){
    int minvalue=INF;
    for(int j=0;j<matrix.size();j++){
        if(!visited[j] && matrix[city][j]< minvalue){
            minvalue=matrix[city][j];
        }
    }
    return minvalue;
}
int estimatelowerbound(vector<vector<int>>&matrix,vector<bool>&visited){
    int lower_bound=0;
    for(int i=0;i<matrix.size();i++){
        if(!visited[i]){
            lower_bound+=findmincost(matrix,i,visited);
        }
    }
    return lower_bound;
}

void exploreroutes(vector<vector<int>>& matrix,vector<bool>&visited,int Currcity,int cityvisit,int currcost,int & mincost,vector<int>&currentRoute,vector<int>&bestRoute){
    int numcities=matrix.size();
    if(cityvisit==numcities && matrix[Currcity][0]!=0){
        int totalcost=currcost+matrix[Currcity][0];
        if(totalcost<mincost){
            mincost=totalcost;
            bestRoute=currentRoute;
        }
        return ;
    }
    for(int nextcity=0;nextcity<numcities;nextcity++){
        if(!visited[nextcity] && matrix[Currcity][nextcity]!=0){
            int newcost=currcost+matrix[Currcity][nextcity];
            visited[nextcity]=true;
            currentRoute.push_back(nextcity);

            int bound=estimatelowerbound(matrix,visited);
            if(newcost+bound<mincost){
                exploreroutes(matrix,visited,nextcity,cityvisit+1,newcost,mincost,currentRoute,bestRoute);
            }
            visited[nextcity]=false;
            currentRoute.pop_back();
        }
    }
}

int main(){
    int numcities;
    cout<<"enter the number of cities";
    cin>>numcities;
    vector<vector<int>>matrix(numcities,vector<int>(numcities));
    cout<<"Enter matrix"<<endl;
    for(int i=0;i<numcities;i++){
        for(int j=0;j<numcities;j++){
            cin>>matrix[i][j];
            if(matrix[i][j]==INF){
                matrix[i][j]=0;
            }
        }
    }
    vector<bool>visited(numcities,false);
    visited[0]=true;
    vector<int>currentRoute={0};
    vector<int>bestRoute;
    int mincost=INF;
    exploreroutes(matrix,visited,0,1,0,mincost,currentRoute,bestRoute);
    cout<<"Minimum cost "<<mincost<<endl;
    cout<<"Optimal Route :";
    for(int city:bestRoute){
        cout<<city<<"   ";
    }
    cout<<0<<endl;
    return 0;
}