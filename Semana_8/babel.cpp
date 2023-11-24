#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

bool is_there_false_in_visited(std::vector<bool>& visited) {
    for (const auto& v : visited) {
        if (!v) return true;
    }
    return false;
}

int minimum_distance(std::vector<int> dist, std::vector<bool> visited) {
    int min = 1e9;
    int min_index = -1;
    for (int i = 0; i < dist.size(); i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

int dijkstra(std::vector<std::vector<int>>& adj_list, std::map<std::pair<int, int>, int>& edges, int start, int finish) {
    std::vector<int> dist(adj_list.size(), 1e9);
    dist[start] = 0;
    std::vector<bool> visited(adj_list.size(), false);
    while (is_there_false_in_visited(visited)) {
        int u = minimum_distance(dist, visited);
        visited[u] = true;
        for (const auto& v : adj_list[u]) {
            if (!visited[v] && dist[u] != 1e9 && dist[u] + edges[std::make_pair(u, v)] < dist[v]) {
                dist[v] = dist[u] + edges[std::make_pair(u, v)];
            }
        }
    }
    return dist[finish];
}

int main(void) {
    for (;;) {
        int n;
        std::string start, finish;
        std::cin >> n;
        if (n == 0) break;
        std::cin >> start >> finish;
        std::unordered_map<std::string, int> graph;
        std::map<std::pair<int, int>, int> edges;
        std::unordered_map<std::string, std::vector<std::string>> languages;
        std::vector<std::vector<int>> adj_list(n + 2);
        graph["start"] = 0;
        graph["finish"] = n + 1;
        int cont = 1;
        for (int i = 0; i < n; i++) {
            std::string lang1, lang2, word;
            std::cin >> lang1 >> lang2 >> word;
            if (!graph.count(word))
                graph[word] = cont++;

            languages[lang1].push_back(word);
            languages[lang2].push_back(word);
        }
        for (auto& lang : languages) {
            auto& words = lang.second;
            for (int i = 0; i < words.size(); ++i) {
                std::string word1 = words[i];
                for (int j = i + 1; j < words.size(); ++j) {
                    if (word1[0] == words[j][0]) continue;

                    int col_i = graph[word1];
                    int col_j = graph[words[j]];

                    adj_list[col_i].push_back(col_j);
                    adj_list[col_j].push_back(col_i);
                    edges[std::make_pair(col_i, col_j)] = words[j].size();
                    edges[std::make_pair(col_j, col_i)] = word1.size();
                }
            }
        }
        for (auto& word : languages[start]) {
            int col = graph[word];
            adj_list[0].push_back(col);
            edges[std::make_pair(0, col)] = word.size();
        }
        for (auto& word : languages[finish]) {
            int col = graph[word];
            adj_list[col].push_back(n + 1);
            edges[std::make_pair(col, n + 1)] = 0;
        }
        int result = dijkstra(adj_list, edges, 0, n + 1);
        if (result != 1e9)
            std::cout << result << std::endl;
        else
            std::cout << "impossivel" << std::endl;
    }
    return 0;
}
