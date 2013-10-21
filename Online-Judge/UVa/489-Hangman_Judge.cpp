/*
Problem:489 - Hangman Judge
Date:2013-10-17
Author: Sophie
Compiler:GNU GCC
Lang:C++
*/


/*
ע�⣺
2.        ������Ӣ���ַ����У��ڴ𰸵�Ӣ�ĵ������г��֣��������е��ַ��ͱ�������
���磺����book��������o��book�е�����o�ͻᱻ��Ϊ�Ѳ��С�
3.        ������Ӣ���ַ�δ�����ڴ𰸵ĵ����У��ͻ���hangman��ͼ�ж��һ����Ҫ���hangmanͼ����7��������ͼ��
ע�⣺ͬһ���´���ַ�ֻ����ͼ�ϻ�һ�������磺����book����һ�����a��δ���У�����ͼ�ϻ�һ�������ڶ����Ժ��ٲ�a�������ٶ໭��
*/

#include <stdio.h>
#include <string.h>

const int max = 1000;
int setCheck(char* word, int len, char ch);
int is_guessed(char* guess, int len, char ch);

int main()
{
    int round;
    char word[max];
    char guess[max];
    int word_len,guess_len;
    int wrongTime;
    int rightWord;
    int type;

    while(scanf("%d",&round) != EOF)
    {
        wrongTime = 0;
        rightWord = 0;
        type = 2;
        if(round == -1)
            break;
        scanf("%s %s",word,guess);

        word_len = strlen(word);
        guess_len = strlen(guess);

        printf("Round %d\n",round);
        for(int i = 0;i<guess_len;i++)
        {
            //���û�б��²��
            if(!is_guessed(guess,i,guess[i]))
            {
                int tempTime = setCheck(word,word_len,guess[i]);
                if(tempTime == 0)
                {
                    //û�в���
                    wrongTime++;
                    if(wrongTime >= 7)
                    {
                        type = 1;
                        break;
                    }
                }
                else
                {
                    //������
                    rightWord += tempTime;
                    if(rightWord >= word_len)
                    {
                        type = 0;
                        break;
                    }
                }
            }
        }
        switch(type)
        {
            case 0:
                printf("You win.\n");
                break;
            case 1:
                printf("You lose.\n");
                break;
            default:
                printf("You chickened out.\n");
        }
    }
    return 0;
}

//���ر�����1�ĸ���
int setCheck(char* word,int len, char ch)
{
    int count = 0;
    for(int i = 0;i<len;i++)
    {
        if(word[i] == ch)
        {
            count++;
        }
    }
    return count;
}
//�ж��Ƿ�²��������Ƿ���1
int is_guessed(char* guess, int len, char ch)
{
    int result = 0;
    for(int i = 0;i<len;i++)
    {
        if(guess[i] == ch)
        {
            result = 1;
            break;
        }
    }
    return result;
}















