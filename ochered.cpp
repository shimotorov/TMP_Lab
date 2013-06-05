#include <iostream>
#include <stdlib.h>

using namespace std;

struct Ochered
{
	int n;
	Ochered *ptr;
};

void add(Ochered **pn, Ochered **pk)
{
	Ochered *r;
	int m;
	cout << "������� ����� = ";
	cin >> m;
	r = new (Ochered);
	if ( r == NULL)
	{
		cerr << "������\n";
		exit(1);
	}
	r->n = m;
	r->ptr = NULL;
	// ���������� ���������� �� � ������� ��������
	if (*pn == NULL)
	{
	// ������� ������
	// ������ ��������� ������� ���������� ������ � ���������
		*pn = r;
		*pk = r;
	}
	else
	{
	// � ������� ���� ��������
	// ��������� ������� � �����
		(*pk)->ptr = r;
		*pk = r; 
	}
}

void del(Ochered **pn, Ochered **pk)
{
	Ochered *p;
	if (pn == NULL)
		cout << "������� �����\n";
	else
	{
		p = *pn;
		cout << "�� ������� ������ ������� = " << p->n << endl;
		*pn = p->ptr; 
		delete p; 
	}
}
void main()
{
	setlocale(LC_ALL,"Russian");
	Ochered *pbeg = 0, *pend = 0;
	char c;
	while(1)
	{
		cout << "1. ���������� �������� � �������\n";
		cout << "2. ����� �������� �� �������\n";
		cout << "3. ����� �� ���������\n";
		cout << "��� �����:";
		cin >> c;
		switch(c)
		{
			case '1':
				add(&pbeg, &pend);
			break;
			case '2':
				del(&pbeg, &pend);
			break;
			case '3':
				return;
		}
	}
}

