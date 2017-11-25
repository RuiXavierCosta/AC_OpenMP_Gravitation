#include "helpers.h"

double get_versor(double x, double y, double z){
    return sqrt( pow(x, 2.0) + pow(y, 2.0) + pow(z, 2.0) );
}

VECTOR sum_vector(VECTOR a, VECTOR b){
    return get_vector_cartesian(a.x + b.x, a.y + b.y, a.z + b.z);
}

VECTOR mult_vector(VECTOR a, VECTOR b){
    return get_vector_polar(a.versor * b.versor, a.theta + b.theta, a.phi + b.phi);
}

VECTOR mult_vector_with_scalar(VECTOR v, double d){
    return get_vector_polar(v.versor * d,v.theta, v.phi);
}

VECTOR sub_vector(VECTOR a, VECTOR b){
    return get_vector_cartesian(a.x - b.x, a.y - b.y, a.z - b.z);
}

double *get_angles(double x, double y, double z){
    double *angles = (double *)malloc(sizeof(double)*2);
    double theta, phi;
    double versor = get_versor(x,y,z);
    
    if(versor > 0){
        theta = acos(z / versor);
    }else{
        theta = 0.0;
    }

    if( x > 0){
        phi = atan(y / x);
    }else{
        phi = 0.0;
    }

    angles[0] = theta;
    angles[1] = phi;
    return angles;
}



VECTOR get_vector_cartesian(double x, double y, double z){
    VECTOR v;

    v.x = x;
    v.y = y;
    v.z = z;

    v.versor = get_versor(x,y,z);
    double *angles = get_angles(x,y,z);
    v.theta = angles[0];
    v.phi = angles[1];

    return v;
}

VECTOR get_vector_polar(double versor, double theta, double phi){
    VECTOR v;

    v.versor = versor;
    v.theta = theta;
    v.phi = phi;

    v.x = versor * sin(theta) * cos(phi);
    v.y = versor * sin(theta) * sin(phi);
    v.z = versor * cos(phi);

    return v;
}