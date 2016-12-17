#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class incorrectDate {
public:
	incorrectDate() {
		cout << "Date is incorrect!\n";
	};
	~incorrectDate() {};
};

class date: {
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
		unsigned int m = stoi(str.substr(0, 2));
		unsigned int d = stoi(str.substr(3, 3));
		if (m < 13 && m > 0) {
			month = m;
		} else {
			throw incorrectDate();
		}
		if (d < 32 && d > 0) {
			day = d;
		} else {
			throw incorrectDate();
		}
		year = stoi(str.substr(6, 7));
	}
	// Вывод даты
	void showdate() {
		// Форматируем вывод для добавления нуля перед однозначными числами
		printf("%02d/%02d/%02d", month, day, year);
	}
	// Вывод возраста
	void showage() {
		date d;
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