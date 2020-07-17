#include "handlers.hpp"


using namespace std;

Response *Login::callback(Request *req) {
    auto *res = new Response;
    res->setHeader("Content-Type", "text/html");
    string body;
    body += "<!DOCTYPE html>";
    body += "<html>";
    body += "<body>";
    body += "<h1>Hello World!</h1>";
    body += "</body>";
    body += "</html>";
    res->setBody(body);
    return res;
}

Response *Adder::callback(Request *req) {
    auto *res = new Response;
    res->setHeader("Content-Type", "text/html");

    int num1 = stoi(req->getBodyParam("num1"));
    int num2 = stoi(req->getBodyParam("num2"));
//    string ss = req->getBody();

    ostringstream body;
    body
            << "<!DOCTYPE html>" << endl
            << "<html>" << endl
            << "<body>" << endl
            << num1 << "+" << num2 << "=" << (num1 + num2) << endl
            << "</body>" << endl
            << "</html>" << endl;
    res->setBody(body.str());
    return res;
}



Response *CheckSignUp::callback(Request * req) {
    auto res = new Response;
    res->setHeader("Content-Type", "text/html");
    stringstream input(req->getBody());
    cout << input.str() << endl;
    try {
        my_app->parse_command(input, "POST", "signup");
    }
    catch (Hotel_Exceptions& err){
        err.handle_error();
//        throw Server::Exception(err.handle_error());
        res = Response::redirect("/");
        res->setHeader("error", err.handle_error());
        return res;
    }
    string args = "true";
    res = Response::redirect("/home");
    res->setSessionId(my_app->get_logged_user()->get_username());
    res->setHeader("error", args);
    return res;
}

Response *CheckLogin::callback(Request * req) {
    auto res = new Response;
    res->setHeader("Content-Type", "text/html");
    stringstream input(req->getBody());
    try {
        my_app->parse_command(input, "POST", "login");
    }
    catch (Hotel_Exceptions& err){
        res = Response::redirect("/");
        res->setHeader("error", err.handle_error());
        return res;
    }
    string args = "true";
    res = Response::redirect("/home");
    res->setSessionId(my_app->get_logged_user()->get_username());
    res->setHeader("error", args);
    return res;
}

Response *Home::callback(Request * req) {
    auto *res = new Response;
    res->setHeader("Content-Type", "text/html");
    string user_name = req->getSessionId();
    vector<Hotel*> my_hotels;
    stringstream s;
    string error = req->getHeader("error");
    try {
        my_app->set_logged_user(user_name);
        my_hotels = my_app->get_hotels(s, true);
    }
    catch (Hotel_Exceptions& err){
        error = err.handle_error();
    }

    ostringstream body;
    body
            << "<!DOCTYPE html>" << endl
            << "<html>" << endl
            << "<body>" << endl;
            if(!error.empty()){
                body
                        << "Error Is: " << error << endl;
            }
            body
            << "Hello You Are: "  << user_name << endl
            << "<form action=\"/wallet\" method=\"get\">" << endl
            << "<button type=\"submit\">See Your Wallet</button>" << endl
            << "</form>" << endl
            << "<form action=\"/\" method=\"get\">" << endl
            << "<button type=\"submit\">LogOut</button>" << endl
            << "</form>" << endl
            << "<b /"
            << "</form>" << endl
            << "<form action=\"/filter\" method=\"post\">" << endl
            << "Filter Hotels With Star" << endl
            << "<b />" << endl
            << "<input name=\"min_star\" type=\"text\" placeholder=\"Min Star\" />" << endl
            << "<input name=\"max_star\" type=\"text\" placeholder=\"Max Star\" />" << endl
            << "<button type=\"submit\">Filter Hotels</button>" << endl
            << "</form>" << endl


            << "<table>" << endl;
            for(auto hotel : my_hotels) {
                string name = hotel->get_id();
                body
                    << "<tr>" << endl
                    << "<td>" << endl
                    << "<img src=" << hotel->get_image() << endl
                    << "<br />" << endl
                    << "<br />" << endl
                    << "Property Name: " << hotel->get_name() << endl
                    << "<br />" << endl
                    << "Hotel Star Rating: " << hotel->get_star_rating() << endl
                    << "<br />" << endl
                    << "City: " << hotel->get_city() << endl
                    << "<br />" << endl
                    << "<form action=\"/hotel_detail\" method=\"post\">" << endl
                    << "<input style=\"display:none; \" name=\"hotel_name\" type=\"text\" placeholder=\"Max Star\" value=" + name +"/>" << endl
                    << "<button type=\"submit\">See Details!</button>" << endl
                    << "</form>" << endl
                    << "</td>" << endl
                    << "</tr>" << endl;

            }
    body
            << "</table>" <<endl
            << "</body>" << endl
            << "</html>" << endl;
    res->setSessionId(my_app->get_logged_user()->get_username());
    res->setBody(body.str());
    return res;
}

