all:
	mkdir ./h
	mkdir ./o
	(cd LinkedList && make compile)
	(cd HashTable && make compile)
	(cd BST && make compile)
	(cd RedBlackTrees && make compile)

clean:
	(cd LinkedList && make clean)
	(cd HashTable && make clean)
	(cd BST && make clean)
	(cd RedBlackTrees && make clean)
	rm -rf ./h
	rm -rf ./o

