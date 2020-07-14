#include "handlers.hpp"


using namespace std;

Response *Login::callback(Request *req) {
    auto *res = new Response;
    res->setHeader("Content-Type", "text/html");
    string body;
    body += "<!DOCTYPE html>";
    body += "<html>";
    body += "<body>";
    body += "<h1>Hello World!</h1>";
    body += "</body>";
    body += "</html>";
    res->setBody(body);
    return res;
}

Response *Adder::callback(Request *req) {
    auto *res = new Response;
    res->setHeader("Content-Type", "text/html");

    int num1 = stoi(req->getBodyParam("num1"));
    int num2 = stoi(req->getBodyParam("num2"));
//    string ss = req->getBody();

    ostringstream body;
    body
            << "<!DOCTYPE html>" << endl
            << "<html>" << endl
            << "<body>" << endl
            << num1 << "+" << num2 << "=" << (num1 + num2) << endl
            << "</body>" << endl
            << "</html>" << endl;
    res->setBody(body.str());
    return res;
}

Response *CheckSignUp::callback(Request * req) {
    auto res = new Response;
    res->setHeader("Content-Type", "text/html");
    stringstream input(req->getBody());
    try {
        my_app->parse_command(input, "POST", "signup");
    }
    catch (Hotel_Exceptions& err){
        err.handle_error();
//        throw Server::Exception(err.handle_error());
        res = Response::redirect("/");
        res->setBody(err.handle_error());
        return res;
    }
    string args = "true";
    res = Response::redirect("/");
    res->setSessionId("SID");
    res->setHeader("error", args);
    return res;
}
