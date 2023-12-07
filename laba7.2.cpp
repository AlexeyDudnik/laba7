#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
struct Book
{
    string Author;
    string Title;
    int Year;
};
void saveToFile(const string& file, const vector<Book>& data) {
	ofstream file_out("file.txt");
	for (auto f : data) {
		file_out << f.Author<<" ";
		file_out << f.Title<<" ";
		file_out << f.Year<<endl;
	}
	file_out.close();
}
void loadFromFile(const string& file, vector<Book>& outData) {
	ifstream filename("file.txt");
	string str;
	while (getline(filename, str)) {
		Book book1;
		istringstream ss(str);
		string str;
		getline(ss, str, ' ');
		book1.Author = str;
		getline(ss, str, ' ');
		book1.Title = str;
		getline(ss, str, ' ');
		int k = stoi(str);
		book1.Year = k;
		outData.push_back(book1);
	}
}
int main()
{
	Book Author1;
	Author1.Author = "NePridumal(";
	Book Author2;
	Author2.Author = "Ya";
	Book Author3;
	Author3.Author = "Da";
	Author1.Title = "Kto";
	Author2.Title = "Ti";
	Author3.Title = "Net";
	Author1.Year = 2023;
	Author2.Year = 2022;
	Author3.Year = 2021;
	string f = "file";
	vector<Book> str1;
	str1.push_back(Author1);
	str1.push_back(Author2);
	str1.push_back(Author3);
	saveToFile(f, str1);
	vector<Book> v;
	loadFromFile(f, v);
	for (auto f : v) {
		cout << f.Author << " " << f.Title << " " << f.Year << endl;
	}

	
}