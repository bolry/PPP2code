#include "std_lib_facilities.h"

class Token {
public:
    char kind;
    double value;
};

class Token_stream{
public:
    Token get();
    void putback(Token t);
private:
    bool full{false};
    Token buffer;
};

void Token_stream::putback(Token t) {
    if(full)error("putback() into a full buffer");
buffer = t;
full = true;
}

Token Token_stream::get() {
    if(full) return full=false,buffer;
    char ch;
    std::cin >> ch;
    switch (ch){
        case ';':  // for print
        case 'q':  // for quite
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token{ch};
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9': {
            std::cin.putback(ch);
            double val;
            std::cin >> val;
            return Token{'8', val};
        }
        default:
            error("Bad token");
    }
}

Token_stream ts;

double expression();

double primary() {
    Token t = ts.get();
    switch (t.kind) {
        case '(': {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
        case '8':
            return t.value;
        default:
            error("primary expected");
    }
}

double term() {
    double left = primary();
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
            case '*':
                left *= primary();
                break;
            case '/' : {
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d;
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

double expression() {
    double left = term();
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
            case '+':
                left += term();
                break;
            case '-':
                left -= term();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}


int main() try {
    while (std::cin)
        std::cout << expression() << '\n';
    keep_window_open();
}
catch (std::exception const &e) {
    std::cerr << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    std::cerr << "exception\n";
    keep_window_open();
    return 2;
}