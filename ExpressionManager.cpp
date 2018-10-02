
#include "ExpressionManager.h"
#include <iostream>
#include <string>

using namespace std;

bool ExpressionManager::isBalanced(string expression){
  char charSet;
  while(!stackOfChars.empty()){
    stackOfChars.pop();
  }
  for (int i=0; i < expression.length(); i++){
    if(expression.at(i) == '(' || expression.at(i) == '[' || expression.at(i) == '{'){
      stackOfChars.push(expression.at(i));
      cout << stackOfChars.top() << " ";
    }
    else if(expression.length() <= 1){
      return false;
    }
    else if(expression.at(i) == ')' || expression.at(i) == ']' || expression.at(i) == '}'){
      cout << expression.at(i) << " ";
      if(stackOfChars.top() == '(' && expression.at(i) == ')'){
        stackOfChars.pop();
        if(stackOfChars.empty()){
          return true;
        }
      } else if(stackOfChars.top() == '[' && expression.at(i) == ']'){
        stackOfChars.pop();
        if(stackOfChars.empty()){
          return true;
        }
      } else if(stackOfChars.top() == '{' && expression.at(i) == '}'){
        stackOfChars.pop();
        if(stackOfChars.empty()){
          return true;
        }
      } else{
        return false;
      }
    }
  }
  cout << endl;
}

string ExpressionManager::postfixToInfix(string postfixExpression){

}

string ExpressionManager::postfixEvaluate(string postfixExpression){

}

string ExpressionManager::infixToPostfix(string infixExpression){

}
