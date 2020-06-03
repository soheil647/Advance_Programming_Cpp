#include "../header/reservationSystem.hpp"

using namespace std;

vector<string> ReservationSystem::read_csv_file(const string &filePath, int &columnsNumber) {

    ifstream inputFile(filePath);
    if (inputFile.fail()) {
        cerr << "Error Opening the file" << endl;
        inputFile.close();
        exit(1);
    }
    vector<string> row;
    string line, word, temp;

    getline(inputFile, line);
    columnsNumber = int(count(line.begin(), line.end(), ',') + 1);
    while (getline(inputFile, line)) {
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
    }
    return row;
}

ReservationSystem::ReservationSystem(const std::string &file_path) {
    int number_of_columns = 0;
    vector<string> hotel_information = read_csv_file(file_path, number_of_columns);

    for (int i = 0; i < hotel_information.size(); i += number_of_columns) {
        vector<string> new_hotel_information;
        new_hotel_information.reserve(number_of_columns);
        for (int j = 0; j < number_of_columns; j++) {
            new_hotel_information.push_back(hotel_information[i + j]);
        }
        auto* new_hotel = new Hotel(new_hotel_information);
        hotels.push_back(new_hotel);
    }
    logged_user = nullptr;
}

void ReservationSystem::parse_command(stringstream& input_line) {
    string word;
    getline(input_line, word, ' ');
    string method = word;
    getline(input_line, word, ' ');
    string command = word;
    getline(input_line, word, ' ');

    return find_command_action(input_line, method, command);
}

void ReservationSystem::find_command_action(stringstream& arg, const string& method, const string& command) {
    switch(resolve_method(method)) {
        case POST: {
            switch(resolve_command(command)){
                case signup:
                    return post_signup(arg);
                case login:
                    return post_login(arg);
                case logout:
                    return post_logout(arg);
                case wallet:
                    return post_wallet(arg);
//                case filters:
//                    return post_filters(arg);
                case reserves:
                    return post_reserves(arg);
                case comments:
                    return post_comments(arg);
                case ratings:
                    return post_rating(arg);
                default:
                    throw Hotel_Exceptions(NOT_FOUND);
            }
        }
        case GET: {
            switch(resolve_command(command)){
                case wallet:
                    return get_wallet(arg);
//                case show_hotels:
//                    return get_hotels(arg);
                case reserves:
                    return get_reserves(arg);
                case comments:
                    return get_comments(arg);
                case ratings:
                    return get_ratings(arg);
                default:
                    throw Hotel_Exceptions(NOT_FOUND);
            }
        }
        case DELETE: {
            switch(resolve_command(command)) {
//                case filters:
//                    return delete_filters(arg);
                case reserves:
                    return delete_reserve(arg);
                default:
                    throw Hotel_Exceptions(NOT_FOUND);
            }
        }
        default: {
            throw Hotel_Exceptions(BAD_REQUEST);
        }
    }

}

ReservationSystem::Methods ReservationSystem::resolve_method(const std::string& method) {
    if( method == "POST" ) return POST;
    if( method == "GET" ) return GET;
    if( method == "DELETE" ) return DELETE;
    return invalid_method;
}

ReservationSystem::Commands ReservationSystem::resolve_command(const std::string& command) {
    if( command == "signup" ) return signup;
    if( command == "login" ) return login;
    if( command == "logout" ) return logout;
    if( command == "wallet" ) return wallet;
    if( command == "hotels" ) return show_hotels;
    if( command == "filters" ) return filters;
    if( command == "reserves" ) return reserves;
    if( command == "comments" ) return comments;
    if( command == "ratings" ) return ratings;
    return invalid_command;
}

vector<string> ReservationSystem::resolve_arguments(std::stringstream &arg){
    string word;
    vector<string> args;
    while(getline(arg, word, ' ')){
        args.push_back(word);
    }
    return args;
}

