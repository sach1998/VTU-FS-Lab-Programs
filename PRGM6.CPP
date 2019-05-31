//SACH CODE
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
class student
{
public:char name[15];
      
 char usn[15];
       char sem[5];
       
char age[5];
       char branch[5];
};

student s[100],t;
char buf[50];

fstream fp1,fp2,fp3;
int count=0,x,i,j,l;

void pack(student s)
{
strcpy(buf,s.name);
strcat(buf,"|");
strcat(buf,s.usn);
strcat(buf,"|");
strcat(buf,s.sem);
strcat(buf,"|");
strcat(buf,s.age);
strcat(buf,"|");
strcat(buf,s.branch);
x=strlen(buf);
for(i=0;i<45-x;i++)
strcat(buf,"!");
fp1.open("std.txt",ios::app);
fp2.open("ind.txt",ios::app);
fp3.open("second.txt",ios::app);
fp1<<count<<"|"<<buf<<endl;
fp2<<s.usn<<"|"<<count<<"|"<<endl;
fp3<<s.name<<"|"<<s.usn<<"|"<<endl;
fp1.close();
fp2.close();
fp3.close();
}

void add()
{
cout<<"Enter all the details: "<<endl;
cout<<"Name: ";
cin>>t.name;
cout<<"USN: ";
cin>>t.usn;
cout<<"Sem: ";
cin>>t.sem;
cout<<"Age: ";
cin>>t.age;
cout<<"Branch: ";
cin>>t.branch;
cout<<"\n";
pack(t);
}

void search()
{
char key_usn[15],tempusn[15],temprrn[10],rrn,buf2[100],key_name[30],sec_usn[20],sec_name[20];
cout<<"Enter the name of the student to be searched: ";
cin>>key_name;
fp3.open("second.txt",ios::in);
for(l=0;l<count;l++)
{
fp3.getline(buf2,100);
sscanf(buf2,"%[^|]|%[^|]|",sec_name,sec_usn);
if(strcmp(key_name,sec_name)==0)
{
strcpy(key_usn,sec_usn);
cout<<"Name is found!";
break;
}
}
fp3.close();
if(l==count)
{
cout<<"Name doesn't exist!";
i=count;
return;
}
fp2.open("ind.txt",ios::in);
for(i=0;i<count;i++)
{
fp2.getline(buf,100);
sscanf(buf,"%[^|]|%[^|]|",tempusn,temprrn);
if(strcmp(key_usn,tempusn)==0)
{
cout<<"\nRecord is found!"<<endl;
cout<<"RRN: "<<temprrn<<endl;
fp1.open("std.txt",ios::in);
int rrnno=atoi(temprrn);
fp1.seekg((rrnno-1)*49,ios::beg);
fp1.getline(buf,100);
sscanf(buf,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^!]!",rrn,t.name,t.usn,t.sem,t.age,t.branch);
cout<<"Name: "<<t.name<<endl;
cout<<"USN: "<<t.usn<<endl;
cout<<"Sem: "<<t.sem<<endl;
cout<<"Age: "<<t.age<<endl;
cout<<"Branch: "<<t.branch<<endl;
fp1.close();
fp2.close();
break;
}
}
}

void del()
{
char temp[10];
if(i==count)
return;
fp1.open("std.txt",ios::in);
for(j=0;j<count;j++)
{
fp1.getline(buf,100);
sscanf(buf,"%[^|]|%[^|]|%[^|]|%[^|]%[^|]|%[^!]!",temp,s[j].name,s[j].usn,s[j].sem,s[j].age,s[j].branch);
}
fp1.close();
remove("std.txt");
remove("ind.txt");
remove("second.txt");
fp1.open("std.txt",ios::out);
fp2.open("ind.txt",ios::out);
fp3.open("second.txt",ios::out);
fp1.close();
fp2.close();
fp3.close();
int oldcount=count;
count=0;
for(j=0;j<oldcount;j++)
{
if(j!=i)
{
count++;
pack(s[j]);
}
}
cout<<"Record deleted!";
}

void main()
{
int ch;

clrscr();

fp1.open("std.txt",ios::out);

fp2.open("ind.txt",ios::out);

fp3.open("second.txt",ios::out);

fp1.close();
fp2.close();
fp3.close();

while(1)
{
cout<<"\n Choose an option:\n 1.Add\t 2.Search\t 3.Delete\t 4.Exit\n"<<endl;
cout<<"Enter your choice: ";
cin>>ch;
switch(ch)
{
case 1:count++;
      add();
      break;

case 2:search();
       break;

case 3:search();
       del();
       break;

case 4:exit(0);
}
}
}