#include<iostream>
using namespace std;

int main()
{
    int a,b,ch,add,sub,multi,div;
cout<<"enter two number";
cin>>a>>b;
cout<<"enter choice";
cin>>ch;
if(ch==1){
	add=a+b;
	cout<<add;
}
else if(ch==2){
	sub=a-b;
	cout<<sub;
}
else if(ch==3)
{multi=a*b;
cout<<multi;
}
else if(ch==4){
div=a/b;
cout<<div;}
else{
	cout<<"invalid statement";
}
return 0;
    return 0;
}
