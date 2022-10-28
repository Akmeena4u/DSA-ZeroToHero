/*

In the case of the min heap, priority queues are a type of container adaptors, 
specifically designed such that its first element is always the smallest of the elements it contains and the rest elements are in increasing order.

priority_queue<object_type,vector<object_type>,greater<object_type>> variable_name;

*/

#include<bits/stdc++.h>
using namespace std;
void printpriorityqueue(priority_queue<int,vector<int>,greater<int>> pq)
{
    priority_queue<int,vector<int>,greater<int>> pq2=pq;
    while(!pq.empty())
    {
        cout<<pq.top()<<"\n";
        pq.pop();
    }
}
int main()
{
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<=5;i++)
    pq.push(i);
    
    cout<<"The elements of the priority queue are:"<<endl;
    printpriorityqueue(pq);
    
    cout<<"The size of the priority queue: "<<pq.size()<<endl;
    cout<<"The top element of the priority queue: "<<pq.top()<<endl;
    cout<<"Pop the top element: "<<endl;
    pq.pop();
    printpriorityqueue(pq);
}
