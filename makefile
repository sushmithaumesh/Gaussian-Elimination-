Finalproject: main.o Start.o Gaussian.o   
	g++ main.o Start.o Gaussian.o -o Finalproject
main.o: main.cpp Start.h Gaussian.h  
	g++ -c main.cpp
Start.o: Start.cpp Start.h Gaussian.h  
	g++ -c Start.cpp
Gaussian.o: Gaussian.cpp Gaussian.h  
	g++ -c Gaussian.cpp
clean:
	rm *.o
	rm Finalproject
run: Finalproject
	./Finalproject


