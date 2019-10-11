#include<stdio.h>
#include<string>
#include<vector>
#include<string>
#include<iostream>
#include<string.h>
#include <sstream>
using namespace std;

#define SymbolNum 42
#define ReserveNum 13
#define PathcLen  100  //文件路径长度
#define String_MaxLen 100
#define Int_MaxLen 33
#define SymT_Maxlen 10
#define SymTa_Maxlen 200

#define TableMax 300
#define NameLen 150

#define FILE_END -38
#define SYM_ERRO -37
#define IDSY -2
#define RESERVESY -2
#define INTSY -2

#define GLOBAL 1
#define LOCAL 0




const char *Print_SY[SymbolNum] = {
	"plusSY",
	"minuSY",
	"multSY",
	"diviSY",
	"assSY",
	"eqSY",
	"neqSY",
	"lsSY",
	"lseSY",
	"laSY",
	"laeSY",
	"lparSY",
	"rparSY",
	"lbrkSY",
	"rbrkSY",
	"lbreSY",
	"rbreSY",
	"sqSY",
	"dqSY",
	"colSY",
	"semiSY",
	"comSY",
	"constSY",
	"intSY",
	"charSY",
	"voidSY",
	"mainSY",
	"ifSY",
	"whileSY",
	"switchSY",
	"caseSY",
	"defaultSY",
	"scanfSY",
	"printfSY",
	"returnSY",
	"unsintSY",
	"sintSY",
	"idSY",
	"chaSY",
	"StrSY",
	"nullSY",
	"overSY"
};
const char *Reserve_word[ReserveNum] = {
	"const",  //22
	"int",
	"char",
	"void",
	"main",
	"if",
	"while",
	"switch",
	"case",
	"default",
	"scanf",
	"printf",
	"return"   //34
};
char ERROR_TYPECODE[200][40] = {
	"ZEROSTARTNUM_ERROR",
	"ILIGALCHAR_ERROR",
	"SINGLEQ_ERROR",
	"DOUBLEQ_ERROR",
	"LPAR_ERROR",
	"RPAR_ERROR",
	"LBRACKET_ERROR",
	"RBRACKET_ERROR",
	"LBRACE_ERROR",
	"RBRACE_ERROR",
	"CONST_TYPE_ERROR",
	"CONST_ID_ERROR",
	"ASSIGN_SY_ERROR",
	"CONST_ASSIGNTY_ERROR",
	"SEMI_ERROR",
	"ID_ERROR",  //15

	"Identifier has been declared",
	"ID_UNDECLARED",
	"FUN_UNDECLARE",
	"SYM_ERROR",
	"VPARA_NUM_ERROR",
	"FUNCFACTOR_SYM_ERROR",
	"RBRK_ERROR",
	"ILIGAL_FACTOR_ERRO",  //22
	"RBRE_ERROR"  

};

typedef enum {
	plusSY = 0,
	minuSY,
	multSY,
	diviSY,
	assSY,
	eqSY,
	neqSY,
	lsSY,
	lseSY,
	laSY,
	laeSY,
	lparSY,
	rparSY,
	lbrkSY,
	rbrkSY,
	lbreSY,
	rbreSY,
	sqSY,
	dqSY,
	colSY,
	semiSY,
	comSY,
	constSY,
	intSY,
	charSY,
	voidSY,
	mainSY,
	ifSY,
	whileSY,
	switchSY,
	caseSY,
	defaultSY,
	scanfSY,
	printfSY,
	returnSY,
	unsintSY,
	sintSY,
	idSY,
	chaSY,
	StrSY,
	nullSY,
	overSY
}symSY;
typedef enum {
	consttype = 0,
	varibletype,
	functiontype,
	arraytype,
	parametertype = 4,
	constype_g,
	vatibletype_g,
	arraytype_g,
	nulltype,
}SYMtyp;
typedef enum {
	ZEROSTARTNUM_ERRO = 0,	//0开始的数字			0
	ILIGALCHAR_ERRO,		//非法字符				1
	SINGLEQ_ERRO,			//单引号				2
	DOUBLEQ_ERRO,			//双引号				3
	LPAR_ERRO,				//左括号				4
	RPAR_ERRO,				//右括号				5
	LBRACKET_ERROR,			//左中括号				6
	RBRACKET_ERROR,			//右中括号				7
	LBRACE_ERROR,			//左大括号				8
	RBRACE_ERROR,			//右大括号				9
	CONST_TYPE_ERROR,		//常量声明类型错误		10
	CONST_ID_ERROR,			//常量声明标识符错误	11
	ASSIGN_SY_ERROR,		//缺少赋值号           12
	CONST_ASSIGNTY_ERROR,		//常量赋值类型错误      13
	SEMI_ERROR,              //缺少分号               14
	ID_ERROR,  //15
	ID_DECLARED,  //16
	ID_UNDECLARED, //17   标识符未定义
	FUN_UNDECLARE,
	SYM_ERROR,        //19
	VPARA_NUM_ERROR,    //20
	FUNCFACTOR_SYM_ERROR,   //21
	RBRK_ERROR,
	ILIGAL_FACTOR_ERRO,  //22
	RBRE_ERROR



}error_num;
typedef struct {
	char name[NameLen];
	SYMtyp symtyp;
	symSY sym;
	int level;
	int length;  //数组长度
	//int offset;
	//int index;
	string value;

}symbolTable;

typedef struct {
	char op;
	string A;
	string B;
	string C;
}mid_code;

typedef struct {
	string func_name;
	string func_rename;
	int fun_begin;
	int fun_end;
	int sp_len;
}function_name;

typedef struct {
	string name;
	int addr;
}run_stack;

typedef struct {
	string name;
}func_tmp_var;


void Compound_statement();
string Expression();
void statement();
void Statement_column();
void genmidcode(char op, string A, string B, string C);
string gentmp();
void check_sym(int achar, int sym);


FILE *infile;
symSY symbol = nullSY;
char token[String_MaxLen];
char INTtoken[Int_MaxLen];
char UINTtoken[Int_MaxLen];
string character;
char CH[1];
int symToken[SymT_Maxlen];
int StatementFlag;
string Expression_print(int &achar);


//symbolTable symtable[SymTa_Maxlen];
symbolTable symtmp;
mid_code midtmp;
mid_code paratmp;
function_name functmp;
run_stack runtmp;
func_tmp_var func_vctmp;
vector<string> midlecode;
vector<mid_code>midcode;
vector<symbolTable>symtable;
vector<function_name>func;
vector<run_stack>*runstack;
//vector<func_tmp_var>*func_stack;  //存每个函数的中间代码中出现的$tn和变量常量，加到vector<function_name>func中;
vector<run_stack>*cur_func_runstack;
int symTop = 0;
int paraNUM = 0;
int fun_level = 0;
int fun_p = 0;
int tmpnum = 0;
int labelnum = 0;
int STRflag = 0;
int CHflag = 0;
int id_index = 0;
int cur_line = 1;
int print_flag = 0;

void error(error_num erroNUM) {
	printf("%s\n", ERROR_TYPECODE[erroNUM]);
	cout << " at line " << cur_line << endl;
};

bool isLetter(char ch) {
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A'&& ch <= 'Z') || ch == '_')
		return true;
	return false;
}
bool isDigit(char ch) {
	if (ch >= '0' && ch <= '9')
		return true;
	else
		return false;
}
int isReserve(char *token) {
	int i = 0;
	for (i = 0; i < 13; i++) {
		if (!(strcmp(token, Reserve_word[i])))
			break;
	}
	return i;

}
bool isPa(char ch) {
	if (ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}') {
		return true;
	}
	else
		return false;
}
bool isOperator(char ch) {
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
		return true;
	}
	else
		return false;
}
bool isDemarcation(char ch) {
	if (ch == ':' || ch == ',' || ch == ';') {
		return true;
	}
	else
		return false;
}
void clearToken(int *token, int Len) {
	int i = 0;
	for (i = 0; i < Len; i++) {
		token[i] = 0;
	}
}
void clearToken(char *token) {
	strcpy(token, "");
}


