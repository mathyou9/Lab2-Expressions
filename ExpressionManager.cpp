
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
    istringstream iss(postfixExpression);
    istream_iterator<string> beg(iss), end;
    vector<string> pfVector(beg, end);
    string postfixString = postfixExpression;
    stack<string> operandStack;
    string isDigitCheck;

    for (int i = 0; i < pfVector.size(); i++) {
        isDigitCheck = pfVector[i];
        if (isdigit(isDigitCheck[0])) {
            if(isDigitCheck[1] == '.') {
                return "invalid";
            }
            else {
                operandStack.push(pfVector[i]);
            }

        }
        else if (pfVector[i] == "+" || pfVector[i] == "-" || pfVector[i] == "*"
            || pfVector[i] == "/" || pfVector[i] == "%") {
            if (operandStack.size() < 2) {
                return "invalid";
            }
            else {
                string newString;

                string o1 = operandStack.top();
                operandStack.pop();
                string o2 = operandStack.top();
                operandStack.pop();
                newString = "( " + o2 + " " + pfVector[i] + " " + o1 + " )";
                operandStack.push(newString);
            }
        }
    }
    if (operandStack.size() == 1) {
        postfixString = operandStack.top();
        return postfixString;
    }
    else {
        return "invalid";
    }
}
string ExpressionManager::postfixEvaluate(string postfixExpression){
    int a;
    int b;
    double c;
    int size;
    stringstream ss;
    ss << postfixExpression;
    isValid = false;
    while (ss >> postfixExpression) {
        if (postfixExpression == ")" || postfixExpression == "]" || postfixExpression == "}") {
            return "invalid";
        }
        //check for operator
        if ((postfixExpression == "+") || (postfixExpression == "-") || (postfixExpression == "*") || (postfixExpression == "/") || (postfixExpression == "%")) {
            if (stackOfInts.size() < 2) {
                return "invalid";
            }
            int a = stackOfInts.top();
            stackOfInts.pop();
            int b = stackOfInts.top();
            stackOfInts.pop();
            switch (postfixExpression[0]) {
            case '+':
                stackOfInts.push(b + a);
                break;
            case '-':
                stackOfInts.push(b - a);
                break;
            case '*':
                stackOfInts.push(b * a);
                break;
            case '/':
                if (a == 0) {
                    return "invalid";
                }
                stackOfInts.push(b / a);
                break;
            case '%':
                if (a == 0) {
                    return "invalid";
                }
                stackOfInts.push(b % a);
                break;
            }
        }
        //check for numeric
        else if (isdigit(postfixExpression[0])) {
            double num;
            num = stoi(postfixExpression);
            stackOfInts.push(num);
            isValid = true;
        }
        else {
            cout << "invalid" << endl;
        }
    }
    if (stackOfInts.empty()) {
        return "invalid";
    }
    return to_string(stackOfInts.top());
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
          return "invalid";
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
