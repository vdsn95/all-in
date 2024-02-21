#include<stdio.h>
#include<string.h>
#define A 10
#define B 3
void system(void);
void input(struct student* stud);
void show(struct student* stud);
void sort(struct student* stud);
void find1(struct student* stud);
void find2(struct student* stud);
void find3(struct student* stud);
void find(void);
void change1(struct student* stud);
void change2(struct student* stud);
void change3(struct student* stud);
void change(void);
void transition(void);
struct student
{
	long studentID;
	char studentname[A];
	int score;
};
struct student stu[B] = { 0,'\0',0 };
struct student* stud;
int a=0,b=0,c=0,i = 0,j=0,k=0,l=0,m=0;
char aa[A];
long d = 0;

int main()
{
	stud = stu;
	system();
	for (i = 0;; i++)
	{
		transition();
	}
	return 0;
}

//����
void system(void)
{
	printf("======��ӭʹ�ð༶�ۺϲ����ɼ�ϵͳ======\n");
	printf("1--¼��ȫ���ۺϲ����ɼ�\n");
	printf("2--��ʾȫ���ۺϲ����ɼ�\n");
	printf("3--ȫ���ۺϲ����ɼ�����\n");
	printf("4--�����ۺϲ����ɼ�\n");
	printf("5--�޸��ۺϲ����ɼ�\n");
	printf("0--�˳�ϵͳ\n");
}

//¼��
void input(struct student* stud)
{
	printf("������ѧ����ѧ�š��������ɼ�\n");
	for (i = 0; i < B; i++, stud++)
	{
		scanf_s("%ld", &stud->studentID);
		getchar();
		scanf_s("%s", stud->studentname, A);
		getchar();
		scanf_s("%d", &stud->score);
		getchar();
	}
	stud = stud - B;
}

//��ʾ
void show(struct student* stud)
{
	for (i = 0; i < B; i++, stud++)
	{
		printf("%02ld\t%s\t%02d\n", (*stud).studentID, (*stud).studentname, (*stud).score);
	}
}

//����
void sort(struct student* stud)
{
	struct student temp; 
	for (i = 0; i < B - 1; i++)
	{
		for (j = 0; j < B - 1 - i; j++)
		{
			if (stud[j].score < stud[j + 1].score)
			{
				temp = stud[j];
				stud[j] = stud[j + 1];
				stud[j + 1] = temp;
			}
		}
	}
}

//����
void find1(struct student* stud)
{
	for (i = 0; i < B; i++,stud++)
	{
		if ((*stud).score < 60)
		{
			printf("��ͬѧ��ϢΪ:\n");
			printf("%02ld\t%s\t%02d\n", (*stud).studentID, (*stud).studentname, (*stud).score);
		}
	}
}

//����
void find2(struct student* stud)
{
FIND:	printf("������ͬѧ����\n");
	scanf_s("%s", aa, A);
	for (i = 0; i < B; i++, stud++)
	{
		if (strcmp(aa, stud->studentname) == 0)
		{
			printf("%02ld\t%s\t%02d\n", (*stud).studentID, (*stud).studentname, (*stud).score);
			c++;
		}
	}
	if (c == 0)
		printf("���޴���\n");
	else
	{
		stud = stud - B;
		for (i = 0; i < A; i++)
		{
			aa[i] = '\0';
		}
		printf("����9�������ң����������\n");
		scanf_s("%d", &b);
		if (b == 9) 
		{
			b = 0;
			goto FIND;
		}
		c = 0;
	}
}

//����
void find3(struct student* stud)
{
FIND:printf("������������ҵ�ѧ�š�\n");
	scanf_s("%ld", &d);
	if (d == (*stud).studentID)
		printf("%02ld\t%s\t%02d\n", (*stud).studentID, (*stud).studentname, (*stud).score);
	d = 0;
	printf("����9�������ң����������\n");
	scanf_s("%d", &b);
	if (b == 9)
		goto FIND;
}

//����
void find(void)
{
	printf("����1���Ҳ�����ͬѧ\n");
	printf("����2ͨ����������ͬѧ\n");
	printf("����3ͨ��ѧ�Ų���ͬѧ\n");
    INPUT:scanf_s("%d", &a);
	if (a < 1 || a>3)
	{
		printf("�޶�Ӧ�Ĳ��������������롣\n");
		goto INPUT;
	}
	else
	switch (a)
	{
	case 1:
		find1(stud);
		break;
	case 2:
		find2(stud);
		break;
	case 3:
		find3(stud);
		break;
	}
}

