#include <string>
#include <iostream>

using namespace std;

void newLine(unsigned int n = 1) {
	for (unsigned int i = 0; i < n; i++)
		cout << endl;
}

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
		hours = stoi(str.substr(0, 2));
		minutes = stoi(str.substr(3, 4));
		seconds = stoi(str.substr(6, 7));
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

int main() {
	myTime t1, t2;
	cout << "Enter 1-st time:\n";
	t1.gettime();
	newLine();
	cout << "Enter 2-nd time:\n";
	t2.gettime();
	newLine();
	cout << "Sum of this time:\n";
	(t1 + t2).showtime();
	newLine();
	return 0;
}