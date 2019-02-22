#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include<windows.h> //use Sleep(#miliseconds) function
using namespace std;

struct studentInfo {
	int age;
	char name[30], gender[10], major[20], status[20]; //structs can only hold arrays, not strings
	struct studentInfo *nextNode;//create place in struct to hold a pointer to the address of the next node.
};

//create insertStudent Function.
struct studentInfo*insertStudent(struct studentInfo*phead, string newName, int newAge, string newGender, string newStatus, string newMajor) {
	struct studentInfo*pfront;
	pfront=(struct studentInfo*)malloc(sizeof(struct studentInfo));
	strcpy_s(pfront->name, newName.c_str());
	pfront->age = newAge;
	strcpy_s(pfront->gender,newGender.c_str());
	strcpy_s(pfront->status,newStatus.c_str());
	strcpy_s(pfront->major,newMajor.c_str());
	pfront->nextNode = phead;
	return pfront;
};
int main() {
	ifstream reader;
	string stringStorage;
	// int i, j;
	struct studentInfo *firstNode, *linkToNextNode, *addressOfNextNode, *searchNode; // create pointers to first and most recently created node , also a node that stores current search results

	reader.open("linkListData.txt", ios::in);
	if (!reader.is_open()) {
		cout << "Unable to open file\n";
		system("pause");
		exit(1);
	}

	firstNode = (struct studentInfo *)malloc(sizeof(struct studentInfo));
	getline(reader, stringStorage);
	strcpy_s(firstNode->name, stringStorage.c_str());
	//cout << "read name :" << stringStorage << endl;
	reader >> firstNode->age;
	reader.ignore();
	//cout << "read age :" << firstNode->age << endl;
	getline(reader, stringStorage);
	//cout << "read gender :" << stringStorage << endl;
	strcpy_s(firstNode->gender, stringStorage.c_str());
	getline(reader, stringStorage);
	//cout << "read major :" << stringStorage << endl;
	strcpy_s(firstNode->major, stringStorage.c_str());
	getline(reader, stringStorage);
	//cout << "read status :" << stringStorage << endl;
	strcpy_s(firstNode->status, stringStorage.c_str());
	firstNode->nextNode = NULL;

	linkToNextNode = firstNode;
	//system("pause");
	while (1) {

		getline(reader, stringStorage);
		//cout << "Str value is now: " << stringStorage << endl;
		if (reader.eof()) {
			break;
		}


		addressOfNextNode = (struct studentInfo *)malloc(sizeof(struct studentInfo));
		//cout << "read name :" << stringStorage << endl;

		strcpy_s(addressOfNextNode->name, stringStorage.c_str());
		reader >> addressOfNextNode->age;
		reader.ignore();
		//cout << "read age :" << addressOfNextNode->age << endl;
		getline(reader, stringStorage);
		//cout << "read gender :" << stringStorage << endl;
		strcpy_s(addressOfNextNode->gender, stringStorage.c_str());
		getline(reader, stringStorage);
		//cout << "read major :" << stringStorage << endl;
		strcpy_s(addressOfNextNode->major, stringStorage.c_str());
		getline(reader, stringStorage);
		//cout << "read status :" << stringStorage << endl;
		strcpy_s(addressOfNextNode->status, stringStorage.c_str());
		addressOfNextNode->nextNode = NULL;
		linkToNextNode->nextNode = addressOfNextNode;
		linkToNextNode = addressOfNextNode;

		//system("pause");
	}
	
	int enteredAge;
	string enteredName, enteredGender, enteredStatus, enteredMajor;
	cout << "Welcome to Student Info!\n";
	cout << "Please Enter the information of the student you would like to add to the datafile.\n";
	cout << "Please enter the students Name: " << endl;
	cin >> enteredName;
	cout << "Please enter the students Age: " << endl;
	cin >> enteredAge;
	cout << "Please enter the students Gender: " << endl;
	cin >> enteredGender;
	cout << "Please enter the students Status: " << endl;
	cin >> enteredStatus;
	cout << "Please enter the students Major: " << endl;
	cin >> enteredMajor;

	firstNode = insertStudent(firstNode, enteredName, enteredAge, enteredGender, enteredStatus, enteredMajor);

	//out put to file
	struct studentInfo*current = firstNode;//point to first
	ofstream write("newLinkListData.txt");
	do  {

		write << current->name << endl << current->age << endl;
		write << current->gender << endl << current->status << endl << current->major << endl;
		current = current->nextNode;//make the current pointer point to the next node.
	} while (current->nextNode != NULL);
	cout << "Submitting New Student Entry......" << endl;
	Sleep(2000);
	cout << "New Student Created. Displaying New Entry..." << endl;
	Sleep(2000);
	cout << "\n\nStudent Name------------------Major-----Search-Results------Status----Gender--------------Age----------------------------" << endl;
	cout << setw(30) << left << firstNode->name << setw(30) << firstNode->major;
	cout << setw(10) << firstNode->status << setw(20) << firstNode->gender;
	cout << setw(5) << firstNode->age << endl;
	reader.close();
	write.close();

	cout << "\n\n";
	system("pause");

	return 0;}

