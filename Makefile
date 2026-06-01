all:
	g++ Main.cpp ./Rendering/Game_Window.cpp -o ./Output/DoomLike -lSDL3

clean:
	rm ./Output/DoomLike

run:
	./Output/DoomLike