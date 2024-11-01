tree : main.c BST.c
	gcc -o tree.exe main.c BST.c
	.\tree.exe
	del tree.exe