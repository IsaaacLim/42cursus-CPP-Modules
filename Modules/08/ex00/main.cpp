#include "easyfind.hpp"

#define YELLOW "\033[0;33m"
#define PURPLE "\033[0;35m"
#define RESET "\033[0m"

void print_title(std::string str)
{
	std::cout << PURPLE "====================== " << str << "======================\n" RESET;
}

template <typename T>
void ft_tryFind(T array, int find)
{
	int index;

	try
	{
		index = easyfind(array, find);
		std::cout << "'" << find << "'\tfound at index: " << index << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "'" << find << "'\t";
		std::cerr << e.what() << '\n';
	}
}

// ---------------------- Print Container Array --------------------------------
template <typename T>
void ft_print(T array)
{
	typename T::iterator i;
	typename T::iterator begin;
	typename T::iterator end;

	begin = array.begin();
	end = array.end();
	std::cout << YELLOW;
	for (i = begin; i != end; ++i)
		std::cout << *i << " ";
	std::cout << RESET "\n\n";
}

template <typename T, typename U>
void ft_print(std::map<T, U> array)
{
	typename std::map<T, U>::iterator i;

	std::cout << YELLOW;
	for (i = array.begin(); i != array.end(); ++i)
		std::cout << i->second << " ";
	std::cout << RESET "\n\n";
}

template <typename T, typename U>
void ft_print(std::multimap<T, U> array)
{
	typename std::map<T, U>::iterator i;

	std::cout << YELLOW;
	for (i = array.begin(); i != array.end(); ++i)
		std::cout << i->second << " ";
	std::cout << RESET "\n\n";
}

// -----------------------------------------------------------------------------
int main(void)
{
	{ //Vector
		std::vector<int> vector_arr;
		std::vector<int>::iterator it;

		print_title("VECTOR");
		for (int i = 0; i < 10; i++)
			vector_arr.push_back(i);
		vector_arr.resize(15, 42); //fill 10th-14th with 42
		vector_arr.resize(20);	   //fill 15th-19th with 0
		it = vector_arr.begin();
		vector_arr.insert(it + 2, 2, 200); //fill 2nd&3rd with 200
		ft_print(vector_arr);
		ft_tryFind(vector_arr, 5);
		ft_tryFind(vector_arr, 6);
		ft_tryFind(vector_arr, 200);
		ft_tryFind(vector_arr, 31);
		std::cout << std::endl;
	}
	{ //List
		std::list<int> list_arr;
		std::list<int>::iterator it;

		print_title("LIST");
		list_arr.push_back(10);
		list_arr.push_back(20);
		list_arr.push_front(30);
		list_arr.insert(list_arr.end(), 5, 43);
		list_arr.insert(list_arr.begin(), 5, -10);
		ft_print(list_arr);
		ft_tryFind(list_arr, 20);
		ft_tryFind(list_arr, -1);
		ft_tryFind(list_arr, -10);
		std::cout << std::endl;
	}
	{ //Deque
		std::deque<int> deque_arr;

		print_title("DEQUE");
		deque_arr.resize(9);
		deque_arr.push_back(42);
		deque_arr.resize(20);
		deque_arr.push_front(21);
		deque_arr.pop_front();
		deque_arr.push_back(10);
		deque_arr.pop_back();
		ft_print(deque_arr);
		ft_tryFind(deque_arr, 21);
		ft_tryFind(deque_arr, 10);
		ft_tryFind(deque_arr, 0);
		ft_tryFind(deque_arr, 42);
		std::cout << std::endl;
	}
	{ // Set
		std::set<int> set_arr;

		print_title("SET");
		for (int i = 0; i < 10; i++)
			set_arr.insert(i);
		set_arr.insert(6);
		ft_print(set_arr);
		ft_tryFind(set_arr, 10);
		ft_tryFind(set_arr, 9);
		std::cout << std::endl;
	}
	{ // Multiset
		std::multiset<int> multiset_arr;

		print_title("MULTISET");
		for (int i = 0; i < 10; i++)
			multiset_arr.insert(i);
		multiset_arr.insert(6);
		ft_print(multiset_arr);
		ft_tryFind(multiset_arr, 10);
		ft_tryFind(multiset_arr, 9);
		std::cout << std::endl;
	}
	{ // Map
		std::map<char, int> map_arr;

		print_title("MAP");
		for (int i = 0; i < 10; i++)
			map_arr[97 + i] = i * 10;
		map_arr.insert(std::pair<char, int>('b', 90) );
		ft_print(map_arr);
		ft_tryFind(map_arr, 10);
		ft_tryFind(map_arr, 90);
		ft_tryFind(map_arr, 99);
		std::cout << std::endl;
	}
	{ // Multimap
		std::multimap<char, int> multimap_arr;

		print_title("MULTIMAP");
		for (int i = 0; i < 10; i++)
			multimap_arr.insert(std::pair<char, int>(97 + i, i * 10) );
		multimap_arr.insert(std::pair<char, int>('b', 90) );
		ft_print(multimap_arr);
		ft_tryFind(multimap_arr, 10);
		ft_tryFind(multimap_arr, 90);
		ft_tryFind(multimap_arr, 99);
		std::cout << std::endl;
	}
}
