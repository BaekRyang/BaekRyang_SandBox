#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

bool CheckPassword(char[], int);

int main() {
CHECKID:
	const int maxPassword = 14; //최대로 입력 가능한 비밀번호의 길이를 설정
	char id[] = "ExampleID"; // ID로 사용할 문자열을 미리 등록
	char mailName[22] = { 0 }; //메일 네임을 등록할 배열을 선언후 초기화
	char mailServer[] = { "@mailserver.com" };
	char password[maxPassword] = { 0 }; //PASSWORD는 maxPassword에 써있는 크기만큼만 사용가능하게 해준다.
	char input[100] = { 0 }; //INPUT은 무슨 문장이 들어올지 알 수 없기 때문에 큰 크기로 선언해준다.
	cout << "ID를 입력해 주세요." << endl << "ID : ";
	cin >> input;
	if (strcmp(id, input) == 0) { //strcmp를 사용해서 등록되어있는 ID와 입력한 ID가 같은지 확인한다. 
		if (CheckPassword(password, maxPassword) == 1)  { //ID를 확인했으니 비밀번호를 등록하는 부분으로 넘어간다.
			cout << "로그인에 성공하셨습니다." << endl<<"안녕하세요. "; //등록이 완료되었다면 메세지를 띄워 확인해준다.

			//메일 네임을 만들기 위해 ID에 있는 단어중 맨앞의 5글자와 그 뒤에 "@mailserver.com" 를 붙여서 만들어 주려고 한다.
			strncpy(mailName, id, 5); //우선 ID의 맨앞의 5글자를 mailName에 strncpy로 복사해준다. 
			mailName[5] = '\0';
			strcat(mailName, mailServer); //그 뒤에 메일 서버 도메인을 strcat을 사용하여 붙여준다.  
			for (int i = 0; mailName[i] != '\0'; i++) {
				cout << mailName[i];
			}
		}
	}
	else {
		cout << "잘못된 아이디 입니다." << endl << "아이디를 다시 입력해주세요. \n\n\n";
		goto CHECKID; //ID입력을 잘못했다면 처음부터 다시 시작한다.
	}
}

bool CheckPassword(char password[], int mp) {
CHECKPW:
	char input[100] = { 0 };
	cout << "사용하고 싶은 PASSWORD를 입력해 주세요." << endl<< "대소문자를 구별하며, 공백을 사용할 수 없습니다. (6~" << mp << ") " << endl << "PASSWORD : ";
	cin >> input;
	if (strlen(input) > mp || strlen(input) < 6) { //strlen을 사용하여 설정한 조건과 맞는 길이인지 확인한다. 
		cout << "비밀번호가 조건에 맞지 않습니다.(" << strlen(input) << ") 다시 입력해 주세요" << endl; //설정과 다른 길이라면 
			goto CHECKPW;
	}
	else {
		strcpy(password, input); // strcpy로 입력받은 값을 password에 저장시켜준다. 
		cout << "사용할 비밀번호가 [ ";
		for (int i = 0; password[i] != '\0'; i++) {
			cout << password[i];
		}
		cout << " ] 가 맞습니까? 맞다면 비밀번호를 재 입력해주세요" << endl << "PASSWORD : ";
		cin >> input;
		if (strcmp(password, input) == 0) { //다시 입력한 문자열이 password와 맞는지 비교한다
			cout << "비밀번호를 등록하였습니다." << endl;
			return true; //맞다면 true로 반환한다.
		}
		else {
			cout << "잘못된 비밀번호입니다. 비밀번호를 재등록 시켜주십시오" << endl;
			goto CHECKPW;
		}
	}
}