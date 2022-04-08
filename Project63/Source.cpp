#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void findANDreplace(char* str, char* resault);
void convert(float y, float z, char* str);

int main()
{
	setlocale(LC_ALL, "RUS");
	float y, z;
	cout << "y: ";
	cin >> y;
	cout << "z: ";
	cin >> z;
	char res[500];
	convert(y, z, res);
	cout << res << endl;
	char* str1 = new char[2500];
	char* str2 = new char[2500];
	strcpy(str1, "@@@@@@@@@@@@");
	findANDreplace(str1, str2);
	cout << str1 << endl;
	cout << str2 << endl;
	delete[]str1;
	delete[]str2;
}
void convert(float y, float z, char* str)
{
	double x = y+3*z;  //X= Y+3*Z
	sprintf(str, "%03.4f = %03.4f + 3 * %03.4f", x, y, z);
}

void findANDreplace(char* str_l, char* resault_l) {
	memset(resault_l, 0, sizeof(char) * 2500);

	char start[2500] = {};

	for (int i = 0; i < strlen(str_l); i++) {
		start[i] = str_l[i];
	}

	int count = 0;
	char res[2500] = {};
	for (int i = 0; i < strlen(start); i++) {
		char sas[4] = {};
		if (start[i] == '@') {
			sprintf(sas, "%d", i);
			strcat(res, sas);
			count++;
		}
		else {
			strncat(res, i + start, 1);
		}
	}
	for (int i = 0; i < strlen(res); i++)
	{
		resault_l[i] = res[i];
	}
	cout << "Замен: " << count << endl;
}