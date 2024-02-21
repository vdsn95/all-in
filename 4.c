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

//界面
void system(void)
{
	printf("======欢迎使用班级综合测评成绩系统======\n");
	printf("1--录入全班综合测评成绩\n");
	printf("2--显示全班综合测评成绩\n");
	printf("3--全班综合测评成绩排序\n");
	printf("4--查找综合测评成绩\n");
	printf("5--修改综合测评成绩\n");
	printf("0--退出系统\n");
}

//录入
void input(struct student* stud)
{
	printf("请输入学生的学号、姓名、成绩\n");
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

//显示
void show(struct student* stud)
{
	for (i = 0; i < B; i++, stud++)
	{
		printf("%02ld\t%s\t%02d\n", (*stud).studentID, (*stud).studentname, (*stud).score);
	}
}

//排序
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

//查找
void find1(struct student* stud)
{
	for (i = 0; i < B; i++,stud++)
	{
		if ((*stud).score < 60)
		{
			printf("该同学信息为:\n");
			printf("%02ld\t%s\t%02d\n", (*stud).studentID, (*stud).studentname, (*stud).score);
		}
	}
}

//查找
void find2(struct student* stud)
{
FIND:	printf("请输入同学姓名\n");
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
		printf("查无此人\n");
	else
	{
		stud = stud - B;
		for (i = 0; i < A; i++)
		{
			aa[i] = '\0';
		}
		printf("输入9继续查找，否则结束。\n");
		scanf_s("%d", &b);
		if (b == 9) 
		{
			b = 0;
			goto FIND;
		}
		c = 0;
	}
}

//查找
void find3(struct student* stud)
{
FIND:printf("请输入你想查找的学号。\n");
	scanf_s("%ld", &d);
	if (d == (*stud).studentID)
		printf("%02ld\t%s\t%02d\n", (*stud).studentID, (*stud).studentname, (*stud).score);
	d = 0;
	printf("输入9继续查找，否则结束。\n");
	scanf_s("%d", &b);
	if (b == 9)
		goto FIND;
}

//查找
void find(void)
{
	printf("输入1查找不及格同学\n");
	printf("输入2通过姓名查找同学\n");
	printf("输入3通过学号查找同学\n");
    INPUT:scanf_s("%d", &a);
	if (a < 1 || a>3)
	{
		printf("无对应的操作，请重新输入。\n");
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

//修改
void change1(struct student* stud)
{
	printf("请输入你想修改的同学学号\n");
	scanf_s("%ld", &d);
	if (d == (*stud).studentID)
	{
		printf("该同学信息为:\n");
		printf("%02ld\t%s\t%02d\n", (*stud).studentID, (*stud).studentname, (*stud).score);
	}
	printf("输入1修改学号\n");
	printf("输入2修改姓名\n");
	printf("输入3修改成绩\n");
	scanf_s("%d", &b);
	switch (b)
	{
	case 1:
		printf("请输入学生学号\n");
		scanf_s("%ld", &(*stud).studentID);
		break;
	case 2:
		printf("请输入学生姓名\n");
		scanf_s("%s", stud->studentname, A);
		break;
	case 3:
		printf("请输入学生成绩\n");
		scanf_s("%d", &(*stud).score);
		break;
	}
}

//修改
void change2(struct student* stud)
{
	printf("请输入你想修改的同学姓名\n");
	scanf_s("%s", aa, A);
	for (i = 0; i < B; i++, stud++)
	{
		if (strcmp(aa, stud->studentname) == 0)
		{
			printf("该同学信息为:\n");
			printf("%02ld\t%s\t%02d\n", (*stud).studentID, (*stud).studentname, (*stud).score);
			printf("输入1修改学号\n");
			printf("输入2修改姓名\n");
			printf("输入3修改成绩\n");
			scanf_s("%d", &b);
			switch (b)
			{
			case 1:
				printf("请输入学生学号\n");
				scanf_s("%ld", &(*stud).studentID);
				break;
			case 2:
				printf("请输入学生姓名\n");
				scanf_s("%s", stud->studentname, A);
				break;
			case 3:
				printf("请输入学生成绩\n");
				scanf_s("%d", &(*stud).score);
				break;
			}
			c++;
		}
	}
	if (c == 0)
		printf("查无此人\n");
	c = 0;
}

//修改
void change3(struct student* stud)
{
INPUT:	printf("请输入你想修改的同学的成绩:\n");
	scanf_s("%d", &a);
	for (i = 0; i < B; i++, stud++)
	{
		if (a == (*stud).score)
		{
			printf("该同学信息为:\n");
			printf("%02ld\t%s\t%02d\n", (*stud).studentID, (*stud).studentname, (*stud).score);
			c++;
		}
	}
	stud = stud - B;
	if (c == 0)
	{
		printf("无成绩为%d的同学，请重新输入成绩\n",a);
		goto INPUT;
	}
	printf("输入1修改学号\n");
	printf("输入2修改姓名\n");
	printf("输入3修改成绩\n");
SORT:	scanf_s("%d", &b);
	if (b < 1 || b>3)
	{
		printf("无对应的操作，请重新输入。\n");
		goto SORT;
	}
	switch (b)
	{
	case 1:
		printf("请输入学生学号\n");
		scanf_s("%ld", &(*stud).studentID);
		break;
	case 2:
		printf("请输入学生姓名\n");
		scanf_s("%s", stud->studentname, A);
		break;
	case 3:
		printf("请输入学生成绩\n");
		scanf_s("%d", &(*stud).score);
		break;
	}
}

//修改
void change(void)
{
	printf("输入1通过学号修改\n");
	printf("输入2通过姓名修改\n");
	printf("输入3通过成绩修改\n");
INPUT:scanf_s("%d", &a);
	if (a < 1 || a>3)
	{
		printf("无对应的操作，请重新输入。\n");
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

//过渡
void transition(void)
{
INPUT:	printf("请输入你要操作的功能\n");
	scanf_s("%d", &a);
	getchar();
	if (a < 0 || a>5)
	{
		printf("无对应的操作，请重新输入。\n");
		goto INPUT;
	}
	else
	{
		switch (a)
		{
		case 1:
			printf("你选择的功能是:1\n");
			input(stud);
			break;
		case 2:
			printf("你选择的功能是:2\n");
			show(stud);
			break;
		case 3:
			printf("你选择的功能是:3\n");
			sort(stud);
			break;
		case 4:
			printf("你选择的功能是:4\n");
			find(stud);
			break;
		case 5:
			printf("你选择的功能是:5\n");
			change();
			break;
		case 0:
			printf("你选择的功能是:0\n");
			printf("欢迎下次使用\n");
			exit(0);
		}
	}
}
