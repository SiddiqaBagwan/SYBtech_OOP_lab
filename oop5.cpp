/*Name: Siddiqa Bagwan
 *PRN:B24CE1093*/
#include<iostream>
using namespace std;
class Shape{
	protected :
	int x;
	int y;
	public :
	void getdata();
	virtual void display_area()=0;
	
};
void Shape::getdata(){
	cout<<"enter base: "<<endl;
	cin>>x;
	cout<<"enter height:"<<endl;
	cin>>y;
}
class triangle:public Shape{
	void display_area(){
	float area=0.5*x*y;
	cout<<"area of triangle : "<<area<<endl;
}
};
class rect:public Shape{
	void display_area(){
		float area=x*y;
		cout<<"area of rectangle : "<<area<<endl;
	}
};
		
int main(){
	Shape*ptr;
	triangle t;
	ptr=&t;
	ptr->getdata();
	ptr->display_area();
	rect r;
	ptr=&r;
	ptr->getdata();
            ptr->display_area();


};
