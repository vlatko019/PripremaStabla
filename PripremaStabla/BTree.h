#pragma once
#include "Node.h"
#include <iostream>

class BTree {
public:
	Node* start;

	BTree() {
		start = nullptr;
	}

	void insert(int item) {
		Node* p = new Node(item);
		if (this->start == nullptr)
			this->start = p;
		else {
			Node* parent = nullptr;
			Node* node = start;
			while (node) {
				parent = node;
				if (p->info < node->info)
					node = node->llink;
				else node = node->rlink;

			}
			if (p->info < parent->info)
				parent->llink = p;
			else parent->rlink = p;
		}
	}

	int info(Node* p) {
		return p->info;
	}
	Node* getLeft(Node* p) {
		return p->llink;
	}
	Node* getRight(Node* p) {
		return p->rlink;
	}
	void traversal(Node* p) {
		if (p) {
			std::cout << p->info;
			traversal(p->llink);
			traversal(p->rlink);
		}
	}

	//get it fixed
	int getDepth(Node* find, Node* start, int k) {
		int i = k;
		if (start == find) {
			return k;
		}
		if (start){
			getDepth(find, start->llink, i);
			getDepth(find, start->rlink, i);
		}
		return -1;
	}
};