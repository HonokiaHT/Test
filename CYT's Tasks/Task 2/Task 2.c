#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
int main()


{
	printf("Where are you from??\nPlease enter 'Roman' OR 'India'.\n");
	char *country[6];
	scanf("%s", country);

	//阿拉伯数字转罗马数字
	if (strcmp(country, "India") == 0)
	{

		int num, n1, n2, n3, n4; //定义输入的阿拉伯数字和它的各个位上的数字（首位到末位）

		printf("\nPlease enter an alabo number:\n");
		scanf_s("%d", &num);

		if (num > 3999 || num < 1)
			printf("\nThe number should be between 1 and 3999.\n");
		else
		{
			//借鉴了查来的数组思维
			char* list[4][10] = {
						{"","I","II","III","IV","V","VI","VII","VIII","IX"},
						{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
						{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
						{"","M","MM","MMM"}
			};

			n1 = num / 1000 % 10;
			n2 = num / 100 % 10;
			n3 = num / 10 % 10;
			n4 = num % 10;

			char* rom1 = list[3][n1];
			char* rom2 = list[2][n2];
			char* rom3 = list[1][n3];
			char* rom4 = list[0][n4];

			printf("\nThe corresponding Roman numeral=%s%s%s%s\n", rom1, rom2, rom3, rom4);
		}
	}

	//罗马数字转阿拉伯数字
	else
		if (strcmp(country, "Roman") == 0)
		{
			char romnum[17];

			printf("\nPlease enter an Roman numeral:\n");
			scanf("%s", romnum);

			//定义三个指示物和将输出的阿拉伯数字
			int arabicnum = 0, i1 = 0, i2 = 0, i3 = 0;

			//判断是否是罗马数字
			//太他妈难判断了
			for (i1; i1 <= 16; i1++)
			{
				if (romnum[i1 + 2] != -52  //不读取数组中未赋值区域（大前提）
					&& ((romnum[i1] == romnum[i1 + 1] && romnum[i1 + 1] == romnum[i1 + 2] && romnum[i1 + 2] == romnum[i1 + 3])
						|| (romnum[i1] == romnum[i1 + 1] && romnum[i1 + 1] == 'I') && (romnum[i1 + 1] != romnum[i1 + 2] && romnum[i1 + 2] != '\0')  //'\0'排除在scanf中赋值时产生的录入的'enter'
						|| ((romnum[i1] == romnum[i1 + 1] && romnum[i1 + 1] == 'X') && (romnum[i1 + 1] != romnum[i1 + 2] && romnum[i1 + 2] != 'I' && romnum[i1 + 2] != 'V' && romnum[i1 + 2] != '\0'))
						|| ((romnum[i1] == romnum[i1 + 1] && romnum[i1 + 1] == 'C') && (romnum[i1 + 1] != romnum[i1 + 2] && romnum[i1 + 2] != 'I' && romnum[i1 + 2] != 'V' && romnum[i1 + 2] != 'X' && romnum[i1 + 2] != 'L' && romnum[i1 + 2] != '\0'))
						|| (romnum[i1] == 'V' && romnum[i1 + 1] != 'I' && romnum[i1 + 1] != -52 && romnum[i1 + 1] != '\0')
						|| (romnum[i1] == 'L' && romnum[i1 + 1] != 'I' && romnum[i1 + 1] != 'V' && romnum[i1 + 1] != 'X' && romnum[i1 + 1] != -52 && romnum[i1 + 1] != '\0')
						|| (romnum[i1] == 'D' && (romnum[i1 + 1] == 'D' || romnum[i1 + 1] == 'M'))
						|| (romnum[i1] != 'I' && romnum[i1] != 'V' && romnum[i1] != 'X' && romnum[i1] != 'L' && romnum[i1] != 'C' && romnum[i1] != 'D' && romnum[i1] != 'M')))
				 
				{
					printf("You are not the Romans!!\n");
					system("pause");
					return 0;
				}
			}

			//对各个罗马数字对应的值求和
			for (i2; i2 <= 16; i2++)
			{
				switch (romnum[i2])
				{
				case'I':arabicnum += 1; break;
				case'V':arabicnum += 5; break;
				case'X':arabicnum += 10; break;
				case'L':arabicnum += 50; break;
				case'C':arabicnum += 100; break;
				case'D':arabicnum += 500; break;
				case'M':arabicnum += 1000; break;
				case'\0':break;
				}
			}
			//将三种特殊情况提出，减去因忽略这些特殊情况而多加的值
			for (i3; i3 <= 16; i3++)
			{
				if (romnum[i3] == 'I' && (romnum[i3 + 1] != 'I' && romnum[i3 + 1] != '\0'))
					arabicnum -= 2;

				if (romnum[i3] == 'X' && (romnum[i3 + 1] != 'I' && romnum[i3 + 1] != 'V' && romnum[i3 + 1] != 'X' && romnum[i3 + 1] != '\0'))
					arabicnum -= 20;

				if (romnum[i3] == 'C' && (romnum[i3 + 1] == 'D' || romnum[i3 + 1] == 'M'))
					arabicnum -= 200;
			}
			
			printf("\nThe corresponding Arabic numeral=%d\n", arabicnum);
		}
		else
			if (strcmp(country, "China") == 0)
				printf("404 NOT FOUND.\n");
			else
				printf("none of your business.\n");

	system("pause");
	return 0;

}

