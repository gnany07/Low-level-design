#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Date {
    uint8_t day;
    uint8_t month;
    uint32_t year;
};

enum PaymentStatus { PAYMENT_SUCCESS, PAYMENT_FAILURE };
enum BookingStatus { BOOKING_SUCCESS, BOOKING_FAILURE };
enum CardType { DEBIT, CREDIT };
enum ShowType { MORNING_SHOW, MATNEE_SHOW, FIRST_SHOW, SECOND_SHOW };
enum SeatType { LOWER_CLASS, UPPER_CLASS, LOWER_BALCONY, UPPER_BALCONY }; 
enum NotificationType { NEW_MOVIE, BOOKED, CANCELLED };

class Address
{
    public:
        string door_no;
        string city;
        string state;
        string country;
        uint64_t zip_code;
};

class Card
{
    public:
        CardType type;
        string number;
        string user_id;
        uint32_t cvv;
        string expiry_date;
        string bank_name;
};

class Customer
{
    public:
        string user_id;
        string name;
        string email;   
        string mobile_no;
        string password;
};

class Movie
{
    public:
        uint32_t id;
        string title;
        vector<string> language;
        vector<string> genre;
        Date release_date;
        vector<string> star_cast;
        uint8_t rating;

        bool is_title_match(string title) {
            return true;
        }

        bool is_language_match(string language) {
            return true;
        }

        bool is_genre_match(string genre) {
            return true;
        }

        bool is_release_date_match(Date release_date) {
            return true;
        }
};

class Transaction
{
    public:
        PaymentStatus payment(uint32_t amount, Card card, string user_id){
            PaymentStatus status;
            return status;
        }
};

class Seat
{
    public:
        SeatType type;
        uint32_t amount;
        bool is_booked;
        Customer customer;
};

class Show
{
    public:
        ShowType type;
        Movie movie;
        vector<vector<Seat> > seat_map;
        bool is_available;
        uint8_t audi_number;
        uint64_t hall_id;

        void display_seat_arrangement(){
            for(int i=0; i<seat_map.size(); i++){
                for(int j=0; j<seat_map[0].size(); j++){
                    cout << seat_map[i][j].is_booked << " ";
                }
                cout << endl;
            }
            return;
        }
};

class Audi
{
    public:
        uint8_t number;
        string name;
        vector<Show> shows;
};

class CinemaHall
{
    public:
        uint64_t hall_id;
        string name;
        Address address;
        vector<Audi> audis;
};

class MovieBookingService
{
    public:
        vector<CinemaHall> halls;
        vector<Movie> movies;
        unordered_map<uint32_t, vector<Show> > movie_vs_show_map;
        vector<Transaction> transactions;

        MovieBookingService(){
            cout << "Movie Booking Service Created" << endl;
        }

        vector<CinemaHall> get_cinema_hall(string city){
            vector<CinemaHall> res;
            for(int i=0; i < halls.size(); i++) {
                if (halls[i].address.city == city)
                    res.push_back(halls[i]);
            }
            return res;
        }

        vector<Movie> search_movie_by_title(string title){
            vector<Movie> res;
            for(int i=0; i<movies.size(); i++) {
                if(movies[i].is_title_match(title)) 
                    res.push_back(movies[i]);
            }
            return res;
        }

        vector<Movie> search_movie_by_language(string language){
            vector<Movie> res;
            for(int i=0; i<movies.size(); i++) {
                if(movies[i].is_language_match(language)) 
                    res.push_back(movies[i]);
            }
            return res;
        }

        vector<Movie> search_movie_by_genre(string genre){
            vector<Movie> res;
            for(int i=0; i<movies.size(); i++) {
                if(movies[i].is_genre_match(genre)) 
                    res.push_back(movies[i]);
            }
            return res;
        }

        vector<Movie> search_movie_by_release_date(Date release_date){
            vector<Movie> res;
            for(int i=0; i<movies.size(); i++) {
                if(movies[i].is_release_date_match(release_date)) 
                    res.push_back(movies[i]);
            }
            return res;
        }

        vector<Show> get_availabe_shows(Movie movie, string city){
            vector<Show> res;
            Show curr;

            unordered_map<uint32_t, vector<Show> >::iterator it;
            it = movie_vs_show_map.find(movie.id);
            if (it == movie_vs_show_map.end())
                return res;
            for(int i=0; i<it->second.size(); i++) {
                curr = it->second[i];
                if(curr.is_available == true)
                    res.push_back(curr);
            }
            return res;
        }

        uint32_t calculate_amount(Show show, vector<Seat> seats){
            return 100;
        }

        BookingStatus book_tickets(Show show, vector<Seat> seats, string user_id, Card card, uint32_t discount) {
            BookingStatus status;
            uint32_t amount = calculate_amount(show, seats);
            amount -= discount;
            Transaction().payment(amount, card, user_id);
            return status;
        }
};
