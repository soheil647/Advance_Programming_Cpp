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

