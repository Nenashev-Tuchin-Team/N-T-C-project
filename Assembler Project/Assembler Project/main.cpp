#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
#define RAM_SIZE 1048576
#define REGISTRS_QUANTITY 16
#define COMMAND_QUANTITY 53

vector<int> RAM(RAM_SIZE);
vector<int> r(REGISTRS_QUANTITY);
stack <int> stack_;
int flags;

typedef struct Command
{
	int id;
	string name;
	string type;
} command;

vector<command> commands({
	{0, "halt", "RI"}, { 1, "syscall", "RI" }, 
	{ 2, "add", "RR"}, { 3, "addi", "RI" },
	{ 4, "sub", "RR" },{ 5, "subi", "RI" },
	{ 6, "mul", "RR" }, { 7, "muli", "RI" },
	{ 8, "div", "RR" }, { 9, "divi", "RI" },
	{ 12, "lc", "RI" }, { 13, "shl", "RR" }, 
	{ 14, "shli", "RI" }, { 15, "shr", "RR" },
	{ 16, "shri", "RI" },{ 17, "and", "RR" }, 
	{ 18, "andi", "RI" },{ 19, "or" , "RR" },
	{ 20, "ori", "RI" }, { 21, "xor", "RR" }, 
	{ 22, "xori", "RI" },{ 23, "not", "RI" }, 
	{ 24, "mov", "RR" },{ 32, "addd", "RR" }, 
	{ 33, "subd", "RR" }, { 34, "muld", "RR" },
	{ 35, "divd", "RR" }, { 36, "itod", "RR" },
	{ 37, "dtoi", "RR" }, { 38, "push", "RI" }, 
	{ 39, "pop", "RI" }, { 40, "call", "RR" },
	{ 41, "calli", "J" }, { 42, "ret", "RI" },
	{ 43, "cmp", "RR" }, { 44, "cmpi", "RI" },
	{ 45, "cmpd", "RR" }, { 46, "jmp", "J" }, 
	{ 47, "jne", "J" }, { 48, "jeq", "J" },
	{ 49, "jle", "J" }, { 50, "jl", "J" },
	{ 51, "jge", "J" }, { 52, "jg", "J" },
	{ 64, "load", "RM" }, { 65, "store", "RM" }, 
	{ 66, "load2", "RM" }, { 67, "store2", "RM" },
	{ 68, "loadr", "RR" }, { 69, "storer", "RR" },
	{ 70, "loadr2", "RR" }, { 71, "storer2", "RR" }
	});


void syscall(int code, int reg, int i, float f, char c)
{
	if (code == 100)
	{
		int a1 = 0;
		cin >> a1;
		r[reg] = a1;
	}
	if (code == 102)
	{
		cout << r[reg] << endl;
	}
	return;
}

void addi(int reg, int imm)
{
	r[reg] += imm;
	return;
}
int main()
{
	vector<string> prog;
	string str;
	string registr;
	string num;
	getline(cin, str, '\n');
	while (str != "end") {
		prog.push_back(str);
		getline(cin, str, '\n');
	}
	prog.push_back(str);
	//for (int i = 0; i < prog.size(); i++)
	//	cout << prog[i] << endl;
	str = "\0";
	for (int i = 0; i < prog.size(); i++)
	{
		int j = 0;
		for (j; j < prog[i].length(); j++) {
			if (prog[i][j] == ' ') {
				j++;
				break;
			}
			str.push_back(prog[i][j]);
		}
		for (j; j < prog[i].length(); j++) {
			if (prog[i][j] == ' ') {
				j++;
				break;
			}
			registr.push_back(prog[i][j]);
		}
		for (j; j < prog[i].length(); j++) {
			if (prog[i][j] == ' ') {
				j++;
				break;
			}
			num.push_back(prog[i][j]);
		}
		int id = 0;
		int numb = atoi(num.c_str());
		int reg_ = 0;
		if (registr.length() == 2)
			reg_ = registr[1] - '0';
		for (int k = 0; k < commands.size(); k++)
		{
			if (commands[k].name == str)
			{
				id = commands[k].id;
				break;
			}
		}
		//cout << id << " " << reg_ << " " << num << endl;
		switch (id)
		{
		case 1: syscall(numb, reg_, 0, 0, 0); break;
		case 3: addi(reg_, numb); break;
		}
		str = "\0";
		num = "\0";
		registr = "\0";
	}
	return 0;
}
/*
syscall r0 100
addi r0 1
syscall r0 102
end
*/
