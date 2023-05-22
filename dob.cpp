#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Customer 
{
    private:
        string name;
        string date_of_birth;
    
    public:
        Customer(string name, string date_of_birth) 
        {
            this->name = name;
            this->date_of_birth = date_of_birth;
        }

        void display() 
        {
            cout << "Name: " << name << endl;
            cout << "Date of Birth: " << date_of_birth << endl;
        }

        static Customer read(string input) 
        {
            vector<string> tokens;
            stringstream ss(input);
            string token;
            while (getline(ss, token, '/'))
             {
                tokens.push_back(token);
            }

            string name = tokens[0];
            string date_of_birth = tokens[1] + "/" + tokens[2] + "/" + tokens[3];

            return Customer(name, date_of_birth);
        }
};

int main() 
{
    string input = "Jenisish/10/03/2004";
    Customer customer = Customer::read(input);
    customer.display();

    return 0;
}