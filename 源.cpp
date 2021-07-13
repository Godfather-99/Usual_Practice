/*3.7 校园快餐POS机计费系统 （链表与文件存储）
【任务描述】
校园快餐店一共出售3大类食品，饮料，主食，小食品。设计一个POS机计费系统，对快餐店的销售信息进行管理。
【功能要求】
（1）管理员功能：
	对食品信息进行管理：添加、查询、修改，删除、存盘。且能够对食品进行多种查询。
	销售信息管理：录入顾客一次购买的食品信息。包括食品编号、单价、数量等。计算购买食品的总金额，用
	户所付金额，找零金额，输出消费明细账单。
	提供多种统计功能：可对指定日期、指定名称食品、指定种类食品的销量、收入总额等数据进行统计，并按
	一定的格式进行显示。
（2）设计要求
    //系统只设置一个管理员，管理员通过密码登录系统，进行系统管理和食品销售以及各类信息查询 .*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct Fastfood Fastfood;		//便于操作

struct Fastfood
{	
	unsigned int F_Save;			//食品库存
	char F_Price[10];				//食品单价
	char F_Name[20];				//食品名称
	char F_ID[20];					//食品编号

	Fastfood* next;
};

//为该快餐店各类食品的信息初始化
struct Fastfood F_Class[9] = { {200,"5.00","百事可乐","D1001"},{150,"6.00","鲜榨橙汁","D1002"},
					   {200,"7.00","牛奶奶茶","D1003"},{300,"10.00","兰州拉面","M1001"},
					   {350,"15.00","咖喱盖饭","M1002"},{400,"8.00","扬州炒饭","M1003"},
					   {250,"5.00","煎饼果子","S1001"},{200,"4.00","香甜糍粑","S1002"},
					   {200,"7.00","灯影牛肉","S1003"} };

struct Fastfood *CreateLink();			    //函数声明1 ，创建链表
void Login_S();							    //函数声明2 ，登录系统
void Mainmenu(Fastfood*);					//函数声明3 ，进入主菜单

void FoodM_M(Fastfood*);					//函数声明4 ，食品信息管理
void FoodR_S(Fastfood*);					//函数声明5 ，食品在线销售
void FoodS_T(static int*,					//函数声明6 ，食品销售统计
	static double*,static int*, static double*);

void FoodC_Add(Fastfood*);				    //函数声明7 ，食品类别添加
void FoodAC_D(Fastfood*);					//函数声明8 ，食品添加类别-饮料类
void FoodAC_M(Fastfood*);				    //函数声明9 ，食品添加类别-主食类
void FoodAC_S(Fastfood*);					//函数声明10，食品添加类别-小吃类

void FoodC_Del(Fastfood*);				    //函数声明11，食品类别删除
void FoodDC_D(Fastfood*);					//函数声明12，食品删除类别-饮料类
void FoodDC_M(Fastfood*);				    //函数声明13，食品删除类别-主食类
void FoodDC_S(Fastfood*);					//函数声明14，食品删除类别-小吃类


void FoodM_Mod(Fastfood*);				    //函数声明15，食品信息修改
void FoodMC_D(Fastfood*);					//函数声明16，食品修改类别-饮料类
void FoodMC_M(Fastfood*);				    //函数声明17，食品修改类别-主食类
void FoodMC_S(Fastfood*);					//函数声明18，食品修改类别-小吃类
 
void FoodM_See(Fastfood*);				    //函数声明19，食品类别查询
void FoodM_Sav(Fastfood*);				    //函数声明20，食品信息存盘

void Output_FM(Fastfood*);				    //函数声明21，输出食品信息
void Output_SM(Fastfood*);				    //函数声明22，输出销售信息


void Login_S()								    //登录系统
{
	int Num_1 = 1;								//用户输错次数计数器
	int Num_2 = 1;								//用户输错次数计数器
	char ch_1[10] = { 0 };						//存储用户输入是否进入
	char Name_1[20] = "姚源杰";					//管理员姓名
	char PassWord_1[20] = "12003990701";		//登录密码
	char Name_2[20] = { 0 };					//存储管理员输入登录姓名
	char PassWord_2[20] = { 0 };				//存储管理员输入登录密码
	Fastfood* p_head = NULL;

	while (1)									//系统安全保障，避免用户胡乱输入
	{
		system("cls");							    //再次进入界面优化处理
		printf("\n");
		printf("请问是否登录 --快餐POS机计费-- 系统：（Y or y || N or n ) -_-\n");
		scanf_s("%s", &ch_1, 10);
		rewind(stdin);							//清空缓存区，避免后续输入紊乱

		if (strcmp(ch_1, "Y") == 0 || strcmp(ch_1, "y") == 0)
		{					
			while (1)						//登录信息输入错误处理
			{
				system("cls");
				printf("\n");
				printf("请输入登录姓名：\n");
				scanf_s("%s", Name_2, 20);
				rewind(stdin);

				printf("请输入登录密码：\n");
				scanf_s("%s", PassWord_2, 20);
				rewind(stdin);

				if (strcmp(Name_1, Name_2) == 0 && strcmp(PassWord_1, PassWord_2) == 0)
				{
					system("cls");									   	//界面友好处理
					printf("\n");
					printf("                     *---------------------------------------------------------*\n");
					printf("                     *                                                         *\n");
					printf("                     *                                                         *\n");
					printf("                     *****       登录成功 欢迎进入 --计费管理系统--        *****\n");
					printf("                     *                                                         *\n");
					printf("                     *                                                         *\n");
					printf("                     *---------------------------------------------------------*\n");

					p_head = CreateLink();			//创建链表
					Sleep(2000);					//界面停顿2秒
					Mainmenu(p_head);
					system("cls");
					break;
				}
				else
				{
					if (Num_2 == 3)				//出错达到三次直接退出程序
					{
						system("cls");									
						printf("\n");
						printf("Sorry,输入错误次数已达上限(3次),请稍后重试。-_-\n");
						exit(1);
					}
					system("cls");
					printf("\n");
					printf("Sorry,输入的登录信息有误，请重新输入：-_-\n");	
					Sleep(2000);			//界面暂停2秒
					printf("\n");
					Num_2++;					//输入错误计数器加一
				}	
			}
			break;							//成功进入系统后立刻退出，避免进入死循环
		}
		else if (strcmp(ch_1, "N") == 0 || strcmp(ch_1, "n") == 0)		//直接退出程序
		{
			system("cls");
			printf("\n");
			printf("已退出 --计费管理系统-- 登录界面，欢迎下次使用。 -_-\n");
			exit(1);
		}
		else
		{
			if (Num_1 == 3)			//容错处理
			{
				system("cls");
				printf("\n");
				printf("Sorry,输入错误次数已达上限(3次),请稍后重试。 -_-\n");
				exit(1);
			}
			system("cls");
			printf("\n");
			printf("Sorry,输入错误请重新输入： -_-\n");
			Sleep(2000);					//界面停留2秒
			Num_1++;				//输入错误计数器加一
		}
	}
	return;						//函数不需返回值
}

struct Fastfood* CreateLink()				//创建链表，并让每种食品的信息存储在结点中
{
	int i=0;											//循环变量
	Fastfood* phead = NULL, *pmove = NULL, *pfresh = NULL;		//头结点、移动指针、首结点

	phead = (Fastfood* )malloc(sizeof(*phead));				//为头结点动态分配内存并判空
	if (phead == NULL)
	{
		printf("Sorry,内存分配失败，请稍后重试。-_-\n");
		exit(0);
	}
	pmove = phead;						//移动指针直接指向头结点
	pmove->next = NULL;					

	for (i = 0;i < 9;i++)				//将九种食品的信息存储在链表的每个结点
	{
		pfresh = (Fastfood*)malloc(sizeof(*pfresh));		//为新结点分配内存并判空
		if (pfresh == NULL)
		{
			printf("Sorry,内存分配失败，请稍后重试。-_-\n");
			exit(0);
		}

		//创建结点，并将每个食品的信息存储在结点中
		pfresh->F_Save = F_Class[i].F_Save;
		strcpy_s(pfresh->F_Price,10, F_Class[i].F_Price);
		strcpy_s(pfresh->F_ID,20, F_Class[i].F_ID);
		strcpy_s(pfresh->F_Name, 20, F_Class[i].F_Name);

		pmove->next = pfresh;										//创建链表三步骤
		pfresh->next = NULL;
		pmove = pfresh;

	}
	return phead;					//返回头结点以便后续操作
}

void Output_FM(Fastfood* head_C)						//输出本店的所有食品信息
{
	double Food_P = 0.0;							//食品单价
	Fastfood* pmove = NULL;										
	pmove = head_C->next;							//避免直接移动头结点，并指向数据域

	system("cls");
	printf("本店所有食品的基本信息如下所示：\n");
	while (pmove != NULL)							//遍历链表
	{
		Food_P = atof(pmove->F_Price);			//将字符串转换为浮点型便于输出
		printf("                                    食品编号：%s            \n", pmove->F_ID);
		printf("                                    食品名称：%s            \n", pmove->F_Name);
		printf("                                    食品单价：%.2lf 元       \n", Food_P);
		printf("                                    食品库存：%d 份         \n", pmove->F_Save);
		pmove = pmove->next;
		printf("\n");
	}
	printf("*---------------------------------------------------------------------------------------*\n");
	printf("\n");				//用户选择停顿时间并选择下一步的操作
	system("pause");
}

void Mainmenu(Fastfood* head)					//系统主菜单
{
	int Err_N = 1;							   //存储用户输入错误的次数
	char ch_1[10] = { 0 };					  //用于选择功能

	Fastfood* phead = NULL;						
	phead = head;									//避免直接移动头指针

	while (1)						       //容错处理，防止用户错误输入
	{
		system("cls");								//界面优化
		printf("\n");
		printf("                                             快餐POS机计费系统            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *            A.食品信息管理             *\n");
		printf("                                 *                                       *\n");
		printf("                                 *            B.食品在线销售             *\n");
		printf("                                 *                                       *\n");
		printf("                                 *            C.食品信息查看             *\n");
		printf("                                 *                                       *\n");
		printf("                                 *            D.退出计费系统             *\n");
		printf("                                 *---------------------------------------*\n");

		printf("请选择相应功能所对应的字母：\n");
		scanf_s("%s", ch_1, 10);
		rewind(stdin);

		if (strcmp(ch_1, "A") == 0)
		{
			FoodM_M(phead);		//进入食品信息管理
			break;
		}
		else if (strcmp(ch_1, "B") == 0)
		{
			FoodR_S(phead);		//进入食品在线销售
			break;
		}
		else if (strcmp(ch_1, "C") == 0)
		{
			Output_FM(phead);		//进入食品信息查看
			Mainmenu(phead);		//查看完后再进入主菜单选择其他操作
			break;
		}
		else if (strcmp(ch_1, "D") == 0)
		{
			system("cls");
			printf("\n");
			printf("已退出 --快餐POS机计费系统-- ,欢迎下次使用。-_-");
			printf("\n");
			exit(1);
		}
		else
		{
			if (Err_N == 3)
			{
				system("cls");
				printf("\n");					//输入错误次数达到3次直接退出系统
				printf("Sorry,输入错误次数已达上限（3次）,请稍后重试。-_-\n");
				Sleep(2000);			//界面停顿两秒
				Login_S();				//进入登录界面
			}
			else
			{
				system("cls");
				printf("\n");
				printf("Sorry,输入错误，请重新输入：-_-\n");
				Sleep(2000);						//界面停留2秒
				Err_N++;								//输入错误计数器加一
				
			}
		}
	}
		
	return;
}

void FoodM_M(Fastfood* head_A)							//食品信息管理
{
	int Err_N = 1;										//存储用户输入错误的次数
	char ch_2[10] = { 0 };								//用于 if 语句选择相应功能

	Fastfood* phead = NULL;								//避免直接移动头指针
	phead = head_A;

	while (1)
	{
		system("cls");										//界面优化
		printf("\n");
		printf("                                             快餐POS机计费系统            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *            A.食品类别添加             *\n");
		printf("                                 *                                       *\n");
		printf("                                 *            B.食品类别删除             *\n");
		printf("                                 *                                       *\n");
		printf("                                 *            C.食品信息修改             *\n");
		printf("                                 *                                       *\n");
		printf("                                 *            D.食品信息查询             *\n");
		printf("                                 *                                       *\n");
		printf("                                 *            E.食品信息存盘             *\n");
		printf("                                 *                                       *\n");
		printf("                                 *            F.返回系统菜单             *\n");
		printf("                                 *                                       *\n");
		printf("                                 *            G.退出计费系统             *\n");
		printf("                                 *---------------------------------------*\n");

		printf("请选择进入相应功能所对应的字母：\n");
		scanf_s("%s", ch_2, 10);
		rewind(stdin);

		if (strcmp(ch_2, "A") == 0)
		{
			FoodC_Add(phead);						//进入食品类别添加
			break;
		}
		else if (strcmp(ch_2, "B") == 0)
		{
			FoodC_Del(phead);						//进入食品类别删除
			break;
		}
		else if (strcmp(ch_2, "C") == 0)
		{
			FoodM_Mod(phead);						//进入食品信息修改
			break;
		}
		else if (strcmp(ch_2, "D") == 0)
		{
			FoodM_See(phead);						//进入食品信息查询
			break;

		}
		else if (strcmp(ch_2, "E") == 0)
		{
			FoodM_Sav(phead);						//进入食品信息存盘
			break;
		}
		else if (strcmp(ch_2, "F") == 0)
		{
			Mainmenu(phead);						//进入主菜单
			break;
		}
		else if (strcmp(ch_2, "G") == 0)			//退出系统
		{
			system("cls");
			printf("\n");
			printf("已退出 --快餐POS机计费系统-- ,欢迎下次使用。-_-\n");
			printf("\n");
			exit(1);
			break;
		}
		else
		{
			if (Err_N == 3)
			{
				system("cls");
				printf("\n");
				//输入错误达到三次后直接返回主菜单
				printf("Sorry,输入错误次数已达上限（3次），请稍后重试。-_-\n");
				Sleep(2000);				//界面停顿2秒
				Mainmenu(head_A);
			}
			else
			{
				system("cls");
				printf("\n");
				printf("Sorry,输入错误，请重新输入：-_-\n");
				Sleep(2000);			//界面停留2秒
				Err_N++;				//输入错误计数器加一
			}
		}
	}
	return;
}

void FoodC_Add(Fastfood* head_1)					//食品类别增加
{
	int Err_N = 1;							  //存储用户输入错误的次数
	char ch_3[10] = { 0 };						//用于 if 语句选择功能

	Fastfood* phead = NULL;							//避免直接移动头指针
	phead = head_1;

	while (1)
	{
		system("cls");									//界面优化
		printf("\n");
		printf("                                              快餐POS机计费系统            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                A.饮料类               *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                B.主食类               *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                C.小吃类               *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("请选择添加食品类别所对应的字母：\n");
		scanf_s("%s", ch_3,10);
		rewind(stdin);

		if (strcmp(ch_3, "A") == 0)
		{
			FoodAC_D(phead);						//进入饮料类添加；
			break;
		}
		else if (strcmp(ch_3, "B") == 0)
		{
			FoodAC_M(phead);						//进入主食类添加
			break;
		}
		else if (strcmp(ch_3, "C") == 0)
		{
			FoodAC_S(phead);						//进入小吃类添加
			break;
		}
		else
		{
			if (Err_N == 3)
			{
				//输入错误达到三次后直接返回上界面
				system("cls");
				printf("\n");
				printf("Sorry,输入错误次数已达上限（3次），请稍后重试。-_-\n");
				Sleep(2000);			//界面停顿两秒
				FoodM_M(head_1);		//进入食品信息管理
			}
			else
			{
				system("cls");
				printf("\n");
				printf("Sorry,输入错误，请重新输入：-_-\n");
				Sleep(2000);    //界面暂停2秒
				Err_N++;				//输入错误计数器加一
				
			}
		}
	}
	return;
}
void FoodAC_D(Fastfood* head_a)
{
	int i=0;									//循环变量
	int Num = 1;								//容错处理
	char Food_M[20] = { 0 };					//存储管理员查询的食品的信息
	char ch_1[10] = { 0 };						//存储管理员是否继续操作输入的字母
	//运用 Static 避免退出该函数后对某一操作的记录消失
	static unsigned int Err_1 = 0;					//存储管理员查询同一食品次数
	static char ch_b[100][50] = { 0 };				//提醒管理员重复查询

	Fastfood* pmove = NULL, * pfresh = NULL;			//避免直接移动头指针
	pmove = head_a->next;

	pfresh = (Fastfood*)malloc(sizeof(*pfresh));		//为新结点动态分配内存并判空
	if (pfresh == NULL)
	{
		printf("Sorry,内存分配失败，请稍后重试。-_-\n");
		exit(0);
	}

	while (1)			//可以提醒管理员本店没有 （TA) 输入的食品，并可以继续查询
	{
		pmove = head_a->next;			//遍历一遍后需要重新指回头结点下一个数据域
		system("cls");								    //界面优化
		printf("\n");
		printf("                                             饮料类各食品的编号            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                D1001                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                D1002                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                D1003                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("请选择在哪一编号后面添加食品信息：\n");
		scanf_s("%s", Food_M, 20);
		rewind(stdin);


		for (i = 0;i < Err_1;i++)				//提醒用户已经查询过现在输入的信息
		{
			if (strcmp(ch_b[i], Food_M) == 0)
			{
				system("cls");
				printf("\n");
				while (1)				//避免用户输入错误数字，并可重新输入
				{
					printf("提醒：该编号后面已经添加了食品信息，是否需要再次添加：（Y or y || N or n )-_-\n");
					scanf_s("%s", &ch_1, 10);
					rewind(stdin);						//清空缓存区，避免后续输入紊乱

					if (strcmp(ch_1, "Y") == 0 || strcmp(ch_1, "y") == 0)
					{
						FoodAC_D(head_a);				//进入食品类别添加
					}
					else if (strcmp(ch_1, "N") == 0 || strcmp(ch_1, "n") == 0)
					{
						FoodM_M(head_a);		//重新进入食品信息管理
					}
					else
					{
						if (Num == 3)
						{
							system("cls");
							printf("\n");
							printf("Sorry,输入错误次数已达上限(3次),请稍后重试。-_-\n");
							Sleep(2000);    //界面停顿两秒
							Mainmenu(head_a);		//错误次数达到三次后直接进入主菜单
						}
						system("cls");
						printf("\n");
						printf("Sorry,输入错误请重新输入：-_-\n");
						Sleep(2000);			//界面暂停2秒
						Num++;				//输入错误，计数器加一
					}
				}
			}
			else					//进行下一次循环，寻找是否再次查询
			{
				continue;
			}
		}

		while (pmove != NULL)				//遍历链表的每个结点
		{
			if (strcmp(Food_M, pmove->F_ID) == 0)
			{
				printf("请输入添加食品的编号：\n");
				scanf_s("%s", pfresh->F_ID, 20);
				rewind(stdin);
				//存储该编号，便于后续提醒管理员重复添加
				strcpy_s(ch_b[Err_1], 20, pmove->F_ID);

				printf("请输入添加食品的名称：\n");
				scanf_s("%s", pfresh->F_Name, 20);
				rewind(stdin);
				printf("请输入添加食品的单价：\n");
				scanf_s("%s", pfresh->F_Price,10);
				rewind(stdin);
				printf("请输入添加食品的库存：\n");
				scanf_s("%d", &pfresh->F_Save);	//浮点型需要 & 取址
				rewind(stdin);

				pfresh->next = pmove->next;		//对角线原则，后插法
				pmove->next = pfresh;

				system("cls");
				printf("\n");
				printf("Perfect，该食品添加成功。-_-\n");
				Sleep(2000);			//添加成功，界面停顿两秒
				Err_1++;				//添加成功后计数器加一
				FoodM_M(head_a);		//重新进入食品信息管理
			}
			pmove = pmove->next;
		}

		system("cls");
		printf("\n");
		printf("Sorry,本店没有食品的编号与你输入的编号匹配。-_-\n");
		Sleep(2000);
		FoodM_M(head_a);		//因为没有输入的食品所以再次食品信息管理
	}
}
void FoodAC_M(Fastfood* head_b)
{
	int i = 0;									//循环变量
	int Num = 1;								//容错处理
	char Food_M[20] = { 0 };					//存储管理员查询的食品的信息
	char ch_1[10] = { 0 };						//管理员输入
	static int Err_2 = 0;					//存储管理员查询同一食品次数
	static char ch_b[100][50] = { 0 };				 //提醒管理员重复查询

	Fastfood* pmove = NULL, * pfresh = NULL;			//避免直接移动头指针
	pmove = head_b->next;

	pfresh = (Fastfood*)malloc(sizeof(*pfresh));		//同上
	if (pfresh == NULL)
	{
		printf("Sorry,内存分配失败，请稍后重试。-_-\n");
		exit(0);
	}

	while (1)
	{
		system("cls");									//界面优化
		pmove = head_b->next;							//遍历一遍后需要重新指回头结点
		printf("\n");
		printf("                                             主食类各食品的编号            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                M1001                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                M1002                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                M1003                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("请选择在哪一编号后面添加食品信息：\n");
		scanf_s("%s", Food_M, 20);
		rewind(stdin);

		for (i = 0;i < Err_2;i++)			//同上
		{
			if (strcmp(ch_b[i], Food_M) == 0)
			{
				system("cls");
				printf("\n");
				while (1)
				{
					printf("提醒：该编号后面已经添加了食品信息，是否需要再次添加：（Y or y || N or n )-_-\n");
					scanf_s("%s", &ch_1, 10);
					rewind(stdin);						//清空缓存区，避免后续输入紊乱

					if (strcmp(ch_1,"Y") == 0 || strcmp(ch_1,"y") == 0)
					{
						FoodAC_D(head_b);					//进入食品类别添加
					}
					else if (strcmp(ch_1, "N") == 0 || strcmp(ch_1, "n") == 0)
					{
						FoodM_M(head_b);		//重新进入食品信息管理
					}
					else
					{
						if (Num == 3)
						{
							system("cls");
							printf("\n");
							printf("Sorry,输入错误次数已达上限(3次),请稍后重试。-_-\n");
							Sleep(2000);
							Mainmenu(head_b);			//输入错误超过三次重新进入主菜单
						}
						system("cls");
						printf("\n");
						printf("Sorry,输入错误请重新输入：-_-\n");
						Sleep(2000);			//界面暂停2秒
						Num++;					//同上
					}
				}
			}
			else     //同上
			{
				continue;
			}
		}

		while (pmove != NULL)   //同上
		{
			if (strcmp(Food_M, pmove->F_ID) == 0)
			{
				printf("请输入添加食品的编号：\n");
				scanf_s("%s", pfresh->F_ID, 20);
				rewind(stdin);

				//存储该编号，提醒重复添加
				strcpy_s(ch_b[Err_2], 20, pmove->F_ID);

				printf("请输入添加食品的名称：\n");
				scanf_s("%s", pfresh->F_Name, 20);
				rewind(stdin);
				printf("请输入添加食品的单价：\n");
				scanf_s("%s", pfresh->F_Price, 10);
				rewind(stdin);
				printf("请输入添加食品的库存：\n");
				scanf_s("%d", &pfresh->F_Save);
				rewind(stdin);

				pfresh->next = pmove->next;		//对角线原则，后插法
				pmove->next = pfresh;

				system("cls");
				printf("\n");
				printf("Perfect，该食品添加成功。-_-\n");
				Sleep(2000);				//同上
				Err_2++;
				FoodM_M(head_b);		//重新进入食品信息管理
			}
			pmove = pmove->next;
		}

		system("cls");
		printf("\n");
		printf("Sorry,本店没有食品的编号与你输入的编号匹配。-_-\n");
		Sleep(2000);
		FoodM_M(head_b);		//重新进入食品信息管理
	}
}
void FoodAC_S(Fastfood* head_c)
{
	int i = 0;								//循环变量
	int  Num = 1;							//容错处理
	char Food_M[20] = { 0 };							 //存储管理员查询的食品的信息
	char ch_1[2] = { 0 };							//管理员输入
	static int Err_3 = 0;				//存储管理员查询同一食品次数
	static char ch_b[100][50] = { 0 };			  //提醒管理员重复查询

	Fastfood* pmove = NULL, * pfresh = NULL;				//避免直接移动头指针
	pmove = head_c->next;

	pfresh = (Fastfood*)malloc(sizeof(*pfresh));			//同上
	if (pfresh == NULL)
	{
		printf("Sorry,内存分配失败，请稍后重试。-_-\n");
		exit(0);
	}

	while (1)
	{
		pmove = head_c->next;							//遍历一遍后需要重新指回头结点
		system("cls");									//界面优化
		printf("\n");
		printf("                                             小吃类各食品的编号            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                S1001                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                S1002                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                S1003                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("请选择在哪一编号后面添加食品信息：\n");
		scanf_s("%s", Food_M, 20);
		rewind(stdin);

		for (i = 0;i < Err_3;i++)			//同上
		{
			if (strcmp(ch_b[i], Food_M) == 0)
			{
				system("cls");
				printf("\n");
				while (1)
				{
					printf("提醒：该编号后面已经添加了食品信息，是否需要再次添加：（Y or y || N or n )-_-\n");
					scanf_s("%s", &ch_1, 10);
					rewind(stdin);						//清空缓存区，避免后续输入紊乱

					if (strcmp(ch_1, "Y") == 0 || strcmp(ch_1, "y") == 0)
					{
						FoodAC_D(head_c);					//进入食品类别添加
					}
					else if (strcmp(ch_1, "N") == 0 || strcmp(ch_1, "n") == 0)
					{
						FoodM_M(head_c);		//重新进入食品信息管理
					}
					else
					{
						if (Num == 3)		//同上
						{
							system("cls");
							printf("\n");
							printf("Sorry,输入错误次数已达上限(3次),请稍后重试。-_-\n");
							Sleep(2000);
							Mainmenu(head_c);			//重新进入主菜单
						}
						system("cls");
						printf("\n");
						printf("Sorry,输入错误请重新输入：-_-\n");
						Sleep(2000);				//界面停留2秒
						Num++;
					}
				}
			}
			else     //同上
			{
				continue;
			}
		}

		while (pmove != NULL)			//同上
		{
			if (strcmp(Food_M, pmove->F_ID) == 0)
			{
				printf("请输入添加食品的编号：\n");
				scanf_s("%s", pfresh->F_ID,20);
				rewind(stdin);

				//存储该编号，提醒重复添加
				strcpy_s(ch_b[Err_3], 20, pmove->F_ID);

				printf("请输入添加食品的名称：\n");
				scanf_s("%s", pfresh->F_Name, 20);
				rewind(stdin);
				printf("请输入添加食品的单价：\n");
				scanf_s("%s", pfresh->F_Price,10);
				rewind(stdin);
				printf("请输入添加食品的库存：\n");
				scanf_s("%d", &pfresh->F_Save);
				rewind(stdin);

				pfresh->next = pmove->next;		//对角线原则，后插法
				pmove->next = pfresh;

				system("cls");
				printf("\n");
				printf("Perfect，该食品添加成功。-_-\n");
				Sleep(2000);
				Err_3++;					//同上
				FoodM_M(head_c);		//重新进入食品信息管理
			}
			pmove = pmove->next;
		}

		system("cls");
		printf("\n");
		printf("Sorry,本店没有食品的编号与你输入的编号匹配。-_-\n");
		Sleep(2000);
		FoodM_M(head_c);		//没有该食品重新进入食品信息管理
	}
}

void FoodC_Del(Fastfood* head_2)					    	//食品信息删除
{
	int Err_N = 1;										  //存储用户输入次数
	char ch_4[10] = { 0 };									//用于 if 语句选择功能

	Fastfood* phead = NULL;										//避免直接移动头指针
	phead = head_2;

	while (1)
	{
		system("cls");												//界面优化
		printf("\n");
		printf("                                              快餐POS机计费系统            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                A.饮料类               *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                B.主食类               *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                C.小吃类               *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("请选择删除食品类别所对应的字母：\n");
		scanf_s("%s", ch_4, 10);
		rewind(stdin);

		if (strcmp(ch_4, "A") == 0)
		{
			FoodDC_D(phead);						//进入饮料类删除；
			break;
		}
		else if (strcmp(ch_4, "B") == 0)
		{
			FoodDC_M(phead);						//进入主食类删除
			break;
		}
		else if (strcmp(ch_4, "C") == 0)
		{
			FoodDC_S(phead);						//进入小吃类删除
			break;
		}
		else
		{
			if (Err_N == 3)
			{
				//输入错误次数达到3次返回上一界面
				system("cls");
				printf("\n");
				printf("Sorry,输入错误次数已达上限（3次），请稍后重试。-_-\n");
				Sleep(2000);			//停顿两秒
				FoodM_M(head_2);				//重新进入信息管理界面
			}
			else
			{
				system("cls");
				printf("\n");
				printf("Sorry,输入错误，请重新输入：-_-\n");
				Sleep(2000);			//界面停留2秒
				Err_N++;			//输入错误计数器加一
			}
		}
	}
	return;
}
void FoodDC_D(Fastfood* head_d)
{
	int i = 0;											//循环变量
	char Food_M[20] = { 0 };										 //存储管理员删除的食品的信息
	//运用 Static 避免退出该函数后对某一操作的记录消失
	static int Err_4 = 0;							//存储管理员删除同一食品次数
	static char ch_b[100][50] = { 0 };						 //提醒管理员重复删除

	Fastfood* pmove = NULL, * psave = NULL;					//避免直接移动头指针
	pmove = head_d;

	while (1)
	{
		system("cls");											//界面优化
		printf("\n");
		printf("                                             饮料类各食品的编号            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                D1001                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                D1002                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                D1003                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("请输入删除食品的编号：\n");
		scanf_s("%s", Food_M, 20);
		rewind(stdin);

		for (i = 0;i < Err_4;i++)			//遍历数组寻找该输入的是否已经删除过
		{
			if (strcmp(ch_b[i], Food_M) == 0)
			{
				system("cls");
				printf("\n");
				printf("提醒：已删除过此食品，无需重复删除。-_-\n");
				Sleep(2000);				//界面停顿2秒
				FoodM_M(head_d);		//重新进入食品信息管理		
			}
			else
			{
				continue;
			}
		}

		pmove = head_d;							//遍历一遍后需要重新指回头结点
		while (pmove->next != NULL)
		{
			if (strcmp(Food_M, pmove->next->F_ID) == 0)
			{
				//将修改的编号存储起来，便于提醒重复修改
				strcpy_s(ch_b[Err_4], 20, pmove->next->F_ID);

				psave = pmove->next;
				pmove->next = pmove->next->next;		//删除节点的关键
				free(psave);				//将删除的节点的动态空间内存释放掉并指向 NULL
				psave = NULL;

				system("cls");
				printf("\n");
				printf("Perfect，编号 -%s- 所对应的信息删除成功。-_-\n", Food_M);
				Sleep(2000);
				Err_4++;			  //添加完成后技术器加一
				FoodM_M(head_d);		//删除成功后重新进入食品信息管理
			}
			pmove = pmove->next;
		}
		system("cls");
		printf("\n");
		printf("Sorry,本店没有食品的编号与你输入的编号匹配。-_-\n");
		Sleep(2000);				//界面停顿2秒
		FoodM_M(head_d);		//没有该食品重新进入食品信息管理
	}
}
void FoodDC_M(Fastfood* head_e)
{
	int i =0 ;											  //循环变量
	char Food_M[20] = { 0 };							 //存储管理员删除的食品的信息
	//运用 Static 避免退出该函数后对某一操作的记录消失
	static int Err_5 = 0;										  //存储管理员删除同一食品次数
	static char ch_b[100][50] = { 0 };						  //提醒管理员重复删除

	Fastfood* pmove = NULL, * psave = NULL;					//避免直接移动头指针
	pmove = head_e->next;

	while (1)
	{
		system("cls");											//界面优化
		printf("\n");
		printf("                                             主食类各食品的编号            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                M1001                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                M1002                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                M1003                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("请输入删除食品的编号：\n");
		scanf_s("%s", Food_M,20);
		rewind(stdin);

		for (i = 0;i < Err_5;i++)			//同上
		{
			if (strcmp(ch_b[i], Food_M) == 0)
			{
				system("cls");
				printf("\n");
				printf("提醒：已删除过此食品，无需重复删除。-_-\n");
				printf("\n");
				Sleep(2000);
				FoodM_M(head_e);		//重新进入食品信息管理				
			}
			else				//同上
			{
				continue;
			}
		}

		pmove = head_e;							//遍历一遍后需要重新指回头结点
		while (pmove->next != NULL)
		{
			if (strcmp(Food_M, pmove->next->F_ID) == 0)
			{
				//将修改的编号存储起来，便于提醒重复修改
				strcpy_s(ch_b[Err_5], 20, pmove->next->F_ID);

				psave = pmove->next;
				pmove->next = pmove->next->next;		//删除节点的关键
				free(psave);				//将删除的节点的动态空间内存释放掉并指向 NULL
				psave = NULL;

				system("cls");
				printf("\n");
				printf("Perfect，编号 -%s- 所对应的信息删除成功。-_-\n", Food_M);
				Sleep(2000);
				Err_5++;					//同上
				FoodM_M(head_e);		//删除成功后进入食品信息管理
			}
			pmove = pmove->next;
		}
		system("cls");
		printf("\n");
		printf("Sorry,本店没有食品的编号与你输入的编号匹配。-_-\n");
		Sleep(2000);
		FoodM_M(head_e);			//同上
	}
}
void FoodDC_S(Fastfood* head_f)
{
	int i = 0;													//循环变量
	char Food_M[20] = { 0 };									 //存储管理员删除的食品的信息
	//运用 Static 避免退出该函数后对某一操作的记录消失
	static int Err_6 = 0;										 //存储管理员删除同一食品次数
	static char ch_b[100][50] = { 0 };						  //提醒管理员重复删除

	Fastfood* pmove = NULL, * psave = NULL;									//避免直接移动头指针
	pmove = head_f->next;

	while (1)
	{
		system("cls");											//界面优化
		printf("\n");
		printf("                                             小吃类各食品的编号            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                S1001                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                S1002                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                S1003                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("请输入删除食品的编号：\n");
		scanf_s("%s", Food_M,20);
		rewind(stdin);

		for (i = 0;i < Err_6;i++)				//同上
		{
			if (strcmp(ch_b[i], Food_M) == 0)
			{
				system("cls");
				printf("\n");
				printf("提醒：已删除过此食品，无需重复删除。-_-\n");
				Sleep(2000);			//同上
				FoodM_M(head_f);				//重新进入食品信息管理
			}
			else				//同上
			{
				continue;
			}
		}

		pmove = head_f->next;							//遍历一遍后需要重新指回头结点
		while (pmove->next!= NULL)
		{
			if (strcmp(Food_M, pmove->next->F_ID) == 0)
			{
				//将修改的编号存储起来，便于提醒重复修改
				strcpy_s(ch_b[Err_6], 20, pmove->next->F_ID);

				psave = pmove->next;
				pmove->next = pmove->next->next;		//删除节点的关键
				free(psave);					//将删除的节点的动态空间内存释放掉并指向 NULL
				psave = NULL;

				system("cls");
				printf("\n");
				printf("Perfect，编号 -%s- 所对应的信息删除成功。-_-\n", Food_M);
				Sleep(2000);			//同上
				Err_6++;
				FoodM_M(head_f);				//删除成功后重新进入食品信息管理				
			}
			pmove = pmove->next;
		}
		system("cls");
		printf("\n");
		printf("Sorry,本店没有食品的编号与你输入的编号匹配。-_-\n");
		Sleep(2000);			//同上
		FoodM_M(head_f);		//没有该食品重新进入食品信息管理	
	}
}

void FoodM_Mod(Fastfood* head_3)			  //食品信息修改
{
	int Err_N = 1;					          //存储用户输入次数
	char ch_5[10] = { 0 };									//用于 if 语句选择功能

	Fastfood* phead = NULL;						//避免直接移动头指针
	phead = head_3;

	while (1)
	{
		system("cls");											//界面优化
		printf("\n");
		printf("                                             快餐POS机计费系统            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *               A.饮料类                *\n");
		printf("                                 *                                       *\n");
		printf("                                 *               B.主食类                *\n");
		printf("                                 *                                       *\n");
		printf("                                 *               C.小吃类                *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("请输入修改食品类别所对应的字母：\n");
		scanf_s("%s", ch_5,10);
		rewind(stdin);

		if (strcmp(ch_5, "A") == 0)
		{
			FoodMC_D(phead);						//进入饮料类修改
			break;
		}
		else if (strcmp(ch_5, "B") == 0)
		{
			FoodMC_M(phead);						//进入主食类修改
			break;
		}
		else if (strcmp(ch_5, "C") == 0)
		{
			FoodMC_S(phead);						//进入小吃类修改
			break;
		}
		else
		{
			if (Err_N == 3)
			{
				//输入错误次数达到3次后返回上一界面
				system("cls");
				printf("\n");
				printf("Sorry,输入错误次数已达上限（3次），请稍后重试。-_-\n");
				Sleep(2000);		//输入错误界面停顿两秒
				FoodM_M(head_3);				//重新进入食品信息管理
			}
			else
			{
				system("cls");
				printf("\n");
				printf("Sorry,输入错误，请重新输入：-_-\n");
				Sleep(2000);				//界面停留2秒
				Err_N++;			//同上
			}
		}
	}
	return;
}
void FoodMC_D(Fastfood* head_g)
{
	int i = 0;										//循环变量
	char Food_M[20] = { 0 };					    //存储管理员修改的食品的信息
	//运用 Static 避免退出该函数后对某一操作的记录消失
	static int Err_7 = 0;							 //存储管理员修改同一食品次数
	static char ch_b[100][50] = { 0 };				//提醒管理员重复修改

	Fastfood* pmove = NULL;							//避免直接移动头指针
	pmove = head_g->next;

	while (1)
	{
		system("cls");									//界面优化
		printf("\n");
		printf("                                             饮料类各食品的编号            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                 D1001                 *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                 D1002                 *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                 D1003                 *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("请输入修改食品的编号：\n");
		scanf_s("%s", Food_M,20);
		rewind(stdin);

		for (i = 0;i < Err_7;i++)				//同上
		{
			if (strcmp(ch_b[i], Food_M) == 0)
			{
				system("cls");
				printf("\n");
				printf("提醒：已修改过此食品，无需重复修改。-_-\n");
				Sleep(2000);			//界面停顿两秒
				system("cls");
				FoodM_M(head_g);			//重新进入食品信息管理
			}
			else
			{
				continue;
			}
		}

		pmove = head_g;							//遍历一遍后需要重新指回头结点
		while (pmove->next != NULL)
		{
			if (strcmp(Food_M, pmove->F_ID) == 0)
			{
				//将修改的编号存储起来，便于提醒重复修改
				strcpy_s(ch_b[Err_7], 20, pmove->F_ID);
				printf("请输入该食品修改后的编号：\n");
				scanf_s("%s", pmove->F_ID, 20);
				rewind(stdin);
				printf("请输入该食品修改后的名称：\n");
				scanf_s("%s", pmove->F_Name, 20);
				rewind(stdin);
				printf("请输入该食品修改后的单价：\n");
				scanf_s("%s", pmove->F_Price,10);
				rewind(stdin);
				printf("请输入该食品修改后的库存：\n");
				scanf_s("%d", &pmove->F_Save);
				rewind(stdin);

				system("cls");
				printf("\n");
				printf("Perfect，编号 -%s- 所对应的食品信息修改成功。-_-\n", Food_M);
				Sleep(2000);
				Err_7++;			//同上
				FoodM_M(head_g);				//修改成功后重新进入食品信息管理	
			}
			pmove = pmove->next;
		}
		system("cls");
		printf("\n");
		printf("Sorry,本店没有食品的编号与你输入的编号匹配。-_-\n");
		Sleep(2000);
		FoodM_M(head_g);				//没有该食品重新进入食品信息管理	
	}
}
void FoodMC_M(Fastfood *head_h)
{
	int i = 0;											 //循环变量
	char Food_M[20] = { 0 };							 //存储管理员修改的食品的信息
	//运用 Static 避免退出该函数后对某一操作的记录消失
	static int Err_8 = 0;							 //存储管理员修改同一食品次数
	static char ch_b[100][50] = { 0 };				 //提醒管理员重复修改

	Fastfood* pmove = NULL;									//避免直接移动头指针
	pmove = head_h->next;

	while (1)
	{
		system("cls");									//界面优化
		printf("\n");
		printf("                                             主食类各食品的编号            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                 M1001                 *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                 M1002                 *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                 M1003                 *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("请输入修改食品的编号：\n");
		scanf_s("%s", Food_M, 20);
		rewind(stdin);

		for (i = 0;i < Err_8;i++)
		{
			if (strcmp(ch_b[i], Food_M) == 0)
			{
				system("cls");
				printf("\n");
				printf("提醒：已修改过此食品，无需重复修改。-_-\n");
				Sleep(2000);
				system("cls");
				FoodM_M(head_h);				//重新进入食品信息管理	
			}
			else
			{
				continue;
			}
		}

		//程序BUG 不能修改最后一个结点
		pmove = head_h;							//遍历一遍后需要重新指回头结点
		while (pmove->next != NULL)
		{
			if (strcmp(Food_M, pmove->F_ID) == 0)
			{
				//将修改的编号存储起来，便于提醒重复修改
				strcpy_s(ch_b[Err_8],20, pmove->F_ID);
				printf("请输入该食品修改后的编号：\n");
				scanf_s("%s", pmove->F_ID, 20);
				rewind(stdin);
				printf("请输入该食品修改后的名称：\n");
				scanf_s("%s", pmove->F_Name, 20);
				rewind(stdin);
				printf("请输入该食品修改后的单价：\n");
				scanf_s("%s", pmove->F_Price, 10);
				rewind(stdin);
				printf("请输入该食品修改后的库存：\n");
				scanf_s("%d", &pmove->F_Save);
				rewind(stdin);

				system("cls");
				printf("\n");
				printf("Perfect，编号 -%s- 所对应的食品信息修改成功。-_-\n", Food_M);
				Sleep(2000);			//同上
				Err_8++;
				FoodM_M(head_h);				//修改成功后重新进入食品信息管理	
			}
			pmove = pmove->next;
		}
		system("cls");
		printf("\n");
		printf("Sorry,本店没有食品的编号与你输入的编号匹配。-_-\n");
		Sleep(2000);
		FoodM_M(head_h);				//修改成功后重新进入食品信息管理	
	}
}
void FoodMC_S(Fastfood *head_i)
{
	int i = 0;											  //循环变量
	char Food_M[20] = { 0 };							  //存储管理员修改的食品的信息
	//运用 Static 避免退出该函数后对某一操作的记录消失
	static int Err_9 = 0;							  //存储管理员修改同一食品次数
	static char ch_b[100][50] = { 0 };				 //提醒管理员重复修改

	Fastfood* pmove = NULL;								//避免直接移动头指针
	pmove = head_i->next;

	while (1)
	{
		system("cls");									//界面优化
		printf("\n");
		printf("                                             小吃类各食品的编号            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                 S1001                 *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                 S1002                 *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                 S1003                 *\n");
		printf("                                 *---------------------------------------*\n");
		printf("请输入修改食品的编号：\n");
		scanf_s("%s", Food_M, 20);
		rewind(stdin);

		for (i = 0;i < Err_9;i++)			//同上
		{
			if (strcmp(ch_b[i], Food_M) == 0)
			{
				system("cls");
				printf("\n");
				printf("提醒：已修改过此食品，无需重复修改。-_-\n");
				Sleep(2000);
				system("cls");
				FoodM_M(head_i);				//修改成功后重新进入食品信息管理	
			}
			else
			{
				continue;
			}
		}

		//程序BUG 不能修改最后一个结点
		pmove = head_i;							//遍历一遍后需要重新指回头结点
		while (pmove!= NULL)
		{
			if (strcmp(Food_M, pmove->F_ID) == 0)
			{
				//将修改的编号存储起来，便于提醒重复修改
				strcpy_s(ch_b[Err_9], 11, pmove->F_ID);
				printf("请输入该食品修改后的编号：\n");
				scanf_s("%s", pmove->F_ID, 20);
				rewind(stdin);
				printf("请输入该食品修改后的名称：\n");
				scanf_s("%s", pmove->F_Name, 20);
				rewind(stdin);
				printf("请输入该食品修改后的单价：\n");
				scanf_s("%s", pmove->F_Price,10);
				rewind(stdin);
				printf("请输入该食品修改后的库存：\n");
				scanf_s("%d", &pmove->F_Save);
				rewind(stdin);

				system("cls");
				printf("\n");
				printf("Perfect，编号 -%s- 所对应的食品信息修改成功。-_-\n", Food_M);
				Sleep(2000);			//同上
				Err_9++;
				FoodM_M(head_i);				//修改成功后重新进入食品信息管理	
			}
			pmove = pmove->next;
		}
		system("cls");
		printf("\n");
		printf("Sorry,本店没有食品的编号与你输入的编号匹配。-_-\n");
		Sleep(2000);
		FoodM_M(head_i);				//无该食品重新进入食品信息管理	
	}
}

void FoodM_See(Fastfood* head_4)					 //食品信息查看
{
	int i = 0;										//循环变量
	int Num = 1;									//容错处理
	double  Food_P= 0.0;						   //食品单价
	char Food_M[20] = { 0 };					   //存储管理员查询的食品的信息
	char ch_1[10] = { 0 };						   //管理员输入
	//运用 Static 避免退出该函数后对某一操作的记录消失
	static int Err_10 = 0;						  //存储管理员查询同一食品次数
	static char ch_b[100][50] = { 0 };			   //提醒管理员重复查询
												
	Fastfood* pmove = NULL;						 //避免直接移动头指针
	pmove = head_4->next;

	while (1)
	{
		system("cls");									//界面优化
		printf("\n");
		printf("                                             各类食品的基本信息            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                食品单价               *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                食品编号               *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                食品名称               *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("提示：\n");
		printf("      样例输入：（D1001）或（百事可乐）或（5.00）\n");
		printf("\n");
		printf("请输入查询食品的具体信息：\n");
		scanf_s("%s", Food_M, 20);
		rewind(stdin);

		//满足能够对食品进行多种查询,并对管理员提醒重复查询
		for (i = 0;i < Err_10;i++)
		{
			if (strcmp(ch_b[i], Food_M) == 0)
			{
				system("cls");
				printf("\n");

				while (1)
				{
					printf("提醒：已重复查询过此食品，是否仍需查询：（Y or y || N or n )-_-\n");
					scanf_s("%s", ch_1, 10);
					rewind(stdin);						//清空缓存区，避免后续输入紊乱

					//重复查询操作
					if (strcmp(ch_1, "Y") == 0 || strcmp(ch_1, "y") == 0)
					{
						pmove = head_4->next;
						while (pmove->next != NULL)
						{
							if (strcmp(Food_M, pmove->F_ID) == 0)
							{
								system("cls");
								Food_P = atof(pmove->F_Price);
								printf("\n");
								printf("编号 --%s-- 所对应食品的详细信息如下：-_-\n", pmove->F_ID);
								printf("\n");
								printf("食品编号：%s \n", pmove->F_ID);
								printf("食品名称：%s\n", pmove->F_Name);
								printf("食品单价：%.2lf 元\n", Food_P);
								printf("食品库存：%d 份\n", pmove->F_Save);
								break;
							}
							pmove = pmove->next;
						}
						printf("\n");
						system("pause");				//管理员选择停顿时间
						FoodM_M(head_4);				//重新进入食品信息管理
					}
					else if (strcmp(ch_1, "N") == 0 || strcmp(ch_1, "n") == 0)
					{
						FoodM_M(head_4);					//重新进入食品信息管理
					}
					else
					{
						if (Num == 3)
						{
							system("cls");
							printf("\n");
							printf("Sorry,输入错误次数已达上限(3次),请稍后重试。-_-\n");
							Sleep(2000);
							Mainmenu(head_4);			//输入错误达到3次后直接进入主菜单
						}
						system("cls");
						printf("\n");
						printf("Sorry,输入错误请重新输入：-_-\n");
						Sleep(2000);				//界面停留2秒
						Num++;			//同上
					}
				}
			}
			else					//同上
			{
				continue;
			}
		}

		while (pmove != NULL)				//以至于可以查询最后结点信息
		{
			if (strcmp(Food_M, pmove->F_ID) == 0)
			{
				strcpy_s(ch_b[Err_10], 20, pmove->F_ID);
				system("cls");

				Food_P = atof(pmove->F_Price);					//字符串型转浮点型
				printf("\n");
				printf("编号 --%s-- 所对应食品的详细信息如下：-_-\n", pmove->F_ID);
				printf("\n");
				printf("食品编号：%s \n", pmove->F_ID);
				printf("食品名称：%s\n", pmove->F_Name);
				printf("食品单价：%.2lf 元\n", Food_P);
				printf("食品库存：%d 份\n", pmove->F_Save);
				printf("\n");
				system("pause");			//管理员选择停留时间
				Err_10++;
				FoodM_M(head_4);					//重新进入食品信息管理
			}
			else if (strcmp(Food_M, pmove->F_Name) == 0)
			{
				strcpy_s(ch_b[Err_10], 20, pmove->F_Name);
				system("cls");

				Food_P = atof(pmove->F_Price);			//字符串型转浮点型
				printf("\n");
				printf("名称 --%s-- 所对应食品的详细信息如下：-_-\n",pmove->F_Name);
				printf("\n");
				printf("食品编号：%s \n", pmove->F_ID);
				printf("食品名称：%s\n", pmove->F_Name);
				printf("食品单价：%.2lf 元\n", Food_P);
				printf("食品库存：%d 份\n", pmove->F_Save);
				printf("\n");
				system("pause");				//管理员选择停留时间
				Err_10++;

				FoodM_M(head_4);					//重新进入食品信息管理
			}
			else if (strcmp(Food_M, pmove->F_Price) == 0)
			{
				strcpy_s(ch_b[Err_10],10, pmove->F_Price);
				system("cls");

				Food_P = atof(pmove->F_Price);
				printf("\n");
				printf("单价 --%.2f-- 元所对应食品的详细信息如下：-_-\n", Food_P);
				printf("\n");
				printf("食品编号：%s \n", pmove->F_ID);
				printf("食品名称：%s\n", pmove->F_Name);
				printf("食品单价：%.2lf 元\n", Food_P);
				printf("食品库存：%d 份\n", pmove->F_Save);
				printf("\n");
				system("pause");				//管理员选择停留时间
				Err_10++;
				FoodM_M(head_4);					//重新进入食品信息管理
			}
			pmove = pmove->next;
		}
		
		system("cls");
		printf("\n");
		printf("Sorry,本店没有你要查询的食品。-_-\n");
		Sleep(2000);			//同上
		FoodM_M(head_4);	   //没有该食品重新进入食品信息管理
	}
}	

void FoodM_Sav(Fastfood* head_5)			 //食品信息存盘
{
	double  P = 0.0;						//存储字符串转换浮点型
	FILE* pfile = NULL;
	Fastfood* phead = NULL;
	phead = head_5->next;					//避免直接移动头结点

	//开始打开文件并存入数据
	if (fopen_s(&pfile, "Fastfood_M.txt", "w+") != NULL)       //正确打开返回0，否则返回非零
	{
		printf("文件打开失败，已退出程序！");
		exit(1);
	}

	while (pfile != NULL)
	{
		fprintf(pfile, "本店所有食品的基本信息如下所示：\n");
		fprintf(pfile, "\n");                                    //层次感
		while (phead != NULL)
		{
			P = atof(phead->F_Price);								//将字符串转换为浮点型
			fprintf(pfile, "                                    食品编号：%s            \n", phead->F_ID);
			fprintf(pfile, "                                    食品名称：%s            \n", phead->F_Name);
			fprintf(pfile, "                                    食品单价：%.2lf 元       \n", P);
			fprintf(pfile, "                                    食品库存：%d 份         \n", phead->F_Save);
			phead = phead->next;
			fprintf(pfile, "\n");
		}
		break;			//退出循环，避免进入死循环
	}
	//打开后一定得及时关闭文件，避免丢失数据
	while (pfile != NULL)
	{
		rewind(pfile);                               //使文件指针指向文件开头
		fclose(pfile);
		break;
	}

	system("cls");
	printf("\n");
	printf("Perfect,本店所有食品的详细信息已经存入文件 Fastfood_M ！请注意查看。-_-\n");
	Sleep(2000);				//停顿2秒
	FoodM_M(head_5);			//返回食品信息管理
}

void FoodR_S(Fastfood* head_B)					//食品在线销售
{
	int i = 0;									//循环变量
	int Num = 0;								//便于计算顾客购买的份数
	//int Err = 0;							    //容错处理
	int Err_N = 1;								//容错次数

	int FoodB_C[10] = { 0 }; 					//购买食品份数
	double  Cash_C = 0.0;						//顾客所给现金
	double  Cash_R = 0.0;						//顾客现金找零
	double  Food_P[9] = { 0.0 };				//食品零售价
	double  FoodP_S = 0.0;						//顾客一次购买食品的价格总计

	char ch_1[10] = { 0 };						//顾客输入容错处理
	char FoodB_M[20] = { 0 };					//所购食品的信息（名称、编号）
	char FoodB_N[100][20] = { 0 };			    //所购食品的名称

	//运用 Static 避免退出该函数后对某一操作的记录消失
	static  int Buy_N = 0;						 //存储购买序号
	static  int Food_R[9] = { 0 };				 //各食品的销量
	static double  FoodM_SR[9] = { 0 };			 //各食品销售总金额
	static  int FoodC_SR[3] = { 0 };			 //三大类食品总销量
	static double  FoodCM_SR[3] = { 0 };		 //三大类食品销售总金额

	int year = 0, mon = 0, day = 0,hour=0,min=0,sec=0;		//输出购买的时间
	time_t  timep = time(0);
	struct tm p;
	time(&timep);
	localtime_s(&p, &timep);
	year= 1900 + p.tm_year;
	mon = 1 + p.tm_mon;
	day = p.tm_mday;
	hour = p.tm_hour;
	min = p.tm_min;
	sec = p.tm_mday;

	//避免用链表遍历，增加代码量
	int FoodS_N[9] = { 200,150,200,300,350,400,250,200,200 };				//存储每个食品的库存
	double  Fastfood_[9][7] = { 5.00,6.00,7.00,10.00,15.00,8.00,5.00,4.00,7.00 };
	char Fastfood_C[18][20] = { "百事可乐","D1001","鲜榨橙汁","D1002","牛奶奶茶","D1003",
							"兰州拉面","M1001","咖喱盖饭","M1002","扬州炒饭","M1003",
							"煎饼果子","S1001","香甜糍粑","S1002","灯影牛肉","S1003" };
	Fastfood* pmove = NULL;
	pmove = head_B->next;							     	//避免直接移动头结点

	while (1)
	{
		system("cls");
		pmove = head_B->next;								//遍历一遍后需要重新指回头结点
		printf("提示：\n如果顾客不再选购，输入字母 R 或 r 退出选食品界面，进入下步操作。 -_-\n");
		printf("\n");
		printf("                                               本店食品清单如下所示         \n");
		printf("                                 ---------------------------------------------\n");
		printf("                                 *    D1001	    M1001          S1001     *\n");
		printf("                                 *    百事可乐      兰州拉面       煎饼果子  *\n");
		printf("                                 *-------------------------------------------*\n");
		printf("                                 *    D1002         M1002          S1002     *\n");
		printf("                                 *    鲜榨橙汁      咖喱盖饭	   香甜糍粑  *\n");
		printf("                                 *-------------------------------------------*\n");
		printf("                                 *    D1003         M1003          S1003     *\n");
		printf("                                 *    牛奶奶茶      扬州炒饭       灯影牛肉  *\n");
		printf("                                 *-------------------------------------------*\n");

		printf("\n");
		printf("请输入顾客购买食品所对应的编号或名称：\n");
		scanf_s("%s", FoodB_M, 20);
		rewind(stdin);

		if (strcmp(FoodB_M, "R") == 0 || strcmp(FoodB_M, "r") == 0)
		{
			if (Num == 0)
			{
				Mainmenu(head_B);				//意味着顾客不会购买食品
			}
			else
			{
				break;
			}
		}

		for (i = 0;i < 18;i++)							//检查本店是否有该食品
		{
			if (strcmp(FoodB_M, Fastfood_C[i]) != 0)
			{
				continue;
			}
			else
			{
				strcpy_s(FoodB_N[Num], 20, FoodB_M);

				Num++;												//有食品计数器加一
				break;
			}
		}

		if (i == 18)				//当 i 为18时说明没有输入的食品
		{
			system("cls");
			printf("\n");
			printf("Sorry,本店没有你所选的食品，请重新选择。-_-\n");
			Sleep(2000);			//停顿两秒
			continue;
		}

		else				//否则说明有该食品
		{
			system("cls");
			printf("\n");
			printf("请输入顾客购买食品 %s 的份数：\n", FoodB_M);
			scanf_s("%d", &FoodB_C[Num - 1]);
			rewind(stdin);
			/*do				//防止用户输入错误的数字
			{
				system("cls");
				printf("\n");
				printf("请输入顾客购买食品 %s 的份数：\n", FoodB_M);
				scanf_s("%d", &FoodB_C[Num - 1]);	//实际是购买的第一个食品，所以数组用 Num-1
				Err = getchar();               //用作判断输入是否是数字,如果不是继续输入
				while (getchar() != '\n');	//	吸收回车所以需要按两次回车才会录入成功
				if (Err != 10)				//说明输入的是数字加字母
				{
					system("cls");
					printf("\n");
					printf("Sorry,购买份数不合理，请重新输入！-_-\n");
					Sleep(2000);
				}
			} while (Err != 10);*/
			for (i = 0;i < 9;i++)			//判断顾客购买的食品是否库存不足
			{
				if (FoodB_C[Num - 1] > FoodS_N[i] - Food_R[i])//总份减去销量
				{
					system("cls");
					printf("\n");
					printf("Sorry,该食品库存不足，请购买其他食品。-_- \n");
					Sleep(2000);				//界面停留2秒
					FoodR_S(head_B);		    //重新进入选食品界面
				}
				else
				{
					continue;
				}
			}

			if (FoodB_C[Num-1] > 50 || FoodB_C[Num-1] < 1)		//暂且设置一个顾客最多购买50份
			{
				system("cls");
				printf("\n");
				printf("Sorry,购买份数不合理，请重新输入！-_-\n");
				Sleep(1000);				//购买阶段只停留1秒
				FoodR_S(head_B);		    //重新进入选食品界面
			}
			
			else
			{
				system("cls");
				printf("\n");
				printf("Perfect,顾客购买食品的信息录入成功……\n");
				Sleep(1500);						//界面停顿1.5秒
			}
		}
	}
	//顾客账单明细输出处理
	for (i = 0;i < Num;i++)
	{
		if (strcmp(FoodB_N[i], Fastfood_C[0]) == 0||strcmp(FoodB_N[i], Fastfood_C[1]) == 0)
		{
			//用于销售阶段
			strcpy_s(FoodB_N[i], 20,"百事可乐");
			Food_P[i] = 5.00;
			FoodP_S = FoodP_S + 5.00 * FoodB_C[i];
			//用于统计阶段
			//Food_R[0]+= FoodB_C[i];						//不够明了
			Food_R[0]= Food_R[0]+ FoodB_C[i];				//销量加一
			FoodC_SR[0]= FoodC_SR[0]+ FoodB_C[i];
			FoodM_SR[0] = FoodM_SR[0] + 5.00 * FoodB_C[i];				//销售金额加和
			FoodCM_SR[0] = FoodCM_SR[0] + 5.00 * FoodB_C[i];
		}
		else if (strcmp(FoodB_N[i], Fastfood_C[2]) == 0 || strcmp(FoodB_N[i], Fastfood_C[3]) == 0)
		{
			strcpy_s(FoodB_N[i],20,"鲜榨橙汁");
			Food_P[i] = 6.00;
			FoodP_S = FoodP_S + 6.00 * FoodB_C[i];
			//用于统计阶段
			Food_R[1] = Food_R[1] + FoodB_C[i];				//销量加一
			FoodC_SR[0] = FoodC_SR[0] + FoodB_C[i];
			FoodM_SR[1] = FoodM_SR[1] + 6.00 * FoodB_C[i];				//销售金额加和
			FoodCM_SR[0] = FoodCM_SR[0] + 6.00 * FoodB_C[i];
		}
		else if (strcmp(FoodB_N[i], Fastfood_C[4]) == 0 || strcmp(FoodB_N[i], Fastfood_C[5]) == 0)
		{
			strcpy_s(FoodB_N[i],20, "牛奶奶茶");
			Food_P[i] = 7.00;
			FoodP_S = FoodP_S + 7.00 * FoodB_C[i];
			//用于统计阶段
			Food_R[2] = Food_R[2] + FoodB_C[i];				//销量加一
			FoodC_SR[0] = FoodC_SR[0] + FoodB_C[i];
			FoodM_SR[2] = FoodM_SR[2] + 7.00 * FoodB_C[i];				//销售金额加和
			FoodCM_SR[0] = FoodCM_SR[0] + 7.00 * FoodB_C[i];
		}
		else if (strcmp(FoodB_N[i], Fastfood_C[6]) == 0 || strcmp(FoodB_N[i], Fastfood_C[7]) == 0)
		{
			strcpy_s(FoodB_N[i],20, "兰州拉面");
			Food_P[i] = 10.00;
			FoodP_S = FoodP_S + 10.00 * FoodB_C[i];
			//用于统计阶段
			Food_R[3] = Food_R[3] + FoodB_C[i];				//销量加一
			FoodC_SR[1] = FoodC_SR[1] + FoodB_C[i];
			FoodM_SR[3] = FoodM_SR[3] + 10.00 * FoodB_C[i];				//销售金额加和
			FoodCM_SR[1] = FoodCM_SR[1] + 10.00 * FoodB_C[i];
		}
		else if (strcmp(FoodB_N[i], Fastfood_C[8]) == 0 || strcmp(FoodB_N[i], Fastfood_C[9]) == 0)
		{
			strcpy_s(FoodB_N[i],20, "咖喱盖饭");
			Food_P[i] = 15.00;
			FoodP_S = FoodP_S + 15.00 * FoodB_C[i];
			//用于统计阶段
			Food_R[4] = Food_R[4] + FoodB_C[i];				//销量加一
			FoodC_SR[1] = FoodC_SR[1] + FoodB_C[i];
			FoodM_SR[4] = FoodM_SR[4] + 15.00 * FoodB_C[i];				//销售金额加和
			FoodCM_SR[1] = FoodCM_SR[1] + 15.00 * FoodB_C[i];
		}
		else if (strcmp(FoodB_N[i], Fastfood_C[10]) == 0 || strcmp(FoodB_N[i], Fastfood_C[11]) == 0)
		{
			strcpy_s(FoodB_N[i],20, "扬州炒饭");
			Food_P[i] = 8.00;
			FoodP_S = FoodP_S + 8.00 * FoodB_C[i];
			//用于统计阶段
			Food_R[5] = Food_R[5] + FoodB_C[i];				//销量加一
			FoodC_SR[1] = FoodC_SR[1] + FoodB_C[i];
			FoodM_SR[5] = FoodM_SR[5] + 8.00 * FoodB_C[i];				//销售金额加和
			FoodCM_SR[1] = FoodCM_SR[1] + 8.00 * FoodB_C[i];
		}
		else if (strcmp(FoodB_N[i], Fastfood_C[12]) == 0 || strcmp(FoodB_N[i], Fastfood_C[13]) == 0)
		{
			strcpy_s(FoodB_N[i],20, "煎饼果子");
			Food_P[i] = 5.00;
			FoodP_S = FoodP_S + 5.00 * FoodB_C[i];
			//用于统计阶段
			Food_R[6] = Food_R[6] + FoodB_C[i];				//销量加一
			FoodC_SR[2] = FoodC_SR[2] + FoodB_C[i];
			FoodM_SR[6] = FoodM_SR[6] + 5.00 * FoodB_C[i];				//销售金额加和
			FoodCM_SR[2] = FoodCM_SR[2] + 5.00 * FoodB_C[i];
		}
		else if (strcmp(FoodB_N[i], Fastfood_C[14]) == 0 || strcmp(FoodB_N[i], Fastfood_C[15]) == 0)
		{
			strcpy_s(FoodB_N[i],20, "香甜糍粑");
			Food_P[i] = 4.00;
			FoodP_S = FoodP_S + 4.00 * FoodB_C[i];
			//用于统计阶段
			Food_R[7] = Food_R[7] + FoodB_C[i];				//销量加一
			FoodC_SR[2] = FoodC_SR[2] + FoodB_C[i];
			FoodM_SR[7] = FoodM_SR[7] + 4.00 * FoodB_C[i];				//销售金额加和
			FoodCM_SR[2] = FoodCM_SR[2] + 4.00 * FoodB_C[i];
		}
		else if (strcmp(FoodB_N[i], Fastfood_C[16]) == 0 || strcmp(FoodB_N[i], Fastfood_C[17]) == 0)
		{
			strcpy_s(FoodB_N[i],20, "灯影牛肉");
			Food_P[i] = 7.00;
			FoodP_S = FoodP_S + 7.00 * FoodB_C[i];
			//用于统计阶段
			Food_R[8] = Food_R[8] + FoodB_C[i];				//销量加一
			FoodC_SR[2] = FoodC_SR[2] + FoodB_C[i];
			FoodM_SR[8] = FoodM_SR[8] + 7.00 * FoodB_C[i];				//销售金额加和
			FoodCM_SR[2] = FoodCM_SR[2] + 7.00 * FoodB_C[i];
		}
	}
	
	while (1)								//准备输出明细账单
	{
		system("cls");
		printf("\n");
		printf("顾客应付金额为：\n");
		printf("                 %.2lf  元\n", FoodP_S);
		printf("\n");
		printf("请输入顾客支付金额：\n");
		scanf_s("%lf", &Cash_C);
		rewind(stdin);

		if (Cash_C < FoodP_S)
		{
			system("cls");
			printf("\n");
			printf("Sorry,输入金额有误，请重新输入！-_-\n");
			Sleep(1000);			//界面停顿1秒
			continue;
		}
		break;
	}

	Cash_R = Cash_C - FoodP_S;						//找零金额 
	Sleep(1000);			
	system("cls");
	printf("\n");
	printf("Perfect,顾客消费账单明细正在打印中……   -_-\n");
	Sleep(2500);										//停顿2.5秒打印账单
	system("cls");
	Buy_N++;					//购买的单据计数器加一 让每位顾客的单据不同
	printf("\n");
	printf("                           *****************************************************\n");
	printf("                           *****************************************************\n");
	printf("                           *                    两江味皇美食                   *\n");
	printf("                           *                                                   *\n");
	printf("                           * %d-%02d-%02d %02d:%02d:%02d                               *\n",year,mon,day,hour,min,sec);
	printf("                           *___________________________________________________*\n");
	printf("                           *---------------------------------------------------*\n");
	printf("                           *              请持此小票到取餐口取餐！！！         *\n");
	printf("                           *___________________________________________________*\n");
	printf("                           *---------------------------------------------------*\n");
	printf("                           * 收据号：%04u                                      *\n", Buy_N);
	printf("                           * 收款员：姚源杰                                    *\n");
	printf("                           *___________________________________________________*\n");
	printf("                           *---------------------------------------------------*\n");
	printf("                           * 名称                 数量                  单价   *\n");
	printf("                           *___________________________________________________*\n");
	printf("                           *---------------------------------------------------*\n");
	for (i = 0;i < Num;i++)				//循环输出顾客购买的食品
	{
		printf("                           * %-4s              %-2u                  %6.2f  *\n",
			FoodB_N[i], FoodB_C[i], Food_P[i]);
	}
	printf("                           *___________________________________________________*\n");
	printf("                           *---------------------------------------------------*\n");
	printf("                           * 合计                                      %6.2lf  *\n", FoodP_S);
	printf("                           * 现金                                      %6.2lf  *\n", Cash_C);
	printf("                           * 找零                                      %6.2lf  *\n", Cash_R);
	printf("                           *___________________________________________________*\n");
	printf("                           *---------------------------------------------------*\n");
	printf("                           *                     谢谢惠顾                      *\n");
	printf("                           *****************************************************\n");
	printf("                           *****************************************************\n");

	printf("\n");
	system("pause");
	while (1)
	{
		system("cls");
		printf("\n");
		printf("请问是否进入 %d-%02d-%02d 的销售统计查询： （ Y or y || N or n)\n",year,mon,day);
		scanf_s("%s", ch_1, 10);
		rewind(stdin);

		if (strcmp(ch_1, "Y") == 0 || strcmp(ch_1, "y") == 0)
		{				
			FoodS_T(Food_R, FoodM_SR, FoodC_SR, FoodCM_SR);	//进入统计查看
			break;
		}
		else if (strcmp(ch_1, "N") == 0 || strcmp(ch_1, "n") == 0)
		{
			break;
		}
		else
		{
			if (Err_N == 3)
			{
				system("cls");
				printf("\n");
				printf("Sorry,输入错误次数已达上限（3次），请稍后重试。-_-\n");
				Sleep(2000);
				FoodR_S(head_B);						//进入销售主界面			 
				break;
			}
			else
			{
				system("cls");
				printf("\n");
				printf("Sorry,输入错误，请重新输入：-_-\n");
				Sleep(2000);					//界面停留2秒
				Err_N++;
			}
		}
	}

	Err_N = 1;								//进入新界面，计数器归位
	while (1)
	{
		system("cls");
		printf("\n");
		printf("请问是否继续在线销售食品： （ Y or y || N or n)\n");
		scanf_s("%s", ch_1, 10);
		rewind(stdin);

		if (strcmp(ch_1, "Y") == 0 || strcmp(ch_1, "y")==0)
		{
			FoodR_S(head_B);						//进入在线销售
			break;
		}
		else if (strcmp(ch_1, "N") == 0 || strcmp(ch_1, "n") == 0)
		{
			Mainmenu(head_B);					 //进入主菜单
			break;
		}
		else
		{
			if (Err_N == 3)
			{
				system("cls");
				printf("\n");
				printf("Sorry,输入错误次数已达上限（3次），请稍后重试。-_-\n");
				Sleep(2000);			//界面停顿2秒
				Mainmenu(head_B);						 //进入主菜单
			} 
			else
			{
				system("cls");
				printf("\n");
				printf("Sorry,输入错误，请重新输入：-_-\n");
				Sleep(2000);			//界面停留2秒
				Err_N++;
			}
		}
	}
}