int get_symbol(FILE *infile, symSY* symbol) {
	strcpy(token, "");
	int i = 0, readflag = 1;
	char c;
	while (readflag && (!feof(infile))) {
		c = fgetc(infile);
		while ((c == '\t' || c == ' ' || c == '\n') && !STRflag) {
			if (!feof(infile)) {
				if (c == '\n')
					cur_line++;
				c = fgetc(infile);
			}
			else {
				return FILE_END;
				break;
			}
		}
		if (isLetter(c) && !CHflag && !STRflag) {
			token[i++] = c;
			c = fgetc(infile);
			while (isLetter(c) || isDigit(c)) {
				token[i++] = c;
				if (!feof(infile)) {
					c = fgetc(infile);
				}
				else {
					return FILE_END;
					break;
				}
			}
			token[i] = '\0';
			readflag = 0;
			if (!feof(infile))
				fseek(infile, -1, SEEK_CUR);
			int num;
			num = isReserve(token);
			if (num > 12) {
				*symbol = idSY;
				return IDSY;
			}
			else if (num < 13) {
				switch (num) {
				case 0: *symbol = constSY; break;
				case 1: *symbol = intSY; break;
				case 2: *symbol = charSY; break;
				case 3: *symbol = voidSY; break;
				case 4: *symbol = mainSY; break;
				case 5: *symbol = ifSY; break;
				case 6: *symbol = whileSY; break;
				case 7: *symbol = switchSY; break;
				case 8: *symbol = caseSY; break;
				case 9: *symbol = defaultSY; break;
				case 10: *symbol = scanfSY; break;
				case 11: *symbol = printfSY; break;
				case 12: *symbol = returnSY; break;
				}
				return RESERVESY;
			}
		}
		else if (isDigit(c) && !CHflag && !STRflag) {
			token[i++] = c;
			c = fgetc(infile);
			while (isDigit(c)) {
				token[i++] = c;
				if (!feof(infile)) {
					c = fgetc(infile);
				}
				else {
					return FILE_END;
					break;
				}
			}
			token[i] = '\0';
			readflag = 0;
			if (!feof(infile))
				fseek(infile, -1, SEEK_CUR);
			*symbol = unsintSY;
			return INTSY;
		}

		else if (c == '"') {  //双引号开始
			STRflag = !STRflag;
			*symbol = dqSY;
			token[i++] = c;
			token[i] = '\0';
			return -2;
		}
		else if (STRflag) {
			token[i++] = c;
			if (c == '\\')
				token[i++] = c;
			c = fgetc(infile);
			while (c != '"') {
				if (c == '\\')
					token[i++] = c;
				token[i++] = c;
				c = fgetc(infile);
			}
			token[i] = '\0';
			fseek(infile, -1, SEEK_CUR);
			*symbol = StrSY;
			return -2;
		}
		else if (c == '\'') {
			CHflag = !CHflag;
			*symbol = sqSY;
			token[i++] = c;
			token[i] = '\0';
			return -2;
		}
		else if (CHflag) {

			if (isDigit(c) || c == '+' || c == '-' || c == '*' || c == '/' || isLetter(c)) {
				token[i++] = c;
				token[i] = '\0';
				*symbol = chaSY;
				return -2;
			}
		}
		else if (c == '!' && !CHflag && !STRflag) {
			token[i++] = c;
			c = fgetc(infile);
			if (c == '=') {   //!=
				token[i++] = c;
				*symbol = neqSY;
				token[i] = '\0';
				return -2;
			}
			else {    //erro
				printf("'!' error");
				return SYM_ERRO;
			}
		}
		else if (c == '=' && !CHflag && !STRflag) {
			token[i++] = c;
			c = fgetc(infile);
			if (c == '=') {   //==
				token[i++] = c;
				*symbol = eqSY;
				token[i] = '\0';
				return -2;
			}
			else {    //=
				fseek(infile, -1, SEEK_CUR);
				*symbol = assSY;
				token[i] = '\0';
				return -2;
			}
		}
		else if (c == '<' && !CHflag && !STRflag) {
			token[i++] = c;
			c = fgetc(infile);
			if (c == '=') {   //<=
				token[i++] = c;
				*symbol = lseSY;
				token[i] = '\0';
				return -2;
			}
			else {    //<
				fseek(infile, -1, SEEK_CUR);
				*symbol = lsSY;
				token[i] = '\0';
				return -2;
			}
		}
		else if (c == '>' && !CHflag && !STRflag) {
			token[i++] = c;
			c = fgetc(infile);
			if (c == '=') {   //>=
				token[i++] = c;
				*symbol = laeSY;
				token[i] = '\0';
				return -2;
			}
			else {    //>
				fseek(infile, -1, SEEK_CUR);
				*symbol = laSY;
				token[i] = '\0';
				return -2;
			}
		}
		else if (isPa(c) && !CHflag && !STRflag) {
			switch (c) {
			case '(':*symbol = lparSY; break;
			case ')':*symbol = rparSY; break;
			case '[':*symbol = lbrkSY; break;
			case ']':*symbol = rbrkSY; break;
			case '{':*symbol = lbreSY; break;
			case '}':*symbol = rbreSY; break;
			}
			token[i++] = c;
			token[i] = '\0';
			return -2;
		}
		else if (isOperator(c) && !CHflag && !STRflag) {
			switch (c) {
			case '+':*symbol = plusSY; break;
			case '-':*symbol = minuSY; break;
			case '*':*symbol = multSY; break;
			case '/':*symbol = diviSY; break;
			}
			token[i++] = c;
			token[i] = '\0';
			return -2;
		}
		else if (isDemarcation(c) && !CHflag && !STRflag) {
			switch (c) {
			case ':':*symbol = colSY; break;
			case ';':*symbol = semiSY; break;
			case ',':*symbol = comSY; break;
			}
			token[i++] = c;
			token[i] = '\0';
			return -2;
		}
		else {
			return SYM_ERRO;
		}
	}

	if (feof(infile)) {
		printf("file end\n");
		*symbol = nullSY;
		return(nullSY);
	}

}

void lexical_analysis(FILE *infile) {
	int RE_sys;
	while (!feof(infile)) {
		RE_sys = get_symbol(infile, &symbol);
		if (RE_sys == -2)
			printf("%s %s\n", Print_SY[symbol], token);
	}
}
bool isReserveSym() {
	if (symbol >= 22 && symbol <= 34)
		return true;
	else
		return false;
}
bool isRelationalOp() {
	if (symbol == eqSY || symbol == neqSY || symbol == lsSY || symbol == lseSY || symbol == laSY || symbol == laeSY) {
		return true;
	}
	else
		return false;

}
bool isZero(char *token) {
	int i, Len;
	Len = strlen(token);
	for (i = 0; i < Len; i++) {
		if (token[i] != 0) {
			return false;
		}
	}
	return true;

}
bool isUnsint() {
	if (symbol == unsintSY) {
		if (token[0] != '0') {
			strcpy(UINTtoken, token);
			return true;
		}
		else {
			if (!isZero) {
				error(ZEROSTARTNUM_ERRO);
				int i = 0, j = 0, L;
				while (token[i++] == '0')
					i++;
				L = strlen(token);
				L = L - i;
				while (j < L) {
					UINTtoken[j++] = token[i++];
				}
				UINTtoken[j] = '\0';
				return true;
			}
			else {
				UINTtoken[0] = '0';
				UINTtoken[1] = '\0';
				return true;
			}
		}
	}
	else return false;
}
bool isINT() {
	if (isUnsint()) {
		strcpy(INTtoken, token);
		get_symbol(infile, &symbol);
		return true;
	}
	else if (symbol == plusSY || symbol == minuSY) {
		int j = 0, k = 0;
		INTtoken[k++] = token[0];
		get_symbol(infile, &symbol);
		while (symbol == plusSY || symbol == minuSY) {
			INTtoken[k++] = token[0];
			get_symbol(infile, &symbol);
		}
		INTtoken[k] = '\0';
		if (isUnsint()) {
			symbol = sintSY;
			strcat(INTtoken, UINTtoken);
		}
		get_symbol(infile, &symbol);
		return true;
	}
	else {     //类型错误，读到分隔符或保留字的时候就返回
		while (symbol != semiSY && symbol != comSY && !isReserveSym())
			get_symbol(infile, &symbol);
		return false;
	}

}
bool isCharacter() {
	if (symbol == sqSY) {
		get_symbol(infile, &symbol);
		if (symbol == chaSY) {
			character = token[0];
			CH[0] = token[0];
			CH[1] = '\0';
			get_symbol(infile, &symbol);

			if (symbol == sqSY) {
				get_symbol(infile, &symbol);
				return true;
			}
			else {
				error(SINGLEQ_ERRO);
				while (symbol != semiSY && symbol != comSY && !isReserveSym())
					get_symbol(infile, &symbol);
				return true;
			}
		}
		else {
			while (symbol != semiSY && symbol != comSY && !isReserveSym())
				get_symbol(infile, &symbol);
			return false;
		}

	}
	else {
		while (symbol != semiSY && symbol != comSY && !isReserveSym())
			get_symbol(infile, &symbol);
		return false;
	}

}
bool check_id() {
	unsigned int i = 0;
	for (i = 0; (i < symtable.size()) && (symtmp.level >= symtable[i].level); i++) {
		if (strcmp(symtmp.name, symtable[i].name) == 0 && symtmp.level == symtable[i].level) {
			error(ID_DECLARED);
			return false;
		}
	}
	return true;
}

void Constant_definition(int global) {   //常量定义
	int flag = 1;
	if (symbol != intSY && symbol != charSY) {
		error(CONST_TYPE_ERROR);
		while (symbol != semiSY && !isReserveSym())
		{
			get_symbol(infile, &symbol);
		}
		get_symbol(infile, &symbol);
	}
	else if (symbol == intSY) {
		get_symbol(infile, &symbol);
		while (flag == 1) {
			symtmp.level = fun_level;
			symtmp.symtyp = consttype;
			symtmp.sym = intSY;
			symtmp.length = 0;
			//string a = "const int ";
			midtmp.op = 'c';
			midtmp.C = "int";
			if (symbol == idSY) {    //标识符
				midtmp.A = token;
				strcpy(symtmp.name, token);
				get_symbol(infile, &symbol);

				if (symbol == assSY) {     //等号
					get_symbol(infile, &symbol);
					if (isINT()) {
						//插入常量表//////////////////////////////////////////
						symtmp.value = INTtoken;
						if (check_id()) {
							symtable.push_back(symtmp);
							midtmp.B = INTtoken;
							midcode.push_back(midtmp);
							//clearmidcodetmp();
						}
						if (symbol == comSY) //逗号则开始读下一个标识符
							flag = 1;
						else if (symbol == semiSY || isReserveSym()) {  //分号则读下一行   或保留字
							flag = 0;
							//if (symbol == semiSY)
								//printf("it is a constant description\n");
						}
						else {
							error(SEMI_ERROR);
							flag = 0;
						}
						get_symbol(infile, &symbol);
					}
					else {       //赋值类型错误
						error(CONST_ASSIGNTY_ERROR);
						//处理分界符
						if (symbol == comSY) //逗号则开始读下一个标识符
							flag = 1;
						else if (symbol == semiSY)   //分号则读完一条const
							flag = 0;
						else {
							error(SEMI_ERROR);   //缺少分号
							flag = 0;
						}
						get_symbol(infile, &symbol);
					}
				}
				else {
					error(ASSIGN_SY_ERROR);    //缺少等号
											   //处理分界符
					if (symbol == comSY) //逗号则开始读下一个标识符
						flag = 1;
					else if (symbol == semiSY || isReserveSym()) {   //分号则读完一条const
						flag = 0;
					}
					else {
						error(SEMI_ERROR);
						flag = 0;
					}
					get_symbol(infile, &symbol);
				}
			}
			else {
				error(CONST_ID_ERROR);
				while (symbol != ',') {
					get_symbol(infile, &symbol);
				}
				get_symbol(infile, &symbol);
			}
		}
	}
	else if (symbol == charSY) {
		get_symbol(infile, &symbol);
		while (flag == 1) {
			symtmp.level = fun_level;
			symtmp.symtyp = consttype;
			symtmp.sym = charSY;
			symtmp.length = 0;
			midtmp.op = 'c';
			midtmp.C = "char";
			if (symbol == idSY) {    //标识符
				midtmp.A = token;
				strcpy(symtmp.name, token);
				get_symbol(infile, &symbol);

				if (symbol == assSY) {     //等号
					//a = a + token;
					get_symbol(infile, &symbol);
					if (isCharacter()) {
						//插入常量表//////////////////////////////////////////
						symtmp.value = CH;
						if (check_id()) {
							symtable.push_back(symtmp);
							int cha_ascii = CH[0];
							stringstream ss;
							ss << cha_ascii;
							midtmp.B = ss.str();
							midcode.push_back(midtmp);
							//midlecode.push_back(a);
						}
						if (symbol == comSY) //逗号则开始读下一个标识符
							flag = 1;
						else if (symbol == semiSY || isReserveSym()) {  //分号则读完一条const
							flag = 0;
							//if (symbol == semiSY)
								//printf("it is a constant description\n");
						}
						else {
							error(SEMI_ERROR);
							flag = 0;
						}
						get_symbol(infile, &symbol);
					}
					else {       //赋值类型错误
						error(CONST_ASSIGNTY_ERROR);
						//处理分界符
						if (symbol == comSY) //逗号则开始读下一个标识符
							flag = 1;
						else if (symbol == semiSY || isReserveSym())   //分号则读完一条const
							flag = 0;
						else {
							error(SEMI_ERROR);
							flag = 0;
						}
						get_symbol(infile, &symbol);
					}
				}
				else {
					error(ASSIGN_SY_ERROR);    //缺少等号
											  //处理分界符
					if (symbol == comSY) //逗号则开始读下一个标识符
						flag = 1;
					else if (symbol == semiSY || isReserveSym())   //分号则读完一条const
						flag = 0;
					else {
						error(SEMI_ERROR);
						flag = 0;
					}
					get_symbol(infile, &symbol);
				}
			}
			else {
				error(CONST_ID_ERROR);
				while (symbol != ',') {
					get_symbol(infile, &symbol);
				}
				get_symbol(infile, &symbol);
			}
			if (symbol == lbreSY) {
				Compound_statement();
			}
		}
	}

}
bool isStatement() {
	if (symbol == ifSY || symbol == whileSY || symbol == lbreSY || symbol == idSY || symbol == scanfSY || symbol == printfSY || symbol == semiSY || symbol == switchSY || symbol == returnSY) {
		return true;
	}
	else
		return false;

}

