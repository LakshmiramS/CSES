//
// Created by lakshmiram  on 07/06/24.
//
/*
 * i represent nodes using a single number between 0 and N-1, where N = n(total no of rows in the matrix) * m (no of cols)
 * the row and col of a given node n can be obtained by row = n/m and col = n%m 
 * IDEA OF SOLUTION: if A is closer to a border node than the closest monster, then we have solution.
 * we use multi-source bfs to find the distance of the closest monster to each border node and compare it with how far A is from the same border node
 * using a fake source node as suggested here https://codeforces.com/blog/entry/54310 proves to be very user friendly!
 * the fake source node in my code is the node number N(whose neighbours are the monsters).
 * note that we don't have to maintain a separate adjacency list for neighbour nodes because we know the location of the neighbours for 
 * every node(up, down, left and right).
 */

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>

using namespace std;

int n, m, N;
vector<int> d,d1;
vector<int> p;
queue<int> q;
vector<bool> visited;
int oo = INT_MAX;
vector<char> a;
vector<int> monsters;

bool is_inside(int node){
    //check if a node is within range
    return 0<= node && node < n*m ;
}

void bfs(int s){
    q.push(s);
    visited[s] = 1;
    p[s] = -1;
    d[s] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        vector<int> neigh;
        if(node == N){
//            neigh = source_neighbours;
            for(int v : monsters){
                neigh.push_back(v);
            }
        }
        else{
            if (a[node + 1] != '#' && node % m != m - 1) {
                //node+1 is a valid neighbour
                neigh.push_back(node + 1);
            }
            if (a[node - 1] != '#' && node % m != 0) {
                neigh.push_back(node - 1);
            }
            if (is_inside(node - m) && a[node - m] != '#') {
                neigh.push_back(node - m);
            }
            if (is_inside(node + m) && a[node + m] != '#') {
                neigh.push_back(node + m);
            }
        }
        for(int v : neigh){
            if(visited[v]) continue;
            visited[v] = 1;
            d[v] = 1 + d[node];
            p[v] = node;
            q.push(v);
        }

    }
}



int main(){
    cin >> n >> m;
    N = n*m;
    
    //input the graph 
    a.assign(N+1, '.');
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    int A;
    for(int i=0;i<N;i++){
        if(a[i] == 'A'){
            A = i;
        }
        else if(a[i] == 'M'){
            monsters.push_back(i);
        }
    }
    //find border nodes
    vector<int> borders;
    for(int node = 0; node < n*m ; node++) {
        int row = node / m;
        int col = node % m;
        if ((row == 0 || row == n - 1 || col == 0 || col == m - 1 )&& (a[node] != '#')){
            borders.push_back(node);
        }
    }
    //prepare for bfs of fake node(and therefore the monsters)
    int source = N;
    d.assign(N+1, oo);
    p.assign(N+1, 0);
    visited.assign(N+1, 0);
    bfs(source);
    d1.assign(N+1, 0);
    
    for(int i=0;i<N+1;i++){
        //we need to subtract 1 from all the distances because the fake node introduces and extra edges in the path.
        d1[i] = d[i] - 1;
    }
    //bfs from A
    d.assign(N+1, oo);
    p.assign(N+1, 0);
    visited.assign(N+1, 0);
    bfs(A);
    for(int border_node : borders){
        if(d[border_node] < d1[border_node]){
            //we have a solution
            //retrace the path.
            string path;
            for(int node = border_node; p[node] != -1; node = p[node]){
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
            cout << "YES" << endl;
            cout << d[border_node] << endl;
            cout << path << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
