#include <string>
#include <iostream>

using namespace std;

class incorrectTime {
public:
	incorrectTime() {
		cout << "Time is incorrect!\n";
	};
};

class myTime {
public:
	int hours;
	int minutes;
	int seconds;
	myTime(): hours(0), minutes(0), seconds(0){};
	myTime(int h, int m, int s): hours(h), minutes(m), seconds(s) {};
	// Ввод времени
	void gettime() {
		string str;
		cin >> str;
		unsigned int h = stoi(str.substr(0, 2));
		unsigned int m = stoi(str.substr(3, 4));
		unsigned int s = stoi(str.substr(6, 7));
		if ((h < 24 && m > 0) && (m < 60 && m > 0) && (s < 60 && s > 0)) {
			hours = h;
			minutes = m;
			seconds = s;
		} else {
			throw incorrectTime();
		}
	}
	// Вывод времени
	void showtime() {
		// Форматируем вывод для добавления нуля перед однозначными числами
		printf("%02d:%02d:%02d", hours, minutes, seconds);
	}
	// Сложение времени
	myTime operator+ (myTime t) {
		unsigned int h = hours + t.hours;
		h > 24 ? h -= 24 : h;
		unsigned int m = minutes + t.minutes;
		if (m > 60) {
			m -= 60;
			h++;
		}
		unsigned int s = seconds + t.seconds;
		if (s > 60) {
			s -= 60;
			m++;
		}
		myTime T(h, m, s);
		return T;
	}
};