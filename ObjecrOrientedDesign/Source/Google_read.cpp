#include "Google_read.h"

using namespace std;


vector<string> Google_read::read_csv_file(const string &filePath, int &columnsNumber) {

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

void Google_read::parse_books_csv(const string &books_file_path) {
    int column_size = 0;
    vector<string> books_csv = read_csv_file(books_file_path, column_size);

    int column_number = 0;
    int temp_book_id = 0, temp_author_id = 0;
    string temp_title, temp_book_genres;
    for (const string &word : books_csv) {
        if (column_number == 0)
            temp_book_id = stoi(word);
        if (column_number == 1)
            temp_title = word;
        if (column_number == 2)
            temp_author_id = stoi(word);
        if (column_number == 3)
            temp_book_genres = word;
        column_number++;
        if (column_number == column_size) {
            books.emplace_back(Books(temp_book_id, temp_title, temp_author_id, temp_book_genres));
            column_number = 0;
        }
    }
}

void Google_read::parse_authors_csv(const string &author_file_path) {
    int column_size = 0;
    vector<string> authors_csv = read_csv_file(author_file_path, column_size);
    int column_number = 0;
    int temp_author_id = 0, temp_author_birth_year = 0;
    string temp_author_name, temp_author_gender, temp_member_since, temp_author_birth_place, temp_author_genres;
    for (const string &word : authors_csv) {
        if (column_number == 0)
            temp_author_id = stoi(word);
        if (column_number == 1)
            temp_author_name = word;
        if (column_number == 2)
            temp_author_gender = word;
        if (column_number == 3)
            temp_member_since = word;
        if (column_number == 4)
            temp_author_birth_year = stoi(word);
        if (column_number == 5)
            temp_author_birth_place = word;
        if (column_number == 6)
            temp_author_genres = word;
        column_number++;
        if (column_number == column_size) {
            authors.emplace_back(temp_author_id, temp_author_name, temp_author_gender, temp_member_since,
                            temp_author_birth_year, temp_author_birth_place, temp_author_genres);
            column_number = 0;
        }
    }
}

void Google_read::parse_users_csv(const string &users_file_path) {
    int column_size = 0;
    vector<string> users_csv = read_csv_file(users_file_path, column_size);

    int column_number = 0;
    int temp_user_id = 0;
    string temp_user_name, temp_user_birth_place, temp_user_member_since, temp_user_favorite_authors;
    string temp_user_want_to_read, temp_user_currently_reading, temp_user_read, temp_user_favorite_genres;
    for (const string &word : users_csv) {
        if (column_number == 0)
            temp_user_id = stoi(word);
        if (column_number == 1)
            temp_user_name = word;
        if (column_number == 2)
            temp_user_birth_place = word;
        if (column_number == 3)
            temp_user_member_since = word;
        if (column_number == 4)
            temp_user_favorite_authors = word;
        if (column_number == 5)
            temp_user_favorite_genres = word;
        if (column_number == 6)
            temp_user_want_to_read = word;
        if (column_number == 7)
            temp_user_currently_reading = word;
        if (column_number == 8)
            temp_user_read = word;
        column_number++;
        if (column_number == column_size) {
            users.emplace_back(User(temp_user_id, temp_user_name, temp_user_birth_place, temp_user_member_since,
                         temp_user_favorite_authors, temp_user_favorite_genres, temp_user_want_to_read,
                         temp_user_currently_reading, temp_user_read));
            column_number = 0;
        }
    }
}

void Google_read::parse_reviews_csv(const std::string &reviews_file_path) {
    int column_size = 0;
    vector<string> review_csv = read_csv_file(reviews_file_path, column_size);

    int column_number = 0;
    int temp_review_id = 0, temp_book_id = 0, temp_user_id = 0, temp_review_rate = 0, temp_review_number_of_like = 0;
    string temp_review_date;
    for (const string &word : review_csv) {
        if (column_number == 0)
            temp_review_id = stoi(word);
        if (column_number == 1)
            temp_book_id = stoi(word);
        if (column_number == 2)
            temp_user_id = stoi(word);
        if (column_number == 3)
            temp_review_rate = stoi(word);
        if (column_number == 4)
            temp_review_date = word;
        if (column_number == 5)
            temp_review_number_of_like = stoi(word);
        column_number++;
        if (column_number == column_size) {
            reviews.emplace_back(temp_review_id, temp_book_id, temp_user_id, temp_review_rate, temp_review_date,
                            temp_review_number_of_like);
            column_number = 0;
        }
    }
}

Google_read::Google_read(const std::string &authors_filepath, const std::string &books_filepath,
                         const std::string &users_filePath, const std::string &review_filepath) {
    parse_authors_csv(authors_filepath);
    parse_books_csv(books_filepath);
    parse_users_csv(users_filePath);
    parse_reviews_csv(review_filepath);
}

void Google_read::show_author_info(int author_id) {
    Authors requested_author = find_author_by_id(author_id);
    cout << "id: " << requested_author.get_id() << endl;
    cout << "Name: " << requested_author.get_name() << endl;
    cout << "Year of Birth: " << requested_author.get_year_of_birth() << endl;
    cout << "Place of Birth: " << requested_author.get_place_of_birth() << endl;
    cout << "Member Since: " << requested_author.get_member_since() << endl;
    cout << "Genres: ";
    int count = 0;
    for (const string &genre : requested_author.get_genres()) {
        cout << genre;
        count++;
        if(count != requested_author.get_genres().size())
            cout << ", ";
    }
    cout << endl;
    cout << "Books: " << endl;
    for (auto book: find_books_by_author_name(requested_author.get_name()))
        cout << "id: " << book.get_id() << " Title: " << book.get_title() << endl;
}

void Google_read::show_sorted_shelf(int user_id, const std::string &shelf_type, const std::string &genre) {
    User requested_user = find_user_by_id(user_id);
    vector<int> shelf_books_id = requested_user.find_shelf_book_for_user(shelf_type);
    vector<Books> shelf_books;
    shelf_books.reserve(shelf_books_id.size());
    for(int id : shelf_books_id)
        shelf_books.push_back(find_book_by_id(id));
    sort(shelf_books.begin(), shelf_books.end(), compare_by_title);
    show_books_by_order(genre, shelf_books);
}

void Google_read::show_best_book() {
    float average_rate = 0;
    int best_book_id = 0;
    find_best_book(average_rate, best_book_id);
    Books best_book = find_book_by_id(best_book_id);
    cout << "id: " << best_book.get_id() << endl;
    cout << "Title: " << best_book.get_title() << endl;
    cout << "Genre: " << best_book.get_genres() << endl;
    cout << "Author: " << find_author_by_id(best_book.get_author_id()).get_name() << endl;
    printf("Average Rating: %.2f\n", average_rate);
}

void Google_read::show_user_credit(int user_id) {
    float user_credit = find_user_credit(user_id);
    printf("%.6f\n", user_credit);
}

void Google_read::show_best_reviewer() {
    int number_of_likes = 0, best_reviewer_user_id = 0;
    find_best_reviewer(number_of_likes, best_reviewer_user_id);
    User best_review_user = find_user_by_id(best_reviewer_user_id);
    cout << "id: " << best_review_user.get_id() << endl;
    cout << "Name: " << best_review_user.get_name() << endl;
    cout << "Place of Birth: " << best_review_user.get_place_of_birth() << endl;
    cout << "Member Since: " << best_review_user.get_member_since() << endl;
    cout << "Favorite Genres: ";
    int count = 0;
    for (const string &genre : best_review_user.get_favorite_genres()) {
        count++;
        cout << genre;
        if(count != best_review_user.get_favorite_genres().size())
            cout << ", ";
    }
    cout << endl;
    count = 0;
    cout << "Favorite Authors: ";
    for (int author_id : best_review_user.get_favorite_authors()) {
        count++;
        cout << find_author_by_id(author_id).get_name();
        if(count != best_review_user.get_favorite_authors().size())
            cout << ", ";
    }
    cout << endl;
    cout << "Number of Books in Read Shelf: " << best_review_user.get_read_books().size() << endl;
    cout << "Number of Books in Want to Read Shelf: " << best_review_user.get_want_to_read_books().size() << endl;
    cout << "Number of Books in Currently Reading Shelf: " << best_review_user.get_currently_reading_books().size()
         << endl;
    cout << "Number of Likes: " << number_of_likes << endl;
}

void Google_read::show_recommended_books(int user_id) {
    float recommend_book_rate = 0;
    int recommend_book_id = 0;
    vector<int> review_ids = find_recommend_book(user_id, recommend_book_rate, recommend_book_id);
    Books my_book = find_book_by_id(recommend_book_id);
    cout << "id: " << my_book.get_id() << endl;
    cout << "Title: " << my_book.get_title() << endl;
    cout << "Genre: " << my_book.get_genres() << endl;
    cout << "Author: " << find_author_by_id(my_book.get_author_id()).get_name() << endl;
    cout << "Reviews: " << endl;
    for (int review_id : review_ids) {
        cout << "id: " << review_id << " Rating: " << find_review_by_id(review_id).get_rating() << " Likes: "
             << find_review_by_id(review_id).get_number_of_likes() << " Date: "
             << find_review_by_id(review_id).get_date() << endl;
    }

}

bool Google_read::compare_by_title(Books book1, Books book2) {
    return book1.get_title() < book2.get_title();
}

void Google_read::show_books_by_order(const string &genre, const vector<Books> &my_shelf_books) {
    int count = 0;
    for (Books book : my_shelf_books) {
        if (book.get_genres() == genre) {
            count++;
            cout << "id: " << book.get_id() << endl;
            cout << "Title: " << book.get_title() << endl;
            cout << "Genre: " << book.get_genres() << endl;
            cout << "Author: " << find_author_by_id(book.get_author_id()).get_name() << endl;
            if(count != my_shelf_books.size())
                cout << "***" << endl;
        }
    }
    for (Books book : my_shelf_books) {
        if (book.get_genres() != genre) {
            count++;
            cout << "id: " << book.get_id() << endl;
            cout << "Title: " << book.get_title() << endl;
            cout << "Genre: " << book.get_genres() << endl;
            cout << "Author: " << find_author_by_id(book.get_author_id()).get_name() << endl;
            if(count != my_shelf_books.size())
                cout << "***" << endl;
        }
    }
}

void Google_read::find_best_book(float &average_rate, int &best_book_id) {
    for (auto book : books) {
        float temp_average_rate = 0;
        int temp_best_book_id = 0, sum_of_rating = 0, number_of_review = 0;
        for (auto review : reviews) {
            if (book.get_id() == review.get_book_id()) {
                sum_of_rating += review.get_rating();
                number_of_review++;
            }
        }
        temp_average_rate = float(sum_of_rating) / float(number_of_review);
        temp_best_book_id = book.get_id();
        if (temp_average_rate > average_rate) {
            average_rate = temp_average_rate;
            best_book_id = temp_best_book_id;
        }
    }
}

void Google_read::find_best_reviewer(int &number_of_likes, int &best_reviewer_user_id) {
    for (auto user : users) {
        int temp_number_of_likes = 0, temp_best_reviewer_user = 0;
        for (auto review : reviews) {
            if (user.get_id() == review.get_user_id()) {
                temp_number_of_likes += review.get_number_of_likes();
            }
        }
        temp_best_reviewer_user = user.get_id();
        if (temp_number_of_likes > number_of_likes) {
            number_of_likes = temp_number_of_likes;
            best_reviewer_user_id = temp_best_reviewer_user;
        }
    }
}

float Google_read::find_user_credit(int user_id) {
    float number_of_user_reviews_likes = 0, number_of_likes = 0, number_of_user_reviews = 0, number_of_reviews = 0;
    for (auto review : reviews) {
        if (review.get_user_id() == user_id) {
            number_of_user_reviews++;
            number_of_user_reviews_likes += float(review.get_number_of_likes());
        }
        number_of_likes += float(review.get_number_of_likes());
        number_of_reviews++;
    }
    float user_credit =
            ((number_of_user_reviews_likes / number_of_likes) + (number_of_user_reviews / number_of_reviews)) / 2;
    return user_credit;
}

vector<int> Google_read::find_recommend_book(int user_id, float &recommend_book_rate, int &recommend_book_id) {
    vector<int> review_ids;
    for (auto book : books) {
        vector<int> temp_review_ids;
        float temp_recommend_book_rate = 0, sum_of_rating = 0;
        int temp_recommend_book_id = 0, number_of_review = 0, is_genre_favorite = 0;
        for (auto review : reviews) {
            if (book.get_id() == review.get_book_id()) {
                sum_of_rating += (float(review.get_rating()) * find_user_credit(user_id));
                number_of_review++;
                temp_review_ids.push_back(review.get_id());
            }
        }
        for (const auto &genre : find_user_by_id(user_id).get_favorite_genres()) {
            if (genre == book.get_genres()) {
                is_genre_favorite = 5;
                break;
            }
        }
        temp_recommend_book_rate = sum_of_rating / float(number_of_review) + float(is_genre_favorite);
        temp_recommend_book_id = book.get_id();
        if (temp_recommend_book_rate > recommend_book_rate) {
            recommend_book_rate = temp_recommend_book_rate;
            recommend_book_id = temp_recommend_book_id;
            review_ids = temp_review_ids;
        }
    }
    return review_ids;
}

Reviews Google_read::find_review_by_id(int review_id) {
    for (auto review : reviews) {
        if (review.get_id() == review_id)
            return review;
    }
    return Reviews();
}

User Google_read::find_user_by_id(int user_id) {
    User my_user;
    for (auto user : users) {
        if (user.get_id() == user_id)
            return user;
    }
    return User();
}

Authors Google_read::find_author_by_id(int author_id) {
    for(auto author : authors){
        if(author.get_id() == author_id) {
            return  author;
        }
    }
    return Authors();
}

Books Google_read::find_book_by_id(int book_id) {
    Books my_book;
    for (auto book : books) {
        if (book.get_id() == book_id)
            return book;
    }
    return Books();
}

vector<Books> Google_read::find_books_by_author_name(const std::string &author_name) {
    vector<Books> author_books;
    for (auto book : books) {
        if (find_author_by_id(book.get_author_id()).get_name() == author_name)
            author_books.push_back(book);
    }
    return author_books;
}