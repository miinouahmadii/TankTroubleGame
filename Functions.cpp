#include "Functions.h"

int return_map_row (string address)
{
    int map_row;
    string line;
    string keep_line;
    ifstream fin;
    fin.open(address);
    getline(fin,line);
    keep_line=line;
    first_index=keep_line[0];
    second_index=keep_line.find(" ");
    num_of_index=((second_index)-(first_index));
    num_index=keep_line.substr(first_index,num_of_index);
    map_row=stoi(num_index);
    return map_row;

}

int return_map_col (string address)
{
    int map_col;
    int index_of_begin,index_of_end,num_of_index;
    string line;
    string keep_line;
    ifstream fin;
    fin.open(address);
    getline(fin,line);
    keep_line=line;
    index_of_begin=keep_line.find(" ");
    index_of_end=keep_line.find("/n");
    num_of_index=((index_of_end)-(index_of_begin));
    num_index=keep_line.substr(index_of_begin+1,num_of_index);
    map_col=stoi(num_index);
    return map_col;
}

int return_tank1_ylocation (string address)
{
    string line;
    string keep_line;
    ifstream fin;
    int tank1_ylocation;
    int count_line=1;
    fin.open(address);
    while(getline(fin, line))
    {
        count_line++;
        if(count_line==map_row+2)
        {
            keep_line=line;
            first_index=keep_line[0];
            tank1_ylocation=stoi(first_index);
        }
    }
return tank1_ylocation;
}

int return_tank2_ylocation (string address)
{
    string line;
    string keep_line;
    ifstream fin;
    int tank1_ylocation;
    int count_line=1;
    fin.open(address);
    while(getline(fin, line))
    {
        count_line++;
        if(count_line==map_row+3)
        {
            keep_line=line;
            first_index=keep_line[0];
            tank2_ylocation=stoi(first_index);
        }
    }
return tank2_ylocation;
}

int return_tank2_xlocation (string address)
{
    string line;
    string keep_line;
    ifstream fin;
    int tank1_xlocation;
    int count_line=1;
    int index_of_begin,index_of_end,num_of_index;
    fin.open(address);
    while(getline(fin, line))
    {
        count_line++;
        if(count_line==map_row+3)
        {
            keep_line=line;
            index_of_begin=keep_line.find(" ");
            index_of_end=keep_line.find("/n");
            num_of_index=((index_of_end)-(index_of_begin));
            num_index=keep_line.substr(index_of_begin+1,num_of_index);
            tank2_xlocation=stoi(num_index);
        }
    }
return tank2_xlocation;
}

int return_tank1_xlocation (string address)
{
    string line;
    string keep_line;
    ifstream fin;
    int tank1_xlocation;
    int count_line=1;
    int index_of_begin,index_of_end,num_of_index;
    fin.open(address);
    while(getline(fin, line))
    {
        count_line++;
        if(count_line==map_row+2)
        {
            keep_line=line;
            index_of_begin=keep_line.find(" ");
            index_of_end=keep_line.find("/n");
            num_of_index=((index_of_end)-(index_of_begin));
            num_index=keep_line.substr(index_of_begin+1,num_of_index);
            tank1_xlocation=stoi(num_index);
        }
    }
return tank1_xlocation;
}

vector<string>open_and_read_file_map(vector<string>&keep_map,string address)
{
   string line;
   string keep_line;
   ifstream fin;
   fin.open(address);
   int count_line=0;
   while(getline(fin, line))
   {
        count_line++;
        if(count_line==2)
            keep_map.push_back(line);
        if(count_line==row_num+2)
            break();
   }
   return keep_map;
 }