
#include <iostream>
#include <string>
#include <utility>
#include <cctype>
#include "passserver.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;

void Menu()
{
  cout << "\n\n";
  cout << "l - Load From File" << endl;
  cout << "a - Add User" << endl;
  cout << "r - Remove User" << endl;
  cout << "c - Change User Password" << endl;
  cout << "f - Find User" << endl;
  cout << "d - Dump HashTable" << endl;
  cout << "s - HashTable Size" << endl;
  cout << "w - Write to Password File" << endl;
  cout << "x - Exit program" << endl;
  cout << "\nEnter choice : ";
}

void parse_input(char &c, PassServer & passtable);

int main(void)
{
	std::size_t size;
	cout << "Enter preferred hash table capacity: ";
	cin >> size;

	PassServer server1(size);

	char c;
	Menu();
	while (cin >> c)
	{
		if (c == 'x' || c == 'X') break;
		parse_input(c, server1);
		Menu();
	}
return 0;
}

void parse_input(char &c, PassServer & passtable)
{
	string input;
	string input2;
	string input3;

	c = std::tolower(c);
	switch(c) 
	{
		case 'l':
		{
			cout << "\nEnter password file name to load from: ";
			cin >> input;
			if (passtable.load(input.c_str())) break;
			else
			{ cout << "Error: Cannot open file " << input; break; }
		}
		case 'a':
		{
			cout << "Enter username: ";
			cin >> input;
			cout << "Enter password: ";
			cin >> input2;
			if(passtable.addUser(make_pair(input, input2)))
			     cout << "\nUser " << input << " added.";
                        else cout << "\nERROR: User already exists. Could not add user.";
			break;
		}
		case 'r':
		{
			cout << "Enter username: ";
			cin >> input;
			if(passtable.removeUser(input))
				cout << "User " << input << " deleted.";
			else
				cout << "ERROR: User not found.  Could not remove user.";
			break;
		}	
		case 'c':
		{
			cout << "Enter username: ";
			cin >> input;
			cout << "Enter password: ";
			cin >> input2;
			cout << "\nEnter new password: ";
			cin >> input3;
			if (passtable.changePassword(make_pair(input, input2), input3))
				{cout << "\nPassword changed for user " << input; break;}
			cout << "Error: Could not change user password";
			break;
		}
		case 'f':
		{
			cout << "Enter username: ";
			cin >> input;
			if (passtable.find(input))
				{cout << "\nUser '" << input << "' found."; break;}
			cout << "\nUser '" << input << "' not found.";
			break;
		}
		case 'd':
		{
			passtable.dump();
			break;
		}
		case 's':
		{
			cout << "Size of hashtable: " << passtable.size();
			break;
		}
		case 'w':
		{
			cout << "Enter password file name to write to: ";
			cin >> input;
			passtable.write_to_file(input.c_str());
			break;
		}
	}
}
