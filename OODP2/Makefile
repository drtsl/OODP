main = test
class1 = AddressBook
class2 = AddressBookManager

all: $(main)

$(main): $(main).o $(class1).o $(class2).o
	g++ -std=c++11 -o $(main) $(main).o $(class1).o $(class2).o

$(main).o: $(main).cpp
	g++ -c -std=c++11 $(main).cpp

$(class1).o: $(class1).cpp
	g++ -c -std=c++11 $(class1).cpp

$(class2).o: $(class2).cpp
	g++ -c -std=c++11 $(class2).cpp

clean:
	rm $(main) *.o
