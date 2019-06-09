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
			std::cout << p->info << "||";
			traversal(p->llink);
			traversal(p->rlink);
		}
	}

	//fixed
	int getDepth(Node* start, int data, int k) {
		int result;
		if (!start) return -1;
		if (start->info == data) return k;
		
		//Formated debug log
		if (start->llink) std::cout << k << " " << start->info << " Left " << start->llink->info << std::endl;
		else std::cout << k << " " << start->info << " Left NULL" << std::endl;
		//Formated debug log


		result = getDepth(start->llink, data, ++k);
		if (result != -1) return result;
		//Formated debug log
		if (start->rlink) std::cout << k << " " << start->info << " Right " << start->rlink->info << std::endl;
		else std::cout << k << " " << start->info << " Right NULL" << std::endl;
		//Formated debug log


		result = getDepth(start->rlink, data, k--);
		return result;
		
	}

	int getLevel(Node* node, int data)
	{
		return getDepth(node, data, 0);
	}
};