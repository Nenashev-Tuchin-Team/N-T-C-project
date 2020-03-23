#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <stack>
#include <fstream>
#include <bitset>
#include <climits>
using namespace std;
#define RAM_SIZE 1048576
#define REGISTRS_QUANTITY 16
#define COMMAND_QUANTITY 53
ifstream fin("input.txt");
ofstream fout("output.txt");
//#define cin fin
//#define cout fout

vector <unsigned> RAM(RAM_SIZE);
vector <unsigned> r(REGISTRS_QUANTITY);
map <string, unsigned> marks;
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
	{ 39, "pop", "RI" }, { 40, "call", "RR+" },
	{ 41, "calli", "J" }, { 42, "ret", "J+" },
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

void separator1(string str, int n) {
	string s;
	for (int i = 0; i < int(str.size()); i++) {
		if (str[i] != ':') {
			s.push_back(str[i]);
		}
		else {
			s.clear();
		}
	}
	return;
}

vector<string> separator2(string str) {
	string s;
	vector<string> ss;
	for (int i = 0; i < int(str.size()); i++) {
		if (str[i] == ' ' || str[i] == '\t') {
			continue;
		}
		while (i < int(str.size()) && str[i] != ' ' && str[i] != '\t') {
			s.push_back(str[i]);
			i++;
		}
		ss.push_back(s);
		s.clear();
	}
	return ss;
}

void cout_prog(vector<vector<string>> prog) {
	for (int i = 0; i < int(prog.size()); i++) {
		fout << i << ") ";
		for (int j = 0; j < int(prog[i].size()); j++) {
			fout << prog[i][j] << " ";
		}
		fout << endl;
	}
}

void cout_prog2(vector<unsigned> prog) {
	for (int i = 0; i < int(prog.size()); i++) {
		unsigned num = prog[i];
		cout << i << "  ";
		for (int j = 31; j >= 24; --j) {
			cout << ((num >> j) & 1);
		}
		cout << " ";
		for (int j = 23; j >= 16; --j) {
			cout << ((num >> j) & 1);
		}
		cout << " ";
		for (int j = 15; j >= 8; --j) {
			cout << ((num >> j) & 1);
		}
		for (int j = 7; j >= 0; --j) {
			cout << ((num >> j	) & 1);
		}
		cout << endl;
	}
}

command find_com(string name) {
	for (int i = 0; i < int(commands.size()); i++) {
		if (commands[i].name == name) {
			return commands[i];
		}
	}
	return { -1, "NULL", "NULL" };
}

void syscall(unsigned x) {
	unsigned reg = (x >> 20) & (0b1111);
	int operand = x & (0b11111111111111111111);
	switch (operand){
	case 0: exit(0); break;
	case 100: int a; cin >> a; r[reg] = a | 0; break;
	case 102: cout << int(r[reg]); break;
	case 104: cin >> r[reg]; break;
	case 105: cout << char(r[reg]); break;
	}
	if (operand == 103) {
		double d1;
		long long di1 = r[reg + 1]; di1 = (di1 << 32) | r[reg];
		d1 = *(double*)(&di1); 
		printf("%lg", d1);
	}
	if (operand == 101) {
		double d; 
		cin >> d;
		long long di = *(long long*)(&d);
		r[reg] = di & (0b11111111111111111111111111111111);
		r[reg + 1] = (di >> 32) & (0b11111111111111111111111111111111);
	}
	return;
}

void lc(unsigned x) {
	unsigned reg = (x >> 20) & (0b1111);
	unsigned operand = x & (0b11111111111111111111);
	r[reg] = operand;
	return;
}

void cmpi(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	int operand = x & (0b11111111111111111111);
	flags = -(operand - int(r[reg1]));
	return;
}

void cmp(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	int operand = x & (0b1111111111111111);
	flags = int(r[reg1]) - (int(r[reg2]) + operand);
	return;
}

void jg(unsigned x, int &i) {
	unsigned operand = x & (0b11111111111111111111);
	if (flags > 0) {
		i = operand;
		i--;
	}
	else {
		return;
	}
}

void jge(unsigned x, int& i) {
	unsigned operand = x & (0b11111111111111111111);
	if (flags >= 0) {
		i = operand;
		i--;
	}
	else {
		return;
	}
}

void jne(unsigned x, int& i) {
	unsigned operand = x & (0b11111111111111111111);
	if (flags != 0) {
		i = operand;
		i--;
	}
	else {
		return;
	}
}

