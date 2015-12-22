#include <cctype>
#include "tree.h"

using namespace std;

Node::Node()
    :left(nullptr), right(nullptr)
{}

Tree::Tree()
    :root(nullptr)
{}

int Tree::Calc() const
{
	return root->Calc();
}

void Tree::print(ostream &out) const
{
	root->print(out);
}

bool isSpace(char symbol)
{
	return (symbol == ' ' || symbol == '\t' || symbol == '\n');
}

void skipSpaces(FILE *file)
{
	char c = getc(file);
	while (!feof(file) && isSpace(c))
	{
		c = getc(file);
	}
	ungetc(c, file);
}

int getNumber(FILE *file)
{
	int result = 0;
	char c = getc(file);
	while (isdigit(c))
	{
		result = result * 10 + c - '0';
		c = getc(file);
	}
	ungetc(c, file);
	return result;
}

Node *getNode(char c, Node *left, Node *right)
{
	switch (c)
	{
		case '+':
			return new NodePlus(left, right);
		case '-':
			return new NodeMinus(left, right);
		case '*':
			return new NodeMultiply(left, right);
		case '/':
			return new NodeDivide(left, right);
		default:
			return nullptr;
	}
}

Node *getNodeFromFile(FILE *file)
{
	skipSpaces(file);
	Node *newNode = nullptr;
	char c = getc(file);
	if (c == '(')
	{
		skipSpaces(file);
		char sign = getc(file);
		skipSpaces(file);
		Node *left = getNodeFromFile(file);
		skipSpaces(file);
		Node *right = getNodeFromFile(file);
		newNode = getNode(sign, left, right);
		skipSpaces(file);
		getc(file);
	}
	else
	{
		ungetc(c, file);
		skipSpaces(file);
		newNode = new NodeNumber(getNumber(file));
	}
	return newNode;
}

Tree::Tree(FILE *file)
{
	root = getNodeFromFile(file);
}

NodeNumber::NodeNumber(int value)
    :value(value)//, left(nullptr), right(nullptr)
{
	this->left = nullptr;
	this->right = nullptr;
}

int NodeNumber::Calc() const
{
	return value;
}

void NodeNumber::print(ostream &out) const
{
	out << value;
}

NodePlus::NodePlus(Node *left, Node *right)
{
	this->left = left;
	this->right = right;
}

int NodePlus::Calc() const
{
	return left->Calc() + right->Calc();
}

void NodePlus::print(std::ostream &out) const
{
	out << "(";
	left->print(out);
	out << " + ";
	right->print(out);
	out << ")";
}

NodeMinus::NodeMinus(Node *left, Node *right)
{
	this->left = left;
	this->right = right;
}

int NodeMinus::Calc() const
{
	return left->Calc() - right->Calc();
}

void NodeMinus::print(std::ostream &out) const
{
	out << "(";
	left->print(out);
	out << " - ";
	right->print(out);
	out << ")";
}

NodeMultiply::NodeMultiply(Node *left, Node *right)
{
	this->left = left;
	this->right = right;
}

int NodeMultiply::Calc() const
{
	return left->Calc() * right->Calc();
}

void NodeMultiply::print(std::ostream &out) const
{
	out << "(";
	left->print(out);
	out << " * ";
	right->print(out);
	out << ")";
}

NodeDivide::NodeDivide(Node *left, Node *right)
{
	this->left = left;
	this->right = right;
}

int NodeDivide::Calc() const
{
	return left->Calc() / right->Calc();
}

void NodeDivide::print(std::ostream &out) const
{
	out << "(";
	left->print(out);
	out << " / ";
	right->print(out);
	out << ")";
}
