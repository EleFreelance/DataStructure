#ifndef _ARRAY_CLASS_H_
#define _ARRAY_CLASS_H_

//ADT抽象数据类型：数据元素之间的逻辑关系+数据元素操作
const int DefaultSize=50;

template<typename T>
class ArrayClass
{
public:
	ArrayClass(int sz=DefaultSize);
	~ArrayClass(){delete[] T };
	ArrayClass(const ArrayClass<T> & A);

	ArrayClass<T> & operator=(const ArrayClass<T> & A);
	bool Insert(T & val,int pos);
	bool Erease(int pos);
	bool Resize(int sz);
private:
	T* Array;
	int Length;
	int MaxSize;
};






#endif