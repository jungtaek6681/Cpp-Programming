#include <iostream>

using namespace std;

/************************************************************************
 * ���ӽ����̽� (Namespace)
 *
 * C++ ���α׷��� �ۼ��� �� �߻��ϴ� �̸��� �ߺ��Ǵ� ��츦 �����ϴ� ���
 ************************************************************************/

 // <namespace ��������>
 // ���� �̸��� �ߺ��� �Ǵ� ��쿡�� ���ӽ����̽��� �ٸ��ٸ� �浹�� ó������ ����
namespace A
{
    int value;
}
namespace B
{
    int value;
}
int value;          // ���ӽ����̽��� �������� ����


// <namespace ���>
// :: �ݷ� �տ� ���ӽ����̽� �̸��� �ٿ� ���
void Namespace_Main1()
{
    A::value = 10;
    B::value = 20;
    ::value = 30;   // ���ӽ����̽��� �������� ���� ��� ���ٹ��
}


// <using namespace>
// ���� ������ ���� �ڵ���� ���ӽ����̽��� ������ �ʰ� ��밡��
namespace A
{
    int target;
}
using namespace A;
void Namespace_Main2()
{
    target = 30;        // A::target = 30;
}