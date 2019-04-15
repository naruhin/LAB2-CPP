

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.H>

using namespace std;

struct building {
	string adress;
	string typeOfBuilding;
	unsigned short numberOfFloors;
	unsigned short numberOfFlats;
	unsigned short lifetime;
	unsigned short termToOverhaul;
};

void menu(building *Array,int N);

//Метод  ввода с проверкой вводимого 
int readInt() {
	unsigned short N;
	while (!(cin >> N) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка!Введите число - " << endl;
	}
	return N;
}

//Метод ввода с проверкой ,что вводимое число позитивное 
int readPositiveInt() {
	unsigned short N;
	bool check = false;
	unsigned short temp;
	while (check == false) {
		temp = readInt();
		if (temp & (1U << (sizeof(temp) * 8 - 1))) {
			cout << "Ошибка! Введите положительное число - ";
		}
		else {
			N = temp;
			check = true;
		}
	}
	return N;
}

//Метод вывода отдельных структур массива
void print(building *Array, int N ,int i) {
	cout << setw(22 + Array[i].adress.length()) << setfill('-') << '-' << ends << endl;
	cout << "|Адресс             | " << setw(Array[i].adress.length()) << setfill(' ') << Array[i].adress << '|' << ends << endl;

	cout << "|Тип здания         | " << setw(Array[i].adress.length()) << setfill(' ') << Array[i].typeOfBuilding << '|' << ends << endl;

	cout << "|Количество этажей  | " << setw(Array[i].adress.length()) << setfill(' ') << Array[i].numberOfFloors << '|' << ends << endl;

	cout << "|Количество квартир | " << setw(Array[i].adress.length()) << setfill(' ') << Array[i].numberOfFlats << '|' << ends << endl;

	cout << "|Срок эксплуатации  | " << setw(Array[i].adress.length()) << setfill(' ') << Array[i].lifetime << '|' << ends << endl;

	cout << "|Срок до ремонта    | " << setw(Array[i].adress.length()) << setfill(' ') << Array[i].termToOverhaul << '|' << ends << endl;
	cout << setw(22 + Array[i].adress.length()) << setfill('-') << '-' << ends << endl;
	cout << endl;
}

//Заполнение дин.массива
void fillArray(building *Array, int N) {
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		cout << endl << "Адресс - ";
		getline(cin, Array[i].adress);
		cout << "Тип здания - ";
		getline(cin, Array[i].typeOfBuilding);
		cout << "Количество этажей - ";
		Array[i].numberOfFloors = readPositiveInt();
		cout << "Количество квартир - ";
		Array[i].numberOfFlats = readPositiveInt();
		cout << "Срок эксплуатации - ";
		Array[i].lifetime = readPositiveInt();
		cout << "Срок до ремонта - ";
		Array[i].termToOverhaul = readPositiveInt();
		cin.ignore();
		cout << endl;
	}	
	menu(Array, N);
}

//Сортировка массива по указанному параметру
void sortByPresetField(building *Array, int N) {
	int choice;
	cout << "Введите параметр по которому требуется отсортировать массив." <<
		"\n 1. Кол-во этажей." <<
		"\n 2. Кол-во квартир." <<
		"\n 3. Срок эксплуатации." <<
		"\n 4. Срок до ремонта." << endl;
	choice = readPositiveInt();
	switch (choice) {
	case 1:
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				if (Array[j].numberOfFloors > Array[j + 1].numberOfFloors) {
					building tmp = Array[j];
					Array[j] = Array[j + 1];
					Array[j + 1] = tmp;
				}
			}
		}
		cout << "------------------------" << endl;
		cout << "| Массив отсортирован! |" << endl;
		cout << "------------------------" << endl;
		break;
	case 2:
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				if (Array[j].numberOfFlats > Array[j + 1].numberOfFlats) {
					building tmp = Array[j];
					Array[j] = Array[j + 1];
					Array[j + 1] = tmp;
				}
			}
		}
		cout << "------------------------" << endl;
		cout << "| Массив отсортирован! |" << endl;
		cout << "------------------------" << endl;
		break;
	case 3:
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				if (Array[j].lifetime > Array[j + 1].lifetime) {
					building tmp = Array[j];
					Array[j] = Array[j + 1];
					Array[j + 1] = tmp;
				}
			}
		}
		cout << "------------------------" << endl;
		cout << "| Массив отсортирован! |" << endl;
		cout << "------------------------" << endl;
		break;
	case 4:
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				if (Array[j].termToOverhaul > Array[j + 1].termToOverhaul) {
					building tmp = Array[j];
					Array[j] = Array[j + 1];
					Array[j + 1] = tmp;
				}
			}
		}
		cout << "------------------------" << endl;
		cout << "| Массив отсортирован! |" << endl;
		cout << "------------------------" << endl;
		break;
	default:
		break;
	}
	
	
	menu(Array, N);
}

//Вывод содержимого массива
void displayArray(building *Array, int N) {
	cout << "\t\t\tВсе здания:" << endl;
	for (int i = 0; i < N; i++) {
		print(Array, N, i);
	}	
	menu(Array, N);
}

