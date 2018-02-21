//
// Created by Chriss on 2018/2/19.
//

#ifndef UNTITLED_LIBRARYSYSTEM_H
#define UNTITLED_LIBRARYSYSTEM_H

#endif //UNTITLED_LIBRARYSYSTEM_H

#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip>

#define MAXB 5   //规定最大借书数目
#define MAXD 30 //规定借书期限

typedef struct BookInfo //图书文件结构体
{
    long bookNum;    //图书编号
    char bookName[100]; //图书名称
    char bookIsbn[30];  //书号
    char bookAuth[30];  //作者
    char bookPub[100];  //出版社
    int book_yes;   //在馆情况（0-已经借出；1-未借出）
    struct BookInfo *next;  //链表后继指针
}Book,*BookList;

typedef struct SetTime   //时间结构体
{
    int year;   //年份
    int month;  //月份
    int day;    //日期
}Time;

typedef struct ReaderBorrow //借书信息结构体
{
    long bookNum;    //图书编号
    char bookName[100]; //书名
    struct SetTime t;    //借书时间
}Borrow;

typedef struct ReaderInfo   //读者文件结构体
{
    long reaNum; //读者编号
    char reaName[30];   //读者姓名
    char reaSex;    //性别（m-男；f-女）
    char reaClass;  //类型（s-学生；t-教师)
    int rea_yes;   //是否借书（0-没有借书；1-有借书）
    struct ReaderBorrow reaborrow[MAXB];
    struct ReaderInfo *next;    //链表后继指针
}Reader,*ReaderList;

//界面
void Face();//欢迎界面
void Face_Reader();//读者管理界面
void Face_Book();//图书管理界面
void Face_ReaderSearch();//读者查询界面
void Face_BookSearch();//图书查询界面
void Face_BookBorrowReturn();//图书借还界面
void Face_Exit();//退出系统

Reader *Reader_Initial(ReaderList &);//读者文件初始化
//读者管理
int ReaderManager(ReaderList &,ReaderList &);//读者管理菜单
int Reader_View(ReaderList &);//读者一览
int Reader_Add(ReaderList &);//添加读者
int Reader_Correct(ReaderList &);//读者信息修改
int Reader_Delet(ReaderList &);//删除读者
int Reader_Sort(ReaderList &);//读者排序
//读者查询
int ReaderSearch(ReaderList &);//读者查询选择菜单
int ReaderSearch_Name(ReaderList &);//按姓名查询读者
int ReaderSearch_Num(ReaderList &);//按编号查询

Book *Book_Initial(BookList &);//图书文件初始化
// 图书管理
int BookManager(BookList &,BookList &,ReaderList &);//图书管理菜单
int Book_View(BookList &);//图书一览
int Book_Add(BookList &);//添加图书
int Book_Correct(BookList &);//图书信息修改
int Book_Delet(BookList &);//删除图书
int Book_Sort(BookList &);//图书排序
//图书查询
int BookSearch(BookList &);//图书查询选择菜单
int BookSearch_Name(BookList &);//按书名查询
int BookSearch_Num(BookList &);//按书编号查询
int BookSearch_ISBN(BookList &);//按书号查询
int Book_BnR(BookList &);//图书借还
int Book_Borrow(ReaderList &,BookList &);//借书
int Book_Return(ReaderList &,BookList &);//还书
int Book_BorrowInfo(ReaderList &);//借书信息

bool Reader_Check(ReaderList &,long);//判断读者是否合法
bool Book_Check(BookList &,long);//判断图书合法
int Book_TimeLimit(BookList &,ReaderList &);//到期催还

//全局变量声明
extern long bnum;
extern long rnum;
