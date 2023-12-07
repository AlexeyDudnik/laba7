#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
using namespace std;
enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent,
    
};
struct Student
{
    string Name;
    int Year;
    map<string, Score> RecordBook;
};
using Groups = map<string, vector<Student>>;
void saveToFile(const string& file, const Groups& g) {
    ofstream file_out("file.txt");
    for (auto f: g.at("IU8")) {
        file_out << f.Name<<" ";
        file_out << f.Year<<" ";
        file_out << f.RecordBook.at("Analgeom")<<endl;

    }
    file_out.close();
}
void loadFromFile(const string& file, Groups& outGroups) {
    ifstream filename("file.txt");
    string str;
    vector<Student> v;
    while (getline(filename, str)) {
        Student s1;
        istringstream ss(str);
        string str;
        getline(ss, str, ' ');
        s1.Name = str;
        getline(ss, str, ' ');
        int k = stoi(str);
        s1.Year = k;
        getline(ss, str, ' ');
        s1.RecordBook["Analgeom"] = static_cast<Score>(std::stoi(str));
        v.push_back(s1);
        
    }
    outGroups["IU8"] = v;
}

int main()
{
    string f = "file";
    Groups g1;
    Groups g2;
    Student s1;
    Student s2;
    Student s3;
    Student s4;
    s1.Name = "Slava";
    s2.Name = "Vanya";
    s3.Name = "Maksim";
    s4.Name = "Zhenya";
    s1.Year = 4;
    s2.Year = 34;
    s3.Year = 19;
    s4.Year = 18;
    s1.RecordBook ["Analgeom"] = Unsatisfactorily;
    s2.RecordBook ["Analgeom"] = Satisfactorily;
    s3.RecordBook["Analgeom"] = Good;
    s4.RecordBook["Analgeom"] = Excellent;
    vector<Student> v1;
    v1.push_back(s1);
    v1.push_back(s2);
    v1.push_back(s3);
    v1.push_back(s4);
    g1["IU8"] = v1;
    saveToFile(f, g1);
    loadFromFile(f, g2);
    for (auto f : g2.at("IU8")) {
        cout << f.Name << " ";
        cout << f.Year << " ";
        cout << f.RecordBook.at("Analgeom") << endl;
    }
}