void Constant_description(int global) {  //常量说明
	if (symbol != constSY) {
		//printf("There is no constant description\n");
		return;
	}
	while (symbol == constSY) {
		get_symbol(infile, &symbol);
		Constant_definition(global);
	}
	//printf("it is a constant description\n");
}
void mid_tmp_op() {
	if (symbol == intSY) {
		midtmp.C = "int";
		symtmp.sym = intSY;
	}
	else if (symbol == charSY) {
		midtmp.C = "char";
		symtmp.sym = charSY;
	}
	else if (symbol == voidSY) {
		midtmp.C = "void";
		symtmp.sym = voidSY;
	}
}
void clearmidcodetmp() {
	midtmp.A = "";
	midtmp.B = "";
	midtmp.C = "";
}
void Parameter_table() {   //参数表
	paraNUM = 0;
	if (symbol == rparSY) {
		get_symbol(infile, &symbol);
		symtable[fun_p].length = paraNUM;
		//printf("it is an empty parameter_table\n");
	}
	else if (symbol == intSY || symbol == charSY) {
		mid_tmp_op();
		midtmp.op = 'p';
		midtmp.B = "";
		symtmp.level = fun_level;
		symtmp.symtyp = parametertype;
		symtmp.value = "";
		symtmp.length = 0;
		while (symbol != rparSY) {       /////////////////////////////缺少右括号未分析
			get_symbol(infile, &symbol);
			if (symbol == idSY) {
				/////inserttabel();//加入符号表
				strcpy(symtmp.name, token);
				midtmp.A = token;
				if (check_id()) {
					symtable.push_back(symtmp);
					midcode.push_back(midtmp);
					paraNUM++;
				}
				get_symbol(infile, &symbol);
				while (symbol == comSY) {   ////////////分号容错
					get_symbol(infile, &symbol);
					if (symbol == intSY || symbol == charSY) {
						mid_tmp_op();
						get_symbol(infile, &symbol);
						if (symbol == idSY) {
							/////inserttabel();//加入符号表
							strcpy(symtmp.name, token);
							midtmp.A = token;
							if (check_id()) {
								symtable.push_back(symtmp);
								midcode.push_back(midtmp);
								paraNUM++;
							}
							get_symbol(infile, &symbol);
						}
						//else
					}
					//else
				}
			}
			//else IDERROR
		}
		symtable[fun_p].length = paraNUM;
		paraNUM = 0;
		//printf("it is a parameter_table\n");
		get_symbol(infile, &symbol);

	}
	else {
		error(RPAR_ERRO);
	}
	if (symbol == lbreSY) {
		Compound_statement();    //复合语句
	}
	else {
		error(LBRACE_ERROR);
		Compound_statement();
	}
	//else
}
/*
string to_string(int num)
{
	string result;
	stringstream ss;
	ss << num;
	ss >> result;
	return result;
}
int atoi(string num)
{
	int result;
	stringstream ss;
	ss << num;
	ss >> result;
	return result;
}
*/
void value_para(string fun_name, int id_index) {
	//get_symbol(infile, &symbol);
	int pa_num = symtable[id_index].length;
	int pa_index = 1;
	string vp, index;

	int achar = 0;
	int sym = symtable[id_index + pa_index].sym;
	vp = Expression_print(achar);  //将值参数表达式结果赋值给临时变量
	check_sym(achar, sym);

	index = to_string(pa_index++);
	genmidcode('d', vp, fun_name, index);
	while (symbol == comSY) {
		achar = 0;
		sym = symtable[id_index + pa_index].sym;
		get_symbol(infile, &symbol);
		vp = Expression_print(achar);
		check_sym(achar, sym);
		index = to_string(pa_index++);
		genmidcode('d', vp, fun_name, index);
	}
	if ((pa_index - 1) != pa_num)
		error(VPARA_NUM_ERROR);
	if (symbol == rparSY) {
		return;
	}
	else {
		error(RPAR_ERRO);
		return;
	}
}
void Funcall_statement(string a, int para_num, int id_index) {
	get_symbol(infile, &symbol);
	if (symbol == rparSY) { //值参数表为空
		//printf("value_para is null\n");
		stringstream ss;
		ss << para_num;
		genmidcode('b', "call", a, ss.str());
		get_symbol(infile, &symbol);
	}
	else {
		value_para(a, id_index);
		//printf("it is a value_para table\n");
		stringstream ss;
		ss << para_num;
		genmidcode('b', "call", a, ss.str());
		get_symbol(infile, &symbol);
	}
}
void check_sym(int achar, int sym) {
	if (sym == charSY && achar != 1) {
		error(SYM_ERROR);
		return;
	}
	else if (sym == intSY && achar != 0) {
		error(SYM_ERROR);
		return;
	}
}
void assign_statement(string id, int sym) {
	if (symbol == assSY) {
		get_symbol(infile, &symbol);
		int achar = 0;
		string result = Expression_print(achar);
		check_sym(achar, sym);
		genmidcode('k', id, "", result);
	}
	else if (symbol == lbrkSY) {
		get_symbol(infile, &symbol);
		string index = Expression();
		if (symbol == rbrkSY) {
			get_symbol(infile, &symbol);
			if (symbol == assSY) {
				get_symbol(infile, &symbol);
				int achar = 0;
				string result = Expression_print(achar);
				check_sym(achar, sym);
				genmidcode('k', id, index, result);
			}
		}
		else {
			error(RBRK_ERROR);
			get_symbol(infile, &symbol);
			if (symbol == assSY) {
				get_symbol(infile, &symbol);
				int achar = 0;
				string result = Expression_print(achar);
				check_sym(achar, sym);
				genmidcode('k', id, index, result);
			}
		}
	}
	//get_symbol(infile, &symbol);
}
bool check_function(char *token) {
	unsigned int i = 0;
	for (i = 0; (i < symtable.size()) && (fun_level >= symtable[i].level); i++) {
		if (strcmp(token, symtable[i].name) == 0 && symtable[i].symtyp == functiontype) {
			id_index = i;
			return true;
		}
	}
	error(FUN_UNDECLARE);
	return false;
}
int check_id_exist(char *token) {
	unsigned int i = 0;
	for (i = 0; (i < symtable.size()) && (fun_level >= symtable[i].level); i++) {
		if (strcmp(token, symtable[i].name) == 0 && symtable[i].level != 0 && (fun_level == symtable[i].level)) {
			if (symtable[i].symtyp == varibletype) {
				id_index = i;
				return varibletype;
			}
			else if (symtable[i].symtyp == arraytype) {
				id_index = i;
				return arraytype;
			}
			else if (symtable[i].symtyp == parametertype) {
				id_index = i;
				return parametertype;
			}
			else if (symtable[i].symtyp == consttype) {
				id_index = i;
				return consttype;
			}
		}
		if (symtable[i].level != 0 && strcmp(token, symtable[i].name) == 0 && symtable[i].symtyp == functiontype) {
			id_index = i;
			return functiontype;
		}

	}
	for (i = 0; (i < symtable.size()) && (fun_level >= symtable[i].level); i++) {
		if (symtable[i].level == 0 && strcmp(token, symtable[i].name) == 0) {
			if (symtable[i].symtyp == varibletype) {
				id_index = i;
				return varibletype;
			}
			else if (symtable[i].symtyp == arraytype) {
				id_index = i;
				return arraytype;
			}
			else if (symtable[i].symtyp == consttype) {
				id_index = i;
				return consttype;
			}
			//else if (symtable[i].symtyp == functiontype)
				//return functiontype;
			//id_index = i;
		}
	}
	error(ID_UNDECLARED);
	return -1;
}