void jmp(unsigned x, int& i) {
	unsigned operand = x & (0b11111111111111111111);
	i = operand;
	i--;
	return;
}

void jeq(unsigned x, int& i) {
	unsigned operand = x & (0b11111111111111111111);
	if (flags == 0) {
		i = operand;
		i--;
	}
	else {
		return;
	}
}

void jle(unsigned x, int& i) {
	unsigned operand = x & (0b11111111111111111111);
	if (flags <= 0) {
		i = operand;
		i--;
	}
	else {
		return;
	}
}

void jl(unsigned x, int& i) {
	unsigned operand = x & (0b11111111111111111111);
	if (flags < 0) {
		i = operand;
		i--;
	}
	else {
		return;
	}
}

void ret(unsigned x, int& i) {
	int adress = RAM[r[14]];
	int operand = x & (0b11111111111111111111);
	r[14] += operand + 1;
	i = adress;
	i--;
	//cout << "ret: " << i << " " << operand << endl;
	return;
}

void push(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	int operand = x & (0b11111111111111111111);
	//cout << "push " << reg1 << ' ' << operand << endl;
	r[14]--;
	RAM[r[14]] = r[reg1] + operand;
	return;
}

void pop(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	int operand = x & (0b11111111111111111111);
	r[reg1] = RAM[r[14]] + operand;
	r[14]++;
	//cout << "pop " << reg1 << " " << operand << endl;
	return;
}

void subi(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	int operand = x & (0b11111111111111111111);
	r[reg1] -= operand;
	//cout << "subi " << reg1 << " " << operand << endl;
	return;
}

void sub(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	int operand = x & (0b1111111111111111);
	int r2 = r[reg2] + operand;
	r[reg1] = int(r[reg1]) - r2;
	return;
}

void calli(unsigned x, int &i) {
	unsigned operand = x & (0b11111111111111111111);
	r[14]--;
	RAM[r[14]] = i + 1;
	i = operand;
	i--;
	return;
}

void call(unsigned x, int& i) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	int operand = x & (0b1111111111111111);
	r[14]--;
	RAM[r[14]] = i + 1;
	i = r[reg2];
	r[reg1] = i;
	i--;
	return;
}

void mul(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	long long operand = x & (0b1111111111111111);
	long long r1 = r[reg1];
	long long r2 = r[reg2] + operand;
	long long a = r1 * r2;
	r[reg1] = a & (0b11111111111111111111111111111111);
	r[reg1 + 1] = (a >> 32) & (0b11111111111111111111111111111111);
	return;
}

void mov(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	int operand = x & (0b1111111111111111);
	int r2 = r[reg2] + operand;
	r[reg1] = r2;
	return;
}

void add(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	int operand = x & (0b1111111111111111);
	int r2 = r[reg2] + operand;
	r[reg1] = int(r[reg1]) + r2;
	return;
}

void addi(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	int operand = x & (0b11111111111111111111);
	r[reg1] = int(r[reg1]) + operand;
	return;
}

void muli(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	long long operand = x & (0b11111111111111111111);
	long long r1 = r[reg1];
	long long res = r1 * operand;
	r[reg1] = res & (0b11111111111111111111111111111111);
	r[reg1 + 1] = (res >> 32) & (0b11111111111111111111111111111111);
	return;
}

void div(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	long long operand = x & (0b1111111111111111);
	long long r1 = r[reg1 + 1];
	r1 = (r1 << 32);
	r1 = r1 | r[reg1];
	long long r2 = r[reg2] + operand;
	long long res1 = r1 / r2;
	long long res2 = r1 % r2;
	r[reg1] = unsigned(res1);
	r[reg1 + 1] = unsigned(res2);
	return;
}

void divi(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	long long operand = x & (0b11111111111111111111);
	long long r1 = r[reg1 + 1];
	r1 = (r1 << 32);
	r1 = r1 | r[reg1];
	long long r2 = operand;
	long long res1 = r1 / r2;
	long long res2 = r1 % r2;
	r[reg1] = unsigned(res1);
	r[reg1 + 1] = unsigned(res2);
	return;
}

void shl(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	int operand = x & (0b1111111111111111);
	unsigned r2 = r[reg2] + operand;
	unsigned r1 = r[reg1];
	r1 = (r1 << r2);
	r[reg1] = r1;
	return;
}

