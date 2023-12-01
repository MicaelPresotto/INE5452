// floyd-warshall

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<int>> floydwarshall(int num_of_vertices, map<pair<int,int>, int>& edges){
    vector<vector<int>> dist(num_of_vertices+1, vector<int>(num_of_vertices+1, 1e9));
    for(int i = 0; i < num_of_vertices+1; i++) dist[i][i] = 0;
    for(const auto& edge : edges){
        dist[edge.first.first][edge.first.second] = edge.second;
    }
    for(int k = 0; k < num_of_vertices; k++){
        for(int i = 0; i < num_of_vertices; i++){
            for(int j = 0; j < num_of_vertices; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist;
}

// falta fazer o problema