#include <iostream>
#include "hashtable.h"
#include "passserver.h"

using namespace std;

void Menu()
{
  cout << "\n\n";
  cout << "l - Load From File" << endl;
  cout << "a - Add User" << endl;
  cout << "r - Remove User" << endl;
  cout << "c - Change User password" << endl;
  cout << "f - Find User" << endl;
  cout << "d - Dump HashTable" << endl;
  cout << "s - HashTable Size" << endl;
  cout << "w - Write to password File" << endl;
  cout << "x - Exit program" << endl;
  cout << "\nEnter choice : ";
}

int main()
{ 

	char select;
	char filename[100];
	int sizeoftable;
	string usersearch, key, password,newpassword;
	pair<string,string> stringp;

	//request for size of table
	cout << "how big will the table be (positive integer): "; cin >> sizeoftable;

	//constructor called to create the table of size prime_below
	PassServer server(sizeoftable);

	//lets user know how big the created table is
	cout << "\nset to: " << server.HowManyBuckets();

	//prints menu
	Menu();cin >> select;


	//exits only when x is selected
	while(select != 'x')
	{
		if(select=='l' || select=='a' || select=='r' || select=='c' || select=='f' || select=='d' || select=='s' || select=='w')
			{
				switch(select)
					{
						//asks user for filename to load into server object
						case 'l':
								{
									cout << "enter password filename to load: ";
									cin >> filename;
									server.load(filename);
									break;
								}

						//adds user iff user doesnt already exist or under 
						//a different password
						case 'a':
								{
									cout << "user name: ";
									cin >> stringp.first;
									cout << "password: ";
									cin >> stringp.second;
									if(server.addUser(stringp))
										cout << "\nsuccessfully added\n";
									else
										cout << "\nuser already exists\n";
									break;
								}

						//removes user from server object
						case 'r':
								{
									cout << "key to remove: ";cin >> key;
									if(server.removeUser(key))
										cout << "\nsuccessfully removed\n";
									else
										cout << "\nuser not found\n";
									break;
								}

						//change password
						case 'c':
								{
									cout << "enter user name: ";
									cin >> stringp.first;
									cout << "enter user current password: ";
									cin >> stringp.second;
									cout << "enter new password: ";
									cin >> newpassword;

									if(server.changePassword(stringp, newpassword))
										cout << "success!\n";
									else
										cout << "failure\n";	;
									break;
								}

						//returns true if key exists
						case 'f':
								{
									cout << "search for which user? ";
									cin >> usersearch;
									if(server.find(usersearch))
										cout << "success!\n";
									else
										cout << "failure\n";		
									break;
								}

						//dump!!!!
						case 'd':
								{
									server.dump();	
									break;
								}

						//returns size
						case 's':	
								{
									cout << server.size() << endl;
									break;
								}

						case 'w':{
									cout << "enter password to write: ";
									cin >> filename;
									server.write_to_file(filename);
									break;}
					}
			}
		else
		cout <<	"\ninvalid input: please select a valid input from the menu\n";
		

		Menu();
		cin >> select;
	}

	return 0;
}
