#include "../header/hotel.hpp"

using namespace std;

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
            property_amenities = word;
        if (column_number == 5)
            city = word;
        if (column_number == 6)
            latitude = stof(word);
        if (column_number == 7)
            longitude = stof(word);
        if (column_number == 8)
            image_url = word;
        if (column_number == 9)
            number_standard_room = stoi(word);
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

void Hotel::assign_rooms_ids() {
    for (int room_number = 1; room_number <= number_standard_room; room_number++)
        standard_rooms.push_back(new Room("s" + to_string(room_number), standard_room_price, "standard"));
    for (int room_number = 1; room_number <= number_deluxe_room; room_number++)
        deluxe_rooms.push_back(new Room("d" + to_string(room_number), deluxe_room_price, "deluxe"));
    for (int room_number = 1; room_number <= number_luxury_room; room_number++)
        luxury_rooms.push_back(new Room("l" + to_string(room_number), luxury_room_price, "luxury"));
    for (int room_number = 1; room_number <= number_premium_room; room_number++)
        premium_rooms.push_back(new Room("p" + to_string(room_number), premium_room_price, "premium"));
}

void Hotel::get_new_comment(const string &username, const string &comment) {
    map<string, string> new_comment;
    new_comment[username] = comment;
    this->comments.push_back(new_comment);
}

string Hotel::get_id() {
    return this->unique_id;
}

void Hotel::show_comments() {
    reverse(this->comments.begin(), this->comments.end());
    for (auto &comment : this->comments) {
        for (auto &comment_value : comment)
            cout << comment_value.first << ": " << comment_value.second << endl;
    }
    reverse(this->comments.begin(), this->comments.end());
}

void Hotel::get_new_rating(float location, float cleanliness, float staff, float facilities, float value_for_money,
                           float overall_Rating) {
    ratings.push_back(
            new Ratings(this->unique_id, location, cleanliness, staff, facilities, value_for_money, overall_Rating));
}

void Hotel::show_ratings() {
    file_rating->show_rating();
}

vector<Room *> Hotel::reserve_rooms(const std::string &room_type, int room_quantity, int check_in, int check_out) {
    vector<Room *> wanted_rooms;
    switch (resolve_room_type(room_type)) {
        case standard: {
            if (room_quantity > number_standard_room)
                throw Hotel_Exceptions(NOT_ENOUGH_ROOM);
            int reserved = 0;
            for (int i = 0; i < number_standard_room; i++) {
                if (standard_rooms[i]->reserve_room(check_in, check_out)) {
                    wanted_rooms.push_back(standard_rooms[i]);
                    reserved += 1;
                }
                if (reserved == room_quantity)
                    return print_reserved_rooms(wanted_rooms);
            }
            break;
        }
        case deluxe: {
            if (room_quantity > number_deluxe_room)
                throw Hotel_Exceptions(NOT_ENOUGH_ROOM);
            int reserved = 0;
            for (int i = 0; i < number_deluxe_room; i++) {
                if (deluxe_rooms[i]->reserve_room(check_in, check_out)) {
                    wanted_rooms.push_back(deluxe_rooms[i]);
                    reserved += 1;
                }
                if (reserved == room_quantity)
                    return print_reserved_rooms(wanted_rooms);
            }
            break;
        }
        case luxury: {
            if (room_quantity > number_luxury_room)
                throw Hotel_Exceptions(NOT_ENOUGH_ROOM);
            int reserved = 0;
            for (int i = 0; i < number_luxury_room; i++) {
                if (luxury_rooms[i]->reserve_room(check_in, check_out)) {
                    wanted_rooms.push_back(luxury_rooms[i]);
                    reserved += 1;
                }
                if (reserved == room_quantity)
                    return print_reserved_rooms(wanted_rooms);
            }
            break;
        }
        case premium: {
            if (room_quantity > number_premium_room)
                throw Hotel_Exceptions(NOT_ENOUGH_ROOM);
            int reserved = 0;
            for (int i = 0; i < number_premium_room; i++) {
                if (premium_rooms[i]->reserve_room(check_in, check_out)) {
                    wanted_rooms.push_back(premium_rooms[i]);
                    reserved += 1;
                }
                if (reserved == room_quantity)
                    return print_reserved_rooms(wanted_rooms);
            }
            break;
        }
        default:
            throw (Hotel_Exceptions(BAD_REQUEST));
    }
    reset_reserved_rooms(wanted_rooms);
    throw Hotel_Exceptions(NOT_ENOUGH_ROOM);
}

