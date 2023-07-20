void heapify(vector<int>& ans, int n, int i) {
        int largest = i;
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;

        if (leftIndex < n && ans[leftIndex] > ans[largest]) {
            largest = leftIndex;
        }
        if (rightIndex < n && ans[rightIndex] > ans[largest]) {
            largest = rightIndex;
        }

        if (largest != i) {
            swap(ans[i], ans[largest]);
            heapify(ans, n, largest);
        }
    }

    vector<int> mergeHeaps(vector<int>& a, vector<int>& b, int n, int m) {
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(a[i]);
        }

        for (int i = 0; i < m; i++) {
            ans.push_back(b[i]);
        }

        int N = n + m;

        for (int i = N / 2 - 1; i >= 0; i--) {
            heapify(ans, N, i);
        }
        return ans;
    }