void ReservationSystem::post_signup(std::stringstream &arg) {
    vector<string> args = resolve_arguments(arg);
    string _email, _username, _password;
    for(int i = 0; i < args.size(); i += 2){
        if(args[i] == "email")
            _email = args[i+1];
        else if(args[i] == "username")
            _username = args[i+1];
        else if(args[i] == "password")
            _password = args[i+1];
        else throw Hotel_Exceptions(BAD_REQUEST);
    }

    User* new_user = new User(_email, _username, _password);
    for(User *user : users){
        if(user->operator==(*new_user))
            throw Hotel_Exceptions(BAD_REQUEST);
    }
    users.push_back(new_user);
    logged_user = new_user;
    cout << "OK" << endl;
}

void ReservationSystem::post_login(std::stringstream &arg) {
    vector<string> args = resolve_arguments(arg);
    string _email, _username, _password;
    for(int i = 0; i < args.size(); i += 2) {
        if(args[i] == "email")
            _email = args[i+1];
        else if(args[i] == "password")
            _password = args[i+1];
        else throw Hotel_Exceptions(BAD_REQUEST);
    }
    for(User *user : users) {
        if(user->compare_login(_email, _password)) {
            logged_user = user;
            cout << "OK" << endl;
            return;
        }
    }
    throw Hotel_Exceptions(BAD_REQUEST);
}

void ReservationSystem::post_logout(std::stringstream &arg) {
    if(logged_user == nullptr)
        throw Hotel_Exceptions(PERMISSION_DENIED);
    logged_user = nullptr;
    cout << "OK" << endl;
}

void ReservationSystem::post_wallet(std::stringstream &arg) {
    vector<string> args = resolve_arguments(arg);
    float amount = 0;
    if(logged_user == nullptr)
        throw Hotel_Exceptions(PERMISSION_DENIED);
    for(int i = 0; i < args.size(); i += 2) {
        if(args[i] == "amount")
            amount = stof(args[i+1]);
        else throw Hotel_Exceptions(BAD_REQUEST);
    }
    logged_user->charging_wallet(amount);
    cout << "OK" << endl;
}

void ReservationSystem::get_wallet(std::stringstream &arg) {
    vector<string> args = resolve_arguments(arg);
    int count = 0;
    if(logged_user == nullptr)
        throw Hotel_Exceptions(PERMISSION_DENIED);
    for(int i = 0; i < args.size(); i += 2) {
        if(args[i] == "count")
            count = stoi(args[i+1]);
        else throw Hotel_Exceptions(BAD_REQUEST);
    }
    logged_user->show_wallet_history(count);
    cout << "OK" << endl;
}

void ReservationSystem::post_comments(std::stringstream &arg) {
    vector<string> args = resolve_arguments(arg);
    string new_comment;
    string hotel_id;
    if(logged_user == nullptr)
        throw Hotel_Exceptions(PERMISSION_DENIED);
    for(int i = 0; i < args.size(); i += 2) {
        if(args[i] == "comment")
            new_comment = args[i+1];
        else if(args[i] == "hotel")
            hotel_id = args[i+1];
        else throw Hotel_Exceptions(BAD_REQUEST);
    }
    find_hotel_by_id(hotel_id)->get_new_comment(logged_user->get_username(), new_comment);
    cout << "OK" << endl;
}

Hotel* ReservationSystem::find_hotel_by_id(const string& hotel_id) {
    for(Hotel* hotel : hotels) {
        if (hotel->get_id() == hotel_id)
            return hotel;
    }
    throw Hotel_Exceptions(NOT_FOUND);
}

void ReservationSystem::get_comments(std::stringstream &arg) {
    vector<string> args = resolve_arguments(arg);
    string hotel_id;
    if(logged_user == nullptr)
        throw Hotel_Exceptions(PERMISSION_DENIED);
    for(int i = 0; i < args.size(); i += 2) {
        if(args[i] == "hotel")
            hotel_id = args[i+1];
        else throw Hotel_Exceptions(BAD_REQUEST);
    }
    find_hotel_by_id(hotel_id)->show_comments();
    cout << "OK" << endl;
}

