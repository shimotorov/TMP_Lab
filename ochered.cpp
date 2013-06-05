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
	cout << "Введите число = ";
	cin >> m;
	r = new (Ochered);
	if ( r == NULL)
	{
		cerr << "Ошибка\n";
		exit(1);
	}
	r->n = m;
	r->ptr = NULL;
	// определяем существуют ли в очереди элементы
	if (*pn == NULL)
	{
	// очередь пустая
	// значит созданный элемент становится первым и последним
		*pn = r;
		*pk = r;
	}
	else
	{
	// в очереди есть элементы
	// добавляем элемент в конец
		(*pk)->ptr = r;
		*pk = r; 
	}
}

void del(Ochered **pn, Ochered **pk)
{
	Ochered *p;
	if (pn == NULL)
		cout << "Очередь пуста\n";
	else
	{
		p = *pn;
		cout << "Из очереди выбран элемент = " << p->n << endl;
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
		cout << "1. Добавление элемента в очередь\n";
		cout << "2. Выбор элемента из очереди\n";
		cout << "3. Выход из программы\n";
		cout << "Ваш выбор:";
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

