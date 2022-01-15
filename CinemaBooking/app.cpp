#include <iostream>
#include "app.hpp"

using namespace std;

int main(){
    MovieBookingService *mbs = new MovieBookingService();
    CinemaHall *hall1 = new CinemaHall();
    Audi *audi1 = new Audi();
    Audi *audi2 = new Audi();
    Show *show1 = new Show();
    Show *show2 = new Show();
    Movie *movie1 = new Movie();
    Movie *movie2 = new Movie();
    return 0;
}
