#ifndef __CUBE
#define __CUBE 1

#include <GL/gl.h>
#include <bits/stdc++.h>
#include <GL/glut.h>

struct Cube
{
	Cube(){
		this->x = 0;
		this->y = 0;
		this->z = 0;
		this->xRotated = (GLfloat)0;
		this->yRotated = (GLfloat)0;
		this->zRotated = (GLfloat)0;
	}
	Cube(float x, float y, float z){
		this->x = x;
		this->y = y;
		this->z = z;
		this->xRotated = (GLfloat)0;
		this->yRotated = (GLfloat)0;
		this->zRotated = (GLfloat)0;
	}
	Cube(const Cube& p){
		this->x = p.x;
		this->y = p.y;
		this->z = p.z;
		this->xRotated = p.xRotated;
		this->yRotated = p.yRotated;
		this->zRotated = p.zRotated;
	}
	~Cube(){

	}
	Cube& operator=(const Cube& p) {
		this->x = p.x;
		this->y = p.y;
		this->z = p.z;
		this->xRotated = p.xRotated;
		this->yRotated = p.yRotated;
		this->zRotated = p.zRotated;
		return *this;
	}
	float getX(){
		return x;
	}
	float getY(){
		return y;
	}
	float getZ(){
		return z;
	}
	GLfloat getXRotated(){
		return xRotated;
	}
	GLfloat getYRotated(){
		return yRotated;
	}
	GLfloat getZRotated(){
		return zRotated;
	}
	void setX(float x){
		this->x = x;
	}
	void setY(float y){
		this->y = y;
	}
	void setZ(float z){
		this->z  = z;
	}
	void plusXRotated(float x){
		this->xRotated += (GLfloat)x;
	}
	void plusYRotated(float y){
		this->yRotated += (GLfloat)y;
	}
	void plusZRotated(float z){
		this->zRotated  += (GLfloat)z;
	}
	void rotate(float tengahX,float tengahY,float tengahZ,float degreeX=0,float degreeY=0,float degreeZ=0){
		x -= tengahX;
		y -= tengahY;
		z -= tengahZ;
		float tempx = x;
		float tempy = y;
		float tempz = z; 
		float radX = degreeX * 3.14159265358979323846 / 180.0 ;
	    float radY = degreeY * 3.14159265358979323846 / 180.0 ;
	    float radZ = degreeZ * 3.14159265358979323846 / 180.0 ;
	   	if (degreeZ) {
	      x = tempx*cos(radZ)-tempy*sin(radZ);
	      y = tempx*sin(radZ)+tempy*cos(radZ);
	    } else if (degreeY) {
	      x = tempz*sin(radY)+tempx*cos(radY);
	      z = tempz*cos(radY)-tempx*sin(radY);
	    } else {
	      y = tempy*cos(radX)-tempz*sin(radX);
	      z = tempy*sin(radX)+tempz*cos(radX);
	    }
	    x += tengahX;
	    y += tengahY;
	    z += tengahZ;
	}
private:
	float x,y,z;
	GLfloat xRotated, yRotated, zRotated;
};

#endif