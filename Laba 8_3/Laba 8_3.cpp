// Laba 8_3.cpp 

#include <iostream>
#include <fstream>
#include <string>
#include <set>


namespace mt
{


    unsigned int strlen(char* str)
    {
        int len = 0;
        while (str[len] != '\0')
            len++;
        return len;
    }

    void strcat(char* dst, char* src)
    {
        int len_dst = strlen(dst);
        int len_src = strlen(src);

        for (int i = 0; i < len_src; i++)
            dst[len_dst + i] = src[i];

        dst[len_dst + len_src] = '\0';
    }

    void strcat(char* dst, char src)
    {
        int len_dst = strlen(dst);
        dst[len_dst] = src;
        dst[len_dst + 1] = '\0';
    }

    char tolower(char c)
    {
        if ('A' <= c && c <= 'Z')
            return c + 32;
        if ('А' <= c && c <= 'Я')
            return c + 32;
        if (c == 'Ё')
            return 'ё';
        return c;
    }

    char togrow(char c)
    {
        if ('a' <= c && c <= 'z')
            return c - 32;
        if ('а' <= c && c <= 'я')
            return c - 32;
        if (c == 'ё')
            return 'Ё';
        return c;
    }

    void tolower(char* str)
    {
        for (int i = 0; i < strlen(str); i++)
            str[i] = tolower(str[i]);
    }

    bool isLetter(char c)
    {
        c = tolower(c);
        if (('а' <= c && c <= 'я') || c == 'ё')
            return true;
        return false;
    }



    void splitText(char text[1000], char words[500][50], int& n)
    {
        char word[50] = { 0 };
        int size = 0;

        char endLetter[2] = ".";
        mt::strcat(text, endLetter);

        for (int i = 0; i < strlen(text); i++)
        {
            if (mt::isLetter(text[i]))
            {
                word[size] = text[i];
                size++;
            }
            else
            {
                if (size == 0)
                    continue;

                word[size] = '\0';
                strcpy_s(words[n], word);
                n++;
                size = 0;
            }
        }
    }





}

int main()
{
    //Ввод текста
    setlocale(LC_ALL, "Rus");
    std::ifstream in("input.txt");
    if (!in.is_open())
    {
        std::cout << "Err";
        return 0;
    }
    std::ofstream out("output.txt", std::ios::app);

    char text[20000];
    in.getline(text, 1000);
    int size = 0;
    int n = 0;
    std::cout << text << std::endl;

    char word[50];
    char words[500][50];
    mt::splitText(text, words, n);



    std::string strtext(text);

    


    for (int i = 0; i < n; i++)
    {
        std::string strwords;
        std::string strwor;
        std::string strletter;
        bool flag = 0;
        for (int j = 0; j < strlen(words[i]); j++)
            strwor += words[i][j];
        for (int j = 0; j < strlen(words[i]-1); j++)
        {
            
            if (words[i][j] == words[i][j + 1])
            {
                words[i][j] = mt::togrow(words[i][j]);
                words[i][j + 1] = mt::togrow(words[i][j + 1]);
                flag = 1;
                strletter += words[i][j];
                
            }
           
        }
        
        if (flag == 1)
        {
            for (int j = 0; j < strlen(words[i] - 1); j++)
            {
                strwords += words[i][j];

            }
           
            
            size_t found = strtext.find(strwor);
            if (found != std::string::npos)
            {
                strtext.replace(found, strwords.length(), strwords + "(" + strletter + ")");
            }
               
            
        }
    
    }

    out << strtext << std::endl;

    return 0;
}
