#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;
int main() {
    ofstream outFile("numbers.txt");
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }
    for (int i = 1; i <= 20; i++) {
        double squareRoot = sqrt(i);
        outFile << i << " " << squareRoot << endl;
    }
    outFile.close();
	int numToSearch;
	cout << "撒比: ";
	cin >> numToSearch;
	ifstream inFile("numbers.txt");
    if (!inFile) {
    	cerr << "Error opening file for reading." << endl;
        return 1;
    }
    bool found = false;
	string line;
    while (getline(inFile, line)) {
        int num;
        double squareRoot;
        istringstream iss(line);
        iss >> num >> squareRoot;
        if (num == numToSearch) {
            cout << numToSearch << "的平方根是" << squareRoot << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "The number you entered was not found in the file." << endl;
    inFile.close();
    return 0;
}

