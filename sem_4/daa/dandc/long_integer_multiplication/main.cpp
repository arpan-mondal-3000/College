#include <iostream>
#include <string>
using namespace std;

// Asserting that lengths of A and B are same
string Multiply(string A, string B)
{
    if (A.length() == 1)
    {
        return to_string(stoi(A) * stoi(B));
    }
}

int main()
{
    string A, B; // Two long integers
    cout << "Enter one number: ";
    cin >> A;
    cout << "Enter other number: ";
    cin >> B;
    return 0;
}