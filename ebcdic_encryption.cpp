#include "header.h"
using namespace std;

string convert_to_four_bit(string x)
{
    string ret_string;
    int string_length = calc_string_len(x);
    int need_0_bit;
    if(string_length<4)
    {
        need_0_bit = 4 - string_length;

        for(int i =0; i<need_0_bit;i++)
        {
            ret_string.push_back('0');
        }
    }
    ret_string = ret_string + x;

    return ret_string;
}
string dec_to_binary_convert(int n)
{
    string binary_string;
    int binaryNum[8];

    int i = 0;
    while (n>0)
    {
        binaryNum[i] = n%2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        binary_string = binary_string + to_string(binaryNum[j]);

    return binary_string;
}

int binary_to_decimal(int n)
{
    int num = n;
    int dec_value = 0;
    int base = 1;
    int temp = num;

    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base = base * 2;
    }

    return dec_value;
}

char ret_char_from_code(string zone_code, string digit_code)
{
    if((zone_code=="0000")&&(digit_code=="0000"))
        return '!';
    if((zone_code=="1111")&&(digit_code=="1111"))
        return ' ';
    int int_zone_bit,int_digit_bit;
    int_zone_bit = binary_to_decimal(convert_stringToNumber(zone_code));
    int_digit_bit = binary_to_decimal(convert_stringToNumber(digit_code));

    if(int_zone_bit==8)
        return (char)(96+int_digit_bit);
    else if(int_zone_bit==9)
        return (char)(105+int_digit_bit);
    else if(int_zone_bit==10)
        return (char)(113+int_digit_bit);
    else if(int_zone_bit==13)
        return (char)(64+int_digit_bit);
    else if(int_zone_bit==14)
        return (char)(73+int_digit_bit);
    else if(int_zone_bit==15)
        return (char)(82+int_digit_bit);
    else if(int_zone_bit==16)
        return (char)(47+int_digit_bit);

}

string ret_digit_bit(char x)
{
    if(x=='\n')
        return "0000";
    else if(x==' ')
        return "1111";
    else if((x>='a')&&(x<='i'))
        return dec_to_binary_convert((int)x%96);
    else if((x>='j')&&(x<='r'))
        return dec_to_binary_convert((int)x%105);
    else if((x>='s')&&(x<='z'))
        return dec_to_binary_convert((int)x%113);
    else if((x>='A')&&(x<='I'))
        return dec_to_binary_convert((int)x%64);
    else if((x>='J')&&(x<='R'))
        return dec_to_binary_convert((int)x%73);
    else if((x>='S')&&(x<='Z'))
        return dec_to_binary_convert((int)x%82);
    else if((x>='0')&&(x<='9'))
        return dec_to_binary_convert((int)x%47);
}

string ret_zone_bit(char x)
{
    if(x=='\n')
        return "0000";
    else if(x==' ')
        return "1111";
    else if((x>='a')&&(x<='i'))
        return dec_to_binary_convert(8);
    else if((x>='j')&&(x<='r'))
        return dec_to_binary_convert(9);
    else if((x>='s')&&(x<='z'))
        return dec_to_binary_convert(10);
    else if((x>='A')&&(x<='I'))
        return dec_to_binary_convert(13);
    else if((x>='J')&&(x<='R'))
        return dec_to_binary_convert(14);
    else if((x>='S')&&(x<='Z'))
        return dec_to_binary_convert(15);
    else if((x>='0')&&(x<='9'))
        return dec_to_binary_convert(16);
}

void ebcdic_encrypt(string taken_file)
{
    string intxt,line_in_file,marker;
    char ch,oldname[]="temp" ;
    char* newname=&taken_file[0];
    int t,l,i;
    ifstream input;
    ofstream output;

    input.open(taken_file, ios:: binary);
    output.open("temp",ios::binary);

    if((input)&&(output))
    {
        input>>marker;
        if(marker=="Y")
            return;
        else
        {
            output<<"Y";
            output<<endl;
        }
        while(input.eof()==0)
        {
            intxt.clear();
            getline(input,line_in_file);
            l = calc_string_len(line_in_file);
            //cout<<l<<" line: "<<line_in_file<<endl;
            for(i=0;i<l;i++)
                intxt = intxt + convert_to_four_bit(ret_zone_bit(line_in_file[i]))+" "+convert_to_four_bit(ret_digit_bit(line_in_file[i]))+" ";
            //input>>noskipws>>ch;
            //cout<<ch;
            intxt = intxt + "0000 0000 ";
            //cout<<intxt;
            output<<intxt;
        }
        input.close();
        output.close();
        remove(&taken_file[0]);
        rename(oldname,newname);
    }
}

void ebcdic_decrypt(string taken_file)
{
    string intxt,word1,word2,marker;
    char ch,oldname[]="temp" ;
    char* newname=&taken_file[0];
    int t,l,i;
    ifstream input;
    ofstream output;

    input.open(taken_file, ios:: binary);
    output.open("temp",ios::binary);

    if((input)&&(output))
    {
        input>>marker;
        if(marker=="N")
            return;
        else
        {
            output<<"N";
            output<<endl;
        }
        while(input.eof()==0)
        {
            input>>word1;
            input>>word2;
            //cout<<"w1: "<<word1<<"w2: "<<word2<<endl;
            ch = ret_char_from_code(word1,word2);
            if(ch=='!')
                output<<endl;
            else
                output<<ch;
        }
        input.close();
        output.close();
        remove(&taken_file[0]);
        rename(oldname,newname);
    }
}
