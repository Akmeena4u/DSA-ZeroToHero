 public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
      int index = i;
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;
        int largest = index;

        if (leftIndex < n && arr[largest] < arr[leftIndex])
        {
            largest = leftIndex;
        }
        if (rightIndex < n && arr[largest] < arr[rightIndex])
        {
            largest = rightIndex;
        }

        if (index != largest)
        {
            swap(arr[index], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
     for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
         buildHeap(arr, n);

        while (n > 1)
        {
            swap(arr[0], arr[n - 1]);
            n--;
            heapify(arr, n, 0);
        }
    }
