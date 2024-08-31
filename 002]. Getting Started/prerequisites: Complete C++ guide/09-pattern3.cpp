/*
1111
222
33
4

*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int i=1;
    while(i<=n){
        int j=i;
        
        while(j<=n){
            cout<<i;
            j++;
        }
        
        cout<<endl;
        i++;
    }

    return 0;
}
