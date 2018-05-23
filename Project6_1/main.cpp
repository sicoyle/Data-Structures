
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <exception>
#include <string>

#include"PostFixTreeBuilder.h"


/*
int main() {

  BinaryExpressionBuilder b;

  cout << "Enter expression" << endl;

  std::string expression;
  getline(std::cin, expression);

  BinaryOperationNode *root = b.parse(expression);

  cout << " result = " << root->value();
  return 0;
}
*/

int main() {

  BinaryExpressionBuilder b;

  std::string expression = "1 2 3 4 5 * * * *";

  BinaryOperationNode *root = b.parse(expression);

  std::cout << " result = " << root->value()<< std::endl;


  if (root->value() == 120 ) { std::cout << " Result_1_Correct" << std::endl ;}


  BinaryExpressionBuilder c;

  expression = "1 2 + 3 - 4 5 1  * * * 8 + ";

  root = c.parse(expression);

  std::cout << " result = " << root->value()<< std::endl;

  if (root->value() == 8 ) { std::cout << " Result_2_Correct" << std::endl ;}

  return 0;
}

