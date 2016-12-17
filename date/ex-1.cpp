#include <string>
#include <iostream>

using namespace std;

void newLine(unsigned int n = 1) {
	for (unsigned int i = 0; i < n; i++)
		cout << endl;
}

class date {
public:
	int day;
	int month;
	int year;
	// Ввод даты
	void getdate() {
		string str;
		cin >> str;
		month = stoi(str.substr(0, 2));
		day = stoi(str.substr(3, 4));
		year = stoi(str.substr(6, 7));
	}
	// Вывод даты
	void showdate() {
		// Форматируем вывод для добавления нуля перед однозначными числами
		printf("%02d/%02d/%02d", month, day, year);
	}
};

int main() {
	date d;
	cout << "Enter the date:\n";
	d.getdate();
	cout << "Your date is:\n";
	d.showdate();
	newLine();
	return 0;
}