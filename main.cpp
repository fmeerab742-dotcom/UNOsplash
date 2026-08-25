#include <iostream>
#include <string>
#include "FileManager.h"

using namespace std;

int main()
{
    string username;
    string password;

    cout << "==========================" << endl;
    cout << "      UNO GAME TEST       " << endl;
    cout << "==========================" << endl;

    cout << "\nCreate Account" << endl;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    FileManager::saveUser(username, password);


    cout << "\n--------------------------" << endl;
    cout << "          LOGIN           " << endl;
    cout << "--------------------------" << endl;

    string loginUsername;
    string loginPassword;

    cout << "Username: ";
    cin >> loginUsername;

    cout << "Password: ";
    cin >> loginPassword;


    if (FileManager::validateUser(loginUsername,
                                  loginPassword))
    {
        cout << "\nLogin Successful!" << endl;
        cout << "Welcome to UNO, "
             << loginUsername
             << "!" << endl;
    }
    else
    {
        cout << "\nLogin Failed!" << endl;
        cout << "Incorrect username or password."
             << endl;
    }

    return 0;
}