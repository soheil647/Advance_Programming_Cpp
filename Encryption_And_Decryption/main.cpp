# include <iostream>
# include <string>
# include <vector>
# include <numeric>
# include <algorithm>
# include <fstream>
# include <sstream>

#define MAX_RANDOM_RANGE 11
#define ENCRYPT_TYPE_NAME "encrypt"
#define DECRYPT_TYPE_NAME "decrypt"
#define SIMPLE_KIND_NAME "simple"
#define COMPLICATED_KIND_NAME "complicated"
#define CIPHER_BLOCK_DELIMITER '\n'

using namespace std;

enum method_type {
    Encryption, Decryption
};
enum method_kind {
    Simple, Complicated
};
struct Method {
    method_type type;
    method_kind kind;
};

struct IO {
    string input_file_path;
    string output_file_path;
};

vector<int> convert_string_to_ascii(const string &input_string);

string repeat_key_n_times(const string &key_to_repeat, int number_of_repeat);

vector<int> simple_encryption(const string &password, const string &decoded_string);

string simple_decryption(const string &password, const vector<int> &encoded_ascii);

string convert_ascii_to_string(const vector<int> &ASCII);

vector<int> create_random_from_password_seed(const string &Password, int n);

vector<int> complex_encryption(const string &password, const string &decoded_string);

string complex_decryption(const string &password, const vector<int> &encoded_ascii);

Method get_method();

string get_key();

IO get_IO();

string read_input_file(const string &file_path);

void writeOutput(const string &output, const string &file_path);

string decrypt(const vector<int> &input_numbers, const string &key, method_kind kind);

vector<int> encrypt(const string &input_string, const string &key, method_kind kind);

string get_cipher_text(const vector<int> &cipher);

vector<int> get_cipher_numbers(const string &cipher_text);

string process_method(const string &input_text, const Method &method, const string &key);

string process_output(const Method &method, const string &key, const IO &io);

int main() {
    Method method = get_method();
    string key = get_key();
    IO io = get_IO();
    string output = process_output(method, key, io);
    writeOutput(output, io.output_file_path);
    return 0;
}

Method get_method() {
    string method_type_name, method_kind_name;
    cin >> method_type_name >> method_kind_name;
    Method method{};
    method.type = method_type_name == ENCRYPT_TYPE_NAME ? Encryption : Decryption;
    method.kind = method_kind_name == SIMPLE_KIND_NAME ? Simple : Complicated;
    return method;
}

string get_key() {
    string key;
    cin >> key;
    return key;
}

IO get_IO() {
    IO io;
    cin >> io.input_file_path >> io.output_file_path;
    return io;
}

vector<int> convert_string_to_ascii(const string &input_string) {
    vector<int> ascii_values;
    for (char letter : input_string) {
        ascii_values.push_back((int) letter);
    }
    return ascii_values;
}

string convert_ascii_to_string(const vector<int> &ascii_int_vector) {
    string converted_string;
    for (int char_value : ascii_int_vector)
        converted_string += (char) char_value;
    return converted_string;
}

string repeat_key_n_times(const string &key_to_repeat, int number_of_repeat) {
    string repeated_key;
    for (int i = 0; i < number_of_repeat; i++)
        repeated_key += key_to_repeat;
    return repeated_key;
}

vector<int> create_random_from_password_seed(const string &password, int n) {
    vector<int> ascii_password = convert_string_to_ascii(password);
    srand(accumulate(ascii_password.begin(), ascii_password.end(), 0));
    vector<int> random_vector;
    random_vector.reserve(n);
    for (int i = 0; i < n; i++)
        random_vector.push_back(rand() % MAX_RANDOM_RANGE);
    return random_vector;
}


vector<int> simple_encryption(const string &password, const string &decoded_string) {
    vector<int> ascii_value_of_input = convert_string_to_ascii(decoded_string);
    string concatenated_password = repeat_key_n_times(password, decoded_string.size());
    vector<int> ascii_value_of_password = convert_string_to_ascii(concatenated_password);
    std::transform(ascii_value_of_input.begin(), ascii_value_of_input.end(), ascii_value_of_password.begin(),
                   ascii_value_of_input.begin(), std::plus<int>());
    return ascii_value_of_input;
}

vector<int> complex_encryption(const string &password, const string &decoded_string) {
    vector<int> ascii_value_of_input = convert_string_to_ascii(decoded_string);
    vector<int> ascii_value_of_password = create_random_from_password_seed(password, decoded_string.size());
    std::transform(ascii_value_of_input.begin(), ascii_value_of_input.end(), ascii_value_of_password.begin(),
                   ascii_value_of_input.begin(), plus<int>());
    return ascii_value_of_input;
}

vector<int> encrypt(const string &input_string, const string &key, method_kind kind) {
    switch (kind) {
        case Simple:
            return simple_encryption(key, input_string);
        case Complicated:
            return complex_encryption(key, input_string);
    }
}

string simple_decryption(const string &password, const vector<int> &encoded_ascii) {
    string concatenated = repeat_key_n_times(password, encoded_ascii.size());
    vector<int> ascii_value_of_password = convert_string_to_ascii(concatenated);
    vector<int> result = encoded_ascii;
    std::transform(result.begin(), result.end(), ascii_value_of_password.begin(),
                   result.begin(), minus<int>());
    return convert_ascii_to_string(result);
}

string complex_decryption(const string &password, const vector<int> &encoded_ascii) {
    vector<int> ascii_value_of_password = create_random_from_password_seed(password, encoded_ascii.size());
    std::transform(ascii_value_of_password.begin(), ascii_value_of_password.end(), encoded_ascii.begin(),
                   ascii_value_of_password.begin(), minus<int>());
    return convert_ascii_to_string(ascii_value_of_password);
}

string decrypt(const vector<int> &input_numbers, const string &key, method_kind kind) {
    switch (kind) {
        case Simple:
            return simple_decryption(key, input_numbers);
        case Complicated:
            return complex_decryption(key, input_numbers);
    }
}

string process_output(const Method &method, const string &key, const IO &io) {

    string input_text = read_input_file(io.input_file_path);
    string output = process_method(input_text, method, key);
    return output;
}

string read_input_file(const string &file_path) {
    ifstream file(file_path);
    stringstream text_buffer;
    text_buffer << file.rdbuf();
    return text_buffer.str();
}

void writeOutput(const string &output, const string &file_path) {
    ofstream file(file_path);
    stringstream buffer(output);
    buffer >> file.rdbuf();
}

string process_method(const string &input_text, const Method &method, const string &key) {
    vector<int> cipher;
    switch (method.type) {
        case Encryption:
            cipher = encrypt(input_text, key, method.kind);
            return (string) get_cipher_text(cipher);
        case Decryption:
            cipher = get_cipher_numbers(input_text);
            return (string) decrypt(cipher, key, method.kind);
    }
}

string get_cipher_text(const vector<int> &cipher) {
    string cipher_text;
    for (int cipher_number : cipher)
        cipher_text += to_string(cipher_number) + CIPHER_BLOCK_DELIMITER;
    return cipher_text;
}

vector<int> get_cipher_numbers(const string &cipher_text) {
    string line;
    stringstream cipherTextStream(cipher_text);
    vector<int> cipher;
    while (getline(cipherTextStream, line, CIPHER_BLOCK_DELIMITER))
        cipher.push_back(stoi(line));
    return cipher;
}
