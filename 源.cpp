/*3.7 У԰���POS���Ʒ�ϵͳ ���������ļ��洢��
������������
У԰��͵�һ������3����ʳƷ�����ϣ���ʳ��СʳƷ�����һ��POS���Ʒ�ϵͳ���Կ�͵��������Ϣ���й���
������Ҫ��
��1������Ա���ܣ�
	��ʳƷ��Ϣ���й�����ӡ���ѯ���޸ģ�ɾ�������̡����ܹ���ʳƷ���ж��ֲ�ѯ��
	������Ϣ����¼��˿�һ�ι����ʳƷ��Ϣ������ʳƷ��š����ۡ������ȡ����㹺��ʳƷ���ܽ���
	����������������������ϸ�˵���
	�ṩ����ͳ�ƹ��ܣ��ɶ�ָ�����ڡ�ָ������ʳƷ��ָ������ʳƷ�������������ܶ�����ݽ���ͳ�ƣ�����
	һ���ĸ�ʽ������ʾ��
��2�����Ҫ��
    //ϵͳֻ����һ������Ա������Աͨ�������¼ϵͳ������ϵͳ�����ʳƷ�����Լ�������Ϣ��ѯ .*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct Fastfood Fastfood;		//���ڲ���

struct Fastfood
{	
	unsigned int F_Save;			//ʳƷ���
	char F_Price[10];				//ʳƷ����
	char F_Name[20];				//ʳƷ����
	char F_ID[20];					//ʳƷ���

	Fastfood* next;
};

//Ϊ�ÿ�͵����ʳƷ����Ϣ��ʼ��
struct Fastfood F_Class[9] = { {200,"5.00","���¿���","D1001"},{150,"6.00","��ե��֭","D1002"},
					   {200,"7.00","ţ���̲�","D1003"},{300,"10.00","��������","M1001"},
					   {350,"15.00","��ସǷ�","M1002"},{400,"8.00","���ݳ���","M1003"},
					   {250,"5.00","�������","S1001"},{200,"4.00","��������","S1002"},
					   {200,"7.00","��Ӱţ��","S1003"} };

struct Fastfood *CreateLink();			    //��������1 ����������
void Login_S();							    //��������2 ����¼ϵͳ
void Mainmenu(Fastfood*);					//��������3 ���������˵�

void FoodM_M(Fastfood*);					//��������4 ��ʳƷ��Ϣ����
void FoodR_S(Fastfood*);					//��������5 ��ʳƷ��������
void FoodS_T(static int*,					//��������6 ��ʳƷ����ͳ��
	static double*,static int*, static double*);

void FoodC_Add(Fastfood*);				    //��������7 ��ʳƷ������
void FoodAC_D(Fastfood*);					//��������8 ��ʳƷ������-������
void FoodAC_M(Fastfood*);				    //��������9 ��ʳƷ������-��ʳ��
void FoodAC_S(Fastfood*);					//��������10��ʳƷ������-С����

void FoodC_Del(Fastfood*);				    //��������11��ʳƷ���ɾ��
void FoodDC_D(Fastfood*);					//��������12��ʳƷɾ�����-������
void FoodDC_M(Fastfood*);				    //��������13��ʳƷɾ�����-��ʳ��
void FoodDC_S(Fastfood*);					//��������14��ʳƷɾ�����-С����


void FoodM_Mod(Fastfood*);				    //��������15��ʳƷ��Ϣ�޸�
void FoodMC_D(Fastfood*);					//��������16��ʳƷ�޸����-������
void FoodMC_M(Fastfood*);				    //��������17��ʳƷ�޸����-��ʳ��
void FoodMC_S(Fastfood*);					//��������18��ʳƷ�޸����-С����
 
void FoodM_See(Fastfood*);				    //��������19��ʳƷ����ѯ
void FoodM_Sav(Fastfood*);				    //��������20��ʳƷ��Ϣ����

void Output_FM(Fastfood*);				    //��������21�����ʳƷ��Ϣ
void Output_SM(Fastfood*);				    //��������22�����������Ϣ


void Login_S()								    //��¼ϵͳ
{
	int Num_1 = 1;								//�û�������������
	int Num_2 = 1;								//�û�������������
	char ch_1[10] = { 0 };						//�洢�û������Ƿ����
	char Name_1[20] = "ҦԴ��";					//����Ա����
	char PassWord_1[20] = "12003990701";		//��¼����
	char Name_2[20] = { 0 };					//�洢����Ա�����¼����
	char PassWord_2[20] = { 0 };				//�洢����Ա�����¼����
	Fastfood* p_head = NULL;

	while (1)									//ϵͳ��ȫ���ϣ������û���������
	{
		system("cls");							    //�ٴν�������Ż�����
		printf("\n");
		printf("�����Ƿ��¼ --���POS���Ʒ�-- ϵͳ����Y or y || N or n ) -_-\n");
		scanf_s("%s", &ch_1, 10);
		rewind(stdin);							//��ջ����������������������

		if (strcmp(ch_1, "Y") == 0 || strcmp(ch_1, "y") == 0)
		{					
			while (1)						//��¼��Ϣ���������
			{
				system("cls");
				printf("\n");
				printf("�������¼������\n");
				scanf_s("%s", Name_2, 20);
				rewind(stdin);

				printf("�������¼���룺\n");
				scanf_s("%s", PassWord_2, 20);
				rewind(stdin);

				if (strcmp(Name_1, Name_2) == 0 && strcmp(PassWord_1, PassWord_2) == 0)
				{
					system("cls");									   	//�����Ѻô���
					printf("\n");
					printf("                     *---------------------------------------------------------*\n");
					printf("                     *                                                         *\n");
					printf("                     *                                                         *\n");
					printf("                     *****       ��¼�ɹ� ��ӭ���� --�Ʒѹ���ϵͳ--        *****\n");
					printf("                     *                                                         *\n");
					printf("                     *                                                         *\n");
					printf("                     *---------------------------------------------------------*\n");

					p_head = CreateLink();			//��������
					Sleep(2000);					//����ͣ��2��
					Mainmenu(p_head);
					system("cls");
					break;
				}
				else
				{
					if (Num_2 == 3)				//����ﵽ����ֱ���˳�����
					{
						system("cls");									
						printf("\n");
						printf("Sorry,�����������Ѵ�����(3��),���Ժ����ԡ�-_-\n");
						exit(1);
					}
					system("cls");
					printf("\n");
					printf("Sorry,����ĵ�¼��Ϣ�������������룺-_-\n");	
					Sleep(2000);			//������ͣ2��
					printf("\n");
					Num_2++;					//��������������һ
				}	
			}
			break;							//�ɹ�����ϵͳ�������˳������������ѭ��
		}
		else if (strcmp(ch_1, "N") == 0 || strcmp(ch_1, "n") == 0)		//ֱ���˳�����
		{
			system("cls");
			printf("\n");
			printf("���˳� --�Ʒѹ���ϵͳ-- ��¼���棬��ӭ�´�ʹ�á� -_-\n");
			exit(1);
		}
		else
		{
			if (Num_1 == 3)			//�ݴ���
			{
				system("cls");
				printf("\n");
				printf("Sorry,�����������Ѵ�����(3��),���Ժ����ԡ� -_-\n");
				exit(1);
			}
			system("cls");
			printf("\n");
			printf("Sorry,����������������룺 -_-\n");
			Sleep(2000);					//����ͣ��2��
			Num_1++;				//��������������һ
		}
	}
	return;						//�������践��ֵ
}

struct Fastfood* CreateLink()				//������������ÿ��ʳƷ����Ϣ�洢�ڽ����
{
	int i=0;											//ѭ������
	Fastfood* phead = NULL, *pmove = NULL, *pfresh = NULL;		//ͷ��㡢�ƶ�ָ�롢�׽��

	phead = (Fastfood* )malloc(sizeof(*phead));				//Ϊͷ��㶯̬�����ڴ沢�п�
	if (phead == NULL)
	{
		printf("Sorry,�ڴ����ʧ�ܣ����Ժ����ԡ�-_-\n");
		exit(0);
	}
	pmove = phead;						//�ƶ�ָ��ֱ��ָ��ͷ���
	pmove->next = NULL;					

	for (i = 0;i < 9;i++)				//������ʳƷ����Ϣ�洢�������ÿ�����
	{
		pfresh = (Fastfood*)malloc(sizeof(*pfresh));		//Ϊ�½������ڴ沢�п�
		if (pfresh == NULL)
		{
			printf("Sorry,�ڴ����ʧ�ܣ����Ժ����ԡ�-_-\n");
			exit(0);
		}

		//������㣬����ÿ��ʳƷ����Ϣ�洢�ڽ����
		pfresh->F_Save = F_Class[i].F_Save;
		strcpy_s(pfresh->F_Price,10, F_Class[i].F_Price);
		strcpy_s(pfresh->F_ID,20, F_Class[i].F_ID);
		strcpy_s(pfresh->F_Name, 20, F_Class[i].F_Name);

		pmove->next = pfresh;										//��������������
		pfresh->next = NULL;
		pmove = pfresh;

	}
	return phead;					//����ͷ����Ա��������
}

void Output_FM(Fastfood* head_C)						//������������ʳƷ��Ϣ
{
	double Food_P = 0.0;							//ʳƷ����
	Fastfood* pmove = NULL;										
	pmove = head_C->next;							//����ֱ���ƶ�ͷ��㣬��ָ��������

	system("cls");
	printf("��������ʳƷ�Ļ�����Ϣ������ʾ��\n");
	while (pmove != NULL)							//��������
	{
		Food_P = atof(pmove->F_Price);			//���ַ���ת��Ϊ�����ͱ������
		printf("                                    ʳƷ��ţ�%s            \n", pmove->F_ID);
		printf("                                    ʳƷ���ƣ�%s            \n", pmove->F_Name);
		printf("                                    ʳƷ���ۣ�%.2lf Ԫ       \n", Food_P);
		printf("                                    ʳƷ��棺%d ��         \n", pmove->F_Save);
		pmove = pmove->next;
		printf("\n");
	}
	printf("*---------------------------------------------------------------------------------------*\n");
	printf("\n");				//�û�ѡ��ͣ��ʱ�䲢ѡ����һ���Ĳ���
	system("pause");
}

void Mainmenu(Fastfood* head)					//ϵͳ���˵�
{
	int Err_N = 1;							   //�洢�û��������Ĵ���
	char ch_1[10] = { 0 };					  //����ѡ����

	Fastfood* phead = NULL;						
	phead = head;									//����ֱ���ƶ�ͷָ��

	while (1)						       //�ݴ�����ֹ�û���������
	{
		system("cls");								//�����Ż�
		printf("\n");
		printf("                                             ���POS���Ʒ�ϵͳ            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *            A.ʳƷ��Ϣ����             *\n");
		printf("                                 *                                       *\n");
		printf("                                 *            B.ʳƷ��������             *\n");
		printf("                                 *                                       *\n");
		printf("                                 *            C.ʳƷ��Ϣ�鿴             *\n");
		printf("                                 *                                       *\n");
		printf("                                 *            D.�˳��Ʒ�ϵͳ             *\n");
		printf("                                 *---------------------------------------*\n");

		printf("��ѡ����Ӧ��������Ӧ����ĸ��\n");
		scanf_s("%s", ch_1, 10);
		rewind(stdin);

		if (strcmp(ch_1, "A") == 0)
		{
			FoodM_M(phead);		//����ʳƷ��Ϣ����
			break;
		}
		else if (strcmp(ch_1, "B") == 0)
		{
			FoodR_S(phead);		//����ʳƷ��������
			break;
		}
		else if (strcmp(ch_1, "C") == 0)
		{
			Output_FM(phead);		//����ʳƷ��Ϣ�鿴
			Mainmenu(phead);		//�鿴����ٽ������˵�ѡ����������
			break;
		}
		else if (strcmp(ch_1, "D") == 0)
		{
			system("cls");
			printf("\n");
			printf("���˳� --���POS���Ʒ�ϵͳ-- ,��ӭ�´�ʹ�á�-_-");
			printf("\n");
			exit(1);
		}
		else
		{
			if (Err_N == 3)
			{
				system("cls");
				printf("\n");					//�����������ﵽ3��ֱ���˳�ϵͳ
				printf("Sorry,�����������Ѵ����ޣ�3�Σ�,���Ժ����ԡ�-_-\n");
				Sleep(2000);			//����ͣ������
				Login_S();				//�����¼����
			}
			else
			{
				system("cls");
				printf("\n");
				printf("Sorry,����������������룺-_-\n");
				Sleep(2000);						//����ͣ��2��
				Err_N++;								//��������������һ
				
			}
		}
	}
		
	return;
}

void FoodM_M(Fastfood* head_A)							//ʳƷ��Ϣ����
{
	int Err_N = 1;										//�洢�û��������Ĵ���
	char ch_2[10] = { 0 };								//���� if ���ѡ����Ӧ����

	Fastfood* phead = NULL;								//����ֱ���ƶ�ͷָ��
	phead = head_A;

	while (1)
	{
		system("cls");										//�����Ż�
		printf("\n");
		printf("                                             ���POS���Ʒ�ϵͳ            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *            A.ʳƷ������             *\n");
		printf("                                 *                                       *\n");
		printf("                                 *            B.ʳƷ���ɾ��             *\n");
		printf("                                 *                                       *\n");
		printf("                                 *            C.ʳƷ��Ϣ�޸�             *\n");
		printf("                                 *                                       *\n");
		printf("                                 *            D.ʳƷ��Ϣ��ѯ             *\n");
		printf("                                 *                                       *\n");
		printf("                                 *            E.ʳƷ��Ϣ����             *\n");
		printf("                                 *                                       *\n");
		printf("                                 *            F.����ϵͳ�˵�             *\n");
		printf("                                 *                                       *\n");
		printf("                                 *            G.�˳��Ʒ�ϵͳ             *\n");
		printf("                                 *---------------------------------------*\n");

		printf("��ѡ�������Ӧ��������Ӧ����ĸ��\n");
		scanf_s("%s", ch_2, 10);
		rewind(stdin);

		if (strcmp(ch_2, "A") == 0)
		{
			FoodC_Add(phead);						//����ʳƷ������
			break;
		}
		else if (strcmp(ch_2, "B") == 0)
		{
			FoodC_Del(phead);						//����ʳƷ���ɾ��
			break;
		}
		else if (strcmp(ch_2, "C") == 0)
		{
			FoodM_Mod(phead);						//����ʳƷ��Ϣ�޸�
			break;
		}
		else if (strcmp(ch_2, "D") == 0)
		{
			FoodM_See(phead);						//����ʳƷ��Ϣ��ѯ
			break;

		}
		else if (strcmp(ch_2, "E") == 0)
		{
			FoodM_Sav(phead);						//����ʳƷ��Ϣ����
			break;
		}
		else if (strcmp(ch_2, "F") == 0)
		{
			Mainmenu(phead);						//�������˵�
			break;
		}
		else if (strcmp(ch_2, "G") == 0)			//�˳�ϵͳ
		{
			system("cls");
			printf("\n");
			printf("���˳� --���POS���Ʒ�ϵͳ-- ,��ӭ�´�ʹ�á�-_-\n");
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
				//�������ﵽ���κ�ֱ�ӷ������˵�
				printf("Sorry,�����������Ѵ����ޣ�3�Σ������Ժ����ԡ�-_-\n");
				Sleep(2000);				//����ͣ��2��
				Mainmenu(head_A);
			}
			else
			{
				system("cls");
				printf("\n");
				printf("Sorry,����������������룺-_-\n");
				Sleep(2000);			//����ͣ��2��
				Err_N++;				//��������������һ
			}
		}
	}
	return;
}

void FoodC_Add(Fastfood* head_1)					//ʳƷ�������
{
	int Err_N = 1;							  //�洢�û��������Ĵ���
	char ch_3[10] = { 0 };						//���� if ���ѡ����

	Fastfood* phead = NULL;							//����ֱ���ƶ�ͷָ��
	phead = head_1;

	while (1)
	{
		system("cls");									//�����Ż�
		printf("\n");
		printf("                                              ���POS���Ʒ�ϵͳ            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                A.������               *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                B.��ʳ��               *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                C.С����               *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("��ѡ�����ʳƷ�������Ӧ����ĸ��\n");
		scanf_s("%s", ch_3,10);
		rewind(stdin);

		if (strcmp(ch_3, "A") == 0)
		{
			FoodAC_D(phead);						//������������ӣ�
			break;
		}
		else if (strcmp(ch_3, "B") == 0)
		{
			FoodAC_M(phead);						//������ʳ�����
			break;
		}
		else if (strcmp(ch_3, "C") == 0)
		{
			FoodAC_S(phead);						//����С�������
			break;
		}
		else
		{
			if (Err_N == 3)
			{
				//�������ﵽ���κ�ֱ�ӷ����Ͻ���
				system("cls");
				printf("\n");
				printf("Sorry,�����������Ѵ����ޣ�3�Σ������Ժ����ԡ�-_-\n");
				Sleep(2000);			//����ͣ������
				FoodM_M(head_1);		//����ʳƷ��Ϣ����
			}
			else
			{
				system("cls");
				printf("\n");
				printf("Sorry,����������������룺-_-\n");
				Sleep(2000);    //������ͣ2��
				Err_N++;				//��������������һ
				
			}
		}
	}
	return;
}
void FoodAC_D(Fastfood* head_a)
{
	int i=0;									//ѭ������
	int Num = 1;								//�ݴ���
	char Food_M[20] = { 0 };					//�洢����Ա��ѯ��ʳƷ����Ϣ
	char ch_1[10] = { 0 };						//�洢����Ա�Ƿ���������������ĸ
	//���� Static �����˳��ú������ĳһ�����ļ�¼��ʧ
	static unsigned int Err_1 = 0;					//�洢����Ա��ѯͬһʳƷ����
	static char ch_b[100][50] = { 0 };				//���ѹ���Ա�ظ���ѯ

	Fastfood* pmove = NULL, * pfresh = NULL;			//����ֱ���ƶ�ͷָ��
	pmove = head_a->next;

	pfresh = (Fastfood*)malloc(sizeof(*pfresh));		//Ϊ�½�㶯̬�����ڴ沢�п�
	if (pfresh == NULL)
	{
		printf("Sorry,�ڴ����ʧ�ܣ����Ժ����ԡ�-_-\n");
		exit(0);
	}

	while (1)			//�������ѹ���Ա����û�� ��TA) �����ʳƷ�������Լ�����ѯ
	{
		pmove = head_a->next;			//����һ�����Ҫ����ָ��ͷ�����һ��������
		system("cls");								    //�����Ż�
		printf("\n");
		printf("                                             �������ʳƷ�ı��            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                D1001                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                D1002                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                D1003                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("��ѡ������һ��ź������ʳƷ��Ϣ��\n");
		scanf_s("%s", Food_M, 20);
		rewind(stdin);


		for (i = 0;i < Err_1;i++)				//�����û��Ѿ���ѯ�������������Ϣ
		{
			if (strcmp(ch_b[i], Food_M) == 0)
			{
				system("cls");
				printf("\n");
				while (1)				//�����û�����������֣�������������
				{
					printf("���ѣ��ñ�ź����Ѿ������ʳƷ��Ϣ���Ƿ���Ҫ�ٴ���ӣ���Y or y || N or n )-_-\n");
					scanf_s("%s", &ch_1, 10);
					rewind(stdin);						//��ջ����������������������

					if (strcmp(ch_1, "Y") == 0 || strcmp(ch_1, "y") == 0)
					{
						FoodAC_D(head_a);				//����ʳƷ������
					}
					else if (strcmp(ch_1, "N") == 0 || strcmp(ch_1, "n") == 0)
					{
						FoodM_M(head_a);		//���½���ʳƷ��Ϣ����
					}
					else
					{
						if (Num == 3)
						{
							system("cls");
							printf("\n");
							printf("Sorry,�����������Ѵ�����(3��),���Ժ����ԡ�-_-\n");
							Sleep(2000);    //����ͣ������
							Mainmenu(head_a);		//��������ﵽ���κ�ֱ�ӽ������˵�
						}
						system("cls");
						printf("\n");
						printf("Sorry,����������������룺-_-\n");
						Sleep(2000);			//������ͣ2��
						Num++;				//������󣬼�������һ
					}
				}
			}
			else					//������һ��ѭ����Ѱ���Ƿ��ٴβ�ѯ
			{
				continue;
			}
		}

		while (pmove != NULL)				//���������ÿ�����
		{
			if (strcmp(Food_M, pmove->F_ID) == 0)
			{
				printf("���������ʳƷ�ı�ţ�\n");
				scanf_s("%s", pfresh->F_ID, 20);
				rewind(stdin);
				//�洢�ñ�ţ����ں������ѹ���Ա�ظ����
				strcpy_s(ch_b[Err_1], 20, pmove->F_ID);

				printf("���������ʳƷ�����ƣ�\n");
				scanf_s("%s", pfresh->F_Name, 20);
				rewind(stdin);
				printf("���������ʳƷ�ĵ��ۣ�\n");
				scanf_s("%s", pfresh->F_Price,10);
				rewind(stdin);
				printf("���������ʳƷ�Ŀ�棺\n");
				scanf_s("%d", &pfresh->F_Save);	//��������Ҫ & ȡַ
				rewind(stdin);

				pfresh->next = pmove->next;		//�Խ���ԭ�򣬺�巨
				pmove->next = pfresh;

				system("cls");
				printf("\n");
				printf("Perfect����ʳƷ��ӳɹ���-_-\n");
				Sleep(2000);			//��ӳɹ�������ͣ������
				Err_1++;				//��ӳɹ����������һ
				FoodM_M(head_a);		//���½���ʳƷ��Ϣ����
			}
			pmove = pmove->next;
		}

		system("cls");
		printf("\n");
		printf("Sorry,����û��ʳƷ�ı����������ı��ƥ�䡣-_-\n");
		Sleep(2000);
		FoodM_M(head_a);		//��Ϊû�������ʳƷ�����ٴ�ʳƷ��Ϣ����
	}
}
void FoodAC_M(Fastfood* head_b)
{
	int i = 0;									//ѭ������
	int Num = 1;								//�ݴ���
	char Food_M[20] = { 0 };					//�洢����Ա��ѯ��ʳƷ����Ϣ
	char ch_1[10] = { 0 };						//����Ա����
	static int Err_2 = 0;					//�洢����Ա��ѯͬһʳƷ����
	static char ch_b[100][50] = { 0 };				 //���ѹ���Ա�ظ���ѯ

	Fastfood* pmove = NULL, * pfresh = NULL;			//����ֱ���ƶ�ͷָ��
	pmove = head_b->next;

	pfresh = (Fastfood*)malloc(sizeof(*pfresh));		//ͬ��
	if (pfresh == NULL)
	{
		printf("Sorry,�ڴ����ʧ�ܣ����Ժ����ԡ�-_-\n");
		exit(0);
	}

	while (1)
	{
		system("cls");									//�����Ż�
		pmove = head_b->next;							//����һ�����Ҫ����ָ��ͷ���
		printf("\n");
		printf("                                             ��ʳ���ʳƷ�ı��            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                M1001                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                M1002                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                M1003                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("��ѡ������һ��ź������ʳƷ��Ϣ��\n");
		scanf_s("%s", Food_M, 20);
		rewind(stdin);

		for (i = 0;i < Err_2;i++)			//ͬ��
		{
			if (strcmp(ch_b[i], Food_M) == 0)
			{
				system("cls");
				printf("\n");
				while (1)
				{
					printf("���ѣ��ñ�ź����Ѿ������ʳƷ��Ϣ���Ƿ���Ҫ�ٴ���ӣ���Y or y || N or n )-_-\n");
					scanf_s("%s", &ch_1, 10);
					rewind(stdin);						//��ջ����������������������

					if (strcmp(ch_1,"Y") == 0 || strcmp(ch_1,"y") == 0)
					{
						FoodAC_D(head_b);					//����ʳƷ������
					}
					else if (strcmp(ch_1, "N") == 0 || strcmp(ch_1, "n") == 0)
					{
						FoodM_M(head_b);		//���½���ʳƷ��Ϣ����
					}
					else
					{
						if (Num == 3)
						{
							system("cls");
							printf("\n");
							printf("Sorry,�����������Ѵ�����(3��),���Ժ����ԡ�-_-\n");
							Sleep(2000);
							Mainmenu(head_b);			//������󳬹��������½������˵�
						}
						system("cls");
						printf("\n");
						printf("Sorry,����������������룺-_-\n");
						Sleep(2000);			//������ͣ2��
						Num++;					//ͬ��
					}
				}
			}
			else     //ͬ��
			{
				continue;
			}
		}

		while (pmove != NULL)   //ͬ��
		{
			if (strcmp(Food_M, pmove->F_ID) == 0)
			{
				printf("���������ʳƷ�ı�ţ�\n");
				scanf_s("%s", pfresh->F_ID, 20);
				rewind(stdin);

				//�洢�ñ�ţ������ظ����
				strcpy_s(ch_b[Err_2], 20, pmove->F_ID);

				printf("���������ʳƷ�����ƣ�\n");
				scanf_s("%s", pfresh->F_Name, 20);
				rewind(stdin);
				printf("���������ʳƷ�ĵ��ۣ�\n");
				scanf_s("%s", pfresh->F_Price, 10);
				rewind(stdin);
				printf("���������ʳƷ�Ŀ�棺\n");
				scanf_s("%d", &pfresh->F_Save);
				rewind(stdin);

				pfresh->next = pmove->next;		//�Խ���ԭ�򣬺�巨
				pmove->next = pfresh;

				system("cls");
				printf("\n");
				printf("Perfect����ʳƷ��ӳɹ���-_-\n");
				Sleep(2000);				//ͬ��
				Err_2++;
				FoodM_M(head_b);		//���½���ʳƷ��Ϣ����
			}
			pmove = pmove->next;
		}

		system("cls");
		printf("\n");
		printf("Sorry,����û��ʳƷ�ı����������ı��ƥ�䡣-_-\n");
		Sleep(2000);
		FoodM_M(head_b);		//���½���ʳƷ��Ϣ����
	}
}
void FoodAC_S(Fastfood* head_c)
{
	int i = 0;								//ѭ������
	int  Num = 1;							//�ݴ���
	char Food_M[20] = { 0 };							 //�洢����Ա��ѯ��ʳƷ����Ϣ
	char ch_1[2] = { 0 };							//����Ա����
	static int Err_3 = 0;				//�洢����Ա��ѯͬһʳƷ����
	static char ch_b[100][50] = { 0 };			  //���ѹ���Ա�ظ���ѯ

	Fastfood* pmove = NULL, * pfresh = NULL;				//����ֱ���ƶ�ͷָ��
	pmove = head_c->next;

	pfresh = (Fastfood*)malloc(sizeof(*pfresh));			//ͬ��
	if (pfresh == NULL)
	{
		printf("Sorry,�ڴ����ʧ�ܣ����Ժ����ԡ�-_-\n");
		exit(0);
	}

	while (1)
	{
		pmove = head_c->next;							//����һ�����Ҫ����ָ��ͷ���
		system("cls");									//�����Ż�
		printf("\n");
		printf("                                             С�����ʳƷ�ı��            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                S1001                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                S1002                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                S1003                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("��ѡ������һ��ź������ʳƷ��Ϣ��\n");
		scanf_s("%s", Food_M, 20);
		rewind(stdin);

		for (i = 0;i < Err_3;i++)			//ͬ��
		{
			if (strcmp(ch_b[i], Food_M) == 0)
			{
				system("cls");
				printf("\n");
				while (1)
				{
					printf("���ѣ��ñ�ź����Ѿ������ʳƷ��Ϣ���Ƿ���Ҫ�ٴ���ӣ���Y or y || N or n )-_-\n");
					scanf_s("%s", &ch_1, 10);
					rewind(stdin);						//��ջ����������������������

					if (strcmp(ch_1, "Y") == 0 || strcmp(ch_1, "y") == 0)
					{
						FoodAC_D(head_c);					//����ʳƷ������
					}
					else if (strcmp(ch_1, "N") == 0 || strcmp(ch_1, "n") == 0)
					{
						FoodM_M(head_c);		//���½���ʳƷ��Ϣ����
					}
					else
					{
						if (Num == 3)		//ͬ��
						{
							system("cls");
							printf("\n");
							printf("Sorry,�����������Ѵ�����(3��),���Ժ����ԡ�-_-\n");
							Sleep(2000);
							Mainmenu(head_c);			//���½������˵�
						}
						system("cls");
						printf("\n");
						printf("Sorry,����������������룺-_-\n");
						Sleep(2000);				//����ͣ��2��
						Num++;
					}
				}
			}
			else     //ͬ��
			{
				continue;
			}
		}

		while (pmove != NULL)			//ͬ��
		{
			if (strcmp(Food_M, pmove->F_ID) == 0)
			{
				printf("���������ʳƷ�ı�ţ�\n");
				scanf_s("%s", pfresh->F_ID,20);
				rewind(stdin);

				//�洢�ñ�ţ������ظ����
				strcpy_s(ch_b[Err_3], 20, pmove->F_ID);

				printf("���������ʳƷ�����ƣ�\n");
				scanf_s("%s", pfresh->F_Name, 20);
				rewind(stdin);
				printf("���������ʳƷ�ĵ��ۣ�\n");
				scanf_s("%s", pfresh->F_Price,10);
				rewind(stdin);
				printf("���������ʳƷ�Ŀ�棺\n");
				scanf_s("%d", &pfresh->F_Save);
				rewind(stdin);

				pfresh->next = pmove->next;		//�Խ���ԭ�򣬺�巨
				pmove->next = pfresh;

				system("cls");
				printf("\n");
				printf("Perfect����ʳƷ��ӳɹ���-_-\n");
				Sleep(2000);
				Err_3++;					//ͬ��
				FoodM_M(head_c);		//���½���ʳƷ��Ϣ����
			}
			pmove = pmove->next;
		}

		system("cls");
		printf("\n");
		printf("Sorry,����û��ʳƷ�ı����������ı��ƥ�䡣-_-\n");
		Sleep(2000);
		FoodM_M(head_c);		//û�и�ʳƷ���½���ʳƷ��Ϣ����
	}
}

void FoodC_Del(Fastfood* head_2)					    	//ʳƷ��Ϣɾ��
{
	int Err_N = 1;										  //�洢�û��������
	char ch_4[10] = { 0 };									//���� if ���ѡ����

	Fastfood* phead = NULL;										//����ֱ���ƶ�ͷָ��
	phead = head_2;

	while (1)
	{
		system("cls");												//�����Ż�
		printf("\n");
		printf("                                              ���POS���Ʒ�ϵͳ            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                A.������               *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                B.��ʳ��               *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                C.С����               *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("��ѡ��ɾ��ʳƷ�������Ӧ����ĸ��\n");
		scanf_s("%s", ch_4, 10);
		rewind(stdin);

		if (strcmp(ch_4, "A") == 0)
		{
			FoodDC_D(phead);						//����������ɾ����
			break;
		}
		else if (strcmp(ch_4, "B") == 0)
		{
			FoodDC_M(phead);						//������ʳ��ɾ��
			break;
		}
		else if (strcmp(ch_4, "C") == 0)
		{
			FoodDC_S(phead);						//����С����ɾ��
			break;
		}
		else
		{
			if (Err_N == 3)
			{
				//�����������ﵽ3�η�����һ����
				system("cls");
				printf("\n");
				printf("Sorry,�����������Ѵ����ޣ�3�Σ������Ժ����ԡ�-_-\n");
				Sleep(2000);			//ͣ������
				FoodM_M(head_2);				//���½�����Ϣ�������
			}
			else
			{
				system("cls");
				printf("\n");
				printf("Sorry,����������������룺-_-\n");
				Sleep(2000);			//����ͣ��2��
				Err_N++;			//��������������һ
			}
		}
	}
	return;
}
void FoodDC_D(Fastfood* head_d)
{
	int i = 0;											//ѭ������
	char Food_M[20] = { 0 };										 //�洢����Աɾ����ʳƷ����Ϣ
	//���� Static �����˳��ú������ĳһ�����ļ�¼��ʧ
	static int Err_4 = 0;							//�洢����Աɾ��ͬһʳƷ����
	static char ch_b[100][50] = { 0 };						 //���ѹ���Ա�ظ�ɾ��

	Fastfood* pmove = NULL, * psave = NULL;					//����ֱ���ƶ�ͷָ��
	pmove = head_d;

	while (1)
	{
		system("cls");											//�����Ż�
		printf("\n");
		printf("                                             �������ʳƷ�ı��            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                D1001                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                D1002                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                D1003                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("������ɾ��ʳƷ�ı�ţ�\n");
		scanf_s("%s", Food_M, 20);
		rewind(stdin);

		for (i = 0;i < Err_4;i++)			//��������Ѱ�Ҹ�������Ƿ��Ѿ�ɾ����
		{
			if (strcmp(ch_b[i], Food_M) == 0)
			{
				system("cls");
				printf("\n");
				printf("���ѣ���ɾ������ʳƷ�������ظ�ɾ����-_-\n");
				Sleep(2000);				//����ͣ��2��
				FoodM_M(head_d);		//���½���ʳƷ��Ϣ����		
			}
			else
			{
				continue;
			}
		}

		pmove = head_d;							//����һ�����Ҫ����ָ��ͷ���
		while (pmove->next != NULL)
		{
			if (strcmp(Food_M, pmove->next->F_ID) == 0)
			{
				//���޸ĵı�Ŵ洢���������������ظ��޸�
				strcpy_s(ch_b[Err_4], 20, pmove->next->F_ID);

				psave = pmove->next;
				pmove->next = pmove->next->next;		//ɾ���ڵ�Ĺؼ�
				free(psave);				//��ɾ���Ľڵ�Ķ�̬�ռ��ڴ��ͷŵ���ָ�� NULL
				psave = NULL;

				system("cls");
				printf("\n");
				printf("Perfect����� -%s- ����Ӧ����Ϣɾ���ɹ���-_-\n", Food_M);
				Sleep(2000);
				Err_4++;			  //�����ɺ�������һ
				FoodM_M(head_d);		//ɾ���ɹ������½���ʳƷ��Ϣ����
			}
			pmove = pmove->next;
		}
		system("cls");
		printf("\n");
		printf("Sorry,����û��ʳƷ�ı����������ı��ƥ�䡣-_-\n");
		Sleep(2000);				//����ͣ��2��
		FoodM_M(head_d);		//û�и�ʳƷ���½���ʳƷ��Ϣ����
	}
}
void FoodDC_M(Fastfood* head_e)
{
	int i =0 ;											  //ѭ������
	char Food_M[20] = { 0 };							 //�洢����Աɾ����ʳƷ����Ϣ
	//���� Static �����˳��ú������ĳһ�����ļ�¼��ʧ
	static int Err_5 = 0;										  //�洢����Աɾ��ͬһʳƷ����
	static char ch_b[100][50] = { 0 };						  //���ѹ���Ա�ظ�ɾ��

	Fastfood* pmove = NULL, * psave = NULL;					//����ֱ���ƶ�ͷָ��
	pmove = head_e->next;

	while (1)
	{
		system("cls");											//�����Ż�
		printf("\n");
		printf("                                             ��ʳ���ʳƷ�ı��            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                M1001                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                M1002                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                M1003                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("������ɾ��ʳƷ�ı�ţ�\n");
		scanf_s("%s", Food_M,20);
		rewind(stdin);

		for (i = 0;i < Err_5;i++)			//ͬ��
		{
			if (strcmp(ch_b[i], Food_M) == 0)
			{
				system("cls");
				printf("\n");
				printf("���ѣ���ɾ������ʳƷ�������ظ�ɾ����-_-\n");
				printf("\n");
				Sleep(2000);
				FoodM_M(head_e);		//���½���ʳƷ��Ϣ����				
			}
			else				//ͬ��
			{
				continue;
			}
		}

		pmove = head_e;							//����һ�����Ҫ����ָ��ͷ���
		while (pmove->next != NULL)
		{
			if (strcmp(Food_M, pmove->next->F_ID) == 0)
			{
				//���޸ĵı�Ŵ洢���������������ظ��޸�
				strcpy_s(ch_b[Err_5], 20, pmove->next->F_ID);

				psave = pmove->next;
				pmove->next = pmove->next->next;		//ɾ���ڵ�Ĺؼ�
				free(psave);				//��ɾ���Ľڵ�Ķ�̬�ռ��ڴ��ͷŵ���ָ�� NULL
				psave = NULL;

				system("cls");
				printf("\n");
				printf("Perfect����� -%s- ����Ӧ����Ϣɾ���ɹ���-_-\n", Food_M);
				Sleep(2000);
				Err_5++;					//ͬ��
				FoodM_M(head_e);		//ɾ���ɹ������ʳƷ��Ϣ����
			}
			pmove = pmove->next;
		}
		system("cls");
		printf("\n");
		printf("Sorry,����û��ʳƷ�ı����������ı��ƥ�䡣-_-\n");
		Sleep(2000);
		FoodM_M(head_e);			//ͬ��
	}
}
void FoodDC_S(Fastfood* head_f)
{
	int i = 0;													//ѭ������
	char Food_M[20] = { 0 };									 //�洢����Աɾ����ʳƷ����Ϣ
	//���� Static �����˳��ú������ĳһ�����ļ�¼��ʧ
	static int Err_6 = 0;										 //�洢����Աɾ��ͬһʳƷ����
	static char ch_b[100][50] = { 0 };						  //���ѹ���Ա�ظ�ɾ��

	Fastfood* pmove = NULL, * psave = NULL;									//����ֱ���ƶ�ͷָ��
	pmove = head_f->next;

	while (1)
	{
		system("cls");											//�����Ż�
		printf("\n");
		printf("                                             С�����ʳƷ�ı��            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                S1001                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                S1002                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                S1003                  *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("������ɾ��ʳƷ�ı�ţ�\n");
		scanf_s("%s", Food_M,20);
		rewind(stdin);

		for (i = 0;i < Err_6;i++)				//ͬ��
		{
			if (strcmp(ch_b[i], Food_M) == 0)
			{
				system("cls");
				printf("\n");
				printf("���ѣ���ɾ������ʳƷ�������ظ�ɾ����-_-\n");
				Sleep(2000);			//ͬ��
				FoodM_M(head_f);				//���½���ʳƷ��Ϣ����
			}
			else				//ͬ��
			{
				continue;
			}
		}

		pmove = head_f->next;							//����һ�����Ҫ����ָ��ͷ���
		while (pmove->next!= NULL)
		{
			if (strcmp(Food_M, pmove->next->F_ID) == 0)
			{
				//���޸ĵı�Ŵ洢���������������ظ��޸�
				strcpy_s(ch_b[Err_6], 20, pmove->next->F_ID);

				psave = pmove->next;
				pmove->next = pmove->next->next;		//ɾ���ڵ�Ĺؼ�
				free(psave);					//��ɾ���Ľڵ�Ķ�̬�ռ��ڴ��ͷŵ���ָ�� NULL
				psave = NULL;

				system("cls");
				printf("\n");
				printf("Perfect����� -%s- ����Ӧ����Ϣɾ���ɹ���-_-\n", Food_M);
				Sleep(2000);			//ͬ��
				Err_6++;
				FoodM_M(head_f);				//ɾ���ɹ������½���ʳƷ��Ϣ����				
			}
			pmove = pmove->next;
		}
		system("cls");
		printf("\n");
		printf("Sorry,����û��ʳƷ�ı����������ı��ƥ�䡣-_-\n");
		Sleep(2000);			//ͬ��
		FoodM_M(head_f);		//û�и�ʳƷ���½���ʳƷ��Ϣ����	
	}
}

void FoodM_Mod(Fastfood* head_3)			  //ʳƷ��Ϣ�޸�
{
	int Err_N = 1;					          //�洢�û��������
	char ch_5[10] = { 0 };									//���� if ���ѡ����

	Fastfood* phead = NULL;						//����ֱ���ƶ�ͷָ��
	phead = head_3;

	while (1)
	{
		system("cls");											//�����Ż�
		printf("\n");
		printf("                                             ���POS���Ʒ�ϵͳ            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *               A.������                *\n");
		printf("                                 *                                       *\n");
		printf("                                 *               B.��ʳ��                *\n");
		printf("                                 *                                       *\n");
		printf("                                 *               C.С����                *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("�������޸�ʳƷ�������Ӧ����ĸ��\n");
		scanf_s("%s", ch_5,10);
		rewind(stdin);

		if (strcmp(ch_5, "A") == 0)
		{
			FoodMC_D(phead);						//�����������޸�
			break;
		}
		else if (strcmp(ch_5, "B") == 0)
		{
			FoodMC_M(phead);						//������ʳ���޸�
			break;
		}
		else if (strcmp(ch_5, "C") == 0)
		{
			FoodMC_S(phead);						//����С�����޸�
			break;
		}
		else
		{
			if (Err_N == 3)
			{
				//�����������ﵽ3�κ󷵻���һ����
				system("cls");
				printf("\n");
				printf("Sorry,�����������Ѵ����ޣ�3�Σ������Ժ����ԡ�-_-\n");
				Sleep(2000);		//����������ͣ������
				FoodM_M(head_3);				//���½���ʳƷ��Ϣ����
			}
			else
			{
				system("cls");
				printf("\n");
				printf("Sorry,����������������룺-_-\n");
				Sleep(2000);				//����ͣ��2��
				Err_N++;			//ͬ��
			}
		}
	}
	return;
}
void FoodMC_D(Fastfood* head_g)
{
	int i = 0;										//ѭ������
	char Food_M[20] = { 0 };					    //�洢����Ա�޸ĵ�ʳƷ����Ϣ
	//���� Static �����˳��ú������ĳһ�����ļ�¼��ʧ
	static int Err_7 = 0;							 //�洢����Ա�޸�ͬһʳƷ����
	static char ch_b[100][50] = { 0 };				//���ѹ���Ա�ظ��޸�

	Fastfood* pmove = NULL;							//����ֱ���ƶ�ͷָ��
	pmove = head_g->next;

	while (1)
	{
		system("cls");									//�����Ż�
		printf("\n");
		printf("                                             �������ʳƷ�ı��            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                 D1001                 *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                 D1002                 *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                 D1003                 *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("�������޸�ʳƷ�ı�ţ�\n");
		scanf_s("%s", Food_M,20);
		rewind(stdin);

		for (i = 0;i < Err_7;i++)				//ͬ��
		{
			if (strcmp(ch_b[i], Food_M) == 0)
			{
				system("cls");
				printf("\n");
				printf("���ѣ����޸Ĺ���ʳƷ�������ظ��޸ġ�-_-\n");
				Sleep(2000);			//����ͣ������
				system("cls");
				FoodM_M(head_g);			//���½���ʳƷ��Ϣ����
			}
			else
			{
				continue;
			}
		}

		pmove = head_g;							//����һ�����Ҫ����ָ��ͷ���
		while (pmove->next != NULL)
		{
			if (strcmp(Food_M, pmove->F_ID) == 0)
			{
				//���޸ĵı�Ŵ洢���������������ظ��޸�
				strcpy_s(ch_b[Err_7], 20, pmove->F_ID);
				printf("�������ʳƷ�޸ĺ�ı�ţ�\n");
				scanf_s("%s", pmove->F_ID, 20);
				rewind(stdin);
				printf("�������ʳƷ�޸ĺ�����ƣ�\n");
				scanf_s("%s", pmove->F_Name, 20);
				rewind(stdin);
				printf("�������ʳƷ�޸ĺ�ĵ��ۣ�\n");
				scanf_s("%s", pmove->F_Price,10);
				rewind(stdin);
				printf("�������ʳƷ�޸ĺ�Ŀ�棺\n");
				scanf_s("%d", &pmove->F_Save);
				rewind(stdin);

				system("cls");
				printf("\n");
				printf("Perfect����� -%s- ����Ӧ��ʳƷ��Ϣ�޸ĳɹ���-_-\n", Food_M);
				Sleep(2000);
				Err_7++;			//ͬ��
				FoodM_M(head_g);				//�޸ĳɹ������½���ʳƷ��Ϣ����	
			}
			pmove = pmove->next;
		}
		system("cls");
		printf("\n");
		printf("Sorry,����û��ʳƷ�ı����������ı��ƥ�䡣-_-\n");
		Sleep(2000);
		FoodM_M(head_g);				//û�и�ʳƷ���½���ʳƷ��Ϣ����	
	}
}
void FoodMC_M(Fastfood *head_h)
{
	int i = 0;											 //ѭ������
	char Food_M[20] = { 0 };							 //�洢����Ա�޸ĵ�ʳƷ����Ϣ
	//���� Static �����˳��ú������ĳһ�����ļ�¼��ʧ
	static int Err_8 = 0;							 //�洢����Ա�޸�ͬһʳƷ����
	static char ch_b[100][50] = { 0 };				 //���ѹ���Ա�ظ��޸�

	Fastfood* pmove = NULL;									//����ֱ���ƶ�ͷָ��
	pmove = head_h->next;

	while (1)
	{
		system("cls");									//�����Ż�
		printf("\n");
		printf("                                             ��ʳ���ʳƷ�ı��            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                 M1001                 *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                 M1002                 *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                 M1003                 *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("�������޸�ʳƷ�ı�ţ�\n");
		scanf_s("%s", Food_M, 20);
		rewind(stdin);

		for (i = 0;i < Err_8;i++)
		{
			if (strcmp(ch_b[i], Food_M) == 0)
			{
				system("cls");
				printf("\n");
				printf("���ѣ����޸Ĺ���ʳƷ�������ظ��޸ġ�-_-\n");
				Sleep(2000);
				system("cls");
				FoodM_M(head_h);				//���½���ʳƷ��Ϣ����	
			}
			else
			{
				continue;
			}
		}

		//����BUG �����޸����һ�����
		pmove = head_h;							//����һ�����Ҫ����ָ��ͷ���
		while (pmove->next != NULL)
		{
			if (strcmp(Food_M, pmove->F_ID) == 0)
			{
				//���޸ĵı�Ŵ洢���������������ظ��޸�
				strcpy_s(ch_b[Err_8],20, pmove->F_ID);
				printf("�������ʳƷ�޸ĺ�ı�ţ�\n");
				scanf_s("%s", pmove->F_ID, 20);
				rewind(stdin);
				printf("�������ʳƷ�޸ĺ�����ƣ�\n");
				scanf_s("%s", pmove->F_Name, 20);
				rewind(stdin);
				printf("�������ʳƷ�޸ĺ�ĵ��ۣ�\n");
				scanf_s("%s", pmove->F_Price, 10);
				rewind(stdin);
				printf("�������ʳƷ�޸ĺ�Ŀ�棺\n");
				scanf_s("%d", &pmove->F_Save);
				rewind(stdin);

				system("cls");
				printf("\n");
				printf("Perfect����� -%s- ����Ӧ��ʳƷ��Ϣ�޸ĳɹ���-_-\n", Food_M);
				Sleep(2000);			//ͬ��
				Err_8++;
				FoodM_M(head_h);				//�޸ĳɹ������½���ʳƷ��Ϣ����	
			}
			pmove = pmove->next;
		}
		system("cls");
		printf("\n");
		printf("Sorry,����û��ʳƷ�ı����������ı��ƥ�䡣-_-\n");
		Sleep(2000);
		FoodM_M(head_h);				//�޸ĳɹ������½���ʳƷ��Ϣ����	
	}
}
void FoodMC_S(Fastfood *head_i)
{
	int i = 0;											  //ѭ������
	char Food_M[20] = { 0 };							  //�洢����Ա�޸ĵ�ʳƷ����Ϣ
	//���� Static �����˳��ú������ĳһ�����ļ�¼��ʧ
	static int Err_9 = 0;							  //�洢����Ա�޸�ͬһʳƷ����
	static char ch_b[100][50] = { 0 };				 //���ѹ���Ա�ظ��޸�

	Fastfood* pmove = NULL;								//����ֱ���ƶ�ͷָ��
	pmove = head_i->next;

	while (1)
	{
		system("cls");									//�����Ż�
		printf("\n");
		printf("                                             С�����ʳƷ�ı��            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                 S1001                 *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                 S1002                 *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                 S1003                 *\n");
		printf("                                 *---------------------------------------*\n");
		printf("�������޸�ʳƷ�ı�ţ�\n");
		scanf_s("%s", Food_M, 20);
		rewind(stdin);

		for (i = 0;i < Err_9;i++)			//ͬ��
		{
			if (strcmp(ch_b[i], Food_M) == 0)
			{
				system("cls");
				printf("\n");
				printf("���ѣ����޸Ĺ���ʳƷ�������ظ��޸ġ�-_-\n");
				Sleep(2000);
				system("cls");
				FoodM_M(head_i);				//�޸ĳɹ������½���ʳƷ��Ϣ����	
			}
			else
			{
				continue;
			}
		}

		//����BUG �����޸����һ�����
		pmove = head_i;							//����һ�����Ҫ����ָ��ͷ���
		while (pmove!= NULL)
		{
			if (strcmp(Food_M, pmove->F_ID) == 0)
			{
				//���޸ĵı�Ŵ洢���������������ظ��޸�
				strcpy_s(ch_b[Err_9], 11, pmove->F_ID);
				printf("�������ʳƷ�޸ĺ�ı�ţ�\n");
				scanf_s("%s", pmove->F_ID, 20);
				rewind(stdin);
				printf("�������ʳƷ�޸ĺ�����ƣ�\n");
				scanf_s("%s", pmove->F_Name, 20);
				rewind(stdin);
				printf("�������ʳƷ�޸ĺ�ĵ��ۣ�\n");
				scanf_s("%s", pmove->F_Price,10);
				rewind(stdin);
				printf("�������ʳƷ�޸ĺ�Ŀ�棺\n");
				scanf_s("%d", &pmove->F_Save);
				rewind(stdin);

				system("cls");
				printf("\n");
				printf("Perfect����� -%s- ����Ӧ��ʳƷ��Ϣ�޸ĳɹ���-_-\n", Food_M);
				Sleep(2000);			//ͬ��
				Err_9++;
				FoodM_M(head_i);				//�޸ĳɹ������½���ʳƷ��Ϣ����	
			}
			pmove = pmove->next;
		}
		system("cls");
		printf("\n");
		printf("Sorry,����û��ʳƷ�ı����������ı��ƥ�䡣-_-\n");
		Sleep(2000);
		FoodM_M(head_i);				//�޸�ʳƷ���½���ʳƷ��Ϣ����	
	}
}

void FoodM_See(Fastfood* head_4)					 //ʳƷ��Ϣ�鿴
{
	int i = 0;										//ѭ������
	int Num = 1;									//�ݴ���
	double  Food_P= 0.0;						   //ʳƷ����
	char Food_M[20] = { 0 };					   //�洢����Ա��ѯ��ʳƷ����Ϣ
	char ch_1[10] = { 0 };						   //����Ա����
	//���� Static �����˳��ú������ĳһ�����ļ�¼��ʧ
	static int Err_10 = 0;						  //�洢����Ա��ѯͬһʳƷ����
	static char ch_b[100][50] = { 0 };			   //���ѹ���Ա�ظ���ѯ
												
	Fastfood* pmove = NULL;						 //����ֱ���ƶ�ͷָ��
	pmove = head_4->next;

	while (1)
	{
		system("cls");									//�����Ż�
		printf("\n");
		printf("                                             ����ʳƷ�Ļ�����Ϣ            \n");
		printf("                                 -----------------------------------------\n");
		printf("                                 *                ʳƷ����               *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                ʳƷ���               *\n");
		printf("                                 *                                       *\n");
		printf("                                 *                ʳƷ����               *\n");
		printf("                                 *                                       *\n");
		printf("                                 *---------------------------------------*\n");

		printf("��ʾ��\n");
		printf("      �������룺��D1001���򣨰��¿��֣���5.00��\n");
		printf("\n");
		printf("�������ѯʳƷ�ľ�����Ϣ��\n");
		scanf_s("%s", Food_M, 20);
		rewind(stdin);

		//�����ܹ���ʳƷ���ж��ֲ�ѯ,���Թ���Ա�����ظ���ѯ
		for (i = 0;i < Err_10;i++)
		{
			if (strcmp(ch_b[i], Food_M) == 0)
			{
				system("cls");
				printf("\n");

				while (1)
				{
					printf("���ѣ����ظ���ѯ����ʳƷ���Ƿ������ѯ����Y or y || N or n )-_-\n");
					scanf_s("%s", ch_1, 10);
					rewind(stdin);						//��ջ����������������������

					//�ظ���ѯ����
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
								printf("��� --%s-- ����ӦʳƷ����ϸ��Ϣ���£�-_-\n", pmove->F_ID);
								printf("\n");
								printf("ʳƷ��ţ�%s \n", pmove->F_ID);
								printf("ʳƷ���ƣ�%s\n", pmove->F_Name);
								printf("ʳƷ���ۣ�%.2lf Ԫ\n", Food_P);
								printf("ʳƷ��棺%d ��\n", pmove->F_Save);
								break;
							}
							pmove = pmove->next;
						}
						printf("\n");
						system("pause");				//����Աѡ��ͣ��ʱ��
						FoodM_M(head_4);				//���½���ʳƷ��Ϣ����
					}
					else if (strcmp(ch_1, "N") == 0 || strcmp(ch_1, "n") == 0)
					{
						FoodM_M(head_4);					//���½���ʳƷ��Ϣ����
					}
					else
					{
						if (Num == 3)
						{
							system("cls");
							printf("\n");
							printf("Sorry,�����������Ѵ�����(3��),���Ժ����ԡ�-_-\n");
							Sleep(2000);
							Mainmenu(head_4);			//�������ﵽ3�κ�ֱ�ӽ������˵�
						}
						system("cls");
						printf("\n");
						printf("Sorry,����������������룺-_-\n");
						Sleep(2000);				//����ͣ��2��
						Num++;			//ͬ��
					}
				}
			}
			else					//ͬ��
			{
				continue;
			}
		}

		while (pmove != NULL)				//�����ڿ��Բ�ѯ�������Ϣ
		{
			if (strcmp(Food_M, pmove->F_ID) == 0)
			{
				strcpy_s(ch_b[Err_10], 20, pmove->F_ID);
				system("cls");

				Food_P = atof(pmove->F_Price);					//�ַ�����ת������
				printf("\n");
				printf("��� --%s-- ����ӦʳƷ����ϸ��Ϣ���£�-_-\n", pmove->F_ID);
				printf("\n");
				printf("ʳƷ��ţ�%s \n", pmove->F_ID);
				printf("ʳƷ���ƣ�%s\n", pmove->F_Name);
				printf("ʳƷ���ۣ�%.2lf Ԫ\n", Food_P);
				printf("ʳƷ��棺%d ��\n", pmove->F_Save);
				printf("\n");
				system("pause");			//����Աѡ��ͣ��ʱ��
				Err_10++;
				FoodM_M(head_4);					//���½���ʳƷ��Ϣ����
			}
			else if (strcmp(Food_M, pmove->F_Name) == 0)
			{
				strcpy_s(ch_b[Err_10], 20, pmove->F_Name);
				system("cls");

				Food_P = atof(pmove->F_Price);			//�ַ�����ת������
				printf("\n");
				printf("���� --%s-- ����ӦʳƷ����ϸ��Ϣ���£�-_-\n",pmove->F_Name);
				printf("\n");
				printf("ʳƷ��ţ�%s \n", pmove->F_ID);
				printf("ʳƷ���ƣ�%s\n", pmove->F_Name);
				printf("ʳƷ���ۣ�%.2lf Ԫ\n", Food_P);
				printf("ʳƷ��棺%d ��\n", pmove->F_Save);
				printf("\n");
				system("pause");				//����Աѡ��ͣ��ʱ��
				Err_10++;

				FoodM_M(head_4);					//���½���ʳƷ��Ϣ����
			}
			else if (strcmp(Food_M, pmove->F_Price) == 0)
			{
				strcpy_s(ch_b[Err_10],10, pmove->F_Price);
				system("cls");

				Food_P = atof(pmove->F_Price);
				printf("\n");
				printf("���� --%.2f-- Ԫ����ӦʳƷ����ϸ��Ϣ���£�-_-\n", Food_P);
				printf("\n");
				printf("ʳƷ��ţ�%s \n", pmove->F_ID);
				printf("ʳƷ���ƣ�%s\n", pmove->F_Name);
				printf("ʳƷ���ۣ�%.2lf Ԫ\n", Food_P);
				printf("ʳƷ��棺%d ��\n", pmove->F_Save);
				printf("\n");
				system("pause");				//����Աѡ��ͣ��ʱ��
				Err_10++;
				FoodM_M(head_4);					//���½���ʳƷ��Ϣ����
			}
			pmove = pmove->next;
		}
		
		system("cls");
		printf("\n");
		printf("Sorry,����û����Ҫ��ѯ��ʳƷ��-_-\n");
		Sleep(2000);			//ͬ��
		FoodM_M(head_4);	   //û�и�ʳƷ���½���ʳƷ��Ϣ����
	}
}	

void FoodM_Sav(Fastfood* head_5)			 //ʳƷ��Ϣ����
{
	double  P = 0.0;						//�洢�ַ���ת��������
	FILE* pfile = NULL;
	Fastfood* phead = NULL;
	phead = head_5->next;					//����ֱ���ƶ�ͷ���

	//��ʼ���ļ�����������
	if (fopen_s(&pfile, "Fastfood_M.txt", "w+") != NULL)       //��ȷ�򿪷���0�����򷵻ط���
	{
		printf("�ļ���ʧ�ܣ����˳�����");
		exit(1);
	}

	while (pfile != NULL)
	{
		fprintf(pfile, "��������ʳƷ�Ļ�����Ϣ������ʾ��\n");
		fprintf(pfile, "\n");                                    //��θ�
		while (phead != NULL)
		{
			P = atof(phead->F_Price);								//���ַ���ת��Ϊ������
			fprintf(pfile, "                                    ʳƷ��ţ�%s            \n", phead->F_ID);
			fprintf(pfile, "                                    ʳƷ���ƣ�%s            \n", phead->F_Name);
			fprintf(pfile, "                                    ʳƷ���ۣ�%.2lf Ԫ       \n", P);
			fprintf(pfile, "                                    ʳƷ��棺%d ��         \n", phead->F_Save);
			phead = phead->next;
			fprintf(pfile, "\n");
		}
		break;			//�˳�ѭ�������������ѭ��
	}
	//�򿪺�һ���ü�ʱ�ر��ļ������ⶪʧ����
	while (pfile != NULL)
	{
		rewind(pfile);                               //ʹ�ļ�ָ��ָ���ļ���ͷ
		fclose(pfile);
		break;
	}

	system("cls");
	printf("\n");
	printf("Perfect,��������ʳƷ����ϸ��Ϣ�Ѿ������ļ� Fastfood_M ����ע��鿴��-_-\n");
	Sleep(2000);				//ͣ��2��
	FoodM_M(head_5);			//����ʳƷ��Ϣ����
}

void FoodR_S(Fastfood* head_B)					//ʳƷ��������
{
	int i = 0;									//ѭ������
	int Num = 0;								//���ڼ���˿͹���ķ���
	//int Err = 0;							    //�ݴ���
	int Err_N = 1;								//�ݴ����

	int FoodB_C[10] = { 0 }; 					//����ʳƷ����
	double  Cash_C = 0.0;						//�˿������ֽ�
	double  Cash_R = 0.0;						//�˿��ֽ�����
	double  Food_P[9] = { 0.0 };				//ʳƷ���ۼ�
	double  FoodP_S = 0.0;						//�˿�һ�ι���ʳƷ�ļ۸��ܼ�

	char ch_1[10] = { 0 };						//�˿������ݴ���
	char FoodB_M[20] = { 0 };					//����ʳƷ����Ϣ�����ơ���ţ�
	char FoodB_N[100][20] = { 0 };			    //����ʳƷ������

	//���� Static �����˳��ú������ĳһ�����ļ�¼��ʧ
	static  int Buy_N = 0;						 //�洢�������
	static  int Food_R[9] = { 0 };				 //��ʳƷ������
	static double  FoodM_SR[9] = { 0 };			 //��ʳƷ�����ܽ��
	static  int FoodC_SR[3] = { 0 };			 //������ʳƷ������
	static double  FoodCM_SR[3] = { 0 };		 //������ʳƷ�����ܽ��

	int year = 0, mon = 0, day = 0,hour=0,min=0,sec=0;		//��������ʱ��
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

	//������������������Ӵ�����
	int FoodS_N[9] = { 200,150,200,300,350,400,250,200,200 };				//�洢ÿ��ʳƷ�Ŀ��
	double  Fastfood_[9][7] = { 5.00,6.00,7.00,10.00,15.00,8.00,5.00,4.00,7.00 };
	char Fastfood_C[18][20] = { "���¿���","D1001","��ե��֭","D1002","ţ���̲�","D1003",
							"��������","M1001","��ସǷ�","M1002","���ݳ���","M1003",
							"�������","S1001","��������","S1002","��Ӱţ��","S1003" };
	Fastfood* pmove = NULL;
	pmove = head_B->next;							     	//����ֱ���ƶ�ͷ���

	while (1)
	{
		system("cls");
		pmove = head_B->next;								//����һ�����Ҫ����ָ��ͷ���
		printf("��ʾ��\n����˿Ͳ���ѡ����������ĸ R �� r �˳�ѡʳƷ���棬�����²������� -_-\n");
		printf("\n");
		printf("                                               ����ʳƷ�嵥������ʾ         \n");
		printf("                                 ---------------------------------------------\n");
		printf("                                 *    D1001	    M1001          S1001     *\n");
		printf("                                 *    ���¿���      ��������       �������  *\n");
		printf("                                 *-------------------------------------------*\n");
		printf("                                 *    D1002         M1002          S1002     *\n");
		printf("                                 *    ��ե��֭      ��ସǷ�	   ��������  *\n");
		printf("                                 *-------------------------------------------*\n");
		printf("                                 *    D1003         M1003          S1003     *\n");
		printf("                                 *    ţ���̲�      ���ݳ���       ��Ӱţ��  *\n");
		printf("                                 *-------------------------------------------*\n");

		printf("\n");
		printf("������˿͹���ʳƷ����Ӧ�ı�Ż����ƣ�\n");
		scanf_s("%s", FoodB_M, 20);
		rewind(stdin);

		if (strcmp(FoodB_M, "R") == 0 || strcmp(FoodB_M, "r") == 0)
		{
			if (Num == 0)
			{
				Mainmenu(head_B);				//��ζ�Ź˿Ͳ��Ṻ��ʳƷ
			}
			else
			{
				break;
			}
		}

		for (i = 0;i < 18;i++)							//��鱾���Ƿ��и�ʳƷ
		{
			if (strcmp(FoodB_M, Fastfood_C[i]) != 0)
			{
				continue;
			}
			else
			{
				strcpy_s(FoodB_N[Num], 20, FoodB_M);

				Num++;												//��ʳƷ��������һ
				break;
			}
		}

		if (i == 18)				//�� i Ϊ18ʱ˵��û�������ʳƷ
		{
			system("cls");
			printf("\n");
			printf("Sorry,����û������ѡ��ʳƷ��������ѡ��-_-\n");
			Sleep(2000);			//ͣ������
			continue;
		}

		else				//����˵���и�ʳƷ
		{
			system("cls");
			printf("\n");
			printf("������˿͹���ʳƷ %s �ķ�����\n", FoodB_M);
			scanf_s("%d", &FoodB_C[Num - 1]);
			rewind(stdin);
			/*do				//��ֹ�û�������������
			{
				system("cls");
				printf("\n");
				printf("������˿͹���ʳƷ %s �ķ�����\n", FoodB_M);
				scanf_s("%d", &FoodB_C[Num - 1]);	//ʵ���ǹ���ĵ�һ��ʳƷ������������ Num-1
				Err = getchar();               //�����ж������Ƿ�������,������Ǽ�������
				while (getchar() != '\n');	//	���ջس�������Ҫ�����λس��Ż�¼��ɹ�
				if (Err != 10)				//˵������������ּ���ĸ
				{
					system("cls");
					printf("\n");
					printf("Sorry,����������������������룡-_-\n");
					Sleep(2000);
				}
			} while (Err != 10);*/
			for (i = 0;i < 9;i++)			//�жϹ˿͹����ʳƷ�Ƿ��治��
			{
				if (FoodB_C[Num - 1] > FoodS_N[i] - Food_R[i])//�ܷݼ�ȥ����
				{
					system("cls");
					printf("\n");
					printf("Sorry,��ʳƷ��治�㣬�빺������ʳƷ��-_- \n");
					Sleep(2000);				//����ͣ��2��
					FoodR_S(head_B);		    //���½���ѡʳƷ����
				}
				else
				{
					continue;
				}
			}

			if (FoodB_C[Num-1] > 50 || FoodB_C[Num-1] < 1)		//��������һ���˿���๺��50��
			{
				system("cls");
				printf("\n");
				printf("Sorry,����������������������룡-_-\n");
				Sleep(1000);				//����׶�ֻͣ��1��
				FoodR_S(head_B);		    //���½���ѡʳƷ����
			}
			
			else
			{
				system("cls");
				printf("\n");
				printf("Perfect,�˿͹���ʳƷ����Ϣ¼��ɹ�����\n");
				Sleep(1500);						//����ͣ��1.5��
			}
		}
	}
	//�˿��˵���ϸ�������
	for (i = 0;i < Num;i++)
	{
		if (strcmp(FoodB_N[i], Fastfood_C[0]) == 0||strcmp(FoodB_N[i], Fastfood_C[1]) == 0)
		{
			//�������۽׶�
			strcpy_s(FoodB_N[i], 20,"���¿���");
			Food_P[i] = 5.00;
			FoodP_S = FoodP_S + 5.00 * FoodB_C[i];
			//����ͳ�ƽ׶�
			//Food_R[0]+= FoodB_C[i];						//��������
			Food_R[0]= Food_R[0]+ FoodB_C[i];				//������һ
			FoodC_SR[0]= FoodC_SR[0]+ FoodB_C[i];
			FoodM_SR[0] = FoodM_SR[0] + 5.00 * FoodB_C[i];				//���۽��Ӻ�
			FoodCM_SR[0] = FoodCM_SR[0] + 5.00 * FoodB_C[i];
		}
		else if (strcmp(FoodB_N[i], Fastfood_C[2]) == 0 || strcmp(FoodB_N[i], Fastfood_C[3]) == 0)
		{
			strcpy_s(FoodB_N[i],20,"��ե��֭");
			Food_P[i] = 6.00;
			FoodP_S = FoodP_S + 6.00 * FoodB_C[i];
			//����ͳ�ƽ׶�
			Food_R[1] = Food_R[1] + FoodB_C[i];				//������һ
			FoodC_SR[0] = FoodC_SR[0] + FoodB_C[i];
			FoodM_SR[1] = FoodM_SR[1] + 6.00 * FoodB_C[i];				//���۽��Ӻ�
			FoodCM_SR[0] = FoodCM_SR[0] + 6.00 * FoodB_C[i];
		}
		else if (strcmp(FoodB_N[i], Fastfood_C[4]) == 0 || strcmp(FoodB_N[i], Fastfood_C[5]) == 0)
		{
			strcpy_s(FoodB_N[i],20, "ţ���̲�");
			Food_P[i] = 7.00;
			FoodP_S = FoodP_S + 7.00 * FoodB_C[i];
			//����ͳ�ƽ׶�
			Food_R[2] = Food_R[2] + FoodB_C[i];				//������һ
			FoodC_SR[0] = FoodC_SR[0] + FoodB_C[i];
			FoodM_SR[2] = FoodM_SR[2] + 7.00 * FoodB_C[i];				//���۽��Ӻ�
			FoodCM_SR[0] = FoodCM_SR[0] + 7.00 * FoodB_C[i];
		}
		else if (strcmp(FoodB_N[i], Fastfood_C[6]) == 0 || strcmp(FoodB_N[i], Fastfood_C[7]) == 0)
		{
			strcpy_s(FoodB_N[i],20, "��������");
			Food_P[i] = 10.00;
			FoodP_S = FoodP_S + 10.00 * FoodB_C[i];
			//����ͳ�ƽ׶�
			Food_R[3] = Food_R[3] + FoodB_C[i];				//������һ
			FoodC_SR[1] = FoodC_SR[1] + FoodB_C[i];
			FoodM_SR[3] = FoodM_SR[3] + 10.00 * FoodB_C[i];				//���۽��Ӻ�
			FoodCM_SR[1] = FoodCM_SR[1] + 10.00 * FoodB_C[i];
		}
		else if (strcmp(FoodB_N[i], Fastfood_C[8]) == 0 || strcmp(FoodB_N[i], Fastfood_C[9]) == 0)
		{
			strcpy_s(FoodB_N[i],20, "��ସǷ�");
			Food_P[i] = 15.00;
			FoodP_S = FoodP_S + 15.00 * FoodB_C[i];
			//����ͳ�ƽ׶�
			Food_R[4] = Food_R[4] + FoodB_C[i];				//������һ
			FoodC_SR[1] = FoodC_SR[1] + FoodB_C[i];
			FoodM_SR[4] = FoodM_SR[4] + 15.00 * FoodB_C[i];				//���۽��Ӻ�
			FoodCM_SR[1] = FoodCM_SR[1] + 15.00 * FoodB_C[i];
		}
		else if (strcmp(FoodB_N[i], Fastfood_C[10]) == 0 || strcmp(FoodB_N[i], Fastfood_C[11]) == 0)
		{
			strcpy_s(FoodB_N[i],20, "���ݳ���");
			Food_P[i] = 8.00;
			FoodP_S = FoodP_S + 8.00 * FoodB_C[i];
			//����ͳ�ƽ׶�
			Food_R[5] = Food_R[5] + FoodB_C[i];				//������һ
			FoodC_SR[1] = FoodC_SR[1] + FoodB_C[i];
			FoodM_SR[5] = FoodM_SR[5] + 8.00 * FoodB_C[i];				//���۽��Ӻ�
			FoodCM_SR[1] = FoodCM_SR[1] + 8.00 * FoodB_C[i];
		}
		else if (strcmp(FoodB_N[i], Fastfood_C[12]) == 0 || strcmp(FoodB_N[i], Fastfood_C[13]) == 0)
		{
			strcpy_s(FoodB_N[i],20, "�������");
			Food_P[i] = 5.00;
			FoodP_S = FoodP_S + 5.00 * FoodB_C[i];
			//����ͳ�ƽ׶�
			Food_R[6] = Food_R[6] + FoodB_C[i];				//������һ
			FoodC_SR[2] = FoodC_SR[2] + FoodB_C[i];
			FoodM_SR[6] = FoodM_SR[6] + 5.00 * FoodB_C[i];				//���۽��Ӻ�
			FoodCM_SR[2] = FoodCM_SR[2] + 5.00 * FoodB_C[i];
		}
		else if (strcmp(FoodB_N[i], Fastfood_C[14]) == 0 || strcmp(FoodB_N[i], Fastfood_C[15]) == 0)
		{
			strcpy_s(FoodB_N[i],20, "��������");
			Food_P[i] = 4.00;
			FoodP_S = FoodP_S + 4.00 * FoodB_C[i];
			//����ͳ�ƽ׶�
			Food_R[7] = Food_R[7] + FoodB_C[i];				//������һ
			FoodC_SR[2] = FoodC_SR[2] + FoodB_C[i];
			FoodM_SR[7] = FoodM_SR[7] + 4.00 * FoodB_C[i];				//���۽��Ӻ�
			FoodCM_SR[2] = FoodCM_SR[2] + 4.00 * FoodB_C[i];
		}
		else if (strcmp(FoodB_N[i], Fastfood_C[16]) == 0 || strcmp(FoodB_N[i], Fastfood_C[17]) == 0)
		{
			strcpy_s(FoodB_N[i],20, "��Ӱţ��");
			Food_P[i] = 7.00;
			FoodP_S = FoodP_S + 7.00 * FoodB_C[i];
			//����ͳ�ƽ׶�
			Food_R[8] = Food_R[8] + FoodB_C[i];				//������һ
			FoodC_SR[2] = FoodC_SR[2] + FoodB_C[i];
			FoodM_SR[8] = FoodM_SR[8] + 7.00 * FoodB_C[i];				//���۽��Ӻ�
			FoodCM_SR[2] = FoodCM_SR[2] + 7.00 * FoodB_C[i];
		}
	}
	
	while (1)								//׼�������ϸ�˵�
	{
		system("cls");
		printf("\n");
		printf("�˿�Ӧ�����Ϊ��\n");
		printf("                 %.2lf  Ԫ\n", FoodP_S);
		printf("\n");
		printf("������˿�֧����\n");
		scanf_s("%lf", &Cash_C);
		rewind(stdin);

		if (Cash_C < FoodP_S)
		{
			system("cls");
			printf("\n");
			printf("Sorry,�������������������룡-_-\n");
			Sleep(1000);			//����ͣ��1��
			continue;
		}
		break;
	}

	Cash_R = Cash_C - FoodP_S;						//������ 
	Sleep(1000);			
	system("cls");
	printf("\n");
	printf("Perfect,�˿������˵���ϸ���ڴ�ӡ�С���   -_-\n");
	Sleep(2500);										//ͣ��2.5���ӡ�˵�
	system("cls");
	Buy_N++;					//����ĵ��ݼ�������һ ��ÿλ�˿͵ĵ��ݲ�ͬ
	printf("\n");
	printf("                           *****************************************************\n");
	printf("                           *****************************************************\n");
	printf("                           *                    ����ζ����ʳ                   *\n");
	printf("                           *                                                   *\n");
	printf("                           * %d-%02d-%02d %02d:%02d:%02d                               *\n",year,mon,day,hour,min,sec);
	printf("                           *___________________________________________________*\n");
	printf("                           *---------------------------------------------------*\n");
	printf("                           *              ��ִ�СƱ��ȡ�Ϳ�ȡ�ͣ�����         *\n");
	printf("                           *___________________________________________________*\n");
	printf("                           *---------------------------------------------------*\n");
	printf("                           * �վݺţ�%04u                                      *\n", Buy_N);
	printf("                           * �տ�Ա��ҦԴ��                                    *\n");
	printf("                           *___________________________________________________*\n");
	printf("                           *---------------------------------------------------*\n");
	printf("                           * ����                 ����                  ����   *\n");
	printf("                           *___________________________________________________*\n");
	printf("                           *---------------------------------------------------*\n");
	for (i = 0;i < Num;i++)				//ѭ������˿͹����ʳƷ
	{
		printf("                           * %-4s              %-2u                  %6.2f  *\n",
			FoodB_N[i], FoodB_C[i], Food_P[i]);
	}
	printf("                           *___________________________________________________*\n");
	printf("                           *---------------------------------------------------*\n");
	printf("                           * �ϼ�                                      %6.2lf  *\n", FoodP_S);
	printf("                           * �ֽ�                                      %6.2lf  *\n", Cash_C);
	printf("                           * ����                                      %6.2lf  *\n", Cash_R);
	printf("                           *___________________________________________________*\n");
	printf("                           *---------------------------------------------------*\n");
	printf("                           *                     лл�ݹ�                      *\n");
	printf("                           *****************************************************\n");
	printf("                           *****************************************************\n");

	printf("\n");
	system("pause");
	while (1)
	{
		system("cls");
		printf("\n");
		printf("�����Ƿ���� %d-%02d-%02d ������ͳ�Ʋ�ѯ�� �� Y or y || N or n)\n",year,mon,day);
		scanf_s("%s", ch_1, 10);
		rewind(stdin);

		if (strcmp(ch_1, "Y") == 0 || strcmp(ch_1, "y") == 0)
		{				
			FoodS_T(Food_R, FoodM_SR, FoodC_SR, FoodCM_SR);	//����ͳ�Ʋ鿴
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
				printf("Sorry,�����������Ѵ����ޣ�3�Σ������Ժ����ԡ�-_-\n");
				Sleep(2000);
				FoodR_S(head_B);						//��������������			 
				break;
			}
			else
			{
				system("cls");
				printf("\n");
				printf("Sorry,����������������룺-_-\n");
				Sleep(2000);					//����ͣ��2��
				Err_N++;
			}
		}
	}

	Err_N = 1;								//�����½��棬��������λ
	while (1)
	{
		system("cls");
		printf("\n");
		printf("�����Ƿ������������ʳƷ�� �� Y or y || N or n)\n");
		scanf_s("%s", ch_1, 10);
		rewind(stdin);

		if (strcmp(ch_1, "Y") == 0 || strcmp(ch_1, "y")==0)
		{
			FoodR_S(head_B);						//������������
			break;
		}
		else if (strcmp(ch_1, "N") == 0 || strcmp(ch_1, "n") == 0)
		{
			Mainmenu(head_B);					 //�������˵�
			break;
		}
		else
		{
			if (Err_N == 3)
			{
				system("cls");
				printf("\n");
				printf("Sorry,�����������Ѵ����ޣ�3�Σ������Ժ����ԡ�-_-\n");
				Sleep(2000);			//����ͣ��2��
				Mainmenu(head_B);						 //�������˵�
			} 
			else
			{
				system("cls");
				printf("\n");
				printf("Sorry,����������������룺-_-\n");
				Sleep(2000);			//����ͣ��2��
				Err_N++;
			}
		}
	}
}

