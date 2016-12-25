#include <string>
#include <iostream>
#include <ctime>

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
	date() {
		time_t t = time(0);
		struct tm * now = localtime(&t);
		month = now -> tm_mon + 1;
		day = now -> tm_mday;
		year = now -> tm_year - 100;
	};
	date(int mm, int dd, int yy): month(mm), day(dd), year(yy) {};
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
	// Вывод возраста
	void showage(date d) {
		unsigned int age = d.year + 100 - year;
		// Из-за неточности ввода подразумевается, что люди не живут дольше 100 лет :)
		if (age >= 100)
			age -= 100;
		if (d.month < month) {
			cout << --age;
			return;
		}
		if (d.day < day) {
			cout << --age;
			return;
		}
		cout << age;
	}
};

int main() {
	date d, today;
	cout << "Enter your birthday date:\n";
	d.getdate();
	cout << "Your age is:\n";
	d.showage(today);
	newLine();
	return 0;
}