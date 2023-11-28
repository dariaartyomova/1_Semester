// Laba8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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

    bool isVowel(char c)
    {
        c = tolower(c);
        char vowels[11] = { 'а', 'у', 'е', 'э', 'о', 'ы', 'я', 'и', 'ю', 'ё' };

        for (int i = 0; i < strlen(vowels); i++)
            if (c == vowels[i])
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



    int numOfVolews(char word[50])
    {
        int result = 0;
        for (int i = 0; i < strlen(word); i++)
            if (isVowel(word[i]))
                result++;
        return result;
    }

    bool isConsonant(char c)
    {
        c = tolower(c);
        char consonant[22] = { 'ц', 'к', 'н', 'г', 'ш', 'щ', 'з', 'х', 'ф', 'в', 'п', 'р', 'л', 'д', 'ж', 'б', 'т', 'м', 'с', 'ч', 'й'};

        for (int i = 0; i < strlen(consonant); i++)
            if (c == consonant[i])
                return true;
        return false;
    }

    void duplicateConsonant(char word[50])
    {
        for (int i = 0; i < strlen(word); i++)
        {
            if (mt::isConsonant(word[i]))
            {
                for (int j = strlen(word) + 1; j >= i; j--)
                    word[j + 1] = word[j];
                i++;
            }
        }
    }

    void removeVowels(char word[50])
    {
        for (int i = 0; i < mt::strlen(word); i++)
        {
            if (mt::isVowel(word[i]))
            {
                for (int j = i; j <= strlen(word); j++)
                    word[j] = word[j + 1];
                i--;
            }
        }
    }

    bool WordIsUniq(char words[500][50], int n, int i)
    {
        int fl = 0; // количество одинаковых слов
        for (int t = 0; t < n; t++)
        {
            int f = 0; // одинаковые буквы
            if (strlen(words[i]) == strlen(words[t]))
                for (int j = 0; j < strlen(words[i]); j++)
                {
                    if (words[t][j] == words[i][j])
                        f++;
                }
            if (strlen(words[i]) == f)
                fl++;
        }
        if (fl == 1)
            return true;
        else
            return false;
    }
        
    

}


/*
int main()
{
    setlocale(LC_ALL, "Rus");
    std::ifstream in("cat.txt");
    if (!in.is_open())
    {
        std::cout << "Err";
        return 0;
    }

    char text[2000];
    in.getline(text, 1000);
    int size = 0;
    int n = 0;
    int kwords;

    std::cout << text << std::endl;
    


    char word[50];

    char words[500][50];


    mt::splitText(text, words, n);

     // согласные упорядочены
    

    //std::cout << strlen(words) << std::endl;
    int maxlet = 0;
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        char c = 0;
        for (int j = 0; j < strlen(words[i]); j++)
        {
            //std::cout << words[i][j] << std::endl;
            if (mt::isConsonant(words[i][j]))
            {
                if (c == 0)
                {
                    c = words[i][j];
                    continue;
                }

                if (c < words[i][j])
                {
                    c = words[i][j];
                }
                else
                {
                    flag = false;
                    break;
                }
            }

        }
        //std::cout << flag << std::endl;
        if (flag == 1)
        {
            if (strlen(words[i]) > maxlet)
            {
                maxlet = strlen(words[i]);
            }
        }

        

    }
    //std::cout << n << std::endl;
    std::cin >> kwords;
    for (int k = 0; k < kwords; k++)
    {
        for (int i = 0; i < n; i++)
        {
            bool flag = true;
            char c = 0;
            for (int j = 0; j < strlen(words[i]); j++)
            {
                //std::cout << words[i][j] << std::endl;
                if (mt::isConsonant(words[i][j]))
                {
                    if (c == 0)
                    {
                        c = words[i][j];
                        continue;
                    }

                    if (c < words[i][j])
                    {
                        c = words[i][j];
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }

            }
            
            if (flag == 1)
                if ((maxlet - k) == strlen(words[i]))
                    if (mt::WordIsUniq(words, n, i))
                        std::cout << words[i] << std::endl;
        }

    }
    

    return 0;
    

    
}
*/

int main()
{
    setlocale(LC_ALL, "Rus");
    std::ifstream in("cat.txt");
    if (!in.is_open())
    {
        std::cout << "Err";
        return 0;
    }

    char text[2000];
    in.getline(text, 1000);
    int size = 0;
    int n = 0;

    std::cout << text << std::endl;



    char word[50];

    char words[500][50];


    mt::splitText(text, words, n);
    std::set<std::string>wordset;

    for (int i = 0; i < n; i++)
    {
        int counter = 0;
        for (int j = 0; j < strlen(words[i]); j++)
        {
            if (mt::isConsonant(words[i][j]))
                counter++;
        }
        if (counter <= 3)
        {
            wordset.insert(words[i]);
        }

        else
        {
            mt::removeVowels(words[i]);
            mt::duplicateConsonant(words[i]);
            std::cout << words[i] << std::endl;
        }

        
            
    }

    for (const auto& word : wordset)
    {
        std::cout << word << std::endl;
    }

    return 0;
}


