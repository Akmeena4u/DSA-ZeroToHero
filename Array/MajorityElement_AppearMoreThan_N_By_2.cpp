
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
