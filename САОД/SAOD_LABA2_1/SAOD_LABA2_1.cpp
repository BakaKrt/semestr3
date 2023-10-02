#include <iostream>
#include <string>
#include <vector>
#include <stack>
//#include <bits/stdc++.h>
using namespace std;


typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}node;
node* newnode(int d) {
	node* temp = new node;
	temp->data = d;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
node* insert(node* root, int d) {
	if (root == NULL) {
		return newnode(d);
	}
	else if (d < root->data) {
		root->left = insert(root->left, d);
	}
	else {
		root->right = insert(root->right, d);
	}
	return root;
}
void inorder(node* root) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}


double average(node* root) {
	stack<node*> st;
	node* curr;
	double sum = 0, count = 0;
	
	st.push(root);
	while (!st.empty()) {
		curr = st.top();
		st.pop();
		sum += curr->data; count++;
		if (curr != NULL) {
			if (curr->left != NULL)
				st.push(curr->left);

			if (curr->right != NULL)
				st.push(curr->right);
		}
	}
	return sum / count;
}



string get_input_numbers() {
	char a = '0'; string out = "";
	while (a != 10) {
		a = getchar();
		if (a == 32) break;
		else if (a > 47 && a < 58 || a == 45) {
			out += a;
		}
	}
	if (out.empty()) {
		out = "#";
	}
	return out;
}

int main() {
	setlocale(0, "");
	node* root = NULL;

	string in;
	while (in != "#") {
		in = get_input_numbers();
		if (in == "#") break;
		root = insert(root, stoi(in));
	}

	inorder(root);
	printf("Среднее арифметическое: %f", average(root));
}