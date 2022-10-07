


/*

pattern 2--

11111
22222
33333
44444
55555

*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int i=1;
    while(i<=n){
        int j=1;
        
        while(j<=n){
            cout<<i;
            j++;
        }
        
        cout<<endl;
        i++;
    }

    return 0;
}
