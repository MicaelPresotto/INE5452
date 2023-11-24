#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<unordered_map>
#include<utility>
#include<queue>
#include<functional>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> d(adj.size(), 1e9);
    d[src] = 0;
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    pq.push({0, src});
    
    while (!pq.empty()) {
        auto& nd = pq.top();
        int w = nd.first;
        int u = nd.second;
        pq.pop();
        
        if (w > d[u]) continue;
        
        for (auto& nh : adj[u]) {
          int wv = nh.first;
          int v = nh.second;
          
          if (d[u] + wv >= d[v]) continue;
          
          d[v] = d[u] + wv;
          pq.push({d[v], v});
        }
    }
    
    return d;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int m;
    while (cin >> m && m) {
        string o, d;
        cin >> o >> d;
        
        vector<vector<pair<int,int>>> adj(m+2); // m + src + dest
        unordered_map<string, int> mp;
        int cnt = 1;
        
        unordered_map<string, vector<string>> lang_col;
        
        for (int i = 0; i < m; ++i) {
            string l1, l2, w;
            cin >> l1 >> l2 >> w;
            
            if (!mp.count(w))
                mp[w] = cnt++;
            
            lang_col[l1].push_back(w);
            lang_col[l2].push_back(w);
        }
        
        for (auto& p : lang_col) {
            auto& colors = p.second;
            for (int i = 0; i < colors.size(); ++i) {
                string& col = colors[i];
                for (int j = i+1; j < colors.size(); ++j) {
                    if (col[0] == colors[j][0]) continue;
                    
                    int col_i = mp[col];
                    int col_j = mp[colors[j]];
                    
                    adj[col_i].push_back({colors[j].size(),  col_j});
                    adj[col_j].push_back({col.size(), col_i});
                }
            }
        }
        
        for (string& c : lang_col[o])
            adj[0].push_back({c.size(), mp[c]});
        for (string& c : lang_col[d])
            adj[mp[c]].push_back({0, cnt});
        
        int ans = dijkstra(adj, 0)[cnt];
        if (ans == 1e9)
            cout << "impossivel\n";
        else
            cout << ans << '\n';
        
    }
}