#include "BTree.h"
#include "Node.h"

int main() {
	BTree sapling;

	for (int i = 0; i < 9; i++) {
		if (i % 3 == 0) sapling.insert(i * 2 + 1);
		else if (i % 4 == 0) sapling.insert(i - 3);
		else if (i % 2 == 0) sapling.insert(-i + 3);
		else sapling.insert(-i * 2 - 1);
	}
	//Print tree elements
	//drvce.traversal(sapling.start);

	std::cout << std::endl;
	//*******NUMBER*******TO*******SEARCH*******HERE*******V
	std::cout << std::endl << sapling.getDepth(sapling.start, -3, 0) << std::endl;

	return 0;
}