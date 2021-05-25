#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Node {
	string value;
	Node* right;
	Node* left;
	int count;

	Node(string _value, Node* right = nullptr, Node* left = nullptr) : value(_value), right(right), left(left), count(1) {};
	void addCount()
	{
		count++;
	}
};


class Text
{
private:
	Node* root;
public:
	Text(string str = "");

	void addWord(string str);
	int getCount(string str);
};