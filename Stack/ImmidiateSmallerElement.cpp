void immediateSmaller(vector<int>&arr, int n) {
	    //  code here
	     vector<int> ans(n, -1);
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                ans[i] = arr[i + 1];
            }
        }
        for (int i = 0; i < n; i++) {
            arr[i] = ans[i];
        }
	}
