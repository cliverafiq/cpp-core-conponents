#include <iostream>
using namespace std;

int main()
{
    string playerName;
    int health = 100;
    int attack = 15;

    cout << "Enter your player name: ";
    cin >> playerName;

    cout <<"Welcome, "<< playerName <<"!"<< endl;
    cout <<"You have "<< health <<" HP and "<< attack <<" attack damage"<<endl;
    return 0;
}