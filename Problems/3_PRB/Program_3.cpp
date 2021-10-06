#include <iostream>
#include <string>
using namespace std;


//���ۿ� �ռ� ��� Ŭ������ �Ҹ��ڰ� "LinkError 1120 : Ȯ���� �� ���� �ܺ� �����Դϴ�." �� �߻���
//�Ҹ��ڿ� �Լ��� ����Ǿ����� �ʱ� ������ ����� ������ Ȯ���ϰ� �Ҹ��ڸ� ������� ���� �����̱� ������
//��� Ŭ������ �Ҹ��ڸ� ������
class Person {
	string name;
	string address;
	string tel;
public:
	//�켱 Person�� ������ �⺻���� ������ �ʱ�ȭ ����Ʈ�� ����Ͽ� �־��ش�.
	Person(string nm, string addr, string t) : name(nm), address(addr), tel(t) {};
	//�⺻���� �Ż��� ����ϴ� �Լ��� ������ش�.
	void Infomations() {
		cout << "Hello! My name is \"" << name << "\"" << endl
			<< "My Address is \"" << address << "\"" << endl
			<< "and My Telephone-Number is \"" << tel << "\"" << endl;
	};
	//���� �����Լ� ����
	//�� �Լ��� �������� ���� Person�̶�� ��ü�� ������ �� ����.
	virtual void meet() = 0;
};

class Professor : public Person
{
public:
	//�⺻���� �Ż������� �Է��ϱ� ���� �μ��� ���� �������� Person�� �����ڿ� �Ѱ��༭
	//��������� �ʱ�ȭ �Ѵ�.
	Professor(string nm, string addr, string t) : Person(nm, addr, t) {};
	void teach() {
		cout << "Now teaching...";
		for (int i = 0; i < 3; i++) {
			cout << "..";
		}
		cout << endl << "Teaching Ended" << endl;
	};
	//�����Լ��� ����� meet()�� �� �ڽ� Ŭ������ �������ش�.
	//���� meet�� �������� �ʰ� �����Ͻ� �߻�Ŭ������ �ν��Ͻ�ȭ �� �� ���ٰ� �Ѵ�.
	void meet() {
		cout << "The professor is meeting another professor" << endl;
	};
};

class TennisPlayer : public Person
{
public:
	TennisPlayer(string nm, string addr, string t) : Person(nm, addr, t) {};
	void playTennis() {
		cout << "Now playing tennis...";
		for (int i = 0; i < 3; i++) {
			cout << "Tack!..";
		}
		cout << endl << "Play tenis Ended" << endl;
	};
	void meet() {
		cout << "The TennisPlayer is meeing Head Coach " << endl;
	};
};

class Businessman : public Person
{
public:
	Businessman(string nm, string addr, string t) : Person(nm, addr, t) {};
	void runBusiness() {
		cout << "Now Businessing...";
		for (int i = 0; i < 3; i++) {
			cout << "walk..";
		}
		cout << endl << "My Business Ended" << endl;
	};
	//�Լ� �������̵��� ���� �� Ŭ���������� �ٸ� ������ �ϰ� �� ���� �� �� �ִ�.
	void Infomations() {
		cout << endl << "My Infomations is Secreat" << endl;
	};
	void meet() {
		cout << "The Businessman is meeting Family" << endl;
	};
};

int main() {
	//��ü ����
	Professor pfs("Gwon Yeji", "Afreeca", "010-aaaa-aaaa");
	TennisPlayer tnp("Kim Minwoo", "Korea", "010-bbbb-bbbb");
	Businessman bsm("Park Chungkyu", "China", "010-cccc-cccc");
	//�Ż� �������� �Է����ش�.

	//�� Ŭ�������� �� �� �ִ� �۾����� �ٸ���.
	pfs.teach();
	cout << endl;
	tnp.playTennis();
	cout << endl;
	bsm.runBusiness();
	cout << endl;

	//�����Լ��� ����� �Լ��� ���
	pfs.meet();
	tnp.meet();
	bsm.meet();
	cout << endl;

	//�θ𿡰� ��ӹ��� �Լ� ���
	pfs.Infomations();
	tnp.Infomations();
	bsm.Infomations(); //�� ���ǵǾ��� ������ �ٸ� ����� ���´�.
}