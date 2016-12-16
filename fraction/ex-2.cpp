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
	fraction operator+ (fraction fr1) {
		if (fr1.denomenator == denomenator) {
			fraction fr(numerator + fr1.numerator, denomenator);
			return fr;
		} else {
			fraction fr(numerator * fr1.denomenator + fr1.numerator * denomenator, denomenator * fr1.denomenator);
			return fr;
		}
	}
};

int main() {
	fraction fr1, fr2(3, 5);
	cout << "1-st fraction: ";
	fr1.output();
	newLine();
	cout << "2-nd fraction: ";
	fr2.output();
	newLine();
	cout << "Sum of this fractions: ";
	(fr1 + fr2).output();
	newLine();
	return 0;
}