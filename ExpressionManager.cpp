
#include "ExpressionManager.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <cctype>

using namespace std;

bool ExpressionManager::isBalanced(string expression){
  char charSet;
  cout << "Original";
  cout << endl << expression << endl;
  cout << "length" << expression.length() << endl;
  if(expression.length() <= 1){
    return false;
  }
  cout << "indexed" << endl;
  /*
  if(expression.length() % 2 != 0){
    return false;
  }
  */
  for (int i=0; i < expression.length(); i++){
    if(expression.at(i) == '(' || expression.at(i) == '[' || expression.at(i) == '{'){
      stackOfChars.push(expression.at(i));
      cout << stackOfChars.top() << " ";
    }
    else if(expression.at(i) == ')' || expression.at(i) == ']' || expression.at(i) == '}'){
      cout << expression.at(i) << " ";
      if(stackOfChars.top() == '(' && expression.at(i) == ')'){
        stackOfChars.pop();
        cout << expression.length() << " " << stackOfChars.size() << endl;
        if(expression.length() == 0){
          cout << ") true" << endl;
          return true;
        }
      } else if(stackOfChars.top() == '[' && expression.at(i) == ']'){
        stackOfChars.pop();
        cout << expression.length() << " " << stackOfChars.size() << endl;
        if(expression.length() == 0){
          cout << "] true" << endl;
          return true;
        }
      } else if(stackOfChars.top() == '{' && expression.at(i) == '}'){
        stackOfChars.pop();
        cout << expression.length() << " " << stackOfChars.size() << endl;
        if(expression.length() == 0){
          cout << "} true" << endl;
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
  istringstream buf(postfixExpression);
  istream_iterator<string> beg(buf), end;
  vector<string> postFixVector(beg,end);
  int postFixInt;
  cout << "more output" << endl;
  for(int i = 0; i < postFixVector.size(); i++){
    if(isdigit(postfixExpression[i])){
      postFixInt = atoi(postFixVector.at(i).c_str());
      cout << postFixInt << " ";
    } else{
      if(postfixExpression == '-'){

      }else if(postfixExpression == '+'){

      }else if(postfixExpression == '*'){

      }else if(postfixExpression == '/'){

      }
    }
  }

  return newInfix;
}

string ExpressionManager::infixToPostfix(string infixExpression){

}