string gentmp() {
	//static int tmpnum = 0;
	string tmp = "$t";
	string tmpname;
	stringstream ss;
	ss << tmpnum;
	ss >> tmpname;
	tmpnum++;
	tmp += tmpname;
	return tmp;
}
string genlabel() {
	string la = "label";
	string laname;
	stringstream ss;
	ss << labelnum;
	ss >> laname;
	labelnum++;
	la += laname;
	return la;
}
void recoverytmp() {
	tmpnum--;
}
void genmidcode(char op, string A, string B, string C) {
	midtmp.op = op;
	midtmp.A = A;
	midtmp.B = B;
	midtmp.C = C;
	midcode.push_back(midtmp);
}
string sym_to_str(symSY symbol) {
	string a;
	if (symbol == intSY) {
		a = "int";
	}
	else if (symbol == charSY) {
		a = "char";
	}
	return a;

}
string replace_global() {
	string id_;
	stringstream ss;
	ss << "*gl" << id_index;
	id_ = ss.str();
	return id_;
}
string factor(string minu) {
	if (symbol == idSY) { //数组元素或函数调用语句
		char a[NameLen];
		strcpy(a, token);
		string a_ = token;
		get_symbol(infile, &symbol);
		if (symbol == lbrkSY) {   //'a' $tn arrayID array_index
			string tmp;
			if (check_id_exist(a) == arraytype) {
				tmp = gentmp();
				if (symtable[id_index].level == 0) {
					a_ = replace_global();
				}
				else a_ = a;
			}
			get_symbol(infile, &symbol);
			string index = Expression();//分析中括号中exp

			if (symbol == rbrkSY) {
				genmidcode('a', tmp, a_, index);
				//printf("it is a factor\n");
				get_symbol(infile, &symbol);
				return tmp;
			}
		}
		else if (symbol == lparSY) {   //函数调用为factor
			check_function(a);
			int p_num = symtable[id_index].length;
			int sym = symtable[id_index].sym;
			if (sym == voidSY) {
				error(FUNCFACTOR_SYM_ERROR);
			}
			Funcall_statement(a, p_num, id_index);
			string retvalue = gentmp();
			genmidcode('b', retvalue, "ret", "");
			//printf("it is a factor\n");
			return retvalue;
		}
		else {
			//printf("it is a factor\n"); //变量名，常量名，参数直接返回名称
			int type_num = check_id_exist(a);
			if (type_num == varibletype || type_num == consttype || type_num == parametertype) {
				if (symtable[id_index].level == 0) {
					a_ = replace_global();
				}
				else a_ = a;
				return a_;
			}
		}
	}
	else if (symbol == lparSY) {
		get_symbol(infile, &symbol);
		string exp;
		exp = Expression();
		if (symbol == rparSY) {
			//printf("it is a factor\n");
			get_symbol(infile, &symbol);
			return exp;
		}
	}
	else if (symbol == plusSY || symbol == minuSY || symbol == unsintSY) {
		isINT();
		string fac_a = gentmp();
		string INT;
		//if (minu == "-") {
			//INT = minu + INTtoken;
		//}
		genmidcode('g', fac_a, INTtoken, "");
		//printf("it is a factor\n");
		return fac_a;
	}
	else if (symbol == sqSY) {
		isCharacter();
		string fac_a = gentmp();
		string ch = CH;
		int ch_ascii = CH[0];//////////////////////////////////////
		//string sq = "\'";
		//ch = sq + CH + sq;
		stringstream ss;
		ss << ch_ascii;
		genmidcode('g', fac_a, ss.str(), "");
		//printf("it is a factor\n");
		return fac_a;
	}
	else {
		error(ILIGAL_FACTOR_ERRO);
	}

}
string term(string a) {
	string tmp_a = factor(a);
	if (tmp_a[0] != '$') {     //factor返回的是变量名
		string id = tmp_a;
		tmp_a = gentmp();
		//if (a == "-")
			//id = "-" + id;
		genmidcode('e', tmp_a, id, "");
	}

	while (symbol == multSY || symbol == diviSY) {
		char op = token[0];
		get_symbol(infile, &symbol);
		string tmp_b = factor(a);
		/*
		if (tmp_b[0] != '$') {     //factor返回的是变量名
			string id = tmp_b;
			tmp_b = gentmp();
			genmidcode('e', tmp_b, id, "");
		}
		*/
		genmidcode(op, tmp_a, tmp_a, tmp_b);
		//if (a == "-") {
			//genmidcode('-', tmp_a, 0, tmp_a);
			//a = "";
		//}
	}
	return tmp_a;
	//printf("it is a term\n");
}
string Expression() {
	string a = token;
	int first_term = 0;
	if (symbol == plusSY || symbol == minuSY) {
		if (symbol == minuSY) {
			first_term = 1;
		}
		get_symbol(infile, &symbol);
	}
	string tmp_a = term(a);
	if (first_term)
	{
		genmidcode('-', tmp_a, "0", tmp_a);
	}
	while (symbol == plusSY || symbol == minuSY) {   //+ -运算
		char op = token[0];
		get_symbol(infile, &symbol);
		a = "";
		string tmp_b = term(a);
		genmidcode(op, tmp_a, tmp_a, tmp_b);
	}
	//printf("it is an expresion\n");
	return tmp_a;
}
void condition() {  //条件   ＜表达式＞＜关系运算符＞＜表达式＞｜＜表达式＞
	while (symbol != rparSY) {
		int achar1 = 0;
		string e1 = Expression_print(achar1);
		if (isRelationalOp()) {
			string a = token;
			int achar2 = 0;
			get_symbol(infile, &symbol);
			string e2 = Expression_print(achar2);
			if (achar1 != achar2) {
				error(SYM_ERROR);
			}
			genmidcode('h', e1, a, e2);
		}
		else {
			genmidcode('h', e1, "!=", "0");
		}
		//genmidcode('i',"BNZ") BNZ满足条件跳转
		//genmidcode('i',"BZ")
	}
	//printf("it is a condition\n");
	printf("it is a condition at line %d\n", cur_line);
}
void case_table(string e, string label) {
	while (symbol == caseSY) {
		get_symbol(infile, &symbol);  //case＜常量＞：＜语句＞
			//get_symbol(infile, &symbol);
		string op = "==";
		string next_case_label = genlabel();//生成case中语句的标签
		string B;
		if (token[0] == '\'') {
			if (isCharacter()) {
				//string sq = "\'";
				//B = sq + CH[0] + sq;
				B = to_string((int)CH[0]);

			}
		}
		else {
			if (isINT()) {
				B = INTtoken;
			}
		}
		genmidcode('h', e, op, B);
		if (symbol == colSY) { //冒号
			genmidcode('j', "BZ", next_case_label, "");
			get_symbol(infile, &symbol);
			statement();
			genmidcode('j', "GOTO", label, "");
			genmidcode('l', next_case_label, ":", "");
		}

	}
}
string factor_print(int &achar) {
	if (symbol == idSY) { //数组元素或函数调用语句
		char a[NameLen];
		strcpy(a, token);
		string a_ = token;
		get_symbol(infile, &symbol);
		if (symbol == lbrkSY) {   //'a' $tn arrayID array_index
			string tmp;
			if (check_id_exist(a) == arraytype) {
				tmp = gentmp();
				if (symtable[id_index].level == 0) {
					a_ = replace_global();
				}
				else a_ = a;
			}
			int sym = symtable[id_index].sym;
			get_symbol(infile, &symbol);
			string index = Expression();//分析中括号中exp

			if (symbol == rbrkSY) {
				genmidcode('a', tmp, a_, index);
				//printf("it is a factor\n");
				get_symbol(infile, &symbol);
				if (sym == charSY)  achar = 1;
				return tmp;
			}
		}
		else if (symbol == lparSY) {   //函数调用为factor
			check_function(a);
			int sym = symtable[id_index].sym;
			int p_num = symtable[id_index].length;
			if (sym == voidSY) {
				error(FUNCFACTOR_SYM_ERROR);
			}
			Funcall_statement(a, p_num, id_index);
			string retvalue = gentmp();
			genmidcode('b', retvalue, "ret", "");
			//printf("it is a factor\n");
			if (sym == charSY)  achar = 1;
			return retvalue;
		}
		else {
			//printf("it is a factor\n"); //变量名，常量名，参数直接返回名称
			int type_num = check_id_exist(a);
			if (type_num == varibletype || type_num == consttype || type_num == parametertype) {
				if (symtable[id_index].level == 0) {
					a_ = replace_global();
				}
				else a_ = a;
				int sym = symtable[id_index].sym;
				if (sym == charSY)  achar = 1;
				return a_;
			}
		}
	}
	else if (symbol == lparSY) {
		get_symbol(infile, &symbol);
		string exp;
		exp = Expression();
		if (symbol == rparSY) {
			//printf("it is a factor\n");
			get_symbol(infile, &symbol);
			return exp;
		}
	}
	else if (symbol == plusSY || symbol == minuSY || symbol == unsintSY) {
		isINT();
		string fac_a = gentmp();
		string INT;
		//if (minu == "-") {
			//INT = minu + INTtoken;
		//}
		genmidcode('g', fac_a, INTtoken, "");
		//printf("it is a factor\n");
		return fac_a;
	}
	else if (symbol == sqSY) {
		isCharacter();
		string fac_a = gentmp();
		string ch = CH;
		int ch_ascii = CH[0];//////////////////////////////////////
		//string sq = "\'";
		//ch = sq + CH + sq;
		stringstream ss;
		ss << ch_ascii;
		genmidcode('g', fac_a, ss.str(), "");
		//printf("it is a factor\n");
		achar = 1;
		return fac_a;
	}


}
string term_print(int &achar) {
	string tmp_a = factor_print(achar);
	if (tmp_a[0] != '$') {     //factor返回的是变量名
		string id = tmp_a;
		tmp_a = gentmp();
		//if (a == "-")
			//id = "-" + id;
		genmidcode('e', tmp_a, id, "");
	}

	while (symbol == multSY || symbol == diviSY) {
		achar = 0;
		int x = -1;
		char op = token[0];
		get_symbol(infile, &symbol);
		string tmp_b = factor_print(x);
		/*
		if (tmp_b[0] != '$') {     //factor返回的是变量名
			string id = tmp_b;
			tmp_b = gentmp();
			genmidcode('e', tmp_b, id, "");
		}
		*/
		genmidcode(op, tmp_a, tmp_a, tmp_b);
		//if (a == "-") {
			//genmidcode('-', tmp_a, 0, tmp_a);
			//a = "";
		//}
	}
	return tmp_a;
	//printf("it is a term\n");
}
string Expression_print(int &achar) {
	string a = token;
	int first_term = 0;
	if (symbol == plusSY || symbol == minuSY) {
		if (symbol == minuSY) {
			first_term = 1;
		}
		get_symbol(infile, &symbol);
	}
	string tmp_a = term_print(achar);
	if (first_term)
	{
		genmidcode('-', tmp_a, "0", tmp_a);
	}
	while (symbol == plusSY || symbol == minuSY) {   //+ -运算
		achar = 0;
		char op = token[0];
		get_symbol(infile, &symbol);
		a = "";
		string tmp_b = term(a);
		genmidcode(op, tmp_a, tmp_a, tmp_b);
	}
	//printf("it is an expresion\n");
	return tmp_a;
}
void statement() {
	if (symbol == semiSY) { //空语句
		get_symbol(infile, &symbol);
		//printf("it is a null statement\n");
		return;
	}
	else if (symbol == ifSY) {  //＜条件语句＞  ::=  if '('＜条件＞')'＜语句＞
		get_symbol(infile, &symbol);
		if (symbol == lparSY) {
			get_symbol(infile, &symbol);
			condition(); //分析条件之，生成e1 or  e1,r_op,e2
			string label = genlabel();
			genmidcode('j', "BZ", label, "");  //不满足跳转
			if (symbol == rparSY) {
				get_symbol(infile, &symbol);
				//printf("it is a if statement\n");
				statement();
				genmidcode('l', label, ":", "");  //分析完if{}中语句，跳转标签
				printf("%s %d\n", "if_end", cur_line);
			}

		}
	}
	else if (symbol == lbreSY) {    //'{' 语句列内语句列
		get_symbol(infile, &symbol);
		Statement_column();
		//printf("Statement column in statement\n"); /////////////////////////////////////////
		get_symbol(infile, &symbol);
	}

	else if (symbol == idSY) {
		string a = token;
		char id[NameLen];
		int id_sym = 0, p_num = 0;
		strcpy(id, token);
		get_symbol(infile, &symbol);
		string id_;
		if (check_id_exist(id) > 0) {
			id_sym = symtable[id_index].sym;
			p_num = symtable[id_index].length;
			if (symtable[id_index].level == 0) {
				id_ = replace_global();
			}
			else id_ = a;
			a = id_;
		}
		if (symbol == assSY) {    //赋值语句
			assign_statement(a, id_sym);
			if (symbol == semiSY) {
				printf("it is an assign statementat line %d\n", cur_line);
				get_symbol(infile, &symbol);
				return;
			}
			else {
				error(SEMI_ERROR);
			}
		}
		else if (symbol == lparSY) {    //函数调用
			Funcall_statement(a, p_num, id_index);
			if (symbol == semiSY) {
				printf("it is a function_call statement at line %d\n", cur_line);
				get_symbol(infile, &symbol);
				//return;
			}
			else {
				error(SEMI_ERROR);
			}
		}
		else if (symbol == lbrkSY) { //给数组元素赋值
			assign_statement(a, id_sym);
			if (symbol == semiSY) {
				printf("it is an assign statement at line %d\n", cur_line);
				get_symbol(infile, &symbol);
				//return;
			}
			else {
				error(SEMI_ERROR);
			}
		}
	}
	else if (symbol == whileSY) {
		get_symbol(infile, &symbol);
		string label_begin = genlabel();
		genmidcode('l', label_begin, ":", "");
		if (symbol == lparSY) {
			get_symbol(infile, &symbol);
			condition();
			string label_end = genlabel();
			genmidcode('j', "BZ", label_end, ""); //不满足条件跳转到结束
			if (symbol == rparSY) {
				get_symbol(infile, &symbol);
				//printf("it is a while statement\n");
				statement();
				genmidcode('j', "GOTO", label_begin, "");
				genmidcode('l', label_end, ":", "");
				printf("%s %d\n", "while_end", cur_line);
			}
		}
	}
	else if (symbol == switchSY) {
		get_symbol(infile, &symbol);
		if (symbol == lparSY) {
			get_symbol(infile, &symbol);
			string e = Expression();
			string switch_end = genlabel();
			if (symbol == rparSY) {
				get_symbol(infile, &symbol);
				if (symbol == lbreSY) {
					get_symbol(infile, &symbol);
					case_table(e, switch_end);
					if (symbol == defaultSY) {
						get_symbol(infile, &symbol);
						if (symbol == colSY) {
							get_symbol(infile, &symbol);
							statement();
							if (symbol == rbreSY) {
								//printf("it is a switch statement\n");
								printf("%s %d\n", "switch_end", cur_line);
								genmidcode('l', switch_end, ":", "");
								get_symbol(infile, &symbol);
							}
							else {
								error(RBRE_ERROR);
							}
						}
					}
					else if (symbol == (rbreSY)) {
						printf("%s %d\n", "switch_end", cur_line);
						genmidcode('l', switch_end, ":", "");
						get_symbol(infile, &symbol);
					}
				}
			}
		}

	}
	else if (symbol == returnSY) {
		get_symbol(infile, &symbol);
		if (symbol == lparSY) {
			get_symbol(infile, &symbol);
			int achar = 0, curlevel, sym;
			curlevel = fun_level;
			int j = 0;
			for (j = 0; j < symtable.size(); j++) {
				if (symtable[j].level == curlevel && symtable[j].symtyp == functiontype) {
					sym = symtable[j].sym;
					break;
				}
			}
			string e = Expression_print(achar);
			check_sym(achar, sym);
			if (symbol == rparSY) {
				get_symbol(infile, &symbol);
				if (symbol == semiSY) {
					printf("it is a return statementat line %d\n", cur_line);
					genmidcode('r', "return", e, "");
					get_symbol(infile, &symbol);
					//return;
				}
				else {
					error(SEMI_ERROR);
				}
			}
		}
		else if (symbol == semiSY) {
			printf("it is a return statementat line %d\n", cur_line);
			genmidcode('r', "return", "", "");
			get_symbol(infile, &symbol);
			//return;
		}
		else {
			error(SEMI_ERROR);
		}
	}
	else if (symbol == scanfSY) {
		get_symbol(infile, &symbol);
		if (symbol == lparSY) {
			get_symbol(infile, &symbol);
			if (symbol == idSY) {
				string id = token;
				string id_;
				if (check_id_exist(token) > 0) {
					if (symtable[id_index].level == 0) {
						id_ = replace_global();
					}
					else id_ = id;
				}
				string sym = sym_to_str(symtable[id_index].sym);
				genmidcode('s', "scan", id_, sym);
				get_symbol(infile, &symbol);
				while (symbol == comSY) {
					get_symbol(infile, &symbol);
					if (symbol == idSY) {
						string id = token;
						char a[NameLen];
						strcpy(a, token);
						if (check_id_exist(token) > 0) {
							//string id_;
							if (symtable[id_index].level == 0) {
								id_ = replace_global();
							}
							else id_ = id;
						}
						sym = sym_to_str(symtable[id_index].sym);
						genmidcode('s', "scan", id_, sym);
						get_symbol(infile, &symbol);
					}
				}
				if (symbol == rparSY) {
					get_symbol(infile, &symbol);
					if (symbol == semiSY) {
						//printf("it is a scanf statementat line %d\n", cur_line);
						get_symbol(infile, &symbol);
						//return;
					}
					else {
						error(SEMI_ERROR);
					}
				}
				else {
					error(RPAR_ERRO);
					get_symbol(infile, &symbol);
					if (symbol == semiSY) {
						//printf("it is a scanf statementat line %d\n", cur_line);
						get_symbol(infile, &symbol);
						//return;
					}
					else {
						error(SEMI_ERROR);
					}
				}

			}
		}
	}
	else if (symbol == printfSY) {
		get_symbol(infile, &symbol);
		int achar = 0;
		if (symbol == lparSY) {
			get_symbol(infile, &symbol);
			if (symbol == dqSY) {
				string dq = "\"", str;
				string str0 = dq + "\\n" + dq;
				get_symbol(infile, &symbol);
				if (symbol == StrSY) {
					str = dq + token + dq;
					//genmidcode('w', "print", str0, "0");
					genmidcode('w', "print", str, "0");
					get_symbol(infile, &symbol);
					if (symbol == dqSY) {
						get_symbol(infile, &symbol);
						if (symbol == comSY) {
							get_symbol(infile, &symbol);
							string e = Expression_print(achar);
							stringstream ss;
							ss << achar;
							//genmidcode('w', "print", str0, "0");
							genmidcode('w', "print", e, ss.str());
						}
					}
				}
			}
			else {
				string e = Expression_print(achar);
				stringstream ss;
				ss << achar;
				genmidcode('w', "print", e, ss.str());
			}
			if (symbol == rparSY) {
				get_symbol(infile, &symbol);
				if (symbol == semiSY) {
					//printf("it is a print statement");
					get_symbol(infile, &symbol);
				}
				else {
					error(SEMI_ERROR);
				}
			}
		}
	}

}
void Statement_column() {    //语句列

	while (isStatement()) {
		statement();
	}
	//printf("it is a Statement column\n");
}
void variable_description(int falg) {
	int i = 0;
	//symToken[i++]////////////
	while (symbol == intSY || symbol == charSY) {
		mid_tmp_op();
		symtmp.level = fun_level;
		symtmp.value = "";
		symtmp.symtyp = varibletype;
		midtmp.op = 'v';
		midtmp.B = "";
		get_symbol(infile, &symbol);
		if (symbol == idSY) {
			strcpy(symtmp.name, token);
			midtmp.A = token;
			//inserttab();
			get_symbol(infile, &symbol);
			if (symbol == lbrkSY) {
				get_symbol(infile, &symbol);
				if (isUnsint()) {
					midtmp.B = UINTtoken;
					symtmp.length = atoi(UINTtoken);
					symtmp.symtyp = arraytype;
					get_symbol(infile, &symbol);
					if (symbol == rbrkSY) {
						get_symbol(infile, &symbol);
					}
				}
			}
			if (check_id()) {
				symtable.push_back(symtmp);
				midcode.push_back(midtmp);
				symtmp.symtyp = varibletype;
				symtmp.length = 0;
				midtmp.B = "";
			}
			while (symbol == comSY) {
				get_symbol(infile, &symbol);
				if (symbol == idSY) {
					//inserttab();
					strcpy(symtmp.name, token);
					midtmp.A = token;
					get_symbol(infile, &symbol);
					if (symbol == lbrkSY) {
						get_symbol(infile, &symbol);
						if (isUnsint()) {
							//inserttab();填入数组信息
							midtmp.B = UINTtoken;
							symtmp.length = atoi(UINTtoken);
							symtmp.symtyp = arraytype;
							get_symbol(infile, &symbol);
							if (symbol == rbrkSY) {
								get_symbol(infile, &symbol);
							}
							else {
								error(LBRACKET_ERROR);
							}
						}
					}
					if (check_id()) {
						symtable.push_back(symtmp);
						midcode.push_back(midtmp);
						symtmp.symtyp = varibletype;
						symtmp.length = 0;
						midtmp.B = "";
					}
				}
			}
			if (symbol == semiSY) {    //一行变量定义
				get_symbol(infile, &symbol);
			}
			else {
				error(SEMI_ERROR);
				get_symbol(infile, &symbol);
			}
		}
	}
	//printf("it is a local variable descriptionat line %d\n", cur_line);

}

