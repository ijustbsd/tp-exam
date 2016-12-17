#include <string>
#include <iostream>

using namespace std;

void newLine(unsigned int n = 1) {
	for (unsigned int i = 0; i < n; i++)
		cout << endl;
}

class MyTime {
public:
	virtual void showtime() = 0;
};

class incorrectTime {
public:
	incorrectTime() {
		cout << "Time is incorrect!\n";
	};
};

class myTime: public MyTime {
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
	friend myTime operator+ (myTime t1, myTime t2);
};

myTime operator+ (myTime t1, myTime t2) {
	unsigned int h = t1.hours + t2.hours;
	h > 24 ? h -= 24 : h;
	unsigned int m = t1.minutes + t2.minutes;
	if (m > 60) {
		m -= 60;
		h++;
	}
	unsigned int s = t1.seconds + t2.seconds;
	if (s > 60) {
		s -= 60;
		m++;
	}
	myTime T(h, m, s);
	return T;
}

class nowTime: public myTime {
public:
	nowTime(): myTime() {};
	nowTime(int h, int m, int s): myTime(h, m, s) {};
	// Вывод текущего времени
	void showCurrentTime() {
		time_t t = time(0);
		struct tm * now = localtime(&t);
		hours = now -> tm_hour;
		minutes = now -> tm_min;
		seconds = now -> tm_sec;
		showtime();
	}
};

int main() {
	myTime t;
	try {
		cout << "Enter the time:\n";
		t.gettime();
	} catch (incorrectTime e) {
		return 1;
	}
	cout << "Your time is:\n";
	t.showtime();
	newLine();
	return 0;
}