#include<iostream>
#include<istream>
#include<ostream>
using namespace std;
#ifndef ARRAY_H
#define ARRAY_H
template<typename T>
class Array
{
private:
	T * data;
	int capacity = 0;
	int isValidIndex(int index)const
	{
		return index >= 0 && index < capacity;
	}
public:
	Array();
	Array(initializer_list<T>list)
	{
		capacity = list.size();
		if (capacity == 0)
		{
			data = 0;
			return;
		}
		data = new T[capacity];
		int j = 0;
		for (auto i : list)
		{
			data[j] = i;
			j++;
		}
	}
	Array&operator =(const Array& ref);
	T& operator[](int index);
	~Array()
	{
		if (data != nullptr)
		{
			delete[]data;
		}
		data = nullptr;
		capacity = 0;
	}
	Array(const Array & ref)
	{
		if (ref.data == nullptr)
		{
			data = nullptr;
			capacity = 0;
			return;
		}
		capacity = ref.capacity;
		data = new T[capacity];
		memcpy(data, ref.data, capacity * sizeof(T));
	}
	const T&  operator[](int index)const
	{
		if (isValidIndex(index))
		{
			return data[index];
		}
		exit(0);
	}

	int getCapacity()const
	{
		return capacity;
	}
	void reSize(int newCap)
	{
		if (newCap < 0)
		{
			this->~Array();
			return;
		}
		if (capacity == 0)
		{
			T * ptr = new T[newCap];
			this->~Array();
			capacity = newCap;
			data = ptr;
			return;
		}
		T * ptr = new T[newCap];
		memcpy(ptr, data, (newCap < capacity ? newCap : capacity) * sizeof(T));
		this->~Array();
		capacity = newCap;
		data = ptr;
	}
};

template<typename T>
istream&operator>>(istream&i,Array<T>&a)
{
	for (int i = 0; i < a.getCapacity(); i = i + 1)
	{
		cin >> a[i];
	}
	return i;
}

template<typename T>
ostream&operator<<(ostream&i, const Array<T>&a)
{
	cout<<"\n";
	for (int i = 0; i < a.getCapacity(); i = i + 1)
	{
		cout<< a[i]<<" ";
	}
	cout << "\n";
	return i;
}

template<typename T>
Array<T>::Array()
{
	data = 0;
	capacity = 0;
}

template<typename G>
Array<G>& Array<G>:: operator =(const Array & ref)
{
	if (this == &ref)
	{
		return *this;
	}
	this->~Array();
	if (ref.data == nullptr)
	{
		data = nullptr;
		capacity = 0;
		return *this;
	}
	capacity = ref.capacity;
	data = new G[capacity];
	memcpy(data, ref.data, capacity * sizeof(G));
}

template<typename T>
T& Array<T>::operator[](int index)
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	exit(0);
}

#endif 


