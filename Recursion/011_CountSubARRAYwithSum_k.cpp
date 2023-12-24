void solve(vector<int>& a, int ind, int& count, int k, int sum) {
    if (ind == a.size()) {
        if (sum == k) {
            count++;
        }
        return;
    }

    // Take the current element
    solve(a, ind + 1, count, k, sum + a[ind]);

    // Don't take the current element
    solve(a, ind + 1, count, k, sum);
}

int subarraysWithSumK(vector<int> a, int k) {
    int count = 0;
    solve(a, 0, count, k, 0);
    return count;
}
