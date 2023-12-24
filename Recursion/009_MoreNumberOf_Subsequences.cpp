//TLE- 34/50


void solve(const string& s, int ind, string& str, unordered_set<string>& result) {
    if (ind >= s.size()) {
        result.insert(str);
        return;
    }

    solve(s, ind + 1, str, result); // take
    str.push_back(s[ind]);
    solve(s, ind + 1, str, result); // not take
    str.pop_back(); // Backtrack to remove the last character
}

string moreSubsequence(int n, int m, string a, string b) {
    unordered_set<string> resultA, resultB;

    string temp = "";
    solve(a, 0, temp, resultA);
    solve(b, 0, temp, resultB);

    if (resultA.size() >= resultB.size()) {
        return a;
    } else {
        return b;
    }
}
