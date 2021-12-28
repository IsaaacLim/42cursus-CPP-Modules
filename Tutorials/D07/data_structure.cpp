// ********* TEMPLATE CLASSES & STRUCTURES ********************************** //

#include <iostream>

template <typename T>

class List
{
private:
	// T * _content;
	T _content;
	List<T> *_next;

public:
	List<T>(T const &content){
		// Etc...
	};
	List<T>(List<T> const &list){
		// Etc...
	};
	~List<T>(void){
		// Etc...
	};
};

int main(void)
{
	List<int> a(42);
	List<float> b(42.42f);
	List<List<int>> c(a);

	// Etc...
}
