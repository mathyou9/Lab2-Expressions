
#include "ExpressionManager.h"
#include <iostream>
#include <string>

using namespace std;

bool ExpressionManager::isBalanced(string expression){
  char charSet;
  for (int i=0; i < expression.length(); i++){
    if(expression.at(i) == '(' || expression.at(i) == '[' || expression.at(i) == '{'){
      stackOfChars.push(expression.at(i));
      cout << stackOfChars.top() << " ";
    }
    else if(expression.length() == 0){
      return false;
    }
    cout << endl;
  }
}

string ExpressionManager::postfixToInfix(string postfixExpression){

}

string ExpressionManager::postfixEvaluate(string postfixExpression){

}

string ExpressionManager::infixToPostfix(string infixExpression){

}