Hotel::RoomType Hotel::resolve_room_type(const std::string &type) {
    if (type == "standard") return standard;
    if (type == "deluxe") return deluxe;
    if (type == "luxury") return luxury;
    if (type == "premium") return premium;
    return invalid_type;
}

vector<Room *> Hotel::print_reserved_rooms(const std::vector<Room *> &reserved_rooms) {
    if (reserved_rooms.size() == 1)
        cout << reserved_rooms[0]->get_id() << " ";
    else {
        for (Room *room : reserved_rooms) {
            cout << room->get_id() << " ";
        }
    }
    cout << endl;
    return reserved_rooms;
}

void Hotel::reset_reserved_rooms(const std::vector<Room *> &reserved_rooms) {
    for (Room *room : reserved_rooms)
        room->reset_room_reservation();
}

int Hotel::get_room_price(const string &room_type) {
    switch (resolve_room_type(room_type)) {
        case standard:
            return standard_room_price;
        case deluxe:
            return deluxe_room_price;
        case luxury:
            return luxury_room_price;
        case premium:
            return premium_room_price;
        case invalid_type:
            throw Hotel_Exceptions(BAD_REQUEST);
    }
}

void Hotel::reset_reserve(const std::vector<Room *> &reserved_rooms) {
    reset_reserved_rooms(reserved_rooms);
}

bool Hotel::check_city_name(const string &city_name) {
    return city_name == this->city;
}

bool Hotel::check_star(int min_star, int max_star) {
    return min_star <= this->hotel_star_rating && this->hotel_star_rating <= max_star;
}

bool Hotel::check_average_price(float min_price, float max_price) {
    float sum_of_price = 0;
    int number_of_room_type = 0;
    if (this->standard_room_price != 0)
        number_of_room_type += 1;
    if (this->deluxe_room_price != 0)
        number_of_room_type += 1;
    if (this->luxury_room_price != 0)
        number_of_room_type += 1;
    if (this->premium_room_price != 0)
        number_of_room_type += 1;

    sum_of_price = float(standard_room_price + deluxe_room_price + luxury_room_price + premium_room_price);
    float average_price = sum_of_price / float(number_of_room_type);
    return min_price <= average_price && average_price <= max_price;
}

float Hotel::find_average_price() {
    float sum_of_price = 0;
    float number_of_room_type = 0;
    if (this->standard_room_price != 0)
        number_of_room_type += 1;
    if (this->deluxe_room_price != 0)
        number_of_room_type += 1;
    if (this->luxury_room_price != 0)
        number_of_room_type += 1;
    if (this->premium_room_price != 0)
        number_of_room_type += 1;

    sum_of_price = float(standard_room_price + deluxe_room_price + luxury_room_price + premium_room_price);
    if (number_of_room_type == 0)
        return 0;
    float average = sum_of_price / number_of_room_type;
    return average;
}

bool Hotel::check_available_room(const std::string &room_type, int quantity, int check_in, int check_out) {
    vector<Room *> wanted_rooms = get_rooms_of_type(room_type);
    int number_of_available_room = 0;
    for (auto room : wanted_rooms) {
        if (room->check_availability(check_in, check_out))
            number_of_available_room += 1;
    }
    return number_of_available_room >= quantity;
}

vector<Room *> Hotel::get_rooms_of_type(const std::string &room_type) {
    vector<Room *> wanted_rooms;
    switch (resolve_room_type(room_type)) {
        case standard: {
            wanted_rooms = standard_rooms;
            break;
        }
        case deluxe: {
            wanted_rooms = deluxe_rooms;
            break;
        }
        case luxury: {
            wanted_rooms = luxury_rooms;
            break;
        }
        case premium: {
            wanted_rooms = premium_rooms;
            break;
        }
        default:
            throw Hotel_Exceptions(BAD_REQUEST);
    }
    return wanted_rooms;
}

