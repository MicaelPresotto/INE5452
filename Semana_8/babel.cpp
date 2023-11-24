// graph modeling
// each word is a vertex
// connect two words if they share common language and differ 1st letter
// cconnect a source vertex to all words that belong to start language
// connect all words that belong to finish language to sink vertex
// edge weight = word.size()
// djisktra


#include <iostream>
#include <string>
#include <vector>
#include <map>

bool is_there_false_in_visited(std::vector<bool>& visited){
    for(const auto& v : visited){
        if(!v) return true;
    }
    return false;
}

int minimum_distance(std::vector<int> dist, std::vector<bool> visited){
    int min = 10000000;
    int min_index = -1;
    for(int i = 0; i < dist.size(); i++){
        if(!visited[i] && dist[i] <= min){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

int dijsktra(std::vector<std::vector<int>>& adj_list, std::map<std::pair<int, int>, int>& edges, int start, int finish){
    std::vector<int> dist(adj_list.size(), 10000000);
    dist[start] = 0;
    std::vector<bool> visited(adj_list.size(), false);
    while(is_there_false_in_visited(visited)){
        int u = minimum_distance(dist, visited);
        visited[u] = true;
        for(const auto& v : adj_list[u]){
            if(!visited[v] && dist[u] != 10000000 && dist[u] + edges[std::make_pair(u, v)] < dist[v]){
                dist[v] = dist[u] + edges[std::make_pair(u, v)];
            }
        }
    }
    return dist[finish];
}

int main(void){
    for(;;){
        int n;
        std::string start, finish;
        std::cin >> n;
        if(n==0) break;
        std::cin >> start >> finish;
        std::map<std::string, int> graph;
        std::map<std::pair<int, int>, int> edges;
        std::map<std::pair<std::string, std::string>, std::string> languages;
        std::vector<std::vector<int>> adj_list(n+2);
        graph["start"] = 0;
        graph["finish"] = n+1;
        for(int i = 0; i < n; i++){
            std::string lang1, lang2, word;
            std::cin >> lang1 >> lang2 >> word;
            languages[std::make_pair(lang1, lang2)] = word;
            graph[word] = i+1;
        }
        for(const auto& language : languages){
            if(language.first.first == start || language.first.second == start){
                adj_list[0].push_back(graph[language.second]);
                edges[std::make_pair(0, graph[language.second])] = language.second.size();
            }
            if(language.first.second == finish || language.first.first == finish){
                adj_list[graph[language.second]].push_back(n+1);
                edges[std::make_pair(graph[language.second], n+1)] = 0;
            }
            for(const auto& language2 : languages){
                if(language.first.first == language2.first.second || language.first.second == language2.first.first || language.first.first == language2.first.first || language.first.second == language2.first.second){
                    if(language.second[0] != language2.second[0]){
                        adj_list[graph[language.second]].push_back(graph[language2.second]);
                        edges[std::make_pair(graph[language.second], graph[language2.second])] = language2.second.size();
                    }
                }
            }
        }
        int result = dijsktra(adj_list, edges, 0, n+1);
        if(result != 10000000)std::cout << result << std::endl;
        else std::cout << "impossivel" << std::endl;
        
    }
}