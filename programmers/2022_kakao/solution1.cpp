#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    int n = id_list.size();
    int info[1000][1000] = { 0 };

    for (int t = 0; t < report.size(); t++) {
        // token으로 신고한 사람, 당한 사람 나누기
        stringstream sstream(report[t]);
        vector<string> words{};
        string word;
        while (std::getline(sstream, word, ' '))
            words.push_back(word);

        // 신고한 사람
        int i = 0;
        for (auto it : id_list) {
            if (it.compare(words[0]) == 0) break;
            i++;
        }

        // 신고 당한 사람
        int j = 0;
        for (auto it : id_list) {
            if (it.compare(words[1]) == 0) break;
            j++;
        }
        // i : 신고한 사람 j : 신고당한 사람
        info[i][j] = 1;
    }

    // 신고 누적 구하기
    vector<int> reportA;
    for (int i = 0; i < id_list.size(); i++) {
        int c = 0;
        for (int j = 0; j < id_list.size(); j++) {
            c += info[j][i];
        }
        reportA.push_back(c);
    }

    // 정지 당하는 사람 index 저장
    int i = 0;
    vector<int> result;
    for (auto it : reportA) {
        if (it >= k) {
            result.push_back(i); // 신고 당함
        }
        i++;
    }

    // 정지 당한 사람과 신고한 사람 매칭해서 카운트
    for (int i = 0; i < id_list.size(); i++) {
        int c = 0;
        for (auto x : result) {
            if (info[i][x] == 1) {
                c++;
            }
        }
        answer.push_back(c);
    }

    return answer;
}