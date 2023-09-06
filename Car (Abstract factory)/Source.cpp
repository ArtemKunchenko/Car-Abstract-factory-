#include<iostream>
using namespace std;

class Wheel
{
public:
	virtual void wheel() = 0;
};
class WheelType1 :public Wheel
{
	void wheel() override { cout << "Wheel type 1" << endl; }
};
class WheelType2 :public Wheel
{
	void wheel() override { cout << "Wheel type 2" << endl; }
};
class WheelType3 :public Wheel
{
	void wheel() override { cout << "Wheel type 3" << endl; }
};

int main()
{
	system("pause");
	return 0;
}