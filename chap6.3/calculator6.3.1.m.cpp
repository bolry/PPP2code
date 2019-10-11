#include "std_lib_facilities.h"

int main() {
    std::cout << "Please enter expression (we can handle +,-,* and / )\n";
    std::cout << "add an x to end expression (e.g., 1+2*3x): ";
    int lval = 0;
    std::cin >> lval;
    if(!std::cin) error("no first operand");
    for(char op; std::cin>>op;){
        int rval;
        if( op != 'x') std::cin >> rval;
        if(!std::cin) error("no second operand");
        switch(op){
            case '+':
                lval += rval;
                break;
            case '-':
                lval -= rval;
                break;
            case '*':
                lval *= rval;
                break;
            case '/':
                lval /= rval;
                break;
            default:
                std::cout << "Result: " << lval << '\n';
                keep_window_open();
                return 0;
        }
    }
    error("bad expression");
}