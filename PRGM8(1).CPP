#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<conio.h>
int no;
fstream file[8];
char fname[8][8]={"1.txt","2.txt","3.txt","4.txt","5.txt","6.txt","7.txt","8.txt"};

void merge_file(char *file1,char *file2,char *file3)
{
	char names[30][20];
	int k=0;
	fstream f1,f2,f3;
	f1.open(file1,ios::in);
	f2.open(file2,ios::in);
 	f3.open(file3,ios::out);

	while(!f1.eof())
	{
		f1.getline(names[k],20,'\n');
		k++;
		
	}
	
	while(!f2.eof())
	{
		f2.getline(names[k],20,'\n');
		k++;
	}
	k=k-1;

	char temp[20];
	
	for(int x=0;x<k;x++)
	{
	for(int y=x+1;y<k;y++)
	{
	if(strcmp(names[x],names[y])>0)
	{
		strcpy(temp,names[x]);
		strcpy(names[x],names[y]);
		strcpy(names[y],temp);
	}
	}
	}

	for(int i=x;i<k;i++)
	{
	f3<<names[i]<<endl;
	}
	f1.close();
	f2.close();
	f3.close();
}
void kwaymerge()
{
merge_file("1.txt","2.txt","11.txt");
merge_file("3.txt","4.txt","22.txt");
merge_file("5.txt","6.txt","33.txt");
merge_file("7.txt","8.txt","44.txt");
merge_file("11.txt","22.txt","111.txt");
merge_file("33.txt","44.txt","222.txt");
merge_file("111.txt","222.txt","1111.txt");
return;
}

void main()
{
	int i,no;
	char name[20];
	clrscr();
	cout<<"Enter the no of records:";
	cin>>no;
	cout<<"Enter all the names\n";

	for(i=0;i<8;i++)
	{
	file[i].open(fname[i],ios::out);
	}
	for(i=0;i<no;i++)
	{
		cout<<"NAME "<<i+1<<" : ";
		cin>>name;
		file[i%8]<<name<<endl;
	}
	file[i].close();
	kwaymerge();
     fstream result;
	result.open("1111.txt",ios::in);
	cout<<"Sorted records:\n";
	char name1[20];
	for(i=0;i<no;i++)
	{
	result.getline(name1,20,'\n');
	cout<<"\nName:"<<name1<<"\n";
      }
	getch();
}

