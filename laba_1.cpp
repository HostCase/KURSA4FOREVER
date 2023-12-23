#include <iostream>


using namespace std;

int main()
{

    setlocale(0, "");
    int choosetype, inversionbit;
    cout << "� ������ ������ ��������� ��� ����� 3\n";
    cout << "�������� ����� �������\n1 ������� ������� ����� ����(��� ����) \n2 ������� ������� ����� ���(int)\n3 ������� ������� ����� ���(float)\n4 ������� ������� ����� ������(��� ���)\n";
    cin >> choosetype;

    if (choosetype == 1) {
        cout << "������ � ������ � ��������� ����������:" << "\n";
        cout << "int" << " " << sizeof(int) << "\n";
        cout << "short int" << " " << sizeof(short int) << "\n";
        cout << "long int" << " " << sizeof(long int) << "\n";
        cout << "float" << " " << sizeof(float) << "\n";
        cout << "double" << " " << sizeof(double) << "\n";
        cout << "long double" << " " << sizeof(long double) << "\n";
        cout << "char" << " " << sizeof(char) << "\n";
        cout << "bool" << " " << sizeof(bool) << "\n";
    }
    else if (choosetype == 2) {
        int inputnumber;
        cout << "������� �����" << "\n";
        cin >> inputnumber;
        cout << "������� ��� ������������� �����?\n";
        cin >> inversionbit;
        int order = sizeof(int) * 8 - 1;
        unsigned int mask = 1 << order;
        for (int i = 0; i <= order; i++) {
            if (inversionbit == 0 or inversionbit % 2 == 0) {
                cout << ((inputnumber & mask) ? 1 : 0);
            }
            else {
                int inputnumber2 = ~inputnumber;
                cout << ((inputnumber2 & mask) ? 1 : 0);
            }
            mask = mask >> 1;
            if (i == 0 or (i + 1) % 8 == 0) {
                cout << " ";
            }
        }
    }




    ////float////
    else if (choosetype == 3) {



        union MyUnion {
            float floatinTObit;
            int int2bitfloat;
        };
        cout << "\n" << "������� �������� ��� ���� float(����������� . ��� ��������� ����� �����) \n";
        MyUnion g;
        cin >> g.floatinTObit;
        cout << "������� ��� �������������?\n";
        cin >> inversionbit;
        int orderf = sizeof(float) * 8 - 1;
        unsigned int maskf = 1 << orderf;
        for (int i = 0; i <= orderf; i++) {
            if (inversionbit == 0 or inversionbit % 2 == 0) {
                cout << ((g.int2bitfloat & maskf) ? 1 : 0);
            }
            else {
                int in2bitfloat2 = ~g.int2bitfloat;
                cout << ((in2bitfloat2 & maskf) ? 1 : 0);
            }
            maskf = maskf >> 1;
            if (i == 0 or i == 8) {
                cout << " ";
            }
        }


    }


    else if (choosetype == 4) {
        cout << "\n������...";
    }
    else {
        cout << "������ �������� ���";
    }


    return 0;
}