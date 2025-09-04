#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Asserting that lengths of A and B are same
int Multiply(string A, string B)
{
    if (A.length() == 1)
    {
        return stoi(A) * stoi(B);
    }
    string w, x, y, z;
    // A = w * 10^m + x
    w = A.substr(0, ceil(A.length() / 2.0));
    x = A.substr(ceil(A.length() / 2.0), A.length());
    // B = y * 10^m + z
    y = B.substr(0, ceil(B.length() / 2.0));
    z = B.substr(ceil(B.length() / 2.0), B.length());

    // multiply (w+x) and (y+z)
    int p = Multiply(to_string(stoi(w) + stoi(x)), to_string(stoi(y) + stoi(z)));
    // multiply w, y
    int q = Multiply(w, y);
    // multiply x, z
    int r = Multiply(x, z);

    return (q * pow(10, A.length())) + ((p - q - r) * pow(10, A.length() / 2)) + r;
}

int main()
{
    string A, B; // Two long integers
    cout << "Enter one number: ";
    cin >> A;
    cout << "Enter other number: ";
    cin >> B;

    int res = Multiply(A, B);
    cout << "Result: " << res << endl;
    return 0;
}