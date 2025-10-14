#include <iostream>
#include <fstream>
using namespace std;

class Inventory {
private:
    string name;
    int id;
    int quantity;
    float price;

public:
    void accept() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Enter price: ";
        cin >> price;
    }

    void writeToFile(ofstream &MyFile) {
        MyFile << name << " " << id << " " << quantity << " " << price << endl;
    }

    void readFromFile(ifstream &MyFile) {
        // Read a record from file
        MyFile >> name >> id >> quantity >> price;
    }

    void display() {
        cout << "Name: " << name << "\nID: " << id
             << "\nQuantity: " << quantity << "\nPrice: " << price << endl;
        cout << "--------------------------\n";
    }

    bool endOfFile(ifstream &MyFile) {
        return MyFile.eof();  // check if file has reached EOF
    }
};

int main() {
    int n;
    cout << "Enter number of inventory items: ";
    cin >> n;

    Inventory* inv = new Inventory[n];

    // ----------------- WRITE TO FILE -----------------
    ofstream MyFile("sample.txt");
    if (!MyFile) {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }

    cout << "\nEnter details of " << n << " inventory items:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nItem " << i + 1 << ":\n";
        inv[i].accept();
        inv[i].writeToFile(MyFile);
    }
    MyFile.close();
    cout << "\nData written successfully to 'sample.txt'\n";

    // ----------------- READ FROM FILE -----------------
    ifstream inFile("sample.txt");
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        delete[] inv;
        return 1;
    }

    cout << "\nReading data from file:\n";
    Inventory temp;
    while (!inFile.eof()) {
        temp.readFromFile(inFile);
        if (!inFile.eof()) temp.display();  // only display valid data
    }
    inFile.close();

    delete[] inv;
    return 0;
}
