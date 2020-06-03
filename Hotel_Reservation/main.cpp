#include "./header/reservationSystem.hpp"
using namespace std;

int main() {

    ReservationSystem my_app = ReservationSystem("./Hotels.csv");
    string input;
    while(getline(cin, input)){
        std::stringstream input_line(input);
        try {
            my_app.parse_command(input_line);
        }
        catch (Hotel_Exceptions& err){
            err.handle_error();
        }
    }
    return 0;
}
