//map data structure used to store and search phonebook.
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <string>

using namespace std;

int main() {
  int numOfEntires, number;
  string name;

  // create empty map
  map<string, int> phoneBook;
  // set number of entires
  cout << "Enter the number of entires: "<<endl;
  cin >> numOfEntires;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  // cout << numOfEntires << endl;
  // enter each persont to the phonebook
  for (int i = 0; i < numOfEntires; i++) {
    cout << "Enter a name: "<<endl;
    cin >> name;
    cout << "Enter a number: "<<endl;
    cin >> number;
    // cout << name << " " << number <<endl;
    phoneBook.insert(pair<string, int>(name, number));
  }
  // create iterator to traverse map with
  map<string, int>::iterator it;
  for (it = phoneBook.begin(); it != phoneBook.end(); it++) {
    string key;
    cout << "Enter a name to search: "<<endl;
    cin >> key;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (key == "")
      break;
    else {
      // use iterator to search map for key
      it = phoneBook.find(key);
      // if iterator reach end of map, then we didnt find the key
      if (it != phoneBook.end()) {
        cout << it->first << "=" << it->second << endl;
      }
      // else, print out the pair (name, number)
      else cout << "Not found" << endl;
        
      // break;
    }
  }

  return 0;
}
