#include <iostream>

using namespace std;

/************************************************************************
 * 네임스페이스 (Namespace)
 *
 * C++ 프로그램을 작성할 때 발생하는 이름이 중복되는 경우를 방지하는 방법
 ************************************************************************/

 // <namespace 공간정의>
 // 같은 이름의 중복이 되는 경우에도 네임스페이스가 다르다면 충돌로 처리하지 않음
namespace A
{
    int value;
}
namespace B
{
    int value;
}
int value;          // 네임스페이스를 지정하지 않음


// <namespace 사용>
// :: 콜론 앞에 네임스페이스 이름을 붙여 사용
void Namespace_Main1()
{
    A::value = 10;
    B::value = 20;
    ::value = 30;   // 네임스페이스를 지정하지 않은 경우 접근방법
}


// <using namespace>
// 현재 파일의 이후 코드부터 네임스페이스를 붙이지 않고 사용가능
namespace A
{
    int target;
}
using namespace A;
void Namespace_Main2()
{
    target = 30;        // A::target = 30;
}