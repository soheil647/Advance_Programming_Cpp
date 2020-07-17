#include "./header/reservationSystem.hpp"
#include "server/server.hpp"
#include "Response/handlers.hpp"

using namespace std;

int main(int argc, char **argv) {

    try {
        auto my_app = new ReservationSystem(argv[0], argv[1]);
        Server server(8080);

        server.post("/checkSignUp", new CheckSignUp(my_app));
        server.post("/checkLogin", new CheckLogin(my_app));
        server.post("/add", new Adder());
        server.get("/", new ShowPage("static/welcome.html"));
        server.get("/home", new Home(my_app));
        server.post("/filter", new DoFilter(my_app));
        server.get("/wallet", new Wallet(my_app));
        server.post("/new_wallet", new AddWallet(my_app));
        server.post("/hotel_detail", new HotelDetail(my_app));

        server.run();
    } catch (Server::Exception& e) {
        cerr << e.getMessage() << endl;
    }
}