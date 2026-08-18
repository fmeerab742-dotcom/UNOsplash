#include "FileManager.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


// ==========================================
// CHECK IF USER ALREADY EXISTS
// ==========================================

bool FileManager::userExists(const string& username)
{
    ifstream file("users.txt");

    // File may not exist the first time.
    if (!file.is_open())
    {
        return false;
    }

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string savedUsername;
        string savedPassword;

        getline(ss, savedUsername, ',');
        getline(ss, savedPassword);

        if (savedUsername == username)
        {
            file.close();
            return true;
        }
    }

    file.close();

    return false;
}


// ==========================================
// SAVE NEW USER
// ==========================================

bool FileManager::saveUser(const string& username,
                           const string& password)
{
    // Prevent duplicate usernames
    if (userExists(username))
    {
        cout << "User already exists!" << endl;
        return false;
    }

    // ios::app means add data without deleting old data
    ofstream file("users.txt", ios::app);

    if (!file.is_open())
    {
        cout << "Error: Could not open users.txt" << endl;
        return false;
    }

    file << username << "," << password << endl;

    file.close();

    cout << "User saved successfully!" << endl;

    return true;
}


// ==========================================
// LOGIN / VALIDATE USER
// ==========================================

bool FileManager::validateUser(const string& username,
                               const string& password)
{
    ifstream file("users.txt");

    if (!file.is_open())
    {
        cout << "Error: users.txt does not exist." << endl;
        return false;
    }

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string savedUsername;
        string savedPassword;

        getline(ss, savedUsername, ',');
        getline(ss, savedPassword);

        if (savedUsername == username &&
            savedPassword == password)
        {
            file.close();
            return true;
        }
    }

    file.close();

    return false;
}