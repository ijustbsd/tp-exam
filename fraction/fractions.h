#include <string>
#include <iostream>

using namespace std;

class divByZero {
public:
	divByZero() {
		cout << "Divide by zero!\n";
	};
	~divByZero() {};
};

class fraction {
public:
	int numerator;
	int denomenator;
	fraction(): numerator(1), denomenator(1) {};
	fraction(int n, int d): numerator(n), denomenator(d) {};
	// НОД 2-х чисел
	int NOD(int x, int y) {
		if (!y)
			return x;
		return NOD(y, x % y);
	}
	// Ввод дроби
	void input() {
		string str;
		cin >> str;
		unsigned int slashPos = str.find('/');
		numerator = stoi(str.substr(0, slashPos));
		int d = stoi(str.substr(slashPos + 1, str.length() - slashPos - 1));
		if (d)
			denomenator = d;
		else
			throw divByZero();
	}
	// Вывод дроби
	void output() {
		cout << numerator << "/" << denomenator;
	}
	// Сокращение дроби
	fraction reduction () {
		int nod = NOD(numerator, denomenator);
		fraction fr(numerator / nod, denomenator / nod);
		return fr;
	}
	// Сложение дробей
	fraction operator+ (fraction fr1) {
		if (fr1.denomenator == denomenator) {
			fraction fr(numerator + fr1.numerator, denomenator);
			return fr;
		} else {
			fraction fr(numerator * fr1.denomenator + fr1.numerator * denomenator, denomenator * fr1.denomenator);
			return fr;
		}
	}
	// Вычитание дробей
	fraction operator- (fraction fr1) {
		if (fr1.denomenator == denomenator) {
			fraction fr(numerator - fr1.numerator, denomenator);
			return fr;
		} else {
			fraction fr(numerator * fr1.denomenator - fr1.numerator * denomenator, denomenator * fr1.denomenator);
			return fr;
		}
	}
};