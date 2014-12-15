#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 50

typedef struct {
  char name[15][20];
  char id[8];
  int score;
} student;

void display(student, char);
void import(char*, student*,int*);
void export(char*, student*,int);

int main(){

  student studentList[MAX_STUDENTS];
  int counter = 0,i = 0;
  char c = '\0', filename[100] = {'\0'};
  do {
    printf("i: 插入\nl: 列出\ns: 存檔\no: 讀檔\nq: 結束\n> ");
    scanf("%c",&c);
    fflush(stdin);
    switch(c) {
      case 'i':
        if(counter >50){ printf("Limit Exceeded"); }
        fflush(stdin);
        printf("姓名: "); scanf(" %s",studentList[counter].name);
        printf("學號: "); scanf(" %s",studentList[counter].id);
        printf("分數: "); scanf(" %d",&(studentList[counter].score));
        printf("插入完成!\n");
        counter ++;
        break;
      case 'l':
        for(i = 0; i<counter; i++) {
          printf("No. %d\n",i+1);
          display(studentList[i], '\n');
          printf("============\n");
        }
        break;
      case 's':
        fflush(stdin);
        printf("輸入檔案名稱(.txt): ");
        scanf(" %s",filename);
        export(filename,studentList,counter);
        break;
      case 'o':
        fflush(stdin);
        printf("輸入檔案名稱(.txt): ");
        scanf(" %s",filename);
        import(filename,studentList,&counter);
        break;
      case 'q':
        return 0;
        break;
      default:
        printf("輸入錯誤!\n");
    }
    fflush(stdin);

#if defined(_WIN32) || defined(_WIN64)
    system("pause");
#else
    printf("Press Enter to Continue...\n");
    scanf("%*c");
    fflush(stdin);
#endif

  }while(1);
}

void display(student input, char append) {
  printf("姓名: %s %c",input.name,append);
  printf("學號: %s %c",input.id,append);
  printf("分數: %d %c",input.score,append);
}


void import(char* fname, student* list,int* pos) {
  FILE* fp;
  student buffer;
  fp = fopen(fname, "r");
  if(fp == NULL) { printf("Error Open File: \"%s\"\n",fname); return;}
  *pos = 0;
  while(fscanf(fp,"%s %s %d",buffer.name,buffer.id,&buffer.score) != EOF) {
    list[*pos] = buffer;
    (*pos)++;
    display(buffer,' '); putchar('\n');
  }
  fclose(fp);
  return;
}

void export(char* fname, student* list,int size) {
  FILE * fp;
  int i;
  fp = fopen(fname, "w");
  if(fp == NULL) { printf("Error Create File: \"%s\"\n",fname); return;}
  for(i = 0; i < size; i++) {
    fprintf(fp, "%s %s %d \n", list[i].name, list[i].id, list[i].score );
  }
  fclose(fp);
  return;
}
