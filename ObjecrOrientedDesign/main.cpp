#include "Google_read.h"
#include "Google_read.cpp"

using namespace std;


int main() {
    Google_read all_data = Google_read("./Assets/authors.csv", "./Assets/books.csv", "./Assets/users.csv",
                                       "./Assets/reviews.csv");

//    all_data.show_author_info(1122);
    all_data.show_sorted_shelf(8, "currently_reading", "Fiction");
//    all_data.show_user_credit(123);
}





