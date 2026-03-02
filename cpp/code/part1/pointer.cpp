#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 20;

    cout << "Initial values: a = " << a << ", b = " << b << endl;

    // 1. const int * p  （或 int const * p）
    const int *p = &a;

    // *p = 100;      // 错误：不能通过 p 修改值
    p = &b;           // 正确：可以修改指向

    cout << "p now points to b, *p = " << *p << endl;


    // 2. int * const p2
    int * const p2 = &a;

    *p2 = 300;        // 正确：可以修改值
    // p2 = &b;       // 错误：不能修改指向

    cout << "After modifying through p2, a = " << a << endl;


    // 3. const int * const p3
    const int * const p3 = &b;

    // *p3 = 400;     // 错误：不能修改值
    // p3 = &a;       // 错误：不能修改指向

    cout << "p3 always points to b, *p3 = " << *p3 << endl;

    return 0;
}