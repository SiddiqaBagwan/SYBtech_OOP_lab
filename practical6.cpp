Design a program with the following functionalities:
1. A function to read two numbers(Double type)
2. A function to calculate division of these two numbers
3. A try block to detect and throw an exception when divide by zero condition occurs
4. Appropriate catch block to handle the exception thrown*/
#include <iostream>
using namespace std;
class exe {
	double x,y;
	public:
	void accept();
	void division();
};
void exe :: accept(){
	cout<<"Enter two numbers:"<<endl;
	cin>>x>>y;
}
void exe :: division(){
	try {
		if (y==0)
		throw y;
		cout<<"division is:"<<x/y;
	}
	catch (double y){
	cout<<"_________________________________\n";
	cout<<"Catched Divide By Zero exception\n";
	cout<<"_________________________________";
}
}
int main(){
	exe e;
	e.accept();
	e.division();
	
	return 0;
}
