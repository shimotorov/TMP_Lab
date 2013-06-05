#include <iostream>

using namespace std;

/**
@brief ����� ��� ������ �� �������
*/

class list
{
private:
	struct element
	{
		int a;
		element* next;
	};

	element head;

public:
	/**
	@brief �����������
	@param �������
	*/
	list(int a)
	{

		head.a = a;
		head.next = NULL;
	};
	/**
	@brief ������� ��� ���������� �������� � n-�� �������
	@param ������� 
	@param �������
	*/
	int add_element_n(int a, int n)
	{
		if (n < 1)
		{
			return 0;
		}
		element b;
		b.a = a;
		if (n == 1)
		{
			b.next = &head;
			head = b;
			return 1;
		}
		else
		{
			element *b = new element;
			b->a = a;
			element *temp = &head;

			for (int i = 1; ((temp->next != NULL)&&(i < n)); temp = temp->next){}

			if (temp->next != NULL)
			{
				return 0;
			}

			b->next = (temp->next);
			temp->next = b;

			return 1;
		}
	};
	/**
	@brief ������� ��� ���������� �������� � ����� ������
	@param �������
	*/
	int add_element_to_end(int a)
	{
		element *b = new element;
		b->a = a;
		element *temp = &head;

		for (; (temp->next != NULL); temp = temp->next){}


		b->next = (temp->next);
		temp->next = b;

		return 1;
	};
	/**
	@brief ������� ��� �������� �������� �� n-�� �������
	@param �������
	*/
	int delete_element_n(int n)
	{
		if (n < 1)
		{
			return 0;
		}
		else
		{

			element *temp = &head;
			element *temp2;

			for (; (temp->next != NULL); temp = temp->next){}

			temp2 = temp->next;
			temp->next = temp->next->next;
			delete temp2;
			return 1;
		}
	};

};

int main()
{
	return 0;
}
