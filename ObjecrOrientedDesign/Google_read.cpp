#include "Google_read.h"

using namespace std;


vector<string> read_csv_file(const string &filePath, int &columnsNumber) {

    ifstream inputFile(filePath);
    if (inputFile.fail()) {
        cerr << "Error Opening the file" << endl;
        inputFile.close();
        exit(1);
    }
    vector<string> row;
    string line, word, temp;

    getline(inputFile, line);
    columnsNumber = count(line.begin(), line.end(), ',') + 1;
    while (getline(inputFile, line)) {
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
    }
    return row;
}

vector<Books> parse_books_csv(const string &books_file_path, const vector<Authors> &all_authors) {
    int column_size = 0;
    vector<string> books_csv = read_csv_file(books_file_path, column_size);

    vector<Books> books;
    int column_number = 0;
    int temp_book_id = 0, temp_author_id = 0;
    string temp_title, temp_author_genres;
    for (const string &word : books_csv) {
        if (column_number == 0)
            temp_book_id = stoi(word);
        if (column_number == 1)
            temp_title = word;
        if (column_number == 2)
            temp_author_id = stoi(word);
        if (column_number == 3)
            temp_author_genres = word;
        column_number++;
        if (column_number == column_size) {
            books.push_back(
                    Books(temp_book_id, temp_title, temp_author_id, temp_author_genres, all_authors));
            column_number = 0;
        }
    }
    return books;
}

vector<Authors> parse_authors_csv(const string &author_file_path) {
    int column_size = 0;
    vector<string> authors_csv = read_csv_file(author_file_path, column_size);
    vector<Authors> authors;
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
            authors.push_back(
                    Authors(temp_author_id, temp_author_name, temp_author_gender, temp_member_since,
                            temp_author_birth_year, temp_author_birth_place, temp_author_genres));
            column_number = 0;
        }
    }
    return authors;
}

vector<User>
parse_users_csv(const string &users_file_path, const vector<Authors> &all_authors, const vector<Books> &all_books) {
    int column_size = 0;
    vector<string> users_csv = read_csv_file(users_file_path, column_size);

    vector<User> users;
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
            users.push_back(
                    User(temp_user_id, temp_user_name, temp_user_birth_place, temp_user_member_since,
                         temp_user_favorite_authors, temp_user_favorite_genres, temp_user_want_to_read,
                         temp_user_currently_reading, temp_user_read, all_authors, all_books));
            column_number = 0;
        }
    }
    return users;
}

vector<Reviews> parse_reviews_csv(const std::string &reviews_file_path, const std::vector<User> &all_users,
                                  const std::vector<Books> &all_books) {
    int column_size = 0;
    vector<string> authors_csv = read_csv_file(reviews_file_path, column_size);
    vector<Reviews> my_reviews;
    int column_number = 0;
    int temp_review_id = 0, temp_book_id = 0, temp_user_id = 0, temp_review_rate = 0, temp_review_number_of_like = 0;
    string temp_review_date;
    for (const string &word : authors_csv) {
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
            my_reviews.push_back(
                    Reviews(temp_review_id, temp_book_id, temp_user_id, temp_review_rate, temp_review_date,
                            temp_review_number_of_like, all_books, all_users));
            column_number = 0;
        }
    }
    return my_reviews;
}

Google_read::Google_read(const std::string &authors_filepath, const std::string &books_filepath,
                         const std::string &users_filePath, const std::string &review_filepath) {
    authors = parse_authors_csv(authors_filepath);
    books = parse_books_csv(books_filepath, authors);
    users = parse_users_csv(users_filePath, authors, books);
    reviews = parse_reviews_csv(review_filepath, users, books);
}

void Google_read::show_author_info(int author_id) {
    Authors requested_author = find_author_by_id(authors, author_id);
    cout << "id: " << requested_author.get_id() << endl;
    cout << "Name: " << requested_author.get_name() << endl;
    cout << "Year of Birth: " << requested_author.get_year_of_birth() << endl;
    cout << "Place of Birth: " << requested_author.get_place_of_birth() << endl;
    cout << "Member Since: " << requested_author.get_member_since() << endl;
    cout << "Genres: ";
    for (const string &genre : requested_author.get_genres())
        cout << genre << ", ";
    cout << endl;
    cout << "Books: " << endl;
    for (auto book: find_books_by_author_name(requested_author.get_name()))
        cout << "id: " << book.get_id() << " Title: " << book.get_title() << endl;
}

void Google_read::show_sorted_shelf(int user_id, const std::string &shelf_type, const std::string &genre) {
    User requested_user = find_user_by_id(user_id, users);
    vector<Books> shelf_books = requested_user.find_shelf_book_for_user(shelf_type);
    sort(shelf_books.begin(), shelf_books.end(), compare_by_title);
    show_books_by_order(genre, shelf_books);
}


vector<Books> Google_read::find_books_by_author_name(const std::string &author_name) {
    vector<Books> author_books;
    for (auto book : books) {
        if (book.get_author_name() == author_name)
            author_books.push_back(book);
    }
    return author_books;
}

void Google_read::show_best_book() {


}

void Google_read::show_user_credit(int user_id) {
    int number_of_user_reviews_likes = 0, number_of_likes = 0, number_of_user_reviews = 0, number_of_reviews = 0;
    for(auto review : reviews){
        if(review.get_user().get_id() == user_id){
            number_of_user_reviews++;
            number_of_user_reviews_likes += review.get_number_of_likes();
        }
        number_of_likes += review.get_number_of_likes();
        number_of_reviews++;
    }
    int user_credit = ((number_of_user_reviews_likes / number_of_likes) + (number_of_user_reviews / number_of_reviews)) / 2;
    cout << user_credit << endl;
}

User find_user_by_id(int user_id, const vector<User> &all_users) {
    User my_user;
    for (auto user : all_users) {
        if (user.get_id() == user_id)
            return user;
    }
    return User();
}

Books find_book_by_id(int book_id, const vector<Books> &all_books) {
    Books my_book;
    for (auto book : all_books) {
        if (book.get_id() == book_id)
            return book;
    }
    return Books();
}

bool compare_by_title(Books book1, Books book2) {
    return book1.get_title() < book2.get_title();
}

void show_books_by_order(const string &genre, const vector<Books> &my_books) {
    for (Books book : my_books) {
        if (book.get_genres() == genre) {
            cout << "id: " << book.get_id() << endl;
            cout << "Title: " << book.get_title() << endl;
            cout << "Genre: " << book.get_genres() << endl;
            cout << "Author: " << book.get_author_name() << endl;
            cout << "***" << endl;
        }
    }
    for (Books book : my_books) {
        if (book.get_genres() != genre) {
            cout << "id: " << book.get_id() << endl;
            cout << "Title: " << book.get_title() << endl;
            cout << "Genre: " << book.get_genres() << endl;
            cout << "Author: " << book.get_author_name() << endl;
            cout << "***" << endl;
        }
    }
}