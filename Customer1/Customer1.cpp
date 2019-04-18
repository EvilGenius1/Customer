// Customer1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "pch.h"
#include<windows.h> 
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>

using namespace std;
 


struct Сustomer {
	char firstName[15], secondName[15], thirdName[15];
	char sex[15], nationality[15];

	int high, weight, data;

	char homeAdress[15], phoneNumber[15];
	char creditPaasword[15], bankAccount[15];
};


int main() {
	int numberOfCustomers = 1 ;
	int size = 1;

	int chosenOneHigh, chosenOneWeigh, chosenOneData;
	int ashenOne;

	Сustomer *c = new Сustomer[1];

	while (numberOfCustomers) {
		if (size == 1) {
			    cout << "Enter name, second name, third name: ";
				cin >> c[size - 1].firstName >> c[size - 1].secondName >> c[size - 1].thirdName ;

				cout << " Enter sex and national: " << endl;
				cin >> c[size - 1].sex >> c[size - 1].nationality;

				cout << "Enter high, weight, data: " << endl;
				cin >> c[size - 1].high >> c[size - 1].weight >> c[size - 1].data;

				cout << "Enter home adress and phone number: " << endl;
				cin >> c[size - 1].homeAdress >> c[size - 1].phoneNumber;

				cout << "Enter credit password and bank accout: " << endl;
				cin >> c[size - 1].creditPaasword >> c[size - 1].bankAccount;

				cout << " Your customer: " << c[size - 1].firstName << " " << c[size - 1].secondName << " " << c[size - 1].thirdName << endl;
				cout << c[size - 1].sex << " " << c[size - 1].nationality << endl;
				cout << c[size - 1].high << " "<< c[size - 1].weight << " " << c[size - 1].data << endl;
				cout << c[size - 1].homeAdress << " " << c[size - 1].phoneNumber << endl;
				cout << c[size - 1].creditPaasword << " " << c[size - 1].bankAccount << endl;

		}
		else
		{
			Сustomer *copy = new Сustomer[size - 1];//создаем новую структуру для копирования в нее данных

			for (int i = 0; i < size - 1; i++)//копируем данные перед отчисткой памяти объекта р
			{
				strcpy_s(copy[i].firstName, c[i].firstName);
				strcpy_s(copy[i].secondName, c[i].secondName);
				strcpy_s(copy[i].thirdName, c[i].thirdName);
				strcpy_s(copy[i].sex, c[i].sex);
				strcpy_s(copy[i].nationality, c[i].nationality);
				strcpy_s(copy[i].phoneNumber, c[i].phoneNumber);
				strcpy_s(copy[i].homeAdress, c[i].homeAdress);
				strcpy_s(copy[i].creditPaasword, c[i].creditPaasword);
				strcpy_s(copy[i].bankAccount, c[i].bankAccount);

				copy[i].high = c[i].high;
				copy[i].weight = c[i].weight;
				copy[i].data = c[i].data;

			}

			delete[] c; //освобождаем  память

			c = new Сustomer[size]; //выделяем новую память

			for (int i = 0; i < size - 1; i++) // обратное копирование в объект р
			{
				strcpy_s(c[i].firstName, copy[i].firstName);
				strcpy_s(c[i].secondName, copy[i].secondName);
				strcpy_s(c[i].thirdName, copy[i].thirdName);
				strcpy_s(c[i].sex, copy[i].sex);
				strcpy_s(c[i].nationality, copy[i].nationality);
				strcpy_s(c[i].phoneNumber, copy[i].phoneNumber);
				strcpy_s(c[i].homeAdress, copy[i].homeAdress);
				strcpy_s(c[i].creditPaasword, copy[i].creditPaasword);
				strcpy_s(c[i].bankAccount, copy[i].bankAccount);

				c[i].high = copy[i].high;
				c[i].weight = copy[i].weight;
				c[i].data = copy[i].data;
			}

			delete[] copy; //освобождаем память
			
			cout << "Enter name, second name , third name: " << endl;//дописываем новые введенные данные
			cin >> c[size - 1].firstName;
			cin >> c[size - 1].secondName;
			cin >> c[size - 1].thirdName;

			cout << "Sex and nationality: " << endl;
			cin >> c[size - 1].sex >> c[size - 1].nationality;

			cout << "Age weigh and high: " << endl;
			cin >> c[size - 1].data >> c[size - 1].weight >> c[size - 1].high; 

			cout << " Phone number and home adress: " << endl;
			cin >> c[size - 1].phoneNumber;
			cin >> c[size - 1].homeAdress;

			cout << "Credit password and bank accout: " << endl;
			cin >> c[size - 1].creditPaasword;
			cin >> c[size - 1].bankAccount;

			cout << endl;

			for (int i = 0; i < size; i++)//выводим все данные  на экран
			{
				cout << i << "-e structurs of elements:  " << c[i].firstName << " " << c[i].secondName << " " << c[i].thirdName << ";" << endl;
				cout << c[i].sex << " " << c[i].nationality << endl;
				cout << c[i].data << " " << c[i].weight << " " << c[i].high << endl;
				cout << c[i].phoneNumber << " " << c[i].homeAdress << endl;
				cout << c[i].creditPaasword << " " << c[i].bankAccount << endl;
			}

			cout << "Enter information about high, data and weigh.And if we got equal iformation we show it. " << endl;
			cin >> chosenOneHigh >> chosenOneData >> chosenOneWeigh;

			for (int i = 0; i < size; i++) {
				if (chosenOneHigh == c[i].high || chosenOneData == c[i].data || chosenOneWeigh == c[i].weight)
				{
					cout << "WE GOT HIM !!!: " << c[i].firstName << " " << c[i].secondName << " " << c[i].thirdName << endl;
					cout << c[i].sex << " " << c[i].nationality << endl;
					cout << c[i].data << " " << c[i].weight <<" " << c[i].high << endl;
					cout << c[i].homeAdress << " " << c[i].phoneNumber << endl;
					cout << c[i].creditPaasword << " " << c[i].bankAccount << endl;
				}
				else {
					cout << "I lost contact." << endl;
				}
			}
			/*cout << " Select  one of this and we sort our customers: " << endl;
			cout << "1.High " << endl;
			cout << "2.Weight " << endl;
			cout << "3.High " << endl;*/
			
			for (int i = 0; i < size; i++) {
				if (c[i].high < c[size].high) {
					cout << c[i].high << " " << c[size - 1].high << endl;
				}
				else {
					cout << c[size - 1].high << " " << c[i].high << endl;
				}
			}
		}

		size++;

		cout << "\nEnte 1 - to continue or 0 to end this shit: ";
		cin >> numberOfCustomers;
		while (numberOfCustomers != 0 && numberOfCustomers != 1)//если пользователь ввел не 0 и не 1
		{
			cout << "Ошибка ввода!\n";
			cout << "\nВнести еще данные - 1, выход - 0: ";
			cin >> numberOfCustomers;
		}
	}

	delete[] c;//освобождение памяти перед завершением работы программы.0

	return 0;
}