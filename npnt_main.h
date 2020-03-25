#ifndef NPNT_MAIN_H
#define NPNT_MAIN_H
#include <qstring.h>

struct data
{
    double *lat;
    double *lon;
    float start_time;
    float end_time;
    float altitude;
    int drone_id;
    int operator_id;
    int number_of_pos;
    unsigned char *signature;
};

class NPNT
{
private:
    struct data pa_data;
public:
    void purse_xml(QByteArray &);
    void num_ofcoordinates(struct data *,QByteArray &);
    void get_flightdata();
    void check_geofence();
    void check_time();
    void get_data(double *_lat, double *_lon)
    {
        int i;
            printf("number of coorinates = %d\n",pa_data.number_of_pos);
            for(i=0;i<4;i++)
            {
               _lat[i]=pa_data.lat[i];
               _lon[i]=pa_data.lon[i];
               printf("%f %f\n",pa_data.lat[i],pa_data.lon[i]);
            }
    }
};

#endif // NPNT_MAIN_H
