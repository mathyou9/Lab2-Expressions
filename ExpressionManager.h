#pragma once
#include "ExpressionManagerInterface.h"
#include <iostream>
#include <string>
#include <stack>

class ExpressionManager : public ExpressionManagerInterface{
public:
  ExpressionManager(){};
  ~ExpressionManager(){};


  /*
	* Checks whether an expression is balanced on its parentheses
	*
	* - The given expression will have a space between every number or operator
	*
	* @return true if expression is balanced
	* @return false otherwise
	*/
  bool isBalanced(string expression);

  /**
  * Converts a postfix expression into an infix expression
  * and returns the infix expression.
  *
  * - The given postfix expression will have a space between every number or operator.
  * - The returned infix expression must have a space between every number or operator.
  * - Redundant parentheses are acceptable i.e. ( ( 3 * 4 ) + 5 ).
  * - Check lab requirements for what will be considered invalid.
  *
  * return the string "invalid" if postfixExpression is not a valid postfix expression.
  * otherwise, return the correct infix expression as a string.
  */
  string postfixToInfix(string postfixExpression);

  /*
  * Evaluates a postfix expression returns the result as a string
  *
  * - The given postfix expression will have a space between every number or operator.
  * - Check lab requirements for what will be considered invalid.
  *
  * return the string "invalid" if postfixExpression is not a valid postfix Expression
  * otherwise, return the correct evaluation as a string
  */
  string postfixEvaluate(string postfixExpression);

  int getPrecedence(string next_thing);
  bool isOpen(string next_thing);
  bool isClosed(string next_thing);
  bool isInteger(string next_thing);
  bool isOperator(string next_thing);
  /*
  * Converts an infix expression into a postfix expression
  * and returns the postfix expression
  *
  * - The given infix expression will have a space between every number or operator.
  * - The returned postfix expression must have a space between every number or operator.
  * - Check lab requirements for what will be considered invalid.
  *
  * return the string "invalid" if infixExpression is not a valid infix expression.
  * otherwise, return the correct postfix expression as a string.
  */
  string infixToPostfix(string infixExpression);
private:
  string inExpression;
  string newInfix;
  string newEvaluate;
  bool isValid;
  stack<char> stackOfChars;
  stack<int> stackOfInts;
  stack<string> stackOfFixedChars;
  stack<string> stackFixed;

};
