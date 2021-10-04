#include <vector>
#include <string>
#include <iostream>
#include "BinaryNumber.h"
#include "Stack.h"
using namespace std;

template <typename T>
class Postfix {
    vector<string> expression;
public:
    Postfix(vector<string> expr) {
        expression = expr;
    }

    bool isOperator(string& exp) {
        return (exp == "+" || exp == "-" || exp == "*");
    }

    BinaryNumber<T> evaluate() {
        auto* stack = new Stack<BinaryNumber<T>>();
        for (string e : expression) {
            if (!isOperator(e)) {
                try {
                    BinaryNumber<T> num = BinaryNumber<T>(stoi(e));
                    cout << "Binary code of number: ";
                    num.printBinArray(num.mainArray);
                    cout << endl;
                    stack->push(num);
                }
                catch (std::invalid_argument& exc) {
                    throw "Invalid symbol in expression";
                }
            }
            else {
                BinaryNumber<T> num1 = stack->pop();
                BinaryNumber<T> num2 = stack->pop();
                BinaryNumber<T> res;
                if (e == "+") res = num1 + num2;
                else if (e == "-") res = num1 - num2;
                else if (e == "*") res = num1 * num2;
                stack->push(res);
            }

        }
        BinaryNumber<T> result = stack->pop();
        if (!stack->empty()) {
            throw "Invalid expression";
        }
        return result;
    }
};