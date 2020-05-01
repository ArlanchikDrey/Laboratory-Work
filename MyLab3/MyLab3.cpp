// MyLab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

class transports {

public:
	transports() {
		speed = 0;
		weight = 0;
	}
	void move() {
		cout << "transports move()";
		cout << "speed =" << speed;
		cout << "weight =" << weight << endl;
	}
	virtual void stop() = 0;

	int getSpeed() {
		return speed;
	}
	int getWeight() {
		return weight;
	}
	void setSpeed(int data) {
		speed = data;
	}
	void setWeight(int data) {
		weight = data;
	}

private:
	int speed;
	int weight;
};

class air : public virtual transports {
public:
	air() {
		wingspan = 0;
		cout << "air constructor" << endl;
	}
	~air() {
		cout << "air destructor" << endl;
	}
	void stop() {
		cout << "air stop()" << endl;
	}
	int getWingspan() {
		return wingspan;
	}
	void setWingspan(int data) {
		wingspan = data;
	}
private:
	int wingspan;
};

class ground : public virtual transports {
public:
	ground() {
		transmission = "4x2";
		cout << "ground constructor" << endl;
	}
	~ground() {
		cout << "ground destructor" << endl;
	}
	void stop() {
		cout << "ground stop()" << endl;
	}
	string getTransmission() {
		return transmission;
	}
	void setTransmission(string data) {
		transmission = data;
	}
private:
	string transmission;
};

class aero_mobil : public air, public ground {
public:
	aero_mobil(){
		cout << "aero_mobil constructor" << endl;
	}
	~aero_mobil() {
		cout << "aero_mobil destructor" << endl;
	}

	void stop() {
		cout << "aero_mobil stop";
	}
private:
	air air;
	ground ground;
};

int main()
{
	air air;
	ground ground;

	transports* eng = NULL;
	eng = &air;
	eng->stop();
	eng = &ground;
	eng->stop();
	cout << endl;

	aero_mobil tp;
	tp.setSpeed(160);
	tp.setWeight(2500);
	tp.setWingspan(8300);
	tp.move();
	tp.stop();

	system("pause");
}
