#include <iostream>
using namespace std;

class Test
{
public:
    Test()  { cout << "Constructor\n"; }
    ~Test() { cout << "Destructor\n"; }
};

int main()
{
    Test* p1 = (Test*)malloc(sizeof(Test));
    free(p1);

    cout << "------\n";

    Test* p2 = new Test;
    delete p2;

    return 0;
}

// ------
// Constructor
// Destructor