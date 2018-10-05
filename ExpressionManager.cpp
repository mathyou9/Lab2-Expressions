
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
  istringstream buf(postfixExpression);
  istream_iterator<string> beg(buf), end;
  vector<string> postFixToInfixVector(beg,end);
  string number1, number2, insertHere, complete;
  for(int i = 0; i < postFixToInfixVector.size(); i++){
    if(postFixToInfixVector.at(i) == "-"){
      number2 = stackOfFixedChars.top();
      stackOfFixedChars.pop();
      number1 = stackOfFixedChars.top();
      stackOfFixedChars.pop();
      insertHere = "( " + number1 + " - " + number2 + " )";
      stackOfFixedChars.push(insertHere);
    }else if(postFixToInfixVector.at(i) == "+"){
      number2 = stackOfFixedChars.top();
      stackOfFixedChars.pop();
      number1 = stackOfFixedChars.top();
      stackOfFixedChars.pop();
      insertHere = "( " + number1 + " + " + number2 + " )";
      stackOfFixedChars.push(insertHere);
    }else if(postFixToInfixVector.at(i) == "*"){
      number2 = stackOfFixedChars.top();
      stackOfFixedChars.pop();
      number1 = stackOfFixedChars.top();
      stackOfFixedChars.pop();
      insertHere = "( " + number1 + " * " + number2 + " )";
      stackOfFixedChars.push(insertHere);
    }else if(postFixToInfixVector.at(i) == "/"){
      number2 = stackOfFixedChars.top();
      stackOfFixedChars.pop();
      number1 = stackOfFixedChars.top();
      stackOfFixedChars.pop();
      insertHere = "( " + number1 + " / " + number2 + " )";
      stackOfFixedChars.push(insertHere);
    }else if(postFixToInfixVector.at(i) == "%"){
      number2 = stackOfFixedChars.top();
      stackOfFixedChars.pop();
      number1 = stackOfFixedChars.top();
      stackOfFixedChars.pop();
      insertHere = "( " + number1 + " % " + number2 + " )";
      stackOfFixedChars.push(insertHere);
    }else if(atoi(postFixToInfixVector.at(i).c_str()) >= 0){
      stackOfFixedChars.push(postFixToInfixVector.at(i));
    }
  }
  complete = "";
  for(int i = 0; i < stackOfFixedChars.size(); i++){
    complete = complete + stackOfFixedChars.top();
    stackOfFixedChars.pop();
  }
  return complete;
}

string ExpressionManager::postfixEvaluate(string postfixExpression){
  istringstream buf(postfixExpression);
  istream_iterator<string> beg(buf), end;
  vector<string> postFixVector(beg,end);
  int math1, math2, mathCombined;
  int postFixInt;
  for(int i = 0; i < postFixVector.size(); i++){
    if(postFixVector.at(i) == "-"){
      if(i < 1){
        return "invalid";
      }
      math1 = stackOfInts.top();
      stackOfInts.pop();
      math2 = stackOfInts.top();
      stackOfInts.pop();
      mathCombined = math2 - math1;
      stackOfInts.push(mathCombined);
      newEvaluate = to_string(stackOfInts.top());
    }else if(postFixVector.at(i) == "+"){
      if(i < 1){
        return "invalid";
      }
      math1 = stackOfInts.top();
      stackOfInts.pop();
      math2 = stackOfInts.top();
      stackOfInts.pop();
      mathCombined = math1 + math2;
      stackOfInts.push(mathCombined);
      newEvaluate = to_string(stackOfInts.top());
    }else if(postFixVector.at(i) == "*"){
      if(i < 1){
        return "invalid";
      }
      math1 = stackOfInts.top();
      stackOfInts.pop();
      math2 = stackOfInts.top();
      stackOfInts.pop();
      mathCombined = math1 * math2;
      stackOfInts.push(mathCombined);
      newEvaluate = to_string(stackOfInts.top());
    }else if(postFixVector.at(i) == "/"){
      if(i < 1){
        return "invalid";
      }

      math1 = stackOfInts.top();
      stackOfInts.pop();
      math2 = stackOfInts.top();
      stackOfInts.pop();
      if(math1 == 0){
        return "invalid";
      }
      mathCombined = (int)math2 / (int)math1;
      stackOfInts.push(mathCombined);
      newEvaluate = to_string(stackOfInts.top());
    }else if(postFixVector.at(i) == "%"){
      if(i < 1){
        return "invalid";
      }
      math1 = stackOfInts.top();
      stackOfInts.pop();
      math2 = stackOfInts.top();
      stackOfInts.pop();
      mathCombined = (int)math2 % (int)math1;
      stackOfInts.push(mathCombined);
      newEvaluate = to_string(stackOfInts.top());
    }
    else if(atoi(postFixVector.at(i).c_str()) >= 0){
      postFixInt = atoi(postFixVector.at(i).c_str());
      stackOfInts.push(postFixInt);
      newEvaluate = to_string(stackOfInts.top());
    }
    if(stackOfInts.size() < 2){
      newEvaluate = to_string(stackOfInts.top());
    }
  }

  return newEvaluate;
}

