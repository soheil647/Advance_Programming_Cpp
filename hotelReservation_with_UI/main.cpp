#include "./header/reservationSystem.hpp"
#include "server/server.hpp"
#include "Response/handlers.hpp"

using namespace std;
//int main() {
//
//    ReservationSystem my_app = ReservationSystem("./assets/hotels.csv", "./assets/ratings.csv");
//    string input;
//    while(getline(cin, input)){
//        std::stringstream input_line(input);
//        try {
//            my_app.parse_command(input_line);
//        }
//        catch (Hotel_Exceptions& err){
//            err.handle_error();
//        }
//    }
//    return 0;
//}

int main(int argc, char **argv) {
    try {
        Server server(8080);

        server.get("/", new Login());
        server.get("/add", new Adder());
        server.get("/login", new ShowPage("static/login.html"));
        server.get("/addform", new ShowPage("static/addform.html"));

        server.run();
    } catch (Server::Exception& e) {
        cerr << e.getMessage() << endl;
    }
}