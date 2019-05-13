#include <iostream>
#include <cassert>
using namespace std;


//ставит в сответствии от0 до 16 символ
char nibble_to_hex( uint8_t i)
{
char mass16[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
if (i>=0 && i<=15)
{
    return mass16[i];
}
}


void print_in_hex(uint8_t byte){
 cout<<nibble_to_hex(byte>>4)<<nibble_to_hex(byte&0x0f);
}

const uint8_t* as_bytes(const void* data){
      return reinterpret_cast<const uint8_t*>(data);
}

void print_in_hex(const void* data, size_t size){
const uint8_t* bytes =  as_bytes(data);
    for (size_t i =0; i<size; i++){
    print_in_hex(bytes[i]);
    //для удобства чтения
    if((i+1)%16 == 0){
        cout<<'\n';
    }
    else {
        cout<<' ';
    }
    }

}

//1.7 Напечатать баайт в двоичном виде
char
bit_digit(uint8_t byte, uint8_t bit) {
    if (byte & (0x1 << bit)) {
        return '1';
    }
    return '0';
}
//Сделаем сидвиги на 7,6,.., 0 бит - циклом
void
print_in_binary(uint8_t byte) {
    for (uint8_t bit = 7; bit > 0; bit--){
        cout << bit_digit(byte, bit);
    }
    cout << bit_digit(byte, 0);
}
//Здесь должная буть самопроверка по слайду из лекции

//1.8. Напечатать блок данных в дв виде
void //приведение типов в дв виде
print_in_binary(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_binary(bytes[i]);

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

struct Student {
	    char name[17];
	    uint32_t year;
	    float sred_ball;
	    int sex:1;
	    uint8_t course;
	    Student*starosta;
};

int main()
{

    uint16_t op1= 1025;
    uint16_t op2=127;
    char operat = '&';
    cout<< '\n';

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
   Student students[3]={
    {"Dima", 17, 4.3, 1, 1, nullptr},
    {"Vera", 18, 4.7, 0, 1,&students[0]},
    {"Oleg", 20, 3.4, 1, 2,&students[0]}
  };


    // адрес и размер массива, всех элементов массива
    cout << "\n";
    cout << "Address of Students: \t" << &students << endl;
    cout << "Size of Students: \t" << sizeof(students) << endl;
    cout << "Address of Students[1]: \t" << &students[1] << endl;
    cout << "Size of Students[1]: \t" << sizeof(students[1]) << endl;
    cout << "Address of Students[2]: \t" << &students[1] << endl;
    cout << "Size of Students[2]: \t" << sizeof(students[1]) << endl;
    cout << "Address of Students[3]: \t" << &students[2] << endl;
    cout << "Size of Students[3]: \t" << sizeof(students[2]) << endl;
    //адреса полей структуры
    cout << "Address of name: \t" << &students[2].name << endl;
    cout << "Address of year: \t" << &students[2].year << endl;
    cout << "Address of sred_ball: \t" << &students[2].sred_ball << endl;
    cout << "Address of course: \t" << &students[2].course << endl;
    //смещение от начала структуры
    cout << "Name is at offset: \t" << offsetof(Student, name) << endl; //Смещение от начала структуры
    cout << "Year is at offset: \t" << offsetof(Student, year) << endl;
    cout << "Sred is at offset: \t" << offsetof(Student, sred_ball) << endl;
    cout << "Course is at offset: \t" << offsetof(Student, course) << endl;
    //размер полей структуры
    cout << "Size of name: \t" << sizeof(students[2].name) << endl;
    cout << "Size of year: \t" << sizeof(students[2].year) << endl;
    cout << "Size of sred_ball: \t" << sizeof(students[2].sred_ball) << endl;
    cout << "Size of course: \t" << sizeof(students[2].course) << endl;
    //шестнадцатеричное и двоичное представление полей структуры
    cout << "Year in hex: \t";
    print_in_hex(&students[2].year, sizeof(students[2].year));
    cout << endl;
    cout << "Sred in hex: \t";
    print_in_hex(&students[2].sred_ball, sizeof(students[2].sred_ball));
    cout << endl;
    cout << "Course in hex: \t";
    print_in_hex(&students[2].course, sizeof(students[2].course));
    cout << endl;
    cout << "Year in bin: \t";
    print_in_binary(&students[2].year, sizeof(students[2].year));
    cout << endl;
    cout << "Sred in bin: \t";
    print_in_binary(students[2].sred_ball);
    cout << endl;
    cout << "Course in bin: \t";
    print_in_binary(students[2].course);
    cout << endl;
    //все элементы массива в шестнадцатеричном виде с указанием соответствия блоков байт полям структур

    cout << "Eear sred_ball course \n";
    for (int i = 0; i < 3; i++)
    {
        print_in_hex(&students[i].year, sizeof(students[i].year));
        cout << "|";
        print_in_hex(&students[i].sred_ball, sizeof(students[i].sred_ball));
        cout << "|";
        print_in_hex(&students[i].course, sizeof(students[i].course));
        cout << endl;

    }
    return 0;

    }



