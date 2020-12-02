objects = main.o Menu.o Character.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o

Combat: $(objects)
	g++ -std=c++11 -g -o Combat $(objects)
	
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
	
Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++11 -c Menu.cpp

Character.o: Character.cpp Character.hpp
	g++ -std=c++11 -c Character.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -std=c++11 -c Vampire.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -std=c++11 -c Barbarian.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -std=c++11 -c BlueMen.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -std=c++11 -c Medusa.cpp
	
HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -std=c++11 -c HarryPotter.cpp
	
.PHONY: clean
clean:
	rm Combat $(objects)
