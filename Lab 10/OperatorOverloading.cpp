
//MULTIPLE INHERITANCE


#include<iostream>
using namespace std;
class a
{
	int p;
public:
	
	
};
class b:public a
{
	int q;
public:
	b()
	{
		cout<<"in default of b class\n";
	}
};
class c:public a
{
	int r;
public:
	c()
	{
		cout<<"in default of c class\n";
	}
};
class d:public b,public c
{
	int s;
public:
	d()
	{
		cout<<"in default of d class\n";
	}
};
int main()
{
	d obj;
}



#include<iostream>
using namespace std;
 class library
{
protected:
	char lname[20];
public:
	library(char *);
	void display();
	library();
};
 library::library()
 {
	 cout<<"in default of base class\n";
	 strcpy(lname,"\0");
 }
 library::library(char * l)
 {
	 cout<<"in para of library class\n";
	 strcpy(lname,l);
 }
void library::display()
{
	cout<<"library name= "<<lname<<endl;
}
 class distributor: virtual public library
{
protected:
	char dname[20];
public:
	void display();
	distributor();
	distributor(char *);
};
 distributor::distributor()
 {
	 cout<<"in default of distributor\n";
	 strcpy(dname,"\0");
 }
 distributor::distributor(char * d)
 {
	 cout<<"in para of distributor\n";
	 strcpy(dname,d);
 }
void distributor::display()
{
	cout<<"distributor name= "<<dname<<endl;
}
class author: virtual public library
{
protected:
	char aname[20];
public:
	void display();
	author();
	author(char *);
};
author::author()
{
	cout<<"in default of author\n";
	strcpy(aname,"\0");
}
author::author(char * a)
{
	cout<<"in para of author\n";
	strcpy(aname,a);
}
void  author::display()
{
	cout<<" authorname= "<<aname<<endl;
}
class book: public author,public distributor
{
protected:
	char title[20];
public:
	void display();
	book();
	book(char*,char *,char *,char *);
};
book::book()
{
	cout<<"in default of  book\n";
	strcpy(title,"\0");
}
book::book(char * l,char * d,char * a,char * t)
	:library(l),author(a),distributor(d)
{
	cout<<"in para of book\n";
	strcpy(title,t);
}
void  book::display()
{
	library::display();
	distributor::display();
	author::display();
	cout<<" title "<<title<<endl;
}
int main()
{
	book b("dyanmandal","sai","kanetkar","cprog");
	b.display();

}





operator overloading

1)an operator is designed to do a particular operation on operands.
2)All operators is a special symbol which are designed to perform a particular operation on predefined datatypes only.
3)by using operator overloading we can add 2 userdefined datatypes also.we are giving extra task to an existing operator.
it gives additional meaning to the existing operator.this features makes UDTs more natural and close to built in datatypes.

4)we cant change basic meaning of an operator.
5)atleast 1 userdefined datatype shld be used in operator overloading concepts.

syntax:
returntype operator symbol(arg-list)
{
}
operator keyword is used to implement operator overloading. 

overloaded operators are implemented as function. therefore function is declared with the keyword operator preceding the operator(symbol).
ex:to overload the addition operator,a function called operator+ can be defined and implemented.


Rules and Regulations
1)cannot change precedence,arity and meaning of the operator.
========================================================================================
#include<iostream>
using namespace std;
class complex
{
	int real,img;

public:
	complex();
	complex(int,int);
	void display();
	complex operator+(complex&);
	complex operator-(complex&);
	complex operator-();
	
	
};
complex::complex()
{
	real=img=0;
}
complex::complex(int real,int img)
{
	this->real=real;
	this->img=img;
}
void complex::display()
{
	if(img>0)
	cout<<"complex number is "<<real<<"+"<<img<<"i"<<endl;
	else
	cout<<"complex number is "<<real<<img<<"i"<<endl;
}
complex complex::operator+(complex & c)
{
	complex temp;
	temp.real=this->real + c.real;
	temp.img=this->img + c.img;
	return temp;
}
complex complex::operator-(complex & c)
{
	complex temp;
	temp.real=this->real - c.real;
	temp.img=this->img -c.img;
	return temp;
}
complex complex::operator-()
{
	complex temp;
	temp.real=-this->real;
	temp.img=-this->img;
	return temp;
}
 
int main()
{
	complex c1(1,2);
	complex c2(3,4);
	complex c3=c1-c2;//c1.operator-(c2)
	c3.display();
	

	complex c4(5,6);
	complex c5=-c4;//c5=c4.operator-()
	c5.display();
	
}
=================================================================================
#include<iostream>
using namespace std;
class complex
{
	int real,img;
public:
	complex(int,int);
	void display();
	
	complex operator-();
	complex operator++();
	 complex operator++(int);
	 complex();
};
complex::complex()
{
	real=img=0;
}
complex::complex(int real,int img)
{
	this->real=real;
	this->img=img;
}
void complex::display()
{
	if(img>0)
	cout<<"complex number is "<<real<<"+"<<img<<"i"<<endl;
	else
	cout<<"complex number is "<<real<<img<<"i"<<endl;
}

