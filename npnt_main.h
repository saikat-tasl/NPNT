#ifndef NPNT_MAIN_H
#define NPNT_MAIN_H
#include <qstring.h>

struct data
{
    float *lat;
    float *lon;
    float start_time;
    float end_time;
    float altitude;
    int drone_id;
    float operator_id;

    unsigned char *signature;
};

class NPNT
{
private:
    struct data *pa_data;

public:

    void purse_xml(QByteArray &);
    void get_flightdata();
    void check_geofence();
    void check_time();

};

#endif // NPNT_MAIN_H
