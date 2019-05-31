//SACH CODE
#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
class record
{
public:
char name[20];
}rec[20];

int no;
fstream file[8];
char fname[8][8]={"1.txt","2.txt","3.txt","4.txt","5.txt","6.txt","7.txt","8.txt"};


void merge_file(char* file1,char* file2,char* file3)
{
record recd[20], temp;
int i,k,t,y;
k=0;
fstream f1,f2,f3;
f1.open(file1,ios::in);
f2.open(file2,ios::in);
while(!f1.eof())
{
f1.getline(recd[k].name,20,'\n');
k++;
}
while(!f2.eof())
{
f2.getline(recd[k].name,20,'\n');
k++;
}
for(t=0;t<k-2;t++)
for(y=0;y<k-t-2;y++)
if(strcmp(recd[y].name,recd[y+1].name)>0)
{
temp=recd[y];
recd[y]=recd[y+1];
recd[y+1]=temp;
}
f3.open(file3,ios::out);
for(t=1;t<k-1;t++)
f3<<recd[t].name<<"\n";
f1.close();
f2.close();
f3.close();
return;
}


void kwaymerge()
{
int i,k;
k=0;
char filename[7][20]={"11.txt","22.txt","33.txt","44.txt","111.txt",
 "222.txt","1111.txt"};
for(i=0;i<8;i+=2)
{
merge_file(fname[i],fname[i+1],filename[k++]);
}
k=4;
for(i=0;i<4;i+=2)
{
merge_file(filename[i],filename[i+1],filename[k++]);
}
merge_file(filename[4],filename[5],filename[6]);
return;
}


void main()
{
int i;
clrscr();
cout<<"Enter no of records\n";
cin>>no;
cout<<"\nEnter "<<no<<" names\n";
for(i=0;i<8;i++)
file[i].open(fname[i],ios::out);
for(i=0;i<no;i++)
{
cout<<"\nName "<<i+1<<": ";
cin>>rec[i].name;
file[i%8]<<rec[i].name<<"\n";
}
for(i=0;i<8;i++)
file[i].close();
kwaymerge();
fstream result;
result.open("1111.txt",ios::in);
cout<<"sorted records\n";
char name[20];
for(i=0;i<no;i++)
{
result.getline(name,20,'\n');
cout<<"\nName:"<<name<<"\n";
}
getch();
}
