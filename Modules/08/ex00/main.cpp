#include "easyfind.hpp"

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

template <typename T>
void ft_print(T array)
{
	typename T::iterator i;
	typename T::iterator begin;
	typename T::iterator end;

	begin = array.begin();
	end = array.end();
	for (i = begin; i != end; ++i)
		std::cout << *i << " ";
	std::cout << "\n";
	std::cout << std::endl;
}

int main(void)
{
	{ //Vector
		std::vector<int> vector_arr;
		std::vector<int>::iterator it;

		std::cout << "====================== VECTOR ======================\n";
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
	}
	{ //List
		std::list<int> list_arr;
		std::list<int>::iterator it;

		std::cout << "======================  LIST  ======================\n";
		list_arr.push_back(10);
		list_arr.push_back(20);
		list_arr.push_front(30);
		list_arr.insert(list_arr.end(), 5, 43);
		list_arr.insert(list_arr.begin(), 5, -10);
		ft_print(list_arr);
		ft_tryFind(list_arr, 20);
		ft_tryFind(list_arr, -1);
		ft_tryFind(list_arr, -10);
	}
	{ //Deque
		std::deque<int> deque_arr;

		std::cout << "====================== DEQUE  ======================\n";
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
	}
}
