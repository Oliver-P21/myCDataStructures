tree : main.c Node.c Tree.c
	gcc -o tree.exe main.c Tree.c Node.c
	.\tree.exe
	del tree.exe