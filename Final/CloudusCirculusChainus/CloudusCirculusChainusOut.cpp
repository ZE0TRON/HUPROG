#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <fstream>

using namespace std;

#define SZ(V) (LL)V.size()

#define FORN(i, n) for(LL i = 0; i < n; i++)

#define FORAB(i, a, b) for(LL i = a; i <= b; i++)

#define eps 1e-8

#define PB push_back

typedef long long LL;

typedef pair<LL,LL> pll;

typedef vector<long  double> vd;

bool flag;

void normalize(vd &a){// normalizing a vector

        long double d;

        FORN(i,3) d+=a[i]*a[i];

        if(d>=eps) FORN(i,3) a[i]/=sqrt(d);

}

vd cross(vd a,vd b){// calculating cross product of two vectors

        vd c(3);

        FORN(i,3) c[0+i]=a[(1+i)%3]*b[(2+i)%3] - a[(2+i)%3]*b[(1+i)%3];

        normalize(c);

        return c;

}

vd circum_center(vd a,vd b,vd c){// calculating circumcenter of circle given three points a,b,c

        vd ab(3),ac(3);

        FORN(i,3) ab[i]=b[i]-a[i];

        FORN(i,3) ac[i]=c[i]-a[i];

        vd n=cross(ab,ac);

        vd abp=cross(n,ab);//slope of perpendicular bisector of AB

        vd acp=cross(n,ac);//slope of perpendicular bisector of AC

        vd abm(3),acm(3);

        FORN(i,3) abm[i]=(a[i]+b[i])/2.0;//point lying on perpendicular bisector of AB

        FORN(i,3) acm[i]=(a[i]+c[i])/2.0;//point lying on perpendicular bisector of AC

        // we have two perpendicular bisectors and center would be the intersecting point of these bisectors

        // calculating center of circle

       long double x=-190.0,y=-190.0;

        FORN(i,3){

                if(abs(abp[(0+i)%3]*acp[(1+i)%3] - abp[(1+i)%3]*acp[(0+i)%3]) >eps){

                        x =( (acp[(0+i)%3]*abm[(1+i)%3]-acp[(1+i)%3]*abm[(0+i)%3]) - (acp[(0+i)%3]*acm[(1+i)%3]-acp[(1+i)%3]*acm[(0+i)%3]) )/(abp[(0+i)%3]*acp[(1+i)%3] - abp[(1+i)%3]*acp[(0+i)%3]) ;

                }

                if(abs(abp[(0+i)%3]*acp[(1+i)%3] - abp[(1+i)%3]*acp[(0+i)%3]) >eps){

                        y= ( (abm[(1+i)%3]*abp[(0+i)%3]-abm[(0+i)%3]*abp[(1+i)%3]) - (acm[(1+i)%3]*abp[(0+i)%3]-acm[(0+i)%3]*abp[(1+i)%3]) )/(abp[(0+i)%3]*acp[(1+i)%3] - abp[(1+i)%3]*acp[(0+i)%3]) ;

                }

        }

        vd center(3);

        FORN(i,3) center[i] = (abp[i]*x) + abm[i];

        return center;

}

bool check_null(vd a){ // checking it magnitude of vector is zero

        return (abs(a[0])<eps && abs(a[1])<eps && abs(a[2])<eps);

}

void rotate(vd center,vd a,vd b,vd c,vd &nx,vd &ny,vd &nz){

        vd ca(3),cb(3);

        if(!check_null(cross(a,b))){

                FORN(i,3) ca[i]=a[i]-center[i];

                FORN(i,3) cb[i]=b[i]-center[i];

        }

        else{

                FORN(i,3) ca[i]=b[i]-center[i];

                FORN(i,3) cb[i]=c[i]-center[i];

        }

        normalize(ca);

        nx=ca;// taking vector from origin to a point on first circle as new x-axis

        nz=cross(nx,cb);// take new z axis to be the normal to plane of first circle

        ny=cross(nz,nx);// new y axis can be calculated by fact that  nx X ny = nz;  where X be cross product

        return;

}

long double dot(vd a,vd b){ // dot product of two vectors

      long  double ans=0;

        FORN(i,3) ans+=a[i]*b[i];

        return ans;

}

void update(vd &a,vd x,vd y,vd z){ // calculating new coordinates by taking projection of a vector to new axis

        vd b=a;

        a[0]=dot(b,x);

        a[1]=dot(b,y);

        a[2]=dot(b,z);

        return;

}

