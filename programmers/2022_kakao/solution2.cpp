#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    int defaultTime = fees[0];
    int defaultFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];

    vector<pair<int, int>> inCar;
    vector<pair<int, int>> management;

    for (auto car : records) {
        stringstream sstream(car);
        vector<string> words{}; // 0 : 시간, 1 : 차번호, 2 : IN or OUT 
        string word;
        while (std::getline(sstream, word, ' '))
            words.push_back(word);

        int num = std::stoi(words[1]);
        int hour = std::stoi(words[0].substr(0, 2));
        int minute = std::stoi(words[0].substr(3, 2));
        minute += (hour * 60);

        pair<int, int> info = make_pair(num, minute);

        if (words[2].compare("IN") == 0) {
            inCar.push_back(info);
        }
        else {
            int i = 0;
            for (auto out : inCar) {
                if (out.first == num) {
                    minute -= out.second;

                    bool check = false;
                    for (auto& car2 : management) {
                        if (car2.first == out.first) {
                            car2.second += minute;
                            check = true;
                            break;
                        }
                    }
                    if (!check) management.push_back(make_pair(num, minute));
                    break;
                }
                i++;
            }
            inCar.erase(inCar.begin() + i);
        }
    }

    while (!inCar.empty()) {
        int minute = 23 * 60 + 59;
        minute -= inCar.back().second;

        bool check = false;
        for (auto& car : management) {
            if (car.first == inCar.back().first) {
                car.second += minute;
                check = true;
                break;
            }
        }
        if(!check) management.push_back(make_pair(inCar.back().first, minute));
        inCar.pop_back();
    }

    auto comp = [](pair<int,int> a, pair<int, int> b) -> bool { return a.first < b.first; };
    sort(management.begin(), management.end(), comp);

    for (auto result : management) {
        int minute = result.second;
        if (minute % unitTime != 0) { // 나머지 있으면 단위시간 올림
            minute = (minute / unitTime) * unitTime + unitTime;
        }
        int price = defaultFee;
        if (defaultTime < minute) {
            price += ceil(((double)minute - (double)defaultTime) / (double)unitTime) * unitFee;
        }

        answer.push_back(price);
    }

    return answer;
}