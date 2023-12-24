bool prints(int ind,vector<int>ds,int sum,int k,vector<int>&a,int n){

    if(sum>k)return false;               //secondary base case 

    if(ind==n){                         //primary base case

        if(sum==k)return true; 

        else return false;

    }

    ds.push_back(a[ind]);

    sum+=a[ind];

    if(prints(ind+1, ds, sum, k, a, n))return true;  //pick

    sum-=a[ind];

    ds.pop_back();

    if(prints(ind+1, ds, sum, k, a, n))return true; //not pick

    return false;

}

bool isSubsetPresent(int n, int k, vector<int> &a)

{

    vector<int>ds;

    return prints(0,ds,0,k,a,n);

}
