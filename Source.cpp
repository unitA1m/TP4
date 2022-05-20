#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
T differ(T size) {
	
	T* arr = new T[size];
	for (T i = 0; i < size; i++) {
		arr[i] = 50 + rand() % 50;
		cout << arr[i] << endl;
	}
	cout << "Âñåãî ýëåìåíòîâ â ìàññèâå:" << size << endl;
	if (arr) {
		cout << "Ìàññèâ ñîçäàí!" << endl;
	}
	else cout << "Error" << endl;
	T diff = 0;
	T min, max;
	min = arr[0];
	max = arr[1];
	for (T i = 0; i < size-1; i++) {
		if (min > arr[i + 1]) {
			min = arr[i + 1];
		}
		if (max < arr[i + 1]) {
			max = arr[i + 1];
		}
	}
	diff = max - min;
	delete [] arr;
	return diff;
}

int main() {
	setlocale(0, "rus");
	int size;
	srand(time(NULL));

	size = 50+ rand()%10;
	cout<<"Ðàçíèöà ìåæäó ìàêñèìàëüíûì è ìèíèìàëüíûì ýëåìåíòîì: " << differ(size) << endl;
}
