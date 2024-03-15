#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class StringProcessor {
private:
    vector<string> lines;

public:
    // Phuong thuc de doc du lieu tu file va luu vao vector lines
    void readFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                lines.push_back(line);
            }
            file.close();
        }
        else {
            cout << "can not open file!" << endl;
        }
    }
    // Phuong thuc de in ra so dong va cac dong bat dau bang '-'
    void printLines() {
        cout << "Tong so dong: " << lines.size() << endl;
        cout << "Cac dong bat dau bang '-':" << endl;
        for (const auto& line : lines) {
            if (line.compare(0, 1, "-") == 0) {
                cout << line << endl;
            }
        }
    }
};

int main1() {
    cout << "054205001151_HoVanDuy" << endl;
    StringProcessor processor;
    processor.readFromFile("data.txt");
    processor.printLines();
    return 0;
}
