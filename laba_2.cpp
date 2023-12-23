#include <iostream>
#include <chrono>
#include <time.h>
#include <algorithm>
using namespace std;
using namespace chrono;

int main()
{
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    constexpr int arralenght = 100;
    int arra[arralenght], arrastart[arralenght], choosetype;
        for (int i = 0; i < arralenght; i++) {
            arra[i] = rand() % 199 - 99;
            arrastart[i] = arra[i];
        }
        cout << "Array created and sorted\n";


        start = steady_clock::now();
        for (int i = 0; i < arralenght; i++) {
            for (int j = 0; j < arralenght - 1; j++) {
                if (arra[j] > arra[j + 1])
                    swap(arra[j], arra[j + 1]);
            }
        }
        end = steady_clock::now();
        result = duration_cast<nanoseconds>(end - start);

        cout << "Sorting time = " << result.count() << "\n\n";

        cout << "Create new array/Show not sorted array/Show sorted array - 1\n";
        cout << "Min/Max from not sorted and sorted array - 2\n";
        cout << "Index, average from not sorted array - 3\n";
        cout << "Index, average from sorted array - 4\n";
        cout << "Amount of numbers(in sort) that <A - 5\n";
        cout << "Amount of numbers(in sort) that >B - 6\n";
        cout << "Swap elements - 7\n";
        cout << "IDZ 1 - 8\n";
        cout << "Exit - 0\n\n";


        do {
            cout << "Choose what you want(Show choices - 9)\n";
            cin >> choosetype;
            switch (choosetype)
            {
            case 1: {
                int choosetypearra;
                do {
                    cout << "Choose what you want(func 1)\n" << "Create new array - 1\n" << "Show not sorted array - 2\n" << "Show sorted array - 3\n" << "Exit from func - 0\n";
                    cin >> choosetypearra;
                    switch (choosetypearra)
                    {
                    case 1: {
                        for (int i = 0; i < arralenght; i++) { 
                            arra[i] = rand() % 199 - 99;
                            arrastart[i] = arra[i];
                        }
                        cout << "New array created and sorted\n";

                        auto start = steady_clock::now();
                        for (int i = 0; i < arralenght; i++) {
                            for (int j = 0; j < arralenght - 1; j++) {
                                if (arra[j] > arra[j + 1])
                                    swap(arra[j], arra[j + 1]);
                            }
                        }
                        auto end = steady_clock::now();
                        auto result = duration_cast<nanoseconds>(end - start);
                        cout << "Sorting time = " << result.count() << "\n";

                        break;
                    }

                    case 2: {
                        cout << "Not sorted array\n";
                        for (int i = 0; i < arralenght; i++)
                        {
                            cout << arrastart[i] << "   ";
                        }
                        cout << "\n";
                        break;

                    }
                    case 3: {
                        cout << "Sorted array\n";
                        for (int i = 0; i < arralenght; i++) {
                            cout << arra[i] << "   ";
                        }
                        cout << "\n";
                        break;
                    }
                    } 
                } while (choosetypearra);
                break;
            }

            case 2: {
                cout << "You choosed show Min/Max from not sorted and sorted array(2)\n";
                int minarrastart = arrastart[0], maxarrastart = arrastart[0];
                auto start = steady_clock::now();
                for (int i = 0; i < arralenght; ++i) {
                    if (arrastart[i] > maxarrastart) {
                        maxarrastart = arrastart[i];
                    }
                    if (arrastart[i] < minarrastart) {
                        minarrastart = arrastart[i];
                    }
                }
                auto end = steady_clock::now();
                auto result = duration_cast<nanoseconds>(end - start);
                cout << "Search time of not sorted array = " << result.count() << "\n";

                cout << "Min from not sort = " << minarrastart << "\n";
                cout << "Max from not sort = " << maxarrastart << "\n";

                int maxarrasort = arra[0], minarrasort = arra[0];
                auto start1 = steady_clock::now();
                for (int i = 0; i < arralenght; ++i) {
                    if (arra[i] > maxarrasort) {
                        maxarrasort = arra[i];
                    }
                    if (arra[i] < minarrasort) {
                        minarrasort = arra[i];
                    }
                }
                auto end1 = steady_clock::now();
                auto result1 = duration_cast<nanoseconds>(end1 - start1);
                cout << "Search time after bubble = " << result1.count() << "\n";
                cout << "Min from sort= " << minarrasort << "\n";
                cout << "Max from sort= " << maxarrasort << "\n"<<"(2) ended\n\n";
                
                break; }

            case 3: {
                cout << "You choosed show index, average from not sorted array(3)\n";
                int minarrastartn = arrastart[0], maxarrastartn = arrastart[0], countindexmax = 0, countindexmin = 0;
                float averagenotsort;
                auto start = steady_clock::now();
                for (int i = 0; i < arralenght; ++i) {
                    if (arrastart[i] > maxarrastartn) {
                        maxarrastartn = arrastart[i];
                    }
                    if (arrastart[i] < minarrastartn) {
                        minarrastartn = arrastart[i];
                    }
                }
                for (int i = 0; i < arralenght; ++i) {
                    if (arrastart[i] == minarrastartn) {
                        cout << "With index " << i << " contained element with min value\n";
                        countindexmin += 1;
                    }
                    if (arrastart[i] == maxarrastartn) {
                        cout << "With index " << i << " contained element with max value\n";
                        countindexmax += 1;
                    }
                }
                auto end = steady_clock::now();
                auto result = duration_cast<nanoseconds>(end - start);
                cout << "Count min = " << countindexmin << "\n" << "Count max = " << countindexmax << "\n";
                cout << "Average search of not sorted array time = " << result.count() << "\n";
                averagenotsort = (minarrastartn + maxarrastartn) / 2.0;

                cout << "Average from not sort= " << averagenotsort << "\n";
                cout << "(3) ended\n\n";
                break;
            }

            case 4: {
                cout << "You choosed show index, average from sorted array(4)\n";
                int maxarrasortn = arra[0], minarrasortn = arra[0], countindexmax = 0, countindexmin = 0;
                float averagesort;
                auto start = steady_clock::now();
                for (int i = 0; i < arralenght; ++i) {
                    if (arra[i] > maxarrasortn) {
                        maxarrasortn = arra[i];
                    }
                    if (arra[i] < minarrasortn) {
                        minarrasortn = arra[i];
                    }
                }
                for (int i = 0; i < arralenght; ++i) {
                    if (arra[i] == minarrasortn) {
                        cout << "With index " << i << " contained element with min value\n";
                        countindexmin += 1;
                    }
                    if (arra[i] == maxarrasortn) {
                        cout << "With index " << i << " contained element with max value\n";
                        countindexmax += 1;
                    }
                }
                auto end = steady_clock::now();
                auto result = duration_cast<nanoseconds>(end - start);
                cout << "Count min = " << countindexmin << "\n" << "Count max = " << countindexmax << "\n";
                cout << "Average search of sorted array time = " << result.count() << "\n";
                averagesort = (minarrasortn + maxarrasortn) / 2.0;
                cout << "average from sort= " << averagesort << "\n";
                cout << "(4) ended\n\n";
                break;
            }

            case 5: {
                cout << "You choosed show mount of numbers(in sort) that <A(5)\n";
                int numbera, countindexa=0;
                cout << "Initialize the number A\n";
                cin >> numbera;
                for (int i = 0; i < arralenght; ++i) {
                    if (arra[i] < numbera) {
                        countindexa += 1;
                    }
                }
                cout << "Amount of numbers that <A = " << countindexa << "\n";
                cout << "(5) ended\n\n";
                break;
            }

            case 6: {
                cout << "You choosed show amount of numbers(in sort) that >B(6)\n";
                int numbera, countindexa = 0;
                cout << "Initialize the number B\n";
                cin >> numbera;
                for (int i = 0; i < arralenght; ++i) {
                    if (arra[i] > numbera) {
                        countindexa += 1;
                    }
                }
                cout << "Amount of numbers that >B = " << countindexa << "\n";
                cout << "(6) ended\n\n";
                break;
            }

            case 7: {
                cout<<"You choosed swap elements(7)\n";
                int choosearra, indexfirst, indexsecond;
                cout << "Choose in which array we will swap( 1 - sort, 2 - not sort, 0 - exit)\n";
                cin >> choosearra;
                if (choosearra == 0)
                break;
                cout << "Enter first index of element to swap\n";
                cin >> indexfirst;
                cout << "Enter second index of element to swap\n";
                cin >> indexsecond;
                switch (choosearra) {
                case 1: {
                    auto start = steady_clock::now();
                    swap(arra[indexfirst], arra[indexsecond]);
                    auto end = steady_clock::now();
                    auto result = duration_cast<nanoseconds>(end - start);
                    cout << "Time of swap = " << result.count() << "\n";
                    break;
                }
                case 2: {
                    auto start = steady_clock::now();
                    swap(arrastart[indexfirst], arrastart[indexsecond]);
                    auto end = steady_clock::now();
                    auto result = duration_cast<nanoseconds>(end - start);
                    cout << "Time of swap = " << result.count() << "\n";
                    break;
                }
                
                } //switch end
                cout << "(7) ended\n";
                break;
            }
            case 8: {
                cout << "For not sorted array\n";
                int newarra[arralenght],count[10];
                for (int i = 0; i < 10; i++)
                    count[i] = 0;
                newarra[arralenght - 1] = arrastart[0] + arrastart[arralenght - 1];
                for (int i = 0; i < arralenght - 1; i++)
                    newarra[i] = arrastart[i] + arrastart[i + 1];
                for(int i=0;i<arralenght;i++)
                    swap(newarra[i], newarra[rand() % 100]);
                for (int i = 0; i < arralenght; i++) {
                        for (int j = 1; j <= 9; j++) {
                            if (newarra[i] % j == 0) {
                                count[j] += 1;
                            }
                        }
                }
                for (int j = 1; j <= 9; j++)
                    cout << "Amount of elements who divided entirely into " << j << " = " << count[j] << "\n";
                break;
            }
            case 9: {
                cout << "Create new array/Show not sorted array/Show sorted array - 1\n";
                cout << "Min/Max from not sorted and sorted array - 2\n";
                cout << "Index, average from not sorted array - 3\n";
                cout << "Index, average from sorted array - 4\n";
                cout << "Amount of numbers(in sort) that <A - 5\n";
                cout << "Amount of numbers(in sort) that >B - 6\n";
                cout << "Swap elements - 7\n";
                cout << "Idz - 8 \n";
                cout << "Exit - 0\n";

                break;
            }

            }//switch end
        } while (choosetype);

    return 0;
}
