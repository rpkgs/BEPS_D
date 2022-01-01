/*************************************************************************
  Program:     penmon.c
  --------
  Description:
  ----------- 
	Calculate plant transpiration and soil evaporation with Penmon-Monteith equation.
	
 ***************************************************************************
  CCRS (EMS/Applications Division)
  Written by:   J. Liu/D.Fraser     
  Last update:	May 1998
*****************************************************************************/
	
#include <math.h>
 
double penmon(tair,vpd,wrad,acond,scond) 
    double tair,vpd,wrad,acond,scond;
    {
/*  penmon-monteith function */
 
    double	a1, a2, b1, b2, c1, c2, d1, d2;
    double 	t1, t2, gamma, svp1, svp2, slope;
    double	cp, pa, ra, rs, xlat, xtrans, penmon;

    gamma = 0.646+0.0006*tair; 
    t1 = tair+0.5; 
    t2 = tair-0.5; 

    a1 = 17.269*t1; 
    a2 = 17.269*t2; 

    b1 = 237.0+t1; 
    b2 = 237.0+t2; 

    c1 = a1 / b1; 
    c2 = a2 / b2; 

    d1 = (double) exp((double) c1); 
    d2 = (double) exp((double) c2); 

    svp1 = d1*6.1078; 
    svp2 = d2*6.1078; 
 
    slope = svp1-svp2; 
    cp = 1.01e+3; 
    pa = 1.292-0.00428*tair; 
    ra = 1.0/acond; 
    rs = 1.0/scond; 
    xlat = (2.501 - 0.0024*tair)* 1.0e+6; 
    xtrans = ((slope*wrad)+(cp*pa)* (vpd/ra)) /(slope+gamma* (1.0+rs/ra));
 
    penmon = xtrans/(xlat * 1000.0);
   
  /* printf("\ntair= %f\n",tair);
    printf("vpd= %f\n",vpd);
    printf("wrad= %f\n",wrad); 
    printf("acond= %f\n",acond);
    printf("scond= %f\n",scond);
    printf("xtrans= %f\n",xtrans);
    printf("xlat= %f\n",xlat);

    printf("penmon= %20.19f\n",penmon); */
 
    return(penmon); 
    }
 
