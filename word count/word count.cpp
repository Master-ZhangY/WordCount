#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define OK 0;

/* main函数入口参数，整型的入口参数数量 + 字符串（数组）指针型的入口参数 */
int main(int parametersNumber, char * parametersArry[])
{
	printf("The parameters number is : %d\n", parametersNumber);
	for (int counter = 0; counter < parametersNumber; ++counter)
	{
		switch (counter)
		{
		case 0: {printf("The program's name is : %s\n", parametersArry[counter]); }break;
		case 1: {printf("Your statistic selection is : %s\n", parametersArry[counter]); }break;
		case 2: {printf("The target text file name is : %s\n", parametersArry[counter]); }break;
		default: {; }break;
		}
	}
	printf("***************************************************\n\n");

	FILE * filePointer; //定义文件指针，用于承接文件内存地址
	char * fileName; //用于承接来自main入口参数的txt文件名
	char * selectionString; //用于承接来自main入口参数的用户选择（计算字符数 或是 单词数）
	int selectionInt; //用整型值标记用户的选择

	selectionString = parametersArry[1];
	/* 利用字符串比较函数判断用户的录入选择属于何种情况 */
	if (strcmp(selectionString, "-c") == 0 || strcmp(selectionString, "-C") == 0)
	{
		selectionInt = 0;
	}
	else if (strcmp(selectionString, "-w") == 0 || strcmp(selectionString, "-W") == 0)
	{
		selectionInt = 1;
	}
	else
	{
		printf("Input error !!!\n");
	}

	fileName = parametersArry[2];
	/* 利用文件打开函数以及字符串连结函数，以只读格式打开相应txt文件，并将地址返回给文件指针 */
	filePointer = fopen(strcat(fileName, ".txt"), "r");

	switch (selectionInt)
	{
	case 0:
	{
		int counter = 0;
		char element;
		/* 当没有遇到文件末尾结束符时，依次循环读取txt文件内所有字符内容 */
		while (!feof(filePointer))
		{
			/* 利用文件字符获取函数，获取当前指针指向的字符 */
			element = fgetc(filePointer);
			if (counter % 6 == 0)
				printf("\n");
			printf("%c ", element);
			counter++;
		}
		printf("\n");
		printf("The total chars number is : %d\n", --counter);
	}break;
	case 1:
	{
		int counter = 0;
		char element;
		while (!feof(filePointer))
		{
			element = fgetc(filePointer);
			printf("%c", element);
			/* 当读取的字符为空格或标点符号，说明单词与单词被分隔开，计数变量自增一个单位 */
			if (element == ' ' || element == ',' || element == '.'
				|| element == '!')
			{
				printf("\n");
				counter++;
			}			
		}
		printf("The total words number is : %d\n", counter);
	}break;
	default: {; }break;
	}

	return OK;
}