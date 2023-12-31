﻿#include <iostream>
#include <string>

using namespace std;

int main()
{
    /**************************************************************
     * 자료형 (Data Type)
     * 
     * 자료(데이터)의 형태를 지정
     * 데이터가 메모리에 저장되는 형태와 처리되는 방식을 명시하는 역할
     * 0과 1만으로 구성된 컴퓨터에게 여러 형태의 자료를 저장하기 위함
     **************************************************************/

    // <자료형 종류>
    // 자료형 이름          자료형 형태            메모리 크기     표현 범위
    // - 논리형 -
    // bool                 논리 자료형            1byte           false, true
    //
    // - 정수형 -
    // short                부호있는 정수          2byte           -2^15 ~ +2^15 - 1   => -32,768 ~ 32,767
    // int                  부호있는 정수          4byte           -2^31 ~ +2^31 - 1   => -2,147,483,648 ~ 2,147,483,647
    // long long            부호있는 정수          8byte           -2^63 ~ +2^63 - 1   => -9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807
    // 
    // unsigned short       부호없는 정수          2byte           0 ~ +2^16 - 1       =>  0 ~ 65,535
    // unsigned int         부호없는 정수          4byte           0 ~ +2^32 - 1       =>  0 ~ 4,294,967,295
    // unsigned long long   부호없는 정수          8byte           0 ~ +2^64 - 1       =>  0 ~ 18,446,744,073,709,551,615
    //
    // - 실수형 -
    // float                부동소수점 실수        4byte           3.4e-38  ~ 3.4e+38   => 약 소수점 7자리
    // double               부동소수점 실수        8byte           1.7e-308 ~ 1.7e+308  => 약 소수점 15자리
    //
    // - 문자형
    // char                 문자(아스키코드)       1byte           'a', 'b', ...
    // string               문자열(아스키코드)       X             "abcd", ...
    // 
    // wchar_t              문자(유니코드)         2byte           L'한', L'글', ...
    // wstring              문자열(유니코드)         X             L"안녕하세요", ...


    /*****************************************************************
     * 변수 (variable)
     *
     * 데이터를 저장하기 위해 프로그램에 의해 이름을 할당받은 메모리 공간
     * 데이터를 저장할 수 있는 메모리 공간을 의미하며, 저장된 값은 변경 가능
     ******************************************************************/

    // <변수 선언 및 초기화>
    // 자료형을 선언하고 빈칸 뒤에 변수이름을 작성하여 변수 선언
    // 변수 선언과 동시에 초기화 과정을 진행할 수 있음
    int iValue = 10;        // int 자료형의 이름이 iValue인 변수에 10의 데이터를 초기화
    float fValue;           // float 자료형의 이름이 fValue인 변수를 선언하지만 값을 초기화하지 않음
    // int iValue;          // error : 중복된 이름의 변수는 사용불가
    // cout << fValue;      // error : 선언한 변수에 값을 초기화하기 전까지 사용불가


    // <변수에 데이터 저장>
    // =(대입연산자) 좌측에 변수를 배치
    iValue = 5;             // iValue 변수에 5의 데이터 저장
    fValue = 1.2f;          // fValue 변수에 1.2f 데이터를 초기화


    // <변수의 데이터 불러오기>
    // 데이터가 필요한 곳에 변수명을 배치
    int rValue = 20;
    int lValue = rValue;
    cout << "rValue 변수에 보관된 데이터는 " << rValue << " 입니다." << endl;
    cout << "lValue 변수에 보관된 데이터는 " << lValue << " 입니다." << endl;



    /*****************************************************************
     * 상수 (Constant)
     *
     * 프로그램이 실행되는 동안 변경할 수 없는 데이터
     * 프로그램에서 값이 변경되기를 원하지 않는 데이터가 있을 경우 사용
     * 저장된 값은 변경 불가능
     ******************************************************************/

    // <상수 선언 및 초기화>
    // 변수 선언 앞에 const 키워드를 추가하여 상수 선언
    const int MAX = 200;        // MAX 상수 변수를 선언하고 초기화
    cout << "MAX 상수에 보관된 데이터는 " << MAX << " 입니다." << endl;
    // const int MIN;           // error : 상수는 초기화 없이 사용불가
    // MAX = 20                 // error : 상수의 데이터 변경 불가



    /*****************************************************************
     * 형변환 (Casting)
     *
     * 데이터를 선언한 자료형에 맞는 형태로 변환하는 작업
     * 다른 자료형의 데이터를 저장하기 위해선 형변환 과정을 거쳐야하며,
     * 이 과정에서 보관할 수 없는 데이터는 버려짐
     ******************************************************************/

    // <명시적 형변환>
    // 변환할 데이터의 앞에 변환할 자료형을 괄호안에 넣어 형변환 진행
    float floatValue = (float)3;    // 형변환을 통해 데이터 변환, 3을 float로 변환한 3.0f가 저장. 데이터의 손실이 없는 경우 묵시적 형변환을 권장함
    int intValue = (int)1.2;        // 1.2를 int로 변환하는 과정 중 보관할 수 없는 소수점이 버려짐. 의도하는 경우 명시적 형변환을 권장함
    cout << "float 변수에 3을 형변환하여 집어넣은 데이터는 " << floatValue << " 입니다." << endl;
    cout << "int 변수에 1.2를 형변환하여 집어넣은 데이터는 " << intValue << " 입니다." << endl;


    // <묵시적 형변환>
    // 변수에 데이터를 넣는 과정에서 자료형이 다른 경우 자동으로 형변환을 진행
    // 이 때, 데이터의 손실을 최소화하는 방향으로 형변환을 진행
    // 주의! 묵시적 형변환을 통해 데이터가 손실되는 경우를 조심해야하며 의도적인 데이터 손실의 경우 명시적 형변환을 권장함
    int num1 = 3.14;            // 주의! 의도하지 않은 경우 소수점 데이터의 손실을 주의해야함. 의도하는 경우 명시적 형변환을 권장함
    double num2 = 5;            // 실수형 자료형이 표현할 수 있는 범위의 데이터는 손실없이 저장 가능. 데이터의 손실이 없는 경우 묵시적 형변환을 권장함

    cout << "정수형 자료형으로 나눗셈을 진행하는 경우 : " << 1 / 4 << endl;           // 소수점이 버려진 0
    cout << "실수형 자료형으로 나눗셈을 진행하는 경우 : " << 1.0 / 4.0 << endl;       // 소수점이 있는 0.25
    cout << "정수형 자료형을 형변환 한 후 진행하는 경우 : " << (double)1 / 4 << endl; // 소수점이 있는 0.25


    // <문자 형변환과 아스키코드>
    // 아스키코드 : 이진법을 사용하는 컴퓨터에서 문자를 표현하기 위해 정해둔 문자와 숫자의 매칭표
    cout << "아스키코드 65는 " << (char)65 << " 로 표현합니다." << endl;
    cout << "문자 'a'는 " << (int)'a' << " 로 저장합니다." << endl;


    // <문자열 형변환>
    // 문자열의 경우 string 헤더의 함수를 이용하여 형변환 진행
    // 문자열 형변환 과정 중 형변환이 불가능한 경우 예외처리가 발생
    cout << stoi("123") << endl;    // stoi : string을 int로 변환
    cout << stof("3.1") << endl;    // stof : string을 float로 변환
    cout << stod("5.4") << endl;    // stod : string을 double로 변환
    // cout << stoi("abc");         // error : 형변환이 불가능한 문자열의 경우 예외처리 발생

    cout << to_string(123) << endl; // to_string : 다른 자료형의 데이터를 string으로 변환
    cout << to_string(3.1) << endl;
}
