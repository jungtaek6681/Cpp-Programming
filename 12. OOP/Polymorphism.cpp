#include <iostream>

using namespace std;

/***************************************************************************
 * ������ (Polymorphism)
 *
 * ��ü�� �Ӽ��̳� ����� ��Ȳ�� ���� �������� ���¸� ���� �� �ִ� ����
 ****************************************************************************/

 // <������>
 // �θ�Ŭ������ �Լ��� �ڽ�Ŭ�������� �������Ͽ� �ڽ�Ŭ������ ���� �ٸ� ������ ����

class Car
{
protected:
    string name;
    int speed;

public:
    void Move()
    {
        cout << name << " ��/��" << speed << "�� �ӵ��� �̵��մϴ�." << endl;
    }
};

class SportsCar : public Car
{
public:
    SportsCar()
    {
        name = "������ī";
        speed = 100;
    }
};

class Truck : public Car
{
public:
    Truck()
    {
        name = "Ʈ��";
        speed = 30;
    }
};

void Polymorphism_Main1()
{
    SportsCar sportCar = SportsCar();
    Truck truck = Truck();

    sportCar.Move();    // ������ī ��/�� 100�� �ӵ��� �̵��մϴ�.
    truck.Move();       // Ʈ�� ��/�� 30�� �ӵ��� �̵��մϴ�.
}


// <�����Լ��� �������̵�>
// �����Լ�   : �θ�Ŭ������ �Լ� �� �ڽ�Ŭ������ ���� ������ �� �� �ִ� �Լ��� ����
// �������̵� : �θ�Ŭ������ �Լ��� ���� �Լ��̸��� ���� �Ű������� ������

class Skill
{
public:
    virtual void Execute()
    {
        cout << "��ų ���� ���ð��� �����Ŵ" << endl;
    }
};

class FireBall : public Skill
{
public:
    void Execute() override
    {
        Skill::Execute();
        cout << "���̾ ��ų�� �����" << endl;
    }
};

class Rush : public Skill
{
public:
    void Execute() override
    {
        cout << "���� ��ų�� �����" << endl;
    }
};


void Polymorphism_Main2()
{
    // <�������ε�>
    // ������ ��ÿ� ȣ��� �Լ��� ����
    // ������ �ڷ����� ������� ȣ���� �Լ��� ����
    Skill sValue = Skill();
    Skill fValue = FireBall();
    Rush rValue = Rush();

    // �ڷ����� �������� �Լ��� ȣ����
    sValue.Execute();           // Skill::Execute() �� ȣ���
    fValue.Execute();           // Skill::Execute() �� ȣ���
    rValue.Execute();           // Rush::Execute() �� ȣ���


    // <�������ε�>
    // ��Ÿ�� ��ÿ� ȣ��� �Լ��� ����
    // virtual �Լ��� �����ϴ� ��ü�� �����Լ����̺��� ������
    // �����Լ��� �������ϴ� ��� �����Լ����̺��� �ּҰ��� �������� �Լ��� �ּҷ� ����
    // ȣ��� �����Լ����̺� �ִ� �Լ� �ּҸ� �о� �Լ��� ����
    Skill* sPtr = new Skill();
    Skill* fPtr = new FireBall();
    Rush* rPtr = new Rush();

    // �����Լ����̺� ����� �Լ��� ȣ���� : �ν��Ͻ��� �������� �Լ��� ȣ���
    sPtr->Execute();            // Skill::Execute() �� ȣ���
    fPtr->Execute();            // FireBall::Execute() �� ȣ���
    rPtr->Execute();            // Rush::Execute() �� ȣ���

    delete sPtr;
    delete fPtr;
    delete rPtr;
}

// <������ ����ǹ� 1>
// ���ο� Ŭ������ �߰��ϰų� Ȯ���� �� ���� �ڵ忡 ������ �ּ�ȭ��

class Heal : public Skill       // ���ο� Ŭ������ ���� �� ������ �ҽ��� �������� �ʾƵ� ��
{
public:
    void Execute() override
    {
        Skill::Execute();
        cout << "ġ�� ��ų�� �����" << endl;
    }
};


// <������ ����ǹ� 2>
// Ŭ���� ���� �������� �ٿ� Ȯ�强�� ���̰� ���յ��� ����

class RapidShot : public Skill
{
public:
    void Execute() override     // �����Ǹ� ���� Ȯ�强�� Ȯ���ϸ�, �ٸ� Ŭ������ ������ ��ġ�� ����
    {
        cout << "���ӻ�� ��ų�� �����" << endl;
    }
};