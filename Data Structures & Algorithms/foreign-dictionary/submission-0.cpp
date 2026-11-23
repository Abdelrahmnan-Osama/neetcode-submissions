class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> inDegree;

        for(auto word : words) {
            for(auto c : word) {
                graph[c];
                inDegree[c] = 0;
            }
        }

        for(int i = 1; i < words.size(); i++) {
            auto word1 = words[i - 1]; 
            auto word2 = words[i];

            int minLen = min(word1.size(), word2.size());

            if(word1.size() > word2.size() && word1.substr(0, minLen) == word2.substr(0, minLen))
                return "";

            for(int j = 0; j < minLen; j++) {
                if(word1[j] != word2[j]) {
                    if(graph[word1[j]].insert(word2[j]).second)
                        inDegree[word2[j]]++;

                    break;
                }
            }
        }

        queue<char> q;
        for(const auto& [c , indeg] : inDegree) {
            if(indeg == 0)
                q.push(c);
        }

        string result;
        while(!q.empty()) {
            char c = q.front();
            q.pop();

            result += c;

            for(auto neighbor : graph[c]) {
                if(--inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return (result.size() == inDegree.size()) ? result : "";
    }
};
