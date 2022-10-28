/*

unordered_multimap in STL are associative containers like unordered maps where each element consists of a key value and a mapped value, 
the only difference is unordered multimaps can store duplicate elements
*/

#include<bits/stdc++.h>

using namespace std;

int main() {
  unordered_multimap < int, int > mp;
  for (int i = 1; i <= 5; i++) {
    mp.insert({i , i * 10});
  }
  mp.insert({4,40});

  cout << "Elements present in the unordered multimap: " << endl;
  cout << "Key\tElement" << endl;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it -> first << "\t" << it -> second << endl;
  }

  int n = 2;
  if (mp.find(2) != mp.end())
    cout << n << " is present in unordered multimap" << endl;

  mp.erase(mp.begin());
  cout << "Elements after deleting the first element: " << endl;
  cout << "Key\tElement" << endl;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it -> first << "\t" << it -> second << endl;
  }

  cout << "The size of the unordered multimap is: " << mp.size() << endl;

  if (mp.empty() == false)
    cout << "The unordered multimap is not empty " << endl;
  else
    cout << "The unordered multimap is empty" << endl;
  mp.clear();
  cout << "Size of the unordered multimap after clearing all the elements: " 
  << mp.size();
}
