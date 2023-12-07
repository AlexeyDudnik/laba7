#include <iostream>
#include <fstream> 
#include <vector>
#include <string>
using namespace std;
void saveToFile(const string& file, const vector<string>& data) {
	ofstream file_out("file.txt");
	for (string f : data) {
		file_out << f;
	}
	file_out.close();
}
void loadFromFile(const string& file, vector<string>& outData) {
	ifstream filename("file.txt");
	string str;
	while (getline(filename, str)) { 
		outData.push_back(str);  
		cout << str << endl;  
	}
}
int main()
{
	string f = "file";
	vector<string> str1{ "Kto ", "Ya ", "Takoi" };
	vector<string> str2;
	saveToFile(f, str1);
	loadFromFile(f, str2);
}