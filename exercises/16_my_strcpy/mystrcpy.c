/*
 * Lesson 16: 字符串拷贝
 *
 * 知识点：指针，const, assert, while (*dest++ = *src++) 惯用法
 *
 * 任务：参考原课 mystrcpy.c，实现 mystrcpy 函数：
 *       1. char *mystrcpy(char *dest, const char *src)
 *       2. 逐字符复制直到 '\0' 也复制过去
 *       3. 返回 dest 起始地址
 *       4. main 中从 stdin 读入字符串，用 mystrcpy 复制后打印
 *
 * 验证：输入 "copy me" → "copy me\n"
 */

#include <assert.h>
#include <stdio.h>

char *mystrcpy(char *dest, const char *src) {       //mystrcpy这个函数的返回值是一个char类型指针
    assert(dest != NULL && src != NULL);        //assert表示断言，条件为真则什么都不做，为假则立即终止程序
    char *save = dest;
    
    while (*dest++ = *src++);       //最终dest和src指向/0后面的值，虽然*优先级低于++，但++在后缀，因此当*执行时用的是原来的地址
    
    return save;        //返回我保存的dest起始位置
}

int main(void) {
    char s1[256] = "";
    char s2[256];

    fgets(s2, sizeof(s2), stdin);       //fgets可以把换行\n也读进来
    /* 去掉换行 */
    int i = 0;
    while (s2[i] && s2[i] != '\n') i++;
    s2[i] = '\0';

    mystrcpy(s1, s2);
    printf("%s\n", s1);

    return 0;
}
