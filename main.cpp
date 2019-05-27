#include <iostream>
#include <cassert>
#include <cstddef>
using namespace std;


//ставит в сответствии от 0 до 16 символ
//»звлечь из байта младший и старший  nibble 1.2-3
char nibble_to_hex( uint8_t i)
{
    /*
char mass16[ ]{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
if (i>=0 && i<=15)
{
    return mass16[i];
} */
  assert(0x0 <= i && i <= 0xf);
	    char digits[] = "0123456789abcdef";
	    return digits[i];

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
        assert(nibble_to_hex(0x0) == '0');
	    assert(nibble_to_hex(0x1) == '1');
	    assert(nibble_to_hex(0x2) == '2');
	    assert(nibble_to_hex(0x3) == '3');
	    assert(nibble_to_hex(0x4) == '4');
	    assert(nibble_to_hex(0x5) == '5');
	    assert(nibble_to_hex(0x6) == '6');
	    assert(nibble_to_hex(0x7) == '7');
	    assert(nibble_to_hex(0x8) == '8');
	    assert(nibble_to_hex(0x9) == '9');
	    assert(nibble_to_hex(0xa) == 'a');
	    assert(nibble_to_hex(0xb) == 'b');
	    assert(nibble_to_hex(0xc) == 'c');
	    assert(nibble_to_hex(0xd) == 'd');
	    assert(nibble_to_hex(0xe) == 'e');
	    assert(nibble_to_hex(0xf) == 'f');
    cout<<'\n';
uint8_t u8=0x42;
cout<<"u8= ";
print_in_hex(&u8, sizeof (u8));
   cout<<'\n';
uint16_t u16=0x42;
   cout<<"u16= ";
print_in_hex(&u16, sizeof (u16));
   cout<<'\n';
uint32_t u32=0x42;
   cout<<"u32= ";
print_in_hex(&u32, sizeof (u32));
   cout<<'\n';

calc( op1, operat,  op2);
cout<<'\n';
////////////////////////////////3
Student students[3]=
{
    {"Dima", 17, 4.3, 1, 1, nullptr},
    {"Vera", 18, 4.7, 0, 1,&students[0]},
    {"Oleg", 20, 3.4, 1, 2,&students[0]}
};

cout << "Address of students" << ' '
<< &students << endl;
cout << "Size of students" << ' '
<< sizeof (students) << endl;

  cout<<"\t Address of elem:\t Size of elem:\n";
	    for (int i=0; i<3; i++){
	        cout<<i<<":\t   "<<&students[i]<<"\t\t      "<< sizeof(students[i])<<'\n';
	    }
	    cout<<"\n Second student \n";
	    cout<<"\t Address of field: \t Size of field\t Smeshen:\n";
	    cout<<"NAME : \t\t"<<&students[1].name<<"\t\t"<<sizeof(students[1].name)
	            <<'\t'<<offsetof(struct Student, name)<<'\n';
	    cout<<"Binary: ";
	    print_in_binary(&students[1].name, sizeof(students[1].name));
	    cout<<"\nHex: ";
	    print_in_hex(&students[1].name, sizeof(students[1].name));
	    cout<<"\nYEAR: \t\t"<<&students[1].year <<"\t\t"<<sizeof(students[1].year)
	            <<'\t'<<offsetof(struct Student, year)<<'\n';
	    cout<<"Binary: ";
	    print_in_binary(&students[1].year, sizeof(students[1].year));
	    cout<<"\nHex: ";
	    print_in_hex(&students[1].year, sizeof(students[1].year));
	    cout<<"\nSRED: \t\t"<<&students[1].sred<<"\t\t"
	            <<sizeof(students[1].sred)
	            <<'\t'<<offsetof(struct Student, sred)<<'\n';
	    cout<<"Binary: ";
	    print_in_binary(&students[1].sred, sizeof(students[1].sred));
	    cout<<"Hex: ";
	    print_in_hex(&students[1].sred, sizeof(students[1].sred));
	    return 0;
	}


