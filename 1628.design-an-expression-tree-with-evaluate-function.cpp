// Category: algorithms
// Level: Medium
// Percent: 82.55227%

// Given the postfix tokens of an arithmetic expression, build and return the
// binary expression tree that represents this expression.
//
// Postfix notation is a notation for writing arithmetic expressions in which
// the operands (numbers) appear before their operators. For example, the
// postfix tokens of the expression 4*(5-(7+2)) are represented in the array
// postfix = ["4","5","7","2","+","-","*"].
//
// The class Node is an interface you should use to implement the binary
// expression tree. The returned tree will be tested using the evaluate
// function, which is supposed to evaluate the tree's value. You should not
// remove the Node class; however, you can modify it as you wish, and you can
// define other classes to implement it if needed.
//
// A binary expression tree is a kind of binary tree used to represent
// arithmetic expressions. Each node of a binary expression tree has either zero
// or two children. Leaf nodes (nodes with 0 children) correspond to operands
// (numbers), and internal nodes (nodes with two children) correspond to the
// operators '+' (addition), '-' (subtraction), '*' (multiplication), and '/'
// (division).
//
// It's guaranteed that no subtree will yield a value that exceeds 10⁹ in
// absolute value, and all the operations are valid (i.e., no division by zero).
//
// Follow up: Could you design the expression tree such that it is more modular?
// For example, is your design able to support additional operators without
// making changes to your existing evaluate implementation?
//
//  
// Example 1:
//
// Input: s = ["3","4","+","2","*","7","/"]
// Output: 2
// Explanation: this expression evaluates to the above binary tree with
// expression ((3+4)*2)/7) = 14/7 = 2.
//
//
// Example 2:
//
// Input: s = ["4","5","2","7","+","-","*"]
// Output: -16
// Explanation: this expression evaluates to the above binary tree with
// expression 4*(5-(2+7)) = 4*(-4) = -16.
//
//
//  
// Constraints:
//
//
// 	1 <= s.length < 100
// 	s.length is odd.
// 	s consists of numbers and the characters '+', '-', '*', and '/'.
// 	If s[i] is a number, its integer representation is no more than 10⁵.
// 	It is guaranteed that s is a valid expression.
// 	The absolute value of the result and intermediate values will not exceed
// 10⁹. 	It is guaranteed that no expression will include division by
// zero.
//

#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  virtual ~Node() {}
  virtual int evaluate() const = 0;
};

/**
 * Defintion for a node with a numeric value.
 */
class NumNode : public Node {
 public:
  NumNode(int val) : _val(val) {}
  int evaluate() const;

 private:
  int _val;
};
int NumNode::evaluate() const { return _val; }

/**
 * Defintion for the interface of a node with an operator.
 */
class OpNode : public Node {
 public:
  OpNode(Node* left, Node* right) : _left(left), _right(right) {}
  ~OpNode();

 protected:
  Node* const _left;
  Node* const _right;
};
OpNode::~OpNode() {
  delete _left;
  delete _right;
}

/**
 * Defintion for a node with add operator.
 */
class AddOpNode : public OpNode {
 public:
  AddOpNode(Node* left, Node* right) : OpNode(left, right) {}
  int evaluate() const;
};
int AddOpNode::evaluate() const {
  return _left->evaluate() + _right->evaluate();
};

/**
 * Defintion for a node with subtract operator.
 */
class SubtractOpNode : public OpNode {
 public:
  SubtractOpNode(Node* left, Node* right) : OpNode(left, right) {}
  int evaluate() const;
};
int SubtractOpNode::evaluate() const {
  return _left->evaluate() - _right->evaluate();
}

/**
 * Defintion for a node with multiply operator.
 */
class MultiplyOpNode : public OpNode {
 public:
  MultiplyOpNode(Node* left, Node* right) : OpNode(left, right) {}
  int evaluate() const;
};
int MultiplyOpNode::evaluate() const {
  return _left->evaluate() * _right->evaluate();
}

/**
 * Defintion for a node with divide operator.
 */
class DivideOpNode : public OpNode {
 public:
  DivideOpNode(Node* left, Node* right) : OpNode(left, right) {}
  int evaluate() const;
};
int DivideOpNode::evaluate() const {
  return _left->evaluate() / _right->evaluate();
}

class TreeBuilder {
 private:
  Node* nodeCreate(string op, Node* left, Node* right) {
    switch (op[0]) {
      case '+':
        return new AddOpNode(left, right);
      case '-':
        return new SubtractOpNode(left, right);
      case '*':
        return new MultiplyOpNode(left, right);
      case '/':
        return new DivideOpNode(left, right);
      default:
        return NULL;
    }
  }

  int toInt(string& x) {
    int ret = 0;
    for (char c : x) ret = ret * 10 + (c - '0');
    return ret;
  }

 public:
  Node* buildTree(vector<string>& postfix) {
    stack<Node*> curStack;
    for (auto& token : postfix) {
      if (isdigit(token[0])) {
        curStack.push(new NumNode(toInt(token)));
      } else {
        auto R = curStack.top();
        curStack.pop();
        auto L = curStack.top();
        curStack.pop();
        curStack.push(nodeCreate(token, L, R));
      }
    }
    return curStack.top();
  }
};
