#include <lexer.h>
#include <string>
#include <iostream>

int main() {
	Token token = getToken();
	std::cout << token.line <<std::endl;
	while ( token.type != tokenType::EOF_TOKEN ) {
		std::cout << "type: " << tokenTypeToString(token.type) << std::endl;
		std::cout << "linha: " << token.line << std::endl;
		std::cout << "lexeme: " << token.lexeme << std::endl;
		token = getToken();
	}
}
