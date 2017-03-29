main = test
class1 = AddressBook
class2 = AddressBookManager
class3 = Call
class4 = CallManager
class5 = SMS
class6 = SMSManager
class7 = time

all: $(main)

$(main): $(main).o $(class1).o $(class2).o $(class3).o $(class4).o $(class5).o $(class6).o $(class7).o
	g++ -std=c++11 -o $(main) $(main).o $(class1).o $(class2).o $(class3).o $(class4).o $(class5).o $(class6).o $(class7).o
$(main).o: $(main).cpp
	g++ -c -std=c++11 $(main).cpp

$(class1).o: $(class1).cpp
	g++ -c -std=c++11 $(class1).cpp

$(class2).o: $(class2).cpp
	g++ -c -std=c++11 $(class2).cpp

$(class3).o: $(class3).cpp
	g++ -c -std=c++11 $(class3).cpp

$(class4).o: $(class4).cpp
	g++ -c -std=c++11 $(class4).cpp

$(class5).o: $(class5).cpp
	g++ -c -std=c++11 $(class5).cpp

$(class6).o: $(class6).cpp
	g++ -c -std=c++11 $(class62).cpp

$(class7).o: $(class7).cpp
	g++ -c -std=c++11 $(class7).cpp

clean:
	rm $(main) *.o
