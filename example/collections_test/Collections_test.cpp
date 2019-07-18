#include "../include/collections.h"
#include <unistd.h>
#include <unistd.h>
#include <unordered_map>

void usage()
{
    printf("------------------------------------------------------------------------\n");
    printf("Collection test usage info:\n\n");
    printf(" -h, --help           Prints help\n");
    printf(" -b                   Test Bag\n");
    printf(" -q                   Test Queue\n");
    printf(" -s                   Test Stack\n");
    printf(" \nUsage Example:\n\n");
    printf(" ./bin/collection_bin -q < input.txt\n");
    printf("------------------------------------------------------------------------\n");
}

void bag_test()
{
    std::string s;
    Bag<double> numbers;
    while (std::cin >> s) {
        numbers.add(std::stod(s));
    }

    int N = numbers.size();
    double sum = 0.0;
    for (auto iter = numbers.begin(); iter != numbers.end(); ++iter) {
        sum += *iter;
    }

    numbers.print(std::cout);
    std::cout << "Mean: " << sum / N << std::endl;
}

void queue_test()
{
    std::string s;
    Queue<std::string> q;
    while (std::cin >> s) {
        if (s.compare("-") != 0)
            q.enqueue(s);
        else if (!q.isEmpty())
            std::cout << q.dequeue() + " ";
    }
    std::cout << "(" << q.size() << " left on queue)" << std::endl;
    q.print(std::cout);
}

void stack_test()
{
    std::string s;
    Stack<std::string> st;
    while (std::cin >> s) {
        if (s.compare("-") != 0)
            st.push(s);
        else if (!st.isEmpty())
            std::cout << st.pop() + " ";
    }
    std::cout << "(" << st.size() << " left on stack)" << std::endl;
    st.print(std::cout);
}

void stack_test_parentheses()
{
    std::string s;
    std::string s_top;
    std::unordered_map<std::string, std::string> paren_map = {
        {"[", "]"},
        {"{", "}"},
        {"<", ">"},
        {"(", ")"}
    };
    Stack<std::string> st;

    while (std::cin >> s) {
        if (st.isEmpty() || (paren_map.find(s) != paren_map.end()))
        {
            st.push(s);
        } else {
            s_top = st.top();
            if (paren_map[s_top].compare(s) == 0)
                st.pop();
        }
    }
    
    if (st.isEmpty())
        std::cout << "matched!" << std::endl;
    else {
        std::cout << "not matched!" << std::endl;
        st.print(std::cout);
    }
}

static double eval( double a, double b, char c)
{
    double ret = 0.0;
    switch (c) {
        case '+':
            ret = a + b;
            break;
        case '-':
            ret = a - b;
            break;
        case '/':
            ret = a / b;
            break;
        case '*':
            ret = a * b;
            break;
        default:
            std::cerr << "Not suppored operator: " << c << std::endl;
    }
    return ret;
}

void stack_test_evaluate()
{
    std::string s;
    Stack<double> operands;
    Stack<char> operators;
    double num1 = 0.0, num2 = 0.0;
    char c;

    while (std::cin >> s) {
         switch (s[0]) {
            case '(':
                break;
            case ')':
                num1 = operands.pop();
                num2 = operands.pop();
                c    = operators.pop();
                operands.push(eval(num2, num1, c));
                break;
            case '*':
            case '+':
            case '-':
            case '/':
                operators.push(s[0]);
                break;
            default:
                operands.push(s[0] -'0');
         }
    }
    if (!operands.isEmpty())
        std::cout << "The eval ret is: " << operands.pop() << std::endl;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        usage();

    int opt = 0;
    static const char *optString = "bqsh";
    while ((opt = getopt(argc, argv, optString)) != -1) {
        switch (opt)
        {
            case 'b':
                bag_test();
                break;
            case 'q':
                queue_test();
                break;
            case 's':
                //stack_test();
                //stack_test_parentheses();
                stack_test_evaluate();
                break;
            default:
                usage();
                break;
        }
    }

    return 0;
}