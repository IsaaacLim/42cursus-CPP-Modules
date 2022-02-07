# Topics Covered

## Standard Template Library(STL)

### ex00

- **Obj: Intro to STL**
- Sequence Containers: `vector`, `list`, `deque`
  - `push_back()`, `push_front()`, `insert()`, `resize()`, `pop_back()`, `pop_front()`
- Associative Contianers: `set`, `multiset`, `map`, `multimap`
- Algorithm: `find()`, `distance`
- Iterators
- With template functions for STL

### ex01

- **Obj: Find the smallest and largest span within a container**
- Iterators: passing iterators to copy container values
- Algorithm: `min_element()`, `erase()`, `sort()`, `.end()[-1]`

### ex02

- Issue with separating the **implementation** of a **template class** from the `Class.hpp` file into the `Class.cpp` file
  - `main.cpp` & `Mutantstack.cpp` will be compiled separately first
  - In `main.cpp`, the compiler will _implicity_ instantiate the template class `MutantStack<int>` because those particular instantitations are used in `main.cpp`
  - In `MutantStack.cpp`, the compiler won't compile those instantiations because there are no implicit or explicit instantitations of `MutantStack<int>` (it doesn't exist in the header file or in `main.o`)
  - <ins>The common method is to put all the implementation in the header file<ins>
- (Con't above)If the separation is really required, **Explicitly instantiate the the template and its member definitions**
  - At the _end_ of `MutantStack.hpp`, add lines explicitly instantiating all the relevant templates, eg:
  ```
  template class MutantStack<int, std::deque<int>>
  template class MutantStack<float, std::deque<float>>
  template class MutantStack<std::string, std::deque<std::string>>
  ```
  [source](https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor)
- `template <typename T, typename Container = std::deque<T> >` needs "`> >`" for `std=c++98`
- typedef-name for linking `MutantStack::iterator` to `std::deque<T>::iterator`
- Accessing underlying deque functions

- Ideas I had to solve this project

  1. Make list/vector to be like stack w/ iterator
     - vector with push_back() & pop_back() [source](https://stackoverflow.com/questions/525365/does-stdstack-expose-iterators)
  2. Expose the iterators of deque [source](https://stackoverflow.com/questions/525365/does-stdstack-expose-iterators#:~:text=The%20std%3A%3Astack%20does%20expose%20its%20underlying)
  3. Make my own [source](https://www.linuxtopia.org/online_books/programming_books/thinking_in_c++/Chapter16_015.html)
  4. Random syntax hint [source](http://www.cplusplus.com/forum/general/64311/)
  5. Store all stack elements in an Array/Vector/List lol [source](https://www.quora.com/How-can-I-iterate-stack-elements-in-a-for-loop-in-c++)
     [source2](https://www.py4u.net/discuss/97801#:~:text=As%20you%20mentioned%20you%20need%20printing%20for%20debugging%20purposes%2C%20maybe%20something%20like%20this%20would%20work%20for%20you%3A)
