#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <unordered_set>
enum class tokenType {
	EOF_TOKEN,
	NUM,
	FUNC,
	ID,
  OPERATOR,
	ERROR

};

struct Token{
	tokenType type;
	std::string lexeme;
	int line;

};


extern std::string Identifier;
extern double numVal;
extern std::unordered_set<char> OPERATORS;
Token getToken();
std::string tokenTypeToString(tokenType type);
#endif
