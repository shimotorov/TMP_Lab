#include<iostream> 
#include<string.h> 
#include<stdio.h> 
#include<stdlib.h> 
#include<conio.h> 
#include <Windows.h> 



class bad_input{};
int obtain_point()
{
   int n;
   try
   {
   std::cin>>n;
    if(!std::cin.good())
	   throw bad_input();

	
   } 
  
   catch(bad_input)
   {
	   HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
       SetConsoleTextAttribute(console, FOREGROUND_RED|FOREGROUND_INTENSITY|FOREGROUND_RED); 


	   std::cout << "ERROR" << std::endl;
	   n = 1;  

   }
   return n;
}





int i, j, n, p, xn, xk; 
int flag[11]; 
unsigned c[11][11], l[11]; 
char s[80], path[80][11]; 


int min(int n)  //
{ 
   int i, result; 
   for(i = 0; i < n; i++) 
   if(!(flag[i]))
	   result = i; 

   for(i = 0; i < n; i ++) 
   if((l[result] > l[i]) && (!flag[i]))
	   result = i; 
   return result; 
} 

unsigned minim(unsigned x, unsigned y) 
{ 
   if(x < y)
      return x; 
   return y; 
} 

void main() 
{ 
   std::cout<<"Vvedite kolichestvo tochek: "; 

   for(i = 0; i < n; i++) 
       for(j=0;j<n;j++)
		   c[i][j]=0;

   for(i = 0; i < n; i++) 
       for(j = i+1; j < n; j++) 
       { 
           std::cout<<"Vvedite rasstoyanie ot  x"<<i+1<<" do x"<<j+1<<": "; 
           std::cin>>c[i][j]; 
       } 

    std::cout<<"   "; 
    for(i = 0; i < n; i++)
		std::cout<<"    X"<<i+1; 

    std::cout<<std::endl<<std::endl; 

    for(i = 0; i < n; i++) 
    { 
        printf("X%d",i+1); 
        for(j=0;j<n;j++) 
        { 
            printf("%6d",c[i][j]); 
            c[j][i]=c[i][j]; 
        } 
        printf("\n\n"); 
    } 
    for(i=0;i<n;i++)

        for(j=0;j<n;j++) 
            if(c[i][j]==0)
				c[i][j]=65535; //бесконечность 
    std::cout<<"Vvedite nachalnuy tochku: "; 
    std::cin>>xn; 
    std::cout<<"Vvedite konechnuy tochku: "; 
    std::cin>>xk; 
    xk--; 
    xn--; 
    if(xn==xk) 
    { 
        std::cout<<"Nachalnaya I konechnaya tochki sovpadayt."<<std::endl; 
        system("pause");
        return; 
    } 
    for(i=0;i<n;i++) 
    { 
        flag[i]=0; 
        l[i]=65535; 
    }

    l[xn]=0; 
    flag[xn]=1; 
    p=xn; 
	
    _itoa_s(xn+1,s,10); 
    for(i=1;i<=n;i++) 
    { 
        strcpy_s(path[i],"X"); 
        strcat_s(path[i],s); 
    } 
    do 
    { 
       for(i=0;i<n;i++) 
           if((c[p][i]!=65535)&&(!flag[i])&&(i!=p)) 
           { 
               if(l[i]>l[p]+c[p][i]) 
               { 
                  _itoa_s(i+1,s,10); 
                  strcpy_s(path[i+1],path[p+1]); 
                  strcat_s(path[i+1],"-X"); 
                  strcat_s(path[i+1],s); 
               } 
               l[i]=minim(l[i],l[p]+c[p][i]); 
           } 
               p=min(n); 
               flag[p]=1; 
     } 
     while(p!=xk); 

     if(l[p]!=65535) 
     { 
        std::cout<<"Put: "<< path[p+1]<<std::endl; 
        std::cout<<"Dlina puti: "<<l[p]<<std::endl; 
     }

     else
        std::cout<<"takogo puti ne syshestvuet!"<<std::endl; 
	 system("pause");
} 