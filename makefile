all:
	mkdir bin
	clang++ src/*.cpp -FFrameworks -framework SFML -framework sfml-window -framework sfml-system -framework sfml-graphics -o bin/raytracer