void Compound_statement() {        //复合语句=［＜常量说明＞］［＜变量说明＞］＜语句列＞
	get_symbol(infile, &symbol);
	Constant_description(LOCAL);
	if (symbol == intSY || symbol == charSY) {
		variable_description(LOCAL);
	}
	Statement_column();  //语句列


}   //

void function(string s) {
	midtmp.B = "";
	while (symToken[0] == intSY || symToken[0] == charSY || symbol == voidSY || symbol == charSY || symbol == intSY) {
		//insert_functionTab()
		if (symToken[0] == intSY || symToken[0] == charSY) {
			//func_id=symToken[1]; //此时左括号已读入
			if (symToken[0] == intSY) {
				midtmp.C = "int";
				symtmp.sym = intSY;
			}
			else {
				midtmp.C = "char";
				symtmp.sym = charSY;
			}
			symtmp.level = ++fun_level;
			symtmp.length = 0;
			symtmp.value = "";
			symtable.push_back(symtmp);
			fun_p = symtable.size() - 1;   //记录函数名再符号表中的位置
			get_symbol(infile, &symbol);
			midtmp.op = 'f';
			midtmp.B = "";
			midcode.push_back(midtmp);
			clearToken(symToken, SymT_Maxlen);
			Parameter_table();
		}

		else if (symbol == voidSY || symbol == charSY || symbol == intSY) {
			mid_tmp_op();
			midtmp.op = 'f';
			symtmp.symtyp = functiontype;
			symtmp.level = ++fun_level;
			get_symbol(infile, &symbol);
			if (symbol == idSY) {
				//insert_functionTab()
				midtmp.A = token;
				midtmp.B = "";
				midcode.push_back(midtmp);
				strcpy(symtmp.name, token);
				//symtmp.level = fun_level++;
				symtmp.value = "";
				symtable.push_back(symtmp);
				fun_p = symtable.size() - 1;
				get_symbol(infile, &symbol);
				if (symbol == lparSY) {
					get_symbol(infile, &symbol);
					Parameter_table();
				}
			}
			else break;
		}
		printf("it is a function\n at line %d\n", cur_line);
		genmidcode('r', "return", "", "");
		if (symbol != rbreSY) {
			error(RBRE_ERROR);
		}
		get_symbol(infile, &symbol);
	}
	if (symbol == mainSY) {
		midtmp.C = "void";
		midtmp.A = "main";
		midtmp.op = 'f';
		midtmp.B = "";
		midcode.push_back(midtmp);
		symtmp.symtyp = functiontype;
		//symtmp.level = ++fun_level;
		symtmp.value = "";
		strcpy(symtmp.name, "main");
		symtable.push_back(symtmp);
		fun_p = symtable.size() - 1;

		get_symbol(infile, &symbol);
		if (symbol == lparSY) {
			get_symbol(infile, &symbol);
			Parameter_table();
		}
		//printf("it is a main function\n");
		if (symbol != rbreSY) {
			error(RBRE_ERROR);
		}
		genmidcode('r', "return", "", "");
		get_symbol(infile, &symbol);
	}


}
void Variable_function() {

	while (symbol == intSY || symbol == charSY) {
		int i = 0;
		//a = a + black;
		mid_tmp_op();
		symToken[i++] = symbol;  //i=0
		symtmp.level = 0;
		get_symbol(infile, &symbol);

		if (symbol == idSY) {
			strcpy(symtmp.name, token);
			string a = token;
			//b = a + token;
			midtmp.A = token;  //name
			strcpy(symtmp.name, token);
			symToken[i++] = symbol;  //i=1
			get_symbol(infile, &symbol);
			if (symbol == lbrkSY || symbol == comSY || symbol == semiSY) {    //[ , ; 说明为变量,   符号表
				midtmp.op = 'v';
				symtmp.value = "";
				if (symbol == comSY) {
					symtmp.symtyp = varibletype;
					symtmp.length = 0;
					if (check_id()) {
						symtable.push_back(symtmp);
						midtmp.B = "";
						midcode.push_back(midtmp);
						get_symbol(infile, &symbol);
					}
				}
				else if (symbol == semiSY) {
					symtmp.symtyp = varibletype;
					symtmp.value = "";
					symtmp.length = 0;
					if (check_id()) {
						symtable.push_back(symtmp);
						midtmp.op = 'v';
						midtmp.B = "";
						midcode.push_back(midtmp);
					}
				}

				while (symbol != semiSY) {
					symtmp.symtyp = varibletype;
					if (symbol == lbrkSY) {
						symtmp.symtyp = arraytype;
						get_symbol(infile, &symbol);
						if (isUnsint()) {
							symtmp.length = atoi(UINTtoken);
							midtmp.B = UINTtoken;
							get_symbol(infile, &symbol);
							if (symbol == rbrkSY) {
								symtmp.value = "";
								if (check_id()) {
									symtable.push_back(symtmp);
									midcode.push_back(midtmp);
									get_symbol(infile, &symbol);
									if (symbol == comSY)
										get_symbol(infile, &symbol);
								}
							}
						}
					}
					else if (symbol == idSY) {
						strcpy(symtmp.name, token);
						midtmp.A = token;
						get_symbol(infile, &symbol);
						if (symbol == lbrkSY) {
							symtmp.symtyp = arraytype;
							get_symbol(infile, &symbol);
							if (isUnsint()) {
								symtmp.length = atoi(UINTtoken);
								midtmp.B = UINTtoken;
								get_symbol(infile, &symbol);
								if (symbol == rbrkSY) {
									get_symbol(infile, &symbol);
								}
							}
						}
						else {
							symtmp.symtyp = varibletype;
							symtmp.length = 0;
							midtmp.B = "";
						}
						if (check_id()) {
							symtable.push_back(symtmp);
							midcode.push_back(midtmp);
							if (symbol == comSY)
								get_symbol(infile, &symbol);
						}
					}

				}

				//printf("it is a variable discription\n");
				get_symbol(infile, &symbol);
			}
			else if (symbol == lparSY) {    //函数
				//b = b + token;
				symtmp.symtyp = functiontype;
				function(a);
			}
			else {
				error(SEMI_ERROR);
			}

		}
		//////////////////////////////////////////////////////////////////////////////
		else {
			error(ID_ERROR);
			while (symbol != lparSY && symbol != semiSY && symbol != comSY);
			{
				get_symbol(infile, &symbol);
			}
		}

	}
	if (symbol == voidSY) {
		string a = token;
		symtmp.sym = symbol;
		symtmp.symtyp = functiontype;
		clearToken(symToken, SymT_Maxlen);
		function(a);
	}
}

