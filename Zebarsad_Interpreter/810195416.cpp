#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <cstdio>
#include <bits/stdc++.h>

#define WRITING 0
#define READING 1
#define UNKNOWN 2
#define ADD "+"
#define MULTIPLY "*"
#define DEVIDE "/"
#define SUBTRACT "-"

using namespace std;

class interPreter {
private:
    enum Commands {
        invalid_command, QuestionMark, ExclamationMark, Equation
    };
    enum Operators {
        invalid_operator, Add, Subtract, Divide, Multiply
    };
    enum VariableState{Writing, Reading, Unknown};
    vector<vector<string>> commands;
    vector<int> variable_values;
    map<string, int> variables;
    map<string, int> variables_state;
    int variable_assign;

    static Commands resolve_command(const string &new_line);

    static Operators resolve_operator(const string &new_operator);

    static vector<vector<string>> parse_command(const vector<vector<string>> &line_separate);

    vector<vector<string>> parse_line(const vector<string> &input_line);

    void save_variables(string input_variables);

    void execute_command(vector<string> &command_line);

    void question_mark_command(const string &command_line);

    int exclamation_mark_command(vector<string> &command_line);

    static vector<string> find_operators(vector<string> &command_line);

    vector<int> find_variables(vector<string> &command_line);

    vector<int> find_variables_values(const vector<string> &elements);

    static bool is_number(const string &s);

    static int find_result(vector<string> &operators, vector<int> &elements);

    static int do_arithmatic(int element1, int element2, const string &new_operator);

    int equation_command(vector<string> &command_line);

    void parse_input(const vector<string> &input_line);

    void find_minimum_step();

    int find_variable_state(const string& variable_name);

public:
    explicit interPreter(const vector<string> &_commands);
    void inter_pret_commands();

};


interPreter::interPreter(const vector<string> &_commands) {
    variable_assign = 0;
    parse_input(_commands);
}

