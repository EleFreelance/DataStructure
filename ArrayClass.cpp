#include"ArrayClass.h"
#include<assert.h>

template<typename T>
ArrayClass<T>::ArrayClass(int sz)
{
	//检验参数的合法性
	if (sz<=0)
	{
		sz=DefaultSize;
	}
	//初始化成员函数
	Array=new T[sz];
	MaxSize=sz;
	Length=0;
}

template<typename T>
ArrayClass<T>::ArrayClass(const ArrayClass<T> & A)
{
	assert(A.Length);
	//浅复制与深复制的根本区别，在于浅复制是复制首地址，而深复制是复制各个元素
	//this->Array=A.Array;
	MaxSize=A.MaxSize;
	this->Length=A.Length;
	this->Array=new T[Length];

	for (int i = 0; i < length; i++)
	{
		this->Array[i]=A.Array[i];
	}
	//拷贝构造函数与构造函数一样，无需返回值
}

template<typename T>
ArrayClass<T> & ArrayClass<T>::operator=(const ArrayClass<T> & A)
{
	//检测输入参数的合法性
	assert(A.Length);
	if (A.Array=Array&&Length=A.Length)
	{
		return *this;
	}
	//清空原有空间
	delete[] Array;
	//进行深复制
	MaxSize=A.MaxSize;
	Length=A.Length;
	Array=new T[Length];
	for (int i = 0; i < length; i++)
	{
		Array[i]=A.Array[i];
	}
	return *this;
}


template<typename T>
bool ArrayClass<T>::Insert(T & val,int pos)
{
    //检验pos的合法性
	if (pos<1||pos>Length+1)
	{
		return false;
	}
	//若为最后一位，则直接插入
	else if(pos==Length+1)
	{
	//检验动态数组对象本身的合法性
		if (MaxSize==Length)
		{
			Resize();
		}
		Array[pos-1]=val;
	}
	//将pos到最后一位数据元素往后移动一位
	else
	{
		if (MaxSize==Length)
		{
			Resize();
		}
		for (int i = pos-1; i < length; i++)
		{
			Array[i+1]=Array[i];
		}
	 //将val插入pos位置
		Array[pos-1]=val;
	 //对象中的成员变量需要的变化，length++
		Length++;
	}
	return true;
}