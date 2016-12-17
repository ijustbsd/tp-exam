#include <string>
#include <iostream>
#include <ctime>

using namespace std;

void newLine(unsigned int n = 1) {
	for (unsigned int i = 0; i < n; i++)
		cout << endl;
}

class Date {
public:
	virtual void showdate() = 0;
};

class date: public Date {
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
	friend void showage(date&);
};

void showage(date& d1) {
	date d;
	unsigned int age = d.year + 100 - d1.year;
	// Из-за неточности ввода подразумевается, что люди не живут дольше 100 лет :)
	if (age >= 100)
		age -= 100;
	if (d.month < d1.month) {
		cout << --age;
		return;
	}
	if (d.day < d1.day) {
		cout << --age;
		return;
	}
	cout << age;
}

class fullDate: public date {
public:
	int day;
	int month;
	int year;
	fullDate() {
		time_t t = time(0);
		struct tm * now = localtime(&t);
		month = now -> tm_mon + 1;
		day = now -> tm_mday;
		year = now -> tm_year + 1900;
	};
	fullDate(int mm, int dd, int yyyy): month(mm), day(dd), year(yyyy) {};
	// Ввод даты
	void getdate() {
		string str;
		cin >> str;
		month = stoi(str.substr(0, 2));
		day = stoi(str.substr(3, 4));
		year = stoi(str.substr(6, 9));
	}
	// Вывод даты
	void showdate() {
		printf("%02d/%02d/%04d", month, day, year);
	}
};

int main() {
	fullDate d;
	d.showdate();
	newLine();
	return 0;
}