vector<vector<string>> interPreter::parse_line(const vector<string> &input_line) {
    vector<vector<string>> parsed_lines;
    for (string line : input_line) {
        vector<string> line_separate;
        if (line[0] == '$') {
            save_variables(line);
            continue;
        }
        std::string delimiter = " ";

        size_t pos = 0;
        std::string token;
        while ((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            if (!token.empty())
                line_separate.push_back(token);
        }
        line_separate.push_back(line);
        parsed_lines.push_back(line_separate);
    }
    return parsed_lines;
}

vector<vector<string>> interPreter::parse_command(const vector<vector<string>> &line_separate) {
    vector<vector<string>> parsed_commands;
    for (const vector<string> &separated : line_separate) {
        vector<string> command;
        for (const string &parsed : separated) {
            int j = 0;
            int k = 0;
            if (is_number(parsed)) {
                command.push_back(parsed);
                continue;
            }
            for (int i = 0; i < parsed.size(); i++) {
                if (isalpha(parsed[i] || isdigit(parsed[i]))) {
                    if (i == parsed.size() - 1) {
                        if (parsed.size() == 1) {
                            command.push_back(parsed);
                        } else {
                            command.push_back(parsed.substr(k, i));
                        }
                    }
                    j++;
                    continue;
                } else if (isdigit(parsed[i])) {
                    if (i == parsed.size() - 1) {
                        if (parsed.size() == 1) {
                            command.push_back(parsed);
                        } else {
                            command.push_back(parsed.substr(k, i));
                        }
                    }
                    j++;
                    continue;
                } else {
                    if (j != 0) {
                        command.push_back(parsed.substr(k, j));
                        k += j;
                        j = 0;
                        i--;
                        continue;
                    }
                    string s(1, parsed[i]);
                    command.push_back(s);
                    k++;
                    continue;
                }
            }
        }
        parsed_commands.push_back(command);
    }
    return parsed_commands;
}

void interPreter::parse_input(const vector<string> &input_line) {
    vector<vector<string>> line_separate = parse_line(input_line);
    vector<vector<string>> command = parse_command(line_separate);
    commands = command;
}

void interPreter::execute_command(vector<string> &command_line) {
    switch (resolve_command(command_line[0])) {
        case invalid_command:
            break;
        case QuestionMark:
            command_line.erase(command_line.begin(), command_line.begin() + 1);
            return question_mark_command(command_line[0]);
        case ExclamationMark: {
            command_line.erase(command_line.begin(), command_line.begin() + 1);
            cout << exclamation_mark_command(command_line) << endl;
            return;
        }
        case Equation: {
            string new_variable = command_line[0];
            command_line.erase(command_line.begin(), command_line.begin() + 2);
            int new_value = equation_command(command_line);
            map<string, int>::iterator it;
            it = variables.find(new_variable);
            if (it == variables.end())
                variables.insert({new_variable, new_value});
            it->second = new_value;
            return;
        }
    }
}

interPreter::Commands interPreter::resolve_command(const string &new_line) {
    if (new_line == "?") return QuestionMark;
    else if (new_line == "!") return ExclamationMark;
    else return Equation;
}

void interPreter::question_mark_command(const string &command_line) {
    variables.insert({command_line, variable_values[variable_assign]});
    variable_assign += 1;
}

int interPreter::exclamation_mark_command(vector<string> &command_line) {
    vector<string> operators = find_operators(command_line);
    vector<int> elements_values = find_variables(command_line);
    return find_result(operators, elements_values);
}

void interPreter::save_variables(string input_variables) {
    std::string delimiter = " ";

    size_t pos = 0;
    std::string token;
    while ((pos = input_variables.find(delimiter)) != std::string::npos) {
        token = input_variables.substr(0, pos);
        input_variables.erase(0, pos + delimiter.length());
        if (token == "$")
            continue;
        else
            variable_values.push_back(stoi(token));
    }
    variable_values.push_back(stoi(input_variables));
}

void interPreter::find_minimum_step(){
    int step_number = 0;
    vector<vector<string>> commands_copy = commands;
    while(true) {
        for (const vector<string> &command : commands_copy) {
            for (int i = 1; i < command.size(); i++) {
                if(command[0] == "?") {
                    variables_state.insert({command[i], WRITING});
                }

                else if(command[0] == "!"){
                    if(isalpha(command[i][0])) {
                        variables_state.insert({command[i], READING});
                    }
                }

                else{
                    variables_state.insert({command[0], WRITING});
                    if(isalpha(command[i][0])) {
                        variables_state.insert({command[i], READING});
                    }
                }

            }
        }
        vector<int> completed_commands;
        for (int j = 0; j < commands_copy.size(); j++) {
            for (int i = 1; i < commands_copy[j].size(); i++) {
                if(commands_copy[j][0] == "?") {
                    completed_commands.push_back(j);
                }

                else if(commands_copy[j][0] == "!"){
                    if(isalpha(commands_copy[j][i][0])) {
                        if(find_variable_state(commands_copy[j][i]) == READING)
                            completed_commands.push_back(j);
                    }
                }
                else{
                    if(find_variable_state(commands_copy[j][0]) == WRITING)
                        if(isalpha(commands_copy[j][i][0])) {
                            if(find_variable_state(commands_copy[j][i]) != WRITING)
                                completed_commands.push_back(j);
                    }
                }
            }
        }
        for(int i : completed_commands)
            commands_copy.erase(commands_copy.begin() + i);
        step_number++;
        if(commands_copy.empty())
            break;
    }
    cout << step_number;
}

void interPreter::inter_pret_commands() {
//    find_minimum_step();
    for (vector<string> command : commands)
        execute_command(command);
}

vector<string> interPreter::find_operators(vector<string> &command_line) {
    vector<string> operators;
    for (int i = 0; i < command_line.size(); i++)
        if (i % 2 == 1)
            operators.push_back(command_line[i]);
    return operators;
}

vector<int> interPreter::find_variables(vector<string> &command_line) {
    vector<string> elements;
    for (int i = 0; i < command_line.size(); i++)
        if (i % 2 == 0)
            elements.push_back(command_line[i]);


    vector<int> elements_values = find_variables_values(elements);
    return elements_values;
}

vector<int> interPreter::find_variables_values(const vector<string> &elements) {
    vector<int> values;
    map<string, int>::iterator it;
    for (const string &element : elements) {
        if (is_number(element)) {
            values.push_back(stoi(element));
            continue;
        } else {
            it = variables.find(element);
            if (it == variables.end()) {
                variables.insert({element, 0});
                values.push_back(0);
                continue;
            }
            values.push_back(it->second);
        }
    }
    return values;
}

bool interPreter::is_number(const std::string &s) {
    return !s.empty() && std::find_if(s.begin(),
                                      s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

int interPreter::find_result(vector<string> &operators, vector<int> &elements) {
    int number_of_operands = operators.size();
    for (int i = 0; i < number_of_operands; i++) {
        int element1 = elements.back();
        elements.pop_back();
        int element2 = elements.back();
        elements.pop_back();
        string new_operator = operators.back();
        operators.pop_back();

        elements.push_back(do_arithmatic(element1, element2, new_operator));
    }
    return elements.back();
}

interPreter::Operators interPreter::resolve_operator(const string &new_operator) {
    if (new_operator == ADD) return Add;
    else if (new_operator == SUBTRACT) return Subtract;
    else if (new_operator == DEVIDE) return Divide;
    else if (new_operator == MULTIPLY) return Multiply;
    else return invalid_operator;
}

int interPreter::do_arithmatic(int element1, int element2, const string &new_operator) {
    switch (resolve_operator(new_operator)) {
        case Add:
            return element2 + element1;
        case Subtract:
            return element2 - element1;
        case Divide:
            return element2 / element1;
        case Multiply:
            return element2 * element1;
        default:
            return 0;
    }
}

int interPreter::equation_command(vector<string> &command_line) {
    return exclamation_mark_command(command_line);
}

int interPreter::find_variable_state(const string& variable_name) {

    for (auto const& x : variables_state)
    {
        if(x.first == variable_name)
            return x.second;
    }
    return 2;
}

int main() {
    string input_line;
    vector<string> a;
    vector<string> commands;
    while (getline(cin, input_line)) {
        if (input_line.empty())
            continue;
        commands.push_back(input_line);
    }
    auto ip = new interPreter(commands);
    ip->inter_pret_commands();

    return 0;
}
