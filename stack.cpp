#include <iostream>

using namespace std;

/**
@brief ����� ����
*/

class stack
{
private:
	int *s, n, size;

public:
	/**
	@brief �����������
	@param ������ �����
	*/
	stack(int stack_size)
	{
		size = stack_size;
		s = new int[stack_size];
		n = 0;
	};
	/**
	@brief ����������
	*/
	~stack()
	{
		delete s;
		n = 0;
		size = 0;
	};
	/**
	@brief ������� ��� ���������� �������� � ����
	@param �������
	*/
	int put(int a)
	{
		if (n != (size-1))
		{
			s[n] = a;
			n++;
			return 1;
		}
		else
		{
			return 0;
		}
	};
	/**
	@brief ������� ������� �� �����
	*/
	int read()
	{
		if (n >= 0)
		{
			n--;
			return s[n];
		}
		else
		{
			return 0;
		}

	};
};
/**
@brief ����
*/
class round
{
private:

	int *s, size, left, right;

public:
	/**
	@brief �����������
	*/
	round(int a)
	{
		size = a;
		s = new int[size];
		left = 0;
		right = 0;
	};
	/**
	@brief ����������
	*/
	~round()
	{
		delete s;
		left = 0;
		right = 0;
		size = 0;
	};
	/**
	@brief ������� ��� ���������� ��������
	@param �������
	*/
	int add(int a)
	{
		s[right] = a;
		right++;
		if (right == size)
		{
			right = 0;
		}
		if (right == left)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	};
	/**
	@brief ������� ��� ��������� ��������
	*/
	int read()
	{
		if (right == left)
		{
			return 0;
		}
		else
		{
			int answer = s[left] ;
			left++;
			if (left == size);
			{
				left = 0;
			}

			return answer;
		}
	};

};

int main() {
	return 0;
}