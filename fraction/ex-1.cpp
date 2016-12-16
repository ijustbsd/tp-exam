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
};

int main() {
	fraction fr1, fr2;
	cout << "Enter 1-st fraction:\n";
	fr1.input();
	cout << "Enter 2-nd fraction:\n";
	fr2.input();
	cout << "1-st fraction: ";
	fr1.output();
	newLine();
	cout << "2-nd fraction: ";
	fr2.output();
	newLine();
	return 0;
}