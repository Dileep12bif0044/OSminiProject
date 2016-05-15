#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<stdio.h>
using namespace std;

void  *saul(char ch[])
{
	int length;
	int temp;
	length=strlen(ch);
	temp=atoi(ch);
	int a[50]; int k=0;
			while(temp!=0)
				{
				 a[k++]=temp%10;
				temp=temp/10;
				}
			int max,min,i;
			float sum=0;
			max=min=a[0];
			for(i=0;i<k;i++)
				{
				 if(a[i]>max)
				max=a[i];
				if(a[i]<min)
				min=a[i];
				sum+=a[i];
			
			}
			
			cout<<"\n Max:"<<max<<"\n Min:"<<min<<"\n Average:"<<sum/k;
			}
			
	int main()
	{
		pthread_t t1;
		char s[20];
		cout<<"Enter a string of numbers";
		cin>>s;
		saul(s);
return 0;
}

