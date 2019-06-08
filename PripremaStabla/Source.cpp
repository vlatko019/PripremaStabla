#include "BTree.h"
#include "Node.h"

int main() {
	BTree drvce;

	for (int i = 0; i < 5; i++) {
		drvce.insert(i * 2 + 1);
	}
	Node *p = new Node(5);
	std::cout << drvce.getDepth(p, drvce.start, 0);
	drvce.traversal(drvce.start);

	return 0;
}