//Поиск и вывод по значению из указаного поля
void findByValueOfPresetField(building *Array, int N) {
	int choice;
	cout << "Введите параметр по которому требуется найти структуру (структуры)." <<
		"\n 1. Адресс." <<
		"\n 2. Тип здания." <<
		"\n 3. Кол-во квартир." <<
		"\n 4. Срок эксплуатации." <<
		"\n 5. Срок до ремонта." << 
		"\n 6. Кол-во этажей." << endl;
	choice = readPositiveInt();
	cin.ignore();

	string temp1;
	int temp2;
	bool check = false;

	switch (choice) {
	case 1:
		cout << "Введите адресс - ";
		getline(cin,temp1);
		
		for (int i = 0; i < N; i++)
		{
			if (temp1 == Array[i].adress) {
				print(Array, N, i);
				check = true;
			}
			else
				cout << "Зданий с таким параметром нет!" << endl;
		}
		break;
	case 2:
		cout << "Введите тип здания - ";
		getline(cin, temp1);
		for (int i = 0; i < N; i++)
		{
			if (temp1 == Array[i].typeOfBuilding) {
				print(Array, N, i);
				check = true;
			}
			else
				cout << "Зданий с таким параметром нет!" << endl;
		}
		break;
	case 3:
		cout << "Введите кол-во квартир - ";
		temp2 = readPositiveInt();
		for (int i = 0; i < N; i++)
		{
			if (temp2 == Array[i].numberOfFlats) {
				print(Array, N, i);
				check = true;
			}
			else
				cout << "Зданий с таким параметром нет!" << endl;
		}
		break;
	case 4:
		cout << "Введите срок эксплуатации - ";
		temp2 = readPositiveInt();
		for (int i = 0; i < N; i++)
		{
			if (temp2 == Array[i].lifetime) {
				print(Array, N, i);
				check = true;
			}
			else
				cout << "Зданий с таким параметром нет!" << endl;
		}
		break;
	case 5:
		cout << "Введите срок до ремонта - ";
		temp2 = readPositiveInt();
		for (int i = 0; i < N; i++)
		{
			if (temp2 == Array[i].termToOverhaul) {
				print(Array, N, i);
				check = true;
			}
			else
				cout << "Зданий с таким параметром нет!" << endl;
		}
		break;
	case 6:
		cout << "Введите кол-во этажей - ";
		temp2 = readPositiveInt();
		for (int i = 0; i < N; i++)
		{
			if (temp2 == Array[i].numberOfFloors) {
				print(Array, N, i);
				check = true;
			}
			else
				cout << "Зданий с таким параметром нет!" << endl;
		}
		break;
	default:
		break;
	}

	menu(Array, N);
}

//Добавление в массив ещё одной структуры(структур)
void pushBack(building *&Array, int &N,int n) {
	for (int i = 0; i < n; i++)
	{
		building *newArray = new building[N + 1];
		cin.ignore();
		for (int i = 0; i < N; i++)
		{
			newArray[i] = Array[i];
			newArray[i].adress = Array[i].adress;
			newArray[i].lifetime = Array[i].lifetime;
			newArray[i].typeOfBuilding = Array[i].typeOfBuilding;
			newArray[i].numberOfFloors = Array[i].numberOfFloors;
			newArray[i].numberOfFlats = Array[i].numberOfFlats;
			newArray[i].termToOverhaul = Array[i].termToOverhaul;
		}
		
		cout << endl << "Адресс - ";
		getline(cin,newArray[N].adress);
		cout << "Тип здания - ";
		getline(cin,newArray[N].typeOfBuilding);
		cout << "Количество этажей - ";
		newArray[N].numberOfFloors = readPositiveInt();
		cout << "Количество квартир - ";
		newArray[N].numberOfFlats = readPositiveInt();
		cout << "Срок эксплуатации - ";
		newArray[N].lifetime = readPositiveInt();
		cout << "Срок до ремонта - ";
		newArray[N].termToOverhaul = readPositiveInt();
		cin.ignore();
		cout << endl;
		N++;

		delete[] Array;
		Array = newArray;
	}
	menu(Array, N);
}

//Меню
void menu(building *Array, int N) {
	
	cout << "\n Что сделать? \n\t 1. Заполнить массив." <<
			"\n\t 2. Вывести массив на экран. " <<
			"\n\t 3. Добавить в массив ещё здания " <<
			"\n\t 4. Отсортировать по выбраному параметру." <<
			"\n\t 5. Поиск и вывод по заданому значению поля." <<
			"\n\t 6. Закончить работу. \n - ";
	int check;
	check = readPositiveInt();

	switch (check) {
	case 1:

		fillArray(Array, N);
		break;
	case 2:
		displayArray(Array, N);
		break;
	case 3:
		cout << "Введите кол-во зданий, которые нужно добавить - ";
		int n;
		n = readPositiveInt();
		pushBack(Array, N, n);
		break;
	case 4:
		sortByPresetField(Array, N);
		break;
	case 5:
		findByValueOfPresetField(Array, N);
		break;
	case 6:
		delete[] Array;
		break;
	default:
		break;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	unsigned short N;

	cout << "Введите кол-во зданий - ";
	N = readPositiveInt();
	cin.ignore();

	building *BUILDINGS = new building[N];
	menu(BUILDINGS, N);

	return 0;
}
