#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define OK 0;

/* main������ڲ��������͵���ڲ������� + �ַ��������飩ָ���͵���ڲ��� */
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

	FILE * filePointer; //�����ļ�ָ�룬���ڳн��ļ��ڴ��ַ
	char * fileName; //���ڳн�����main��ڲ�����txt�ļ���
	char * selectionString; //���ڳн�����main��ڲ������û�ѡ�񣨼����ַ��� ���� ��������
	int selectionInt; //������ֵ����û���ѡ��

	selectionString = parametersArry[1];
	/* �����ַ����ȽϺ����ж��û���¼��ѡ�����ں������ */
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
	/* �����ļ��򿪺����Լ��ַ������ắ������ֻ����ʽ����Ӧtxt�ļ���������ַ���ظ��ļ�ָ�� */
	filePointer = fopen(strcat(fileName, ".txt"), "r");

	switch (selectionInt)
	{
	case 0:
	{
		int counter = 0;
		char element;
		/* ��û�������ļ�ĩβ������ʱ������ѭ����ȡtxt�ļ��������ַ����� */
		while (!feof(filePointer))
		{
			/* �����ļ��ַ���ȡ��������ȡ��ǰָ��ָ����ַ� */
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
			/* ����ȡ���ַ�Ϊ�ո������ţ�˵�������뵥�ʱ��ָ�����������������һ����λ */
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