#include <bits/stdc++.h>
using namespace std;

/* DFS algorithm
 * It is a recursive algorithm to search all the vertices of a tree data structure or a graph.
 * The depth-first search (DFS) algorithm starts with the initial node of graph G and goes deeper until we find the goal node or the node with no children.
 */

void dfs_iterative(int cur,unordered_map<int,list<int>> &adj_list,unordered_map<int,bool> &visited){
    stack<int> nodes;
    nodes.push(cur);

    while(!nodes.empty()){
        int node = nodes.top();
        nodes.pop();
        if(!visited[node]){
            cout<<node<<" ";
            visited[node] = true;
        }
        for(auto neigh:adj_list[node]){
            if(!visited[neigh]){
                nodes.push(neigh);
            }
        }
    }
    cout<<endl;
}


void dfs_recursive(int cur,unordered_map<int,list<int>> &adj_list,unordered_map<int,bool> &visited){
    cout<<cur<<" ";

    visited[cur] = true;
    for(int neigh:adj_list[cur]){
        if(!visited[neigh]){
            dfs_recursive(neigh,adj_list,visited);
        }
    }
}


void print(unordered_map<int,list<int>> &adj_list){
    for(auto kv_pairs : adj_list){
        cout<<kv_pairs.first<<": {";
        for(auto v : kv_pairs.second){
            cout<<v<<", ";
        }
        cout<<"}"<<endl;
    }
}

int main(){
    vector<pair<int,int>> edges{
            {1,3},
            {1,4},
            {2,8},
            {2,4},
            {3,5},
            {3,8},
            {4,9},
            {4,8},
            {5,7},
            {6,7},
            {6,8},
    };

    unordered_map<int,list<int>> adj_list;
    for(auto edge : edges){
        adj_list[edge.first].push_back(edge.second);
        adj_list[edge.second].push_back(edge.first);
    }

    unordered_map<int,bool> visited1;
    unordered_map<int,bool> visited2;

    print(adj_list);
    dfs_iterative(7,adj_list,visited2);
    dfs_recursive(7,adj_list,visited1);            //7 5 3 1 4 2 8 6 9


    return 0;
}
