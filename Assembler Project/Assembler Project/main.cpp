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

vector<command> commands({ {0, "halt", "RI"}, { 1, "syscall", "RI" }, { 2, "add", "RR"}, { 3, "addi", "RI" }, { 4, "sub", "RR" },
	{ 5, "subi", "RI" }, { 6, "mul", "RR" }, { 7, "muli", "RI" }, { 8, "div", "RR" }, { 9, "divi", "RI" },
	{ 12, "lc", "RI" }, { 13, "shl", "RR" }, { 14, "shli", "RI" }, { 15, "shr", "RR" }, { 16, "shri", "RI" },
	{ 17, "and", "RR" }, { 18, "andi", "RI" }, { 19, "or" , "RR" },
	{ 20, "ori", "RI" }, { 21, "xor", "RR" }, { 22, "xori", "RI" }, { 23, "not", "RI" }, { 24, "mov", "RR" },
	{ 32, "addd", "RR" }, { 33, "subd", "RR" }, { 34, "muld", "RR" },
	{ 35, "divd", "RR" }, { 36, "itod", "RR" }, { 37, "dtoi", "RR" }, { 38, "push", "RI" }, { 39, "pop", "RI" },
	{ 40, "call", "RR" }, { 41, "calli", "J" }, { 42, "ret", "RI" }, { 43, "cmp", "RR" }, { 44, "cmpi", "RI" },
	{ 45, "cmpd", "RR" }, { 46, "jmp", "J" }, { 47, "jne", "J" }, { 48, "jeq", "J" }, { 49, "jle", "J" },
	{ 50, "jl", "J" }, { 51, "jge", "J" }, { 52, "jg", "J" },
	{ 64, "load", "RM" }, { 65, "store", "RM" }, { 66, "load2", "RM" }, { 67, "store2", "RM" },
	{ 68, "loadr", "RR" }, { 69, "storer", "RR" },
	{ 70, "loadr2", "RR" }, { 71, "storer2", "RR" }
	});

int main()
{
	for (int i = 0; i != commands.size(); i++)
	{
		cout << commands[i].id << " " << commands[i].name << " " << commands[i].type << endl;
	}
	return 0;
}
