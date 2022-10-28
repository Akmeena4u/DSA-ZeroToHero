
/*

Sorting is one of the most standard operations used very frequently while writing programs.
Writing the complete sorting algorithm might be time consuming and hence STL provides us with a standard inbuilt function to sort any container very easily.

sort(begin, end)

*/

//ARRAY

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    
    int arr[] = {4,2,1};

    sort(arr, arr+3);
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
    return 0;
}

//VECTOR

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    
    vector<int> vec = {4,2,1};

    sort(vec.begin(), vec.end());
    
    cout<<vec[0]<<" "<<vec[1]<<" "<<vec[2];
    
    return 0;
}

//sort a container in descending order using sort()
/*

by using comparators. The role of a comparator in most functions is to compare between two elements before performing an operation

In STL, we already have a comparator defined to do this which is called greater(). We just need to pass this greater<container_data_type>() as the
third parameter to sort function as shown in the below codes and it will sort the comparator in descending order.

*/


//aRRAY

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    
    int arr[] = {4,2,1};

    sort(arr, arr+3, greater<int>());
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
    return 0;
}

//VECTOR

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    
    vector<int> vec = {4,2,1};

    sort(vec.begin(), vec.end(), greater<int>());
    
    cout<<vec[0]<<" "<<vec[1]<<" "<<vec[2];
    
    return 0;
}
