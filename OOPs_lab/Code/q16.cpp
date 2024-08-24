#include<iostream>
#include<cmath>
using namespace std;

class Point{
    int x,y,z;
    public:
    Point(int x,int y,int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    
    void dist(Point p2){
        int distanceSq = 0;
        distanceSq = (pow((x-p2.x),2)+pow((y-p2.y),2)+pow((z-p2.z),2));
        cout<<"The distance between point ("<<x<<','<<y<<','<<z<<") and point ("<<p2.x<<','<<p2.y<<','<<p2.z<<") is : "<<pow(distanceSq,0.5)<<endl;
    }
};
int main(){
    Point p1(0,0,0),p2(3,4,5);
    p1.dist(p2);
}