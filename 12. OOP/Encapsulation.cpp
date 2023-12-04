#include <iostream>

using namespace std;

/****************************************************************
 * ĸ��ȭ (Encapsulation)
 *
 * ��ü�� ������ ������� ���� ���� �ǹ�
 * ��ü�� ���� ���¿� ����� �����, ����� ���¿� ��ɸ��� �׼��� ���
 ****************************************************************/

 // <ĸ��ȭ>
 // ��ü�� ������ ������� ���� ��, ��ü�� ������ ����� ������ ǥ����
 // ���Ǽ����� ��ü�� ǥ���ϱ� ���� ��ü�� ������ ������ �ൿ�� ���� �����ϸ� �̸� ���� ��ü�� ��ȣ�ۿ�

class Capsule
{
    int variable;       // ������� : ��ü�� ������ ǥ��
    void Function() {}  // ����Լ� : ��ü�� ����� ǥ��
};


// <����������>
// �ܺο��� ������ ������ ��������� ����Լ��� �����ϴ� ���
// 
// public    : �ܺο����� ���ٰ���
// private   : ���ο����� ���ٰ���
// protected : �ܺ������� private, ����� Ŭ������ public

class AccessSpecifier
{
public:
    int publicValue;
private:
    int privateValue;

    void Function()
    {
        publicValue;            // ���ٰ���
        privateValue;           // ���ٰ���
    }
};

void Encapsulation_Main1()
{
    AccessSpecifier instance;
    instance.publicValue;       // ���ٰ���
    // instance.privateValue;   // ���ٺҰ�
}


// <��������>
// ��ü ������ �־ �ܺο��� ����ϱ� ���ϴ� ��ɰ� ����ϱ� ������ �ʴ� ����� �����ϱ� ���� ���
// ����ڰ� ��ü�� ����ϴµ� �־ �ʿ��� ��ɸ��� Ȯ���ϱ� ���� �뵵�̸�
// �ܺο� ���� ������ ���� �ʱ� ���ϴ� ����� ���߱� ���� �뵵�̱⵵ ��

class Bank
{
    int balance;

public:
    void Save(int money)
    {
        balance += money;
    }
    void Load(int money)
    {
        balance -= money;
    }
};

void Encapsulation_Main2()
{
    Bank bank;

    // �ܺο��� Bank�� balance�� ���������� ���ٺҰ�
    // bank.balance = 0;

    // �ܺο����� Bank���� �ǵ��� Save�� Load�� ���� Bank�� �ٷ�� ����
    bank.Save(20000);
    bank.Load(10000);
}


// <ĸ��ȭ ����ǹ� 1 - ���⼺ ����>
// ĸ��ȭ�� Ŭ������ �ܺο��� ����ϱ� ���� �������̽����� ����
// ��, ĸ��ȭ�� Ŭ������ ���������� ��� �����Ǿ����� ���� ��밡��

class VeryComplicatedObject
{
    // ĸ��ȭ�� Ŭ������ private�� �ܺο��� ���ٺҰ��ϹǷ� ����� �� ����
    int veryComplicatedValue1;
    int veryComplicatedValue2;
    int veryComplicatedValue3;

    void VeryComplicatedFunction1() {}
    void VeryComplicatedFunction2() {}
    void VeryComplicatedFunction3() {}

public:
    // ĸ��ȭ�� Ŭ������ public�� �ܺο��� ���ٰ����ϹǷ� ����� �����ϴ� ���
    void UseThisFunction() {}
};


// <ĸ��ȭ ����ǹ� 2 - ���� ����>
// ĸ��ȭ�� Ŭ������ �ܺο��� ������ �ʴ� �������κ��� ��ȣ�� �� ����

class IntArray
{
    int array[10];

public:
    void SetValue(int index, int value)
    {
        if (index < 0 || index >= 10)
            return;

        array[index] = value;
    }
};