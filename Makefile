all:main

main: obj/NewtonsMethod.o obj/TangentsMethod.o obj/GeneralFunctions.o obj/matrix.o obj/main.o
		g++ obj/NewtonsMethod.o obj/TangentsMethod.o obj/GeneralFunctions.o obj/matrix.o obj/main.o -o main

obj/NewtonsMethod.o: NewtonsMethod/NewtonsMethod.cpp
		g++ -I SecondaryFunctions -I GeneralFunctions -I TangentsMethod -c NewtonsMethod/NewtonsMethod.cpp -o obj/NewtonsMethod.o

obj/TangentsMethod.o: TangentsMethod/TangentsMethod.cpp
		g++ -I SecondaryFunctions -I GeneralFunctions -I NewtonsMethod -c TangentsMethod/TangentsMethod.cpp -o obj/TangentsMethod.o

obj/GeneralFunctions.o: GeneralFunctions/GeneralFunctions.cpp
		g++ -c GeneralFunctions/GeneralFunctions.cpp -o obj/GeneralFunctions.o

obj/matrix.o: SecondaryFunctions/matrix.cpp
		g++ -I SecondaryFunctions -c SecondaryFunctions/matrix.cpp -o obj/matrix.o

obj/main.o: main.cpp
		g++ -I GeneralFunctions -c main.cpp -o obj/main.o


clean:
		rm -rf obj/*.o main

