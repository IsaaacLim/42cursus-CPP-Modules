//Source: https://youtu.be/6OoSgY6NVVk

#include <iostream>
#include <algorithm> //functions for STL containers

using namespace std;

/*
** Arrays containers are like flexible arrays
**	Program will not break if we try to excess unallocated memory
*/
#include <array>
void ft_array(void)
{
	int arr[10];				//Stack
	int *new_arr = new int[10]; //Heap
	delete[] new_arr;

	std::array<int, 10> cont_arr; //pseudo array
	cont_arr[9] = 42;

	cout << cont_arr.size() << "\n"; //some methods available for containters
	cout << cont_arr.data() << "\n";

	// -------- Iterator ---------------------------------------------------- //
	for (int i = 0; i < 10; i++) //standard way
		cont_arr[i] = 0;
	for (int i = 0; i < cont_arr.size(); i++) //using provided method
		cont_arr[i] = 1;
	for (std::array<int, 10>::iterator i = cont_arr.begin(); i != cont_arr.end(); ++i) //using iterator
		*i = 2;																		   // iterator is like a pointer
	for (auto i = cont_arr.begin(); i != cont_arr.end(); ++i)						   //auto keyword to replace the words
		*i = 3;
	for (auto &i : cont_arr) //ranged for loop (does the same thing)
		i = 4;
	std::fill(cont_arr.begin(), cont_arr.end(), 5); //algorithm functions (does the same thing)
}

/*
** VECTORS: Arrays that are dynamic in size
**	dynamic meaning once there isn't enough memory for the data to be stored contiguously,
**	it'll automatically copied the contents to a larger space for it to expand
**	(hence, Pointers to a vector isn't always valid if its size keeps increasing)
*/
#include <vector>
void ft_vector(void)
{
	std::vector<int> arr;
	arr.push_back(1); // adds data to the vector container
	arr.push_back(2);
	arr.push_back(3);

	cout << arr.size() << "\n"; //some methods available for containters

	// -------- Iterator ---------------------------------------------------- //
	for (int i = 0; i < 10; i++) //standard way (alright going past allocated memory)
		arr[i] = 0;

	for (int i = 0; i < arr.size(); i++) //using provided method
		cout << arr[i] << " ";
	cout << endl;

	std::fill(arr.begin(), arr.end(), 5); //algorithm functions (may pass function)

	for (std::vector<int>::iterator i = arr.begin(); i != arr.end(); ++i) //using iterator
		cout << *i << " ";												  // iterator is like a pointer
	cout << endl;
}

/*
** LIST: doubly linked list
** When we .push_back() 2 values, the nodes aren't placed contiguously
**	They are joined with 2 pointers, next and prev
**	If a middle node is removed, the connection will automaticall be corrected
** Access this list like a double linked list. Can't do arr[5]!
*/
#include <list>
void ft_list(void)
{
	std::list<int> arr;
	arr.push_back(10);
}

/*
** DEQUE: Double Ended Queue
** Combination of Vectors and List (ie: Linked list of arrays)
**	Once contiguously memory runs out, it might create a new block of memory
**	or just insert the data at the end of the existing block
** There is indexing with deques (arr[5])
*/
#include <deque>
void ft_deque(void)
{
	std::deque<int> arr;
	arr.push_back(10);
}

/*
** Set of unique data (can only ONE of any type of item)
** Data stored are immediately sorted
** Usefull when collecting alot of data without wanting duplicates
*/
#include <set>
void ft_set(void)
{
	cout << "\n====== SET ======\n";
	std::set<int> arr;
	// arr.push_back(1);
	arr.insert(1);
	arr.insert(2);
	arr.insert(2); //doesn't register
	arr.insert(2); //doesn't register
	arr.insert(3);
	arr.insert(0); //Inserted in the front

	// cout << arr[0] << " " << arr[1] << " " << arr[2] << endl; //Wrong syntax
	std::set<int>::iterator setStart = arr.begin();
	int first = *setStart;
	auto forthPtr = std::next(setStart, 3); //(three after the first)
	int forth = *forthPtr;
	cout << first << " " << forth << endl;

	for (auto it = arr.begin(); it != arr.end(); ++it) //display all
	{
		int current = *it;
		cout << current << " ";
	}
	cout << endl;
}

/*
** Similar with SET, but unordered
*/
#include <unordered_set>
void ft_unordered_set()
{
	cout << "\n====== UNORDERED SET ======\n";
	std::unordered_set<int> arr;
	arr.insert(5);
	arr.insert(4);
	arr.insert(4); //doesn't register
	arr.insert(4); //doesn't register
	arr.insert(10);
	arr.insert(42);

	for (auto it = arr.begin(); it != arr.end(); ++it) //display all
	{
		int current = *it;
		cout << current << " ";
	}
	cout << endl;
}

/*
** MAP stores Key-Value pair
** Used to create correlation between one type and another
** 	Map is sorted by KEY not Value
*/
#include <map>
#include <unordered_map>
void ft_map(void)
{
	cout << "\n====== UNORDERED MAP ======\n";
	std::unordered_map<std::string, int> container;
	container["one"] = 1;
	container["two"] = 2;
	container["three"] = 3;
	container["four"] = 4;
	container["five"] = 5;

	for (auto &i : container)
		cout << i.first << " = " << i.second << "\n"; //first(key), second(value)

	cout << "\n====== ORDERED MAP ======\n";
	std::map<std::string, int> container2; //Order by KEY not Value
	container2["one"] = 1;
	container2["two"] = 2;
	container2["three"] = 3;
	container2["four"] = 4;
	container2["five"] = 5;

	for (auto &i : container2)
		cout << i.first << " = " << i.second << "\n"; //first(key), second(value)
}

int main()
{
	ft_array();
	ft_vector();
	ft_list();
	ft_set();
	ft_unordered_set();
	ft_map();
}

// **** NOTES for c++98 ***************************************************** //
/*
Unusable Containers
- Array
- Unordered set
- Unordered map

Unusable Keyword
- auto
*/
