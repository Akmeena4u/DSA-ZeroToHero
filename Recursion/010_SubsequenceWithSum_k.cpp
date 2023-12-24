

void solve(vector<int>& a, int ind, vector<int>& current, vector<vector<int>>& result, int k, int sum) {
    if (ind == a.size()) {
        if (sum == k) {
            result.push_back(current);
        }
        return;
    }

    // Take the current element
    current.push_back(a[ind]);
    solve(a, ind + 1, current, result, k, sum + a[ind]);
    current.pop_back();

    // Don't take the current element
    solve(a, ind + 1, current, result, k, sum);
}

vector<vector<int>> subarraysWithSumK(vector<int> a, int k) {
    vector<vector<int>> result;
    vector<int> current;

    solve(a, 0, current, result, k, 0);

    // Sort the subarrays lexicographically
    for (auto& subarr : result) {
        sort(subarr.begin(), subarr.end());
    }

    // Sort the entire result based on the first element of each subarray
    sort(result.begin(), result.end());

    // Remove duplicates
    result.erase(unique(result.begin(), result.end()), result.end());

    return result;
}

