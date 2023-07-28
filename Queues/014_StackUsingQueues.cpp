/*
m1--use two queues
approch--
push x to q2
q1-->q2
q2--q1

*/

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
        // Your Code
        q2.push(x);
       
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
        
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code  
         if(q1.empty())  return -1;
        int x=q1.front();
        q1.pop();
        return x;
}

/*m2-- Qusing single queue

Approach:

Take a single queue.
push(x): Push the element in the queue.
Use a for loop of size()-1, remove element from queue and again push back to the queue, hence the most recent element becomes the most former element and vice versa.
pop(): remove the element from the queue.
top(): show the element at the top of the queue.
size(): size of the current queue.

  */
#include<bits/stdc++.h>

using namespace std;

class Stack {
  queue < int > q;
  public:
    void Push(int x) {
      int s = q.size();
      q.push(x);
      for (int i = 0; i < s; i++) {

        q.push(q.front());
        q.pop();
      }
    }
  int Pop() {
    int n = q.front();
    q.pop();
    return n;
  }
  int Top() {
    return q.front();
  }
  int Size() {
    return q.size();
  }
};

int main() {
  Stack s;
  s.Push(3);
  s.Push(2);
  s.Push(4);
  s.Push(1);
  cout << "Top of the stack: " << s.Top() << endl;
  cout << "Size of the stack before removing element: " << s.Size() << endl;
  cout << "The deleted element is: " << s.Pop() << endl;
  cout << "Top of the stack after removing element: " << s.Top() << endl;
  cout << "Size of the stack after removing element: " << s.Size();

}
