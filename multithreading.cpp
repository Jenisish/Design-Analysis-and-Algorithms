#include<chrono>
#include<iostream>
#include<thread>

using namespace std;

int random_number,square,cube;

void random_gen(void)
{
	srand((unsigned) time(NULL));
	random_number = (rand()%100+1);
	cout<<"Generated random number is:"<<random_number<<endl;
	this_thread::sleep_for(chrono::seconds(2));
}

void display_square(void)
{
	srand((unsigned) time(NULL));
	square = random_number*random_number;
	cout<<"The square of the number is:"<<square<<endl;
	this_thread::sleep_for(chrono::seconds(2));
}

void display_cube(void)
{
	srand((unsigned) time(NULL));
	cube = random_number*random_number*random_number;
	cout<<"Cube of the number is:"<<cube<<endl<<endl;
	this_thread::sleep_for(chrono::seconds(3));
}


int main(){
    int x,i;
    cout<<"Enter the No. of threads : ";
    cin>>x;

	for(int i=0;i<x;i++)
	{
		thread th1(random_gen);
		th1.join();
		thread th2(display_square);
		th2.join();
		thread th3(display_cube);
		th3.join();
    }

	return 0;
}