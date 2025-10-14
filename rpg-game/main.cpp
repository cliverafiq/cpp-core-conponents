#include <iostream>
using namespace std;

struct Player {
    string name;
    int health;
    int attack;
};

struct Enemy {
    string name;
    int health;
    int attack;
};

void fight(Player &player, Enemy &enemy) {
    cout << "\nA wild " << enemy.name << " appears!\n";

    while (player.health > 0 && enemy.health > 0) {
        cout << "\nChoose action: [1] Attack [2] Run\n> ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "You attack the " << enemy.name << "!\n";
            enemy.health -= player.attack;
            cout << enemy.name << " HP: " << enemy.health << "\n";

            if (enemy.health <= 0) break;

            cout << enemy.name << " attacks you!\n";
            player.health -= enemy.attack;
            cout << "Your HP: " << player.health << "\n";
        } else if (choice == 2) {
            cout << "You ran away!\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

    if (player.health <= 0)
        cout << "\nYou were defeated!\n";
    else if (enemy.health <= 0)
        cout << "\nYou defeated the " << enemy.name << "!\n";
}

int main()
{
    Player player;

    cout << "Enter your player name: ";
    cin >> player.name;

    cout <<"Welcome, "<< player.name <<"!"<< endl;
    cout <<"You have "<< player.name <<" HP and "<< player.attack <<" attack damage"<<endl;

    Enemy goblin;
    goblin.name = "Goblin";
    goblin.health = 50;
    goblin.attack = 10;

    fight(player, goblin);

    cout << "\nGame over!\n";

    return 0;
}