bool check(vd center,vd p,vd a,vd b){// checking if one of a,b lies inside the second circle and other outside

       long double radius=0.0;

        FORN(i,3) radius+=(p[i]-center[i])*(p[i]-center[i]);

        long double da=0.0,db=0.0;

        FORN(i,3) da+=(a[i]-center[i])*(a[i]-center[i]);

        FORN(i,3) db+=(b[i]-center[i])*(b[i]-center[i]);

        return ((min(da,db)<radius) && (max(da,db)>radius)) ;

}

int main()

{
    ofstream myFileOut;
    string outName;
    cout<<"Dosya sirasi output"<<endl;
    cin>>outName;
    myFileOut.open("output"+outName+".txt");
    
    ifstream myFileInp;
    myFileInp.open("input"+outName+".txt");

        LL test,sum,a[3];

        myFileInp >> test;

        while(test--){

                vd a1(3),a2(3),a3(3),b1(3),b2(3),b3(3);

                FORN(i,3) myFileInp >> a1[i];
                

                
                FORN(i,3) myFileInp >> a2[i];
                

                FORN(i,3) myFileInp >> a3[i];
                

                FORN(i,3) myFileInp >> b1[i];
                

                FORN(i,3) myFileInp >> b2[i];
                

                FORN(i,3) myFileInp >> b3[i];
                

                vd c1=circum_center(a1,a2,a3);

                //    translating the axis to c1

                FORN(i,3) a1[i]=a1[i]-c1[i];

                FORN(i,3) a2[i]=a2[i]-c1[i];

                FORN(i,3) a3[i]=a3[i]-c1[i];

                FORN(i,3) b1[i]=b1[i]-c1[i];

                FORN(i,3) b2[i]=b2[i]-c1[i];

                FORN(i,3) b3[i]=b3[i]-c1[i];

                vd nx,ny,nz;

                FORN(i,3) c1[i]=0.0;

                rotate(c1,a1,a2,a3,nx,ny,nz);

                // rotating axis so that first circle would end up on xy axis

                // new x,y,z axis would be nx,ny,nz respectively

                update(a1,nx,ny,nz);

                update(a2,nx,ny,nz);

                update(a3,nx,ny,nz);

                update(b1,nx,ny,nz);

                update(b2,nx,ny,nz);

                update(b3,nx,ny,nz);

                /* calculating equation of plane of second circle

                         ax+by+cz=d;

                        a->constants[0]; b-> constants[1]; c-> constants[2]; d->d;

                */

                vd constants(3);

                FORN(i,3){

                        constants[i] = ( (b2[(1+i)%3] - b1[(1+i)%3])*(b3[(2+i)%3]-b1[(2+i)%3]) - (b3[(1+i)%3] - b1[(1+i)%3])*(b2[(2+i)%3]-b1[(2+i)%3]) );

                }

               long double d=0.0,radius=0.0;

                FORN(i,3) d+=b1[i]*constants[i];

                FORN(i,3) radius+=a1[i]*a1[i];

                radius=sqrt(radius);

                // equation of first circle will become x^2 + y^2 = r^2

                // solving both equations for plane(of second circle) and the first circle itself

                flag=true;

                if(abs(constants[0])<eps){

                        if(abs(constants[1])<eps) flag=false;

                        else{

                               long double y=d/constants[1],k=(radius*radius - y*y);

                                if(abs(k) <eps ) flag=false;

                                else{

                                        vd a(3,0.0),b(3,0.0);

                                        a[1]=b[1]=y;

                                        a[0]=sqrt(k);

                                        b[0]=-sqrt(k);

                                        // checking if these circles are entangled

                                        // a,b are intersecting points of first circle and the plane

                                        if(!check(circum_center(b1,b2,b3),b1,a,b)) flag=false;

                                }

                        }

                }

                else{

                        long double a,b,c;

                        a= (constants[0]*constants[0]) + (constants[1]*constants[1]);

                        b= -2.0*constants[1]*d;

                        c= d*d - constants[0]*constants[0]*radius*radius;

                        long double k=b*b -4*a*c;

                        if(k<eps) flag=false;

                        else{

                                vd x(3,0.0),y(3,0.0);

                                x[1] = (-b + sqrt(k))/(2*a);
                                cout<<x[1]<<endl;
                                

                                y[1] = (-b - sqrt(k))/(2*a);
                                cout<<y[1]<<endl;
                                x[0] = (d-b*x[1])/a;

                                y[0] = (d-b*y[1])/a;

                                // checking if these circles are entangled

                                // x,y are intersecting points of first circle and the plane

                                if(!check(circum_center(b1,b2,b3),b1,x,y)) flag=false;

                        }

                }
                myFileOut << (flag ? "YES" : "NO") << endl;

        }

        return 0;

}
