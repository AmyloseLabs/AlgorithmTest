#include <iostream>
#include <sstream>

#include "common/DebugHelper.h"
#include "algorithm/RangeSum/RangeSum.hpp"

#define ARR_SZ(ARG) (sizeof(ARG)/sizeof(ARG[0]))

int main(int, char**){
    LOGI("Hello, from AlgorithmTest!");
    
    LOGI("TEST : " << STR_CYAN(RangeSum 1D));

    int arrData[5] = {5, 4, 3, 2, 1};
    int arrSum[5];

    RangeSum::createSumArray1D(&arrSum[0], ARR_SZ(arrSum), &arrData[0], ARR_SZ(arrData));

    size_t arrQuestion[3][2] {
        {1u, 3u},
        {2u, 4u},
        {5u, 5u}
    };

    for(auto &question : arrQuestion) {
        auto ans =  RangeSum::getRangeSum1D(&arrSum[0], ARR_SZ(arrSum), question[0] - 1u, question[1] - 1u);
        LOGI("Q1 : Range(" << question[0] << " ~ " << question[1] << ") SUM = " << ARG_CYAN(ans));
    }


    std::vector<std::vector<int>> vData = {
        {1, 2, 3, 4},
        {2, 3, 4, 5},
        {3, 4, 5, 6},
        {4, 5, 6, 7}
    };

    std::vector<std::vector<int>> vSum;

    LOGI("TEST : " << STR_CYAN(RangeSum 2D));
    RangeSum::createSumArray2D(vSum, vData);


    std::stringstream ss;
    ss.str("");
    for (const auto &vDir_i : vSum) {
        for (const auto &value :vDir_i) {
            ss << std::to_string(value) << " ";
        }
        ss << "\n";
    }
    LOGI("SUM ARRAY 2D \n" << ARG_CYAN(ss.str()));

    std::vector<std::vector<size_t>> vQuestion2 = {
        {2u, 2u, 3u, 4u},
        {3u, 4u, 3u, 4u},
        {1u, 1u, 4u, 4u}
    };

    for (const auto &q2 : vQuestion2) {
        auto b_i = q2[0u] - 1u;
        auto b_j = q2[1u] - 1u;
        auto e_i = q2[2u] - 1u;
        auto e_j = q2[3u] - 1u;
        auto ans2 = RangeSum::getRangeSum2D(vSum, b_i, b_j, e_i, e_j);
        LOGI("Q2 : Range([" << q2[0u] << ", " << q2[1u] << "] ~ [" << q2[2u] << ", " << q2[3u] << "]) SUM = " << ARG_CYAN(ans2));
    }


}
