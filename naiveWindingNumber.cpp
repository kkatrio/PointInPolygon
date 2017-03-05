#include <iostream>
#include <math.h>
#include <vector>


using namespace std;

const double pi = 3.1415926535897;

struct Point{
    double x;
    double y;

    Point(double xin, double yin) : x(xin), y(yin) {}
};


float det(double v1x,double v1y,double v2x,double v2y)
{
    return v1x*v2y - v2x*v1y;
}


double calcAngle(double v1x,double v1y,double v2x,double v2y)
{
    double nom = v1x * v2x + v1y * v2y;
    double denom = sqrt(v1x*v1x + v1y*v1y) * sqrt(v2x*v2x + v2y*v2y);

    if(denom == 0)
    {
        return 0;
    }
    else
    {
        return det(v1x,v1y,v2x,v2y) < 0 ? acos(nom/denom) * (180.0/pi) : - acos(nom/denom) * (180.0/pi);
    }


}


double calcSumsOfAngles(const vector<Point>& Verts, const Point& P)
{
    double sum = 0;
    for(unsigned int i=0; i!=Verts.size()-1; i++)
    {

        double theta = calcAngle(Verts[i].x - P.x, Verts[i].y - P.y, Verts[i+1].x - P.x, Verts[i+1].y - P.y);
        //cout<<"theta: "<<theta<<endl;

        //consider point on line
        if (fabs(theta) > 179.9 && fabs(theta) < 180.1)
        {
            theta = 0;
            //cout<<"--theta->0\n";
        }

        sum += theta;

    }

    return sum;

}



int main()
{



    Point p0(-1,0);
    Point p1(0,2);
    Point p2(3,0);
    Point p3(0,-2);

    vector<Point> Verts;


    cout<<"test1 - point inside \n";

    Point P1(0.5,0.0);


    Verts.clear();
    Verts.push_back(p0);
    Verts.push_back(p1);
    Verts.push_back(p2);
    Verts.push_back(p3);
    Verts.push_back(p0); // add the first

    cout<<"sum of angles:"<< calcSumsOfAngles(Verts,P1)<<endl;
    cout<<"---------\n";




    cout<<"test2 -- point outside\n";

    Point P2(-1,-2);


    Verts.clear();
    Verts.push_back(p0);
    Verts.push_back(p1);
    Verts.push_back(p2);
    Verts.push_back(p3);
    Verts.push_back(p0); // add the first

    cout<<"sum of angles:"<< calcSumsOfAngles(Verts,P2)<<endl;
    cout<<"---------\n";



    cout<<"test3 -- point on border line\n";

    Point P3(-0.5,1);


    Verts.clear();
    Verts.push_back(p0);
    Verts.push_back(p1);
    Verts.push_back(p2);
    Verts.push_back(p3);
    Verts.push_back(p0); // add the first

    cout<<"sum of angles:"<< calcSumsOfAngles(Verts,P3)<<endl;
    cout<<"---------\n";



    cout<<"test4 -- point on a Vertex\n";

    Point P4(-1,0);


    Verts.clear();
    Verts.push_back(p0);
    Verts.push_back(p1);
    Verts.push_back(p2);
    Verts.push_back(p3);
    Verts.push_back(p0); // add the first

    cout<<"sum of angles:"<< calcSumsOfAngles(Verts,P4)<<endl;
    cout<<"---------\n";



    /*
    cout<<"test5 - point inside - no clockwise order\n";

    Point P5(0.5,0.0);


    Verts.clear();
    Verts.push_back(p0);
    Verts.push_back(p1);
    Verts.push_back(p3);
    Verts.push_back(p2);
    Verts.push_back(p0); // add the first

    cout<<"sum of angles:"<< calcSumsOfAngles(Verts,P5)<<endl;
    cout<<"---------\n";



    cout<<"test6 -- point outside - no clockwise order\n";

    Point P6(-1,-2);


    Verts.clear();
    Verts.push_back(p0);
    Verts.push_back(p1);
    Verts.push_back(p3);
    Verts.push_back(p2);
    Verts.push_back(p0); // add the first

    cout<<"sum of angles:"<< calcSumsOfAngles(Verts,P6)<<endl;
    cout<<"---------\n";


    cout<<"test7 -- point on border line - no clockwise order\n";

    Point P7(-0.5,1);


    Verts.clear();
    Verts.push_back(p0);
    Verts.push_back(p1);
    Verts.push_back(p3);
    Verts.push_back(p2);
    Verts.push_back(p0); // add the first

    cout<<"sum of angles:"<< calcSumsOfAngles(Verts,P7)<<endl;
    cout<<"---------\n";


    cout<<"test8 -- point on a Vertex - no clockwise order\n";


    Point P8(-1,0);


    Verts.clear();
    Verts.push_back(p0);
    Verts.push_back(p1);
    Verts.push_back(p3);
    Verts.push_back(p2);
    Verts.push_back(p0); // add the first

    cout<<"sum of angles:"<< calcSumsOfAngles(Verts,P8)<<endl;
    cout<<"---------\n";
    */


    return 0;
}
