#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<iomanip.h>
#include<fstream.h>

int check(int *);
void show_part_emp();
void register_emp();
void pay_slip();
void display();
void modify();
void delete_rec();
int chepass(char []);
void chanpass();

class employee
{
char fname[20],lname[20];
long int basepay;
int desig;
struct date
{
int day,month,year;
}doj;
public:
int eid;
void input();
void showdata();
void calculate();
}s,r;

fstream pass;


void main()
{
int ch;
char pword[20],p[10]="employee";
pass.open("passwd",ios::in|ios::out);
if(pass.get()==EOF)
pass<<p;
pass.close();
while(1)
{
cout<<"Enter your choice\n\n1.Register new employee\n2.Generate\
 Payslips\n3.See organisation data\n4.See patricular data\n5.Modify\n\
6.Delete record\n7.Change Password\n0.Exit\n";
cin>>ch;
if(ch>0&&ch<8)
{
cout<<"Enter password\n";
cin>>pword;
if(chepass(pword))
{}
else
{
cout<<"wrong password\n";
break;
}
}

switch(ch)
{
     case 1:register_emp();
	    break;
     case 2:pay_slip();
	    break;
     case 3:display();
	    break;
     case 4:show_part_emp();
	    break;
     case 5:modify();
	    break;
     case 6:delete_rec();
	    break;
     case 7:chanpass();
	    break;
     case 0:exit(0);
	    break;
     default:cout<<"WRONG CHOICE\n";
	     	     break;
     }
}
}

void chanpass()
{
char psword[20],pword[20];
cout<<"enter new password\n";
cin>>psword;
cout<<"enter again\n";
cin>>pword;
pass.open("passwd",ios::out|ios::trunc);
if(strcmp(pword,psword)==0)
{
pass.seekp(0,ios::beg);
pass<<psword;
cout<<"password changed\n";
}
else
cout<<"don't match\n";
pass.close();
}
void employee::input()
{
int ye,d,m;
cout<<"enter the following details of the employee\n";
cout<<"First Name : ";
cin>>fname;
cout<<"Last Name : ";
cin>>lname;
cout<<"Date of joining\n";
cout<<"Year : ";
cin>>ye;
while((ye<1950)||(ye>2017))
{
cout<<"year should range between 1950to now.\
Enter correct year again\n";
cin>>ye;
}
doj.year=ye;
cout<<"Month : ";
cin>>m;
while(m>12||m<1)
{
cout<<"wrongly entered.enter again 1-12\n";
cin>>m;
}
doj.month=m;
cout<<"Day : ";
cin>>d;
while((d>31)||((m==4||m==6||m==9||m==11)&&d>30)
||(m==2&&ye%4!=0&&d>28)||(m==2&&d>29))
{
cout<<"wrong day entered . Enter again \n";
cin>>d;
}
d=d+200;
doj.day=d;
cout<<"Basic Salary: ";
cin>>basepay;
cout<<"Enter your designation\n";
cout<<"1. Senior manager\n2. Junior Manager\n3. Supervisor\n4.Line \
Employee\n";
cin>>desig;
while(desig>4||desig<1)
{
cout<<"Wrong Entry.... Enter again\n";
cin>>desig;
}
}

void employee::showdata()
{
cout<<eid<<"\t"<<fname<<" "<<lname<<"\t"<<basepay\
<<"\t"<<doj.day-200<<"-"<<doj.month\
<<"-"<<doj.year<<"\t";
switch(desig)
{
case 1:cout<<"S M";
       break;
case 2:cout<<"J M";
       break;
case 3:cout<<"S V";
       break;
default :cout<<"L E";
}
cout<<"\n";
}

void employee::calculate()
{
int l,o,b,flag=0;
long int lp,op,bp,total;
cout<<"enter the no. of leaves\n";
cin>>l;
lp=(basepay/30)*l;
cout<<"No. of overtime hours\n";
cin>>o;
op=basepay/250*o;
cout<<"Percentage Bonus given : ";
cin>>b;
while(b>20||b<0)
{
cout<<"Bonus should be between 0 to 20%... enter again";
cin>>b;
}
bp=basepay*b/100;
total=basepay+bp+op-lp;
if(total>99999)
{
flag=1;
total=total-(total/20);
}
cout<<"Name : ";
cout<<fname<<" "<<lname<<endl;
cout<<"Employee Id.: ";
cout<<eid<<endl;
cout<<"Basic salary : ";
cout<<basepay;
cout<<"\nLeave Deduction : ";
cout<<lp;
cout<<"\nOvertime Pay : ";
cout<<op;
cout<<"\nBonus : ";
cout<<bp;
cout<<"\nTDS : ";
if(flag==1)
cout<<"5%";
else
cout<<"No Deduction \n";
cout<<"Net Pay : ";
cout<<total;
cout<<"\n\n\n\npress any key ...";
}
int chepass(char psword[20])
{
char p[20];
pass.open("passwd",ios::in);
pass.seekg(0,ios::beg);
pass>>p;
pass.close();
if(strcmp(p,psword)==0)
return 1;
else
return 0;
}

