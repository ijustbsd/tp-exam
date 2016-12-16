#include <string>
#include <iostream>

using namespace std;

void newLine(unsigned int n = 1) {
	for (unsigned int i = 0; i < n; i++)
		cout << endl;
}

class fraction {
public:
	int numerator;
	int denomenator;
	fraction(): numerator(1), denomenator(1) {};
	fraction(int n, int d): numerator(n), denomenator(d) {};
	// Ввод дроби
	void input() {
		string str;
		cin >> str;
		unsigned int slashPos = str.find('/');
		numerator = stoi(str.substr(0, slashPos));
		denomenator = stoi(str.substr(slashPos + 1, str.length() - slashPos - 1));
	}
	// Вывод дроби
	void output() {
		cout << numerator << "/" << denomenator;
	}
	// Сложение дробей
	friend fraction operator+ (fraction fr1, fraction fr2);
};

fraction operator+ (fraction fr1, fraction fr2) {
	if (fr1.denomenator == fr2.denomenator) {
		fraction fr(fr1.numerator + fr2.numerator, fr1.denomenator);
		return fr;
	} else {
		fraction fr(fr1.numerator * fr2.denomenator + fr2.numerator * fr1.denomenator, fr1.denomenator * fr2.denomenator);
		return fr;
	}
}

class exFraction: public fraction {
public:
	exFraction(): fraction() {};
	exFraction(int n, int d): fraction(n, d) {};
	// НОД числителя и знаменателя
	int NOD(int x, int y) {
		if (!y)
			return x;
		return NOD(y, x % y);
	}
	// Сокращение дроби
	exFraction reduction () {
		int nod = NOD(numerator, denomenator);
		exFraction fr(numerator / nod, denomenator / nod);
		return fr;
	}
};

int main() {
	fraction fr1, fr2;
	cout << "Enter 1-st fraction:\n";
	fr1.input();
	cout << "Enter 2-nd fraction:\n";
	fr2.input();
	cout << "Sum of this fractions: ";
	(fr1 + fr2).output();
	newLine();
	exFraction fr3(4, 6);
	cout << "3-rd fraction before reduction: ";
	fr3.output();
	newLine();
	cout << "3-rd fraction after reduction: ";
	fr3.reduction().output();
	newLine();
	return 0;
}