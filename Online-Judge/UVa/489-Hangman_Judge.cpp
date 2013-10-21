/*
Problem:489 - Hangman Judge
Date:2013-10-17
Author: Sophie
Compiler:GNU GCC
Lang:C++
*/


/*
注意：
2.        如果这个英文字符猜中（在答案的英文单字中有出现），被猜中的字符就被翻开。
例如：答案是book，如果你猜o，book中的两个o就会被视为已猜中。
3.        如果这个英文字符未出现在答案的单字中，就会在hangman的图中多加一划。要完成hangman图共需7划，如下图。
注意：同一个猜错的字符只能再图上画一划，例如：答案是book，第一次你猜a（未猜中）会在图上画一划，但第二次以后再猜a并不会再多画。
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
            //如果没有被猜测过
            if(!is_guessed(guess,i,guess[i]))
            {
                int tempTime = setCheck(word,word_len,guess[i]);
                if(tempTime == 0)
                {
                    //没有猜中
                    wrongTime++;
                    if(wrongTime >= 7)
                    {
                        type = 1;
                        break;
                    }
                }
                else
                {
                    //猜中了
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

//返回本次置1的个数
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
//判断是否猜测过，如果是返回1
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















