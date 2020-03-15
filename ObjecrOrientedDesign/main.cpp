#include "Google_read.h"
#include <chrono>

using namespace std::chrono;

using namespace std;


int main(int argv, char *argc[]) {
    string assets_address = "./" + string(argc[1]);
    Google_read all_data = Google_read(assets_address + "/authors.csv", assets_address + "/books.csv",
                                       assets_address + "/users.csv", assets_address + "/reviews.csv");


    auto start = high_resolution_clock::now();
//    all_data.show_author_info(1121);
//    all_data.show_sorted_shelf(100, "currently_reading", "Fiction");
//    all_data.show_user_credit(123);
//    all_data.show_best_book();
//    all_data.show_best_reviewer();
    all_data.show_recommended_books(10);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << "Function Duration: " << duration.count() << endl;
}





