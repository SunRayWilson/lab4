#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


int main()
{
    const size_t MAX_SIZE = 256;
    const char* symbols = "*<>?|\"";
    char text[MAX_SIZE];
    cout << "Vvod filename" << '\n';
    fgets(text,MAX_SIZE,stdin);
    char* filename = text;
    filename[strlen(filename) - 1] = '\0';

    while(true)
    {
//определяет, сколько первых символов строки подряд относятся к множеству,
// заданному другой строкой и равняется Количество символов в строке до первого вхождения символа
        if(strcspn(filename,symbols) == strlen(filename));
        else{
            cout << "Not correct name of file";
            break;
        }

           if (strchr(filename,58) != NULL)
        {
            if (strcspn(filename,"'\'") == 2)
            {
                if (strcspn(filename,":") == 1){
                    if (isalpha(filename[0])) {}
                    else{
                        cout << "Not correct name of file";
                        break;
                        }
                }
                else{
                    cout << "Not correct name of file";
                    break;
                    }
            }
            else{
                cout << "Not correct name of file";
                break;
                }
        }

 //eсли имя фаила не имеет расширения(3)
        if(strrchr(filename,'.') == nullptr)
            strcat(filename,".txt");
//оступ к фаилу
        FILE* file = fopen(filename,"r+");
        if (file == 0) break;
//опредерение размера фаила
        fseek(file,0,SEEK_END);
//выделяем определённый размер в памяти для фаила
        int fsize = ftell(file);
//выделение в динамической памяти достаточного места
        char* massive = new char[fsize];
        fseek(file,0,SEEK_SET);
//загрузка всего содержимого в выделенную область памяти
        fread ( massive , 1 , fsize , file );
        massive[fsize] = '\0';
        char stroka[MAX_SIZE];
        cout << "Enter stroka" << '\n';
        fgets(stroka,MAX_SIZE,stdin);
        char* str = stroka;
        *(str + strlen(str) - 1) = '\0';
        int povtor = 0;
        while(*massive != '\0'){
            if(strncmp(massive,str,strlen(str)) != 0)
                massive += 1;
            else{
                povtor ++;
                massive += 1;
            }
        }
        cout << "Chislo vhozdenyi " << povtor << '\n';

//освобождение массива и памяти
        delete[] massive;
        fclose(file);
        break;
    }
    return 0;
}
