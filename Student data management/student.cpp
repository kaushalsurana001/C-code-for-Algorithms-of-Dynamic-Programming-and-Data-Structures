#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<process.h>
#include<iomanip.h>
#include<fstream.h>
class student
{
   struct semester
   {
   char rstatus;
   int m[10],tot;
   char g[10];
   float per;
   }sem[8];
int ipstatus,csem;
float per10,per12;
char fname[35],mname[35],branch[4],lstname[15];
public:
char fstname[15],rollno[7];
struct daob
{
int day,month,year;
}dob;
student()
{
ipstatus=0;csem=0;
}
void regis();
void ipdata();
void showdata();
void showcomp(int);
void showpart(int);
};
void main()
{
setprecision(2);
fstream file;
int ch;
char rn[7],fn[15];
file.open("student",ios::in | ios::app | ios::binary);
student *s;
while(1)
{
cout<<"Enter your choice\n1 Registration of student\n\
2 Input data of student\n3 See data of student\n\
4 Exit\n";
cin>>ch;
     switch(ch)
     {
     case 1:s=new(student);
	    s->regis();
	    file.write((char *) s,sizeof(student));
	    delete s;
	    break;
     case 2:file.seekg(0);
	    if(file.get()==EOF)
	    cout<<"no data present\n";
	    else
	    {
	    cout<<"enter data of student whose data \
	    is to be inputed in small case \n";
	    cout<<"First Name : ";
	    cin>>fn;
	    cout<<"Roll No. : ";
	    cin>>rn;
	    file.seekg(0);
	    int fi=0;
	 while(file)
	 {
	 file.read((char *) s,sizeof(student));
	 if((strcmp(fn,s->fstname)==0)&&(strcmp(rn,s->rollno)==0))
	    {
	    s->ipdata();
	    file.write((char *) s,sizeof(student));
	    fi=1;
	    break;
	    }
	    }

	    if(fi==0)
	    {
	    cout<<"name and rollno. don't match .Remember\
	     input data in small case\n";
	    }
	    }
	    break;
     case 3:file.seekg(0);
	    if(file.get()==EOF)
	    cout<<"no data present\n";
	    else
	    {
	    cout<<"enter data of student whose \
	    data is to be displayed in small case\n";
	    cout<<"First Name : ";
	    cin>>fn;
	    cout<<"Roll No. : ";
	    cin>>rn;
	    file.seekg(0);
	    int fs=0;
	    while(file)
	    {
	    file.read((char *) s,sizeof(student));
	    if((strcmp(fn,s->fstname)==0)&&(strcmp(rn,s->rollno)==0))
	    {
	    s->showdata();
	    fs=1;
	    break;
	    }
	    }
	    if(fs==0)
	    {
	    cout<<"name and rollno. don't match .\
	     remember input in lower case\n";
	    }
	    }
	    break;
     case 4:exit(0);
	    break;
     default:cout<<"WRONG CHOICE\n";
	     break;
     }
}
}
void student::regis()
{
static int count=1;
char r[7],fn[15];
float y;
int ye,m,d,i;
cout<<"Enter the data of : "<<count<<" st student\n";
cout<<"First Name : ";
cin>>fn;
i=strlen(fn);
for(int j=0;j<i;j++)
{
if(isupper(fn[j]))
tolower(fn[j]);
}
strcpy(fstname,fn);
cout<<"Last Name : ";
cin>>lstname;
cout<<"Date of birth\n";
cout<<"Year : ";
cin>>ye;
while(ye<1991||ye>2000)
{
cout<<"year should range between 1990 to 2000.\
Enter correct year again\n";
cin>>ye;
}
dob.year=ye;
cout<<"Month : ";
cin>>m;
while(m>12||m<1)
{
cout<<"wrongly entered.enter again 1-12\n";
cin>>m;
}
dob.month=m;
cout<<"Day : ";
cin>>d;
while((d>31)||((m==4||m==6||m==9||m==11)&&d>30)\
||(m==2&&ye%4!=0&&d>28)||(m==2&&d>29))
{
cout<<"wrong day entered . Enter again \n";
cin>>d;
}
dob.day=d;
fflush(stdin);
cout<<"Father's Name : ";
cin.getline(fname,35);
cout<<"Mother's Name : ";
cin.getline(mname,35);
cout<<"six character Roll No. : ";
while(1)
{
cin>>r;
i=strlen(r);
if(i==6)
break;
else
{
cout<<"invalid rollno. Enter again\n";
cin>>r;
}
}
for(i=0;i<6;i++)
{
if(isupper(r[i]))
tolower(r[i]);
}
strcpy(rollno,r);
cout<<"two or three character Branch code : ";
while(1)
{
cin>>r;
i=strlen(r);
if(i>1&&i<4)
break;
else
{
cout<<"invalid code . enter branch again \n";
cin>>r;
}
}
strcpy(branch,r);
cout<<"12th Percentage : ";
cin>>y;
while(y>=100)
{
cout<<"invalid entry . enter again \n";
cin>>y;
}
per12=y;
cout<<"Percentage of 10th : " ;
cin>>y;
while(y>100)
{
cout<<"wrong entry .Enter again\n";
cin>>y;
}
per10=y;
}
void student::ipdata()
{
int rsem;
int mr,t=0;
char gr;

ipstatus=1;
cout<<"enter the current semester of the student\n";
cin>>rsem;
for(int i=csem;i<rsem;i++)
{
sem[i].rstatus='p';
cout<<"enter the data of : "<<i+1<<" sem\n";
for(int j=0;j<10;j++)
{
cout<<"enter the marks of "<<j+1<<" subject\n";
cin>>mr;
while(mr<0||mr>100)
{
cout<<"marks should be in 0-100.Enter again\n";
cin>>mr;
}
t+=mr;
if(mr<33)
{
gr='c';
sem[i].rstatus='f';
}
else if(mr<60)
gr='b';
else
gr='a';
sem[i].m[j]=mr;
sem[i].g[j]=gr;
}
sem[i].tot=t;
sem[i].per=float(t/10);
}
csem=rsem-1;
}
void student::showdata()
{
int ch;
cout<<"enter your choice 1. particular semester data\
\n2. complete data\n";
cin>>ch;
if(ch==1)
showpart(ipstatus);
else if(ch==2)
showcomp(ipstatus);
else
cout<<"wrong choice \n";
}
void student::showpart(int b)
{
int a;
if(b==1)
{
cout<<"enter the sem no. of which data is required\n";
cin>>a;
if(a-1<=csem)
{
cout<<"Name : "<<fstname<<" "<<lstname<<endl;
cout<<"Rollno. : "<<rollno<<endl;
cout<<"Branch : "<<branch<<endl;
cout<<"the data of "<<a<<" sem is as follows\n";
cout<<"srno.\tmarks\tgrade\n";
for(int i=0;i<10;i++)
{
cout<<i+1<<"\t"<<sem[a-1].m[i]<<"\t"<<sem[a-1].g[i]<<endl;
}
cout<<"Total : "<<sem[a-1].tot<<endl;
cout<<"Result : ";
if(sem[a-1].rstatus=='p')
cout<<"Pass";
else
cout<<"Fail";
cout<<endl;
}
}
else
cout<<"no sem data present\n";
}
void student::showcomp(int b)
{
cout<<"Name : "<<fstname<<" "<<lstname<<endl;
cout<<"Roll no. : "<<rollno<<endl;
cout<<"Father's Name : ";
cout.write(fname,35);
cout<<"\nMother's Name : ";
cout.write(mname,35);
cout<<"\nDOB : "<<dob.day<<"-"<<dob.month<<"-"<<dob.year<<endl;
cout<<"Branch : "<<branch<<endl;
cout<<"10th % : "<<per10<<"12th % : "<<per12<<endl;
if(b==1)
{
cout<<"data of different semester\n";
cout<<"Semester\tTotal\tPercentage\tResult\n";
for(int i=0;i<=csem;i++)
{
cout<<i+1<<"\t"<<sem[i].tot<<"\t"<<sem[i].per<<"\t"<<sem[i].rstatus<<endl;
}
}
else
cout<<"only registration data present here \n";
}


