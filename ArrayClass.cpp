#include"ArrayClass.h"
#include<assert.h>

template<typename T>
ArrayClass<T>::ArrayClass(int sz)
{
	//��������ĺϷ���
	if (sz<=0)
	{
		sz=DefaultSize;
	}
	//��ʼ����Ա����
	Array=new T[sz];
	MaxSize=sz;
	Length=0;
}

template<typename T>
ArrayClass<T>::ArrayClass(const ArrayClass<T> & A)
{
	assert(A.Length);
	//ǳ��������Ƶĸ�����������ǳ�����Ǹ����׵�ַ��������Ǹ��Ƹ���Ԫ��
	//this->Array=A.Array;
	MaxSize=A.MaxSize;
	this->Length=A.Length;
	this->Array=new T[Length];

	for (int i = 0; i < length; i++)
	{
		this->Array[i]=A.Array[i];
	}
	//�������캯���빹�캯��һ�������践��ֵ
}

template<typename T>
ArrayClass<T> & ArrayClass<T>::operator=(const ArrayClass<T> & A)
{
	//�����������ĺϷ���
	assert(A.Length);
	if (A.Array=Array&&Length=A.Length)
	{
		return *this;
	}
	//���ԭ�пռ�
	delete[] Array;
	//�������
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
    //����pos�ĺϷ���
	if (pos<1||pos>Length+1)
	{
		return false;
	}
	//��Ϊ���һλ����ֱ�Ӳ���
	else if(pos==Length+1)
	{
	//���鶯̬���������ĺϷ���
		if (MaxSize==Length)
		{
			Resize();
		}
		Array[pos-1]=val;
	}
	//��pos�����һλ����Ԫ�������ƶ�һλ
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
	 //��val����posλ��
		Array[pos-1]=val;
	 //�����еĳ�Ա������Ҫ�ı仯��length++
		Length++;
	}
	return true;
}