//
// Created by Chriss on 2018/2/20.
//

#include "LibrarySystem.h"
#include<iostream>
using namespace std;

long bnum = 10000;
long rnum = 10000;

/***********************************************
 * 功能描述：欢迎界面
 * 输入参数：无
 * 输出参数：无
 * 返回值：无
 * 其他说明：主界面
************************************************/
void Face()
{
    cout<<endl<<"          ----------欢迎进入合肥工业大学图书管理系统----------           "<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                |     *1.图书管理      |"<<endl;
    cout<<"                |     *2.读者管理      |"<<endl;
    cout<<"                |     *3.退出系统      |"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                     *请输入您的选择： ";
}
/***********************************************
 * 功能描述：读者管理界面
 * 输入参数：无
 * 输出参数：无
 * 返回值：无
 * 其他说明：界面2
************************************************/
void Face_Reader()
{
    cout<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                |      *1.读者一览     |"<<endl;
    cout<<"                |      *2.读者查询     |"<<endl;
    cout<<"                |      *3.添加读者     |"<<endl;
    cout<<"                |      *4.修改读者     |"<<endl;
    cout<<"                |      *5.删除读者     |"<<endl;
    cout<<"                |      *6.返回上页     |"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                     *请输入您的选择： ";
}
/***********************************************
 * 功能描述：图书管理界面
 * 输入参数：无
 * 输出参数：无
 * 返回值：无
 * 其他说明：界面3
************************************************/
void Face_Book()
{
    cout<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                |      *1.图书一览     |"<<endl;
    cout<<"                |      *2.图书查询     |"<<endl;
    cout<<"                |      *3.添加图书     |"<<endl;
    cout<<"                |      *4.删除图书     |"<<endl;
    cout<<"                |      *5.图书借还     |"<<endl;
    cout<<"                |      *6.图书修改     |"<<endl;
    cout<<"                |      *7.到期催还     |"<<endl;
    cout<<"                |      *8.返回上页     |"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                     *请输入您的选择： ";
}
/***********************************************
 * 功能描述：读者查询界面
 * 输入参数：无
 * 输出参数：无
 * 返回值：无
 * 其他说明：界面4
************************************************/
void Face_ReaderSearch()
{
    cout<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                |      *1.按姓名查询   |"<<endl;
    cout<<"                |      *2.按编号查询   |"<<endl;
    cout<<"                |      *3.返回上页     |"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                     *请输入您的选择： ";
}
/***********************************************
 * 功能描述：图书查询界面
 * 输入参数：无
 * 输出参数：无
 * 返回值：无
 * 其他说明：界面5
************************************************/
void Face_BookSearch()
{
    cout<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                |      *1.按书名查询   |"<<endl;
    cout<<"                |      *2.按编号查询   |"<<endl;
    cout<<"                |      *3.按书号查询   |"<<endl;
    cout<<"                |      *4.返回上页     |"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                     *请输入您的选择： ";
}
/***********************************************
 * 功能描述：图书借还界面
 * 输入参数：无
 * 输出参数：无
 * 返回值：无
 * 其他说明：界面6
************************************************/
void Face_BookBorrowReturn()
{
    cout<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                |      *1.借书服务     |"<<endl;
    cout<<"                |      *2.还书服务     |"<<endl;
    cout<<"                |      *3.借书一览     |"<<endl;
    cout<<"                |      *4.返回上页     |"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                     *请输入您的选择： ";
}
/***********************************************
 * 功能描述：退出界面
 * 输入参数：无
 * 输出参数：无
 * 返回值：无
 * 其他说明：界面7
************************************************/
void Face_Exit()
{
    cout<<endl;
    cout<<endl;
    cout<<"          ----------欢迎再次登陆图书管理系统----------           "<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"                                                     ---Developed by ChrissHwuang"<<endl;
}
/***********************************************
 * 功能描述：读者文件初始化
 * 输入参数：rtail-读者链表尾指针
 * 输出参数：无
 * 返回值：读者链表
 * 其他说明：无
************************************************/
Reader *Reader_Initial(ReaderList &rtail)
{
    Reader *rhead;
    rhead=(Reader *)malloc(sizeof(Reader));
    if(!rhead)
        exit(1);
    rtail=rhead;
    rhead->next=NULL;
    return rhead;
}
/***********************************************
 * 功能描述：添加读者
 * 输入参数：rtail-读者链表尾指针
 * 输出参数：是否成功添加
 * 返回值：（1）
 * 其他说明：无
************************************************/
int Reader_Add(ReaderList &rtail)
{
    Reader * t;
    int i,j;
    i = 0;
    t=(Reader *)malloc(sizeof(Reader));
    if(!t)
        exit(1);
    cout<<"         ----------系统已经就绪，是否开始添加读者？----------"<<endl;
    cout<<"                     (1->yes ; 0->no)"<<endl;
    cin>>j;
    while(j==1)
    {
        cout<<endl;
        cout<<"          ---------- ---------- ---------- ----------"<<endl;
        cout<<"                     *请输入读者姓名： ";
        cin>>t->reaName;
        cout<<"                     *请输入读者性别：(m->男 ; f->女) ";
        cin>>t->reaSex;
        cout<<"                     *请输入读者类型：（s->学生 ； t->教师）";
        cin>>t->reaClass;
        t->reaNum = rnum++;
        t->rea_yes = 0;
        rtail = t;
        rtail = rtail->next;
        rtail->next = NULL;
        i++;
        cout<<"         ----------是否继续添加读者？----------"<<endl;
        cout<<"                   (1->yes ; 0->no)"<<endl;
        cin>>j;
    }
    cout<<"         ----------已成功添加"<<i<<"位读者！"<<endl;
    return 1;
}
/***********************************************
 * 功能描述：读者一览
 * 输入参数：rhead-读者链表头指针
 * 输出参数：读者信息
 * 返回值：1
 * 其他说明：无
************************************************/
int Reader_View(ReaderList &rhead)
{
    Reader *t;
    cout<<setw(10)<<"姓名"<<setw(17)<<"编号"<<setw(8)<<"性别"<<setw(10)<<"读者类型"<<setw(10)<<"是否借书"<<endl;
    if(rhead->next == NULL)
        cout<<"             ----------暂无读者！----------"<<endl;
    else
    {
        t=rhead->next;
        while(t)
        {
            cout<<setw(10)<<t->reaName;
            cout<<setw(17)<<t->reaNum;
            if(t->reaSex == 'm')
                cout<<setw(8)<<"男";
            else if(t->reaSex == 'f')
                cout<<setw(8)<<"女";
            if(t->reaClass == 's')
                cout<<setw(10)<<"学生";
            else if(t->reaClass == 't')
                cout<<setw(10)<<"教师";
            if(t->rea_yes == 1)
                cout<<setw(10)<<"是"<<endl;
            else if(t->rea_yes == 0)
                cout<<setw(10)<<"否"<<endl;
            t=t->next;
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：判断读者合法
 * 输入参数：rhead-读者链表头指针、读者编号
 * 输出参数：无
 * 返回值：bool
 * 其他说明：无
************************************************/
bool Reader_Check(ReaderList &rhead,long rnum)
{
    Reader *t;
    for(t=rhead->next;t!=NULL;t=t->next)
    {
        if(rnum == t->reaNum)
            break;
    }
    if(t!=NULL)
        return true;
    else if(t==NULL)
        return false;
}
/***********************************************
 * 功能描述：读者查询选择菜单
 * 输入参数：1～3（对应相应功能）
 * 输出参数：相应界面
 * 返回值：（1）
 * 其他说明：3为退出
************************************************/
int ReaderSearch(ReaderList &rhead)
{
    int m=1;
    while(m!=3)
    {
        Face_ReaderSearch();
        cin>>m;
        switch(m)
        {
            case 1:
                ReaderSearch_Name(rhead);
                break;
            case 2:
                ReaderSearch_Num(rhead);
                break;
            case 3:
                break;
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：读者管理选择菜单
 * 输入参数：1～6（对应相应功能）
 * 输出参数：相应界面
 * 返回值：（1）
 * 其他说明：6为退出;需要尾指针
************************************************/
int ReaderManager(ReaderList &rhead,ReaderList &rtail)
{
    int m=1;
    while(m!=6)
    {
        Face_Reader();
        cin>>m;
        switch(m)
        {
            case 1:
                Reader_View(rhead);
                break;
            case 2:
                ReaderSearch(rhead);
                break;
            case 3:
                Reader_Add(rtail);
                break;
            case 4:
                Reader_Correct(rhead);
                break;
            case 5:
                Reader_Delet(rhead);
                break;
            case 6:
                break;
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：读者信息修改
 * 输入参数：读者的相关修改信息
 * 输出参数：新的读者文件
 * 返回值：1
 * 其他说明：无
************************************************/
int Reader_Correct(ReaderList &rhead)
{
    Reader *t;
    long m;
    t=NULL;
    cout<<"         ----------读者信息修改----------"<<endl;
    while(!t)
    {
        cout<<"   *请输入需要修改信息的读者编号： ";
        cin>>m;
        for(t=rhead->next;t!=NULL;t=t->next)
        {
            if(t->reaNum == m)
                break;
        }
        if(t == NULL)
        {
            cout << "     ----------对不起，读者编号输入错误！----------" << endl;
            continue;
        }
        else if(t != NULL)
        {
            cout<<"     *请输入修改后的读者姓名：";
            cin>>t->reaName;
            cout<<"     *请输入修改后的读者性别：(m->男 ； f->女)";
            cin>>t->reaSex;
            cout<<"     *请输入修改后的读者类型：(s->学生 ; t->老师)";
            cin>>t->reaClass;
            cout<<endl;
            cout<<"         ----------读者信息已成功修改！----------"<<endl;
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：图书管理选择菜单
 * 输入参数：1～8（对应相应功能）
 * 输出参数：相应界面
 * 返回值：（1）
 * 其他说明：8为退出；需要尾指针；需要读者链表
************************************************/
int BookManager(BookList &bhead,BookList &btail,ReaderList &rhead)
{
    int m=1;
    while(m!=8)
    {
        Face_Book();
        cin>>m;
        switch(m)
        {
            case 1:
                Book_View(bhead);
                break;
            case 2:
                BookSearch(bhead);
                break;
            case 3:
                Book_Add(btail);
                break;
            case 4:
                Book_Delet(bhead);
                break;
            case 5:
                Book_BnR(bhead);
                break;
            case 6:
                Book_Correct(bhead);
                break;
            case 7:
                Book_TimeLimit(BookList &bhead,ReaderList &rhead);
                break;
            case 8:
                break;
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：图书查询选择菜单
 * 输入参数：1～4（对应相应功能）
 * 输出参数：相应界面
 * 返回值：（1）
 * 其他说明：4为退出
************************************************/
int BookSearch(BookList &bhead) //测试！！ 输入4时会出现什么结果？
{
    int m=1;
    while(m!=4)
    {
        Face_BookSearch();
        cin>>m;
        switch(m)
        {
            case 1:
                BookSearch_Name(bhead);
                break;
            case 2:
                BookSearch_Num(bhead);
                break;
            case 3:
                BookSearch_ISBN(bhead);
                break;
            case 4:
                break;
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：图书文件初始化
 * 输入参数：无
 * 输出参数：无
 * 返回值：图书链表
 * 其他说明：无
************************************************/
Book *Book_Initial(BookList &btail)
{
    Book *bhead;
    bhead=(Book *)malloc(sizeof(Book));
    if(!bhead)
        exit(1);
    btail=bhead;
    bhead->next=NULL;
    return bhead;
}
/***********************************************
 * 功能描述：添加图书
 * 输入参数：图书链表尾指针
 * 输出参数：是否成功添加
 * 返回值：（1）
 * 其他说明：无
************************************************/
int Book_Add(BookList &btail)
{
    Book *t;
    int i,j;
    i = 0;
    t=(Book *)malloc(sizeof(Book));
    if(!t)
        exit(1);
    cout<<"         ----------系统已经就绪，是否开始添加图书？----------"<<endl;
    cout<<"                        (1->yes ; 0->no)"<<endl;
    cin>>j;
    while(j==1)
    {
        cout<<endl;
        cout<<"          ---------- ---------- ---------- ----------"<<endl;
        cout<<endl;
        cout<<"                     *请输入图书名称： ";
        cin>>t->bookName;
        cout<<"                     *请输入图书作者： ";
        cin>>t->bookAuth;
        cout<<"                     *请输入图书出版社： ";
        cin>>t->bookPub;
        cout<<"                     *请输入图书书号： ";
        cin>>t->bookIsbn;
        t->bookNum = bnum++;
        t->book_yes = 1;
        btail->next = t;
        btail = btail->next;
        btail->next = NULL;
        i++;
        cout<<"         ----------是否继续添加图书？----------"<<endl;
        cout<<"                 (1->yes ; 0->no)"<<endl;
        cin>>j;
    }
    cout<<"         ----------已将"<<i<<"本图书成功入库！----------"<<endl;
    return 1;
}
/***********************************************
 * 功能描述：图书一览
 * 输入参数：bhead-读者链表头指针
 * 输出参数：图书信息
 * 返回值：1
 * 其他说明：无
************************************************/
int Book_View(BookList &bhead)
{
    Book *t;
    cout<<setw(20)<<"书名"<<setw(17)<<"编号"<<setw(9)<<"作者"<<setw(30)<<"出版社"<<setw(30)<<"书号ISBN"<<setw(7)<<"在馆情况"<<endl;
    if(bhead->next==NULL)
        cout<<"     ----------暂无图书在馆！----------"<<endl;
    else
    {
        t=bhead->next;
        while(t)
        {
            cout<<setw(20)<<t->bookName;
            cout<<setw(17)<<t->bookNum;
            cout<<setw(9)<<t->bookAuth;
            cout<<setw(30)<<t->bookPub;
            cout<<setw(30)<<t->bookIsbn;
            if(t->book_yes == 1)
                cout<<setw(7)<<"是";
            else if(t->book_yes == 0)
                cout<<setw(7)<<"否";
            t=t->next;
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：判断图书合法
 * 输入参数：bhead-图书链表头指针、图书编号
 * 输出参数：无
 * 返回值：bool
 * 其他说明：无
************************************************/
bool Book_Check(BookList &bhead,long bnum)
{
    Book *t;
    for(t=bhead->next;t!=NULL;t=t->next)
    {
        if(t->bookNum == bnum)
            break;
    }
    if(t == NULL)
        return false;
    else if(t != NULL)
        return true;
}
