/*
	Компилировать вот так
	g++ interp2.cpp -std=c++11
*/

#include<fstream>
#include<stdexcept>
#include<stack>
#include<map>
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

struct FunctionDefinition {
	vector<string> input_params;
	int begin_func_line_number;
};

struct StackFrame {
	std::map<string, string> variables;
	int parent_line_number;
};

std::map<string, FunctionDefinition> functions;
std::stack<StackFrame> call_stack;

enum eState {
	func_definition,
	running,
};

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
	try {
		eState state = running;

		for(int i = 0; i < code_lines.size(); i++) {
			istringstream stream(code_lines[i]);
			string current_operator;
			stream >> current_operator;
		
			if(current_operator == "def") {
				state = func_definition;

				string func_name;
				if (!(stream >> func_name))
					throw std::runtime_error("Не задано имя добавляемой функции");
				if (functions.find(func_name) != functions.end())
					throw std::runtime_error("Добавляемая функция уже задана");
				
				FunctionDefinition new_func;
				string param;
				while(stream >> param) {
					new_func.input_params.push_back(param);
				}

				new_func.begin_func_line_number = i;
				functions[func_name] = new_func;
			} else if (current_operator == "end") {
				if(state == running) {
					if(call_stack.empty()) {
						throw std::runtime_error("Пустой стек вызовов в момент выполнения");
					} else {
						i = call_stack.top().parent_line_number;
						call_stack.pop();
					}
				} else {
					state = running;
				}
			} else if (current_operator == "call") {
				if (state == running) {
                                	string func_name;
                                	if (!(stream >> func_name))
                                	        throw std::runtime_error("Не задано имя функции которую нужно вызвать");
                                	if (functions.find(func_name) == functions.end())
                                	        throw std::runtime_error("Не найдено  определение вызываемой функции");
					
					FunctionDefinition& cur_func_def = functions[func_name];
					StackFrame new_frame;
					for(int i = 0; i < cur_func_def.input_params.size(); i++) {
						string value;
						string param_name = cur_func_def.input_params[i];
						if (!(stream >> value)) {
							throw std::runtime_error("Не удается пробросить параметр " + 
							param_name + " при вызове функции " + func_name);
						}
						new_frame.variables[param_name] = value;
					}
					new_frame.parent_line_number = i;
					call_stack.push(new_frame);
					i = cur_func_def.begin_func_line_number;
					state = running;
				}	
			 } else if (current_operator == "print") {
				if(state == running) {
			 		string arg;
					for(int i = 0; stream >> arg; i++) {
						if (i != 0)
							cout << " ";
						auto vars = call_stack.top().variables;
						if(vars.find(arg) != vars.end()) {
							cout << vars[arg];
						} else {
							cout << arg;
						}
					}
					cout << endl;
				}
			 }
		}
	} catch(const std::runtime_error& e) {
		cerr << e.what() << endl;
		cerr << "Аварийное завершение интерпретатора" << endl;
	}
}
