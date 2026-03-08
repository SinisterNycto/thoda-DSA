#include <bits/stdc++.h>
using namespace std;

void solve(int idx, string &s, string &curr, vector<string> &res){
    if(idx == s.length()){
        res.push_back(curr);
        return;
    }

    // lower_case
    char ch1 = tolower(s[idx]);
    curr.push_back(ch1);
    solve(idx + 1, s, curr, res);
    curr.pop_back();

    // upper case
    char ch2 = toupper(s[idx]);
    curr.push_back(ch2);
    solve(idx + 1, s, curr, res);
    curr.pop_back();
}

vector<string> casePermutations(string s){
    vector<string> res;
    string curr = "";

    solve(0, s, curr, res);

    return res;
}

int main() {
    string s;
    cin >> s;

    vector<string> res = casePermutations(s);

    for(string &str: res){
        cout << str << endl;
    }
    
    return 0;
}
