#pragma once
class Node {
public:
	Node* llink;
	Node* rlink;
	int info;

	Node(){
		this->info = 0;
		this->llink = nullptr;
		this->rlink = nullptr;
	}

	Node(int a) {
		this->info = a;
		this->llink = nullptr;
		this->rlink = nullptr;
	}
};