all:
	g++ ./src/Main.cpp ./src/Game_Window.cpp ./src/Player.cpp ./src/Camera.cpp ./src/Game.cpp -o ./Output/DoomLike -lSDL3

clean:
	rm ./Output/DoomLike

run:
	./Output/DoomLike