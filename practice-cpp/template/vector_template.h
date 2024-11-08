#include <string>

template <typename T>
class Vector {
 public:
	Vector(int n = 1);
	
	void push_back(T s);
	
	void erase(int x);

	T operator[](int i);

 private:	
	T* data_;
	int capacity_;
	int length_;

};