void FoodS_T(static int*Food_R1, static double* FoodM_SR2,static int* FoodC_SR1, static double* FoodCM_SR)
{
	int i = 0;
	double  FoodR_S = 0.0;
	char Fastfood_N[9][20] = { "百事可乐","鲜榨橙汁","牛奶奶茶","兰州拉面","咖喱盖饭",
		                      "扬州炒饭","煎饼果子","香甜糍粑","灯影牛肉" };
	char Fastfood_C[3][20] = { "饮料类","主食类","小吃类" };

	int year = 0, mon = 0, day = 0;			//打印何时的统计结果
	time_t  timep = time(0);
	struct tm p;
	time(&timep);
	localtime_s(&p, &timep);
	year = 1900 + p.tm_year;
	mon = 1 + p.tm_mon;
	day = p.tm_mday;

	system("cls");
	printf("\n");
	printf(" %d年%02d月%02d日 本店食品销售统计情况如下所示：\n",year,mon,day);
	printf("\n");
	printf(" %d年%02d月%02d日 九种食品各销量如下：\n",year,mon,day);
	printf("\n");
	for (i = 0;i < 9;i++)
	{
		printf("%s 的销量为： %d 份\n", Fastfood_N[i], Food_R1[i]);
	}
	printf("\n");
	printf("九种食品各收入总额如下：\n");
	printf("\n");
	for (i = 0;i < 9;i++)
	{
		printf("%s 的收入总额为： %.2lf 元\n", Fastfood_N[i], FoodM_SR2[i]);
	}
	printf("\n");
	printf("三大类食品各销量如下：\n");
	printf("\n");
	for (i = 0;i < 3;i++)
	{
		printf("%s 的销量为： %d 份\n", Fastfood_C[i], FoodC_SR1[i]);
	}
	printf("\n");
	printf("三大类食品各销售总额如下：\n");
	printf("\n");
	for (i = 0;i < 3;i++)
	{
		printf("%s 的销售总额为： %.2lf 元\n", Fastfood_C[i], FoodCM_SR[i]);
		FoodR_S = FoodR_S + FoodCM_SR[i];
	}
	printf("\n");
	printf(" %d年%02d月%02d日 总收入为：%.2lf 元\n", year,mon,day,FoodR_S);
	printf("\n");
	system("pause");				//管理员选择停留时间
}

int main()
{
	Login_S();									//登录系统
	return 0;
}