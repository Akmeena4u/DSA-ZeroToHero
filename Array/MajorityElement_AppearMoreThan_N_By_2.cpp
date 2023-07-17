
//. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
int majorityElement(int a[], int size)
    {
        
        // your code hereint n = v.size();

    //declaring a map:
    map<int, int> mpp;

    //storing the elements with its occurnce:
    for (int i = 0; i < size; i++) {
        mpp[a[i]]++;
    }

    //searching for the majority element:
    for (auto it : mpp) {
        if (it.second > (size / 2)) {
            return it.first;
        }
    }

    return -1;
        
    }

//optimal app === Moore’s Voting Algorithm:
int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
}
