#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void createFiles(int num_files) {
    for (int i = 1; i <= num_files; i++) {
        string filename = "file" + to_string(i) + ".txt";
        ofstream file(filename);
        file << "Содержимое файла " << i;
        file.close();
    }
}

string readFile(string filename) {
    ifstream file_in(filename);
    string file_data((istreambuf_iterator<char>(file_in)), istreambuf_iterator<char>());
    file_in.close();
    return file_data;
}

void writeFile(string filename, string file_data) {
    ofstream file_out(filename);
    file_out << file_data;
    file_out.close();
}

void swapFiles(int file1, int file2) {
    string filename1 = "file" + to_string(file1) + ".txt";
    string filename2 = "file" + to_string(file2) + ".txt";

    string file_data1 = readFile(filename1);
    string file_data2 = readFile(filename2);

    writeFile(filename2, file_data1);
    writeFile(filename1, file_data2);

    cout << "Completed! " << file1 << " и " << file2 << endl;
}

int main() {
    int num_files;
    cout << "how meny file create ";
    cin >> num_files;
    createFiles(num_files);

    int file1, file2;
    cout << "Input number file first: ";
    cin >> file1;
    cout << "Input number file second: ";
    cin >> file2;
    swapFiles(file1, file2);

}