Response *DoFilter::callback(Request * req) {
    auto *res = new Response;

    string min_star = req->getBodyParam("min_star");
    string max_star = req->getBodyParam("max_star");
    string user_name = req->getSessionId();

    vector<string> arg = {"min_star", min_star, "max_star", max_star};

    stringstream s;
    try {
        my_app->set_logged_user(user_name);
        my_app->get_logged_user()->add_star_filter(arg);
    }
    catch (Hotel_Exceptions& err){
        err.handle_error();
    }

    string args = "true";
    res = Response::redirect("/home");
    res->setSessionId(my_app->get_logged_user()->get_username());
    res->setHeader("error", args);
    return res;
}

Response *Wallet::callback(Request *req) {
    auto *res = new Response;
    res->setHeader("Content-Type", "text/html");

    string user_name = req->getSessionId();

    vector<float> wallet_history;
    string error;
    try {
        my_app->set_logged_user(user_name);
        wallet_history = my_app->get_wallet();
    }
    catch (Hotel_Exceptions &err) {
        error = err.handle_error();
    }
    reverse(wallet_history.begin(), wallet_history.end());

    ostringstream body;
    body
            << "<!DOCTYPE html>" << endl
            << "<html>" << endl
            << "<body>" << endl;
            if(!error.empty()){
                body
                    << "Error Is: " << error << endl;
            }
    body
            << "<form action=\"/new_wallet\" method=\"post\">" << endl
            << "Deposite money to Account? : <input name=\"new_wallet\" type=\"text\" placeholder=\"Amount\" />" << endl
            << "<button type=\"submit\">Submit Your History</button>" << endl
            << "</form>" << endl

            << "<form action=\"/home\" method=\"get\">" << endl
            << "<button type=\"submit\">Return Home</button>" << endl
            << "</form>" << endl

            << "<table>" << endl;
    if(wallet_history.size() <= 1){
        body
                << "You Have No History!" << endl;
    }
    else {
        for (int i=0; i < wallet_history.size(); i++) {
            body
                    << "<tr>" << endl
                    << "<td>" << endl
                    << "History number: " << i+1 << " is:" << wallet_history[i] << endl
                    << "</td>" << endl
                    << "</tr>" << endl;
        }
    }
    body
            << "</table>" <<endl
            << "</body>" << endl
            << "</html>" << endl;
    res->setSessionId(my_app->get_logged_user()->get_username());
    res->setBody(body.str());
    return res;
}

bool isFloat( const string& myString ) {
    std::istringstream iss(myString);
    float f;
    iss >> noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}

Response *AddWallet::callback(Request *req) {
    string user_name = req->getSessionId();
    string new_wallet = req->getBodyParam("new_wallet");

    if(!isFloat(new_wallet)){
        return Response::redirect("/wallet");
    }

    try {
        my_app->set_logged_user(user_name);
        my_app->add_wallet(new_wallet);
    }
    catch (Hotel_Exceptions &err) {
        err.handle_error();
    }
    return Response::redirect("/wallet");
}

Response *HotelDetail::callback(Request *req) {

    auto *res = new Response;
    res->setHeader("Content-Type", "text/html");

    string hotel_id = req->getBodyParam("hotel_name");
    string user_name = req->getSessionId();

    vector<string> room_names = {"Standard Room", "Deluxe Room", "Luxury Room", "Premium Room"};
    Hotel *hotel = nullptr;
    try {
        my_app->set_logged_user(user_name);
        hotel = my_app->get_hotel(hotel_id);
    }
    catch (Hotel_Exceptions &err) {
        err.handle_error();
    }
    vector<int> room_detail = hotel->get_rooms_details();
    ostringstream body;
    body
            << "<!DOCTYPE html>" << endl
            << "<html>" << endl
            << "<body>" << endl
            << "<table>" << endl
            << "<tr>" << endl
            << "<td>" << endl
            << "<img src=" << hotel->get_image() << endl
            << "<br />" << endl
            << "<br />" << endl
            << "Property Name: " << hotel->get_name() << endl
            << "<br />" << endl
            << "Hotel Star Rating: " << hotel->get_star_rating() << endl
            << "<br />" << endl
            << "City: " << hotel->get_city() << endl
            << "<br />" << endl
            << "Property Amenities: " << hotel->get_amenities() << endl
            << "<br />" << endl

            << "<table>" << endl;
            for(int i = 0; i < room_detail.size(); i = i + 2) {
                body
                    << "<td>" << endl
                    << "<tr>" << endl
                    << "Number of " << room_names[i/2] << " Are " << room_detail[i] << " and With Price of: " << room_detail[i+1] << endl
                    << "<br/>" << endl
                    << "</tr>" << endl
                    << "</td>" << endl;
            }
    body
            << "</table>" <<endl
            << "Hotel Over View: " << endl
            << "<br/>" << endl
            << hotel->get_overview() << endl
            << "</td>" << endl
            << "</tr>" << endl
            << "</table>" <<endl
            << "<br/> <br/>" << endl

            << "<form action=\"/home\" method=\"get\">" << endl
            << "<button type=\"submit\">Return Home</button>" << endl
            << "</form>" << endl

            << "</body>" << endl
            << "</html>" << endl;
    res->setBody(body.str());
    return res;
}
