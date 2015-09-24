#include <iostream>
#include <string>

using namespace std;

class Animal{
  public:
  Animal(float weight, string name, string color){
    this->weight = weight;
    this->name = name;
    this->color = color;
  }
  
  virtual string getType(){
    return "Generic Animal";
  }
  
  virtual float landSpeed() = 0;
  
  float getWeight(){ return weight;}
  string getName(){return name; }
  string getColor(){return color; }
  protected:
  float weight;   // lb
  string name;
  string color;
};


class Dog: public Animal{
  public:
  Dog(float weight, string name):Animal(weight,name,"brown"){
  
  }
  string getType(){
    return "Dog";
  }
  
  float landSpeed(){
    return 50.0 - weight;
  } 

};

class Cat: public Animal{
  public:
  Cat(float weight, string name, string color):Animal(weight,name,color){
  
  }
  string getType(){
    return "Cat";
  }
  
  float landSpeed(){
    return 30.0 - weight;
  }
};

class Turtle: public Animal{

  string getType(){
    return "Turtle";
  }
  
  float landSpeed(){
    return 0.1;
  }
};
