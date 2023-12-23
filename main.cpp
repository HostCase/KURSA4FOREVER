#include <iostream>
using namespace std;

int main()
{
	int labs;
	do {
		system("cls");
		cout << "\nEnter number of laboratory work(you can enter 0 to exit programm) \n1 - First lab\n2 - Second lab\n3 - Third lab\n4 - Fourth lab\n";
		cin >> labs;
		switch (labs) {
		case 1: {
			system("g++ -o laba_1 laba_1.cpp");
			system("laba_1");
			break;
		}
		case 2: {
			system("g++ -o laba_2 laba_2.cpp");
			system("laba_2");
			break;
		}
		case 3: {
			system("g++ -o laba_3 laba_3.cpp");
			system("laba_3");
			break;
		}
		case 4: {
			system("laba_4");
			break;
		}





		}
	} while (labs);
	return 0;
}
