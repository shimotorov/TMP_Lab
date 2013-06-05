#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void merge (int* mass,int left,int middle,int right)
{
	int* m = new int[right-left];
	int i = left;
	int j = middle+1;
	int k = 0;
	for (int z = left; z <= right; z++) {
		if(i > middle) {
			m[k] = mass[j];
			j++;
		}
		else 
			if(j > right) {
				m[k] = mass[i];
				i++;
			}
			else
				if(mass[i] < mass[j]) {
					m[k] = mass[i];
					i++;
				}
				else {
					m[k] = mass[j];
					j++;
				}
				k++;
	}
	for(int counter = 0; counter <= right-left; counter++)
		mass[counter+left] = m[counter];
}
void sort(int* mass,int left,int right) {
	if(left >= right)
		return;
	int middle = (right+left)/2;
	sort(mass,left,middle);
	sort(mass,middle+1,right);
	merge(mass,left,middle,right);
}
void print(int *mass, int n) {
	for( int i = 0; i < n; i++ ) {
		printf( "%d " , mass[i] );
	}
}

void main() {
	int n,*p;
	printf("n=");
	scanf("%d", &n);
	srand(time(NULL));
	p = (int*) malloc (n*sizeof(int));
	for(int i=0; i<n; i++) {
		p[i] = rand() % 100;
		printf("%d " , p[i]);
	}
	printf("\n");
	sort(p,0,n-1);
	print(p,n);
	getch();
}
