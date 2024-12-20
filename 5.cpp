#include <bits/stdc++.h>
using namespace std;

string sortWord(const string &word) {
    string sorted_word = word;
    sort(sorted_word.begin(), sorted_word.end());
    return sorted_word;
}

int countAnigrams(const unordered_map<string, int> &sorted_word_map,
                 const unordered_map<string, int> &word_count_map,
                 const string &query_word) {
    string sorted_query = sortWord(query_word);
    auto it = sorted_word_map.find(sorted_query);
    if (it == sorted_word_map.end()) {
        return 0; 
    }
    int total = it->second;
    auto it_word = word_count_map.find(query_word);
    int same_word_count = (it_word != word_count_map.end()) ? it_word->second : 0;
    int anigram_count = total - same_word_count;
    return (anigram_count > 0) ? anigram_count : 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    unordered_map<string, int> sorted_word_map;
    unordered_map<string, int> word_count_map;
    
    for(int i = 0; i < N; ++i){
        string word;
        cin >> word;
        string sorted = sortWord(word);
        sorted_word_map[sorted]++;
        word_count_map[word]++;
    }
    
    int Q;
    cin >> Q;
    
    while(Q--){
        string query_word;
        cin >> query_word;
        int result = countAnigrams(sorted_word_map, word_count_map, query_word);
        cout << result << "\n";
    }
    
    return 0;
}