bool ExpressionManager::isOpen(string next_thing) { //false = not open             true = open
	return (next_thing == "(" || next_thing == "{" || next_thing == "[");
}

bool ExpressionManager::isClosed(string next_thing) { //false = not closed         true = closed
	return (next_thing == ")" || next_thing == "}" || next_thing == "]");
}

bool ExpressionManager::isInteger(string next_thing) {
	stringstream isint;
	isint << next_thing;
	int num;
  isint >> num;
	return num;
}

bool ExpressionManager::isOperator(string next_thing) {
	return (next_thing == "*" || next_thing == "/" || next_thing == "%"
			|| next_thing == "+" || next_thing == "-");
}
int ExpressionManager::getPrecedence(string next_thing) {
	int precedence = 0;
	if (next_thing == "*" || next_thing == "/" || next_thing == "%") {
		precedence = 3;
	} else if (next_thing == "+" || next_thing == "-") {
		precedence = 2;
	} else if (next_thing == "(" || next_thing == ")" || next_thing == "{" || next_thing == "}" || next_thing == "[" || next_thing == "]") {
		precedence = 1;
	}
	return precedence;
}
string ExpressionManager::infixToPostfix(string infixExpression){
  if (!isBalanced(infixExpression)) {
			return "invalid";
		}
	stringstream tt(infixExpression);
	for (int i = 0; i < tt.str().length(); i++) {
			if (tt.str()[i] == '.') {
				return "invalid";
			}
			if (tt.str().length() == 1) {
				return "invalid";
			}
		}
	string temp_stuff;
	stringstream temp;
	temp << infixExpression;
	while (temp >> temp_stuff) {
		if (isOperator(temp_stuff) == false && isOpen(temp_stuff) == false && isInteger(temp_stuff) == false &&
				isClosed(temp_stuff) == false) {
		}
	}
	string previous;
	string next_thing;
	string output_queue;
	stack<string> post_fix_stack;
	stringstream pf;
	pf << infixExpression;
	while (pf >> next_thing) {
		if (isOperator(previous) && isOperator(next_thing)) {
					return "invalid";
				}
		if (isOperator(previous) && isClosed(next_thing)) {
					return "invalid";
				}
		if (isInteger(next_thing)) {
			output_queue.append(next_thing);
			output_queue.append(" ");
		} else if (isOperator(next_thing) || isOpen(next_thing) || isClosed(next_thing)) {
				if (next_thing == "(" || next_thing == "{" || next_thing == "[") {
					post_fix_stack.push(next_thing);
				}
				else if (post_fix_stack.empty()) {
					post_fix_stack.push(next_thing);
				}
				else if (getPrecedence(next_thing) == 3 && getPrecedence(post_fix_stack.top()) != 3) {
					post_fix_stack.push(next_thing);
				}
				else if (getPrecedence(next_thing) == getPrecedence(post_fix_stack.top())) {
					if (post_fix_stack.top() != "(" && post_fix_stack.top() != "[" && post_fix_stack.top() != "{" && post_fix_stack.top() != ")" && post_fix_stack.top() != "]" && post_fix_stack.top() != "}") {
						output_queue.append(post_fix_stack.top());
						output_queue.append(" ");
					}
					post_fix_stack.pop();
					post_fix_stack.push(next_thing);
				}
				else if (getPrecedence(next_thing) == 2 && getPrecedence(post_fix_stack.top()) == 3) {
					if (post_fix_stack.top() != "(" && post_fix_stack.top() != "[" && post_fix_stack.top() != "{" && post_fix_stack.top() != ")" && post_fix_stack.top() != "]" && post_fix_stack.top() != "}") {
					output_queue.append(post_fix_stack.top());
					output_queue.append(" ");
					}
					post_fix_stack.pop();
					post_fix_stack.push(next_thing);
				}
				else if (getPrecedence(next_thing) == 2 && getPrecedence(post_fix_stack.top()) == 1) {
					post_fix_stack.push(next_thing);
				}
				else if (next_thing == ")" || next_thing == "]" || next_thing == "}") {
					while (post_fix_stack.top() != "(" && post_fix_stack.top() != "{" && post_fix_stack.top() != "[") {
					if (post_fix_stack.top() != "(" && post_fix_stack.top() != "[" && post_fix_stack.top() != "{" && post_fix_stack.top() != ")" && post_fix_stack.top() != "]" && post_fix_stack.top() != "}") {
						output_queue.append(post_fix_stack.top());
						output_queue.append(" ");
					}
					post_fix_stack.pop();
					}
					if (post_fix_stack.top() == "(" || post_fix_stack.top() == "{" || post_fix_stack.top() == "[") {
						post_fix_stack.pop();
					}
				}
		}
		previous = next_thing;
	}
	while (post_fix_stack.size() != 0) {
		output_queue.append(post_fix_stack.top());
		if (post_fix_stack.size() != 1) {
			output_queue.append(" ");
		}
		post_fix_stack.pop();
	}
	return output_queue;
}
