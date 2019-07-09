//
// Created by asorb on 19-6-27.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FILE_DIR "D:\\hello.c"

// 需要分析的内容
struct {
    int len;        // 长度
    int p;          // 指针
    char *val;     // 内容
} con;

// 加载文件
void loadFile(char fileDir[])
{
    int sizeB;      // 记录文件字节大小
    FILE *fp = fopen(fileDir, "r");
    if (fp == NULL)
        exit(0);
    fseek(fp, 0L, 2);
    sizeB = ftell(fp);
    fseek(fp, 0L, 0);
    con.val = (char *) malloc(sizeB);
    if (con.val == NULL)
        exit(0);
    con.len = 0;
    con.p = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        *(con.val + con.len) = c;
        con.len++;
    }
    fclose(fp);
}

// 去除空格
void delTrim()
{
    while (con.val[con.p] == ' ' || con.val[con.p] == '\n' || con.val[con.p] == '\t')
        con.p++;
}

// 扫描#include和#define
bool tagIncludeAndDefine(int state)
{
    char tagInclude[] = "include";
    char tagDefine[] = "define";
    switch (state) {
    case 0:
        if (con.val[con.p] == 'i')
            return tagIncludeAndDefine(1);
        else if (con.val[con.p] == 'd')
            return tagIncludeAndDefine(2);
        else
            return false;
    case 1:
        for (int i = 0; i < strlen(tagInclude); i++) {
            if (tagInclude[i] != con.val[con.p++])
                return false;
        }
        delTrim();
        if (con.val[con.p] == '"' || con.val[con.p] == '<') {
            con.p++;
            char name[21];
            int index = 0;
            char c;
            while (true) {
                c = con.val[con.p];
                if (c == '>' || c == '"') {
                    name[index] = '\0';
                    if (strlen(name) == 0)
                        return false;
                    else {
                        con.p++;
                        printf("包含头文件：%s\n", name);
                        delTrim();
                        return true;
                    }
                } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '.') {
                    name[index++] = c;
                    con.p++;
                } else
                    return false;
            }
        } else
            return false;
    case 2:
        for (int i = 0; i < strlen(tagDefine); i++) {
            if (tagDefine[i] != con.val[con.p++])
                return false;
        }
        delTrim();
        char name[21];
        char value[51];
        int index = 0;
        while (index < 20) {
            char c = con.val[con.p];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
                name[index++] = c;
                con.p++;
            } else
                break;
        }
        name[index] = '\0';
        delTrim();
        index = 0;
        char c = con.val[con.p];
        // 字符串
        if (c == '"') {
            con.p++;
            while ((c = con.val[con.p++]) != '"' && index < 50)
                value[index++] = c;
        } else {
            while (c != ' ' && c != '\n' && c != '\t' && index < 50) {
                value[index++] = c;
                con.p++;
                c = con.val[con.p];
            }
        }
        value[index] = '\0';
        if (strlen(name) != 0 && strlen(value) != 0) {
            printf("定义了常量：%s 值：%s\n", name, value);
            con.p++;
            return true;
        } else
            return false;
    }
}

// 扫描int关键字
bool tagInt(int state)
{
    char word[] = "int";
    char name[21];
    switch(state) {
    case 0:
        for(int i = 0; i < strlen(word); i++) {
            if(word[i] != con.val[con.p])
                return false;
            con.p++;
        }
        return tagInt(1);
    case 1: {
        delTrim();
        int index = 0;
        while(true) {
            char c = con.val[con.p];
            if(c == ' ' || c == '\n' || c == '\t')
                break;
            name[index++] = c;
            con.p++;
        }
        name[index] = '\0';
        delTrim();
        if(con.val[con.p] == '(')
            return tagInt(2);
        else
            return tagInt(3);
    }
    case 2: {
        if(strlen(name) == 0)
            return false;
        printf("%s\n",name);
        if(strcmp(name,"main") == 0)
            printf("程序入口：main函数！\n");
        else
            printf("定义了int型的函数%s\n",name);
        while(true) {
            char c = con.val[con.p];
            if(c == '{') {
                con.p++;
                break;
            }
            con.p++;
        }
        return true;
    }
    case 3: {
        if(strlen(name) == 0)
            return false;
        if(con.val[con.p] == ';') {
            printf("声明了int型的变量%s\n",name);
            return true;
        } else {
            char value[51];
            int index = 0;
            while(index < 50) {
                char c = con.val[con.p++];
                if(c < '0' || c > '9')
                    return false;
                else if(c == ';')
                    break;
                value[index++] = c;
            }
            value[index] = '\0';
            printf("定义了int型的变量%s 值：%s",name,value);
            return true;
        }
    }
    }
}

// 扫描入口
void scan(int state)
{
    while (true) {
        if (con.p >= con.len) {
            printf("\n========华丽分割线========\n");
            printf("程序分析完毕，未发现语法问题！\n");
            break;
        }

        delTrim();

        switch (state) {
        case 0:
            if (con.val[con.p] == '#') {
                con.p++;
                if (tagIncludeAndDefine(0))
                    state = 0;
                else
                    state = -1;
            } else
                state = 1;
            break;
        case 1:
            if(con.val[con.p] == 'i') {
                if(tagInt(0))
                    state = 0;
                else
                    state = -1;
            } else
                state = 2;
            break;
        case -1:
            printf("\n========华丽分割线========\n");
            printf("在%d处发现未能识别的语法，程序终止！\n", con.p);
            exit(0);
        }
    }
}

// 启动扫描
void start(char fileDir[])
{
    loadFile(fileDir);
    scan(0);
}

int main()
{
    start(FILE_DIR);

    // 释放开辟的空间
    if (con.val != NULL)
        free(con.val);

    return 0;
}
