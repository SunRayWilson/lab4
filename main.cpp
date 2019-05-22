#include <iostream>
#include <cassert>
#include <cstddef>
using namespace std;


//ставит в сответствии от 0 до 16 символ
//»звлечь из байта младший и старший  nibble 1.2-3
char nibble_to_hex( uint8_t i)
{
char mass16[ ]{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
if (i>=0 && i<=15)
{
    return mass16[i];
}
}

//Ќапечатать байт как два nibble 1.4
void print_in_hex(uint8_t byte){
 cout<<nibble_to_hex(byte>>4)<<nibble_to_hex(byte&0x0f);
}

//приведением типов
const uint8_t* as_bytes(const void* data){
      return reinterpret_cast<const uint8_t*>(data);
}

//ѕреобразовать void* в uint8_t* и напечатать массив этих байт 1.5-6
void print_in_hex(const void* data, size_t size)
{
const uint8_t* bytes =  as_bytes(data);
    for (size_t i =0; i<size; i++){
    print_in_hex(bytes[i]);
    //дл€ удобства чтени€
    if((i+1)%16 == 0){
        cout<<'\n';
    }
    else {
        cout<<' ';
    }
    }

}

//Ќапечатать байт в двоичном виде1.7
char bit_digit(uint8_t byte, uint8_t bit){
if(byte&(0x1<<bit)){
    return '1';
}
return '0';
}
//—делаем сидвиги на 7,6,.., 0 бит - циклом
void print_in_binary(uint8_t byte){
for (uint8_t bit= 7;bit>0; bit--) {
    cout<< bit_digit(byte, bit);
}
cout<< bit_digit(byte,0);
}

//приведение типов в дв виде
void print_in_binary(const void* data, size_t size) {
	    const uint8_t* bytes = as_bytes(data);
	    for (size_t i = 0; i < size; i++) {
	        print_in_binary(bytes[i]);
	        // ƒл€ удобства чтени€
	        if ((i + 1) % 4 == 0) {
	            cout << '\n';
	        }
	        else {
	            cout << ' ';
	        }
	    }
	}



void calc(uint16_t op1,char operat, uint16_t op2){
//16
print_in_hex(&op1, sizeof(op1));
cout<<operat;
print_in_hex(&op2, sizeof(op2));
cout<<" = ";
uint16_t res;
if (operat =='&') {
    res=op1 &op2;
}
if (operat =='^') {
    res=op1 ^ op2;
}
    if (operat =='|'){
         res=op1 | op2;
    }
print_in_hex(&res, sizeof(res));
cout<<"\n";
//02
print_in_binary(&op1, sizeof(op1));
    cout<<" & ";
    print_in_binary(&op2, sizeof(op2));
    cout<<" = ";

print_in_binary(&res, sizeof(res));

}

//проверка 1.1




 struct Student{
char name[17];
uint16_t year;
float sred;
uint8_t gender:1;//пол1муж
uint8_t kurse;
Student* starosta;};


int main()
{
    uint16_t op1= 1025;
    uint16_t op2=127;
    char operat = '&';


  // cout << "1025 & 127" << endl;
  //  cin>>chislo;
   // print_in_hex(&chislo, sizeof(chislo));
 cout<< '\n';

   // cout<<"  ";
   // print_in_hex(127);
    cout<<'\n';

  uint8_t u8=0x42;
    cout<<"u8= ";
print_in_hex(&u8, sizeof (u8));
cout<<"\n";

uint16_t u16=0x42;
    cout<<"u16= ";
print_in_hex(&u16, sizeof (u16));
cout<<"\n";


uint32_t u32=0x42;
cout<<"u32= ";
print_in_hex(&u32, sizeof (u32));
cout<<"\n";

calc( op1, operat,  op2);
cout<<"\n";


////////////////////////////////3
Student students[3]=
{
    {"Dima", 17, 4.3, 1, 1, nullptr},
    {"Vera", 18, 4.7, 0, 1,&students[0]},
    {"Oleg", 20, 3.4, 1, 2,&students[0]}
};
cout<<"Adress of Students:\t";
cout<<&students<<"\n";
cout<<"Size of Students:\t" <<sizeof(students)<<"\n";
cout<<"Adress of Students[1]:\t" <<&students[1];




}
