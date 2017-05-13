#include<fstream>
#include<vector>
#include<iostream>
#include<sstream>
using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
using std::getline;
using std::istringstream;

int main(int argc, char*argv[]) {
	if(argc < 2) {
		cerr << "Введите имя файла с инструкциями" << endl;
	}
	ifstream inf(argv[1]);
	string code_line;
	vector<string> code_lines;
	while (getline(inf, code_line))
	{
   		code_lines.push_back(code_line);
	}
	
	for(int i = 0; i < code_lines.size(); i++) {
		istringstream stream(code_lines[i]);
		string current_operator;
		stream >> current_operator;
		if(current_operator == "+") {
			string first_oper;
			string second_oper;
			stream >> first_oper >> second_oper;
			cout << "Производится сложение " << first_oper << " " << second_oper << endl;
		}
	}
}