complex complex::operator++()//pre
{
	++this->real;//this->real=this->real + 1
	++this->img;
	return (*this);
}
complex complex::operator++(int)
{
	complex temp= (*this);
	++this->real;
	++this->img;
	return temp;
}
int main()
{
	complex c1(1,2);
	complex c2=++c1;//c2=c1.operator++()
	c1.display();
	c2.display();

	/*complex c1(1,2);
	complex c2=c1++;//c2=c1.operator++(0);
	c1.display();
	c2.display();*/

}
=================================================================
#include<iostream>
using namespace std;
#include<string.h>
class string1
{
	int len;
	char* ptr;
	public:
		void display();
		string1(char*);
		string1& operator=(string1&);
		string1(string1&)
		{
			cout<<"copy constructor is called";
		}
		
};
string1& string1::operator=(string1& s)
{
	cout<<"assignment is called\n";
	len=s.len;
	delete[] ptr;
	ptr=new char[len+1];
	strcpy(ptr,s.ptr);
	return (*this);
}
void string1::display()
{
	cout<<"length is "<<len<<endl;
	cout<<"string is "<<ptr<<endl;
}
string1::string1(char * sptr)
{
	len=strlen(sptr);
	ptr=new char[len+1];
	strcpy(ptr,sptr);
}	

int main()
{


	string1 s1("abc");
	string1 s2("xyz");


	s2=s1;//s2.operator=(s1)
	s2.display();
	
	string1 s5=s2;

}





/*	string1 s4(s1);//give call to copy constructor
	s2.display();
	
	string1 s5=s1;//call to copy constrictor
	*/
============================================================================









#include<iostream>
using namespace std;
class complex
{
	int real,img;
public:
	complex();
	complex(int,int);
	void display();
	complex operator+(int);
	friend complex operator+(int,complex&);
};
complex::complex()
{}
complex::complex(int real,int img)
{
	this->real=real;
	this->img=img;
}
void complex::display()
{
	if(img>0)
	cout<<"complex number is "<<real<<"+"<<img<<"i"<<endl;
	else
	cout<<"complex number is "<<real<<img<<"i"<<endl;
}
complex complex::operator+(int num)
{
	complex temp;
	temp.real=real + num;
	temp.img=this->img + num;
	return temp;
}
complex operator+(int num,complex& c)
{
	complex temp;
	temp.real=c.real + num;
	temp.img=c.img + num;
	return temp;
}
int main()
{
/*	complex c1(1,2);
	complex c2=c1 + 5;//c2=c1.operator+(int)
	c2.display();//6+7i*/
	
	complex c1(1,2);
	complex c2=5+c1;//  c2=operator+(5,c1)            
	c2.display();
}
=========================================================================
//overloading of insertion and extraction operator
int a=10;
cout<<a;//cout is an object of ostream class.
whenever we are overloading << lhs obj shld be of type class and rhs variable.
use << on userdefined object.

cout req 2 objects predefined as lhs and userdefined as rhs.when two classes are involved then go for friend function.

#include <iostream>
using namespace std;
 
class Complex
{
private:
    int real, imag;
public:
    Complex(int r = 0, int i =0)
    {  real = r;   imag = i; }
    friend void operator << (ostream &out, const Complex &c);
    friend void operator >> (istream &in,  Complex &c);
};
 
void operator << (ostream &out, const Complex &c)
{
    out << c.real;
    out  <<"+"<< c.imag <<"i"<< endl;
   
}
 
void operator >> (istream &in,  Complex &c)
{
    cout << "Enter Real Part ";
    in >> c.real;
    
    cout << "Enter Imaginary Part ";
    in >> c.imag;
    
}
 
int main()
{
   Complex c1;
   cin >> c1;
   cout << "The complex object is ";
   cout << c1;
   return 0;
}
==============================================================================
#include<iostream>
using namespace std;
class Date1
{
      int day;
      int month;
      int year;
      public:
             Date1(int d,int m,int y)
             {
                   day=d;
                   month=m;
                   year=y;
             }
             
             friend void operator-(Date1 &,int);
             friend void operator+(Date1 &,int);
             void display()
             {
                  cout<<"Date:"<<day<<"-"<<month<<"-"<<year<<endl;
             }
};
void operator-(Date1 &x, int y)
{
     x.day= x.day-y;
    x.month=x.month-3;
x.year=x.year-6;
 cout<<"Date:"<<x.day<<"/"<<x.month<<"/"<<x.year<<endl;
}
void  operator+(Date1 &x,int y)
{
     x.day= x.day+y;
    x.month=x.month+3;
x.year=x.year+6;
 cout<<"Date:"<<x.day<<"/"<<x.month<<"/"<<x.year<<endl;
}
int main()
{
    int dd,mm,yy;
    cout<<"Enter Day:";
    cin>>dd;
    cout<<"Enter Month:";
    cin>>mm;
    cout<<"Enter Year:";
    cin>>yy;
    
    Date1 d1(dd,mm,yy);
    d1-1;//d1=operator+(date1,int)
   	d1+2;
   
    return 0;
}
======================================================
#include<iostream>
using namespace std;
class time
{
      int hr;
      int min;
      int sec;
      public:
             time(int h,int m,int s)
             {
                   hr=h;
                   min=m;
                   sec=s;
             }
             
             friend time operator-(time &,int);
             friend time operator+(time &,int);
             void display()
             {
                  cout<<"time:"<<hr<<":"<<min<<":"<<sec<<endl;
             }
};
time operator-(time &x,int y)
{
     x.hr= x.hr-y;
     x.min= x.min-y;
     x.sec= x.sec-y;
     return x;
}
time operator+(time &x,int y)
{
     x.hr= x.hr+y;
     x.min= x.min+y;
     x.sec= x.sec+y;
     return x;
}
int main()
{
    int hr,min,sec;
    cout<<"Enter hr:";
    cin>>hr;
    cout<<"Enter Min:";
    cin>>min;
    cout<<"Enter sec:";
    cin>>sec;
    
    time t(hr,min,sec);
    t=t-1;
    t.display();
    
    return 0;
}
=============================================================