void FoodS_T(static int*Food_R1, static double* FoodM_SR2,static int* FoodC_SR1, static double* FoodCM_SR)
{
	int i = 0;
	double  FoodR_S = 0.0;
	char Fastfood_N[9][20] = { "���¿���","��ե��֭","ţ���̲�","��������","��ସǷ�",
		                      "���ݳ���","�������","��������","��Ӱţ��" };
	char Fastfood_C[3][20] = { "������","��ʳ��","С����" };

	int year = 0, mon = 0, day = 0;			//��ӡ��ʱ��ͳ�ƽ��
	time_t  timep = time(0);
	struct tm p;
	time(&timep);
	localtime_s(&p, &timep);
	year = 1900 + p.tm_year;
	mon = 1 + p.tm_mon;
	day = p.tm_mday;

	system("cls");
	printf("\n");
	printf(" %d��%02d��%02d�� ����ʳƷ����ͳ�����������ʾ��\n",year,mon,day);
	printf("\n");
	printf(" %d��%02d��%02d�� ����ʳƷ���������£�\n",year,mon,day);
	printf("\n");
	for (i = 0;i < 9;i++)
	{
		printf("%s ������Ϊ�� %d ��\n", Fastfood_N[i], Food_R1[i]);
	}
	printf("\n");
	printf("����ʳƷ�������ܶ����£�\n");
	printf("\n");
	for (i = 0;i < 9;i++)
	{
		printf("%s �������ܶ�Ϊ�� %.2lf Ԫ\n", Fastfood_N[i], FoodM_SR2[i]);
	}
	printf("\n");
	printf("������ʳƷ���������£�\n");
	printf("\n");
	for (i = 0;i < 3;i++)
	{
		printf("%s ������Ϊ�� %d ��\n", Fastfood_C[i], FoodC_SR1[i]);
	}
	printf("\n");
	printf("������ʳƷ�������ܶ����£�\n");
	printf("\n");
	for (i = 0;i < 3;i++)
	{
		printf("%s �������ܶ�Ϊ�� %.2lf Ԫ\n", Fastfood_C[i], FoodCM_SR[i]);
		FoodR_S = FoodR_S + FoodCM_SR[i];
	}
	printf("\n");
	printf(" %d��%02d��%02d�� ������Ϊ��%.2lf Ԫ\n", year,mon,day,FoodR_S);
	printf("\n");
	system("pause");				//����Աѡ��ͣ��ʱ��
}

int main()
{
	Login_S();									//��¼ϵͳ
	return 0;
}