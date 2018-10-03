
#include "ExpressionManager.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <cctype>

using namespace std;

bool ExpressionManager::isBalanced(string expression){
  stringstream ss;
  string expressionString;
  stack<string> stackOfChars;
  ss << expression;
  while(ss >> expressionString){
    if(expressionString == "(" || expressionString == "{" || expressionString == "["){
      stackOfChars.push(expressionString);
    }else if(expressionString == ")" || expressionString == "}" || expressionString == "]"){
      if(stackOfChars.empty()){
        return false;
      }
      if(stackOfChars.top() == "(" && expressionString == ")"){
        stackOfChars.pop();
      }
      else if(stackOfChars.top() == "{" && expressionString == "}"){
        stackOfChars.pop();
      }
      else if(stackOfChars.top() == "[" && expressionString == "]"){
        stackOfChars.pop();
      }else{
        return false;
      }
    }
  }
  if(!stackOfChars.empty()){
    return false;
  }
  return true;
}

string ExpressionManager::postfixToInfix(string postfixExpression){

}

string ExpressionManager::postfixEvaluate(string postfixExpression){
  istringstream buf(postfixExpression);
  istream_iterator<string> beg(buf), end;
  vector<string> postFixVector(beg,end);
  cout << "Original" << endl;
  for(int i = 0; i < postFixVector.size(); i++){
    cout << postFixVector[i] << " ";
  }
  cout << endl;
  int postFixInt;
  cout << "more output" << endl;
  for(int i = 0; i < postFixVector.size(); i++){
    if(postfixExpression[i] == '0' || postfixExpression[i] == '1' ||
    postfixExpression[i] == '2' || postfixExpression[i] == '3' ||
    postfixExpression[i] == '4' || postfixExpression[i] == '5' ||
    postfixExpression[i] == '6' || postfixExpression[i] == '7' ||
    postfixExpression[i] == '8' || postfixExpression[i] == '9'){
      postFixInt = atoi(postFixVector.at(i).c_str());
      stackOfInts.push(postFixInt);
      cout << stackOfInts.top() << " ";
    } else{
      if(postfixExpression[i] == '-'){
        cout << "- ";
      }else if(postfixExpression[i] == '+'){
        cout << "+ ";
      }else if(postfixExpression[i] == '*'){
        cout << "* ";
      }else if(postfixExpression[i] == '/'){
        cout << "/ ";
      }
    }
  }
  cout << endl;

  return newInfix;
}

string ExpressionManager::infixToPostfix(string infixExpression){

}
