#include<iostream>
using namespace std;

#pragma region PART
class Part
{
public:
	virtual void part() = 0;
};
class WheelType1 :public Part
{
public:
	void part() override { cout << "Wheel type 1" << endl; }
};
class WheelType2 :public Part
{
public:
	void part() override { cout << "Wheel type 2" << endl; }
};
class WheelType3 :public Part
{
public:
	void part() override { cout << "Wheel type 3" << endl; }
};
class HoodType1 : public Part
{
public:
	void part() override { cout << "Hood type 1" << endl; }
};
class HoodType2 : public Part
{
public:
	void part() override { cout << "Hood type 2" << endl; }
};
class HoodType3 : public Part
{
public:
	void part() override { cout << "Hood type 3" << endl; }
};

class DoorType1 : public Part
{
public:
	void part() override { cout << "Door type 1" << endl; }
};
class DoorType2 : public Part
{
public:
	void part() override { cout << "Door type 2" << endl; }
};
class DoorType3 : public Part
{
public:
	void part() override { cout << "Door type 3" << endl; }
};
#pragma endregion

#pragma region STAMPING EQUIPMENT
class StampingEquipment
{
public:
	virtual Part* stampPart() = 0;
};
class Model1Wheels : public StampingEquipment
{
public:
	Part* stampPart() override { return new WheelType1(); }
};
class Model2Wheels : public StampingEquipment
{
public:
	Part* stampPart() override { return new WheelType2(); }
};
class Model3Wheels : public StampingEquipment
{
public:
	Part* stampPart() override { return new WheelType3(); }
};
class Model1Hood : public StampingEquipment
{
public:
	Part* stampPart() override { return new HoodType1(); }
};
class Model2Hood : public StampingEquipment
{
public:
	Part* stampPart() override { return new HoodType2(); }
};
class Model3Hood : public StampingEquipment
{
public:
	Part* stampPart() override { return new HoodType3(); }
};
class Model1Door : public StampingEquipment
{
public:
	Part* stampPart() override { return new DoorType1(); }
};
class Model2Door : public StampingEquipment
{
public:
	Part* stampPart() override { return new DoorType2(); }
};
class Model3Door : public StampingEquipment
{
public:
	Part* stampPart() override { return new DoorType3(); }
};
#pragma endregion

#pragma region CAR
class Car
{
public:
	virtual void createCar() = 0;
	StampingEquipment* getWheels() { return _wheels; }
	StampingEquipment* getHood() { return _hood; }
	StampingEquipment* getDoor() { return _door; }
protected:
	StampingEquipment* _wheels;
	StampingEquipment* _hood;
	StampingEquipment* _door;
};
class CarType1 : public Car
{
public:
	void createCar() override
	{
		_wheels = new Model1Wheels();
		_hood = new Model1Hood();
		_door = new Model1Door();
	}
};
class CarType2 : public Car
{
public:
	void createCar() override
	{
		_wheels = new Model2Wheels();
		_hood = new Model2Hood();
		_door = new Model2Door();
	}
};
class CarType3 : public Car
{
public:
	void createCar() override
	{
		_wheels = new Model3Wheels();
		_hood = new Model3Hood();
		_door = new Model3Door();
	}
};
#pragma endregion

#pragma region CLIENT
class Client
{
public:
	void printCar(Car& car)
	{
		cout << "The client chose :\n";
		Part* wheels = car.getWheels()->stampPart();
		wheels->part();
		Part* hood = car.getHood()->stampPart();
		hood->part();
		Part* door = car.getDoor()->stampPart();
		door->part();
	}
};
#pragma endregion


int main()
{
	Car* car= new CarType1();
	car->createCar();
	Client* client = new Client();
	client->printCar(*car);
	
	system("pause");
	return 0;
}