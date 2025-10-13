#include <iostream>
using namespace std;

int main()
{
    string playerName;
    int playerHealth = 100;
    int playerAttack = 15;

    cout << "Enter your player name: ";
    cin >> playerName;

    cout <<"Welcome, "<< playerName <<"!"<< endl;
    cout <<"You have "<< playerHealth <<" HP and "<< playerAttack <<" attack damage"<<endl;

    cout <<"A Wild goblins has appeared!";
    int enemyHealth = 50;
    int enemyAttack = 10;

    while (playerHealth > 0 && enemyHealth > 0) 
    {
        cout << "\nChoose action: [1] Attack [2] Run\n> ";
        int choice;
        cin >> choice;

        if (choice == 1) 
        {
            cout << "You attack the Goblin!\n";
            enemyHealth -= playerAttack;
            cout << "Goblin HP: " << enemyHealth << "\n";

            if (enemyHealth <= 0) break;

            cout << "Goblin attacks you!\n";
            playerHealth -= enemyAttack;
            cout << "Your HP: " << playerHealth << "\n";
        } 
        else if (choice == 2) 
        {
            cout << "You ran away!\n";
            break;
        } 
        else 
        {
            cout << "Invalid choice!\n";
        }
    }

    if (playerHealth <= 0)
        cout << "\nYou were defeated!\n";
    else if (enemyHealth <= 0)
        cout << "\nYou defeated the Goblin!\n";

    return 0;
}