//�޸�
void change1(struct student* stud)
{
	printf("�����������޸ĵ�ͬѧѧ��\n");
	scanf_s("%ld", &d);
	if (d == (*stud).studentID)
	{
		printf("��ͬѧ��ϢΪ:\n");
		printf("%02ld\t%s\t%02d\n", (*stud).studentID, (*stud).studentname, (*stud).score);
	}
	printf("����1�޸�ѧ��\n");
	printf("����2�޸�����\n");
	printf("����3�޸ĳɼ�\n");
	scanf_s("%d", &b);
	switch (b)
	{
	case 1:
		printf("������ѧ��ѧ��\n");
		scanf_s("%ld", &(*stud).studentID);
		break;
	case 2:
		printf("������ѧ������\n");
		scanf_s("%s", stud->studentname, A);
		break;
	case 3:
		printf("������ѧ���ɼ�\n");
		scanf_s("%d", &(*stud).score);
		break;
	}
}

//�޸�
void change2(struct student* stud)
{
	printf("�����������޸ĵ�ͬѧ����\n");
	scanf_s("%s", aa, A);
	for (i = 0; i < B; i++, stud++)
	{
		if (strcmp(aa, stud->studentname) == 0)
		{
			printf("��ͬѧ��ϢΪ:\n");
			printf("%02ld\t%s\t%02d\n", (*stud).studentID, (*stud).studentname, (*stud).score);
			printf("����1�޸�ѧ��\n");
			printf("����2�޸�����\n");
			printf("����3�޸ĳɼ�\n");
			scanf_s("%d", &b);
			switch (b)
			{
			case 1:
				printf("������ѧ��ѧ��\n");
				scanf_s("%ld", &(*stud).studentID);
				break;
			case 2:
				printf("������ѧ������\n");
				scanf_s("%s", stud->studentname, A);
				break;
			case 3:
				printf("������ѧ���ɼ�\n");
				scanf_s("%d", &(*stud).score);
				break;
			}
			c++;
		}
	}
	if (c == 0)
		printf("���޴���\n");
	c = 0;
}

//�޸�
void change3(struct student* stud)
{
INPUT:	printf("�����������޸ĵ�ͬѧ�ĳɼ�:\n");
	scanf_s("%d", &a);
	for (i = 0; i < B; i++, stud++)
	{
		if (a == (*stud).score)
		{
			printf("��ͬѧ��ϢΪ:\n");
			printf("%02ld\t%s\t%02d\n", (*stud).studentID, (*stud).studentname, (*stud).score);
			c++;
		}
	}
	stud = stud - B;
	if (c == 0)
	{
		printf("�޳ɼ�Ϊ%d��ͬѧ������������ɼ�\n",a);
		goto INPUT;
	}
	printf("����1�޸�ѧ��\n");
	printf("����2�޸�����\n");
	printf("����3�޸ĳɼ�\n");
SORT:	scanf_s("%d", &b);
	if (b < 1 || b>3)
	{
		printf("�޶�Ӧ�Ĳ��������������롣\n");
		goto SORT;
	}
	switch (b)
	{
	case 1:
		printf("������ѧ��ѧ��\n");
		scanf_s("%ld", &(*stud).studentID);
		break;
	case 2:
		printf("������ѧ������\n");
		scanf_s("%s", stud->studentname, A);
		break;
	case 3:
		printf("������ѧ���ɼ�\n");
		scanf_s("%d", &(*stud).score);
		break;
	}
}

//�޸�
void change(void)
{
	printf("����1ͨ��ѧ���޸�\n");
	printf("����2ͨ�������޸�\n");
	printf("����3ͨ���ɼ��޸�\n");
INPUT:scanf_s("%d", &a);
	if (a < 1 || a>3)
	{
		printf("�޶�Ӧ�Ĳ��������������롣\n");
		goto INPUT;
	}
	else
		switch (a)
		{
		case 1:
			change1(stud);
			break;
		case 2:
			change2(stud);
			break;
		case 3:
			change3(stud);
			break;
		}
}

//����
void transition(void)
{
INPUT:	printf("��������Ҫ�����Ĺ���\n");
	scanf_s("%d", &a);
	getchar();
	if (a < 0 || a>5)
	{
		printf("�޶�Ӧ�Ĳ��������������롣\n");
		goto INPUT;
	}
	else
	{
		switch (a)
		{
		case 1:
			printf("��ѡ��Ĺ�����:1\n");
			input(stud);
			break;
		case 2:
			printf("��ѡ��Ĺ�����:2\n");
			show(stud);
			break;
		case 3:
			printf("��ѡ��Ĺ�����:3\n");
			sort(stud);
			break;
		case 4:
			printf("��ѡ��Ĺ�����:4\n");
			find(stud);
			break;
		case 5:
			printf("��ѡ��Ĺ�����:5\n");
			change();
			break;
		case 0:
			printf("��ѡ��Ĺ�����:0\n");
			printf("��ӭ�´�ʹ��\n");
			exit(0);
		}
	}
}