void shli(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned operand = x & (0b11111111111111111111);
	r[reg1] = r[reg1] << operand;
	return;
}

void shr(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	int operand = x & (0b1111111111111111);
	unsigned r2 = r[reg2] + operand;
	unsigned r1 = r[reg1];
	r1 = (r1 >> r2);
	r[reg1] = r1;
	return;
}

void shri(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned operand = x & (0b11111111111111111111);
	r[reg1] = r[reg1] >> operand;
	return;
}

void and_(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	int operand = x & (0b1111111111111111);
	unsigned r2 = r[reg2] + operand;
	unsigned r1 = r[reg1];
	r1 = (r1 & r2);
	r[reg1] = r1;
	return;
}

void andi(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned operand = x & (0b11111111111111111111);
	r[reg1] = r[reg1] & operand;
	return;
}

void or_(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	int operand = x & (0b1111111111111111);
	unsigned r2 = r[reg2] + operand;
	unsigned r1 = r[reg1];
	r1 = (r1 | r2);
	r[reg1] = r1;
	return;
}

void ori(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned operand = x & (0b11111111111111111111);
	r[reg1] = r[reg1] | operand;
	return;
}

void xor_(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	int operand = x & (0b1111111111111111);
	unsigned r2 = r[reg2] + operand;
	unsigned r1 = r[reg1];
	r1 = (r1 ^ r2);
	r[reg1] = r1;
	return;
}

void xori(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned operand = x & (0b11111111111111111111);
	r[reg1] = r[reg1] ^ operand;
	return;
}

void not_(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned operand = x & (0b11111111111111111111);
	r[reg1] = ~r[reg1];
	return;
}

void load(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned operand = x & (0b11111111111111111111);
	r[reg1] = RAM[operand];
	return;
}

void loadr(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	int operand = x & (0b1111111111111111);
	r[reg1] = unsigned(RAM[(int(r[reg2]) + operand) % RAM_SIZE]);
	return;
}

void load2(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned operand = x & (0b11111111111111111111);
	r[reg1] = RAM[operand];
	r[reg1 + 1] = RAM[operand + 1];
	return;
}

void loadr2(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	int operand = x & (0b1111111111111111);
	r[reg1] = unsigned(RAM[(int(r[reg2]) + operand) % RAM_SIZE]);
	r[reg1 + 1] = unsigned(RAM[(int(r[reg2]) + operand + 1) % RAM_SIZE]);
	return;
}

void store(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned operand = x & (0b11111111111111111111);
	RAM[operand] = r[reg1];
	return;
	return;
}

void store2(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned operand = x & (0b11111111111111111111);
	RAM[operand] = r[reg1];
	RAM[operand + 1] = r[reg1 + 1];
	return;
}

void storer(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	int operand = x & (0b1111111111111111);
	RAM[(int(r[reg2]) + operand) % RAM_SIZE] = r[reg1];
	return;
}

void storer2(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	int operand = x & (0b1111111111111111);
	RAM[(int(r[reg2]) + operand) % RAM_SIZE] = r[reg1];
	RAM[(int(r[reg2]) + operand + 1) % RAM_SIZE] = r[reg1 + 1];
	return;
}

void addd(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	double operand = x & (0b1111111111111111);
	long long r1 = 0 | r[reg1 + 1];
	r1 = (r1 << 32);
	r1 = r1 | r[reg1];
	double d1 = *(double*)(&r1);
	long long r2 = 0 | r[reg2 + 1];
	r2 = (r2 << 32);
	r2 = r2 | r[reg2];
	double d2 = *(double*)(&r2);
	double res = d1 + d2 + operand;
	long long resb = *(long long*)(&res);
	r[reg1] = resb & (0b11111111111111111111111111111111);
	r[reg1 + 1] = (resb >> 32) & (0b11111111111111111111111111111111);
	return;
}

void subd(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	double operand = x & (0b1111111111111111);
	long long r1 = 0 | r[reg1 + 1];
	r1 = (r1 << 32);
	r1 = r1 | r[reg1];
	double d1 = *(double*)(&r1);
	long long r2 = 0 | r[reg2 + 1];
	r2 = (r2 << 32);
	r2 = r2 | r[reg2];
	double d2 = *(double*)(&r2);
	double res = d1 - (d2 + operand);
	long long resb = *(long long*)(&res);
	r[reg1] = resb & (0b11111111111111111111111111111111);
	r[reg1 + 1] = (resb >> 32) & (0b11111111111111111111111111111111);
	return;
}

