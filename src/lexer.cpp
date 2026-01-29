#include <string>
#include <lexer.h>
#include <iostream>
#include <unordered_set>

std::string Identifier = "";
double numVal = 0;
int line = 0;
std::unordered_set<char> OPERATORS = { '+','-','/','*','=','>','<','(',')','{','}' };



Token getToken() {
	int lastChar = ' ';
  while(isspace(lastChar))
		lastChar = getchar();
  
  std::cout <<  static_cast<char>(lastChar) <<std::endl;	
	if (lastChar == "\r" || lastChar == "\n")
		line++;

	if (isalpha(lastChar)){
	
    Identifier = lastChar;
		
    while(isalnum(lastChar=getchar()))
				Identifier += lastChar;
		
    if (Identifier == "func")
			return Token { tokenType::FUNC, Identifier, line };
		
    return Token { tokenType::ID, Identifier, line };

  }

	if (isdigit(lastChar)) {
	
    std::string strNum;
		
    do { 
		
      strNum += lastChar;
			lastChar = getchar();
		
    } while(isdigit(lastChar));
    
    if (lastChar == ".") {
		
      if (isdigit(lastChar = getchar())) {
			
        do { 
					strNum += lastChar;
					lastChar = getchar();
				
        } while(isdigit(lastChar));
			
      } else 
				return Token { tokenType::ERROR, ("Lexic error at line" + std::to_string(line) + " . Malformed Number"), line };
			
	  }
		numVal = strtod(strNum.c_str(),0);
		return Token { tokenType::NUM, strNum, line };
  }
	if (lastChar == "#"){
		do { lastChar = getchar(); } while (lastChar != EOF && lastChar != "/n" && lastChar != "/r");
		
    if (lastChar != EOF)
			return getToken();
  }
	if (lastChar == EOF)
    return Token { tokenType::EOF_TOKEN, "", line };
	
  if (OPERATORS.contains(lastChar))
    return Token{ tokenType::OPERATOR, std::string(1, static_cast<char>(lastChar)), line };
  
  return Token{ tokenType::ERROR, ("Lexic error: Unrecognizable token at line " + line), line};
}


std::string tokenTypeToString(tokenType type) {
	switch (type) {
		case tokenType::EOF_TOKEN: return "EOF_TOKEN";
		case tokenType::ID: return "ID";
		case tokenType::NUM: return "NUM";
		case tokenType::FUNC: return "func";
    case tokenType::OPERATOR: return "OPERATOR";
	}
	return "NONE";

}
