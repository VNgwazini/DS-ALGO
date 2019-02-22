#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iomanip>
#include <unistd.h>
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
	strcpy(pfront->name, newName.c_str());
	pfront->age = newAge;
	strcpy(pfront->gender,newGender.c_str());
	strcpy(pfront->status,newStatus.c_str());
	strcpy(pfront->major,newMajor.c_str());
	pfront->nextNode = phead;
	return pfront;
};
int main() {
	ifstream reader;
	string stringStorage;
	// int i, j;
	// create pointers to first and most recently created node , also a node that stores current search results
	struct studentInfo *firstNode, *linkToNextNode, *addressOfNextNode, *searchNode; 

	reader.open("linkListData.txt", ios::in);
	if (!reader.is_open()) {
		cout << "Unable to open file\n";
		system("pause");
		exit(1);
	}

	firstNode = (struct studentInfo *)malloc(sizeof(struct studentInfo));
	getline(reader, stringStorage);
	strcpy(firstNode->name, stringStorage.c_str());
	//cout << "read name :" << stringStorage << endl;
	reader >> firstNode->age;
	reader.ignore();
	//cout << "read age :" << firstNode->age << endl;
	getline(reader, stringStorage);
	//cout << "read gender :" << stringStorage << endl;
	strcpy(firstNode->gender, stringStorage.c_str());
	getline(reader, stringStorage);
	//cout << "read major :" << stringStorage << endl;
	strcpy(firstNode->major, stringStorage.c_str());
	getline(reader, stringStorage);
	//cout << "read status :" << stringStorage << endl;
	strcpy(firstNode->status, stringStorage.c_str());
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

		strcpy(addressOfNextNode->name, stringStorage.c_str());
		reader >> addressOfNextNode->age;
		reader.ignore();
		//cout << "read age :" << addressOfNextNode->age << endl;
		getline(reader, stringStorage);
		//cout << "read gender :" << stringStorage << endl;
		strcpy(addressOfNextNode->gender, stringStorage.c_str());
		getline(reader, stringStorage);
		//cout << "read major :" << stringStorage << endl;
		strcpy(addressOfNextNode->major, stringStorage.c_str());
		getline(reader, stringStorage);
		//cout << "read status :" << stringStorage << endl;
		strcpy(addressOfNextNode->status, stringStorage.c_str());
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