void muld(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	double operand = x & (0b1111111111111111);
	long long r1 = 0 | r[reg1 + 1];
	r1 = (r1 << 32);
	r1 = r1 | r[reg1];
	double d1 = *(double*)(&r1);
	long long r2 = 0 | r[reg2 + 1];
	r2 = (r2 << 32);
	r2 = r2 | r[reg2];
	double d2 = *(double*)(&r2);
	double res = d1 * (d2 + operand);
	long long resb = *(long long*)(&res);
	r[reg1] = resb & (0b11111111111111111111111111111111);
	r[reg1 + 1] = (resb >> 32) & (0b11111111111111111111111111111111);
	return;
}

void divd(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	double operand = x & (0b1111111111111111);
	long long r1 = 0 | r[reg1 + 1];
	r1 = (r1 << 32);
	r1 = r1 | r[reg1];
	double d1 = *(double*)(&r1);
	long long r2 = 0 | r[reg2 + 1];
	r2 = (r2 << 32);
	r2 = r2 | r[reg2];
	double d2 = *(double*)(&r2);
	double res = d1 / (d2 + operand);
	long long resb = *(long long*)(&res);
	r[reg1] = resb & (0b11111111111111111111111111111111);
	r[reg1 + 1] = (resb >> 32) & (0b11111111111111111111111111111111);
	return;

}

void itod(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	long long operand = x & (0b1111111111111111);
	long long r2 = r[reg2];
	r2 = r2 + operand;
	double rd2 = r2;
	long long resd = *(long long*)(&rd2);
	r[reg1] = resd & (0b11111111111111111111111111111111);
	r[reg1 + 1] = (resd >> 32) & (0b11111111111111111111111111111111);
	return;
}

