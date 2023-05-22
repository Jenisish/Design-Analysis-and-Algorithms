#include <iostream>
#include <exception>

using namespace std;

int main() {
    double a, b;

    cout<<"enter the value of a : ";
    cin >> a;
    cout<<"enter the value of b : ";
    cin>> b;
   try {
        if (b == 0) {
            throw exception();
        }
        cout << "a/b = " << a / b << endl;
    } catch (exception& e) {
        cout << "Error: division by zero" << endl;
    }

    return 0;
}
