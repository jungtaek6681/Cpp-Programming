#include <iostream>

using namespace std;

int main()
{
    /****************************
     * 문자열
     *
     * 문자들의 연속적인 모음
     ****************************/

    // <C스타일 문자열>
    // C스타일 문자열은 문자 배열을 통해 구현
    // 문자열의 마지막을 나타내기 위해 null('\0')을 사용

    // 기본사용법
    char charArray1[] = {'A', 'B', 'C', 'D', '\0', 'E', 'F'};
    cout << "문자배열로 표현한 문자열은 " << charArray1 << endl;    // "ABCD"

    char charArray2[] = "ABCD";
    cout << "문자배열로 표현한 문자열은 " << charArray2 << endl;
    int length = sizeof(charArray2) / sizeof(char);
    cout << "문자배열의 길이는 " << length << endl;
    for (int i = 0; i < length; i++)
    {
        cout << (int)charArray2[i] << " ";
    }   // 65(A) 66(B) 67(C) 68(D) 0(\0)


    // <C++ string>
    // C++에서 제공하는 문자열을 다루기 위한 기능
    // C스타일의 문자배열보다 쉽고 안전하며 유연함

    // 기본사용법
    string str = "ABCD";
    str = "EFGH";

    // 추가 기능
    const char* array = str.c_str();    // string을 C스타일 문자배열로 변환

    str[0] = 'a';                       // 문자열의 n번째 요소 접근
    str.front();                        // 문자열 가장 앞 문자
    str.back();                         // 문자열 가장 뒤 문자
    str.length();                       // 문자열 길이
    str.size();                         // 문자열 길이
    str.empty();                        // 문자열이 빈 문자열인지 확인

    str += "ABC";                       // 문자열 붙이기
    str.append("DEF");                  // 문자열 붙이기
    str.insert(5, "To");                // 문자열 삽입
    str.replace(1, 3, "D");             // 문자열 대체
    str.erase(0, 3);                    // 문자열 일부 지우기
    str.clear();                        // 문자열 전체 지우기
    str.find("ABC");                    // 문자열 찾기
    str == "ABC";                       // 문자열 비교
    str < "ABC";                        // 문자열 비교
    str > "ABC";                        // 문자열 비교
    str.compare("ABC");                 // 문자열 비교
}
