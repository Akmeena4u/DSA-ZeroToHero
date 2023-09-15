void leftRotate(int arr[], int n, int d) {
    if (n == 0) return;

    // Get the effective number of rotations:
    d = d % n;

    //checking if d is a multiple of n:
    if (d == 0) return;

    int temp[d]; // temporary array

    //step 1: Copying first d elements
    // in the temporary array:
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    // step 2: Shift last (n-d) elements
    // to the left by d places in the given array:
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    //step 3: Place the elements of the temporary
    // array in the last d places of the given array:
    for (int i = n - d; i < n; i++) {
        arr[i] = temp[i - (n - d)];
    }
}
