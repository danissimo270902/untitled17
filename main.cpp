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

int main() {
    std::pair<int, std::pair<char, char>> res = mostAscendingSequence("abasdafdfsdfdv");
    std::cout<< res.first << "\t" << res.second.first << "\t" << res.second.second;
}