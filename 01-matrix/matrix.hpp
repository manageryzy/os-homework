/*
 * matrix.hpp
 *
 *  Created on: Jul 8, 2016
 *      Author: manageryzy
 */

#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <iostream>
#include <malloc.h>
#include <memory.h>

class Matrix {
public:
	Matrix(int sizeX,int sizeY){
		if(sizeX<=0 || sizeY<=0){
			throw "size too small";
		}
		this->sizeX = sizeX;
		this->sizeY = sizeY;
		this->matrix = (int *)malloc(sizeof(int)*sizeX*sizeY);

		if(this->matrix == nullptr){
			throw "malloc fail";
		}

		memset(this->matrix,0,sizeof(int)*sizeX*sizeY);
	}

	~Matrix(){
		free(this->matrix);
	}

	//init the matrix
	void init(){
		init(0,0);
	}

	int getSizeX(){
		return sizeX;
	}

	int getSizeY(){
		return sizeY;
	}

	int * getMatrix(){
		return matrix;
	}

	void setElement(int x,int y,int num){
		if(x<0 || x>=sizeX ||
				y < 0 || y>= sizeY){
			return;
		}

		matrix[y * sizeX + x] = num;
	}

	int getElement(int x,int y){
		return matrix[y * sizeX + x];
	}

private:
	int * matrix;
	int sizeX,sizeY;

	void  init(int layer,int num){
		int startX = layer;
		int endX = sizeX - layer;

		int startY = layer;
		int endY = sizeY - layer;

		if(startX >= endX || startY >= endY){
			return;
		}

		for(int x=startX;x<endX;x++){
			setElement(x,startY,num++);
		}

		for(int y=startY+1;y<endY;y++){
			setElement(endX-1,y,num++);
		}

		for(int x=endX-2;x>=startX;x--){
			setElement(x,endY-1,num++);
		}

		for(int y=endY-2;y>startY;y--){
			setElement(startX,y,num++);
		}

		init(layer+1,num);

	}
};

#endif /* MATRIX_HPP_ */
