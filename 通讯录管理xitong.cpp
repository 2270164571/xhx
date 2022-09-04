#include<iostream>
#include<cstring>
#define MAX 1000
using namespace std;
void showMenu(){
	cout<<"*****************************"<<endl; 
	cout<<"********1、添加联系人********"<<endl;
	cout<<"********2、显示联系人********"<<endl;
	cout<<"********3、删除联系人********"<<endl;
	cout<<"********4、查找联系人********"<<endl;
	cout<<"********5、修改联系人********"<<endl;
	cout<<"********6、清空联系人********"<<endl;
	cout<<"********0、退出通讯录********"<<endl; 
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
		cout<<"通讯录已满"<<endl;
		return ;
	}else{
		cout<<"请依次输入姓名、性别、年龄、电话号码"<<endl;
		cin>>abc->personArray [abc->M_size ].Name;
		cout<<"姓名添加成功"<<endl;
		getchar();
		scanf("%c",&abc->personArray [abc->M_size].Sex);
		cout<<"性别添加成功"<<endl;
		scanf("%d",&abc->personArray [abc->M_size].Age);
		cout<<"年龄添加成功"<<endl;
		getchar();
		cin>>abc->personArray [abc->M_size].Phone;
		cout<<"电话号码添加成功"<<endl;
		abc->M_size ++;
		cout<<"已添加成功"<<endl;
	}
	system("pause");
	system("cls");
}
void showPerson(Addressbooks *abc){
	if(abc->M_size ==0){
		cout<<"联系人为空"<<endl;
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
			cout<<"找到了"<<endl;
		}
	}
	return -1;
}
void deletPerson(Addressbooks *abc){
	cout<<"请输入你要删除的联系人"<<endl;
	string name;
	cin>>name;
	int ret=isExist(abc,name);
	if(ret==-1){
		cout<<"查无此人"<<endl;
	}else{
		for(int i=ret;i<abc->M_size ;i++){
			abc->personArray [i]=abc->personArray [i+1];
		}
		abc->M_size --;
		cout<<"删除成功"<<endl;
	}
	system("pause");
	system("cls");
}
void findPerson(Addressbooks *abc){
	cout<<"请输入你要查找的联系人"<<endl;
	string name;
	cin>>name;
	int ret=isExist(abc,name);
	if(ret==-1){
		cout<<"查无此人"<<endl;
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
	cout<<"请输入你要查找的联系人"<<endl;
	string name;
	cin>>name;
	int ret=isExist(abc,name);
	if(ret==-1){
		cout<<"查无此人"<<endl;
	}else{
		cout<<"请依次输入姓名、性别、年龄、电话号码"<<endl;
		cin>>abc->personArray [ret].Name;
		cout<<"姓名修改成功"<<endl;
		scanf("%c",&abc->personArray [ret].Sex);
		cout<<"性别修改成功"<<endl;
		scanf("%d",&abc->personArray [ret].Age);
		cout<<"年龄修改成功"<<endl;
		cin>>abc->personArray [ret].Phone;
		cout<<"电话号码修改成功"<<endl;
		cout<<"修改成功"<<endl; 
	}
	system("pause");
	system("cls");
}
void cleanPerson(Addressbooks *abc){
	abc->M_size =0;
	cout<<"通讯录已清空"<<endl;
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
				cout<<"欢迎下次使用"<<endl;
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
