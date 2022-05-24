#include<stdlib.h>
#include<stdio.h>

int charc(char *file) {
	FILE *fp = NULL;
	int charcount = 0;
	if ((fp=fopen(file,"r"))== NULL) {
		printf("文件寻找失败！\n");
		exit(-1);
	}
	char ch;
	ch = fgetc(fp);
	while (!feof(fp)) {
		ch = fgetc(fp);//读取文件中的字符
		charcount++;//统计字符数
	}
	fclose(fp);
	return charcount;
}

int wordc(char *file) {
	FILE *fp = NULL;
	int wordcount = 0;
	if ((fp = fopen(file,"r")) == NULL) {
		printf("文件寻找失败！\n");
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
	char file[50];//文件地址
	printf("\n请输入文件地址：\n");
	scanf("%s",file);
	if((fp=fopen(file,"r"))==NULL){
		printf("不存在这个文件");
		exit(-1);
	}
	else{
		ch=charc(file);
		wo=wordc(file);
		printf("\n该文件字符数为%d\n单词数为%d\n",ch,wo);
	}

}