/*#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include<windows.h> //use Sleep(#miliseconds) function
using namespace std;

struct studentInfo {
	int age;
	char name[30], gender[10], major[20], status[20]; //structs can only hold arrays, not strings
	struct studentInfo *nextNode;//create place in struct to hold a pointer to the address of the next node.
};

bool search(struct studentInfo* head, string ss) { //function passes pointer to struct and compares feild to string
	struct studentInfo* current = head; //create pointer to current node
	while (current != NULL) { //while we are not at the last node
		if (current->name == ss) { //if the name field in the current node holds a value = to the value in string ss
			cout << "Searching Database... " <<endl;
			Sleep(2000);
			cout <<"Student Found: Retrieving Student Info..."<<endl;
			Sleep(2000); //#include <windows.h>
			cout <<"\n\nStudent Name------------------Major-----Search-Results------Status----Gender--------------Age----------------------------"<<endl;
			cout << setw(30) << left << current->name << setw(30) << current->major;
			cout << setw(10) << current->status << setw(20) << current->gender;
			cout << setw(5) << current->age << endl;
			return true; //exit function
		}
			current = current->nextNode; // tell current pointer to point at next node so that the next node become the current node
	}
		cout << "Searching Database... " << endl;
		Sleep(2000);//#include <windows.h>
		cout <<"Sorry, "<< ss << " was not found in this database."<<endl;
		return false;//exit function
};
int main() {
	ifstream reader;
	string stringStorage;
	// int i, j;
	struct studentInfo *firstNode, *linkToNextNode, *addressOfNextNode, *searchNode; // create pointers to first and most recently created node , also a node that stores current search results

	reader.open("c:\\Users\\vusaj\\source\\repos\\JeriesAlgoHW4\\JeriesAlgoHW4\\linkListData.txt", ios::in);
	if (!reader.is_open()) {
		cout << "Unable to open file\n";
		exit(1);
	}

	firstNode = (struct studentInfo *)malloc(sizeof(struct studentInfo));
	getline(reader, stringStorage);
	strcpy_s(firstNode->name, stringStorage.c_str());
	//cout << "read name :" << stringStorage << endl;
	reader >> firstNode->age;
	reader.ignore();
	//cout << "read age :" << firstNode->age << endl;
	getline(reader, stringStorage);
	//cout << "read gender :" << stringStorage << endl;
	strcpy_s(firstNode->gender, stringStorage.c_str());
	getline(reader, stringStorage);
	//cout << "read major :" << stringStorage << endl;
	strcpy_s(firstNode->major, stringStorage.c_str());
	getline(reader, stringStorage);
	//cout << "read status :" << stringStorage << endl;
	strcpy_s(firstNode->status, stringStorage.c_str());
	firstNode->nextNode = NULL;

	linkToNextNode = firstNode;
	//system("pause");
	while (1) {

		getline(reader, stringStorage);
		//cout << "Str value is now: " << stringStorage << endl;
		if (reader.eof()) {
			break;
		}


		addressOfNextNode = (struct studentInfo *)malloc(sizeof(struct studentInfo));
		//cout << "read name :" << stringStorage << endl;

		strcpy_s(addressOfNextNode->name, stringStorage.c_str());
		reader >> addressOfNextNode->age;
		reader.ignore();
		//cout << "read age :" << addressOfNextNode->age << endl;
		getline(reader, stringStorage);
		//cout << "read gender :" << stringStorage << endl;
		strcpy_s(addressOfNextNode->gender, stringStorage.c_str());
		getline(reader, stringStorage);
		//cout << "read major :" << stringStorage << endl;
		strcpy_s(addressOfNextNode->major, stringStorage.c_str());
		getline(reader, stringStorage);
		//cout << "read status :" << stringStorage << endl;
		strcpy_s(addressOfNextNode->status, stringStorage.c_str());
		addressOfNextNode->nextNode = NULL;
		linkToNextNode->nextNode = addressOfNextNode;
		linkToNextNode = addressOfNextNode;
	
		//system("pause");
	}
	reader.close();

	string queryName;
	cout << "Welcome to Student Info!\n";
	cout << "Enter the name of the student who's information you would like to retrieve.\n";
	cin >> queryName;
	search(firstNode, queryName);

	cout << "\n\n";
	system("pause");

	return 0;
}*/
}
