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
};

int main() {
	myTime t;
	cout << "Enter the time:\n";
	t.gettime();
	cout << "Your time is:\n";
	t.showtime();
	newLine();
	return 0;
}