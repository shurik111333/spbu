#pragma once

#include <cstdio>
#include <ostream>

class Node
{
public:
	Node *left;
	Node *right;
	
public:
	Node();
	
	virtual int Calc() const = 0;
	
	virtual void print(std::ostream &out) const = 0;
};

class Tree
{
private:
	Node *root;
	
public:
	Tree();
	
	Tree(FILE *file);
	
	int Calc() const;
	
	void print(std::ostream &out) const;
	
	friend Node *getNodeFromFile(FILE *file);
};

class NodeNumber : public Node
{
private:
	int value;
	
public:
	NodeNumber(int value);
	
	int Calc() const;
	
	void print(std::ostream &out) const;
};

class NodePlus : public Node
{
public:
	NodePlus(Node *left, Node *right);
	
	int Calc() const;
	
	void print(std::ostream &out) const;
};

class NodeMinus : public Node
{
public:
	NodeMinus(Node *left, Node *right);
	
	int Calc() const;
	
	void print(std::ostream &out) const;
};

class NodeMultiply : public Node
{
public:
	NodeMultiply(Node *left, Node *right);
	
	int Calc() const;
	
	void print(std::ostream &out) const;
};

class NodeDivide : public Node
{
public:
	NodeDivide(Node *left, Node *right);
	
	int Calc() const;
	
	void print(std::ostream &out) const;
};