void Grammatical_analysis() {
	Constant_description(GLOBAL);
	Variable_function();

}
void print_midcode() {
	unsigned int i = 0;
	string space = " ";
	while (i < midcode.size()) {
		if (midcode[i].op == 'c') {
			cout << "const";
			cout << " ";
			cout << midcode[i].C;
			cout << " ";
			cout << midcode[i].A;
			cout << " ";
			cout << "=";
			cout << " ";
			cout << midcode[i].B << endl;
		}
		else if (midcode[i].op == 'v') {
			cout << "var";
			cout << " ";
			cout << midcode[i].C;
			cout << " ";
			cout << midcode[i].A;
			if (midcode[i].B != "") {
				cout << "[";
				cout << midcode[i].B;
				cout << "]";
			}
			cout << endl;
		}
		else if (midcode[i].op == 'f') {
			cout << midcode[i].C;
			cout << " ";
			cout << midcode[i].A << endl;
		}
		else if (midcode[i].op == 'p') {
			cout << "para";
			cout << space;
			cout << midcode[i].C;
			cout << space;
			cout << midcode[i].A << endl;
		}
		else if (midcode[i].op == 'a') {
			cout << midcode[i].A;
			cout << space;
			cout << "=";
			cout << space;
			cout << midcode[i].B;
			cout << "[";
			cout << midcode[i].C;
			cout << "]" << endl;
		}
		else if (midcode[i].op == 'b') {
			cout << midcode[i].A;
			cout << space;
			cout << midcode[i].B;
			cout << space;
			cout << midcode[i].C << endl;
		}
		else if (midcode[i].op == 'd') {
			cout << "push";
			cout << space;
			cout << midcode[i].A << endl;
		}
		else if (midcode[i].op == 'e' || midcode[i].op == 'g') {
			cout << midcode[i].A;
			cout << space;
			cout << "=";
			cout << space;
			cout << midcode[i].B << endl;
		}
		else if (midcode[i].op == 'h') {
			if (midcode[i].B != "") {
				cout << midcode[i].A;
				cout << space;
				cout << midcode[i].B;
				cout << space;
				cout << midcode[i].C << endl;
			}
		}
		else if (midcode[i].op == 'j') {
			cout << midcode[i].A;
			cout << space;
			cout << midcode[i].B << endl;
		}
		else if (midcode[i].op == 'k') {
			cout << midcode[i].A;
			if (midcode[i].B != "") {
				cout << "[";
				cout << midcode[i].B;
				cout << "]";
				cout << space;
				cout << "=";
				cout << space;
				cout << midcode[i].C << endl;
			}
			else {
				cout << space;
				cout << "=";
				cout << space;
				cout << midcode[i].C << endl;
			}
		}
		else if (midcode[i].op == 'l') {
			cout << midcode[i].A;
			cout << midcode[i].B << endl;
		}
		else if (midcode[i].op == 'r') {
			cout << midcode[i].A;
			cout << space;
			cout << midcode[i].B << endl;
		}
		else if (midcode[i].op == 'w') {
			cout << midcode[i].A;
			cout << space;
			cout << midcode[i].B;
			cout << space;
			cout << midcode[i].C << endl;
		}
		else if (midcode[i].op == 's') {
			cout << midcode[i].A;
			cout << space;
			cout << midcode[i].C;
			cout << space;
			cout << midcode[i].B << endl;

		}
		else if (midcode[i].op == '+' || midcode[i].op == '-' || midcode[i].op == '*' || midcode[i].op == '/') {
			cout << midcode[i].A;
			cout << space;
			cout << "=";
			cout << space;
			cout << midcode[i].B;
			cout << space;
			cout << midcode[i].op;
			cout << space;
			cout << midcode[i].C << endl;
		}

		i++;
	}
}
void mips_globl() {
	unsigned int i = 0, num = 0;
	cout << ".align 2" << endl;
	for (i = 0; i < midcode.size() && midcode[i].op != 'f'; i++) {
		if (midcode[i].op == 'c') {
			stringstream ss, ssn;
			if (midcode[i].C == "int") {  //const int max=1
				ssn << "*gl" << num;
				ss << "ggl" << num++ << ": .word " << midcode[i].B;
				cout << ss.str() << endl;
				midcode[i].A = ssn.str();
			}
			else if (midcode[i].C == "char") {   //const char A='a'
				//int c = midcode[i].B[0];
				ssn << "*gl" << num;
				ss << "ggl" << num++ << ": .word " << midcode[i].B;
				cout << ss.str() << endl;
				midcode[i].A = ssn.str();
			}
		}
		else if (midcode[i].op == 'v') {
			stringstream ss, ssn;
			if (midcode[i].C == "int") {  //var int
				if (midcode[i].B == "") {  //var int A
					ssn << "*gl" << num;
					ss << "ggl" << num++ << ": .word ";
					cout << ss.str() << 0 << endl;
					midcode[i].A = ssn.str();
				}
				else {  //var int array[100]
					int length;
					stringstream len, ss;
					len << midcode[i].B;
					len >> length;
					length = length * 4;
					ssn << "*gl" << num;
					ss << "ggl" << num++ << ": .space " << length;
					cout << ss.str() << endl;
					midcode[i].A = ssn.str();
				}
			}
			else if (midcode[i].C == "char") {   //var char
				if (midcode[i].B == "") {  //var char A
					ssn << "*gl" << num;
					ss << "ggl" << num++ << ": .word ";
					cout << ss.str() << 0 << endl;
					midcode[i].A = ssn.str();
				}
				else {  //var char array[100]
					int length;
					stringstream len, ss, ssn;
					len << midcode[i].B;
					len >> length;
					length *= 4;
					ssn << "*gl" << num;
					ss << "ggl" << num++ << ": .space " << length;
					cout << ss.str() << endl;
					midcode[i].A = ssn.str();
				}
			}
		}
	}
}
void mips_str() {
	unsigned int i = 1, b = 1;
	string dq = "\"", str;
	string str0 = dq + "\\n" + dq;
	stringstream ss0;
	ss0 << "sstr0: .asciiz " << str0;
	cout << ss0.str() << endl;
	for (i = 0; i < midcode.size(); i++) {
		if (midcode[i].op == 'w' && midcode[i].B[0] == '\"') {
			if (midcode[i].B != str0) {
				stringstream ss;
				string str_rename = "*str" + to_string(b);
				ss << "sstr" << b++ << ": .asciiz " << midcode[i].B;
				cout << ss.str() << endl;
				midcode[i].B = str_rename;
			}
		}
	}
}
void instack(vector<run_stack>* func_runstack, string name, int cap)
{
	int x1 = (*func_runstack).size();
	for (int i = 0; i < x1; i++)
	{
		if ((*func_runstack)[i].name == name)
			return;
	}
	run_stack tmp;
	tmp.name = name;
	if (x1 == 0)
		tmp.addr = cap;
	else
		tmp.addr = cap + (*func_runstack)[x1 - 1].addr;
	(*func_runstack).push_back(tmp);
}
string getaddr(string name, string index2 = "-1")
{
	stringstream ss;
	int index;
	ss << index2;
	ss >> index;
	if (name[0] == '*'&&name[1] == 's')
	{
		name[0] = name[1];
		return name;
	}
	if (name[0] == '*'&&name[1] == 'g')
	{
		name[0] = name[1];
		if (index == -1)
			return name;
		else
		{
			return name + "+" + to_string(index * 4);
		}
	}
	int tmp = (*cur_func_runstack).back().addr;
	int vir = 0;
	for (int i = 0; i < (*cur_func_runstack).size(); i++)
	{
		if ((*cur_func_runstack)[i].name == name)
		{
			vir = (*cur_func_runstack)[i].addr;
			break;
		}
	}
	if (index == -1)
		return (to_string(4 + tmp - vir) + "($sp)");
	else if (index == -2)
		return to_string(4 + tmp - vir);
	else
		return (to_string(4 + tmp - (vir - 4 * index)) + "($sp)");
}