void ReservationSystem::post_rating(std::stringstream &arg) {
    vector<string> args = resolve_arguments(arg);
    float location = 0, cleanliness = 0, staff = 0, facilities = 0, value_for_money = 0, overall_Rating = 0;
    string hotel;
    if(logged_user == nullptr)
        throw Hotel_Exceptions(PERMISSION_DENIED);
    for(int i = 0; i < args.size(); i += 2) {
        if(args[i] == "hotel")
            hotel = args[i+1];
        else if((stof(args[i+1]) < 1 || stof(args[i+1]) > 5))
            throw Hotel_Exceptions(BAD_REQUEST);
        else if(args[i] == "location")
            location = stof(args[i+1]);
        else if(args[i] == "cleanliness")
            cleanliness = stof(args[i+1]);
        else if(args[i] == "staff")
            staff = stof(args[i+1]);
        else if(args[i] == "facilities")
            facilities = stof(args[i+1]);
        else if(args[i] == "value_for_money")
            value_for_money = stof(args[i+1]);
        else if(args[i] == "overall_rating")
            overall_Rating = stof(args[i+1]);
    }
    find_hotel_by_id(hotel)->get_new_rating(location, cleanliness, staff, facilities, value_for_money, overall_Rating);
    cout << "OK" << endl;
}

void ReservationSystem::get_ratings(std::stringstream &arg) {
    vector<string> args = resolve_arguments(arg);
    string hotel;
    if(logged_user == nullptr)
        throw Hotel_Exceptions(PERMISSION_DENIED);
    for(int i = 0; i < args.size(); i += 2) {
        if (args[i] == "hotel")
            hotel = args[i + 1];
        else
            throw Hotel_Exceptions(BAD_REQUEST);
    }
    find_hotel_by_id(hotel)->show_ratings();
    cout << "OK" << endl;
}

void ReservationSystem::post_reserves(std::stringstream &arg) {
    vector<string> args = resolve_arguments(arg);
    int quantity = 0, check_in = 0, check_out = 0;
    string hotel, type;
    if(logged_user == nullptr)
        throw Hotel_Exceptions(PERMISSION_DENIED);
    for(int i = 0; i < args.size(); i += 2) {
        if (args[i] == "hotel")
            hotel = args[i + 1];
        else if (args[i] == "type")
            type = args[i + 1];
        else if (args[i] == "quantity")
            quantity = stoi(args[i + 1]);
        else if (args[i] == "check_in")
            check_in = stoi(args[i + 1]);
        else if (args[i] == "check_out")
            check_out = stoi(args[i + 1]);
        else
            throw Hotel_Exceptions(BAD_REQUEST);
    }
    if(logged_user->get_wallet() < float(quantity * find_hotel_by_id(hotel)->get_room_price(type)))
        throw Hotel_Exceptions(NOT_ENOUGH_CREDIT);
    int price = find_hotel_by_id(hotel)->reserve_rooms(type, quantity, check_in, check_out);
    logged_user->reserve_rooms(hotel, type, quantity, price, check_in, check_out);
    logged_user->decreasing_wallet(float(quantity * price));
}

void ReservationSystem::get_reserves(std::stringstream &arg) {
    if(logged_user == nullptr)
        throw Hotel_Exceptions(PERMISSION_DENIED);
    return logged_user->show_reserves();
}

void ReservationSystem::delete_reserve(std::stringstream &arg) {
    vector<string> args = resolve_arguments(arg);
    int id = 0;
    if(logged_user == nullptr)
        throw Hotel_Exceptions(PERMISSION_DENIED);
    for(int i = 0; i < args.size(); i += 2) {
        if (args[i] == "id")
            id = stoi(args[i + 1]);
        else
            throw Hotel_Exceptions(BAD_REQUEST);
    }
     userReservation* reserve =  logged_user->delete_reserve(id);
    find_hotel_by_id(reserve->get_hotel())->reset_reserve();
}
