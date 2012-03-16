#include <iostream>
#include <cstdlib>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
  list<int> L;
  generate_n(front_inserter(L), 1000, rand);
  
  list<int>::const_iterator it = min_element(L.begin(), L.end());
  cout << "The smallest element is " << *it << endl;
}
