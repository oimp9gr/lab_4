#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class MathematicalOperation {
public:
    MathematicalOperation(string file_) : file(file_) {
    }

    void Solve() {
        string row;
        vector<string> result_rows;
        ifs.open(file);
        while (getline(ifs, row)) {
            int result;
            stringstream ss(row);
            int lhs, rhs;
            char operation;
            ss >> lhs >> operation >> rhs;
            if (operation == '+') {
                result = lhs + rhs;
            } else if (operation == '-') {
                result = lhs - rhs;
            } else if (operation == '*') {
                result = lhs * rhs;
            }
            result_rows.push_back(row + " = " + to_string(result));
        }
        ifs.close();
        WriteResults(result_rows);
    }

    void WriteResults(const vector<string>& results) {
        ofs.open(file);
        for (const auto & row : results) {
            ofs << row << "\n";
        }
        ofs.close();
    }

private:
    string file;
    ifstream ifs;
    ofstream ofs;
};