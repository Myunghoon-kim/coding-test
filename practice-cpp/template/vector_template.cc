#include "vector_template.h"

template <typename T>
Vector<T>::Vector(int n): data_(new T[n]), capacity_(n), length_(0) {
	
};

template <typename T>
void Vector<T>::push_back(T s) {
	// 용량이 작다면?
	if(capacity_ <= length_) {
		T* tmp = new T[capacity_ * 2];
		// 복사 진행
		for(int i = 0 ; i < length_; i++) {
			tmp[i] = data_[i];
		}

		delete[] data_;

		data_ = tmp;
		
		capacity_ = capacity_ * 2;
	}
	data_[length_] = s;

	length_++;
}

template <typename T>
void Vector<T>::erase(int x) {
	if(length_ < x)
		return;

	for (int i = x + 1; i < length_; i++) {
      data_[i - 1] = data_[i];
    }

    length_--;
}

template <typename T>
T Vector<T>::operator[](int i) {
	return data_[i];
}
