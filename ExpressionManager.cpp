
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
  int math1, math2, mathCombined;
  cout << "Original" << endl;
  for(int i = 0; i < postFixVector.size(); i++){
    cout << postFixVector[i] << " ";
  }
  cout << endl;
  int postFixInt;
  cout << "more output" << endl;
  for(int i = 0; i < postFixVector.size(); i++){
    if(postFixVector.at(i) == "-"){
      cout << "- ";
      math1 = stackOfInts.top();
      stackOfInts.pop();
      math2 = stackOfInts.top();
      stackOfInts.pop();
      mathCombined = math2 - math1;
      stackOfInts.push(mathCombined);
      newInfix = to_string(stackOfInts.top());
      cout << mathCombined << " ";
    }else if(postFixVector.at(i) == "+"){
      cout << "+ ";
      math1 = stackOfInts.top();
      stackOfInts.pop();
      math2 = stackOfInts.top();
      stackOfInts.pop();
      mathCombined = math1 + math2;
      stackOfInts.push(mathCombined);
      newInfix = to_string(stackOfInts.top());
      cout << mathCombined << " ";
    }else if(postFixVector.at(i) == "*"){
      cout << "* ";
      math1 = stackOfInts.top();
      stackOfInts.pop();
      math2 = stackOfInts.top();
      stackOfInts.pop();
      mathCombined = math1 * math2;
      stackOfInts.push(mathCombined);
      newInfix = to_string(stackOfInts.top());
      cout << mathCombined << " ";
    }else if(postFixVector.at(i) == "/"){
      cout << "/ ";
      math1 = stackOfInts.top();
      stackOfInts.pop();
      math2 = stackOfInts.top();
      stackOfInts.pop();
      mathCombined = (int)math2 / (int)math1;
      stackOfInts.push(mathCombined);
      newInfix = to_string(stackOfInts.top());
      cout << mathCombined << " ";
    }else if(postFixVector.at(i) == "%"){
        cout << "% ";
        math1 = stackOfInts.top();
        stackOfInts.pop();
        math2 = stackOfInts.top();
        stackOfInts.pop();
        mathCombined = (int)math2 % (int)math1;
        stackOfInts.push(mathCombined);
        newInfix = to_string(stackOfInts.top());
        cout << mathCombined << " ";
    }
    else if(atoi(postFixVector.at(i).c_str()) >= 0){
      postFixInt = atoi(postFixVector.at(i).c_str());
      stackOfInts.push(postFixInt);
      newInfix = to_string(stackOfInts.top());
      cout << stackOfInts.top() << " ";
    }
    if(stackOfInts.size() < 2){
      newInfix = to_string(stackOfInts.top());
    }
  }
  cout << endl;

  return newInfix;
}

string ExpressionManager::infixToPostfix(string infixExpression){

}
