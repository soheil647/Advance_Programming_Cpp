#include "../header/hotel.hpp"

using namespace std;

struct Hotel::Rating {
    float location;
    float cleanliness;
    float staff;
    float facilities;
    float value_for_money;
    float overall_rating;
};


Hotel::Hotel(const vector<string> &information_path) {
    parse_hotel_information(information_path);
    assign_rooms_ids();
}

void Hotel::parse_hotel_information(const vector<string> &hotel_information) {
    int column_number = 0;
    for (const string &word : hotel_information) {
        if (column_number == 0)
            unique_id = word;
        if (column_number == 1)
            property_name = word;
        if (column_number == 2)
            hotel_star_rating = stoi(word);
        if (column_number == 3)
            hotel_overview = word;
        if (column_number == 4)
            parse_properties(word);
        if (column_number == 5)
            city = word;
        if (column_number == 6)
            latitude = stof(word);
        if (column_number == 7)
            longitude = stof(word);
        if (column_number == 8)
            image_url = word;
        if (column_number == 9) {
            number_standard_room = stoi(word);
            number_of_rooms.insert(make_pair("standard", stoi(word)));
        }
        if (column_number == 10)
            number_deluxe_room = stoi(word);
        if (column_number == 11)
            number_luxury_room = stoi(word);
        if (column_number == 12)
            number_premium_room = stoi(word);
        if (column_number == 13)
            standard_room_price = stoi(word);
        if (column_number == 14)
            deluxe_room_price = stoi(word);
        if (column_number == 15)
            luxury_room_price = stoi(word);
        if (column_number == 16)
            premium_room_price = stoi(word);
        column_number++;
    }
}

void Hotel::parse_properties(const string &properties) {
    stringstream s(properties);
    string word;
    vector<string> parse_properties;
    while (getline(s, word, '|')) {
        property_amenities.push_back(word);
    }
}

void Hotel::assign_rooms_ids() {
    for (int room_number = 0; room_number < number_standard_room; room_number++)
        standard_rooms.push_back(new Room("s" + to_string(room_number), standard_room_price));
    for (int room_number = 0; room_number < number_deluxe_room; room_number++)
        deluxe_rooms.push_back(new Room("d" + to_string(room_number), deluxe_room_price));
    for (int room_number = 0; room_number < number_luxury_room; room_number++)
        luxury_rooms.push_back(new Room("l" + to_string(room_number), luxury_room_price));
    for (int room_number = 0; room_number < number_premium_room; room_number++)
        premium_rooms.push_back(new Room("p" + to_string(room_number), premium_room_price));
}

void Hotel::get_new_comment(const string& username, const string& comment) {
    map<string, string> new_comment;
    new_comment[username] = comment;
    this->comments.push_back(new_comment);
}

string Hotel::get_id() {
    return this->unique_id;
}

void Hotel::show_comments() {
    reverse(this->comments.begin(), this->comments.end());
    for (auto & comment : this->comments) {
        for(auto &comment_value : comment)
            cout << comment_value.first << ": " << comment_value.second << endl;
    }
    reverse(this->comments.begin(), this->comments.end());
}

void Hotel::get_new_rating(float location, float cleanliness, float staff, float facilities, float value_for_money, float overall_Rating) {
    Rating new_rating = {.location=location, .cleanliness=cleanliness, .staff=staff, .facilities=facilities, .value_for_money=value_for_money, .overall_rating=overall_Rating};
    ratings.push_back(new_rating);
}

void Hotel::show_ratings() {
    float sum_location = 0, sum_cleanliness = 0, sum_facilities = 0, sum_staff = 0, sum_value_for_money = 0, sum_overall_rating = 0;
    float average_location = 0, average_cleanliness = 0, average_facilities = 0, average_staff = 0, average_value_for_money = 0, average_overall_rating = 0;
    int number_of_ratings = this->ratings.size();
    if(number_of_ratings == 0)
        throw Hotel_Exceptions(EMPTY);

    for(auto& rate : ratings) {
        sum_location += rate.location;
        sum_cleanliness += rate.cleanliness;
        sum_facilities += rate.facilities;
        sum_staff += rate.staff;
        sum_value_for_money += rate.value_for_money;
        sum_overall_rating += rate.overall_rating;
    }
    average_location = ((sum_location)/float(number_of_ratings));
    average_cleanliness = ((sum_cleanliness)/float(number_of_ratings));
    average_facilities = ((sum_facilities)/float(number_of_ratings));
    average_staff = ((sum_staff)/float(number_of_ratings));
    average_value_for_money = ((sum_value_for_money)/float(number_of_ratings));
    average_overall_rating = ((sum_overall_rating)/float(number_of_ratings));

    cout << "location: " << setprecision(2) << average_location << endl;
    cout << "cleanliness: " << setprecision(2) << average_cleanliness << endl;
    cout << "staff: " << setprecision(2) << average_staff << endl;
    cout << "facilities: " << setprecision(2) << average_facilities << endl;
    cout << "value for money: " << setprecision(2) << average_value_for_money << endl;
    cout << "overall rating: " << setprecision(2) << average_overall_rating << endl;
}

void Hotel::reserve_rooms(const std::string& room_type, int room_quantity, int check_in, int check_out) {
    vector<Room*> wanted_rooms;
    switch (resolve_room_type(room_type)){
        case standard: {
            if(room_quantity > number_standard_room)
                throw Hotel_Exceptions(NOT_ENOUGH_ROOM);
            int reserved = 0;
            for(int i = 0; i < number_standard_room; i++) {
                reserved += standard_rooms[i]->reserve_room(check_in, check_out);
                if(reserved == 1)
                    wanted_rooms.push_back(standard_rooms[i]);
                if(reserved == room_quantity)
                    return print_reserved_rooms(wanted_rooms);
            }
            break;
        }
        case deluxe:
            break;
        case luxury:
            break;
        case premium:
            break;
        default:
            throw (Hotel_Exceptions(BAD_REQUEST));
    }
    reset_reserved_rooms(wanted_rooms);
    throw Hotel_Exceptions(NOT_ENOUGH_ROOM);
}

Hotel::RoomType Hotel::resolve_room_type(const std::string &type) {
    if( type == "standard" ) return standard;
    if( type == "deluxe" ) return deluxe;
    if( type == "luxury" ) return luxury;
    if( type == "premium" ) return premium;
    return invalid_type;
}

void Hotel::print_reserved_rooms(const std::vector<Room *>& reserved_rooms) {
    for(Room* room : reserved_rooms)
        cout << room->get_id() << " ";
    cout << endl;
}

void Hotel::reset_reserved_rooms(const std::vector<Room *>& reserved_rooms) {
    for(Room* room : reserved_rooms)
        room->reset_room_reservation();
}
