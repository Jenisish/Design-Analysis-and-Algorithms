#include <iostream> 
using namespace std; 
 
#define MAX 10 
 
class student 
{ 
 private: 
 char name[30]; 
 long long rollNo; 
 char branch[30]; 
 char pname[100]; 
 long long phno; 
 public: 
 //member function to get student's details 
 void getDetails(void); 
 //member function to print student's details 
 void putDetails(void); 
}; 
 
//member function definition, outside of the class 
void student::getDetails(void){ 
 cout << "Enter roll number: "; 
 cin >> rollNo; 
 cout << "Enter name: " ; 
 cin >> name; 
 cout << "Enter branch: "; 
 cin >> branch; 
 cout << "Enter program name: "; 
 cin >> pname; 
 cout << "Enter phone number: "; 
 cin >> phno; 
 
} 
 
//member function definition, outside of the class 
void student::putDetails(void){ 
 cout << rollNo<<"\t"<< name <<"\t\t "<< branch<<"\t\t" << pname<<"\t\t"<<phno; 
} 
 
int main() 
{ 
 student std[MAX]; //array of objects creation 
 int n,loop; 
 
 cout << "Enter total number of students: "; 
 cin >> n; 
 
 for(loop=0;loop< n; loop++){ 
 cout << "Enter details of student " << loop+1 << ":\n"; 
 std[loop].getDetails(); 
 } 
 
 cout << endl; 
 cout << "Details of student :\n"; 
 cout<<"Roll Number \t Name \t\t Branch \t Program name\t\t Phone number\n"; 
 for(loop=0;loop< n; loop++){ 
 
 std[loop].putDetails(); 
 } 
 
 return 0; 
}