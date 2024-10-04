#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 정렬 기준 함수
bool compare(const std::string &a, const std::string &b) {
    return a + b > b + a;
}

std::string largestNumber(std::vector<int> &nums) {
    // 정수 배열을 문자열 배열로 변환
    std::vector<std::string> strNums;
    for (int num : nums) {
        strNums.push_back(std::to_string(num));
    }

    // 비교 함수에 따라 정렬
    std::sort(strNums.begin(), strNums.end(), compare);

    // 모든 수가 0인 경우, "0" 반환
    if (strNums[0] == "0") {
        return "0";
    }

    // 결과 문자열 생성
    std::string result;
    for (const std::string &str : strNums) {
        result += str;
    }

    return result;
}

int main() {
    std::vector<int> nums = {6, 10, 2};

    std::string result = largestNumber(nums);
    std::cout << "가장 큰 수: " << result << std::endl;

    return 0;
}
