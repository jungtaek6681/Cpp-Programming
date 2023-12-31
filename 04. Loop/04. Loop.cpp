﻿#include <iostream>

using namespace std;

int main()
{
    /****************************************************************
     * 반복문 (Iteration)
     *
     * 블록을 반복적으로 실행하는 문장
     ****************************************************************/

    /****************************************************************
     * while 반복문
     *
     * 조건식의 true, false에 따라 블록을 반복하는 반복문
     ****************************************************************/

    int coin = 1300;
    while (coin > 0)
    {
        if (coin >= 500)
        {
            cout << "500원 동전을 꺼냅니다." << endl;
            coin -= 500;
        }
        else if (coin >= 100)
        {
            cout << "100원 동전을 꺼냅니다." << endl;
            coin -= 100;
        }
        else
        {
            cout << "나머지 금액은 동전으로 꺼낼 수 없습니다." << endl;
            coin = 0;
        }
    }



    /****************************************************************
     * do while 반복문
     *
     * 블록을 한번 실행 후 조건식의 true, false에 따라 블록을 반복하는 반복문
     ****************************************************************/

    int input;
    do
    {
        cout << "1 에서 9 사이의 수를 입력하세요 : ";
        cin >> input;
    } while (input < 1 || 9 < input);



    /****************************************************************
     * for 반복문
     *
     * 초기화, 조건식, 증감연산 으로 구성된 반복문
     ****************************************************************/

    for (int i = 0; i < 5; i++)
    {
        cout << "for 반복문 반복횟수 : " << i << endl;
    }



    /****************************************************************
     * 제어문
     *
     * 프로그램의 순차적인 실행 중 다른 문으로 제어를 전송
     ****************************************************************/

    /****************************************************************
     * break 제어문
     *
     * 가장 가까운 반복문을 종료
     ****************************************************************/

    int num = 35;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            cout << num << "을 나눌 수 있는 가장 작은 수는 " << i << "입니다." << endl;
            break;
        }
    }



    /****************************************************************
     * continue 제어문
     *
     * 가장 가까운 반복문의 새 반복을 시작
     ****************************************************************/

    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            continue;
        if (i % 3 == 0)
            continue;

        cout << i << "은 2의 배수와 3의 배수가 아닙니다." << endl;
    }
}
