#include <stdio.h>
#include <math.h>
//һ�ٵ����ټ������
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 101; i <= 200; i+=2)
//	{
//		for (j = 2; j <= sqrt(i); j++)
//			if (i % j == 0)
//			{
//				break;
//			}
//
//		    if (j > sqrt(i))
//				printf("%d  ", i);
//	}
//	return 0;
//	
//}

//main()
//{
//	char a;
//	printf("������һ��Сд��ĸ��\n");
//	a = getchar();//�õ�ascll��
//	a = a - 32;
//	printf("ת���ɵĴ�д��ĸΪ��%c\n", a);//%c������ת�����ַ�
//
//}

//main()
//{
//	float a, b, c, x1, x2, disc;
//	printf("input a b c:\n");
//	scanf("%f%f%f", &a, &b, &c);
//	if (fabs(a) < 1e-6)
//		printf("The equation is not a quadratic\n");
//	else
//	{
//		disc = b * b - 4 * a * c;
//		if (disc < 0)
//			printf("The equation has not real root!\n");
//		else
//			if (fabs(disc < 1e-6))
//				printf("The equation has two equal roots:%8.4f\n", -b / (2 * a));
//			else
//			{
//				x1 = (-b + sqrt(disc)) / (2 * a);
//				x2 = (-b - sqrt(disc)) / (2 * a);
//				printf("The equation has two equal roots:%8.4f,%8.4f", x1, x2);
//			}
//	}
//}
#include "stdio.h"
main()
{
	ep3_2_1();
	ep3_2_2();
	ep3_2_3();
	ep3_2_4();
	/*ep3_2_5();*/
	ep3_2_6();
	ep3_2_7();
	ep3_2_8();
	ex3_1_1();
	ex3_1_2();
	ex3_1_3();
	ex3_2_1();
	ex3_2_2();

}

int ep3_2_1()
{
	int x = 0, y = 0, z = 0;
	scanf("%d%d%d", &x, &y, &z);
	printf("x=%d,y=%d,z=%d\n", x, y, z);
}

int ep3_2_2()
{
	char ch;
	while ((ch = getchar()) == '0')
		printf("#");
}

int ep3_2_3()
{
	char c; int n = 100; float f = 10; double x;
	x = f *= n /= (c = 50);
	printf("\n%d,%f\n", n, x);
}

int ep3_2_4()
{
	int a, b;
	printf("\n���룺");
	scanf_s("a=%d,b=%d", &a, &b);
	printf("a=%d,b=%d\n", a, b);
}

int ep3_2_5()
{
	char a[10], b[10];
	puts("\n�������ַ���1��");
	gets(a); puts(a);
	printf("�������ַ���2��\n");
	scanf_s("%s", &b);
	printf("%s\n", b);
}

int ep3_2_6()
{
	int x = 'd';
	printf("%c\n", 'y' - (x - 'a' + 1));
}

int ep3_2_7()
{
	char c1, c2, c3, c4, c5, c6;
	printf("\n�����룺");
	scanf_s("%c%c%c%c", &c1, &c2, &c3, &c4);
	c5 = getchar();    c6 = getchar();
	putchar(c1);     putchar(c2);
	printf("%c%c\n", c5, c6);
}

int ep3_2_8()
{
	int a, b, c;
	float average;
	printf("\n��������������");
	scanf_s("%d%d%d", &a, &b, &c);
	average = (a + b + c) / 3.0;
	printf("ƽ���֣�%-7.2f\n", average);
}

int ex3_1_1()
{
	char a = 'p';
	printf("\nASCII��ֵΪ%d", a);
}

int ex3_1_2()
{
	char a, b, c;
	printf("\n������һ����дӢ���ַ�:\n");
	scanf_s("%c", &a);
	a += 32; b = a - 1; c = a + 1;
	printf("ת���ɵ�СдӢ���ַ�Ϊ%c,���ڵ�������ĸΪ%c%c,ASCII��ֱ���%d,%d", a, b, c, b, c);
}

int ex3_1_3()
{
	int R = 25, r = 15;
	double PI = 3.1415, s = 0.0;
	s = PI * (R * R - r * r);
	printf("\nʵ��Բ���������%lf", s);

}

int ex3_2_1()
{
	int a = 0, b, c, d;
	printf("\n������һ����λ������:\n");
	scanf("%d", &a);
	b = a / 100;
	c = (a - 100 * b) / 10;
	d = a - 100 * b - 10 * c;
	printf("������%d%d%d", d, c, b);
	return 0;
}
int ex3_2_2()
{
	float a = 0.0, b;
	printf("\n�����뻪���¶ȣ�");
	scanf("%f", &a);
	b = 5.0 / 9 * (a - 32);
	printf("�����¶�Ϊ%.1f", b);

}

