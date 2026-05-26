all:
	g++ Main.cpp -o ./Output/DoomLike -lSDL3

clean:
	rm ./Output/DoomLike

run:
	./Output/DoomLike