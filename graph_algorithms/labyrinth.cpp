//
// Created by lakshmiram  on 03/06/24.
//
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
int n, m;
vector< vector<int> > edges;
bool is_inside(int node){
    if(0<= node && node < n*m){
        return true;
    }
    return false;
}
vector<bool> visited;
vector<int> p;
vector<int> d;
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
            if(visited[neigh] != 1){
                visited[neigh] = 1;
                d[neigh] = 1 + d[temp];
                p[neigh] = temp;
                q.push(neigh);
            }
        }

    }



}
int main(){
    cin >> n >> m;
    edges.assign(n*m, vector<int>());
    vector<char> a(n*m);
    int start, end;
    for(int i=0;i<n*m;i++){
        cin >> a[i];
    }
    for(int i=0;i<n*m;i++){
        if(a[i] == 'A'){
            start = i;
        }
        else if(a[i] == 'B'){
            end = i;
        }

    }

    for(int node = 0; node< n*m;node++){
        if(a[node]!= '#'){
            //find out the neighbours
            if( a[node+1]!='#' && node%m !=m-1){
                //node+1 is a valid neighbour
                edges[node].push_back(node+1);
            }
            if( a[node-1]!='#' && node%m !=0){
                edges[node].push_back(node-1);
            }
            if(is_inside(node-m) && a[node-m]!='#'){
                edges[node].push_back(node-m);
            }
            if(is_inside(node+m) && a[node+m]!='#'){
                edges[node].push_back(node+m);
            }
        }
    }
    visited.assign(n*m ,false);
    d.assign(n*m,0);
    p.assign(n*m,0);

    bfs(start);
    //remember to clear all the vectors before another bfs
    if(visited[end] == 0){
        cout << "NO" << endl;
        return 0;
    }
    else{
        string path;
        for(int node = end; p[node] != -1; node = p[node]){
            if(node - p[node] == 1){
                //parent node is to the left of node
                //so print R
                path += 'R';
            }
            else if(node - p[node] == -1){
                path += 'L';
            }
            else if(node - p[node] == m){
                path += 'D';
            }
            else{
                path += 'U';
            }
        }
        reverse(path.begin(), path.end());
        cout << "YES" << endl << d[end] << endl << path << endl;
        return 0;

    }
}
