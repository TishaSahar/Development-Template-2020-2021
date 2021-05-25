#include "TreeString.h"

using namespace std;


Text::Text(string str)
{
	root = nullptr;

	string temp("");
	string ch;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		ch = str[i];
		if (i != len - 1)
			if (ch == " ") {
				this->addWord(temp);
				temp = "";
			}
			else
				temp += ch;
		else {
			temp += ch;
			this->addWord(temp);
		}
	}
}


void Text::addWord(string str)
{
	if (this->root == nullptr) {
		this->root = new Node(str);
		return;
	}
	Node* node = root;
	Node* curr;
	while (true) {
		if (node->value < str) {
			curr = node->right;
			if (curr == nullptr) {
				node->right = new Node(str);
				break;
			}
			node = curr;
		}
		else if (node->value > str) {
			curr = node->left;
			if (curr == nullptr) {
				node->left = new Node(str);
				break;
			}
			node = curr;
		}
		else {
			node->addCount();
			break;
		}
	}
}

int Text::getCount(string str)
{
	Node* node = root;
	while (node->value != str)
		if (node->value < str) {
			node = node->right;
			if (node == nullptr)
				return 0;
		}
		else {
			node = node->left;
			if (node == nullptr)
				return 0;
		}

	return node->count;
}