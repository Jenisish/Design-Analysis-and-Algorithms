#include <iostream>
using namespace std;
class staff
{
    int staffid;
    char name[100];
    long int phone;
    float salary;
public:
    void set_p()
    {
        cout << "\nEnter the Id: ";
        cin >> staffid;
        fflush(stdin);
        cout << "Enter the Name: ";
        cin.get(name, 100);
        cout << "enter phone no.: ";
        cin >> phone;
        cout << "enter salary: ";
        cin >> salary;
    }
    void display_p()
    {
        cout << "\n\nStaff id:" << staffid << endl;
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
        cout << "salary: " << salary << endl;
    }
};
class Teaching : private staff
{
    char domain[50];
    int publications;
public:
    void set_s()
    {
        set_p();
        cout << "Enter the Domain Name: ";
        fflush(stdin);
        cin.getline(domain, 50);
        cout << "Enter the No. of Publications: ";
        cin >> publications;
    }
    void display_s()
    {
        display_p();
        cout << "Domain: " << domain << endl;
        cout << "No. of Publications: " << publications << endl;
    }
};
class Technical : private staff
{
    char skills[50];
public:
    void set_x()
    {
        set_p();
        cout << "Enter the skills:";
        fflush(stdin);
        cin.getline(skills, 50);
    }
    void display_x()
    {
        display_p();
        cout << "skills: " << skills << endl;
    }
};
class Contract : private staff
{
    int period;
public:
    void set_y()
    {
        set_p();
        cout << "Enter the No. of Period:";
        cin >> period;
    }
    void display_y()
    {
        display_p();
        cout << "No. of Period: " << period << endl;
    }
};
int main()
{
    int x,y,s;
    cout<<"enter no of records\n";
    cin>>y;
    for(x=1;x<=y;x++)
    {
    cout<<"give the details\n";
    cout<<"enter teaching details:";
        Teaching s;
        s.set_s();
        cout<<"enter technical details";
        Technical a;
        a.set_x();
        cout<<"enter contract details";
        Contract b;
        b.set_y();
         s.display_s();
         a.display_x();
        b.display_y();
        return 0;
    }
}