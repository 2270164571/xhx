#include<iostream>
#include<cstring>
#define MAX 1000
using namespace std;
void showMenu(){
	cout<<"*****************************"<<endl; 
	cout<<"********1�������ϵ��********"<<endl;
	cout<<"********2����ʾ��ϵ��********"<<endl;
	cout<<"********3��ɾ����ϵ��********"<<endl;
	cout<<"********4��������ϵ��********"<<endl;
	cout<<"********5���޸���ϵ��********"<<endl;
	cout<<"********6�������ϵ��********"<<endl;
	cout<<"********0���˳�ͨѶ¼********"<<endl; 
	cout<<"*****************************"<<endl;
} 
struct Person{
	string Name;
	char Sex;
	int Age;
	string Phone;
};
struct Addressbooks{
	struct Person personArray[MAX];
	int M_size;
	Addressbooks(){
		M_size=0;
	}
};
void addPerson(Addressbooks *abc){
	if(abc->M_size ==MAX){
		cout<<"ͨѶ¼����"<<endl;
		return ;
	}else{
		cout<<"�����������������Ա����䡢�绰����"<<endl;
		cin>>abc->personArray [abc->M_size ].Name;
		cout<<"������ӳɹ�"<<endl;
		getchar();
		scanf("%c",&abc->personArray [abc->M_size].Sex);
		cout<<"�Ա���ӳɹ�"<<endl;
		scanf("%d",&abc->personArray [abc->M_size].Age);
		cout<<"������ӳɹ�"<<endl;
		getchar();
		cin>>abc->personArray [abc->M_size].Phone;
		cout<<"�绰������ӳɹ�"<<endl;
		abc->M_size ++;
		cout<<"����ӳɹ�"<<endl;
	}
	system("pause");
	system("cls");
}
void showPerson(Addressbooks *abc){
	if(abc->M_size ==0){
		cout<<"��ϵ��Ϊ��"<<endl;
	}else{
		for(int i=0;i<abc->M_size ;i++){
			cout<<abc->personArray [i].Name<<"\t";
			cout<<abc->personArray [i].Sex<<"\t";
			cout<<abc->personArray [i].Age<<"\t";
			cout<<abc->personArray [i].Phone<<endl;
		}
	}
	system("pause");
	system("cls");
} 
int isExist(Addressbooks *abc,string name){
	for(int i=0;i<abc->M_size;i++){
		if(abc->personArray[i].Name ==name){
			return i;
			cout<<"�ҵ���"<<endl;
		}
	}
	return -1;
}
void deletPerson(Addressbooks *abc){
	cout<<"��������Ҫɾ������ϵ��"<<endl;
	string name;
	cin>>name;
	int ret=isExist(abc,name);
	if(ret==-1){
		cout<<"���޴���"<<endl;
	}else{
		for(int i=ret;i<abc->M_size ;i++){
			abc->personArray [i]=abc->personArray [i+1];
		}
		abc->M_size --;
		cout<<"ɾ���ɹ�"<<endl;
	}
	system("pause");
	system("cls");
}
void findPerson(Addressbooks *abc){
	cout<<"��������Ҫ���ҵ���ϵ��"<<endl;
	string name;
	cin>>name;
	int ret=isExist(abc,name);
	if(ret==-1){
		cout<<"���޴���"<<endl;
	}else{
		cout<<abc->personArray [ret].Name<<"\t";
		cout<<abc->personArray [ret].Sex<<"\t";
		cout<<abc->personArray [ret].Age<<"\t";
		cout<<abc->personArray [ret].Phone<<endl;
	}
	system("pause");
	system("cls");
}
void modifyPerson(Addressbooks *abc){
	cout<<"��������Ҫ���ҵ���ϵ��"<<endl;
	string name;
	cin>>name;
	int ret=isExist(abc,name);
	if(ret==-1){
		cout<<"���޴���"<<endl;
	}else{
		cout<<"�����������������Ա����䡢�绰����"<<endl;
		cin>>abc->personArray [ret].Name;
		cout<<"�����޸ĳɹ�"<<endl;
		scanf("%c",&abc->personArray [ret].Sex);
		cout<<"�Ա��޸ĳɹ�"<<endl;
		scanf("%d",&abc->personArray [ret].Age);
		cout<<"�����޸ĳɹ�"<<endl;
		cin>>abc->personArray [ret].Phone;
		cout<<"�绰�����޸ĳɹ�"<<endl;
		cout<<"�޸ĳɹ�"<<endl; 
	}
	system("pause");
	system("cls");
}
void cleanPerson(Addressbooks *abc){
	abc->M_size =0;
	cout<<"ͨѶ¼�����"<<endl;
	system("pause");
	system("cls");
}

int main(){
	Addressbooks abc;
	while(true){
		int select=0;
		showMenu();	
		cin>>select;
		switch(select){
			case 1:
				addPerson(&abc);
				break;
			case 2:
				showPerson(&abc);
				break;
			case 3:
				deletPerson(&abc);
				break;
			case 4:
				findPerson(&abc);
				break;
			case 5:
				modifyPerson(&abc);
				break;
			case 6:
				cleanPerson(&abc);
				break;
			case 0:
				cout<<"��ӭ�´�ʹ��"<<endl;
				system("pause");
				return 0;
				break;
			default:
				break;
		}
	}
	system("pause");
	return 0;
}
