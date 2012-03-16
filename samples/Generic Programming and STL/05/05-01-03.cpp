#include <iterator>
using namespace std;

template <class T, size_t N>
struct block {
  typedef T value_type;
  
  typedef value_type* pointer;
  typedef const value_type* const_pointer;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  
  typedef ptrdiff_t difference_type;
  typedef size_t size_type;
  
  typedef pointer iterator;
  typedef const_pointer const_iterator;
  
  iterator begin() { return data; }
  iterator end() { return data + N; }
  
  const_iterator begin() const { return data; }
  const_iterator end() const { return data + N; }

  typedef reverse_iterator<const_iterator> const_reverse_iterator;
  typedef reverse_iterator<iterator> reverse_iterator;
  
  reverse_iterator rbegin() { return reverse_iterator(end()); }
  reverse_iterator rend() { return reverse_iterator(begin()); }

  const_reverse_iterator rbegin() const {
    return const_reverse_iterator(end()); 
  }
  const_reverse_iterator rend() const {
    return const_reverse_iterator(begin()); 
  }
  
  reference operator[](size_type n) { return data[n]; }
  const_reference operator[](size_type n) const { return data[n]; }
  
  size_type size() const { return N; }
  size_type max_size() const { return N; }
  bool empty() const { return N == 0; }
  
  void swap(block& x) {
    for (size_t n = 0; n < N; ++n)
      std::swap(data[n], x.data[n]);
  }

  T data[N];
};

template <class T, size_t N>
bool operator==(const block<T,N>&x, const block<T,N>& y)
{
  for (size_t n = 0; n < N; ++n)
    if (x.data[n] != y.data[n])
      return false;
    return true;
}

template <class T, size_t N>
bool operator<(const block<T,N>&x, const block<T,N>& y)
{
  for (size_t n = 0; n < N; ++n)
    if (x.data[n] < y.data[n])
      return true;
    else if (y.data[n] > x.data[n])
      return false;
    return false;
}

int main(int argc, char *argv[])
{
  block<int, 6> A = {1, 4, 2, 8, 5, 7};

  return 0;
}
