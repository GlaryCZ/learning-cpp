#include<iostream>

int* GenerateTickets(int Adults, int Childs, int Stops, int* seats) {
    int i = 0;
    while (Adults > 0 && Childs > 0) {
        if (i > sizeof(seats)/sizeof(seats[0])) {
            std::cout << Adults << " dospelych a " << Childs << " deti se do autobusu nevejde" << std::endl;
            break;
        }
        if (seats[i] == 0) {
            if (Adults > 0) {
                continue; // print adult ticket
            } else if (Childs > 0) {
                continue; // print child ticket
            } else {
                return seats;
            }
            
        }
    }
    
}

int GoToNextStop(int* seats) {
    for (int i=0; i<sizeof(seats)/sizeof(seats[0]); i++) {
        if (seats[i] > 0) seats[i] = seats[i]-1;
    }
    int NextPassenger = 1;
    while (NextPassenger > 0) {
    
        int AdultTickets = 0;
        int ChildTickets = 0;
        int StopsCount = 0;
        std::cout << "Pocet zastavek: ";
        std::cin >> StopsCount;
        std::cout << "Pocet listku za dospele jizdne: ";
        std::cin >> AdultTickets;
        std::cout << "Pocet listku za detske jizdne: ";
        std::cin >> ChildTickets;
        seats = GenerateTickets(AdultTickets, ChildTickets, StopsCount, seats);
        std::cout << "Dalsi nastupujici? (0/1) ";
    }

    

}


int main() {
    const int BusCapacity = 40;
    int seats[BusCapacity];
    for (int i=0; i<BusCapacity; i++) {
        seats[i] = 0;
        std::cout << i << std::endl;
    }

    // GoToNextStop(seats);
    return 0;
}