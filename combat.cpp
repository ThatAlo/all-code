#include <iostream>
using namespace std;

int pHelth[4] = { 100, 100, 100, 100 };
int Ehelth;
int turnRoll;
int choice;
int atkPoint[4] = { 65, 65, 65, 65 };
int pAtk;
bool block = false;
string pName[4]= {"hi", "hi", "hi", "hi"};
int pClass[4];
int difficulty;
int players;
void start(){
    cout << "how many people are playing \n(1-4)\n";
    cin >> players;
    for (int i = 0; i < players; i++) {
        cout << "p"<<i+1<<": what is your name?\n";
        cin >> pName[i];
    }
    cout << "welcome to wombat combat! \nwombat combat is a game where you will enter a gladitiorial arena with your enamy. \nat the beggining of each round a coin will be fliped and eyther you or the enemy will get to attack. if it is your turn to attack the menue will appear to show you your options, simply type in the number of the move you want to doand press enter. \nhowever, you will want to stay mindful of how much energy(or move points) you have left. if you run out of move points, or your helth drops to 0, you will loose. \n have fun!\n";
    cin.ignore();
    cin.get();
    system("cls");
    for (int j = 0; j < players; j++) {
        cout << "first things first, you are going to need to choose your class. p"<<j+1<<" there are three classes you can choose from.\n1: wizard, is a magic user who uses spells for all of their attacks.\n2 : fighter, if magic is a little to confusing for you, the fighter is perfect, prefering to take on their enamies with the power of their material weapons alone.\n3 : archer, the archer is similar to the fighter but with on large difference.instead of just going for streight damage, the archer provides a safer aproach by hitting enamys from a distance.\n";
        cin >> pClass[j];
    }
    cout << "next you will need to choose your difficulty (1-3)\n";
    cin >> difficulty;
    switch (difficulty) {
    case 1:
        Ehelth = 50 * players;
        break;
    case 2:
        Ehelth = 75 * players;
        break;
    case 3:
        Ehelth = 100 * players;
            break;
    case 4:
        Ehelth = 100000 * players;
        break;
    }
    system("cls");
}
void eTurn(bool block) {
    cout << "enamy turn:\n";
    int target = rand() % players;
    if (block == false) {
        int eatk = rand() % 10 + 1;
        pHelth[target] = pHelth[target] - eatk;
        cout << "enamy did " << eatk << " damage to p"<<target+1<<"\nplayer "<<target<<" helth : " << pHelth[target] << "\nenamy helth : " << Ehelth << "\n";
    }
    else {
        cout << "the enamy tried to attack, but it was blocked!\n";
    }
}
void pTurn(int k) {
    if (pClass[k] == 1) {
        switch (choice) {
        case 1:
            cout << "staff smack\n";
            atkPoint[k] = atkPoint[k] - 1;
            pAtk = rand() % 5 + 1;
            Ehelth = Ehelth - pAtk;
            if (rand() % 10 == 1) {
                cout << "opprotunity attack!\n";
                eTurn(block);
                block = false;
            }
            break;
        case 2:
            cout << "fireball\n";
            atkPoint[k] = atkPoint[k] - 2;
            pAtk = rand() % 10 + 1;
            Ehelth = Ehelth - pAtk;
            if (rand() % 3 == 1) {
                cout << "opprotunity attack!\n";
                eTurn(block);
                block = false;
            }
            break;
        case 3:
            cout << "magical cannon\n";
            pAtk = rand() % 20 + 1;
            Ehelth = Ehelth - pAtk;
            atkPoint[k] = atkPoint[k] - 6;
            cout << "opprotunity attack!\n";
            eTurn(block);
            block = false;
            break;
        }
    }
    else if (pClass[k] == 2) {
        switch (choice) {
        case 1:
            cout << "sword\n";
            atkPoint[k] = atkPoint[k] - 1;
            pAtk = rand() % 7 + 1;
            Ehelth = Ehelth - pAtk;
            if (rand() % 5 == 1) {
                cout << "opprotunity attack!\n";
                eTurn(block);
                block = false;
            }
            break;
        case 2:
            cout << "spear\n";
            atkPoint[k] = atkPoint[k] - 2;
            pAtk = rand() % 12 + 1;
            Ehelth = Ehelth - pAtk;
            if (rand() % 2 == 1) {
                cout << "opprotunity attack!\n";
                eTurn(block);
                block = false;
            }
            break;
        case 3:
            cout << "shield bash\n";
            pAtk = rand() % 25 + 1;
            Ehelth = Ehelth - pAtk;
            atkPoint[k] = atkPoint[k] - 6;
            cout << "opprotunity attack!\n";
            eTurn(block);
            block = false;
            break;
        }
    }
    else if (pClass[k] == 3) {
        switch (choice) {
        case 1:
            cout << "dagger\n";
            atkPoint[k] = atkPoint[k] - 1;
            pAtk = rand() % 3 + 1;
            Ehelth = Ehelth - pAtk;
            if (rand() % 15 == 1) {
                cout << "opprotunity attack!\n";
                eTurn(block);
                block = false;
            }
            break;
        case 2:
            cout << "short bow\n";
            atkPoint[k] = atkPoint[k] - 1;
            pAtk = rand() % 7 + 1;
            Ehelth = Ehelth - pAtk;
            if (rand() % 5 == 1) {
                cout << "opprotunity attack!\n";
                eTurn(block);
                block = false;
            }
            break;
        case 3:
            cout << "long bow\n";
            pAtk = rand() % 17 + 1;
            Ehelth = Ehelth - pAtk;
            atkPoint[k] = atkPoint[k] - 5;
            if (rand() % 3 == 1) {
                cout << "opprotunity attack!\n";
                eTurn(block);
                block = false;
            }
            break;
        }
    }
    cout << "you did " << pAtk << " damage\n";
}

    int main() {
    start();
    while (pHelth[1] > 0|| pHelth[0] > 0|| pHelth[2] > 0|| pHelth[3] > 0) {
        if (rand() % 2==1) {
            for (int k = 0; k < players; k++) {
                if (pClass[k] == 1) {
                    cout << pName[k] << "'s turn:\nmoves:\n1: staff smack: 1 move point, 1-5 damage, 1:10 chance to give your opponent an attack \n2: fireball: 2 move points, 1-10 damage, 1:3 chance to give your opponent an attack \n3: magical cannon: 6 move points, 1-20 damage, alwase give your opponent an attack \n4: block:4 move points, blocks your opponents next attack\n" << atkPoint[k] << " move points\nplayer helth: " << pHelth[k] << "\nenamy helth: " << Ehelth << "\n";
                }
                else if (pClass[k] == 2) {
                    cout << pName[k] << "'s turn:\nmoves:\n1: sword: 1 move point, 1-7 damage, 1:5 chance to give your opponent an attack \n2: spear: 2 move points, 1-15 damage, 1:2 chance to give your opponent an attack \n3: shield bash: 6 move points, 1-25 damage, alwase give your opponent an attack \n4: block:4 move points, blocks your opponents next attack\n" << atkPoint[k] << " move points\nplayer helth: " << pHelth[k] << "\nenamy helth: " << Ehelth << "\n";
                }
                else if (pClass[k] == 3) {
                    cout << pName[k] << "'s turn:\nmoves:\n1: knife: 1 move point, 1-3 damage, 1:15 chance to give your opponent an attack \n2: short bow: 2 move points, 1-10 damage, 1:3 chance to give your opponent an attack \n3: long bow: 6 move points, 1-20 damage, alwase give your opponent an attack \n4: block:4 move points, blocks your opponents next attack\n" << atkPoint[k] << " move points\nplayer helth: " << pHelth[k] << "\nenamy helth: " << Ehelth << "\n";
                }
                if (block == true) {
                    cout << "block: ready\n";
                }
                else {
                    cout << "block: not ready\n";
                }
                cin >> choice;
                if (choice != 4) {
                    pTurn(k);
                }
                if (choice == 4) {
                    block = true;
                    cout << "you prepare to block...\n";
                    atkPoint[k] = atkPoint[k] - 4;
                }
            }
        }
        else {
            eTurn(block);
            block = false;
        }
        cout << "press enter";
        cin.ignore();
        cin.get();
        system("cls");
        if (Ehelth <= 0) {
            cout << "you win! :D";
            return 0;
        }
        if (atkPoint[1] <= 0|| atkPoint[0] <= 0|| atkPoint[2] <= 0|| atkPoint[3] <= 0) {
            cout << "you lose! \n:'( \nyou ran out of move points";
            return 0;
        }
    }
        cout << "you lose! \n:'( \nyou ran out of health";
        return 0;
}