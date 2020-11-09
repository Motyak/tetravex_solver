L'implémentation multithread n'a pas été terminée, son code est néanmoins disponible.

# BUILD
```console
foo@bar:<...>/tetravex_solver$ make
g++ -c src/Board.cpp -o obj/Board.o -O3
g++ -c src/Solver.cpp -o obj/Solver.o -O3
g++ -c src/main.cpp -o obj/main.o -O3
g++ obj/Board.o obj/Solver.o obj/main.o -o bin/tetravex-solver -O3
```

#CLEAN OBJ FILES
```console
foo@bar:<...>/tetravex_solver$ make clean
rm -rf obj/Board.o obj/Solver.o obj/main.o
```

#CLEAN GENERATED DIRS
```console
foo@bar:<...>/tetravex_solver$ make mrproper
rm -rf bin obj
```