void dtoi(unsigned x) {
	unsigned reg1 = (x >> 20) & (0b1111);
	unsigned reg2 = (x >> 16) & (0b1111);
	double operand = x & (0b1111111111111111);
	long long r1 = 0 | r[reg2 + 1];
	r1 = (r1 << 32);
	r1 = r1 | r[reg2];
	double d2 = *(double*)(&r1);
	long long res = (long long)(d2);
	r[reg1] = res & (0b11111111111111111111111111111111);
	r[reg1 + 1] = (res >> 32) & (0b11111111111111111111111111111111);
	return;
}
int main()
{
	vector<vector<string>> prog;
	string str;
	int word_count = 0;
	////Ввод
	unsigned string_num = 0;
	while (int(str.find("end")) == -1) {
		getline(cin, str, '\n');
		if (int(str.find("word")) != -1) {
			word_count++;
			continue;
		}
		if (int(str.find(';')) != -1) {
			continue;
		}
		if (int(str.find(":")) != -1) {
			separator1(str, string_num);
			vector<string> sss = separator2(str);
			sss[0].pop_back();
			marks.insert(make_pair(sss[0], string_num));
			sss.erase(sss.begin());
			if (!sss.empty()) {
				prog.push_back(sss);
				string_num++;
			}
			continue;
		}
		prog.push_back(separator2(str));
		string_num++;
	}
	r[14] = RAM_SIZE - 1;
	r[15] = marks[prog[prog.size() - 1].back()];
	////
	////Перевод во внутреннее исполнение
	//cout_prog(prog);
	vector<unsigned> inside_prog;
	for (int i = 0; i + 1 < int(prog.size()); i++) {
		int j = 0;
		if (j < int(prog[i].size())) {
			command x = find_com(prog[i][j]);
			if (x.id == -1) {
				cout << "error in line " << i << endl;
				cout << prog[i][j] << endl;
				return 0;
			}
			unsigned com = 0;
			com = com | x.id;
			com = com << 24;
			if (x.type == "RM") {
				prog[i][j + 1].erase(prog[i][j + 1].begin());
				unsigned reg = 0;
				reg = atoi(prog[i][j + 1].c_str());
				reg = reg << 20;
				com = com | reg;
				unsigned operand = 0;
				operand = atoi((prog[i][j + 2]).c_str());
				com = com | operand;
			}
			if (x.type == "RI") {
				prog[i][j + 1].erase(prog[i][j + 1].begin());
				unsigned reg = 0;
				reg = atoi(prog[i][j + 1].c_str());
				reg = reg << 20;
				com = com | reg;
				int operand = 0;
				if (marks.find(prog[i][j + 2]) != marks.end()) {
					operand = marks[prog[i][j + 2]];
				}
				else {
					operand = atoi((prog[i][j + 2]).c_str());
				}
				com = com | operand;
			}
			if (x.type == "RR") {
				prog[i][j + 1].erase(prog[i][j + 1].begin());
				unsigned reg = 0;
				reg = atoi(prog[i][j + 1].c_str());
				reg = reg << 20;
				com = com | reg;
				prog[i][j + 2].erase(prog[i][j + 2].begin());
				reg = atoi(prog[i][j + 2].c_str());
				reg = reg << 16;
				com = com | reg;
				int operand = 0;
				if (marks.find(prog[i][j + 2]) != marks.end()) {
					operand = marks[prog[i][j + 3]];
				}
				else {
					operand = atoi((prog[i][j + 3]).c_str());
				}
				com = com | operand;
			}
			if (x.type == "J") {
				unsigned operand = marks[prog[i][j + 1]];
				com = com | operand;
			}
			if (x.type == "J+") {
				unsigned operand = atoi(prog[i][j + 1].c_str());
				com = com | operand;
			}
			if (x.type == "RR+") {
				prog[i][j + 1].erase(prog[i][j + 1].begin());
				unsigned reg = 0;
				reg = atoi(prog[i][j + 1].c_str());
				reg = reg << 20;
				com = com | reg;
				prog[i][j + 2].erase(prog[i][j + 2].begin());
				reg = atoi(prog[i][j + 2].c_str());
				reg = reg << 16;
				com = com | reg;
			}
			inside_prog.push_back(com);
		}
	}
	int size = inside_prog.size();
	////////// Выполнение
	//cout_prog(prog);
	//cout_prog2(inside_prog);
	/*for (map <string, unsigned>::iterator it = marks.begin(); it != marks.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}*/
	for (int i = r[15]; i < size; i++) {
		unsigned comm = inside_prog[i];
		unsigned id = comm >> 24;
		switch (id){
		case 0: exit(0);break;
		case 1: syscall(comm);break;
		case 44: cmpi(comm);break;
		case 12: lc(comm);break;
		case 52: jg(comm, i);break;
		case 51: jge(comm, i);break;
		case 50: jl(comm, i);break;
		case 49: jle(comm, i);break;
		case 48: jeq(comm, i);break;
		case 47: jne(comm, i);break;
		case 46: jmp(comm, i);break;
		case 42: ret(comm, i);break;
		case 38: push(comm);break;
		case 39: pop(comm);break;
		case 6: mul(comm);break;
		case 41: calli(comm, i);break;
		case 5: subi(comm); break;
		case 24: mov(comm);break;
		case 2: add(comm);break;
		case 3: addi(comm);break;
		case 43: cmp(comm);break;
		case 4: sub(comm);break;
		case 7: muli(comm);break;
		case 8: div(comm);break;
		case 9: divi(comm);break;
		case 40: call(comm, i);break;
		case 13: shl(comm);break;
		case 14: shli(comm);break;
		case 15: shr(comm);break;
		case 16: shri(comm);break;
		case 17: and_(comm);break;
		case 18: andi(comm);break;
		case 19: or_(comm);break;
		case 20: ori(comm);break;
		case 21: xor_(comm);break;
		case 22: xori(comm);break;
		case 23: not_(comm);break;
		case 64: load(comm);break;
		case 65: store(comm);break;
		case 66: load2(comm);break;
		case 67: store2(comm);break;
		case 68: loadr(comm);break;
		case 69: storer(comm);break;
		case 70: loadr2(comm);break;
		case 71: storer2(comm);break;
		case 32: addd(comm);break;
		case 33: subd(comm);break;
		case 34: muld(comm);break;
		case 35: divd(comm);break;
		case 36: itod(comm);break;
		case 37: dtoi(comm);break;
		}
		//cout << i << ") " << "|r0:" << r[0] << "|r1:" << r[1] << "|r2:" << r[2] << "|r3:" << r[3] << "|r4:" << r[4] << "|r5:" << r[5] << "|r6:" << r[6] << "|r7:" << r[7] << "|r8:" << r[8] << endl;
		//cout << "flags: " << flags << endl;
	};
	return 0;
}