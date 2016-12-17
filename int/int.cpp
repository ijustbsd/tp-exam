#include <string>
#include <iostream>

using namespace std;

void newLine(unsigned int n = 1) {
	for (unsigned int i = 0; i < n; i++)
		cout << endl;
}

class generalInt {
public:
	virtual void output() = 0;
};

class outOfRange {
public:
	outOfRange() {
		cout << "Out of range!\n";
	};
};

class Int: public generalInt {
public:
	int value;
	Int(): value(0) {};
	Int(int n): value(n) {};
	// Ввод значения
	void input() {
		cin >> value;
	}
	// Вывод значения
	void output() {
		cout << value;
	}
	// Получить значение
	int get() {
		return value;
	}
	// Сложение двух Int'ов
	friend Int operator+ (Int n1, Int n2);
	// Присваивание двух Int'ов
	Int& operator=(const Int& arg) {
		value = arg.value;
		return *this;
	}
};
// Сложение двух Int'ов
Int operator+ (Int n1, Int n2) {
	return (n1.value + n2.value);
}

class smallInt: public Int {
public:
	const int MAX = 100;
	const int MIN = -100;
	smallInt(): Int() {};
	smallInt(int n) {
		if (n < MAX && n > MIN) {
			Int(n);
		} else {
			throw outOfRange();
		}
	}
	void input() {
		int n;
		cin >> n;
		if (n < MAX && n > MIN) {
			value = n;
		} else {
			throw outOfRange();
		}
	}
};

int main() {
	Int x(2), y(3), z;
	cout << "x = " << x.get() << endl;
	cout << "y = " << y.get() << endl;
	z = x + y;
	cout << "z = x + y = ";
	z.output();
	newLine();
	smallInt s;
	try {
		cout << "Input integer: ";
		s.input();
	} catch (outOfRange e) {
		return 1;
	}
	cout << "Your integer = ";
	s.output();
	newLine();
	return 0;
}