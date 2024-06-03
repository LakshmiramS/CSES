//
// Created by lakshmiram  on 03/06/24.
//
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector< vector<int> > edges;

vector<bool> visited;
vector<int> d;
vector<int> p;
void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    d[start] = 0;
    p[start] = -1;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int neigh : edges[temp]){
            if(!visited[neigh]){
                visited[neigh] = 1;
                d[neigh] = 1 + d[temp];
                p[neigh] = temp;
                q.push(neigh);
            }
        }
    }


}
int main(){
    int n, m;
    cin >> n >> m;
    edges.assign(n, vector<int>());
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    d.assign(n, 0);
    p.assign(n,0);
    visited.assign(n, false);
    bfs(0);
    if(!visited[n-1]){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    else{
        cout << d[n-1] + 1 << endl;
        vector<int> path;
        for(int node = n-1; p[node] != -1; node = p[node]){
            path.push_back(node);
        }
        reverse(path.begin(),path.end());
        cout << 1 << " ";
        for(int node : path){
            cout << node + 1 << " ";
        }
        cout << endl;
        return 0;
    }

}