void delete_rec()
{
ifstream fil;
int id;
cout<<"Enter the employee Id. whose data is to be removed\n";
cin>>id;
ofstream o;
o.open("new.dat",ios::out|ios::binary);
fil.open("emp.dat",ios::in|ios::binary);
if(!fil)
cout<<"File not found\n";
else
{
fil.seekg(0,ios::beg);
while(fil.read((char *) &s,sizeof(s)))
{
if(id!=s.eid)
o.write((char *) &s,sizeof(s));
}
o.close();
fil.close();
remove("emp.dat");
rename("new.dat","emp.dat");
}
}

void display()
{
ifstream fil;
fil.open("emp.dat",ios::in|ios::binary);
int i=0,n;
long int size;
fil.seekg(0,ios::beg);
size=fil.tellg();
fil.seekg(0,ios::end);
size=fil.tellg()-size;
n=size/sizeof(s);
cout<<"number of employees are: "<<n<<endl;
fil.seekg(0,ios::beg);
while(fil.read((char *) &s,sizeof(s)))
{
if(i<21)
{
cout<<"E.Id\tName\tBasic pay\tDate of join\tDesignation\n";
s.showdata();
i++;
}
else
{
cout<<"Press any key for next page\n";
i=0;
}
}
}

void show_part_emp()
{
ifstream fil;
int id,flag=0;
cout<<"Enter the employee Id. whose data is to be shown\n";
cin>>id;
fil.open("emp.dat",ios::in|ios::binary);
fil.seekg(0,ios::beg);
while(fil.read((char *) &s,sizeof(s)))
{
if(id==s.eid)
{
cout<<"E.Id\tName\tBasic pay\tDate of join\tDesignation\n";
s.showdata();
flag=1;
break;
}
}
if(flag==0)
cout<<"data not found\n";
}

void register_emp()
{
int id,i;
ofstream fil;
fil.open("emp.dat",ios::app|ios::binary);
while(1)
{
cout<<"Enter the employee id\n";
cin>>id;
i=check(&id);
if(i)
break;
else
cout<<"this id already exist\n";
}
r.eid=id;
r.input();
fil.write((char *) &r,sizeof(r));
cout<<"enter any key...\n";
fil.close();
}

int check(int *id)
{
ifstream fil;
int i,flag=0;
while(*id/10000!=0||*id/1000<0)
{
cout<<"Id should be of 4 digit...   Enter again\n";
cin>>i;
*id=i;
}
fil.open("emp.dat",ios::in|ios::binary);
while(fil.read((char *) &s,sizeof(s)))
{
if(*id==s.eid)
{
flag=1;
break;
}
}
fil.close();
if(flag==0)
return 1;
else
return 0;
}

void modify()
{
fstream fil;
int id,i,a;
fil.open("emp.dat",ios::in|ios::out|ios::binary);
cout<<"Enter the id of the employee whose data is to be modified\n";
cin>>id;
i=check(&id);
if(i==1)
cout<<"no data found\n";
else
{
a=id;
while(i==0)
{
cout<<"enter new id\n";
cin>>id;
i=check(&id);
if(i==0)
cout<<"This id is already allocated\n";
}
fil.seekg(0,ios::beg);
while(fil.read((char *)&s,sizeof(s)))
{
if(s.eid==a)
{
s.eid=id;
s.input();
break;
}
fil.seekg(0,ios::cur);
fil.seekp(fil.tellg()-sizeof(s));
fil.write((char *) &s,sizeof(s));
fil.close();
}
}
}

void pay_slip()
{
ifstream fil;
int id,flag=0;
cout<<"Enter the employee Id. whose pay slip is required\n";
cin>>id;
fil.open("emp.dat",ios::in|ios::binary);
fil.seekg(0,ios::beg);
while(fil.read((char *) &s,sizeof(s)))
{
if(id==s.eid)
{
s.calculate();
flag=1;
break;
}
}
if(flag==0)
cout<<"data not found\n";
fil.close();
}



