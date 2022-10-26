#include<iostream>
#include<math.h>
using namespace std;

class A
{
public:
	int a,b,c,D;
	double Y;
	void data()
	{
		cout<<"enter a :";
		cin>>a;
		cout<<"enter b:";
		cin>>b;
		cout<<"enter constant:";
		cin>>c;
		D=(b*b)-4*a*c;
		cout<<"The discriminent is="<<D<<endl;
	}
	void root()
	{
		double x1,x2;
		Y=sqrt(D);
		x1=((-b)+Y)/(2*a);
		cout<<"one root of equation is:"<<x1<<endl;
		x2=((-b)-Y)/(2*a);
		cout<<"second root of eq is :"<<x2;
	}
};
int main()
{
	A obj;
	obj.data();
	obj.root();
}