void mips_fun(int func_begin, int func_end) {
	//计算每个函数栈空间
	int push_cot = 0;
	vector<run_stack> func_runstack;
	string A = midcode[func_begin].A;
	if (A != "main")A[0] = A[1];
	cout << A << ":\n";
	unsigned int j;
	for (j = func_begin + 1; j < func_end; j++) {
		char op = midcode[j].op;
		string A = midcode[j].A;
		string B = midcode[j].B;
		string C = midcode[j].C;
		if (op == 'c' || op == 'v' || op == 'p') {
			if (op == 'v') {
				if (B != "") {
					stringstream ss;
					int B_int;
					ss << B;
					ss >> B_int;
					instack(&func_runstack, A, B_int * 4);
				}
				else
					instack(&func_runstack, A, 4);
			}
			else
			{
				instack(&func_runstack, A, 4);
			}
		}
		else if (A[0] == '$')
		{
			instack(&func_runstack, A, 4);
		}
	}
	cur_func_runstack = &func_runstack;
	//翻译函数
	if (func_runstack.empty())
		cout << "subi $sp,$sp,4" << endl;
	else
		cout << "subi $sp,$sp," << (func_runstack.back().addr + 4) << endl;
	cout << "sw $ra,($sp)" << endl;
	for (j = func_begin; j < func_end; j++) {
		char op = midcode[j].op;
		string A = midcode[j].A;
		string B = midcode[j].B;
		string C = midcode[j].C;
		if (op == 'j'&&A == "BZ")
		{
			if (midcode[j - 1].A == "0")
				cout << "add $t1,$0,$0" << endl;
			else if (midcode[j - 1].A[0] == '-' || midcode[j - 1].A[0] == '+' || '0' <= (midcode[j - 1].A[0]) && (midcode[j - 1].A[0]) <= '9')
				cout << "addi $t1,$0," << midcode[j - 1].A << endl;
			else
				cout << "lw $t1," << getaddr(midcode[j - 1].A) << endl;
			if (midcode[j - 1].C == "0")
				cout << "add $t2,$0,$0" << endl;
			else if (midcode[j - 1].C[0] == '+' || midcode[j - 1].C[0] == '-' || '0' <= (midcode[j - 1].C[0]) && (midcode[j - 1].C[0]) <= '9')
				cout << "addi $t2,$0," << midcode[j - 1].C << endl;
			else
				cout << "lw $t2," << getaddr(midcode[j - 1].C) << endl;
			string tmp = midcode[j - 1].B;
			if (tmp == "<") {
				cout << "bge ";
			}
			else if (tmp == "<=") {
				cout << "bgt ";
			}
			else if (tmp == ">") {
				cout << "ble ";
			}
			else if (tmp == ">=") {
				cout << "blt ";
			}
			else if (tmp == "!=") {
				cout << "beq ";
			}
			else if (tmp == "==") {
				cout << "bne ";
			}

			B[0] = B[1];
			cout << "$t1,$t2," << B << endl;
		}
		else if (op == 'j'&&A == "GOTO")
		{
			B[0] = B[1];
			cout << "j " << B << endl;
		}
		else if (op == 'l')
		{
			A[0] = A[1];
			cout << A << ":" << endl;
		}
		else if (op == 'a')
		{
			if (C[0] == '+')
				C[0] = '0';
			if (C[0] == '-' || C[0] >= '0'&&C[0] <= '9')
				cout << "lw $s0," << getaddr(B, C) << endl;
			else
			{
				cout << "lw $t0," << getaddr(C) << endl << "mul $t0,$t0,4" << endl;
				if (B[0] == '*'&&B[1] == 'g')
				{
					B[0] = B[1];
					cout << "lw $s0," << B << "($t0)" << endl;
				}
				else
				{
					cout << "add $t0,$t0," << getaddr(B, "-2") << endl << "add $t0,$t0,$sp\n" << "lw $s0,($t0)" << endl;
				}
			}
			cout << "sw $s0," << getaddr(A) << endl;
		}
		else if (op == 'b'&&A != "call")
		{
			cout << "sw $v1," << getaddr(A) << endl;
		}
		else if (op == 'e')
		{
			cout << "lw $s1," << getaddr(B) << endl;
			//cout<<A<<endl;
			cout << "sw $s1," << getaddr(A) << endl;
		}
		else if (op == 'g')
		{
			cout << "li $s1," << B << endl;
			cout << "sw $s1," << getaddr(A) << endl;
		}
		else if (op == 'k')
		{
			if (B == "")
			{
				cout << "lw $s1," << getaddr(C) << endl;
				cout << "sw $s1," << getaddr(A) << endl;
			}
			else {
				if (C[0] == '+')
					C[0] = '0';
				cout << "lw $s1," << getaddr(C) << endl;
				if (C[0] == '-' || C[0] >= '0'&&C[0] <= '9')
					cout << "sw $s1," << getaddr(A, B) << endl;
				else
				{
					cout << "lw $t0," << getaddr(B) << endl << "mul $t0,$t0,4" << endl;
					if (A[0] == '*'&&A[1] == 'g')
					{
						A[0] = A[1];
						cout << "sw $s1," << A << "($t0)" << endl;
					}
					else
					{
						cout << "add $t0,$t0," << getaddr(A, "-2") << endl << "add $t0,$t0,$sp" << endl << "sw $s1,($t0)" << endl;
					}
				}
			}
		}
		else if (op == '+')
		{
			cout << "lw $s1," << getaddr(C) << endl;
			cout << "lw $s2," << getaddr(B) << endl;
			cout << "add $s2,$s2,$s1" << endl;
			cout << "sw $s2," << getaddr(A) << endl;;
		}
		else if (op == '-')
		{

			cout << "lw $s1," << getaddr(C) << endl;
			if (B == "0")
				cout << "add $s2,$0,$0" << endl;
			else
				cout << "lw $s2," << getaddr(B) << endl;
			cout << "sub $s2,$s2,$s1" << endl;
			cout << "sw $s2," << getaddr(A) << endl;;
		}
		else if (op == '*')
		{
			cout << "lw $s1," << getaddr(C) << endl;
			cout << "lw $s2," << getaddr(B) << endl;
			cout << "mul $s2,$s2,$s1" << endl;
			cout << "sw $s2," << getaddr(A) << endl;;
		}
		else if (op == '/')
		{
			cout << "lw $s1," << getaddr(C) << endl;
			cout << "lw $s2," << getaddr(B) << endl;
			cout << "div $s2,$s2,$s1" << endl;
			cout << "sw $s2," << getaddr(A) << endl;;
		}
		else if (op == 'd')
		{
			push_cot++;
			cout << "lw $t1," << getaddr(A) << endl;
			cout << "subi $sp,$sp," << to_string(4 * push_cot) << endl;
			cout << "sw $t1,($sp)" << endl;
			cout << "addi $sp,$sp," << to_string(4 * push_cot) << endl;
		}
		else if (op == 'b'&&A == "call")
		{
			//vector<symtable>* tmp_func=find_func_table(midcode[i].str1);
			int p_n;
			stringstream ss;
			ss << C;
			ss >> p_n;
			push_cot -= p_n;///函数参数个数
			cout << "subi $sp,$sp," << (push_cot * 4) << endl;
			if (B != "main")B[0] = B[1];
			cout << "jal " << B << endl;
			cout << "addi $sp,$sp," << (push_cot * 4) << endl;
		}
		else if (op == 'r')
		{
			if (B == "");
			else
			{
				cout << "lw $v1," << getaddr(B) << endl;
			}
			cout << "lw $ra,($sp)" << endl << "addi $sp,$sp,";
			if (func_runstack.empty())
				cout << 4 << endl;
			else
				cout << (func_runstack.back().addr + 4) << endl;
			if (func_end != midcode.size())
				cout << endl << "jr $ra" << endl;
		}
		else if (op == 's')
		{
			cout << "li $v0,4" << endl << "la $a0,sstr0" << endl << "syscall" << endl;
			if (C == "char")
			{
				cout << "li $v0,12\nsyscall\n" << endl;
				cout << "sw $v0," << getaddr(B) << endl;
			}
			else
			{
				cout << "li $v0,5\nsyscall\n" << endl;
				cout << "sw $v0," << getaddr(B) << endl;
			}
		}
		else if (op == 'w')
		{
			cout << "li $v0,4" << endl << "la $a0,sstr0" << endl << "syscall" << endl;
			if (B[0] == '*'&&B[1] == 's')
			{
				cout << "li $v0,4" << endl;
				cout << "la $a0," << getaddr(B) << endl << "syscall\n";
			}
			else if (C[0] == '1')
			{
				cout << "li $v0,11" << endl;
				cout << "lw $a0," << getaddr(B) << endl << "syscall" << endl;
			}
			else
			{
				//cout<<C<<endl;
				cout << "li $v0,1" << endl;
				cout << "lw $a0," << getaddr(B) << endl << "syscall" << endl;
			}
		}
		else if (op == 'c')
		{
			cout << "li $s0," << B << endl;
			cout << "sw $s0," << getaddr(A) << endl;
		}
	}
}
/*
void mips_fun() {
	cout << ".text" << endl;
	unsigned int i = 0, j = 0, fun_num = 0;

	for (i = 0; i < midcode.size(); i++) {
		if (midcode[i].op == 'f' && midcode[i].A != "main") {
			stringstream ss;
			functmp.fun_begin = i;
			functmp.func_name = midcode[i].A;
			ss << "*fun" << fun_num++  ;
			functmp.func_rename = midcode[i].A;
			midcode[i].A = ss.str();

			func.push_back(functmp);
		}
		else if (midcode[i].op == 'f' && midcode[i].A == "main") {
			functmp.fun_begin = i;
			functmp.func_name = midcode[i].A;
			functmp.func_rename = midcode[i].A;
			func.push_back(functmp);
		}
	}

	//将midcode中函数换名
	for (i = 0; i < midcode.size(); i++) {
		if (midcode[i].op == 'b' || midcode[i].op == 'd') {
			if (midcode[i].B != "ret") {
				for (j = 0; j < func.size(); j++) {
					if (func[j].func_name == midcode[i].B) {
						midcode[i].B = func[j].func_rename;
					}
				}
			}
		}
	}

	//计算每个函数栈空间
	for (i = 0; i < func.size() - 1; i++) {
		for (j = func[i].fun_begin; j < func[i + 1].fun_begin; j++) {
			char op = midcode[j].op;
			string A = midcode[j].A;
			string B = midcode[j].B;
			string C = midcode[j].C;
			if (op == 'c' || op == 'v') {

			}
		}
	}

	//翻译函数
	for (i = 0; i < func.size()-1; i++) {
		for (j = func[i].fun_begin; j < func[i+1].fun_begin; j++) {
			char op = midcode[j].op;
			string A = midcode[j].A;
			string B = midcode[j].B;
			string C = midcode[j].C;
			if (op == 'f') {
				cout << A << ":" << endl;
			}


		}
	}
}
*/
void mips_data() {
	cout << ".data" << endl;
	mips_str();
	mips_globl();

}
void gen_mips() {
	freopen("mips.txt", "w", stdout);
	cout << ".globl main" << endl;
	mips_data();  //
	cout << ".text" << endl;
	unsigned int i = 0, j = 0, fun_num = 0;

	for (i = 0; i < midcode.size(); i++) {
		if (midcode[i].op == 'f' && midcode[i].A != "main") {
			functmp.fun_begin = i;
			functmp.func_name = midcode[i].A;
			stringstream ss;
			ss << "*fun" << fun_num++;
			midcode[i].A = ss.str();
			functmp.func_rename = midcode[i].A;
			func.push_back(functmp);
		}
		else if (midcode[i].op == 'f' && midcode[i].A == "main") {
			functmp.fun_begin = i;
			functmp.func_name = midcode[i].A;
			functmp.func_rename = midcode[i].A;
			func.push_back(functmp);
		}
	}

	//将midcode中函数换名
	for (i = 0; i < midcode.size(); i++) {
		if (midcode[i].op == 'b' || midcode[i].op == 'd') {
			if (midcode[i].B != "ret") {
				for (j = 0; j < func.size(); j++) {
					if (func[j].func_name == midcode[i].B) {
						midcode[i].B = func[j].func_rename;
					}
				}
			}
		}
	}
	for (i = 0; i < func.size() - 1; i++) {
		mips_fun(func[i].fun_begin, func[i + 1].fun_begin);
	}
	int end_num = func.size() - 1;
	mips_fun(func[end_num].fun_begin, midcode.size());
}
int main() {

	//freopen("分析.txt", "w", stdout);
	char infilePath[PathcLen];// = "test.txt";
	scanf("%s", infilePath);
	infile = fopen(infilePath, "r");
	//lexical_analysis(infile);
	//语法分析
	get_symbol(infile, &symbol);
	Grammatical_analysis();



	freopen("mips.txt", "w", stdout);
	gen_mips();

	freopen("中间代码.txt", "w", stdout);
	print_midcode();

	freopen("中间代码结构.txt", "w", stdout);
	unsigned int i = 0;
	/*
	while (midcode[i].op != 'f') {
		cout << midcode[i].op;
		cout << " ";
		stringstream ss;
		ss << "*gl" << i  ;
		cout << ss.str();
		cout << " ";
		cout << midcode[i].B;
		cout << " ";
		cout << midcode[i].C << endl;

		i++;
	}
	*/
	while (i < midcode.size()) {
		cout << midcode[i].op;
		cout << " ";
		cout << midcode[i].A;
		cout << " ";
		cout << midcode[i].B;
		cout << " ";
		cout << midcode[i].C << endl;

		i++;
	}
	unsigned int j = 0;
	while (j < symtable.size()) {
		cout << symtable[j].name;
		cout << " ";
		cout << symtable[j].symtyp;
		cout << " ";
		cout << symtable[j].sym;
		cout << " ";
		cout << symtable[j].length;
		cout << " ";
		cout << symtable[j].level;
		cout << " ";
		cout << symtable[j++].value << endl;
	}


	return 0;
}
