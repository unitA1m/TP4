#include <iostream>
#include <time.h>

int IsInt() {
	int digit;
	while (true) {
		std::cin >> digit;
		if (std::cin.fail() || std::cin.get() != '\n') {
			std::cout << "Некорректный ввод, пожалуйста, попробуйте снова>>";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}
		return digit;
	}
}

template <typename Mas>
void Inverse(Mas* arr, int Number_of_elements) {
	
	 
	double min = arr[0]; double max = arr[0];
	for (int i = 1; i < Number_of_elements; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
	}
	for (int j = 1; j < Number_of_elements; j++)
	{
		if (max < arr[j])
		{
			max = arr[j];
		}
	}
	std::cout << std::endl;
	std::cout << max - min;
	
}

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int Work = 1;
	int Number_of_elements = rand() % 50 + 50;
	std::cout << "Выберите тип данных массива для работы: " << std::endl;
	std::cout << "1. Integer" << std::endl;
	std::cout << "2. Float" << std::endl;
	std::cout << "3. Double" << std::endl;
	std::cout << ">>";
	int Typename_choice = IsInt();
	switch (Typename_choice) {
	case 1:
	{
		int* Arr_int = new int[Number_of_elements];
		std::cout << "Исходный массив типа integer на " << Number_of_elements << " элементов:" << std::endl;
		for (int i = 0; i < Number_of_elements; i++) {
			Arr_int[i] = rand() % 50 + 50;
			std::cout << Arr_int[i] << "    ";
		}
		try {
			Inverse(Arr_int, Number_of_elements);
		}
		catch (const char* message) {
			std::cout << message << std::endl;
		}
		delete[] Arr_int;
		break;
	}
	
	case 2:
	{
		float* Arr_float = new float[Number_of_elements];
		std::cout << "Исходный массив типа float на " << Number_of_elements << " элементов:" << std::endl;
		for (int i = 0; i < Number_of_elements; i++) {
			Arr_float[i] = static_cast <float>(rand()) / static_cast <float>(RAND_MAX / 50 + 50);
			std::cout << Arr_float[i] << "    ";
		}
		try {
			Inverse(Arr_float, Number_of_elements);
		}
		catch (const char* message) {
			std::cout << message << std::endl;
		}
		delete[] Arr_float;
		break;
	}
	case 3:
	{
		double* Arr_double = new double[Number_of_elements];
		std::cout << "Исходный массив типа double на " << Number_of_elements << " элементов:" << std::endl;
		for (int i = 0; i < Number_of_elements; i++) {
			Arr_double[i] = static_cast <double>(rand()) / static_cast <double>(RAND_MAX / 50 + 50);
			std::cout << Arr_double[i] << "    ";
		}
		try
		{
			Inverse(Arr_double, Number_of_elements);
		}
		catch (const char* message)
		{
			std::cout << message << std::endl;
		}
		delete[] Arr_double;
		break;
	}
	default:
	{
		std::cout << "Выберите существующий пункт меню." << std::endl;
		system("pause");
	}
	}
	return 0;
}
