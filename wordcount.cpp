#include<stdlib.h>
#include<stdio.h>

int charc(char *file) {
	FILE *fp = NULL;
	int charcount = 0;
	if ((fp=fopen(file,"r"))== NULL) {
		printf("�ļ�Ѱ��ʧ�ܣ�\n");
		exit(-1);
	}
	char ch;
	ch = fgetc(fp);
	while (!feof(fp)) {
		ch = fgetc(fp);//��ȡ�ļ��е��ַ�
		charcount++;//ͳ���ַ���
	}
	fclose(fp);
	return charcount;
}

int wordc(char *file) {
	FILE *fp = NULL;
	int wordcount = 0;
	if ((fp = fopen(file,"r")) == NULL) {
		printf("�ļ�Ѱ��ʧ�ܣ�\n");
		exit(-1);
	}
	char ch;
	int word;
	while (!feof(fp)) {
		ch = fgetc(fp);
		if (ch>'Z'&&ch< 'a'||ch>'z')
			word=0; 
		else if (word==0)
		{
		word=1;
		wordcount++;
		}
	}
	return wordcount;
}


int main(){
	FILE *fp;
	int ch,wo,li;
	char file[50];//�ļ���ַ
	printf("\n�������ļ���ַ��\n");
	scanf("%s",file);
	if((fp=fopen(file,"r"))==NULL){
		printf("����������ļ�");
		exit(-1);
	}
	else{
		ch=charc(file);
		wo=wordc(file);
		printf("\n���ļ��ַ���Ϊ%d\n������Ϊ%d\n",ch,wo);
	}

}

