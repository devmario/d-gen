#ncurses
#$ brew tap homebrew/dupes
#$ brew install ncurses
#LDFLAGS:  -L/usr/local/opt/ncurses/lib
#CPPFLAGS: -I/usr/local/opt/ncurses/include

d-gen : d-gen.o
	g++ -lcurses -o build/d-gen build/obj/d-gen.o
	tree build

d-gen.o : 3rd/cmdline/cmdline.h src/d-gen.cpp
	g++ -c src/d-gen.cpp -o build/obj/d-gen.o

clean :
	rm -f build/d-gen
	rm -f build/obj/*
	tree build

test :
	echo "\n\nclean" && make clean && echo "\n\nmake" && make && echo "\n\nrun" &&  build/d-gen
