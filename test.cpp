#include <iostream>

using namespace std;

void gen(char& gn) {
	int r, s, nums;
	char num[10] = { '0','1','2','3','4','5','6','7','8','9' };
	char symb[5] = { '+', '-', '_', '$', '~' };
	r = rand() % 3;
	if (r == 0) {
		nums = rand() % 10;
		gn = num[nums];
	} else if (r == 1) {
		do {
			gn = rand() % 26 + 'a';
		} while (gn != 'c' && gn != 'p' && gn != 's' && gn != 'x');
	} else {
		s = rand() % 5;
		gn = symb[s];
	}
}

int main()
{
	int N;
	char one, two;
	int oneCounter = 0, twoCounter = 0, counter = 0;

		cout << "Enter the len str = ";
		cin >> N;

	char* n = new char[N];
	
	char gn = 0;

	for (int i = 0; i < N; i++) {
		gen(gn);
		n[i] = gn;
		//генерация строки(- C,P,S,X)(+ +,-,_,$,~)
	}

	for (int i = 0; i < N; i++) {
		cout << n[i] << " ";
	}
	cout << endl;

	cout << "Enter the char for char - ";
	cin >> one;
	cout << "Enter the char for num - ";
	cin >> two;

	for (int i = 0; i < N; i++) {
		if (n[i] >= 'a' && n[i] <= 'z')
			n[i] = one;
		else if (n[i] >= '1' && n[i] <= '9' || n[i] == '0')
			n[i] = two;
	}


	for (int i = 0; i < N; i++) {
		cout << n[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < N; i++) {
		if (n[i] == one) {
			oneCounter++;
		} else if (n[i] == two) {
			twoCounter++;
		} else {
			counter++;
		}
	}

	cout << oneCounter << " " << twoCounter << " " << counter << endl;
}