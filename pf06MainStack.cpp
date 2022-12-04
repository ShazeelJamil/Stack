#include<iostream>
#include"Stack.h"
#include<string.h>
using namespace std;

bool checkStringNN(const string& src);
bool checkStringST(const string& src);
bool checkStringNNN(const string& src);
template<typename T>
void reverseStack(Stack<T>& src);
//template<typename T>
//void transferElements(Stack<T>& src, Stack<T> dest);
int main()
{
	//cout << checkStringNN("ab");
	//cout << checkStringST("aabbba");
	//cout << checkStringNNN("aaabbbccc");// producing an unexpected error
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	Stack<int> s1(s);
	//transferElements(s, s1);
	int noe = s1.getNumberOfElements();
	//reverseStack(s);
	//cout << s.getNumberOfElements() << " : " << s.getCapacity() << "\n";
	for (int i = 0; i < noe; i++)
		cout<< s1.pop()<<" ";
	
	return 0;
}
template<typename T>
void transferElements(Stack<T>& src, Stack<T> dest)
{
	dest = src;
}
template<typename T>
void reverseStack(Stack<T>& src)
{
	Stack<T> temp;
	int noe=src.getNumberOfElements();
	for (int i = 0; i < noe; i++)
		temp.push(src.pop());
	src = temp;
}
bool checkStringNNN(const string& src)
{
	int size = src.length();
	const char ch1 = src[0];
	int i = 1, count = 1;
	if (size % 2 == 0)
	{
		while (src[i] == ch1)
		{
			i++;
			count++;
		}
		if (count == size / 3)
		{
			const char ch2 = src[i++];
			count++;
			while (src[i] == ch2)
			{
				i++;
				count++;
			}
			if (count == 2 * size / 3)
			{
				const char ch3 = src[i++];
				count++;
				while (src[i] == ch3)
				{
					i++;
					count++;
				}
				return (count == size ? true : false);

			}
			else 
				return false;
		}
		else
			return false;
	}
	else
	{
		while (src[i] == ch1)
		{
			i++;
			count++;
		}
		const char ch2 = src[i++];
		count++;
		while (src[i] == ch2);
		{
			i++;
			count++;
		}
		const char ch3 = src[i++];
		count++;
		while (src[i] == ch3)
		{
			i++;
			count++;
		}
		return (count == size ? true : false);
	}
}
bool checkStringST(const string& src)
{
	const char ch1 = src[0];
	int i = 1, count = 1;
	while (src[i] == ch1)
	{
		i++;
		count++;
	}
	const char ch2 = src[i++];
	count++;
	while (src[i] == ch2)
	{
		i++;
		count++;
	}
	return (count == src.length() ? true : false);
}
bool checkStringNN(const string& src)
{
	int size = src.length();
	if (size % 2 == 0)
	{
		int count =1, i = 1;
		const char ch = src[0];
		while (src[i] == ch)
		{
			i++;
			count++;
		}
		if (count == size / 2)
		{
			const char ch2 = src[i++];
			count++;
			while (src[i] == ch2)
			{
				i++;
				count++;
			}
			return(count == src.length() ? true : false);
		}
		else
			return false;
	}
	else
		return false;
}