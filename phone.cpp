#include<iostream>
#include<string>
#define M 1000
using namespace std;
void MeNu()
{
    cout<<"************************"<<endl;
    cout<<"***** 1.添加联系人 *****"<<endl;
    cout<<"***** 2.显示联系人 *****"<<endl;
    cout<<"***** 3.删除联系人 *****"<<endl;
    cout<<"***** 4.查找联系人 *****"<<endl;
    cout<<"***** 5.修改联系人 *****"<<endl;
    cout<<"***** 6.清空联系人 *****"<<endl;
    cout<<"***** 0.退出通讯录 *****"<<endl;
    cout<<"************************"<<endl;
}

struct Person
{
    string name;
    string sex;//性别
    int age;
    string num;//电话号码
};

struct Contacts
{
    struct Person p[M];
    int member;
};

void Add(Contacts *a)
{
    if(a->member==M){
        cout<<"通讯录已满，无法添加!"<<endl;
        return;
    }
    else{
        string name;
        string sex;
        int age;
        string num;

        cout<<"姓名：";
        cin>>name;
        cout<<"性别：";
        cin>>sex;
        cout<<"年龄：";
        cin>>age;
        cout<<"电话号码：";
        cin>>num;

        //用户输入的名字添加到通讯录结构体中
        a->p[a->member].name=name;
        a->p[a->member].sex=sex;
        a->p[a->member].age=age;
        a->p[a->member].num=num;
        a->member++;
    }
}
void Show(Contacts *a)
{
    if(a->member==0){
        cout<<"当前记录为空"<<endl;
    return;
    }
    else{
        for(int i=0;i<a->member;i++){
            cout<<"姓名："<<a->p[i].name;
            cout<<"性别："<<a->p[i].sex;
            cout<<"年龄："<<a->p[i].age;
            cout<<"电话号码："<<a->p[i].num<<endl;
        }
    }
    

}
int Exist(Contacts *a,string name)
{
    for(int i=0;i<a->member;i++){
        if(a->p[i].name==name){
            return i;
        }
    }
    return -1;//如果没找到这个人
}
void Delete(Contacts *a)
{
    cout<<"请输入人名：";
    string name;
    cin>>name;
    int ret=Exist(a,name);
    if(ret!=-1){
        for(int i=ret;i<a->member;i++){
            a->p[i]=a->p[i+1];
        }
        a->member--;
        cout<<"已删除"<<endl;
    }
    else{
        cout<<"查无此人"<<endl;
    }
}
void Clean(Contacts *a)
{
    a->member=0;
    cout<<"已清空"<<endl;
    system("read");
    system("clear");
}
int main()
{
    MeNu();
    struct Contacts a;
    a.member=0;
    int input=0;
    while(true){
        cout<<"需要什么服务？"<<endl;
        cin>>input;
        switch(input){
            case 1:{Add(&a);break;}
            case 2:{Show(&a);break;}
            case 3:
            {
                system("clear");//清零
                Delete(&a);
                system("pause");
                break;
            }
            case 4:break;
            case 5:break;
            case 6:{Clean(&a);break;}
            case 0:
            {
                system("clear");//清零
                cout<<"欢迎下次使用"<<endl;
                system("read");//任意键退出
                return 0;
                break;
            }
            default:break;
        }   
    }
    
    return 0;

}