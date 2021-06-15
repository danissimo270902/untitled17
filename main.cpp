#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>


std::pair<int, std::pair<char, char>> mostAscendingSequence(std::string sequence){

    int length = 1, resStart, resEnd;
    int start = 0, end = 1;
    for(int i = 1; i < sequence.size(); i++){
        if(sequence[i - 1] < sequence[i]){
            end++;
        } else {
            if(end - start > length){
                resStart = start;
                resEnd = end;
                length = end - start;
            }

            start = end;
            end = start + 1;
        }

    }

    if(end - start > length){
        resStart = start;
        resEnd = end;
        length = end - start;
    }

    std::pair<int, std::pair<char, char>> res;
    res.first = length;
    res.second.first = sequence[resStart];
    res.second.second = sequence[resEnd - 1];

    return res;
}
void test(){
    std::pair<int, std::pair<char, char>> res = mostAscendingSequence("abasdafdfsdfdv");
            CHECK(5, res.first);
            CHECK('d', res.second.first);
            CHECK('s', res.second.second);
}
TEST_CASE("cheaking funcion for corection") {
    test();
}

int main(int argc, char** argv) {
    doctest::Context context;



    // defaults
//    context.addFilter("test-case-exclude", "*math*"); // exclude test cases with "math" in their name
//    context.setOption("abort-after", 5);              // stop test execution after 5 failed assertions
//    context.setOption("order-by", "name");            // sort the test cases by their name

    context.applyCommandLine(argc, argv);

    // overrides
//    context.setOption("no-breaks", true);             // don't break in the debugger when assertions fail

    int res = context.run(); // run

    if(context.shouldExit()) // important - query flags (and --exit) rely on the user doing this
        return res;          // propagate the result of the tests

    int client_stuff_return_code = 0;
    // your program - if the testing framework is integrated in your production code

    return res + client_stuff_return_code; // the result from doctest is propagated here as well
}
