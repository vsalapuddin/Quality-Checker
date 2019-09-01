#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <iomanip>
#include <vector>
using namespace std; 

struct Info { 
    string address;
    string city;
    string county;
    string zipcode;

    //constructor
    Info(string _address, string _city, string _county, string _zipcode) {
        address = _address;
        city = _city;
        county = _county; 
        zipcode = _zipcode;
    }
};
//prototypes
void loadAFile(string filename, vector<Info>& fileInfo);
void searchDuplicates (vector<Info>& fileInfo);

//main function
int main() {
    cout << std::fixed << setprecision(2);
    cout << "Which file would you like to quality check? ";
    string option;
    cin >> option;
    vector<Info> fileInfo;

    (loadAFile(option, fileInfo));

    cout << endl;
    cout << "What would you like to do with the file?" << endl;
    cout << "1. Check for duplicate addresses" << endl;
    cout << "2. Placeholder" << endl; 
 
    int choice;
    cin >> choice;
    cin.get();

    switch (choice) {
        case 1:
        searchDuplicates(fileInfo);
        break;
        case 2: 
        cout << "Hello" << endl;
        break;
    }
    

}
void loadAFile(string filename, vector<Info>& fileInfo) {
ifstream inFile(filename);
string lineFromFile;
//To buffer out column names
getline(inFile, lineFromFile);

while (getline(inFile, lineFromFile)) {
    istringstream stream(lineFromFile);
    string _address;
    string _city;
    string _county;
    string _zipcode; 

    getline(stream, _address, '|');
    getline(stream, _city, '|');
    getline(stream, _county, '|');
    getline(stream, _zipcode);

    Info information (_address, _city, _county, _zipcode);
    fileInfo.push_back(information);
}
}
void searchDuplicates (vector<Info>& fileInfo) {
    int count = 0;
    for (unsigned int i = 0; i < fileInfo.size(); i++) {
        
        for (unsigned int j = 0; j < fileInfo.size(); j++) {
            if (fileInfo[i].address == fileInfo[j].address) {
                cout << "Duplicate found: " << fileInfo[j].address;
                count++;
            }
            else if (fileInfo[i].address != fileInfo[j].address) {
                j++;
                continue;
            }
        }
        
    }
    if (count == 0) {
        cout << "No duplicates found" << endl;
    }
    else if (count > 0) {
        cout << count << " duplicates were found." << endl;
    }
}
