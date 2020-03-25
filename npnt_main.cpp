#include <iostream>
#include <stdio.h>
#include "npnt_main.h"

using namespace std;

void NPNT::purse_xml(QByteArray &pa)
{
    int size=0,i=0,j=0;
    char temp_buffer[50],*n;
    char *index,*ptr = pa.data();
    num_ofcoordinates(&pa_data,pa);

//extract logitude

    while(*ptr)
    {
        if((index = strstr(ptr+size,"longitude=")))
        {
            n=index+11;
            while(*n!='"')
            {
                temp_buffer[i++]=*n;
                n++;
            }
            temp_buffer[i] = '\0';i=0;
            pa_data.lon[j++] = atof(temp_buffer);
            size=(index-ptr)+1;
        }
        ptr++;
    }j=0;

//extract latitude
    size=0;ptr = pa.data();
    while(*ptr)
    {
        if((index = strstr(ptr+size,"latitude=")))
        {
            n=index+10;
            while(*n!='"')
            {
                temp_buffer[i++]=*n;
                n++;
            }
            temp_buffer[i] = '\0';i=0;
            pa_data.lat[j++] = atof(temp_buffer);
            size=(index-ptr)+1;
        }
        ptr++;
    }j=0;

    for(int j=0;j<4;j++)
    {
        char temp[50];
        printf("lat = %f, lon = %f\n",pa_data.lat[j],pa_data.lon[j]);
    }

//extract logitude
//    ptr = pa.data();
//    do
//    {
//        if((index = strstr(ptr+size,"longitude=")))
//        {
//             printf("\n%.15s\n",index+11);
//             size=(index-ptr)+1;
//        }
//        ptr++;
//    }while(*ptr);
//extract logitude
//    ptr = pa.data();
//    do
//    {
//        if((index = strstr(ptr+size,"longitude=")))
//        {
//             printf("\n%.15s\n",index+11);
//             size=(index-ptr)+1;
//        }
//        ptr++;
//    }while(*ptr);
}

void NPNT::num_ofcoordinates(struct data *pa_data,QByteArray &pa)
{
        char *index,*ptr;
        int size=0,count=0;
        ptr = pa.data();
        do
        {
            if((index = strstr(ptr+size,"longitude=")))
            {
                count++;
                size=(index-ptr)+1;
            }
            ptr++;

        }while(*ptr);
        pa_data->number_of_pos = count;
        pa_data->lon = new double[count * 8];    //size of double is 8byte
        ptr = pa.data();count=0;size=0;

        do
        {
            if((index = strstr(ptr+size,"latitude=")))
            {
                count++;
                size=(index-ptr)+1;
            }
            ptr++;

        }while(*ptr);

        pa_data->lat = new double[count * 8];
        count=0;size=0;
}

void NPNT::get_flightdata()
{

}
void NPNT::check_geofence()
{

}
void NPNT::check_time()
{

}