void Hotel::print_hotel() {
    cout << this->unique_id << endl;
    cout << this->property_name << endl;
    cout << "star: " << this->hotel_star_rating << endl;
    cout << "overview: " << this->hotel_overview << endl;
    cout << "amenities: " << this->property_amenities << endl;
    cout << "city: " << this->city << endl;
    cout << setprecision(2) << fixed;
    cout << "latitude: " << this->latitude << endl;
    cout << "longitude: " << this->longitude << endl;
    cout << "#rooms: " << number_standard_room << " " << number_deluxe_room << " " << number_luxury_room << " "
         << number_premium_room << endl;
    cout << "price: " << standard_room_price << " " << deluxe_room_price << " " << luxury_room_price << " "
         << premium_room_price << endl;
}

void Hotel::print_summery_of_hotel() {
    int total_number_of_rooms = number_standard_room + number_deluxe_room + number_luxury_room + number_premium_room;
    cout << this->unique_id << " " << this->property_name << " " << this->hotel_star_rating << " " << this->city << " ";
    cout << total_number_of_rooms << " ";
    cout << setprecision(2) << fixed;
    cout << find_average_price() << " " << endl;
}

bool Hotel::check_default_price(float mean, float variance) {
    float average_price = find_average_price();
    return abs(average_price - mean) <= 2 * variance;
}

string Hotel::get_name() { return this->property_name; }

int Hotel::get_star_rating() { return this->hotel_star_rating; }

std::string Hotel::get_city() { return this->city; }

int Hotel::get_standard_price() { return this->standard_room_price; }

int Hotel::get_deluxe_price() { return this->deluxe_room_price; }

int Hotel::get_luxury_price() { return this->luxury_room_price; }

int Hotel::get_premium_price() { return this->premium_room_price; }

float Hotel::get_average_price() { return this->find_average_price(); }

void Hotel::save_rating(const std::vector<std::string> &rating_information) {
    int column_number = 0;
    string unique_info;
    float _location_rating = 0, _cleanliness_rating = 0, _staff_rating = 0, _facilities_rating = 0, _value_for_money_rating = 0;
    float _overall_rating = 0;
    for (const string &word : rating_information) {
        if (column_number == 0)
            unique_info = word;
        if (column_number == 1)
            _location_rating = stof(word);
        if (column_number == 2)
            _cleanliness_rating = stof(word);
        if (column_number == 3)
            _staff_rating = stof(word);
        if (column_number == 4)
            _facilities_rating = stof(word);
        if (column_number == 5)
            _value_for_money_rating = stof(word);
        if (column_number == 6)
            _overall_rating = stof(word);
        column_number++;
    }
    this->file_rating = new Ratings(unique_info, _location_rating, _cleanliness_rating, _staff_rating,
                                    _facilities_rating, _value_for_money_rating, _overall_rating);
}

float Hotel::get_rating(const std::vector<Ratings *> &user_ratings, RatingWeights *user_rating_weights ,RatingWeights* estimate_weights) {
    for (auto rate : user_ratings) {
        if (rate->get_hotel_id() == this->unique_id)
            return rate->get_overall_rate();
    }

    if (user_rating_weights->check_status())
        return personal_rating_by_weights(user_rating_weights);
    else {
        if(user_ratings.size() < 5)
            throw Hotel_Exceptions(INSUFFICIENT_RATINGS);
        return personal_rating_by_weights(estimate_weights);
    }
}

float Hotel::personal_rating_by_weights(RatingWeights *user_weights) {
    return file_rating->find_weighted_rate(user_weights);
}

std::string Hotel::get_image() {
    return this->image_url;
}

vector<int> Hotel::get_rooms_details() {
    vector<int> prices = {number_standard_room, standard_room_price, number_deluxe_room, deluxe_room_price, number_luxury_room, luxury_room_price, number_premium_room, premium_room_price};
    return prices;
}

string Hotel::get_amenities() {
    return this->property_amenities;
}

string Hotel::get_overview() {
    return this->hotel_overview;
}
