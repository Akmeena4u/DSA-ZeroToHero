
//approch:--
//step -1 --store first elemnets in temp variable 
//step 2- shift all elements one place left
//step-3-- insert temp element in last to rotate array by one place 


void solve(int arr[], int n) {
  int temp = arr[0]; // storing the first element of array in a variable
  for (int i = 0; i < n - 1; i++) {
    arr[i] = arr[i + 1];
  }
  arr[n - 1] = temp; // assigned the value of variable at the last index
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

}
