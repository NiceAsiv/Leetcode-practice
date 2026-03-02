#include <iostream>
using namespace std;

// --------- 指针函数 ----------
int* pointerFunction(int &x)
{
    return &x;
}

// --------- 普通函数（用于函数指针） ----------
int add(int a, int b)
{
    return a + b;
}

int main()
{
    cout << "===== 1. 数组指针 =====" << endl;

    int arr[5] = {1, 2, 3, 4, 5};

    int (*pArray)[5] = &arr;   // 数组指针

    cout << "First element: " << (*pArray)[0] << endl;
    cout << "Third element: " << (*pArray)[2] << endl;


    cout << "\n===== 2. 指针数组 =====" << endl;

    int a = 10, b = 20, c = 30;

    int *ptrArray[3] = {&a, &b, &c};  // 指针数组

    for(int i = 0; i < 3; i++)
    {
        cout << "Value: " << *ptrArray[i] << endl;
    }


    cout << "\n===== 3. 函数指针 =====" << endl;

    int (*pf)(int, int) = add;   // 函数指针

    int result = pf(3, 4);
    cout << "3 + 4 = " << result << endl;


    cout << "\n===== 4. 指针函数 =====" << endl;

    int x = 100;
    int *p = pointerFunction(x);   // 调用指针函数

    cout << "Returned pointer value: " << *p << endl;

    return 0;
}