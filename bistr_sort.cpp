#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


void sort(int *p, int low, int high) {
	int i = low;
	int j = high;
	int m;
	m = p[(low+high)/2];
	do {
		while(p[i] < m)
			i++; 
		while(p[j] > m)
			j--;
		if(i <= j) {           
			int temp = p[i];
			p[i] = p[j];
			p[j] = temp;
			i++;
			j--;
		}
	} 
	while(i < j);
	if( low < j ) 
		sort(p,low,j);
	if(i < high) 
		sort(p,i,high);
}
void print(int *p, int n) {
	printf("\n");
	for( int i = 0; i < n; i++ ) {
		printf( "%d " , p[i] );
	}
}

int main() {
	int n,low,high;
	int *p;
	printf("n=");
	scanf("%d", &n);
	low = 0;
	high = n-1;
	srand(time(NULL));
	p = (int*) malloc (n*sizeof(int));
	for( int i = 0; i < n; i++ ) {
		p[i] = rand() % 100;
		printf( "%d " , p[i] );
	}
	sort(p,low,high);
	print(p,n);
	getch();
	return 0;
}