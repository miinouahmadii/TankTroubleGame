#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "rsdl.hpp"

using namespace std;

int return_map_row (string address)
{
    int map_row;
    string line;
    string keep_line;
    ifstream fin;
    string num_index;
    int num_of_index,second_index,first_index;
    fin.open(address);
    getline(fin,line);
    keep_line=line;
    first_index=0;
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
    string num_index;
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

int return_tank1_xlocation (string address)
{
    string line,num_index;
    string keep_line;
    ifstream fin;
    int map_row= return_map_row(address);
    int tank1_xlocation;
    int first_index,second_index,num_of_index;
    int count_line=1;
    fin.open(address);
    while(getline(fin, line))
    {
        count_line++;
        if(count_line==map_row+3)
        {
            keep_line=line;
            first_index=0;
            second_index=keep_line.find(" ");
            num_of_index=((second_index)-(first_index));
            num_index=keep_line.substr(first_index,num_of_index);
            tank1_xlocation=stoi(num_index);
        }
    }
return tank1_xlocation;
}

int return_tank2_xlocation (string address)
{
    string line,num_index;
    string keep_line;
    ifstream fin;
    int first_index,num_of_index,second_index;
    int map_row= return_map_row(address);
    int tank2_xlocation;
    int count_line=0;
    fin.open(address);
    while(getline(fin, line))
    {
        count_line++;
        if(count_line==map_row+3)
        {
            keep_line=line;
            first_index=0;
            second_index=keep_line.find(" ");
            num_of_index=((second_index)-(first_index));
            num_index=keep_line.substr(first_index,num_of_index);
            tank2_xlocation=stoi(num_index);
        }
    }
return tank2_xlocation;
}

int return_tank2_ylocation (string address)
{
    string line;
    string keep_line;
    ifstream fin;
    string num_index;
    int map_row= return_map_row(address);
    int tank2_ylocation;
    int count_line=0;
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
            tank2_ylocation=stoi(num_index);
        }
    }
return tank2_ylocation;
}

int return_tank1_ylocation (string address)
{
    string line;
    string keep_line;
    ifstream fin;
    string num_index;
    int map_row= return_map_row(address);
    int tank1_ylocation;
    int count_line=0;
    int index_of_begin,index_of_end,num_of_index;
    fin.open(address);
    getline(fin, line);
    while(getline(fin, line))
    {
        count_line++;
        if(count_line==map_row+2)
        {
            keep_line=line;
            index_of_begin=keep_line.find(" ");
            index_of_end=keep_line.find("/n");
            num_of_index=((index_of_end)-(index_of_begin));
            num_index=keep_line.substr(index_of_begin,num_of_index);
            tank1_ylocation=stoi(num_index);
        }
    }
return tank1_ylocation;
}

void press_key(Window &win,int &tank1_xlocation,int &tank1_ylocation)
{
    Event event= win.poll_for_event();
    char key=event.get_pressed_key();
    if(event.get_type()== Event::KEY_PRESS)
    {
        key=event.get_pressed_key();
        if (key == 'l')
        tank1_xlocation-=5;
    }
}

vector<string>open_and_read_file_map(string address)
{
   vector<string> keep_map;
   string line;
   string keep_line;
   ifstream fin;
   int map_row= return_map_row(address);
   fin.open(address);
   int count_line=0;
   while(getline(fin, line))
   {
        count_line++;
        if(count_line >1)
            keep_map.push_back(line);
        if(count_line==map_row+1)
            break;
   }
   
   return keep_map;
 }

void print_background(Window &win,int map_row,int map_col)
{
win.fill_rect(Rectangle(0,0,map_col*30,map_row*30),WHITE);
}

void print_map(Window &win,int map_row,int map_col,vector<string>keep_map,int tank1_xlocation,int tank1_ylocation,int tank2_xlocation,int tank2_ylocation)
{
    win.draw_line(Point(0,map_row*30),Point(map_col*30,map_row*30),BLACK);
    win.draw_line(Point(map_col*30,map_row*30),Point(map_col*30,0),BLACK);
    for(int i=0;i<map_row;i++)
    {
       for(int j=0;j<map_col;j++)
       {
            if( keep_map[i][j] == '1')
            {
                win.draw_line(Point(j*30,i*30),Point(j*30+30,i*30),BLACK);
            }
            if( keep_map[i][j] == '2')
             {
                win.draw_line(Point(j*30,i*30),Point(j*30,i*30+30),BLACK);
             }
            
            if( keep_map[i][j] == '3')
             {
                win.draw_line(Point(j*30,i*30),Point(j*30+30,i*30),BLACK);
                win.draw_line(Point(j*30,i*30),Point(j*30,i*30+30),BLACK);
             }
       }
    }
    win.draw_img("Assets/Tank1-Normal.png",Rectangle(tank1_xlocation*10,tank1_ylocation*10,10,10));
    win.draw_img("Assets/Tank2-Normal.png",Rectangle(tank2_xlocation*10,tank2_ylocation*10,10,10));
}

int main(int argc, char* argv[])
{
    int show_from=0,tank1_xlocation,tank1_ylocation,tank2_xlocation,tank2_ylocation;
    vector<string>keep_map;
    string keep_argv_1 = argv[1];
    keep_argv_1+="/sample_map.txt";
    return_map_col(keep_argv_1);
    return_map_row(keep_argv_1);
    tank1_xlocation=return_tank1_xlocation(keep_argv_1);
    tank1_ylocation=return_tank1_ylocation(keep_argv_1);
    tank2_xlocation=return_tank2_xlocation(keep_argv_1);
    tank2_ylocation=return_tank2_ylocation(keep_argv_1);
    keep_map=open_and_read_file_map(keep_argv_1);
    int map_row=return_map_row(keep_argv_1);
    int map_col=return_map_col(keep_argv_1);

    Window win (map_col*30,map_row*30,"tank");
    
    Event event= win.poll_for_event();
    
    print_background(win,map_row,map_col);
    print_map(win,map_row,map_col,keep_map,tank1_xlocation,tank1_ylocation,tank2_xlocation,tank2_ylocation);
    press_key(win,tank1_xlocation,tank1_ylocation);
    win.update_screen();
    delay(6000);
    
   
}
