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

ReservationSystem::ReservationSystem(const std::string &file_path_hotel, const std::string& file_path_rating) {
    parse_hotel(file_path_hotel);
    parse_rating(file_path_rating);
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

void ReservationSystem::parse_hotel(const string& file_path_hotel) {
    int number_of_columns = 0;
    vector<string> hotel_information = read_csv_file(file_path_hotel, number_of_columns);

    for (int i = 0; i < hotel_information.size(); i += number_of_columns) {
        vector<string> new_hotel_information;
        new_hotel_information.reserve(number_of_columns);
        for (int j = 0; j < number_of_columns; j++) {
            new_hotel_information.push_back(hotel_information[i + j]);
        }
        auto* new_hotel = new Hotel(new_hotel_information);
        hotels.push_back(new_hotel);
    }
}

void ReservationSystem::parse_rating(const string& file_path_rating) {
    int number_of_columns = 0;
    vector<string> rating_information = read_csv_file(file_path_rating, number_of_columns);

    for (int i = 0; i < rating_information.size(); i += number_of_columns) {
        vector<string> new_rating_information;
        new_rating_information.reserve(number_of_columns);
        for (int j = 0; j < number_of_columns; j++) {
            new_rating_information.push_back(rating_information[i + j]);
        }
        find_hotel_by_id(new_rating_information[0])->save_rating(new_rating_information);
    }

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
                case filters:
                    return post_filters(arg);
                case reserves:
                    return post_reserves(arg);
                case comments:
                    return post_comments(arg);
                case ratings:
                    return post_rating(arg);
                case default_price_filter:
                    return post_default_filter_price(arg);
                case sort:
                    return post_sort(arg);
                case manual_weights:
                    return post_manual_weights(arg);
                default:
                    throw Hotel_Exceptions(NOT_FOUND);
            }
        }
        case GET: {
            switch(resolve_command(command)){
                case wallet:
                    return get_wallet(arg);
                case show_hotels:
                    return get_hotels(arg);
                case reserves:
                    return get_reserves(arg);
                case comments:
                    return get_comments(arg);
                case ratings:
                    return get_ratings(arg);
                case manual_weights:
                    return get_manual_weights(arg);
                default:
                    throw Hotel_Exceptions(NOT_FOUND);
            }
        }
        case DELETE: {
            switch(resolve_command(command)) {
                case filters:
                    return delete_filters(arg);
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
    if( command == "default_price_filter" ) return default_price_filter;
    if( command == "sort" ) return sort;
    if( command == "manual_weights" ) return manual_weights;
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
    check_logged_user();
    logged_user = nullptr;
}

void ReservationSystem::post_wallet(std::stringstream &arg) {
    vector<string> args = resolve_arguments(arg);
    float amount = 0;
    check_logged_user();
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
    check_logged_user();
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
    check_logged_user();
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
    check_logged_user();
    for(int i = 0; i < args.size(); i += 2) {
        if(args[i] == "hotel")
            hotel_id = args[i+1];
        else throw Hotel_Exceptions(BAD_REQUEST);
    }
    find_hotel_by_id(hotel_id)->show_comments();
}

void ReservationSystem::post_rating(std::stringstream &arg) {
    vector<string> args = resolve_arguments(arg);
    float location = 0, cleanliness = 0, staff = 0, facilities = 0, value_for_money = 0;
    float overall_Rating = 0;
    string hotel;
    check_logged_user();
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
    logged_user->add_rating(hotel, location, cleanliness, staff, facilities, value_for_money, overall_Rating);
    cout << "OK" << endl;
}

void ReservationSystem::get_ratings(std::stringstream &arg) {
    vector<string> args = resolve_arguments(arg);
    string hotel;
    check_logged_user();
    for(int i = 0; i < args.size(); i += 2) {
        if (args[i] == "hotel")
            hotel = args[i + 1];
        else
            throw Hotel_Exceptions(BAD_REQUEST);
    }
    find_hotel_by_id(hotel)->show_ratings();
}

void ReservationSystem::post_reserves(std::stringstream &arg) {
    vector<string> args = resolve_arguments(arg);
    int quantity = 0, check_in = 0, check_out = 0;
    string hotel, type;
    check_logged_user();
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
    vector<Room*> reserved_rooms = find_hotel_by_id(hotel)->reserve_rooms(type, quantity, check_in, check_out);
    logged_user->reserve_rooms(hotel, reserved_rooms);
    logged_user->decreasing_wallet(float(quantity * reserved_rooms[0]->get_price()));
}

void ReservationSystem::get_reserves(std::stringstream &arg) {
    check_logged_user();
    return logged_user->show_reserves();
}

void ReservationSystem::delete_reserve(std::stringstream &arg) {
    vector<string> args = resolve_arguments(arg);
    int id = 0;
    check_logged_user();
    for(int i = 0; i < args.size(); i += 2) {
        if (args[i] == "id")
            id = stoi(args[i + 1]);
        else
            throw Hotel_Exceptions(BAD_REQUEST);
    }
     userReservation* reserve =  logged_user->delete_reserve(id);
    find_hotel_by_id(reserve->get_hotel())->reset_reserve(reserve->get_reserve_rooms());
    cout << "OK" << endl;
}

void ReservationSystem::post_filters(std::stringstream &arg) {
    vector<string> args = resolve_arguments(arg);
    check_logged_user();
    switch (resolve_filter_type(args)) {
        case city: {
            logged_user->add_city_filter(args);
            break;
        }
        case star: {
            logged_user->add_star_filter(args);
            break;
        }
        case cost: {
            logged_user->add_cost_filter(args);
            break;
        }
        case room: {
            logged_user->add_room_filter(args);
            break;
        }
        default:
            throw Hotel_Exceptions(BAD_REQUEST);
    }
    cout << "OK" << endl;
}

ReservationSystem::Filters ReservationSystem::resolve_filter_type(const vector<string>& args){
    if(args[0] == "city")
        return city;
    else if(args[0] == "min_star" || args[0] == "max_star")
        return star;
    else if(args[0] == "min_price" || args[0] == "max_price")
        return cost;
    else if(args[0] == "type" || args[0] == "quantity" || args[0] == "check_in" || args[0] == "check_out")
        return room;
    else
        return invalid_filter;
}

void ReservationSystem::delete_filters(std::stringstream &arg) {
    check_logged_user();
    logged_user->delete_filters();
    cout << "OK" << endl;
}

void ReservationSystem::get_hotels(std::stringstream &arg) {
    vector<string> args = resolve_arguments(arg);
    check_logged_user();
    switch (resolve_hotel_command(args)) {
        case one: {
            print_one_hotel(args);
            break;
        }
        case all: {
            print_filter_hotels();
            break;
        }
        case invalid: {
            throw Hotel_Exceptions(BAD_REQUEST);
        }
    }

}

ReservationSystem::GetHotelType ReservationSystem::resolve_hotel_command(const vector<string>& args){
    if(args.empty())
        return all;
    else if (args[0] == "id")
        return one;
    else
        return invalid;
}

void ReservationSystem::print_one_hotel(const vector<string>& args){
    string id;
    for(int i = 0; i < args.size(); i += 2) {
        if (args[i] == "id")
            id = args[i + 1];
        else
            throw Hotel_Exceptions(BAD_REQUEST);
    }
    find_hotel_by_id(id)->print_hotel();
}

void ReservationSystem::print_filter_hotels(){
    check_logged_user();
    vector<Hotel*> filtered_hotels = filter_hotels();
    if(filtered_hotels.empty())
        throw Hotel_Exceptions(EMPTY);
    std::sort(filtered_hotels.begin(), filtered_hotels.end(), logged_user->get_sort_function());
    if(check_default_filter())
        cout << "* Results have been filtered by the default price filter." << endl;
    for(auto hotel : filtered_hotels)
        hotel->print_summery_of_hotel();
}

vector<Hotel*> ReservationSystem::filter_hotels(){
    check_logged_user();
    vector<Hotel*> filtered_hotels = hotels;
    auto filters = logged_user->get_filters();
    for(auto filter : filters) {
        if(filter->get_name() == DEFAULT_FILTER)
            if(!logged_user->check_default_filter())
                continue;
        filtered_hotels = filter->apply(filtered_hotels);
    }
    return filtered_hotels;
}

void ReservationSystem::post_default_filter_price(std::stringstream &arg) {
    vector<string> args = resolve_arguments(arg);
    check_logged_user();
    string status;
    for(int i = 0; i < args.size(); i += 2) {
        if (args[i] == "active")
            status = args[i + 1];
        else
            throw Hotel_Exceptions(BAD_REQUEST);
    }
    logged_user->status_default_filter_price(status);
    cout << "OK" << endl;
}

bool ReservationSystem::check_default_filter() {
    return logged_user->check_default_filter();
}

void ReservationSystem::post_sort(std::stringstream &arg) {
    vector<string> args = resolve_arguments(arg);
    check_logged_user();
    string sort_property, order;
    for(int i = 0; i < args.size(); i += 2) {
        if (args[i] == "property")
            sort_property = args[i + 1];
        else if(args[i] == "order")
            order = args[i + 1];
        else
            throw Hotel_Exceptions(BAD_REQUEST);
    }
    logged_user->save_sort_order(sort_property, order);
    cout << "OK" << endl;
}

void ReservationSystem::check_logged_user(){
    if(logged_user == nullptr)
        throw Hotel_Exceptions(PERMISSION_DENIED);
}

void ReservationSystem::post_manual_weights(std::stringstream &arg) {
    vector<string> args = resolve_arguments(arg);
    check_logged_user();
    string status;
    float location = 0, cleanliness = 0, staff = 0, facilities = 0, value_for_money = 0;
    for(int i = 0; i < args.size(); i += 2) {
        if(status == "false")
            return logged_user->off_rating_weights();
        if (args[i] == "active")
            status = args[i + 1];
        else if(args[i] == "location")
            location = stof(args[i + 1]);
        else if(args[i] == "cleanliness")
            cleanliness = stof(args[i + 1]);
        else if(args[i] == "staff")
            staff = stof(args[i + 1]);
        else if(args[i] == "facilities")
            facilities = stof(args[i + 1]);
        else if(args[i] == "value_for_money")
            value_for_money = stof(args[i + 1]);
        else
            throw Hotel_Exceptions(BAD_REQUEST);
    }
    if((location < 1 || location > 5) || (cleanliness < 1 || cleanliness > 5) || (staff < 1 || staff > 5) || (facilities < 1 || facilities > 5) || (value_for_money < 1 || value_for_money > 5))
        throw Hotel_Exceptions(BAD_REQUEST);

    logged_user->save_rating_weights(status, location, cleanliness, staff, facilities, value_for_money);
    cout << "OK" << endl;
}

void ReservationSystem::get_manual_weights(std::stringstream &arg) {
    check_logged_user();
    logged_user->show_rating_weights();
}
