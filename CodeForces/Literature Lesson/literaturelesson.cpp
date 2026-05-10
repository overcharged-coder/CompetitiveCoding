/*
Problem Name: Literature Lesson
Link to problem: https://codeforces.com/problemset/problem/138/A
*/

#include <bits/stdc++.h>
using namespace std;
string vowels = "aeiou";
vector<string> rhymes = {"0011", "0101", "0110", "0000"};

int main() {
    int n, k, cur_vowel; string line, prev_rhyme, suffix; bool foundrvowel; cin >> n >> k; vector<string> rhyme_poem(n);
    for (int i = 0; i < n; i++){
        unordered_map<string, int> rhyming;
        for (int j = 0; j < 4; j++){
            cur_vowel = 0; foundrvowel = false;
            cin >> line;
            for (int m = line.size() - 1; m >= 0; m--){
                if (vowels.find(line[m]) != string::npos){
                    cur_vowel++;
                    if (cur_vowel == k){
                        foundrvowel = true;
                        suffix = line.substr(m);
                        rhyming.insert({suffix, rhyming.size()});
                        break;
                    }
                }
            }
            if (!foundrvowel){
                cout << "NO"; return 0;
            }
            rhyme_poem[i].push_back('0' + rhyming[suffix]);
        }
    }
    prev_rhyme = rhyme_poem[0];
    for (int i = 0; i < rhyme_poem.size(); i++){
        if (find(rhymes.begin(), rhymes.end(), rhyme_poem[i]) == rhymes.end()){
            cout << "NO"; return 0;
        }
        if (rhyme_poem[i] != prev_rhyme && rhyme_poem[i] != "0000" && prev_rhyme != "0000"){
            cout << "NO"; return 0;
        }
        if (rhyme_poem[i] != "0000") prev_rhyme = rhyme_poem[i];
    }
    for (int i = 0; i < 4; i++){
        if (prev_rhyme[i] == '0') prev_rhyme[i] = 'a';
        else if (prev_rhyme[i] == '1') prev_rhyme[i] = 'b';
    }
    cout << prev_rhyme;
}