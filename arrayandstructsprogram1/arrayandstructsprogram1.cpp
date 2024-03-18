#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int numr = 5;
const int numd = 7;


void readDataFromFile(string filename, string runners[], int miles[][numd]);
void calculateStats(const string runners[], const int miles[][numd], int total[], double average[]);
void displayResults(const string runners[], const int miles[][numd], const int total[], const double average[]);

int main() {
    string runners[numr];
    int miles[numr][numd];
    int total[numr] = { 0 };
    double average[numr] = { 0 };

    readDataFromFile("runners.txt", runners, miles);
    calculateStats(runners, miles, total, average);
    displayResults(runners, miles, total, average);

    return 0;
}

void readDataFromFile(string filename, string runners[], int miles[][numd]) {
    ifstream inputFile(filename);
    for (int i = 0; i < numr; ++i) {
        inputFile >> runners[i];
        for (int j = 0; j < numd; ++j) {
            inputFile >> miles[i][j];
        }
    }

    inputFile.close();
}

void calculateStats(const string runners[], const int miles[][numd], int total[], double average[]) {
    for (int i = 0; i < numr; ++i) {
        total[i] = 0;
        for (int j = 0; j < numd; ++j) {
            total[i] += miles[i][j];
        }
        average[i] = static_cast<double>(total[i]) / numd;
    }
}

void displayResults(const string runners[], const int miles[][numd], const int total[], const double average[]) {
    cout << setw(10) << "Runner" << setw(10) << "Mon" << setw(10) << "Tue" << setw(10) << "Wed"
        << setw(10) << "Thu" << setw(10) << "Fri" << setw(10) << "Sat" << setw(10) << "Sun"
        << setw(15) << "Total" << setw(15) << "Average" << endl;

    for (int i = 0; i < numr; ++i) {
        cout << setw(10) << runners[i];
        for (int j = 0; j < numd; ++j) {
            cout << setw(10) << miles[i][j];
        }
        cout << setw(15) << total[i] << setw(15) << fixed << setprecision(2) << average[i] << endl;
    }
}