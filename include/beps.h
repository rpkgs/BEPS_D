#ifndef BEPS_H
#define BEPS_H

/*************************************************************************
  program: 	beps.h
  Description:  Header file for defining constants and global variables
  ----------    for BEPS program

***************************************************************************
  CCRS (EMS/Applications Division)
  Wrintten by: 	J. Liu
  Last update:  December 2000
*****************************************************************************/

#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b)) ? (a) : (b)
#define min(a, b) ((a) < (b)) ? (a) : (b)

/* Define Constants */
#define NOERROR 0
#define ERROR 1
#define PI 3.1415926

#define NPIX_CAN 5700
#define NLIN_CAN 4800

#define SIZEB 101
#define SIZEG 101
#define SIZEX 20
#define SIZEZ 50

#define RTIMES 1
#define RPERIOD 3600 /* in sec */

/* Declare structures */
struct climatedata {
    int long pix;
    double tmax;
    double tmin;
    double dewp;
    double srad;
    double frad;
    double precip;
};

struct xvalue {
    int long pix;
    double x1;  /* snow pack */
    double x2;  /* soil water */
    double x3;  /* out flow */
    double x4;  /* transpiration */
    double x5;  /* evaporation */
    double x6;  /* photosynthesis */
    double x7;  /* Rm */
    double x8;  /* leaf C */
    double x9;  /* stem C */
    double x10; /* root C */
    double x11; /* GPP */
    double x12; /* ResSoil */
    double x13; /* NEP */
    double x14; /* M Res leaf */
    double x15; /* M Res stem */
    double x16; /* M Res root */
    double x17; /* Number of days with rain */
    double x18; /* understory Trans */
};


void readconf();
void readb_init();
void pixtolon();
void readindex();
void readlc();
void readawc();
void readsnow();
void readbm();
void readlai();
void readclim();
void readb();

void model(int long pix, int short jday, int short day_start,
    double lai_p, double lat_p, double awc_p,
    int short lc_p,
    double x[],
    double b[],
    struct climatedata sdat[],
    struct xvalue xx[]);

void setx();

void zeroxx();
void readxx();
void writexx();

void zcomp();
void doflux(double b[], double g[], double x[], double z[]);

void inter(double b[], double g[], double x[], double z[]);
void melt(double b[], double g[], double x[], double z[]);
void ra(double b[], double g[], double x[], double z[]);
void rs(double b[], double g[], double x[], double z[]);

void rsoil(double b[], double g[], double x[], double z[]);

void carbon(double b[], double g[], double x[], double z[]);
int farq_psn(double z[], double g[]);

int net_longwave(double lai_o, double lai_u, double omega, double es, double ta,
                 double *m_lnet_o, double *m_lnet_u, double *lnet_g);
int net_shortwave(double sg, double cos_theta, double lai_p, double omega,
                  double *ssun, double *sshade, double lai_u,
                  double *n_ssun, double *n_sshade, double *n_sunder, double *n_sground);
int rad_ssl(double sg, double cos_theta, double lai_p, double omega, double *ssun, double *sshade);
double penmon(double tair, double vpd, double wrad, double acond, double scond);

void display();


/*	Declare global variables */
char awcf[255];       /* Available water holding capacity file */
char landcoverf[255]; /* Land cover file */
char leafareaf[255];  /* Leaf area index file */
char snowpackf[255];  /* Snow pack data file */
char deltacolf[255];  /* Delta column data file */
char deltarowf[255];  /* Delta row data file */
char rowf[255];       /* Row file */
char colf[255];       /* Column file */
char rowminf[255];    /* Row minimum file */
char ncarbinf[255];   /* NCAR Binary data file */
int long cycle_display;
int long jday_start; /* Julian day start */
int long jday_end;   /* Julian day end */
int long lin_offset; /* Line offset (pci coord. system) */
int long nlines;     /* Number of lines in study area */
int long npixels;    /* Number of pixels in study area */
int long pix_offset; /* Pixel offset (pci coord. system) */

float factor;
char outf_name[255];
char output_NPP;
char output_res;
char output_eva;
char output_tra;
char output_site;

float *dr; /*Delta row values*/
float *dc; /*Delta column values*/
unsigned char *row_index;
unsigned char *col_index;
double *z;

#endif
