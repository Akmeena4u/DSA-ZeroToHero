void rearrange(vector<int> &arr) {
    // Create two separate vectors to hold positive and negative numbers
    vector<int> positive, negative;

    // Iterate through the array and distribute numbers into positive and negative vectors
    for(auto x : arr){
        if(x >= 0) 
            positive.push_back(x);  // Add positive numbers to 'positive' vector
        else 
            negative.push_back(x);  // Add negative numbers to 'negative' vector
    }

    // Initialize pointers for positive, negative, and the main array index
    int i = 0, j = 0, k = 0;

    // Alternate between adding elements from positive and negative vectors to the main array
    while(i < positive.size() && j < negative.size()){
        if(k % 2 == 0) 
            arr[k++] = positive[i++];  // Place a positive number in even positions
        else 
            arr[k++] = negative[j++];  // Place a negative number in odd positions
    }

    // If there are remaining positive numbers, add them to the main array
    while(i < positive.size()) 
        arr[k++] = positive[i++];

    // If there are remaining negative numbers, add them to the main array
    while(j < negative.size()) 
        arr[k++] = negative[j++];
}
